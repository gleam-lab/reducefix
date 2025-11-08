#!/usr/bin/env python3
"""
OSS-Fuzz reducer benchmark - 对比三种缩减方法

三种方法：
1. **ddmin-only**: 朴素的 ddmin 算法（不针对格式做特殊处理）
   - 使用 ddmin.py 中的通用实现
   
2. **reducefix**: 使用 **LLM one-shot 生成的 reducer** 进行缩减
   - 通过 reducer_builder.py 生成 reducer.py
   - 然后用生成的 reducer 压缩输入
   
3. **llm-generated**: **LLM 直接压缩输入**（不生成 reducer）
   - 直接调用 LLM API
   - 发送原始输入，让 LLM 返回压缩后的输入
   - 不经过 reducer 生成步骤

与外层 reducer_test.py 逻辑保持一致。
"""
import argparse
import json
import os
import sys
import time
import traceback
import importlib.util
import signal
from typing import Dict, Optional, Tuple

from .adapters import pdfium_runner, harfbuzz_runner, default_oracle, get_docker_runner_for_case
from .ddmin import ddmin_reduce
from .reducefix import reduce_fix


class TimeoutError(Exception):
    """超时异常"""
    pass


def timeout_handler(signum, frame):
    """超时信号处理"""
    raise TimeoutError("操作超时")


def run_with_timeout(func, timeout_sec=60, *args, **kwargs):
    """
    在超时限制内运行函数
    
    Args:
        func: 要执行的函数
        timeout_sec: 超时时间（秒）
        *args, **kwargs: 传递给函数的参数
    
    Returns:
        函数的返回值，如果超时则返回 None
    """
    # 设置超时信号
    signal.signal(signal.SIGALRM, timeout_handler)
    signal.alarm(timeout_sec)
    
    try:
        result = func(*args, **kwargs)
        signal.alarm(0)  # 取消超时
        return result
    except TimeoutError:
        print(f"[Timeout] 操作超过 {timeout_sec} 秒，强制终止")
        return None
    finally:
        signal.alarm(0)  # 确保取消超时


def _load_bytes(path: str) -> bytes:
    """读取文件为字节数据"""
    with open(path, "rb") as f:
        return f.read()


def _save_bytes(path: str, data: bytes) -> None:
    """保存字节数据到文件"""
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "wb") as f:
        f.write(data)


def _mk_test_fn(runner) -> callable:
    """创建测试函数（用于判断是否仍能复现 bug）"""
    oracle = default_oracle()
    def test_fn(b: bytes) -> bool:
        res = runner.run(b)
        return oracle(res)
    return test_fn


def load_reducefix_reducer(target: str, model_tag: str) -> Optional[callable]:
    """
    加载 LLM 生成的 reducer（用于 reducefix 方法）
    
    按 target 加载 reducer，而不是按 case_id。
    同一个 target 的所有案例共用一个 reducer。
    
    优先从 cases_data 目录加载，如果不存在则从 artifacts 加载。
    
    Args:
        target: 目标项目名称（如 pdfium, harfbuzz）
        model_tag: 模型标签
    
    Returns:
        generated_reduce 函数，如果加载失败则返回 None
    """
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    # 优先从 cases_data 加载，备选 artifacts
    possible_paths = [
        os.path.join(base, "oss_fuzz_results", "cases_data", target, model_tag, "reducer.py"),
        os.path.join(base, "oss_fuzz_results", "artifacts", target, model_tag, "reducer.py"),
    ]
    
    reducer_path = None
    for path in possible_paths:
        if os.path.exists(path):
            reducer_path = path
            break
    
    if not reducer_path:
        print(f"[Warning] Reducefix reducer 不存在于以下路径:", file=sys.stderr)
        for path in possible_paths:
            print(f"  - {path}", file=sys.stderr)
        print(f"[Info] 提示：运行 'python3 -m oss_fuzz.reducer_builder <any_{target}_case> --model <model> --tag {model_tag}' 生成 reducer")
        return None
    
    print(f"[Info] 加载 {target} 的 reducer: {reducer_path}")
    
    try:
        # 动态加载模块
        spec = importlib.util.spec_from_file_location(f"reducefix_reducer_{target}_{model_tag}", reducer_path)
        if spec is None or spec.loader is None:
            print(f"[Error] 无法加载 reducer spec: {reducer_path}", file=sys.stderr)
            return None
        
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        
        # 获取 generated_reduce 函数
        if hasattr(module, 'generated_reduce'):
            print(f"[Success] 成功加载 {target} reducefix reducer")
            return module.generated_reduce
        else:
            print(f"[Error] Reducer 模块缺少 generated_reduce 函数: {reducer_path}", file=sys.stderr)
            return None
    
    except Exception as e:
        print(f"[Error] 加载 reducefix reducer 失败: {e}", file=sys.stderr)
        traceback.print_exc()
        return None


def _map_model_tag_to_llm_name(model_tag: str) -> str:
    """从 model_tag 推导用于 LLM 调用的模型名。

    规则：
    - 去除前缀 "reducefix_"（如有）
    - 常见别名映射：
      - qwen        -> qwen-plus
      - coder7b     -> qwen2.5-coder-7b-instruct
      - gpt4        -> gpt-4
      - claude3     -> claude-3
    - 未命中映射则原样返回
    """
    tag = model_tag or ""
    if tag.startswith("reducefix_"):
        tag = tag[len("reducefix_"):]

    mapping = {
        "qwen": "qwen-plus",
        "coder7b": "qwen2.5-coder-7b-instruct",
        "qwen3": "qwen3-max",
        "gpt4": "gpt-4",
        "claude3": "claude-3",
        "deepseek": "deepseek-v3.1",
    }
    return mapping.get(tag, tag)


def llm_direct_reduce(
    original_bytes: bytes,
    test_fn: callable,
    target: str,
    model_name: str = "qwen-plus"
) -> Tuple[bytes, str]:
    """
    LLM 直接压缩输入（不生成 reducer）
    
    这是第三种方法：直接让 LLM 对输入进行压缩
    
    Args:
        original_bytes: 原始输入
        test_fn: 测试函数
        target: 目标工程名称
        model_name: LLM 模型名称
    
    Returns:
        (压缩后的字节, 状态)
    """
    import llm
    import base64
    
    # 构建 prompt
    format_hints = {
        "pdfium": "这是一个 PDF 文件。请保留关键的 PDF 结构（header, xref, trailer），移除冗余对象和流数据。",
        "harfbuzz": "这是一个字体文件。请保留触发 bug 的关键表结构，移除不必要的字形数据。"
    }
    
    hint = format_hints.get(target, "这是一个二进制文件。请识别并保留触发 bug 的关键字节，移除冗余数据。")
    
    # 将输入转换为可传输格式
    # 对于二进制数据，使用 base64 编码
    encoded_input = base64.b64encode(original_bytes).decode('ascii')
    original_size = len(original_bytes)
    
    prompt = f"""你是测试用例缩减专家。请直接压缩以下输入，使其仍能触发相同的 bug。

目标: {target}
原始大小: {original_size} bytes
提示: {hint}

要求：
1. 输出压缩后的数据（Base64 编码）
2. 保留触发 bug 的关键部分
3. 尽可能减小大小
4. 只输出 Base64 编码的数据，不要有其他说明文字

原始输入 (Base64):
{encoded_input[:1000]}{"..." if len(encoded_input) > 1000 else ""}

请输出压缩后的 Base64 编码数据：
"""
    
    try:
        print(f"[Info] 调用 LLM ({model_name}) 直接压缩输入...")
        print(f"[Info] 原始大小: {original_size} bytes")
        
        messages = [{"role": "user", "content": prompt}]
        response = llm.call_llm(
            prompt_history=messages,
            model_name=model_name,
            temperature=0.0,
            max_tokens=8192
        )
        
        if not response:
            print(f"[Error] LLM 返回空响应")
            return original_bytes, "llm_no_response"
        
        print(f"[Info] LLM 响应长度: {len(response)} 字符")
        
        # 尝试提取 Base64 数据
        # 移除可能的 markdown 代码块标记
        response = response.strip()
        if response.startswith("```"):
            lines = response.split('\n')
            response = '\n'.join([l for l in lines if not l.strip().startswith('```')])
        
        response = response.strip()
        
        # 尝试解码
        try:
            compressed_bytes = base64.b64decode(response)
            compressed_size = len(compressed_bytes)
            
            print(f"[Info] 解码成功，压缩后大小: {compressed_size} bytes")
            
            # 验证是否仍能触发 bug
            if test_fn(compressed_bytes):
                print(f"[Success] LLM 压缩成功！大小: {compressed_size} bytes ({compressed_size/original_size*100:.1f}%)")
                return compressed_bytes, "success"
            else:
                print(f"[Error] 压缩后的输入无法触发 bug")
                return original_bytes, "not_interesting"
        
        except Exception as e:
            print(f"[Error] Base64 解码失败: {e}")
            print(f"[Debug] 响应内容: {response[:200]}...")
            return original_bytes, "decode_error"
    
    except Exception as e:
        print(f"[Error] LLM 调用失败: {e}")
        traceback.print_exc()
        return original_bytes, "llm_error"


def run_single(
    case_id: str,
    target: str,
    target_bin: str,
    input_path: str,
    out_dir: str,
    model_tag: Optional[str] = None,
    skip_initial_check: bool = False,
    timeout: int = 240
) -> Dict:
    """
    运行单个案例的缩减对比实验
    
    Args:
        case_id: 案例 ID
        target: 目标工程 (pdfium/harfbuzz)
        target_bin: 可执行文件路径
        input_path: 原始 PoC 路径
        out_dir: 输出目录
        model_tag: 模型标签（用于加载 LLM-generated reducer）
        skip_initial_check: 是否跳过初始检查
    
    Returns:
        统计信息字典
    """
    os.makedirs(out_dir, exist_ok=True)
    
    # 1. 读取原始输入
    print(f"[Info] 读取原始输入: {input_path}")
    original = _load_bytes(input_path)
    original_size = len(original)
    print(f"[Info] 原始大小: {original_size} bytes ({original_size/1024:.1f} KB)")
    
    # 预先定义输出路径（供缓存检查与保存复用）
    ddmin_path = os.path.join(out_dir, "reduced.ddmin")
    rfix_path = os.path.join(out_dir, "reduced.reducefix")
    generated_path = os.path.join(out_dir, "reduced.llm_generated")
    original_path = os.path.join(out_dir, "original.bin")
    
    # 2. 设置 runner 和 test function
    # 优先使用 Docker runner（更准确）
    runner = None
    use_docker = False
    
    if case_id:
        docker_runner_inst = get_docker_runner_for_case(case_id, timeout_sec=40.0)
        if docker_runner_inst:
            runner = docker_runner_inst
            use_docker = True
            print(f"[Info] 使用 Docker runner (镜像来自 cases.json)")
    
    # Fallback 到本地 runner
    if not runner:
        print(f"[Warning] Docker runner 不可用，使用本地 fuzzer（可能无法触发崩溃）")
        if target == "pdfium":
            runner = pdfium_runner(target_bin)
        elif target == "harfbuzz":
            runner = harfbuzz_runner(target_bin)
        elif target in ["mupdf", "imagemagick", "libxml2", "poppler", "php-src"]:
            # 使用通用 runner（类似 harfbuzz）
            runner = harfbuzz_runner(target_bin)
        else:
            raise ValueError(f"Unknown target: {target}")
    
    test_fn = _mk_test_fn(runner)
    
    # 3. 初始检查（确保原始输入能触发 bug）
    if not skip_initial_check:
        print("[Info] 检查原始输入是否能触发 bug...")
        
        # 运行测试并捕获详细输出
        result = runner.run(original)
        oracle = default_oracle()
        is_interesting = oracle(result)
        
        print(f"[Debug] 运行结果:")
        print(f"  - returncode: {result.returncode}")
        print(f"  - timed_out: {result.timed_out}")
        print(f"  - stdout (前200字符): {result.stdout[:200] if result.stdout else '(empty)'}")
        print(f"  - stderr (前200字符): {result.stderr[:200] if result.stderr else '(empty)'}")
        print(f"  - oracle 判断为 interesting: {is_interesting}")
        
        if not is_interesting:
            print("[Error] 原始输入未能触发 bug")
            print("[Info] 如果这是预期行为，可以使用 --skip-check 跳过此检查")
            raise RuntimeError("Original input does not reproduce the bug (not interesting)")
        print("[Info] ✓ 原始输入确认可触发 bug")
    else:
        print("[Info] 跳过初始检查（回归测试模式）")
    
    # === 方法 1: ddmin-only ===
    print("\n" + "="*60)
    print(f"方法 1: ddmin-only (超时限制: {timeout}秒)")
    print("="*60)
    
    # 缓存检查：ddmin 结果
    ddmin_cached = False
    if os.path.exists(ddmin_path):
        ddmin_out = _load_bytes(ddmin_path)
        ddmin_size = len(ddmin_out)
        ddmin_ratio = ddmin_size / max(1, original_size)
        ddmin_time = 0
        ddmin_cached = True
        print(f"[Cache] 已存在 ddmin 结果，直接加载: {ddmin_path}")
        print(f"  - 缩减后: {ddmin_size} bytes ({(1-ddmin_ratio)*100:.1f}%)")
    
    if not ddmin_cached:
        print(f"[Info] 开始 ddmin 缩减...")
        print(f"[Info] 输入大小: {original_size} bytes")
    
    # 根据 target 类型选择合适的分割策略
    # 二进制格式（字体、图片等）：按块分割
    # 文本格式（PDF、XML 等）：按行分割
    # 注意：Poppler 虽然处理 PDF，但很多测试文件是高度压缩的二进制数据
    binary_targets = ["harfbuzz", "imagemagick", "poppler"]
    text_targets = ["pdfium", "libxml2"]
    
    if not ddmin_cached:
        if target in binary_targets:
            by_lines = False
            print(f"[Info] 使用块级分割策略（二进制格式）")
        elif target in text_targets:
            by_lines = True
            print(f"[Info] 使用行级分割策略（文本格式）")
        else:
            # 默认使用块级（更通用）
            by_lines = False
            print(f"[Info] 使用块级分割策略（默认）")
    
    if not ddmin_cached:
        start_time = time.time()
        try:
            # 使用 run_with_timeout 确保 ddmin 不会超时
            ddmin_out = run_with_timeout(
                ddmin_reduce,
                timeout,  # 超时时间（秒）
                original, 
                test_fn, 
                by_lines=by_lines, 
                verbose=True
            )
            
            if ddmin_out is None:
                # 超时
                ddmin_out = original
                ddmin_size = original_size
                ddmin_ratio = 1.0
                ddmin_time = timeout
                print(f"[Timeout] ddmin 超时，保留原始输入")
            else:
                ddmin_time = time.time() - start_time
                ddmin_size = len(ddmin_out)
                ddmin_ratio = ddmin_size / max(1, original_size)
                print(f"[Success] ddmin 完成")
                print(f"  - 原始大小: {original_size} bytes")
                print(f"  - 缩减后: {ddmin_size} bytes")
                print(f"  - 压缩率: {(1-ddmin_ratio)*100:.1f}%")
                print(f"  - 耗时: {ddmin_time:.1f}s")
        except Exception as e:
            print(f"[Error] ddmin 失败: {e}")
            traceback.print_exc()
            ddmin_out = original
            ddmin_size = original_size
            ddmin_ratio = 1.0
            ddmin_time = 0
    
    # === 方法 2: reducefix (使用 LLM 生成的 reducer) ===
    print("\n" + "="*60)
    print(f"方法 2: reducefix (one-shot generated reducer, 超时限制: {timeout}秒)")
    print("="*60)
    
    # 缓存检查：reducefix 结果
    rfix_cached = False
    if os.path.exists(rfix_path):
        rfix_out = _load_bytes(rfix_path)
        rfix_size = len(rfix_out)
        rfix_ratio = rfix_size / max(1, original_size)
        rfix_time = 0
        rfix_cached = True
        print(f"[Cache] 已存在 ReduceFix 结果，直接加载: {rfix_path}")
        print(f"  - 缩减后: {rfix_size} bytes ({(1-rfix_ratio)*100:.1f}%)")
    
    # 默认值
    if not rfix_cached:
        start_time = time.time()
        rfix_out = original
        rfix_size = original_size
        rfix_ratio = 1.0
        rfix_time = 0
    
    if not rfix_cached and model_tag:
        # 尝试加载 LLM 生成的 reducer（按 target 加载）
        reducefix_fn = load_reducefix_reducer(target, model_tag)
        
        if reducefix_fn:
            try:
                # 使用 run_with_timeout 确保 reducefix 不会超时
                rfix_out = run_with_timeout(
                    reducefix_fn,
                    timeout,  # 超时时间（秒）
                    original, 
                    test_fn, 
                    verbose=True
                )
                
                if rfix_out is None:
                    # 超时
                    print(f"[Timeout] reducefix 超时，尝试 fallback 策略")
                    # Fallback 也用超时控制
                    rfix_out = run_with_timeout(
                        reduce_fix,
                        timeout // 2,  # fallback 使用一半的时间
                        original, 
                        test_fn, 
                        block_size=4096, 
                        line_mode=True
                    )
                    if rfix_out is None:
                        rfix_out = original
                        print(f"[Timeout] Fallback 也超时，保留原始输入")
                    rfix_time = time.time() - start_time
                    rfix_size = len(rfix_out)
                    rfix_ratio = rfix_size / max(1, original_size)
                else:
                    rfix_time = time.time() - start_time
                    rfix_size = len(rfix_out)
                    rfix_ratio = rfix_size / max(1, original_size)
                    print(f"[Success] reducefix 完成")
                    print(f"  - 原始大小: {original_size} bytes")
                    print(f"  - 缩减后: {rfix_size} bytes")
                    print(f"  - 压缩率: {(1-rfix_ratio)*100:.1f}%")
                    print(f"  - 耗时: {rfix_time:.1f}s")
                    print(f"  - 改进 (vs ddmin): {(ddmin_size-rfix_size)/max(1,ddmin_size)*100:.1f}%")
            except Exception as e:
                print(f"[Error] reducefix 执行失败: {e}")
                traceback.print_exc()
                # Fallback to simple reducefix
                print(f"[Info] Fallback 到简单 reducefix 策略")
                try:
                    rfix_out = run_with_timeout(
                        reduce_fix,
                        timeout // 2,  # fallback 使用一半的时间
                        original, 
                        test_fn, 
                        block_size=4096, 
                        line_mode=True
                    )
                    if rfix_out is None:
                        rfix_out = original
                    rfix_time = time.time() - start_time
                    rfix_size = len(rfix_out)
                    rfix_ratio = rfix_size / max(1, original_size)
                    print(f"[Success] Fallback reducefix 完成: {rfix_size} bytes")
                except Exception as e2:
                    print(f"[Error] Fallback 也失败: {e2}")
        else:
            # No LLM reducer, use simple reducefix
            print(f"[Info] 未找到 LLM reducer，使用简单 reducefix 策略")
            try:
                rfix_out = run_with_timeout(
                    reduce_fix,
                    timeout,
                    original, 
                    test_fn, 
                    block_size=4096, 
                    line_mode=True
                )
                if rfix_out is None:
                    rfix_out = original
                rfix_time = time.time() - start_time
                rfix_size = len(rfix_out)
                rfix_ratio = rfix_size / max(1, original_size)
                print(f"[Success] Simple reducefix 完成: {rfix_size} bytes ({(1-rfix_ratio)*100:.1f}%)")
            except Exception as e:
                print(f"[Error] Simple reducefix 失败: {e}")
    elif not rfix_cached:
        # No model_tag, use simple reducefix
        print(f"[Info] 未提供 model_tag，使用简单 reducefix 策略")
        try:
            rfix_out = run_with_timeout(
                reduce_fix,
                timeout,
                original, 
                test_fn, 
                block_size=4096, 
                line_mode=True
            )
            if rfix_out is None:
                rfix_out = original
            rfix_time = time.time() - start_time
            rfix_size = len(rfix_out)
            rfix_ratio = rfix_size / max(1, original_size)
            print(f"[Success] Simple reducefix 完成: {rfix_size} bytes ({(1-rfix_ratio)*100:.1f}%)")
        except Exception as e:
            print(f"[Error] Simple reducefix 失败: {e}")
    
    # === 方法 3: llm-generated (LLM 直接压缩输入) ===
    print("\n" + "="*60)
    print("方法 3: llm-generated (LLM 直接压缩输入)")
    print("="*60)
    
    # 缓存检查：llm-generated 结果
    generated_cached = False
    if os.path.exists(generated_path):
        generated_out = _load_bytes(generated_path)
        generated_size = len(generated_out)
        generated_ratio = generated_size / max(1, original_size)
        generated_time = 0
        generated_status = "cached"
        generated_cached = True
        print(f"[Cache] 已存在 llm-generated 结果，直接加载: {generated_path}")
        print(f"  - 缩减后: {generated_size} bytes ({(1-generated_ratio)*100:.1f}%)")
    else:
        generated_out = original
        generated_size = original_size
        generated_ratio = 1.0
        generated_time = 0
        generated_status = "not_attempted"
        
        # 如果提供了 model_tag，尝试使用 LLM 直接压缩
        if model_tag:
            # 从 model_tag 提取模型名称（支持 reducefix_* 前缀与别名映射）
            llm_model = _map_model_tag_to_llm_name(model_tag)
            
            start_time = time.time()
            try:
                # 使用 run_with_timeout 确保 LLM 调用不会超时
                result = run_with_timeout(
                    llm_direct_reduce,
                    timeout,
                    original,
                    test_fn,
                    target,
                    model_name=llm_model
                )
                
                if result is None:
                    # 超时
                    print(f"[Timeout] llm-generated 超时")
                    generated_out = original
                    generated_status = "timeout"
                    generated_time = timeout
                else:
                    generated_out, generated_status = result
                    generated_time = time.time() - start_time
                
                generated_size = len(generated_out)
                generated_ratio = generated_size / max(1, original_size)
                
                if generated_status == "success":
                    print(f"[Success] llm-generated 完成")
                    print(f"  - 原始大小: {original_size} bytes")
                    print(f"  - 缩减后: {generated_size} bytes")
                    print(f"  - 压缩率: {(1-generated_ratio)*100:.1f}%")
                    print(f"  - 耗时: {generated_time:.1f}s")
                    print(f"  - 改进 (vs ddmin): {(ddmin_size-generated_size)/max(1,ddmin_size)*100:.1f}%")
                    print(f"  - 改进 (vs reducefix): {(rfix_size-generated_size)/max(1,rfix_size)*100:.1f}%")
                else:
                    print(f"[Error] llm-generated 失败: {generated_status}")
            except Exception as e:
                print(f"[Error] llm-generated 执行失败: {e}")
                traceback.print_exc()
                generated_status = "error"
        else:
            print(f"[Info] 未提供 model_tag，跳过 llm-generated")
            generated_status = "skipped"
    
    # 4. 保存缩减结果
    print("\n" + "="*60)
    print("保存结果")
    print("="*60)
    
    _save_bytes(original_path, original)
    _save_bytes(ddmin_path, ddmin_out)
    _save_bytes(rfix_path, rfix_out)
    _save_bytes(generated_path, generated_out)
    
    print(f"[Info] 已保存: {original_path}")
    print(f"[Info] 已保存: {ddmin_path}")
    print(f"[Info] 已保存: {rfix_path}")
    print(f"[Info] 已保存: {generated_path}")
    
    # 5. 生成统计信息（与外层 analyze_reducer_stats.py 一致）
    stats = {
        "case_id": case_id,
        "target": target,
        "original_size": original_size,
        "original_size_bytes": original_size,  # 保持向后兼容
        
        # ddmin-only
        "ddmin_size": ddmin_size,
        "ddmin_size_bytes": ddmin_size,
        "ddmin_ratio": ddmin_ratio,
        "ddmin_compression_ratio": 1 - ddmin_ratio,
        "ddmin_time_seconds": ddmin_time,
        
        # reducefix
        "reducefix_size": rfix_size,
        "reducefix_size_bytes": rfix_size,
        "reducefix_ratio": rfix_ratio,
        "reducefix_compression_ratio": 1 - rfix_ratio,
        "reducefix_time_seconds": rfix_time,
        
        # llm-generated
        "generated_size": generated_size,
        "generated_size_bytes": generated_size,
        "generated_ratio": generated_ratio,
        "generated_compression_ratio": 1 - generated_ratio,
        "generated_time_seconds": generated_time,
        "generated_status": generated_status,
        
        # 改进指标
        "reducefix_improvement_over_ddmin": (ddmin_size - rfix_size) / max(1, ddmin_size),
        "generated_improvement_over_ddmin": (ddmin_size - generated_size) / max(1, ddmin_size),
        "generated_improvement_over_reducefix": (rfix_size - generated_size) / max(1, rfix_size),
    }
    
    # 保存统计信息
    stats_path = os.path.join(out_dir, "stats.json")
    with open(stats_path, "w", encoding="utf-8") as f:
        json.dump(stats, f, ensure_ascii=False, indent=2)
    print(f"[Info] 已保存统计信息: {stats_path}")
    
    # 6. 打印汇总
    print("\n" + "="*60)
    print("实验汇总")
    print("="*60)
    print(f"{'方法':<20} {'大小(bytes)':<15} {'压缩率':<12} {'耗时(s)':<10}")
    print("-"*60)
    print(f"{'原始':<20} {original_size:<15} {'-':<12} {'-':<10}")
    print(f"{'ddmin-only':<20} {ddmin_size:<15} {(1-ddmin_ratio)*100:<11.1f}% {ddmin_time:<10.1f}")
    print(f"{'reducefix':<20} {rfix_size:<15} {(1-rfix_ratio)*100:<11.1f}% {rfix_time:<10.1f}")
    print(f"{'llm-generated':<20} {generated_size:<15} {(1-generated_ratio)*100:<11.1f}% {generated_time:<10.1f}")
    print("="*60)
    
    return stats


def main():
    parser = argparse.ArgumentParser(
        description="OSS-Fuzz reducer benchmark - 对比 ddmin/reducefix/llm-generated"
    )
    parser.add_argument("target", 
                       choices=["pdfium", "harfbuzz", "mupdf", "imagemagick", "libxml2", "poppler", "php-src", "mbedtls", "gdal", "open62541", "ffmpeg"], 
                       help="目标工程")
    parser.add_argument("target_bin", help="可执行文件路径")
    parser.add_argument("input", help="原始 PoC 路径")
    parser.add_argument("out_dir", help="输出目录")
    parser.add_argument("--case-id", help="案例 ID（用于加载 LLM-generated reducer）")
    parser.add_argument("--model-tag", help="模型标签（用于加载 LLM-generated reducer）")
    parser.add_argument("--skip-check", action="store_true", help="跳过初始检查")
    parser.add_argument("--timeout", type=int, default=240, help="Reduce 超时时间（秒，默认240）")
    args = parser.parse_args()
    
    stats = run_single(
        case_id=args.case_id,
        target=args.target,
        target_bin=args.target_bin,
        input_path=args.input,
        out_dir=args.out_dir,
        model_tag=args.model_tag,
        skip_initial_check=args.skip_check,
        timeout=args.timeout
    )
    
    # 输出 JSON（供 shell 脚本解析）
    print("\n=== JSON OUTPUT ===")
    print(json.dumps(stats, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()




#!/usr/bin/env python3
"""
ReduceFix 完整实验流程

正确的流程（参考 AtCoder 的 run.sh）：
1. 为每个 project 生成一次 ReduceFix reducer
2. 对每个 case 运行 3 种缩减方法（ddmin, llm-generated, reducefix）
3. 只用 ReduceFix 缩减的数据进行 Repair（3个策略）
4. 统计并对比结果

使用现有模块：
- reducer_builder.py: 生成 reducer
- bench.py: 运行 3 种缩减方法
- apr_repair.py: 运行 repair（3个策略）
"""

import argparse
import json
import sys
import os
from pathlib import Path
from typing import Dict, List
import subprocess

# 添加项目根目录到路径（用于包导入 oss_fuzz.*）
sys.path.insert(0, str(Path(__file__).parent.parent))

from oss_fuzz_results.reducer_builder import build_reducer
from oss_fuzz_results.apr_repair import run_repair_experiment
from oss_fuzz_results.bench import _map_model_tag_to_llm_name


def run_step1_generate_reducer(project: str, case_id: str, model: str, model_tag: str):
    """步骤 1: 为 project 生成 ReduceFix reducer（只生成一次）"""
    print(f"\n{'='*70}")
    print(f"步骤 1: 为 {project} 生成 ReduceFix Reducer")
    print(f"{'='*70}")
    
    try:
        reducer_path = build_reducer(case_id, model, model_tag)
        print(f"✓ Reducer 生成成功: {reducer_path}")
        return reducer_path
    except Exception as e:
        print(f"✗ Reducer 生成失败: {e}")
        import traceback
        traceback.print_exc()
        return None


def run_step2_reduce(case_id: str, model_tag: str, force: bool = False):
    """步骤 2: 运行 3 种缩减方法（使用 bench.py）"""
    print(f"\n{'='*70}")
    print(f"步骤 2: 缩减 {case_id}（3种方法对比）")
    print(f"{'='*70}")
    
    # 加载案例配置
    with open('oss_fuzz_results/cases.json') as f:
        cases = json.load(f)
    
    if case_id not in cases:
        print(f"✗ 案例不存在: {case_id}")
        return False
    
    config = cases[case_id]
    target = config.get('target')
    data_dir = config.get('data_dir')
    
    if not target or not data_dir:
        print(f"✗ 案例配置不完整：缺少 target 或 data_dir")
        return False
    
    # 从 data_dir 推导出 poc 路径
    poc_path = os.path.join(data_dir, 'testcase')
    if not os.path.exists(poc_path):
        print(f"✗ PoC 文件不存在: {poc_path}")
        return False
    
    # 根据 target 确定可执行文件路径（需要提前从 Docker 提取或配置）
    # 这里假设已经提取到本地
    bin_path_map = {
        'harfbuzz': '/tmp/fuzzer_bins/harfbuzz/hb-subset-fuzzer',
        'mupdf': '/tmp/fuzzer_bins/mupdf/pdf_fuzzer',
        'imagemagick': '/tmp/fuzzer_bins/imagemagick/magick_fuzzer',
        'libxml2': '/tmp/fuzzer_bins/libxml2/xml_fuzzer',
        'poppler': '/tmp/fuzzer_bins/poppler/pdf_fuzzer',
        'php-src': '/tmp/fuzzer_bins/php-src/php-fuzz-parser',  # PHP 有多个 fuzzer，默认使用 parser
    }
    
    bin_path = bin_path_map.get(target)
    
    # 检查是否有 Docker 镜像可用（优先使用 Docker）
    docker_image = config.get('docker_image_vul')
    has_docker = docker_image is not None
    
    # 如果既没有本地 bin 也没有 Docker，则报错
    if not bin_path and not has_docker:
        print(f"✗ 不支持的 target: {target} (既没有本地 fuzzer 路径也没有 Docker 镜像)")
        return False
    
    # 如果没有本地 bin 但有 Docker，使用占位符（bench.py 会自动使用 Docker runner）
    if not bin_path and has_docker:
        bin_path = "/tmp/placeholder_will_use_docker"
        print(f"[Info] 未配置本地 fuzzer，将使用 Docker 运行: {docker_image}")
    
    # 检查可执行文件是否存在（如果使用 Docker 则跳过）
    if not has_docker and not os.path.exists(bin_path):
        print(f"[Info] 可执行文件不存在，尝试从 Docker 容器提取...")
        if not extract_fuzzer_from_docker(case_id, target, bin_path):
            print(f"✗ 无法提取可执行文件")
            return False
    elif has_docker:
        print(f"[Info] 将使用 Docker runner，跳过本地 fuzzer 检查")
    
    # 输出目录（按 target/case_id 组织）
    out_dir = f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}"
    os.makedirs(out_dir, exist_ok=True)
    
    # 检查是否已经完成过缩减（DDMin 是确定性的，无需重复）
    # 需要检查实际的缩减结果文件，而不仅仅是 stats.json
    stats_file = os.path.join(out_dir, "stats.json")
    ddmin_file = os.path.join(out_dir, "reduced.ddmin")
    reducefix_file = os.path.join(out_dir, "reduced.reducefix")
    original_file = os.path.join(out_dir, "original.bin")
    generated_file = os.path.join(out_dir, "reduced.llm_generated")
    
    # 检查关键文件是否都存在
    all_files_exist = all([
        os.path.exists(stats_file),
        os.path.exists(ddmin_file),
        os.path.exists(reducefix_file),
        os.path.exists(original_file)
        # generated 文件在部分情况下可能缺失（跳过/失败），不强制作为完成条件
    ])
    
    if all_files_exist and not force:
        print(f"[Info] 检测到已存在的缩减结果")
        try:
            with open(stats_file, 'r') as f:
                stats = json.load(f)
            
            # 检查缩减是否真的完成（不是0%缩减）
            ddmin_ratio = stats.get('ddmin_compression_ratio', 0)
            reducefix_ratio = stats.get('reducefix_compression_ratio', 0)
            original_size = stats.get('original_size', 0)
            ddmin_size = stats.get('ddmin_size', original_size)
            reducefix_size = stats.get('reducefix_size', original_size)
            
            # 如果所有方法都没有缩减（0%），说明之前失败了
            if ddmin_size == original_size and reducefix_size == original_size:
                print(f"[Warning] 之前的缩减似乎失败了（0% 缩减），将重新运行")
            else:
                print(f"[Info] 之前的结果:")
                print(f"  - 原始大小: {original_size} bytes")
                print(f"  - DDMin 缩减后: {ddmin_size} bytes ({ddmin_ratio*100:.1f}% 缩减)")
                print(f"  - ReduceFix 缩减后: {reducefix_size} bytes ({reducefix_ratio*100:.1f}% 缩减)")
                # 如果有 llm-generated 结果，补充打印
                generated_size = stats.get('generated_size')
                generated_ratio = stats.get('generated_compression_ratio')
                if generated_size is not None and generated_ratio is not None:
                    print(f"  - LLM-Generated: {generated_size} bytes ({generated_ratio*100:.1f}% 缩减)")
                print(f"[Info] ✓ 跳过已完成的缩减（DDMin 是确定性算法）")
                print(f"[Tip] 使用 --force 可强制重新运行")
                return True
        except Exception as e:
            print(f"[Warning] 无法读取已有结果: {e}，将重新运行缩减")
    elif all_files_exist and force:
        print(f"[Info] 检测到已存在的缩减结果，但 --force 已启用，将重新运行")
    elif os.path.exists(stats_file) and not all_files_exist:
        print(f"[Warning] 检测到不完整的缩减结果（缺少某些文件），将重新运行")
    
    print(f"[Info] Target: {target}")
    print(f"[Info] Binary: {bin_path}")
    print(f"[Info] PoC: {poc_path}")
    print(f"[Info] Output: {out_dir}")
    
    # 调用 bench.py
    cmd = [
        "python3", "-m", "oss_fuzz_results.bench",
        target, bin_path, poc_path, out_dir,
        "--case-id", case_id,
        "--model-tag", model_tag
    ]
    
    try:
        result = subprocess.run(cmd, check=True, capture_output=False, text=True)
        print(f"✓ 缩减完成")
        return True
    except subprocess.CalledProcessError as e:
        print(f"✗ 缩减失败: {e}")
        return False


def extract_fuzzer_from_docker(case_id: str, target: str, output_path: str) -> bool:
    """从 Docker 容器中提取 fuzzer 可执行文件"""
    try:
        # 加载案例配置获取 Docker 镜像
        with open('oss_fuzz_results/cases.json') as f:
            cases = json.load(f)
        
        if case_id not in cases:
            return False
        
        docker_image = cases[case_id].get('docker_image_vul')
        if not docker_image:
            return False
        
        # 确定容器内的 fuzzer 路径
        # 注意：不同容器可能有不同的 fuzzer 名称
        # 使用实际检测到的名称
        fuzzer_name_map = {
            'harfbuzz': '/out/hb-subset-fuzzer',
            'mupdf': '/out/pdf_fuzzer',
            'imagemagick': '/out/encoder_png_fuzzer',  # ImageMagick 有多个，默认用 PNG
            'libxml2': '/out/xml',
            'poppler': '/out/pdf_fuzzer',  # 根据容器列出结果
            'php-src': '/out/php-fuzz-parser',  # PHP 有多个 fuzzer，默认使用 parser
        }
        
        fuzzer_path_in_container = fuzzer_name_map.get(target)
        if not fuzzer_path_in_container:
            print(f"[Warning] 未知的 fuzzer 路径 for {target}")
            return False
        
        # 创建输出目录
        os.makedirs(os.path.dirname(output_path), exist_ok=True)
        
        # 从 Docker 复制文件
        print(f"[Info] 从 {docker_image} 复制 {fuzzer_path_in_container}...")
        
        # 启动临时容器
        result = subprocess.run(
            ['docker', 'create', docker_image],
            capture_output=True, text=True, check=True
        )
        container_id = result.stdout.strip()
        
        try:
            # 复制文件
            subprocess.run(
                ['docker', 'cp', f'{container_id}:{fuzzer_path_in_container}', output_path],
                check=True, capture_output=True
            )
            
            # 设置可执行权限
            os.chmod(output_path, 0o755)
            
            print(f"[Success] Fuzzer 提取成功: {output_path}")
            return True
        
        finally:
            # 清理容器
            subprocess.run(['docker', 'rm', container_id], capture_output=True)
        
    except Exception as e:
        print(f"[Error] 提取 fuzzer 失败: {e}")
        import traceback
        traceback.print_exc()
        return False


def run_step3_repair(case_id: str, model_tag: str, repair_model: str = None, force: bool = False):
    """步骤 3: 使用 ReduceFix 缩减数据进行 Repair（3个策略）"""
    print(f"\n{'='*70}")
    print(f"步骤 3: Repair {case_id}（3个策略，使用 ReduceFix 缩减数据）")
    print(f"{'='*70}")
    
    # 读取案例配置获取 target
    cases_file = "oss_fuzz_results/cases.json"
    if not os.path.exists(cases_file):
        print(f"✗ 案例配置不存在: {cases_file}")
        return False
    with open(cases_file, "r", encoding="utf-8") as f:
        cases = json.load(f)
    if case_id not in cases:
        print(f"✗ 案例不存在: {case_id}")
        return False
    case_config = cases[case_id]
    target = case_config.get('target')
    if not target:
        print(f"✗ 案例配置不完整：缺少 target")
        return False
    
    # 检查 ReduceFix 缩减结果（与 bench.py 的输出文件名一致，按 target/case_id 组织）
    reducefix_file = f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}/reduced.reducefix"
    
    if not os.path.exists(reducefix_file):
        print(f"✗ ReduceFix 缩减结果不存在: {reducefix_file}")
        return False
    
    # 构造输出目录（按 target/case_id 组织）
    out_dir_base = f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}"
    # 选择用于修复的模型（CLI > 根据 model_tag 映射 > 默认值）
    model_to_use = repair_model or _map_model_tag_to_llm_name(model_tag) or "deepseek-v3.1"
    # 按 repair 模型隔离输出
    repair_out_dir = os.path.join(out_dir_base, "repair_results", model_to_use)
    os.makedirs(repair_out_dir, exist_ok=True)
    
    # ==================== 检查是否已存在修复结果 ====================
    results_file = os.path.join(repair_out_dir, "results.json")
    patches_dir = os.path.join(repair_out_dir, "patches")
    
    if os.path.exists(results_file) and not force:
        print(f"[Info] 检测到已存在的修复结果")
        try:
            with open(results_file, 'r', encoding='utf-8') as f:
                existing_results = json.load(f)
            
            # 检查patch文件数量
            patch_count = 0
            if os.path.exists(patches_dir):
                patch_count = len([f for f in os.listdir(patches_dir) if f.endswith('.patch')])
            
            # 显示已有结果摘要
            print(f"[Info] 已有结果:")
            for strategy_name in ["without_test", "origin_test", "reduced_test"]:
                strategy_result = existing_results.get(strategy_name, {})
                versions = strategy_result.get("versions", [])
                passed_count = sum(1 for v in versions if v.get("passed"))
                total_count = len(versions)
                status = "✓" if strategy_result.get("passed", False) else "✗"
                print(f"  {status} {strategy_name}: {passed_count}/{total_count} 版本通过")
            
            print(f"  - 补丁文件数: {patch_count}")
            print(f"[Info] ✓ 跳过已完成的修复")
            print(f"[Tip] 使用 --force 可强制重新运行")
            return True
        except Exception as e:
            print(f"[Warning] 无法读取已有结果: {e}，将重新运行修复")
    elif os.path.exists(results_file) and force:
        print(f"[Info] 检测到已存在的修复结果，但 --force 已启用，将重新运行")
    
    # ==================== 开始修复流程 ====================
    print(f"  使用 ReduceFix 缩减结果: {reducefix_file}")
    print(f"  Repair 模型: {model_to_use}")
    
    # 读取原始/缩减测试用例
    original_file = os.path.join(out_dir_base, "original.bin")
    if not os.path.exists(original_file):
        print(f"✗ 原始输入不存在: {original_file}")
        return False
    try:
        with open(original_file, "rb") as f:
            original_bytes = f.read()
        with open(reducefix_file, "rb") as f:
            reduced_bytes = f.read()
    except Exception as e:
        print(f"✗ 读取测试用例失败: {e}")
        return False
    
    # 解析 metadata 作为 crash_info（用于生成 Prompt）
    crash_info = {
        "crash_type": case_config.get("crash_type", "unknown"),
    }
    metadata_path = case_config.get("metadata_file")
    def _extract_stack_top(md: dict) -> str:
        try:
            comments = (((md or {}).get("report") or {}).get("comments")) or []
            if not comments:
                return "unknown"
            content = comments[0].get("content", "")
            marker = "Crash State:\n"
            idx = content.find(marker)
            if idx == -1:
                return "unknown"
            rest = content[idx + len(marker):]
            first_line = rest.splitlines()[0].strip() if rest else "unknown"
            return first_line or "unknown"
        except Exception:
            return "unknown"
    if metadata_path and os.path.exists(metadata_path):
        try:
            with open(metadata_path, "r", encoding="utf-8") as f:
                md = json.load(f)
            crash_info["stack_top"] = _extract_stack_top(md)
            # stderr 可为空，由 Docker 验证阶段实际获取
            crash_info["stderr"] = ""
        except Exception:
            crash_info["stack_top"] = "unknown"
    else:
        crash_info["stack_top"] = "unknown"
        crash_info["stderr"] = ""
    
    print("  开始三策略修复与验证 (no_tc / origin_test / reduced_test)...")
    try:
        results = run_repair_experiment(
            case_config=case_config,
            crash_info=crash_info,
            original_testcase=original_bytes,
            reduced_testcase=reduced_bytes,
            output_dir=repair_out_dir,
            model=model_to_use
        )
    except Exception as e:
        print(f"✗ 修复评估失败: {e}")
        import traceback
        traceback.print_exc()
        return False
    
    # 保存结果（包括补丁）
    try:
        # 1. 提取补丁（在保存 JSON 之前）
        patches = results.pop("patches", {})  # 移除 patches 以免保存到 JSON 中（太大）
        
        # 2. 保存 results.json（不包含补丁内容）
        results_path = os.path.join(repair_out_dir, "results.json")
        with open(results_path, "w", encoding="utf-8") as f:
            json.dump(results, f, ensure_ascii=False, indent=2)
        print(f"[Info] 已保存修复结果: {results_path}")
        
        # 3. 保存所有生成的补丁到单独文件
        patches_dir = os.path.join(repair_out_dir, "patches")
        os.makedirs(patches_dir, exist_ok=True)
        
        saved_count = 0
        for strategy_name, patch_list in patches.items():
            # patch_list 是 List[Optional[str]]，长度为 TOP_K
            if not patch_list:
                continue
            
            for version_idx, patch_code in enumerate(patch_list, start=1):
                if patch_code:  # 只保存成功生成的补丁
                    patch_filename = f"{strategy_name}_v{version_idx}.patch"
                    patch_path = os.path.join(patches_dir, patch_filename)
                    
                    try:
                        with open(patch_path, "w", encoding="utf-8") as pf:
                            pf.write(patch_code)
                        saved_count += 1
                    except Exception as save_err:
                        print(f"[Warning] 保存补丁失败 {patch_filename}: {save_err}")
        
        print(f"[Info] ✓ 已保存 {saved_count} 个补丁到: {patches_dir}")
        
    except Exception as e:
        print(f"[Warning] 修复结果保存失败: {e}")
        import traceback
        traceback.print_exc()
    
    # 简要摘要
    try:
        def _summ(skey: str) -> str:
            r = results.get(skey) or {}
            versions = r.get("versions") or []
            passed = sum(1 for v in versions if v.get("passed"))
            return f"{passed}/{len(versions)}"
        print("\n--- Repair 评估摘要 ---")
        print(f"  without_test: {_summ('without_test')}")
        print(f"  origin_test:  {_summ('origin_test')}")
        print(f"  reduced_test: {_summ('reduced_test')}")
    except Exception:
        pass
    
    return True


def _collect_reduce_stats(case_ids: List[str], model_tag: str) -> Dict:
    """收集并汇总多案例的 reduce 统计（平均压缩率/平均耗时/平均大小）。"""
    import glob
    import statistics
    
    # 读取 cases.json 获取 case_id -> target 的映射
    with open('oss_fuzz_results/cases.json', 'r', encoding='utf-8') as f:
        cases = json.load(f)
    
    per_case = []
    for cid in case_ids:
        # 获取 target
        target = cases.get(cid, {}).get('target')
        if not target:
            continue
        
        # 使用 target/case_id 路径结构
        stats_path = os.path.join("oss_fuzz", "artifacts", target, cid, model_tag, "stats.json")
        if not os.path.exists(stats_path):
            continue
        try:
            with open(stats_path, 'r') as f:
                s = json.load(f)
            per_case.append({
                'case_id': cid,
                'original_size': s.get('original_size'),
                'ddmin_compression_ratio': s.get('ddmin_compression_ratio'),
                'reducefix_compression_ratio': s.get('reducefix_compression_ratio'),
                'generated_compression_ratio': s.get('generated_compression_ratio'),
                'ddmin_time_seconds': s.get('ddmin_time_seconds'),
                'reducefix_time_seconds': s.get('reducefix_time_seconds'),
                'generated_time_seconds': s.get('generated_time_seconds'),
            })
        except Exception:
            continue
    def _avg(key):
        vals = [c[key] for c in per_case if c.get(key) is not None]
        return (sum(vals) / len(vals)) if vals else None
    summary = {
        'model_tag': model_tag,
        'case_count': len(per_case),
        'avg_ddmin_compression_ratio': _avg('ddmin_compression_ratio'),
        'avg_reducefix_compression_ratio': _avg('reducefix_compression_ratio'),
        'avg_generated_compression_ratio': _avg('generated_compression_ratio'),
        'avg_ddmin_time_seconds': _avg('ddmin_time_seconds'),
        'avg_reducefix_time_seconds': _avg('reducefix_time_seconds'),
        'avg_generated_time_seconds': _avg('generated_time_seconds'),
        'cases': per_case,
    }
    return summary


def _print_reduce_summary(project: str, summary: Dict):
    print("\n" + "-"*70)
    print(f"{project} Reduce 汇总 (共 {summary.get('case_count',0)} 个案例)")
    print("-"*70)
    def pct(x):
        return f"{(x*100):.1f}%" if x is not None else "-"
    print(f"ddmin    平均压缩率: {pct(summary.get('avg_ddmin_compression_ratio'))}    平均耗时: {summary.get('avg_ddmin_time_seconds') or '-'}s")
    print(f"reducefix 平均压缩率: {pct(summary.get('avg_reducefix_compression_ratio'))}    平均耗时: {summary.get('avg_reducefix_time_seconds') or '-'}s")
    print(f"llm-gen  平均压缩率: {pct(summary.get('avg_generated_compression_ratio'))}    平均耗时: {summary.get('avg_generated_time_seconds') or '-'}s")


def run_project(project_config: Dict, model: str = "qwen-plus", repair_model: str = None, force: bool = False, skip_build: bool = False, skip_reduce: bool = False, skip_repair: bool = False):
    """运行单个 project 的完整流程"""
    project = project_config['project']
    cases = project_config['cases']
    reducer_case = project_config.get('reducer_case', cases[0])
    
    model_tag = f"reducefix_{model.replace('qwen-plus', 'qwen').replace('qwen2.5-coder-7b-instruct', 'coder7b')}"
    
    print(f"\n{'='*70}")
    print(f"开始处理 Project: {project}")
    print(f"  案例数: {len(cases)}")
    print(f"  Reducer 模型: {model}")
    if repair_model:
        print(f"  Repair  模型: {repair_model}")
    if force:
        print(f"  强制重新运行: 是")
    print(f"{'='*70}")
    
    # 步骤 1: 为 project 生成一次 reducer
    if not skip_build:
        reducer_path = run_step1_generate_reducer(project, reducer_case, model, model_tag)
        if not reducer_path:
            print(f"✗ Project {project} reducer 生成失败，跳过")
            return
    else:
        print(f"[Info] 跳过 Reducer 生成（--skip-build）")
    
    # 步骤 2 & 3: 对每个 case 运行缩减和修复
    for case_id in cases:
        print(f"\n{'='*70}")
        print(f"处理案例: {case_id}")
        print(f"{'='*70}")
        
        # 缩减（3种方法）
        if not skip_reduce:
            if not run_step2_reduce(case_id, model_tag, force=force):
                print(f"✗ {case_id} 缩减失败，跳过 repair")
                continue
        else:
            print(f"[Info] 跳过缩减（--skip-reduce）")
        
        # Repair（只用 ReduceFix 缩减的数据）
        if not skip_repair:
            run_step3_repair(case_id, model_tag, repair_model=repair_model, force=force)
        else:
            print(f"[Info] 跳过 Repair（--skip-repair）")

    # 汇总 Reduce 统计（即使跳过 repair 也做汇总）
    try:
        case_ids = project_config['cases']
        summary = _collect_reduce_stats(case_ids, model_tag)
        _print_reduce_summary(project, summary)
        # 保存到 experiment_results
        os.makedirs("oss_fuzz/experiment_results", exist_ok=True)
        out_path = os.path.join("oss_fuzz/experiment_results", f"{project}_{model_tag}_reduce_summary.json")
        with open(out_path, 'w', encoding='utf-8') as f:
            json.dump(summary, f, ensure_ascii=False, indent=2)
        print(f"[Info] Reduce 汇总已保存: {out_path}")
    except Exception as e:
        print(f"[Warning] 汇总 Reduce 统计失败: {e}")
    
    print(f"\n✓ Project {project} 处理完成")


def main():
    parser = argparse.ArgumentParser(
        description="ReduceFix 完整实验流程（正确版本）"
    )
    parser.add_argument(
        "--project",
        help="指定单个 project（如 harfbuzz）"
    )
    parser.add_argument(
        "--model",
        default="qwen-plus",
        help="Reducer 生成模型（默认: qwen-plus）"
    )
    parser.add_argument(
        "--repair-model",
        help="Repair 使用的模型（默认: deepseek-v3.1）"
    )
    parser.add_argument(
        "--timeout",
        type=int,
        default=300,
        help="Reduce 超时时间（秒，默认300）"
    )
    parser.add_argument(
        "--skip-build",
        action="store_true",
        help="跳过 reducer 生成"
    )
    parser.add_argument(
        "--skip-reduce",
        action="store_true",
        help="跳过 reduce 阶段"
    )
    parser.add_argument(
        "--skip-repair",
        action="store_true",
        help="跳过 repair 阶段"
    )
    parser.add_argument(
        "--all",
        action="store_true",
        help="运行所有 projects"
    )
    parser.add_argument(
        "--force",
        action="store_true",
        help="强制重新运行已完成的缩减（即使结果已存在）"
    )
    
    args = parser.parse_args()
    
    # 加载项目分组配置
    project_groups_file = "oss_fuzz/project_groups.json"
    
    if not os.path.exists(project_groups_file):
        print(f"[错误] 项目分组配置不存在: {project_groups_file}")
        print(f"请先运行脚本生成配置")
        sys.exit(1)
    
    with open(project_groups_file) as f:
        projects = json.load(f)
    
    # 筛选要运行的 projects
    if args.project:
        projects = [p for p in projects if p['project'] == args.project]
        if not projects:
            print(f"[错误] Project 不存在: {args.project}")
            sys.exit(1)
    elif not args.all:
        print("[提示] 请使用 --project <name> 或 --all")
        print(f"可用的 projects:")
        for p in projects:
            print(f"  - {p['project']} ({len(p['cases'])} cases)")
        sys.exit(0)
    
    # 运行实验
    for project_config in projects:
        try:
            run_project(project_config, args.model, repair_model=args.repair_model, force=args.force, skip_build=args.skip_build, skip_reduce=args.skip_reduce, skip_repair=args.skip_repair)
        except KeyboardInterrupt:
            print(f"\n⚠ 用户中断")
            break
        except Exception as e:
            print(f"\n✗ Project {project_config['project']} 运行失败: {e}")
            import traceback
            traceback.print_exc()
            continue
    
    print(f"\n{'='*70}")
    print("ReduceFix 实验完成！")
    print(f"{'='*70}")


if __name__ == "__main__":
    main()


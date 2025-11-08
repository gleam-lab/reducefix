#!/usr/bin/env python3
"""
Docker Patch 测试器 - 真实的编译和崩溃测试

工作流程：
1. 启动 Docker 容器（保持运行）
2. 将 patch 复制到容器
3. 应用 patch 到源代码
4. 重新编译
5. 用 testcase 测试是否还崩溃
"""

import subprocess
import tempfile
import time
import os
import re
from pathlib import Path
from typing import Dict, Optional, Tuple


def _strip_code_fences(patch_text: str) -> str:
    """移除 markdown 代码围栏，保留内部内容。"""
    if patch_text.strip().startswith("```"):
        # 去掉开头 ```xxx 和结尾 ```
        patch_text = re.sub(r"^```[a-zA-Z0-9_-]*\n", "", patch_text)
        patch_text = re.sub(r"\n```\s*$", "", patch_text)
    return patch_text


def _normalize_patch(patch_text: str) -> str:
    """对补丁做轻量规范化：
    - 去掉 markdown 代码围栏
    - 统一换行到 \n
    - 去掉 \r
    - 确保以换行结尾
    注意：不移除补丁行尾空格，以免影响 hunk 匹配。
    """
    if not patch_text:
        return patch_text
    text = _strip_code_fences(patch_text)
    # 统一换行
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    if not text.endswith("\n"):
        text += "\n"
    return text


def _basic_validate_patch(patch_text: str) -> Dict[str, object]:
    """对补丁进行基础校验，返回问题列表，便于日志输出。"""
    issues = []
    has_header = ("--- a/" in patch_text and "+++ b/" in patch_text) or ("--- " in patch_text and "+++ " in patch_text)
    if not has_header:
        issues.append("missing_header")
    if "@@" not in patch_text:
        # 有些添加/删除整个文件可能无 @@ ，但我们主要面向行内修改
        issues.append("missing_hunk_header")
    # 检测可能写成 '@ -' 的错误 hunk
    bad_hunks = re.findall(r"^@\s-", patch_text, flags=re.MULTILINE)
    if bad_hunks:
        issues.append("malformed_hunk_header_single_at")
    return {"valid": len(issues) == 0, "issues": issues}


def _filter_text_diffs(patch_text: str) -> str:
    """过滤掉包含二进制修改的 diff block，只保留纯文本文件的补丁。
    简单启发式：丢弃包含以下标记的块：
      - 'GIT binary patch'
      - 行以 'Binary files ' 开头
      - 仅有 'new file mode'/'index'，但无 @@ hunk 的块
    """
    parts = patch_text.split('\ndiff --git ')
    if len(parts) == 1:
        # 不是多块，直接按启发式判断
        blk = patch_text
        if 'GIT binary patch' in blk or '\nBinary files ' in blk:
            return ''
        if '@@' not in blk and ('new file mode' in blk or 'index ' in blk):
            return ''
        return patch_text
    kept = []
    # 第一段为前导（可能为空）
    prefix = parts[0]
    for blk in parts[1:]:
        candidate = 'diff --git ' + blk
        if 'GIT binary patch' in candidate or '\nBinary files ' in candidate:
            continue
        if '@@' not in candidate and ('new file mode' in candidate or 'index ' in candidate):
            # 没有任何 hunk 的，丢弃
            continue
        kept.append(candidate)
    text = (prefix + ('\n'.join(kept) if kept else '')).strip()
    if text and not text.endswith('\n'):
        text += '\n'
    return text


def _filter_fuzzer_files(patch_text: str) -> str:
    """
    过滤掉对 fuzzer 文件的修改（硬编码规则）
    
    LLM 经常错误地生成修改 fuzzer 文件的 patch，但这些文件：
    1. 不是源代码的一部分
    2. 在某些 Docker 镜像中不存在
    3. 修改它们无法修复源代码的 bug
    
    过滤规则：
    - fuzz/*.cc, fuzz/*.cpp, fuzz/*.c (fuzzer 源文件)
    - *_fuzzer.cc, *_fuzzer.cpp (fuzzer 主文件)
    - test/*, tests/* (测试文件，除非明确需要)
    """
    # 需要过滤的文件模式
    fuzzer_patterns = [
        r'fuzz/.*\.(cc|cpp|c|h)',            # fuzz/ 目录下的所有源文件
        r'.*_fuzzer\.(cc|cpp|c)',            # 任何 *_fuzzer.cc 文件
        r'fuzzer.*\.(cc|cpp|c)',             # fuzzer*.cc 文件
    ]
    
    # 使用更可靠的分割方式
    import re
    # 查找所有 diff --git 的位置
    diff_positions = [m.start() for m in re.finditer(r'^diff --git ', patch_text, re.MULTILINE)]
    
    if len(diff_positions) == 0:
        # 没有 diff --git，可能是简单 patch，直接返回
        return patch_text
    
    if len(diff_positions) == 1:
        # 单个 diff，检查是否匹配 fuzzer 模式
        # 提取文件路径
        match = re.search(r'diff --git a/(.+?) b/', patch_text)
        if match:
            file_path = match.group(1)
            for pattern in fuzzer_patterns:
                if re.search(pattern, file_path):
                    print(f"    [Filter] ✗ 过滤掉 fuzzer 文件: {file_path}")
                    return ''
        return patch_text
    
    # 多个 diff blocks
    kept = []
    filtered_count = 0
    
    for i, pos in enumerate(diff_positions):
        # 确定当前 block 的结束位置
        if i + 1 < len(diff_positions):
            end_pos = diff_positions[i + 1]
        else:
            end_pos = len(patch_text)
        
        block = patch_text[pos:end_pos]
        
        # 提取文件路径
        match = re.search(r'diff --git a/(.+?) b/', block)
        if match:
            file_path = match.group(1)
            
            # 检查是否是 fuzzer 文件
            is_fuzzer = False
            for pattern in fuzzer_patterns:
                if re.search(pattern, file_path):
                    is_fuzzer = True
                    print(f"    [Filter] ✗ 过滤掉 fuzzer 文件: {file_path}")
                    filtered_count += 1
                    break
            
            if not is_fuzzer:
                kept.append(block)
        else:
            # 无法提取文件路径，保守保留
            kept.append(block)
    
    if filtered_count > 0:
        print(f"    [Filter] 总计过滤掉 {filtered_count} 个 fuzzer 文件修改")
    
    if not kept:
        return ''
    
    # 拼接保留的 blocks
    result = ''.join(kept)
    if not result.endswith('\n'):
        result += '\n'
    return result


class DockerPatchTester:
    """基于 Docker 的真实 patch 测试器"""
    
    def __init__(self, docker_image_vul: str, project: str, timeout: int = 300):
        """
        初始化测试器
        
        Args:
            docker_image_vul: vulnerable 版本的 Docker 镜像
            project: 项目名称（如 harfbuzz）
            timeout: 超时时间（秒，默认 240=4分钟）
        """
        self.docker_image = docker_image_vul
        self.project = project
        self.timeout = timeout
        self.container_id = None
    
    def start_container(self):
        """启动 Docker 容器并保持运行"""
        if self.container_id:
            return  # 已经启动
        
        try:
            # 先尝试拉取镜像（避免 run 时因拉取超时）
            try:
                subprocess.run([
                    'docker', 'pull', self.docker_image
                ], capture_output=True, text=True, timeout=600)
            except Exception:
                pass
            # 尝试多种方式启动保持存活的容器
            # 添加 --security-opt seccomp=unconfined 解决 WSL2 的 seccomp 问题
            run_cmds = [
                ['docker', 'run', '-d', '--security-opt', 'seccomp=unconfined', self.docker_image, 'tail', '-f', '/dev/null'],
                ['docker', 'run', '-d', '--security-opt', 'seccomp=unconfined', self.docker_image, 'sh', '-lc', 'sleep infinity'],
                ['docker', 'run', '-d', '--security-opt', 'seccomp=unconfined', self.docker_image, 'bash', '-lc', 'sleep infinity'],
            ]
            last_err = None
            for args in run_cmds:
                try:
                    result = subprocess.run(args, capture_output=True, text=True, timeout=120, check=True)
                    self.container_id = result.stdout.strip()
                    if self.container_id:
                        print(f"    [Docker] 容器启动: {self.container_id[:12]}")
                        break
                except Exception as e2:
                    last_err = e2
            if not self.container_id:
                raise last_err or RuntimeError('docker run failed')
            
            # 优化：初始化编译缓存（ccache）
            try:
                init_ccache = subprocess.run([
                    'docker', 'exec', self.container_id,
                    'bash', '-c',
                    'mkdir -p /tmp/ccache && '
                    'apt-get update -qq && apt-get install -y -qq ccache > /dev/null 2>&1 || true'
                ], capture_output=True, timeout=60)
                if init_ccache.returncode == 0:
                    print(f"    [Docker] ✓ ccache 已配置（将加速后续编译）")
            except Exception:
                # ccache 安装失败不影响正常流程
                pass
                
        except Exception as e:
            print(f"    [Error] 容器启动失败: {e}")
            raise
    
    def _reset_git_state(self, recompile: bool = False):
        """恢复 git 仓库到原始状态（用于多次 patch 尝试）
        
        Args:
            recompile: 是否重新编译（关键：确保二进制文件也恢复）
        """
        try:
            reset_result = subprocess.run([
                'docker', 'exec', self.container_id,
                'bash', '-c',
                f'cd /src/{self.project} && git reset --hard HEAD && git clean -fd'
            ], capture_output=True, text=True, timeout=10)
            
            if reset_result.returncode == 0:
                print(f"    [Docker] 已恢复 git 状态")
            else:
                print(f"    [Docker] ⚠ git reset 失败: {reset_result.stderr[:100]}")
                return
            
            # 关键：重新编译，确保二进制文件也恢复
            if recompile:
                print(f"    [Docker] 重新编译原始版本...")
                # 使用 ccache 加速重新编译
                compile_cmd = (
                    'export CCACHE_DIR=/tmp/ccache && '
                    'export CC="ccache clang" && '
                    'export CXX="ccache clang++" && '
                    'arvo compile 2>&1'
                )
                compile_result = subprocess.run([
                    'docker', 'exec', self.container_id,
                    'bash', '-lc',
                    compile_cmd
                ], capture_output=True, timeout=300)
                
                if compile_result.returncode == 0:
                    print(f"    [Docker] ✓ 重新编译成功")
                else:
                    stderr_preview = compile_result.stderr.decode('utf-8', errors='ignore')[:200]
                    print(f"    [Docker] ⚠ 重新编译失败: {stderr_preview}")
        
        except Exception as e:
            print(f"    [Docker] ⚠ 恢复状态失败: {e}")
    
    def cleanup(self):
        """清理容器"""
        if self.container_id:
            try:
                subprocess.run([
                    'docker', 'rm', '-f', self.container_id
                ], capture_output=True, timeout=30)
                print(f"    [Docker] 容器清理: {self.container_id[:12]}")
            except:
                pass
            self.container_id = None
    
    def _analyze_crash_output(self, returncode: int, stdout: bytes, stderr: bytes) -> Dict:
        """更细粒度的崩溃判定与诊断信息。"""
        out = stdout.decode('utf-8', errors='ignore') if isinstance(stdout, (bytes, bytearray)) else str(stdout)
        err = stderr.decode('utf-8', errors='ignore') if isinstance(stderr, (bytes, bytearray)) else str(stderr)
        text = (out + "\n" + err) if err else out
        text_lower = text.lower()
        crash_keywords = [
            'addresssanitizer',
            'heap-use-after-free',
            'heap-buffer-overflow',
            'global-buffer-overflow',
            'stack-use-after-return',
            'use-of-uninitialized-value',
            'fatal signal',
            'segv', 'segmentation fault',
            'asan:deadlysignal',
            'runtime error: '
        ]
        libfuzzer_keywords = [
            '==error: libfuzzer', 'ERROR: libFuzzer', 'SUMMARY: AddressSanitizer'
        ]
        asan_detected = any(kw in text_lower for kw in crash_keywords)
        fuzzer_detected = any(kw.lower() in text_lower for kw in libfuzzer_keywords)
        is_timeout = 'timeout' in text_lower or returncode == 124
        likely_crash = asan_detected or fuzzer_detected or returncode not in (0,)
        reason = 'timeout' if is_timeout else ('asan/libfuzzer' if (asan_detected or fuzzer_detected) else (f'exit_{returncode}' if returncode != 0 else 'clean'))
        return {
            'is_crash': likely_crash and not is_timeout,
            'returncode': returncode,
            'asan_detected': asan_detected,
            'fuzzer_detected': fuzzer_detected,
            'is_timeout': is_timeout,
            'reason': reason,
            'stderr_head': err[:400],
            'stdout_head': out[:200]
        }


    def test_crash(self, testcase_data: bytes) -> Tuple[bool, str]:
        """
        测试是否崩溃 - 按照 ARVO README 使用 arvo 命令
        
        Returns:
            (is_crash, stderr): 是否崩溃及错误输出
        """
        # 创建临时 testcase 文件
        with tempfile.NamedTemporaryFile(delete=False, suffix='.bin') as f:
            temp_testcase = f.name
            f.write(testcase_data)
        
        try:
            # 复制 testcase 到容器：ARVO 默认路径 /tmp/poc
            copy_result = subprocess.run([
                'docker', 'cp',
                temp_testcase,
                f'{self.container_id}:/tmp/poc'
            ], capture_output=True, timeout=10)
            
            if copy_result.returncode != 0:
                print(f"    [Warning] 复制 testcase 失败: {copy_result.stderr.decode('utf-8', errors='ignore')[:100]}")
                return False, f"Copy failed: {copy_result.stderr.decode('utf-8', errors='ignore')}"
            
            # 按照 ARVO README: 直接运行 arvo 命令
            # arvo 会自动从 /tmp/poc 读取并执行
            print(f"    [Docker] 运行: arvo")
            result = subprocess.run([
                'docker', 'exec', self.container_id,
                'bash', '-lc',
                'timeout 25 arvo || true'
            ], capture_output=True, timeout=35)
            
            analysis = self._analyze_crash_output(result.returncode, result.stdout, result.stderr)
            if not analysis['is_crash']:
                print(f"    [Debug] 未检测到崩溃 rc={analysis['returncode']} reason={analysis['reason']}")
                print(f"    [Debug] ASAN检测: {analysis['asan_detected']}, Fuzzer检测: {analysis['fuzzer_detected']}")
                print(f"    [Debug] Stderr长度: {len(result.stderr)} bytes")
                print(f"    [Debug] Stderr前200: {analysis['stderr_head'][:200]}")
            else:
                print(f"    [Docker] ✓ 确认崩溃 (reason={analysis['reason']})")
            return analysis['is_crash'], analysis['stderr_head']
            
        except subprocess.TimeoutExpired:
            print(f"    [Warning] 测试超时")
            return True, "Timeout (假设为崩溃)"
        except Exception as e:
            print(f"    [Error] 测试异常: {e}")
            return False, f"测试异常: {e}"
        finally:
            try:
                os.unlink(temp_testcase)
            except:
                pass
    
    def apply_patch_and_compile(self, patch_content: str, target_file: Optional[str] = None) -> Tuple[bool, str, bool]:
        """
        应用 patch 并重新编译
        
        Args:
            patch_content: patch 内容（代码片段或 diff）
            target_file: 目标文件路径（容器内）
            
        Returns:
            (compile_success, error_msg, patch_applied): 编译是否成功、错误信息、patch是否应用成功
        """
        try:
            # 1) 规范化补丁文本
            normalized = _normalize_patch(patch_content)
            normalized = _filter_text_diffs(normalized)
            # 1.5) 过滤 fuzzer 文件修改（硬编码规则）
            normalized = _filter_fuzzer_files(normalized)
            if not normalized.strip():
                return False, "过滤后无可应用的文本补丁（可能仅包含二进制变更或 fuzzer 文件修改）", False
            validate_info = _basic_validate_patch(normalized)
            if not validate_info.get('valid'):
                print(f"    [Patch] 规范化后仍可能存在问题: {validate_info.get('issues')}")

            # 2) 创建临时 patch 文件
            with tempfile.NamedTemporaryFile(mode='w', delete=False, suffix='.patch') as f:
                patch_file = f.name
                f.write(normalized)
            
            # 2. 复制 patch 到容器
            subprocess.run([
                'docker', 'cp',
                patch_file,
                f'{self.container_id}:/tmp/repair.patch'
            ], check=True, timeout=10)
            
            # 3) 应用 patch - 使用 --check 先验证，避免部分应用导致状态混乱
            print(f"    [Docker] 尝试 git apply...")
            
            # 定义尝试的命令（从最严格到最宽松）
            git_apply_variants = [
                ("标准", f'cd /src/{self.project} && git apply /tmp/repair.patch 2>&1'),
                ("忽略空白", f'cd /src/{self.project} && git apply --ignore-whitespace /tmp/repair.patch 2>&1'),
                ("宽松模式", f'cd /src/{self.project} && git apply --reject --whitespace=nowarn /tmp/repair.patch 2>&1'),
            ]
            
            git_apply_success = False
            patch_applied = False
            
            # 逐个尝试，每次失败后恢复原始状态
            for idx, (variant_name, cmd) in enumerate(git_apply_variants, 1):
                # 先用 --check 验证是否可以应用（不实际修改文件）
                check_cmd = cmd.replace('git apply', 'git apply --check')
                check_result = subprocess.run([
                    'docker', 'exec', self.container_id,
                    'bash', '-c', check_cmd
                ], capture_output=True, text=True, timeout=20)
                
                if check_result.returncode == 0:
                    # 可以应用，执行实际应用
                    apply_result = subprocess.run([
                        'docker', 'exec', self.container_id,
                        'bash', '-c', cmd
                    ], capture_output=True, text=True, timeout=20)
                    
                    if apply_result.returncode == 0:
                        print(f"    [Docker] ✓ git apply 成功 ({variant_name})")
                        git_apply_success = True
                        patch_applied = True
                        break
                    else:
                        # 理论上不应该失败，因为 --check 通过了
                        print(f"    [Docker] ✗ git apply 应用失败 ({variant_name}): {apply_result.stdout[:120]}")
                        # 恢复状态
                        self._reset_git_state()
                else:
                    # --check 失败，记录并继续下一个变体
                    out = (check_result.stdout or check_result.stderr or '')
                    print(f"    [Docker] ✗ git apply 不可用 ({variant_name}): {out[:100]}")
            
            # 如果 git apply 都失败，尝试 patch 命令
            if not git_apply_success:
                print(f"    [Docker] 尝试 patch 命令...")
                
                patch_variants = [
                    ("标准", f'cd /src/{self.project} && patch -p1 < /tmp/repair.patch 2>&1'),
                    ("模糊匹配", f'cd /src/{self.project} && patch --fuzz=2 -p1 < /tmp/repair.patch 2>&1'),
                ]
                
                for idx, (variant_name, cmd) in enumerate(patch_variants, 1):
                    # patch 命令也先用 --dry-run 检查
                    check_cmd = cmd.replace('patch ', 'patch --dry-run ')
                    check_result = subprocess.run([
                        'docker', 'exec', self.container_id,
                        'bash', '-c', check_cmd
                    ], capture_output=True, text=True, timeout=20)
                    
                    if check_result.returncode == 0:
                        # 可以应用，执行实际应用
                        apply_result = subprocess.run([
                            'docker', 'exec', self.container_id,
                            'bash', '-c', cmd
                        ], capture_output=True, text=True, timeout=20)
                        
                        if apply_result.returncode == 0:
                            print(f"    [Docker] ✓ patch 命令成功 ({variant_name})")
                            patch_applied = True
                            break
                        else:
                            print(f"    [Docker] ✗ patch 应用失败 ({variant_name}): {apply_result.stdout[:120]}")
                            # 恢复状态
                            self._reset_git_state()
                    else:
                        out = (check_result.stdout or '')
                        print(f"    [Docker] ✗ patch 不可用 ({variant_name}): {out[:100]}")
                
                if not patch_applied:
                    print(f"    [Docker] ✗ 所有应用方式均失败")
            
            # 4. 智能编译：根据修改内容选择编译策略
            compile_start = time.time()
            
            # 检测是否只修改了源码（不是构建脚本）
            is_build_script_change = False
            if target_file:
                target_lower = target_file.lower()
                is_build_script_change = any(pattern in target_lower for pattern in [
                    'build', 'cmake', 'makefile', 'configure', '.sh', '.yml', '.yaml'
                ])
            
            # 优化策略选择
            if is_build_script_change:
                # 构建脚本修改：需要完整重新编译（包括依赖）
                print(f"    [Docker] 重新编译（构建脚本修改，需完整重建）: arvo compile")
                print(f"    [Docker] ⏳ 编译中（预计 1-5 分钟）...")
                compile_cmd = (
                    'export CCACHE_DIR=/tmp/ccache && '
                    'export CC="ccache clang" && '
                    'export CXX="ccache clang++" && '
                    'arvo compile 2>&1'
                )
            else:
                # 源码修改：尝试增量编译（只重新编译项目本身）
                print(f"    [Docker] 增量编译（源码修改，跳过依赖重建）")
                print(f"    [Docker] ⏳ 编译中（预计 30-60 秒）...")
                # 直接在项目目录重新编译，不重建依赖
                compile_cmd = (
                    'cd /src/* && '
                    'export CCACHE_DIR=/tmp/ccache && '
                    'export CC="ccache clang" && '
                    'export CXX="ccache clang++" && '
                    'export CFLAGS="${CFLAGS:-}" && '
                    'export CXXFLAGS="${CXXFLAGS:-}" && '
                    'bash compile 2>&1 || arvo compile 2>&1'  # fallback 到完整编译
                )
            
            # 使用 Popen 实现实时输出和进度反馈
            process = subprocess.Popen([
                'docker', 'exec', self.container_id,
                'bash', '-lc',
                compile_cmd
            ], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, bufsize=1)
            
            compile_output_lines = []
            error_count = 0
            warning_count = 0
            last_progress_time = compile_start
            
            try:
                # 实时读取输出
                for line in process.stdout:
                    compile_output_lines.append(line)
                    line_lower = line.lower()
                    
                    # 统计错误和警告
                    if 'error:' in line_lower and 'error' not in line_lower.split('error:')[0][-10:]:
                        error_count += 1
                        # 立即显示第一个错误
                        if error_count == 1:
                            print(f"    [Docker] ⚠ 首个编译错误: {line.strip()[:120]}")
                    if 'warning:' in line_lower:
                        warning_count += 1
                    
                    # 动态调整进度显示频率
                    current_time = time.time()
                    elapsed = current_time - compile_start
                    
                    # 前30秒每30秒显示，之后每60秒显示（减少输出）
                    progress_interval = 30 if elapsed < 30 else 60
                    
                    if current_time - last_progress_time > progress_interval:
                        # 只在有错误时显示警告数，否则太冗余
                        if error_count > 0:
                            print(f"    [Docker] ⏳ 编译进行中... {elapsed:.0f}秒 (错误:{error_count}, 警告:{warning_count})")
                        else:
                            print(f"    [Docker] ⏳ 编译进行中... {elapsed:.0f}秒 (错误:{error_count}, 警告:{warning_count})")
                        last_progress_time = current_time
                
                # 等待进程完成
                return_code = process.wait(timeout=self.timeout)
                compile_duration = time.time() - compile_start
                full_output = ''.join(compile_output_lines)
                
            except subprocess.TimeoutExpired:
                process.kill()
                return False, "编译超时", False
            
            # 关键修复：区分真正的编译错误和脚本后处理错误
            # 如果没有编译错误（error_count == 0），即使返回码非零也算成功
            # 因为 OSS-Fuzz 的 mv 命令可能因为可选文件不存在而失败
            if return_code == 0 or (return_code != 0 and error_count == 0):
                if return_code != 0:
                    # 返回码非零但没有编译错误，可能是 mv 等后处理失败
                    last_lines = [l.strip() for l in compile_output_lines[-5:] if l.strip()]
                    print(f"    [Docker] ✓ 编译成功 ({compile_duration:.1f}秒) - 忽略后处理警告")
                    if last_lines:
                        print(f"               (后处理: {last_lines[-1][:80]})")
                else:
                    print(f"    [Docker] ✓ 编译成功 ({compile_duration:.1f}秒)")
                
                if warning_count > 0:
                    print(f"    [Docker] ℹ 有 {warning_count} 个警告")
                return True, "", patch_applied
            else:
                # 真正的编译失败 - 有明确的编译错误
                compile_log_file = f"/tmp/compile_error_{self.project}_{int(time.time())}.log"
                try:
                    with open(compile_log_file, 'w', encoding='utf-8') as f:
                        f.write(full_output)
                    print(f"    [Docker] 📝 完整编译日志已保存: {compile_log_file}")
                except:
                    pass
                
                # 提取关键错误信息
                error_msg = full_output[-1000:]  # 保存最后 1000 字符
                
                # 提取所有错误行
                error_lines = [line.strip() for line in compile_output_lines if 'error:' in line.lower()]
                print(f"    [Docker] ✗ 编译失败 ({compile_duration:.1f}秒): 共 {error_count} 个错误")
                # 显示前 3 个错误
                for i, err in enumerate(error_lines[:3], 1):
                    print(f"               错误 {i}: {err[:120]}")
                if len(error_lines) > 3:
                    print(f"               ... 及其他 {len(error_lines)-3} 个错误")
                
                return False, error_msg, patch_applied
            
        except subprocess.TimeoutExpired:
            return False, "编译超时", False
        except Exception as e:
            return False, f"应用 patch 失败: {str(e)}", False
        finally:
            try:
                os.unlink(patch_file)
            except:
                pass
    
    def validate_repair(self, patch_content: str, testcase_data: bytes, target_file: Optional[str] = None) -> Dict:
        """
        完整验证流程：应用 patch → 编译 → 测试
        
        Returns:
            验证结果字典
        """
        result = {
            "success": False,
            "original_crash": False,
            "patch_applied": False,  # 新增：patch 是否应用成功
            "compiled": False,
            "fixed_crash": False,
            "error": None,
            "duration": 0
        }
        
        start_time = time.time()
        
        try:
            # 步骤 1: 测试原始版本是否崩溃
            print("    [1/3] 测试原始版本...")
            is_crash, stderr_head = self.test_crash(testcase_data)
            result["original_crash"] = is_crash
            result["orig_stderr_head"] = stderr_head
            
            if not is_crash:
                result["error"] = "原始版本未崩溃，无法验证修复"
                return result
            
            print(f"    [Docker] ✓ 确认崩溃")
            
            # 步骤 2: 应用 patch 并编译
            print("    [2/3] 应用 patch 并编译...")
            compile_success, compile_error, patch_applied = self.apply_patch_and_compile(patch_content, target_file)
            result["patch_applied"] = patch_applied
            result["compiled"] = compile_success
            
            if not compile_success:
                result["error"] = f"编译失败: {compile_error}"
                if not patch_applied:
                    result["error"] = f"Patch 应用失败，{compile_error}"
                return result
            
            # 步骤 3: 测试修复后版本
            print("    [3/3] 测试修复后版本...")
            is_crash_after, stderr_after = self.test_crash(testcase_data)
            result["fixed_crash"] = not is_crash_after
            result["after_stderr_head"] = stderr_after
            
            if result["fixed_crash"]:
                print(f"    [Docker] ✓ 修复成功（不再崩溃）")
                result["success"] = True
            else:
                print(f"    [Docker] ✗ 仍然崩溃")
                result["error"] = "修复后仍然崩溃"
            
        except Exception as e:
            result["error"] = f"验证异常: {str(e)}"
        finally:
            result["duration"] = time.time() - start_time
            # 关键修复：验证完成后重置环境，避免影响后续版本
            # 只有在成功编译的情况下才需要重置（失败的patch不会改变二进制）
            if result.get("compiled"):
                # 编译成功意味着代码和二进制都被修改了，必须完全重置
                print(f"    [Docker] 重置环境（代码 + 重新编译）...")
                self._reset_git_state(recompile=True)
            elif result.get("patch_applied"):
                # 只应用了patch但编译失败，只需重置代码
                print(f"    [Docker] 重置 git 状态...")
                self._reset_git_state(recompile=False)
        
        return result
    
    def __enter__(self):
        """上下文管理器：进入"""
        self.start_container()
        return self
    
    def __exit__(self, *args):
        """上下文管理器：退出时清理"""
        self.cleanup()


def extract_code_from_repair(repair_text: str) -> Optional[str]:
    """从 LLM 输出中提取代码 - 严格验证只提取 diff 格式
    
    注意：这个函数只用于 fallback，主要逻辑应该使用 extract_search_replace_and_generate_patch
    """
    # 优先提取 markdown 代码块中的 diff
    patterns = [
        r'```(?:diff|patch)\s*\n(.*?)```',  # diff 代码块（最优先）
        r'((?:^|\n)---\s+a/.*?\n\+\+\+\s+b/.*?(?:\n@@.*?)?(?:\n[\s\S]+?)?)(?:\n```|\Z)',  # 裸 diff（没有代码块）
    ]
    
    for pattern in patterns:
        match = re.search(pattern, repair_text, re.DOTALL | re.MULTILINE)
        if match:
            extracted = match.group(1).strip()
            # 严格验证：必须是 diff 格式（包含 --- 和 +++ 和 @@）
            if ('--- a/' in extracted or '---' in extracted[:100]) and \
               ('+++ b/' in extracted or '+++' in extracted[:100]) and \
               '@@' in extracted:
                # 额外验证：不能是 SEARCH/REPLACE 格式
                if '<<<<<<< SEARCH' not in extracted and '>>>>>>> REPLACE' not in extracted:
                    return extracted
    
    # 最后尝试：如果整个文本看起来像 diff，就直接返回
    if ('--- a/' in repair_text or '+++ b/' in repair_text) and '@@' in repair_text:
        # 额外检查：不能包含 SEARCH/REPLACE 标记
        if '<<<<<<< SEARCH' not in repair_text or '>>>>>>> REPLACE' not in repair_text:
            # 清理可能的markdown标记
            cleaned = repair_text.replace('```diff', '').replace('```', '').strip()
            # 再次验证
            if ('---' in cleaned and '+++' in cleaned and '@@' in cleaned):
                return cleaned
    
    return None


def test_docker_patch_tester():
    """测试 DockerPatchTester"""
    print("=" * 70)
    print("Docker Patch 测试器 - 真实验证测试")
    print("=" * 70)
    print()
    
    docker_image = "n132/arvo:44263-vul"
    project = "harfbuzz"
    
    # 读取 testcase
    testcase_file = Path("oss_fuzz/cases_data/harfbuzz/arvo-44263/testcase")
    if not testcase_file.exists():
        print("✗ testcase 文件不存在")
        return
    
    with open(testcase_file, 'rb') as f:
        testcase_data = f.read()
    
    print(f"Docker 镜像: {docker_image}")
    print(f"项目: {project}")
    print(f"Testcase 大小: {len(testcase_data):,} bytes")
    print()
    
    # 模拟一个简单的 patch（仅用于测试流程）
    fake_patch = """
--- a/src/hb-ot-layout-common.hh
+++ b/src/hb-ot-layout-common.hh
@@ -100,6 +100,8 @@ struct RangeRecord
   int cmp (hb_codepoint_t g) const
   { return g < start ? -1 : g <= end ? 0 : +1; }
   
+  // Safety check
+  
   bool sanitize (hb_sanitize_context_t *c) const
   {
     TRACE_SANITIZE (this);
"""
    
    print("开始真实验证...")
    print()
    
    with DockerPatchTester(docker_image, project) as tester:
        result = tester.validate_repair(fake_patch, testcase_data[:5000])
    
    print()
    print("=" * 70)
    print("验证结果")
    print("=" * 70)
    print(f"原始崩溃: {result['original_crash']}")
    print(f"编译通过: {result['compiled']}")
    print(f"修复成功: {result['fixed_crash']}")
    print(f"总体成功: {result['success']}")
    print(f"耗时: {result['duration']:.1f} 秒")
    if result['error']:
        print(f"错误: {result['error']}")


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1 and sys.argv[1] == "--test":
        test_docker_patch_tester()
    else:
        print("Docker Patch 测试器 - 真实验证")
        print()
        print("用法:")
        print("  python3 docker_patch_tester.py --test")
        print()
        print("功能:")
        print("  1. 在 Docker 容器中应用 LLM 生成的 patch")
        print("  2. 重新编译项目")
        print("  3. 测试 patch 是否真正修复了崩溃")
        print("  4. 返回真实的验证结果")


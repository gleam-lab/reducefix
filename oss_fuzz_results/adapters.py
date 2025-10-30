import os
import subprocess
import tempfile
import json
from typing import List, Optional, Callable
from dataclasses import dataclass
from pathlib import Path


@dataclass
class RunResult:
    """运行结果"""
    returncode: int
    stdout: str
    stderr: str
    timed_out: bool


InterestingOracle = Callable[[RunResult], bool]


class Runner:
    """简单的程序运行器"""
    
    def __init__(self, cmd: List[str], env: dict = None, timeout_sec: float = 30.0):
        self.cmd = cmd
        self.env = {**os.environ, **(env or {})}
        self.timeout = timeout_sec
    
    def run(self, input_bytes: bytes) -> RunResult:
        """运行程序并返回结果"""
        # 创建临时输入文件
        with tempfile.NamedTemporaryFile(delete=False, suffix='.bin') as f:
            temp_input = f.name
            f.write(input_bytes)
        
        try:
            # 替换命令中的 {input} 占位符
            cmd = [arg.replace('{input}', temp_input) for arg in self.cmd]
            
            # 运行命令
            result = subprocess.run(
                cmd,
                env=self.env,
                capture_output=True,
                timeout=self.timeout,
                text=True
            )
            
            return RunResult(
                returncode=result.returncode,
                stdout=result.stdout,
                stderr=result.stderr,
                timed_out=False
            )
        
        except subprocess.TimeoutExpired as e:
            return RunResult(
                returncode=-1,
                stdout=e.stdout.decode('utf-8', errors='ignore') if e.stdout else '',
                stderr=e.stderr.decode('utf-8', errors='ignore') if e.stderr else '',
                timed_out=True
            )
        
        finally:
            # 清理临时文件
            try:
                os.unlink(temp_input)
            except:
                pass


def _default_crash_oracle(result: RunResult) -> bool:
    """默认的崩溃判定函数"""
    # 检查是否有崩溃关键词
    crash_keywords = [
        'AddressSanitizer',
        'MemorySanitizer',
        'UndefinedBehaviorSanitizer',
        'heap-use-after-free',
        'heap-buffer-overflow',
        'stack-overflow',
        'SEGV',
        'segmentation fault',
        'Sanitizer',
    ]
    
    output = result.stderr + result.stdout
    if any(kw in output for kw in crash_keywords):
        return True
    
    # 非零退出码也可能表示崩溃
    if result.returncode not in [0, 1]:
        return True
    
    # 超时也算 interesting
    if result.timed_out:
        return True
    
    return False


def _asan_env() -> dict:
    # Favor detailed sanitizer reports
    env = {
        "ASAN_OPTIONS": "halt_on_error=1,alloc_dealloc_mismatch=0,handle_segv=1,handle_abort=1,abort_on_error=1,detect_leaks=0",
        "UBSAN_OPTIONS": "print_stacktrace=1",
    }
    return env


def pdfium_runner(pdfium_test_path: str, *, timeout_sec: float = 30.0) -> Runner:
    """Create a Runner for PDFium using pdfium_test fuzz target.

    pdfium_test typically accepts a filename argument. We place the input to {input}.
    """
    cmd = [pdfium_test_path, "{input}"]
    return Runner(cmd, env=_asan_env(), timeout_sec=timeout_sec)


def harfbuzz_runner(hb_shape_fuzzer_path: str, *, timeout_sec: float = 30.0) -> Runner:
    """Create a Runner for HarfBuzz (hb-shape-fuzzer or similar)."""
    cmd = [hb_shape_fuzzer_path, "{input}"]
    return Runner(cmd, env=_asan_env(), timeout_sec=timeout_sec)


def default_oracle() -> InterestingOracle:
    return _default_crash_oracle


def docker_runner(docker_image: str, *, timeout_sec: float = 30.0, use_persistent: bool = True) -> Runner:
    """
    Create a Runner that runs fuzzer inside Docker container.
    
    This is necessary because fuzzers extracted from Docker don't work
    properly in local environment (missing ASAN runtime, etc.)
    
    Args:
        docker_image: Docker image name
        timeout_sec: Timeout for each test run
        use_persistent: If True, reuse a long-running container (much faster)
    """
    
    if use_persistent:
        class PersistentDockerRunner:
            """优化的 Docker runner，复用容器以减少开销"""
            def __init__(self, image: str, timeout: float):
                self.image = image
                self.timeout = timeout
                self.container_id = None
                self._run_count = 0
                self._start_container()
            
            def _start_container(self):
                """启动持久容器"""
                if self.container_id:
                    return
                
                try:
                    # 启动容器并保持运行
                    result = subprocess.run([
                        'docker', 'run', '-d', '-it',
                        '--security-opt', 'seccomp=unconfined',  # WSL2 兼容性
                        self.image,
                        'sleep', 'infinity'  # 保持容器运行
                    ], capture_output=True, text=True, timeout=30, check=True)
                    
                    self.container_id = result.stdout.strip()
                    print(f"[Docker] 启动持久容器: {self.container_id[:12]} (镜像: {self.image})")
                
                except Exception as e:
                    print(f"[Docker Warning] 无法启动持久容器，回退到一次性模式: {e}")
                    if hasattr(e, 'stderr') and e.stderr:
                        print(f"[Docker Error] {e.stderr}")
                    self.container_id = None
            
            def run(self, input_bytes: bytes) -> RunResult:
                """Run fuzzer inside persistent Docker container"""
                self._run_count += 1
                
                # 定期显示进度（减少输出量）
                if self._run_count % 50 == 0:
                    print(f"  [Docker] 已完成 {self._run_count} 次测试...")
                
                # 如果容器不可用，回退到一次性模式
                if not self.container_id:
                    return self._run_ephemeral(input_bytes)
                
                # 创建临时输入文件
                with tempfile.NamedTemporaryFile(delete=False, suffix='.bin') as f:
                    temp_input = f.name
                    f.write(input_bytes)
                
                try:
                    # 将文件复制到容器
                    subprocess.run([
                        'docker', 'cp', temp_input, f'{self.container_id}:/tmp/poc'
                    ], capture_output=True, timeout=5, check=True)
                    
                    # 在容器内执行 fuzzer
                    # arvo 脚本无参数时会自动运行 fuzzer 并使用 /tmp/poc
                    result = subprocess.run([
                        'docker', 'exec', self.container_id,
                        'bash', '-c', 'arvo 2>&1'  # 不传递参数，让脚本自动处理
                    ], capture_output=True, timeout=self.timeout, text=False)
                    
                    # 解码输出
                    stdout = result.stdout.decode('utf-8', errors='ignore') if result.stdout else ''
                    stderr = result.stderr.decode('utf-8', errors='ignore') if result.stderr else ''
                    
                    return RunResult(
                        returncode=result.returncode,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=False
                    )
                
                except subprocess.TimeoutExpired as e:
                    stdout = e.stdout.decode('utf-8', errors='ignore') if e.stdout else ''
                    stderr = e.stderr.decode('utf-8', errors='ignore') if e.stderr else ''
                    return RunResult(
                        returncode=-1,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=True
                    )
                
                except Exception as e:
                    # 容器可能已停止，尝试重启
                    print(f"[Docker] 容器执行失败，尝试重启: {e}")
                    self.cleanup()
                    self._start_container()
                    return self._run_ephemeral(input_bytes)
                
                finally:
                    # 清理临时文件
                    try:
                        os.unlink(temp_input)
                    except:
                        pass
            
            def _run_ephemeral(self, input_bytes: bytes) -> RunResult:
                """回退到一次性容器模式"""
                with tempfile.NamedTemporaryFile(delete=False, suffix='.bin') as f:
                    temp_input = f.name
                    f.write(input_bytes)
                
                try:
                    cmd = [
                        'docker', 'run', '--rm',
                        '--security-opt', 'seccomp=unconfined',  # WSL2 兼容性
                        '-v', f'{temp_input}:/tmp/poc:ro',
                        self.image,
                        'arvo'  # 不传递参数，arvo 脚本会自动使用 /tmp/poc
                    ]
                    
                    result = subprocess.run(
                        cmd,
                        capture_output=True,
                        timeout=self.timeout,
                        text=False
                    )
                    
                    stdout = result.stdout.decode('utf-8', errors='ignore') if result.stdout else ''
                    stderr = result.stderr.decode('utf-8', errors='ignore') if result.stderr else ''
                    
                    return RunResult(
                        returncode=result.returncode,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=False
                    )
                
                except subprocess.TimeoutExpired as e:
                    stdout = e.stdout.decode('utf-8', errors='ignore') if e.stdout else ''
                    stderr = e.stderr.decode('utf-8', errors='ignore') if e.stderr else ''
                    return RunResult(
                        returncode=-1,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=True
                    )
                
                finally:
                    try:
                        os.unlink(temp_input)
                    except:
                        pass
            
            def cleanup(self):
                """清理持久容器"""
                if self.container_id:
                    try:
                        subprocess.run([
                            'docker', 'rm', '-f', self.container_id
                        ], capture_output=True, timeout=10)
                        # print(f"[Docker] 清理容器: {self.container_id[:12]}")
                    except:
                        pass
                    self.container_id = None
            
            def __del__(self):
                """析构时清理容器"""
                self.cleanup()
            
            @property
            def cmd(self):
                return ['docker', 'exec', self.container_id or 'N/A', 'arvo']
            
            @property
            def env(self):
                return {}
        
        return PersistentDockerRunner(docker_image, timeout_sec)
    
    else:
        # 原始的一次性容器模式
        class DockerRunner:
            def __init__(self, image: str, timeout: float):
                self.image = image
                self.timeout = timeout
            
            def run(self, input_bytes: bytes) -> RunResult:
                """Run fuzzer inside Docker container"""
                # 创建临时输入文件
                with tempfile.NamedTemporaryFile(delete=False, suffix='.bin') as f:
                    temp_input = f.name
                    f.write(input_bytes)
                
                try:
                    # 在 Docker 容器中运行
                    cmd = [
                        'docker', 'run', '--rm',
                        '--security-opt', 'seccomp=unconfined',  # WSL2 兼容性
                        '-v', f'{temp_input}:/tmp/poc:ro',
                        self.image,
                        'arvo'  # 不传递参数，arvo 脚本会自动使用 /tmp/poc
                    ]
                    
                    result = subprocess.run(
                        cmd,
                        capture_output=True,
                        timeout=self.timeout,
                        text=False  # 保持 bytes 以处理二进制输出
                    )
                    
                    # 解码输出
                    stdout = result.stdout.decode('utf-8', errors='ignore') if result.stdout else ''
                    stderr = result.stderr.decode('utf-8', errors='ignore') if result.stderr else ''
                    
                    return RunResult(
                        returncode=result.returncode,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=False
                    )
                
                except subprocess.TimeoutExpired as e:
                    stdout = e.stdout.decode('utf-8', errors='ignore') if e.stdout else ''
                    stderr = e.stderr.decode('utf-8', errors='ignore') if e.stderr else ''
                    return RunResult(
                        returncode=-1,
                        stdout=stdout,
                        stderr=stderr,
                        timed_out=True
                    )
                
                finally:
                    # 清理临时文件
                    try:
                        os.unlink(temp_input)
                    except:
                        pass
            
            @property
            def cmd(self):
                return ['docker', 'run', self.image, 'arvo']
            
            @property
            def env(self):
                return {}
        
        return DockerRunner(docker_image, timeout_sec)


def get_docker_runner_for_case(case_id: str, *, timeout_sec: float = 30.0) -> Optional[Runner]:
    """
    根据 case_id 创建 Docker runner
    
    Args:
        case_id: 案例 ID（如 arvo-20249）
        timeout_sec: 超时时间
    
    Returns:
        Docker runner，如果找不到配置则返回 None
    """
    # 查找 cases.json
    oss_fuzz_dir = Path(__file__).parent
    cases_file = oss_fuzz_dir / "cases.json"
    
    if not cases_file.exists():
        return None
    
    try:
        with open(cases_file) as f:
            cases = json.load(f)
        
        if case_id not in cases:
            return None
        
        docker_image = cases[case_id].get('docker_image_vul')
        if not docker_image:
            return None
        
        return docker_runner(docker_image, timeout_sec=timeout_sec)
    
    except Exception:
        return None



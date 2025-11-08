#!/usr/bin/env python3
"""
APR (Automatic Program Repair) 模块 - ReduceFix 实验

**实验设计**:
1. 3个策略: 
   - without_test (no_tc): 不使用测试用例
   - origin_test (orig_tc): 使用原始测试用例
   - reduced_test (reduced_tc): 使用 ReduceFix 缩减后的测试用例
2. 每个策略生成 TOP_K=10 个版本（并行生成，不同temperature）
3. 评估逻辑: 只要10个版本中有1个通过真实验证 → 该策略成功
4. pass@k: 成功的 cases 数 / 总 cases 数
5. 真实验证: Docker 编译 + 崩溃测试
"""

import json
import os
import re
import sys
import time
from typing import Dict, List, Optional, Tuple
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
import subprocess
import tempfile

# 添加项目路径
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import llm

# 导入真实验证器
from oss_fuzz_results.docker_patch_tester import DockerPatchTester, extract_code_from_repair

# 导入 GitHub API（如果需要）
try:
    from github import Github, GithubException
    GITHUB_AVAILABLE = True
except ImportError:
    GITHUB_AVAILABLE = False
    print("[Warning] PyGithub not available, will use git command line instead")


# ==================== 配置参数（与 evaluate_repair.py 对齐）====================
TOP_K = 10  # 每个策略生成10个版本
REPAIR_MODEL = "deepseek-v3.1"
# 统一温度为 1.0（与用户要求对齐）
TEMPERATURE_RANGE = [1.0]
MAX_THREADS = 5
USE_REAL_VALIDATION = True  # 使用真实 Docker 验证

# Ground Truth Patch 文件路径
PATCH_BASE_DIR = "/home/barty/research/ARVO-Meta/archive_data/patches"
META_BASE_DIR = "/home/barty/research/ARVO-Meta/archive_data/meta"


# ==================== Docker 容器文件获取（优先方法）====================

def get_file_content_from_docker(container_id: str, file_path: str, project: str = None) -> Optional[str]:
    """
    直接从 Docker 容器获取文件内容（最准确的方法）
    
    Args:
        container_id: Docker 容器 ID
        file_path: 文件路径（相对路径，如 "source/fitz/draw-device.c"）
        project: 项目名（如 "mupdf"）
    
    Returns:
        文件内容字符串，失败返回 None
    """
    try:
        # 尝试不同的路径组合
        possible_paths = [
            f'/src/{file_path}',  # 直接路径
        ]
        
        if project:
            possible_paths.insert(0, f'/src/{project}/{file_path}')  # 项目子目录（优先）
        
        for full_path in possible_paths:
            cmd = ['docker', 'exec', container_id, 'cat', full_path]
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=30
            )
            
            if result.returncode == 0:
                print(f"  [Docker] ✓ 成功从容器获取文件: {full_path} ({len(result.stdout)} bytes)")
                return result.stdout
        
        # 所有路径都失败
        print(f"  [Docker] ✗ 获取文件失败，尝试的路径: {possible_paths}")
        return None
            
    except Exception as e:
        print(f"  [Docker] ✗ 异常: {e}")
        return None


def load_buggy_files_from_docker(container_id: str, patch_info: Dict, project: str = None) -> Optional[Dict]:
    """
    从 Docker 容器加载 buggy 文件的完整内容
    
    Args:
        container_id: Docker 容器 ID
        patch_info: patch 解析信息（包含文件列表和行号）
        project: 项目名（如 "mupdf"）
    
    Returns:
        字典 {
            "files": [{
                "path": 文件路径,
                "content": 完整文件内容（从 Docker 容器获取），
                "line_start": patch 修改的起始行号,
                "line_count": patch 修改的行数
            }]
        }，如果失败返回 None
    """
    if not patch_info or not patch_info.get('files'):
        return None
    
    files_with_content = []
    
    for file_info in patch_info['files']:
        file_path = file_info['path']
        
        # 从 Docker 容器获取完整文件内容
        full_content = get_file_content_from_docker(container_id, file_path, project)
        
        if full_content:
            files_with_content.append({
                "path": file_path,
                "content": full_content,
                "line_start": file_info.get('line_start'),
                "line_count": file_info.get('line_count')
            })
            print(f"  [Docker] ✓ 加载成功: {file_path}")
        else:
            print(f"  [Docker] ✗ 加载失败: {file_path}")
    
    if not files_with_content:
        return None
    
    return {"files": files_with_content}


# ==================== Git 仓库信息获取（备用方法）====================

def get_file_content_from_commit(repo_path: str, commit_hash: str, file_path: str) -> Optional[str]:
    """
    从指定 commit 获取文件内容（buggy version，即 commit^ 的版本）
    
    Args:
        repo_path: 本地 git 仓库路径
        commit_hash: commit hash（fix commit）
        file_path: 文件路径
    
    Returns:
        文件内容字符串，失败返回 None
    """
    try:
        # 获取 fix commit 的前一个版本（buggy version）
        cmd = ['git', 'show', f'{commit_hash}^:{file_path}']
        result = subprocess.run(
            cmd,
            cwd=repo_path,
            capture_output=True,
            text=True,
            timeout=30
        )
        
        if result.returncode == 0:
            return result.stdout
        else:
            print(f"  [Git] Failed to get file content: {result.stderr}")
            return None
            
    except Exception as e:
        print(f"  [Git] Error getting file content: {e}")
        return None


def clone_or_update_repo(repo_addr: str, target_dir: str) -> bool:
    """
    克隆或更新 git 仓库
    
    Args:
        repo_addr: git 仓库地址
        target_dir: 目标目录
    
    Returns:
        成功返回 True，失败返回 False
    """
    try:
        if os.path.exists(os.path.join(target_dir, '.git')):
            # 已存在，执行 pull
            print(f"  [Git] Updating existing repo at {target_dir}...")
            result = subprocess.run(
                ['git', 'pull'],
                cwd=target_dir,
                capture_output=True,
                text=True,
                timeout=120
            )
            return result.returncode == 0
        else:
            # 不存在，执行 clone
            print(f"  [Git] Cloning repo from {repo_addr}...")
            os.makedirs(target_dir, exist_ok=True)
            result = subprocess.run(
                ['git', 'clone', repo_addr, target_dir],
                capture_output=True,
                text=True,
                timeout=240
            )
            return result.returncode == 0
            
    except Exception as e:
        print(f"  [Git] Error cloning/updating repo: {e}")
        return False


# ==================== Meta 信息加载 ====================

def load_meta_info(arvo_id: int) -> Optional[Dict]:
    """
    从 meta.json 文件加载详细的崩溃信息
    
    Args:
        arvo_id: ARVO 案例 ID
    
    Returns:
        meta 信息字典，如果失败返回 None
    """
    meta_file = os.path.join(META_BASE_DIR, f"{arvo_id}.json")
    
    if not os.path.exists(meta_file):
        print(f"  [Meta] File not found: {meta_file}")
        return None
    
    try:
        with open(meta_file, 'r', encoding='utf-8') as f:
            meta = json.load(f)
        
        print(f"  [Meta] Loaded from: {meta_file}")
        
        # 提取有用信息
        crash_state = None
        detailed_report = None
        
        # 从 comments 中提取 crash state
        if 'report' in meta and 'comments' in meta['report']:
            for comment in meta['report']['comments']:
                content = comment.get('content', '')
                if 'Crash State:' in content:
                    # 提取 Crash State
                    lines = content.split('\n')
                    crash_state_lines = []
                    in_crash_state = False
                    for line in lines:
                        if 'Crash State:' in line:
                            in_crash_state = True
                            continue
                        if in_crash_state:
                            if line.strip() and not line.startswith('Sanitizer:'):
                                crash_state_lines.append(line.strip())
                            else:
                                break
                    crash_state = '\n'.join(crash_state_lines)
                    detailed_report = content
                    break
        
        result = {
            'project': meta.get('project', 'unknown'),
            'crash_type': meta.get('crash_type', 'unknown'),
            'severity': meta.get('severity', 'unknown'),
            'fuzzer': meta.get('fuzzer', 'unknown'),
            'sanitizer': meta.get('sanitizer', 'unknown'),
            'crash_state': crash_state,
            'detailed_report': detailed_report,
            'fix_commit': meta.get('fix_commit', 'unknown'),
            'repo_addr': meta.get('repo_addr', 'unknown')
        }
        
        print(f"  [Meta] Extracted: crash_type={result['crash_type']}, severity={result['severity']}")
        return result
        
    except Exception as e:
        print(f"  [Meta] Failed to load: {e}")
        return None


# ==================== Patch 解析（从 ground truth patch 提取修改前的代码）====================

def parse_git_diff_patch(patch_file_path: str) -> Dict[str, Dict[str, str]]:
    """
    解析 git diff 格式的 patch 文件，提取修改前后的代码和行号信息
    
    Args:
        patch_file_path: patch 文件路径
    
    Returns:
        字典 {文件路径: {
            "before": 修改前的代码, 
            "after": 修改后的代码, 
            "file": 文件名,
            "line_start": 起始行号,
            "line_count": 行数
        }}
    """
    if not os.path.exists(patch_file_path):
        return {}
    
    try:
        with open(patch_file_path, 'r', encoding='utf-8', errors='ignore') as f:
            patch_content = f.read()
    except Exception as e:
        print(f"  [Warning] Failed to read patch file: {e}")
        return {}
    
    # 解析 diff 文件
    result = {}
    current_file = None
    before_lines = []
    after_lines = []
    in_hunk = False
    line_start = None
    line_count = None
    
    for line in patch_content.splitlines():
        # 检测新文件开始
        if line.startswith('diff --git'):
            # 保存前一个文件的内容
            if current_file and (before_lines or after_lines):
                result[current_file] = {
                    "before": '\n'.join(before_lines),
                    "after": '\n'.join(after_lines),
                    "file": current_file,
                    "line_start": line_start,
                    "line_count": line_count
                }
            
            # 重置状态
            current_file = None
            before_lines = []
            after_lines = []
            in_hunk = False
            line_start = None
            line_count = None
            
        elif line.startswith('--- a/'):
            # 提取文件名
            current_file = line[6:].strip()
            
        elif line.startswith('@@ '):
            # hunk 开始 - 提取行号信息
            # 格式: @@ -line_start,line_count +new_start,new_count @@
            in_hunk = True
            match = re.match(r'@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@', line)
            if match:
                line_start = int(match.group(1))
                line_count = int(match.group(2)) if match.group(2) else 1
            
        elif in_hunk and current_file:
            if line.startswith('-') and not line.startswith('---'):
                # 删除的行（修改前的代码）
                before_lines.append(line[1:])
            elif line.startswith('+') and not line.startswith('+++'):
                # 添加的行（修改后的代码）
                after_lines.append(line[1:])
            elif line.startswith(' '):
                # 上下文行（同时添加到修改前后）
                before_lines.append(line[1:])
                after_lines.append(line[1:])
    
    # 保存最后一个文件
    if current_file and (before_lines or after_lines):
        result[current_file] = {
            "before": '\n'.join(before_lines),
            "after": '\n'.join(after_lines),
            "file": current_file,
            "line_start": line_start,
            "line_count": line_count
        }
    
    return result


def load_buggy_code_from_patch(arvo_id: int) -> Optional[Dict]:
    """
    从 ground truth patch 文件中加载修改前的 buggy 代码和位置信息
    
    Args:
        arvo_id: ARVO 案例 ID
    
    Returns:
        字典 {
            "code": 合并的代码字符串,
            "files": [{
                "path": 文件路径,
                "code": 代码,
                "code_after": 修复后的代码（用于对比）,
                "line_start": 起始行号,
                "line_count": 行数
            }]
        }，如果失败返回 None
    """
    # 尝试两种可能的文件扩展名
    for ext in ['.diff', '.patch']:
        patch_file = os.path.join(PATCH_BASE_DIR, f"{arvo_id}{ext}")
        
        if os.path.exists(patch_file):
            print(f"  [Patch] Loading from: {patch_file}")
            
            parsed = parse_git_diff_patch(patch_file)
            
            if not parsed:
                print(f"  [Warning] Failed to parse patch file")
                return None
            
            # 收集所有文件信息
            files_info = []
            buggy_code_parts = []
            
            for file_path, changes in parsed.items():
                before_code = changes.get('before', '').strip()
                after_code = changes.get('after', '').strip()
                
                if before_code:
                    line_start = changes.get('line_start')
                    line_count = changes.get('line_count')
                    
                    # 构建带行号信息的代码块
                    header = f"// File: {file_path}"
                    if line_start:
                        header += f" (lines {line_start}-{line_start + line_count - 1})"
                    header += "\n// This code needs to be fixed:"
                    
                    buggy_code_parts.append(f"{header}\n{before_code}")
                    
                    files_info.append({
                        "path": file_path,
                        "code": before_code,
                        "code_after": after_code,  # 保存修复后的代码用于参考
                        "line_start": line_start,
                        "line_count": line_count
                    })
            
            if buggy_code_parts:
                buggy_code = '\n\n'.join(buggy_code_parts)
                print(f"  [Patch] Extracted {len(buggy_code):,} chars from {len(parsed)} file(s)")
                
                return {
                    "code": buggy_code,
                    "files": files_info
                }
    
    print(f"  [Warning] Patch file not found for ARVO-{arvo_id}")
    return None


def load_complete_buggy_files(arvo_id: int, meta_info: Dict) -> Optional[Dict]:
    """
    从 git commit 加载完整的 buggy 文件内容（用于 SEARCH/REPLACE）
    
    Args:
        arvo_id: ARVO 案例 ID
        meta_info: meta 信息，包含 repo_addr 和 fix_commit
    
    Returns:
        字典 {
            "files": [{
                "path": 文件路径,
                "content": 完整文件内容,
                "line_start": patch 修改的起始行号,
                "line_count": patch 修改的行数
            }]
        }，如果失败返回 None
    """
    if not meta_info:
        return None
        
    repo_addr = meta_info.get('repo_addr')
    fix_commit = meta_info.get('fix_commit')
    
    if not repo_addr or not fix_commit:
        print(f"  [FullFile] Missing repo_addr or fix_commit in meta")
        return None
    
    # 从 patch 获取文件列表和行号信息
    patch_info = load_buggy_code_from_patch(arvo_id)
    if not patch_info or not patch_info.get('files'):
        print(f"  [FullFile] No patch info available")
        return None
    
    # 准备本地仓库路径
    repo_name = repo_addr.rstrip('/').split('/')[-1].replace('.git', '')
    repo_cache_dir = f"/tmp/ossfuzz_repos/{repo_name}"
    
    # 克隆或更新仓库
    if not clone_or_update_repo(repo_addr, repo_cache_dir):
        print(f"  [FullFile] Failed to clone/update repo")
        return None
    
    # 获取每个文件的完整内容
    files_with_content = []
    for file_info in patch_info['files']:
        file_path = file_info['path']
        
        # 获取完整文件内容
        full_content = get_file_content_from_commit(repo_cache_dir, fix_commit, file_path)
        
        if full_content:
            files_with_content.append({
                "path": file_path,
                "content": full_content,
                "line_start": file_info.get('line_start'),
                "line_count": file_info.get('line_count')
            })
            print(f"  [FullFile] Loaded {file_path}: {len(full_content):,} chars")
        else:
            print(f"  [FullFile] Failed to load {file_path}")
    
    if not files_with_content:
        return None
    
    return {"files": files_with_content}


# ==================== SEARCH/REPLACE 处理函数 ====================

def test_patch_validity(patch: str) -> bool:
    """
    测试 patch 的有效性（简单检查格式）
    
    Args:
        patch: git diff 格式的 patch
    
    Returns:
        True 如果格式看起来正确
    """
    if not patch:
        return False
    
    # 检查基本的 diff 标记
    has_diff_header = '---' in patch and '+++' in patch
    has_hunks = '@@' in patch
    has_changes = any(line.startswith(('+', '-')) for line in patch.splitlines() 
                      if not line.startswith(('+++', '---')))
    
    return has_diff_header and has_hunks and has_changes


def parse_search_replace_blocks(llm_output: str) -> List[Dict]:
    """
    从 LLM 输出中解析 SEARCH/REPLACE 命令
    
    优化策略：
    1. 优先提取包含完整 SEARCH/REPLACE 结构的代码块
    2. 从后往前查找，因为 LLM 通常在最后给出实际的修复代码
    3. 过滤掉不完整或示例性质的块
    
    Returns:
        [{
            "file": 文件路径,
            "start_line": 起始行号,
            "end_line": 结束行号,
            "search": 搜索内容,
            "replace": 替换内容
        }, ...]
    """
    blocks = []
    
    # 方法1: 尝试直接匹配完整的 SEARCH/REPLACE 块（不依赖代码围栏）
    # 这种方法更精确，可以避免提取到示例代码
    direct_sr_pattern = r'###\s+([^\n]+)\s*\n-\s*start_line\s*:\s*(\d+).*?-\s*end_line\s*:\s*(\d+).*?<{7,}\s*SEARCH\s*\n(.*?)\n={7,}\s*\n(.*?)\n>{7,}\s*REPLACE'
    direct_matches = list(re.finditer(direct_sr_pattern, llm_output, re.DOTALL | re.IGNORECASE))
    
    if direct_matches:
        print(f"  [SR] Found {len(direct_matches)} complete SEARCH/REPLACE block(s)")
        # 从后往前处理（最后的通常是实际代码）
        for match in reversed(direct_matches):
            file_path = match.group(1).strip()
            start_line = int(match.group(2))
            end_line = int(match.group(3))
            search_content = match.group(4).rstrip()
            replace_content = match.group(5).rstrip()
            
            # 严格验证：确保 search 和 replace 都不为空，且不是示例代码
            if not search_content.strip() or len(search_content) < 5:
                print(f"  [SR] Skipping block with empty/too short search content")
                continue
            
            # 额外验证：拒绝明显的示例代码（包含占位符）
            # 注意：要检测真正的占位符，而不是代码中恰好包含这些词的情况
            search_lower = search_content.lower()
            is_placeholder = False
            
            # 检测占位符模式（必须是独立的词或短语，不是参数的一部分）
            placeholder_patterns = [
                r'\byour\s+code\s+here\b',
                r'\btodo\b',
                r'\bxxx\b',
                r'\bplaceholder\b',
                r'\.\.\.',  # 三个点表示省略
                r'example\.cpp',  # 示例文件名
                r'src/memory/allocator\.cpp',  # prompt 中的示例文件
            ]
            
            for pattern in placeholder_patterns:
                if re.search(pattern, search_lower):
                    is_placeholder = True
                    break
            
            if is_placeholder:
                print(f"  [SR] Skipping block with placeholder/example content")
                continue
            
            # 额外验证：拒绝嵌套的 SEARCH/REPLACE 块（说明提取错误）
            if '<<<<<<< SEARCH' in search_content or '>>>>>>> REPLACE' in search_content:
                print(f"  [SR] Skipping block with nested SEARCH/REPLACE markers")
                continue
            
            blocks.append({
                "file": file_path,
                "start_line": start_line,
                "end_line": end_line,
                "search": search_content,
                "replace": replace_content
            })
        
        # 反转回正常顺序（但已经过滤了无效块）
        blocks.reverse()
        return blocks
    
    # 方法2: 使用代码围栏提取（备用方法）
    code_block_pattern = r'```(?:cpp|c\+\+|c|python|java|diff)?\s*\n(.*?)```'
    code_blocks_matches = list(re.finditer(code_block_pattern, llm_output, re.DOTALL))
    
    # 从后往前查找有效块
    valid_blocks = []
    for match in reversed(code_blocks_matches):
        block = match.group(1)
        
        # 检查是否包含 SEARCH/REPLACE 结构
        if '<<<<<<<' not in block or '=======' not in block or '>>>>>>>' not in block:
            continue
        if 'SEARCH' not in block or 'REPLACE' not in block:
            continue
        
        # 解析文件路径（支持多种格式）
        file_match = re.search(r'###\s+(.+?)\s*\n', block)
        if not file_match:
            file_match = re.search(r'File:\s*(.+?)\s*\n', block, re.IGNORECASE)
        if not file_match:
            continue
        file_path = file_match.group(1).strip()
        
        # 解析行号（可选）
        start_line_match = re.search(r'-\s*start_line\s*:\s*(\d+)', block, re.IGNORECASE)
        end_line_match = re.search(r'-\s*end_line\s*:\s*(\d+)', block, re.IGNORECASE)
        
        start_line = int(start_line_match.group(1)) if start_line_match else 0
        end_line = int(end_line_match.group(1)) if end_line_match else 0
        
        # 解析 SEARCH/REPLACE（更宽松的匹配）
        sr_pattern = r'<{7,}\s*SEARCH\s*\n(.*?)\n={7,}\s*\n(.*?)\n>{7,}\s*REPLACE'
        sr_match = re.search(sr_pattern, block, re.DOTALL | re.IGNORECASE)
        
        if not sr_match:
            # 尝试更宽松的格式
            sr_pattern = r'SEARCH:\s*\n(.*?)\nREPLACE:\s*\n(.*?)(?:\n```|\Z)'
            sr_match = re.search(sr_pattern, block, re.DOTALL | re.IGNORECASE)
        
        if not sr_match:
            continue
        
        search_content = sr_match.group(1).rstrip()
        replace_content = sr_match.group(2).rstrip()
        
        # 严格验证内容有效性
        if not search_content.strip() or len(search_content) < 5:
            print(f"  [SR] Skipping block with empty/too short search content")
            continue
        
        # 拒绝示例代码
        if any(placeholder in search_content.lower() for placeholder in 
               ['example', 'your code here', 'todo', 'xxx', 'placeholder']):
            print(f"  [SR] Skipping block with placeholder content")
            continue
        
        # 拒绝嵌套的 SEARCH/REPLACE
        if '<<<<<<< SEARCH' in search_content or '>>>>>>> REPLACE' in search_content:
            print(f"  [SR] Skipping block with nested markers")
            continue
        
        valid_blocks.append({
            "file": file_path,
            "start_line": start_line,
            "end_line": end_line,
            "search": search_content,
            "replace": replace_content
        })
    
    # 反转回正常顺序
    valid_blocks.reverse()
    blocks.extend(valid_blocks)
    
    # 方法3: 如果还是没找到，尝试不带代码围栏的匹配
    if not blocks:
        direct_pattern = r'###\s+[^\n]+\s*\n.*?<{7,}\s*SEARCH.*?>{7,}\s*REPLACE'
        direct_matches = re.findall(direct_pattern, llm_output, re.DOTALL)
        if direct_matches:
            print(f"  [SR] Found {len(direct_matches)} SEARCH/REPLACE block(s) without code fence")
            
            for block in reversed(direct_matches):  # 从后往前
                # 解析文件路径
                file_match = re.search(r'###\s+(.+?)\s*\n', block)
                if not file_match:
                    continue
                file_path = file_match.group(1).strip()
                
                # 解析行号
                start_line_match = re.search(r'-\s*start_line\s*:\s*(\d+)', block, re.IGNORECASE)
                end_line_match = re.search(r'-\s*end_line\s*:\s*(\d+)', block, re.IGNORECASE)
                
                start_line = int(start_line_match.group(1)) if start_line_match else 0
                end_line = int(end_line_match.group(1)) if end_line_match else 0
                
                # 解析 SEARCH/REPLACE
                sr_pattern = r'<{7,}\s*SEARCH\s*\n(.*?)\n={7,}\s*\n(.*?)\n>{7,}\s*REPLACE'
                sr_match = re.search(sr_pattern, block, re.DOTALL | re.IGNORECASE)
                
                if not sr_match:
                    continue
                
                search_content = sr_match.group(1).rstrip()
                replace_content = sr_match.group(2).rstrip()
                
                # 严格验证内容有效性
                if not search_content.strip() or len(search_content) < 5:
                    continue
                
                # 拒绝示例代码和嵌套标记
                if any(placeholder in search_content.lower() for placeholder in 
                       ['example', 'your code here', 'todo', 'xxx', 'placeholder']):
                    continue
                
                if '<<<<<<< SEARCH' in search_content or '>>>>>>> REPLACE' in search_content:
                    continue
                
                blocks.append({
                    "file": file_path,
                    "start_line": start_line,
                    "end_line": end_line,
                    "search": search_content,
                    "replace": replace_content
                })
            
            blocks.reverse()
    
    return blocks


def normalize_indentation(text: str, target_indent_char: str = '\t') -> str:
    """
    标准化文本的缩进字符（空格 <-> 制表符）
    
    Args:
        text: 原始文本
        target_indent_char: 目标缩进字符 ('\t' 或 ' ')
    
    Returns:
        转换后的文本
    """
    lines = text.splitlines()
    result_lines = []
    
    for line in lines:
        if not line.strip():  # 空行
            result_lines.append(line)
            continue
        
        # 检测当前缩进
        stripped = line.lstrip()
        indent_len = len(line) - len(stripped)
        
        if indent_len == 0:
            result_lines.append(line)
            continue
        
        # 如果目标是制表符
        if target_indent_char == '\t':
            # 假设4个空格 = 1个制表符
            if line.startswith('    '):
                # 转换空格为制表符
                space_count = 0
                for char in line:
                    if char == ' ':
                        space_count += 1
                    else:
                        break
                tab_count = space_count // 4
                remaining_spaces = space_count % 4
                new_line = '\t' * tab_count + ' ' * remaining_spaces + stripped
                result_lines.append(new_line)
            else:
                result_lines.append(line)
        else:
            # 目标是空格，转换制表符为空格
            if '\t' in line[:indent_len]:
                new_line = line.replace('\t', '    ')
                result_lines.append(new_line)
            else:
                result_lines.append(line)
    
    return '\n'.join(result_lines)


def apply_search_replace(original_content: str, search: str, replace: str) -> Optional[str]:
    """
    应用 SEARCH/REPLACE 命令到文件内容
    
    Args:
        original_content: 原始文件内容
        search: 要搜索的内容
        replace: 替换内容
    
    Returns:
        修改后的内容，如果失败返回 None
    """
    # 方法1: 精确匹配
    if search in original_content:
        print(f"  [SR] Applied exact match")
        return original_content.replace(search, replace, 1)
    
    # 方法1.5: 尝试标准化缩进后匹配（空格 vs 制表符）
    # 检测原始文件使用的缩进字符
    uses_tabs = '\t' in original_content and original_content.find('\t') < 100
    uses_spaces = '    ' in original_content and original_content.find('    ') < 100
    
    if uses_tabs and '    ' in search:
        # 文件用制表符，search 用空格 → 转换 search 和 replace 为制表符
        search_with_tabs = normalize_indentation(search, '\t')
        replace_with_tabs = normalize_indentation(replace, '\t')
        
        if search_with_tabs in original_content:
            print(f"  [SR] Applied with tabs conversion (spaces → tabs)")
            return original_content.replace(search_with_tabs, replace_with_tabs, 1)
    
    if uses_spaces and '\t' in search:
        # 文件用空格，search 用制表符 → 转换 search 和 replace 为空格
        search_with_spaces = normalize_indentation(search, ' ')
        replace_with_spaces = normalize_indentation(replace, ' ')
        
        if search_with_spaces in original_content:
            print(f"  [SR] Applied with spaces conversion (tabs → spaces)")
            return original_content.replace(search_with_spaces, replace_with_spaces, 1)
    
    # 方法2: 忽略行尾空格的匹配
    search_lines = search.splitlines()
    original_lines = original_content.splitlines()
    
    # 查找匹配的起始位置
    for i in range(len(original_lines) - len(search_lines) + 1):
        match = True
        for j, search_line in enumerate(search_lines):
            if original_lines[i + j].rstrip() != search_line.rstrip():
                match = False
                break
        
        if match:
            # 找到匹配，进行替换
            new_lines = (
                original_lines[:i] +
                replace.splitlines() +
                original_lines[i + len(search_lines):]
            )
            print(f"  [SR] Applied with trailing whitespace tolerance at line {i+1}")
            return '\n'.join(new_lines)
    
    # 方法3: 尝试标准化空格后匹配（处理缩进差异）
    def normalize_whitespace(line):
        """标准化行的空格，但保留相对缩进"""
        return line.strip()
    
    for i in range(len(original_lines) - len(search_lines) + 1):
        match = True
        for j, search_line in enumerate(search_lines):
            if normalize_whitespace(original_lines[i + j]) != normalize_whitespace(search_line):
                match = False
                break
        
        if match:
            # 找到匹配，完全保留原始缩进风格
            # 分析原始行的缩进级别模式
            original_indents = []
            for j in range(len(search_lines)):
                if (i + j) < len(original_lines):
                    orig_line = original_lines[i + j]
                    indent = orig_line[:len(orig_line) - len(orig_line.lstrip())]
                    original_indents.append(indent)
                else:
                    original_indents.append('')
            
            # 对 replace 的每一行，智能应用原始缩进
            adjusted_replace_lines = []
            replace_lines_list = replace.splitlines()
            
            for j, replace_line in enumerate(replace_lines_list):
                if not replace_line.strip():  # 空行
                    adjusted_replace_lines.append('')
                    continue
                
                # 确定该行应该使用的缩进
                # 1. 如果在 search 范围内，使用对应原始行的缩进
                # 2. 如果是新增行，尝试推断缩进
                if j < len(original_indents) and original_indents[j]:
                    # 使用对应行的缩进
                    target_indent = original_indents[j]
                elif j > 0 and j < len(replace_lines_list) and adjusted_replace_lines:
                    # 新增行：使用前一行的缩进作为基准
                    prev_line = adjusted_replace_lines[-1] if adjusted_replace_lines else ''
                    if prev_line.strip().endswith('{'):
                        # 前一行是开括号，增加一级缩进
                        prev_indent = prev_line[:len(prev_line) - len(prev_line.lstrip())]
                        target_indent = prev_indent + '\t'
                    elif replace_line.strip().startswith('}'):
                        # 当前行是闭括号，减少一级缩进
                        prev_indent = prev_line[:len(prev_line) - len(prev_line.lstrip())]
                        target_indent = prev_indent[:-1] if prev_indent.endswith('\t') else prev_indent
                    else:
                        # 保持同级缩进
                        prev_indent = prev_line[:len(prev_line) - len(prev_line.lstrip())]
                        target_indent = prev_indent
                else:
                    # 默认：使用第一个原始行的缩进
                    target_indent = original_indents[0] if original_indents else ''
                
                # 应用缩进
                replace_stripped = replace_line.lstrip()
                adjusted_replace_lines.append(target_indent + replace_stripped)
            
            new_lines = (
                original_lines[:i] +
                adjusted_replace_lines +
                original_lines[i + len(search_lines):]
            )
            print(f"  [SR] Applied with whitespace normalization and indent preservation at line {i+1}")
            return '\n'.join(new_lines)
    
    print(f"  [SR] Failed to find match. Search has {len(search_lines)} lines, file has {len(original_lines)} lines")
    return None


def generate_git_diff(file_path: str, original_content: str, new_content: str) -> str:
    """
    生成 git diff 格式的 patch
    
    Args:
        file_path: 文件路径
        original_content: 原始内容
        new_content: 新内容
    
    Returns:
        git diff 格式的字符串
    """
    import difflib
    
    # 确保内容以换行符结尾
    if original_content and not original_content.endswith('\n'):
        original_content += '\n'
    if new_content and not new_content.endswith('\n'):
        new_content += '\n'
    
    # 按行分割，并清理尾部空格（避免 trailing whitespace 警告）
    original_lines = []
    for line in original_content.splitlines(keepends=True):
        # 保留缩进但去除尾部空格
        cleaned = line.rstrip() + '\n' if line.strip() else '\n'
        original_lines.append(cleaned)
    
    new_lines = []
    for line in new_content.splitlines(keepends=True):
        # 保留缩进但去除尾部空格
        cleaned = line.rstrip() + '\n' if line.strip() else '\n'
        new_lines.append(cleaned)
    
    # 生成 unified diff（增加上下文行数）
    diff_lines = difflib.unified_diff(
        original_lines,
        new_lines,
        fromfile=f'a/{file_path}',
        tofile=f'b/{file_path}',
        lineterm='\n',  # 明确指定行结束符
        n=5  # 增加上下文行数从3到5，提高匹配成功率
    )
    
    # 转换为字符串并确保格式正确
    result = ''.join(diff_lines)
    
    # 如果结果为空或格式不对，返回空
    if not result or not result.startswith('---'):
        print(f"  [SR] Warning: Generated diff is empty or malformed")
        return ''
    
    # 确保最后有换行符
    if not result.endswith('\n'):
        result += '\n'
    
    return result


def standardize_patch_in_docker(container_id: str, modified_files: Dict[str, str], original_files: Dict[str, str], project: Optional[str] = None) -> Optional[str]:
    """
    在Docker容器中应用修改并生成标准git diff（确保100% apply成功）
    
    Args:
        container_id: Docker容器ID
        modified_files: {文件路径: 修改后的内容}
        original_files: {文件路径: 原始内容}
        project: 项目名（如mupdf）
    
    Returns:
        标准化的git diff patch
    """
    import subprocess
    import tempfile
    
    try:
        for file_path, new_content in modified_files.items():
            # 确定容器内的完整路径
            if project:
                container_path = f"/src/{project}/{file_path}"
            else:
                container_path = f"/src/{file_path}"
            
            # 创建临时文件
            with tempfile.NamedTemporaryFile(mode='w', delete=False, suffix='.tmp') as f:
                temp_file = f.name
                f.write(new_content)
            
            try:
                # 复制修改后的文件到容器
                subprocess.run(
                    ['docker', 'cp', temp_file, f"{container_id}:{container_path}"],
                    capture_output=True,
                    check=True,
                    timeout=10
                )
                print(f"    [Docker] 📝 Applied changes to {file_path}")
            finally:
                os.unlink(temp_file)
        
        # 在容器中生成git diff（只针对修改的文件，避免submodule变更）
        modified_file_paths = ' '.join(modified_files.keys())
        result = subprocess.run(
            ['docker', 'exec', container_id, 'sh', '-c', 
             f'cd /src/{project if project else ""} && git diff --no-color HEAD -- {modified_file_paths}'],
            capture_output=True,
            text=True,
            timeout=10
        )
        
        if result.returncode == 0 and result.stdout.strip():
            diff_output = result.stdout
            
            # 过滤掉可能的submodule变更
            filtered_lines = []
            skip_section = False
            for line in diff_output.splitlines():
                # 跳过submodule相关的diff段落
                if line.startswith('diff --git') and 'thirdparty/' in line:
                    skip_section = True
                    continue
                elif line.startswith('diff --git'):
                    skip_section = False
                
                if not skip_section:
                    filtered_lines.append(line)
            
            diff_output = '\n'.join(filtered_lines)
            
            # 确保patch以换行符结尾
            if diff_output and not diff_output.endswith('\n'):
                diff_output += '\n'
            
            # 恢复原始文件（重要！避免影响后续验证）
            for file_path in modified_files.keys():
                if project:
                    container_path = f"/src/{project}/{file_path}"
                else:
                    container_path = f"/src/{file_path}"
                
                # 使用git checkout恢复
                subprocess.run(
                    ['docker', 'exec', container_id, 'sh', '-c',
                     f'cd /src/{project if project else ""} && git checkout HEAD -- {file_path}'],
                    capture_output=True,
                    timeout=10
                )
            
            print(f"    [Docker] ✅ Generated standardized git diff and restored files")
            return diff_output
        else:
            print(f"    [Docker] ✗ Failed to generate git diff: {result.stderr[:200]}")
            return None
            
    except subprocess.TimeoutExpired:
        print(f"    [Docker] ✗ Timeout during patch standardization")
        return None
    except Exception as e:
        print(f"    [Docker] ✗ Error during patch standardization: {e}")
        return None


def extract_search_replace_and_generate_patch(llm_output: str, file_contents: Dict[str, str], docker_container_id: Optional[str] = None, project: Optional[str] = None) -> Optional[str]:
    """
    从 LLM 输出提取 SEARCH/REPLACE 命令并生成 git patch
    
    Args:
        llm_output: LLM 的输出
        file_contents: {文件路径: 完整文件内容} 的字典
        docker_container_id: Docker 容器 ID（可选，用于标准化patch生成）
        project: 项目名（可选）
    
    Returns:
        git diff 格式的 patch，如果失败返回 None
    """
    blocks = parse_search_replace_blocks(llm_output)
    
    if not blocks:
        print("  [SR] No SEARCH/REPLACE blocks found in LLM output")
        print(f"  [SR] Debug: LLM output preview: {llm_output[:500]}...")
        return None
    
    print(f"  [SR] Found {len(blocks)} SEARCH/REPLACE block(s)")
    
    # 构建路径别名映射（支持 src/ <-> source/ 互换）
    path_aliases = {}
    for original_path in file_contents.keys():
        path_aliases[original_path] = original_path
        
        # 添加 source/ <-> src/ 别名
        if original_path.startswith('source/'):
            alias = 'src/' + original_path[7:]  # source/fitz/... -> src/fitz/...
            path_aliases[alias] = original_path
        elif original_path.startswith('src/'):
            alias = 'source/' + original_path[4:]  # src/fitz/... -> source/fitz/...
            path_aliases[alias] = original_path
        
        # 添加去掉 ./ 前缀的别名
        if original_path.startswith('./'):
            path_aliases[original_path[2:]] = original_path
    
    # 应用所有修改
    modified_files = {}
    failed_blocks = []
    
    for idx, block in enumerate(blocks, 1):
        file_path = block['file']
        
        print(f"  [SR] Processing block {idx}/{len(blocks)} for file: {file_path}")
        
        # 尝试路径匹配（使用别名）
        actual_path = None
        if file_path in file_contents:
            actual_path = file_path
        elif file_path in path_aliases:
            actual_path = path_aliases[file_path]
            print(f"  [SR] 🔄 Resolved alias: {file_path} -> {actual_path}")
        else:
            # 尝试去掉可能的前缀
            alt_path = file_path.lstrip('./')
            if alt_path in path_aliases:
                actual_path = path_aliases[alt_path]
                print(f"  [SR] 🔄 Resolved alias: {file_path} -> {actual_path}")
            else:
                print(f"  [SR] Warning: File '{file_path}' not in original files")
                print(f"  [SR] Available files: {list(file_contents.keys())}")
                failed_blocks.append((idx, "File not found"))
                continue
        
        # 更新 block 使用实际路径
        file_path = actual_path
        block['file'] = actual_path
        
        original = file_contents.get(file_path)
        if file_path in modified_files:
            original = modified_files[file_path]
        
        new_content = apply_search_replace(original, block['search'], block['replace'])
        
        if new_content:
            modified_files[file_path] = new_content
            print(f"  [SR] ✓ Successfully applied change to {file_path}")
        else:
            print(f"  [SR] ✗ Failed to apply change to {file_path}")
            print(f"  [SR] Search block preview: {block['search'][:200]}...")
            failed_blocks.append((idx, "Match failed"))
            # 不立即返回 None，尝试继续处理其他 blocks
    
    # 如果有失败的 blocks，记录但不一定失败（可能有些成功）
    if failed_blocks:
        print(f"  [SR] Warning: {len(failed_blocks)} block(s) failed: {failed_blocks}")
        # 如果所有 blocks 都失败了，才返回 None
        if len(failed_blocks) == len(blocks):
            return None
    
    # 生成 git diff
    if not modified_files:
        print("  [SR] No files were modified")
        return None
    
    # 过滤掉 fuzzer 文件（硬编码规则）
    import re
    fuzzer_patterns = [
        r'fuzz/.*\.(cc|cpp|c|h)',
        r'.*_fuzzer\.(cc|cpp|c)',
        r'fuzzer.*\.(cc|cpp|c)',
    ]
    
    filtered_files = {}
    for file_path in modified_files:
        is_fuzzer = False
        for pattern in fuzzer_patterns:
            if re.search(pattern, file_path):
                is_fuzzer = True
                print(f"  [SR] ✗ 过滤掉 fuzzer 文件: {file_path}")
                break
        
        if not is_fuzzer:
            filtered_files[file_path] = modified_files[file_path]
    
    if not filtered_files:
        print("  [SR] 所有修改都是 fuzzer 文件，已过滤")
        return None
    
    patches = []
    for file_path in filtered_files:
        original = file_contents[file_path]
        new = filtered_files[file_path]
        
        if original != new:
            diff = generate_git_diff(file_path, original, new)
            if diff:
                patches.append(diff)
                print(f"  [SR] Generated diff for {file_path} ({len(diff)} bytes)")
            else:
                print(f"  [SR] Warning: Empty diff for {file_path}")
    
    if patches:
        final_patch = '\n'.join(patches)
        print(f"  [SR] ✓ Successfully generated patch ({len(final_patch)} bytes total)")
        
        # 🚀 Docker标准化：在容器中应用修改并生成标准git diff（确保100% apply成功）
        if docker_container_id and filtered_files:
            print(f"  [SR] 🔧 Standardizing patch in Docker container...")
            standardized_patch = standardize_patch_in_docker(
                docker_container_id, 
                filtered_files,  # 使用过滤后的文件列表
                file_contents,
                project
            )
            
            if standardized_patch:
                print(f"  [SR] ✅ Generated standardized patch via Docker ({len(standardized_patch)} bytes)")
                return standardized_patch
            else:
                print(f"  [SR] ⚠️ Docker standardization failed, using Python-generated patch")
        
        return final_patch
    
    print("  [SR] No valid patches generated")
    return None


# ==================== Prompt 生成（完全对齐 evaluate_repair.py）====================

def extract_function_boundaries(lines: List[str], bug_line: int, bug_line_count: int) -> Tuple[int, int]:
    """
    智能提取包含bug的函数边界（针对C/C++代码）
    
    Args:
        lines: 文件的所有行
        bug_line: bug所在行号（1-based，需要转换为0-based）
        bug_line_count: bug涉及的行数
    
    Returns:
        (func_start, func_end): 函数的起始和结束行号（0-based）
    """
    bug_idx = bug_line - 1  # 转换为0-based
    
    # 向上查找函数开始（寻找函数签名）
    func_start = bug_idx
    brace_count = 0
    found_open_brace = False
    
    # 首先向上找到包含bug的最近的{
    for i in range(bug_idx, -1, -1):
        line = lines[i].rstrip()
        
        # 统计括号
        for char in line:
            if char == '{':
                found_open_brace = True
                brace_count += 1
            elif char == '}':
                brace_count -= 1
        
        # 如果找到了开括号且回到平衡状态，说明找到了函数开始
        if found_open_brace and brace_count == 1:
            # 继续向上找函数签名（可能在{之前几行）
            func_start = i
            for j in range(i - 1, max(0, i - 10), -1):
                prev_line = lines[j].rstrip()
                # 如果遇到空行、注释结束、或者其他函数的}，停止
                if not prev_line or prev_line.endswith('}') or prev_line.startswith('//'):
                    func_start = j + 1
                    break
                # 如果这行看起来是函数签名的一部分
                if ('(' in prev_line or 'static' in prev_line or 'void' in prev_line or 
                    'int' in prev_line or 'return' not in prev_line):
                    func_start = j
                else:
                    break
            break
    
    # 向下查找函数结束（匹配的}）
    func_end = min(len(lines), bug_idx + bug_line_count + 50)  # 默认限制
    brace_count = 0
    
    for i in range(func_start, len(lines)):
        line = lines[i].rstrip()
        for char in line:
            if char == '{':
                brace_count += 1
            elif char == '}':
                brace_count -= 1
                if brace_count == 0:
                    func_end = i + 1
                    return (func_start, func_end)
    
    # 如果没找到匹配的}，返回一个合理的范围
    return (max(0, bug_idx - 30), min(len(lines), bug_idx + bug_line_count + 30))


def truncate_smart(text: str, max_length: int = 40960) -> Tuple[str, str]:
    """智能截断文本 - 与 evaluate_repair.py 一致"""
    if len(text) <= max_length:
        return text, ""
    truncated = text[:max_length]
    note = f" (truncated from {len(text)} chars)"
    return truncated, note


def get_diff_info(wa_output: Optional[str], expected_output: Optional[str], max_lines: int = 20) -> str:
    """生成 diff 信息 - 与 evaluate_repair.py 的 get_diff_lines 一致"""
    if not wa_output or not expected_output:
        return "Missing output data"
    
    wa_lines = wa_output.splitlines()
    exp_lines = expected_output.splitlines()
    
    diffs = []
    for i in range(max(len(wa_lines), len(exp_lines))):
        wa_line = wa_lines[i].rstrip() if i < len(wa_lines) else "<EOF>"
        exp_line = exp_lines[i].rstrip() if i < len(exp_lines) else "<EOF>"
        if wa_line != exp_line:
            diffs.append(f"Line {i+1}: Got '{wa_line}', Expected '{exp_line}'")
            if len(diffs) >= max_lines:
                break
    
    if not diffs:
        return "Outputs appear identical (possibly whitespace issue)"
    return "\n".join(diffs)


def detect_language_from_path(file_path: str) -> str:
    """根据文件扩展名检测编程语言，用于代码块标记"""
    ext = file_path.lower().split('.')[-1] if '.' in file_path else ''
    
    lang_map = {
        'c': 'c',
        'h': 'c',
        'cpp': 'cpp',
        'cxx': 'cpp',
        'cc': 'cpp',
        'hpp': 'cpp',
        'hxx': 'hpp',
        'sh': 'bash',
        'bash': 'bash',
        'py': 'python',
        'js': 'javascript',
        'ts': 'typescript',
        'java': 'java',
        'go': 'go',
        'rs': 'rust',
        'rb': 'ruby',
        'php': 'php',
        'swift': 'swift',
        'kt': 'kotlin',
        'scala': 'scala',
        'm': 'objectivec',
        'mm': 'objectivec',
    }
    
    return lang_map.get(ext, 'cpp')  # 默认用 cpp


def is_non_core_file(file_path: str) -> bool:
    """
    判断文件是否为非核心代码文件（测试/配置/文档等）
    这些文件的 diff 可以直接提供给 LLM，不需要 LLM 重新生成
    """
    file_lower = file_path.lower()
    
    # 测试文件
    test_patterns = [
        '/test/', '/tests/', 'test/', 'tests/',  # 目录（可能在开头）
        '_test.', 'test_',  # 文件名模式
        '/spec/', '/specs/', '_spec.',
        '/unittest/', '/unittests/',
        '/testcases/', '/testcase/',
        '/fuzz/', '/fuzzing/',  # fuzzer 文件
    ]
    
    # 配置文件
    config_patterns = [
        '.xml', '.yml', '.yaml', '.json', '.toml', '.ini', '.cfg',
        '.conf', '.config', 'dockerfile', '.env',
        '.github/', '.gitlab/', '.ci/',
    ]
    
    # 构建文件（某些情况下）
    build_patterns = [
        'cmakelists.txt', 'makefile', 'build.gradle', 
        'pom.xml', 'package.json', 'setup.py', 'setup.cfg',
        'configure.ac', 'meson.build',
    ]
    
    # 文档
    doc_patterns = [
        '.md', '.txt', '.rst', 'readme', 'changelog', 
        'license', 'authors', 'contributors', 'todo',
        '/doc/', '/docs/',
    ]
    
    # 检查各类模式
    all_patterns = test_patterns + config_patterns + build_patterns + doc_patterns
    
    for pattern in all_patterns:
        if pattern in file_lower:
            return True
    
    return False


def extract_non_core_diffs_from_patch(patch_content: str) -> dict:
    """
    从 ground truth patch 中提取非核心代码文件的 diff
    
    Returns:
        {
            'file_path': {
                'old_content': str,
                'new_content': str,
                'description': str
            }
        }
    """
    non_core_diffs = {}
    
    # 解析 patch 文件
    # 格式：diff --git a/path b/path
    #       --- a/path
    #       +++ b/path
    #       @@ ... @@
    #       -old line
    #       +new line
    
    current_file = None
    current_old = []
    current_new = []
    in_hunk = False
    
    for line in patch_content.split('\n'):
        # 检测文件开始
        if line.startswith('diff --git'):
            # 保存上一个文件
            if current_file and is_non_core_file(current_file):
                non_core_diffs[current_file] = {
                    'old_content': '\n'.join(current_old),
                    'new_content': '\n'.join(current_new),
                    'is_non_core': True
                }
            
            # 开始新文件
            parts = line.split()
            if len(parts) >= 4:
                current_file = parts[2].replace('a/', '', 1)
            current_old = []
            current_new = []
            in_hunk = False
            
        elif line.startswith('+++'):
            # 文件路径确认
            file_path = line.split()[1].replace('b/', '', 1)
            if file_path != '/dev/null':
                current_file = file_path
                
        elif line.startswith('@@'):
            in_hunk = True
            
        elif in_hunk:
            if line.startswith('-') and not line.startswith('---'):
                # 删除的行
                current_old.append(line[1:])
            elif line.startswith('+') and not line.startswith('+++'):
                # 添加的行
                current_new.append(line[1:])
            elif line.startswith(' '):
                # 上下文行
                current_old.append(line[1:])
                current_new.append(line[1:])
    
    # 保存最后一个文件
    if current_file and is_non_core_file(current_file):
        non_core_diffs[current_file] = {
            'old_content': '\n'.join(current_old),
            'new_content': '\n'.join(current_new),
            'is_non_core': True
        }
    
    return non_core_diffs


def generate_repair_prompt(
    crash_info: dict,
    buggy_function: str,
    crash_description: str,  # 相当于 AtCoder 的 problem_description
    strategy: str,
    buggy_code: Optional[str] = None,  # 从 patch 文件提取的修改前代码
    meta_info: Optional[Dict] = None,  # 从 meta.json 加载的详细信息
    complete_files: Optional[Dict] = None,  # 完整文件内容（用于 SEARCH/REPLACE）
    testcase_hex: Optional[str] = None,
    wa_output: Optional[str] = None,
    expected_output: Optional[str] = None,
    secondary_testcase_hex: Optional[str] = None,
    secondary_wa_output: Optional[str] = None,
    secondary_expected_output: Optional[str] = None,
    ground_truth_patch_content: Optional[str] = None  # 新增：ground truth patch 内容
) -> str:
    """
    生成修复 prompt - 统一框架，只在测试用例部分有差异
    
    Args:
        crash_info: 崩溃信息（相当于 WA code 的错误信息）
        buggy_function: 有问题的函数
        crash_description: 崩溃的完整描述（相当于问题描述）
        strategy: 策略名 (no_tc, orig_tc, reduced_tc)
        buggy_code: 从 ground truth patch 提取的修改前代码（可选）
        testcase_hex: 测试用例（十六进制）
        wa_output: 实际崩溃输出
        expected_output: 期望行为（不崩溃）
        secondary_testcase_hex: 原始测试用例（用于对比）
        secondary_wa_output: 第二个测试用例的崩溃输出
        secondary_expected_output: 第二个测试用例的期望输出
    
    Returns:
        LLM prompt, use_search_replace_format
    """
    crash_type = crash_info.get('crash_type', 'unknown')
    stack_top = crash_info.get('stack_top', 'unknown')
    stderr = crash_info.get('stderr', '')[:1500]  # 截断到1500字符
    
    # 优先使用 meta_info 中的信息
    if meta_info:
        crash_type = meta_info.get('crash_type', crash_type)
        
    # ========== SECTION 1: ISSUE DESCRIPTION (统一) ==========
    bug_location_hint = ""
    is_build_script = False
    buggy_files_list = []
    
    if buggy_code and isinstance(buggy_code, dict) and buggy_code.get('files'):
        bug_location_hint = "\n🎯 **EXACT BUG LOCATION**:\n"
        for file_info in buggy_code['files']:
            file_path = file_info['path']
            buggy_files_list.append(file_path)
            line_start = file_info.get('line_start')
            line_count = file_info.get('line_count', 1)
            if line_start:
                bug_location_hint += f"- File: `{file_path}`, Lines {line_start}-{line_start + line_count - 1}\n"
            else:
                bug_location_hint += f"- File: `{file_path}`\n"
            
            # 检测是否为构建脚本、配置文件或测试脚本
            if any(pattern in file_path.lower() for pattern in [
                'build', 'cmake', 'makefile', 'configure', '.sh', '.yml', '.yaml', 
                'build.gradle', 'pom.xml', 'package.json', 'setup.py', '.toml'
            ]):
                is_build_script = True
            
            # 专门检测测试脚本（注意：.sh 已在上面匹配，但我们需要区分测试脚本）
            if 'test' in file_path.lower() or 'lavf' in file_path.lower():
                is_build_script = True  # 重用这个标志，后面会细化提示
    
    # 为构建脚本/测试脚本添加特殊提示
    build_script_hint = ""
    if is_build_script:
        # 检测是否是测试脚本
        is_test_script = any('test' in f.lower() or 'lavf' in f.lower() for f in buggy_files_list)
        
        if is_test_script:
            build_script_hint = f"""

⚠️  **Note: The buggy file is a TEST SCRIPT**, not application source code.
   This means the crash is in a **test harness**, not necessarily in production code.
   
   **Valid fix strategies for test scripts:**
   1. **Disable problematic test cases** (if the underlying feature is known to be broken):
      - Skip CRC/checksum verification: add `disable_crc` parameter
      - Comment out broken test assertions: `#do_avconv_crc ...`
      - Add conditional skip: `test ${{condition}} = "disable" || run_test`
   
   2. **Adjust test configuration** (if test setup is incorrect):
      - Change codec parameters: `-c:v`, `-c:a`
      - Modify test input/output format
      - Add error handling or timeouts
   
   3. **Workaround known bugs** (if fixing the actual code is too complex):
      - Add comments explaining why tests are disabled
      - Example: `# The RealMedia muxer is broken - skip verification`
   
   **⚠️  IMPORTANT**: 
   - Fixing a test script is **acceptable** if the underlying bug is too complex
   - Focus on making the **test pass**, even if the underlying issue isn't fixed
   - Document your workaround with clear comments"""
        else:
            build_script_hint = f"""

⚠️  **Note: The buggy file is a build/configuration script**, not source code.
   The crash may be caused by:
   - **Missing or incorrect compiler/linker flags**
   - **Dependency version conflicts or linking issues**
   - **Enabled features that trigger bugs in dependencies** (consider disabling problematic features)
   - **Missing build guards or sanitization options**
   
   **Common fixes for build scripts:**
   - Disable problematic features: `-DWITH_XXX=off`, `--disable-xxx`
   - Add missing flags: `-DCMAKE_C_FLAGS="$CFLAGS"`, `CXXFLAGS="..."`
   - Change build configuration: `-DCMAKE_BUILD_TYPE`, `-DBUILD_TESTING=off`
   - Work around linking issues by disabling optional components
   
   **⚠️  CRITICAL**: The crash location in the stack trace may be **misleading**!
   - A crash in library X doesn't mean you need to fix library X's code
   - It may mean you need to **change how library X is built or linked**
   - Focus on **what the build script enables/disables**, not just the crash location"""
    
    prompt = f"""We are currently solving the following crash issue:
--- BEGIN ISSUE ---
{crash_description}{build_script_hint}

### Crash Details
- Type: {crash_type}
- Function: {buggy_function}"""
    
    # 添加 meta 信息中的详细 crash state
    if meta_info:
        if meta_info.get('severity'):
            prompt += f"\n- Severity: {meta_info['severity']}"
        if meta_info.get('sanitizer'):
            prompt += f"\n- Sanitizer: {meta_info['sanitizer']}"
        if meta_info.get('crash_state'):
            prompt += f"\n\n### Crash Stack Trace\n```\n{meta_info['crash_state']}\n```"
    else:
        prompt += f"\n- Stack Top: {stack_top}"
    
    prompt += f"""

### Crash Log
{stderr}
--- END ISSUE ---

{bug_location_hint}
"""
    
    # ========== SECTION 2: SOURCE CODE (统一) ==========
    use_search_replace_format = False
    
    if complete_files and complete_files.get('files'):
        use_search_replace_format = True
        prompt += """Below are the source files that contain the bug:
--- BEGIN FILES ---
"""
        
        for file_info in complete_files['files']:
            file_path = file_info['path']
            content = file_info['content']
            line_start = file_info.get('line_start')
            line_count = file_info.get('line_count', 10)
            
            # 智能提取buggy函数，而非大范围上下文
            if line_start:
                lines = content.splitlines()
                
                # 方法1: 如果有buggy_code snippet，尝试精确搜索匹配
                actual_line_start = line_start
                if buggy_code and buggy_code.get('files'):
                    # 尝试在文件中搜索buggy code snippet
                    for f_info in buggy_code['files']:
                        if f_info['path'] == file_path:
                            snippet = f_info.get('code', '').strip()
                            if snippet:
                                # 搜索这个snippet在文件中的位置
                                snippet_lines = snippet.splitlines()
                                for i in range(len(lines) - len(snippet_lines) + 1):
                                    # 简化比较（忽略前后空格）
                                    if all(lines[i+j].strip() == snippet_lines[j].strip() 
                                           for j in range(min(3, len(snippet_lines)))):  # 只检查前3行
                                        actual_line_start = i + 1  # 转为1-based
                                        print(f"  [Context] 🎯 Found buggy code at line {actual_line_start} (originally line {line_start})")
                                        break
                
                # 方法2: 提取完整函数（寻找函数边界）
                func_start, func_end = extract_function_boundaries(lines, actual_line_start, line_count)
                
                # 如果函数过大（>150行），则只提取±20行上下文
                if (func_end - func_start) > 150:
                    context_start = max(0, actual_line_start - 20)
                    context_end = min(len(lines), actual_line_start + line_count + 20)
                    print(f"  [Context] Function too large, using ±20 lines context: {context_start+1}-{context_end}")
                else:
                    context_start = func_start
                    context_end = func_end
                    print(f"  [Context] Extracted function: lines {func_start+1}-{func_end}")
                
                # 提取代码片段并标注 bug 位置
                focused_lines = lines[context_start:context_end]
                
                # 计算bug相对位置
                bug_relative_start = actual_line_start - context_start
                bug_relative_end = bug_relative_start + line_count
                
                # 构建带标注的代码（在 bug 行前后添加箭头标记）
                annotated_lines = []
                for i, line in enumerate(focused_lines):
                    if bug_relative_start <= i < bug_relative_end:
                        # 这是 bug 行，添加箭头标记
                        annotated_lines.append(f"{line}  // <-- ⚠️ BUG IS HERE (Line {context_start + i + 1})")
                    else:
                        annotated_lines.append(line)
                
                focused_content_annotated = '\n'.join(annotated_lines)
                
                # 提取bug所在的精确代码行（高亮显示）
                bug_lines_text = '\n'.join(focused_lines[bug_relative_start:bug_relative_end])
                
                # 分析关键上下文（变量声明、宏使用等）
                context_hints = []
                
                # 检查是否有变量声明
                var_decls = []
                for i, line in enumerate(focused_lines[:bug_relative_start]):
                    if any(keyword in line for keyword in ['int ', 'char ', 'void *', 'struct ', 'float ', 'double ', 'fz_', 'timelib_']):
                        if '=' in line or ';' in line:
                            var_decls.append(f"Line {context_start + i + 1}: {line.strip()}")
                
                if var_decls:
                    context_hints.append("**Variable declarations before bug**:\n" + "\n".join(f"  - {v}" for v in var_decls[-5:]))  # 最后5个
                
                # 检查是否有宏使用
                macro_uses = []
                for i, line in enumerate(focused_lines):
                    if any(macro in line for macro in ['fz_try', 'fz_always', 'fz_catch', 'fz_var', 'do {', 'while (']):
                        macro_uses.append(f"Line {context_start + i + 1}: {line.strip()}")
                
                if macro_uses:
                    context_hints.append("**Special macros/structures in this function**:\n" + "\n".join(f"  - {m}" for m in macro_uses[:8]))
                
                context_section = "\n\n".join(context_hints) + "\n\n" if context_hints else ""
                
                # 检测文件语言
                lang = detect_language_from_path(file_path)
                
                prompt += f"""### {file_path}
**Function containing the bug** (lines {context_start+1}-{context_end}):

```{lang}
{focused_content_annotated}
```

{context_section}**🎯 Bug Location** (lines {line_start}-{line_start+line_count-1}):
```{lang}
{bug_lines_text}
```

**⚠️ IMPORTANT**: When generating your SEARCH/REPLACE edit:
- The shown function has {len(focused_lines)} lines total
- Bug is at lines {line_start}-{line_start+line_count-1}
- Variables declared before the bug MUST NOT be removed (they may be used after)
- Check for paired macros (fz_try/always/catch, do/while) - keep them balanced
- Only edit the MINIMAL lines needed to fix the bug

"""
            else:
                # 没有行号信息，提供合理范围
                lines = content.splitlines()
                lang = detect_language_from_path(file_path)
                if len(lines) > 100:
                    # 提取前100行
                    focused_content = '\n'.join(lines[:100])
                    prompt += f"""### {file_path}
**First 100 lines**:
```{lang}
{focused_content}
```

"""
                else:
                    prompt += f"""### {file_path}
```{lang}
{content}
```

"""
        
        prompt += """--- END FILES ---

"""
    
    # ========== 处理非核心文件的 diff（测试/配置等）==========
    non_core_section = ""
    if ground_truth_patch_content:
        non_core_diffs = extract_non_core_diffs_from_patch(ground_truth_patch_content)
        
        if non_core_diffs:
            non_core_section = """
## 📋 Supporting Files (Reference Only - Already Provided)

The following files are also modified in this fix, but you **DO NOT need to generate** patches for them.
They are provided here for **context only** to help you understand the complete fix.

**Your task is ONLY to fix the core source code files shown above.**

"""
            
            for file_path, diff_info in non_core_diffs.items():
                old_content = diff_info['old_content'].strip()
                new_content = diff_info['new_content'].strip()
                
                if old_content and new_content:
                    # 检测文件语言
                    lang = detect_language_from_path(file_path)
                    
                    # 判断文件类型
                    file_type = ""
                    if '/test/' in file_path.lower() or '_test.' in file_path.lower():
                        file_type = " (Test File)"
                    elif any(ext in file_path.lower() for ext in ['.xml', '.yml', '.yaml', '.json']):
                        file_type = " (Configuration File)"
                    elif any(ext in file_path.lower() for ext in ['.md', 'readme']):
                        file_type = " (Documentation)"
                    elif any(pat in file_path.lower() for pat in ['cmake', 'makefile', '.sh']):
                        file_type = " (Build Script)"
                    
                    non_core_section += f"""
### {file_path}{file_type}

**SEARCH:**
```{lang}
{old_content}
```

**REPLACE:**
```{lang}
{new_content}
```

---

"""
            
            non_core_section += """
**⚠️ REMINDER**: The above files are already handled. Focus on fixing the **core source code** only.

"""
            
            prompt += non_core_section
    
    # === 如果没有完整文件，fallback 到 buggy code snippet ===
    elif buggy_code:
        # buggy_code 现在是字典，包含 code 和 files 信息
        code_text = buggy_code.get('code', '') if isinstance(buggy_code, dict) else str(buggy_code)
        files_info = buggy_code.get('files', []) if isinstance(buggy_code, dict) else []
        
        code_truncated, note = truncate_smart(code_text, 8000)
        if note:
            print(f"  [Truncation] Buggy code{note}")
        
        # 为代码片段添加位置信息（如果有）
        location_info = ""
        lang = 'cpp'  # 默认
        if files_info:
            for file_info in files_info:
                file_path = file_info.get('path', 'unknown')
                lang = detect_language_from_path(file_path)  # 从第一个文件检测语言
                line_start = file_info.get('line_start')
                line_count = file_info.get('line_count', 1)
                if line_start:
                    location_info += f"- **File**: `{file_path}`, **Lines**: {line_start}-{line_start + line_count - 1}\n"
                break  # 只从第一个文件检测语言
        
        prompt += f"""### Buggy Code Snippet
{location_info}
```{lang}
{code_truncated}
```

"""
    
    # ========== SECTION 3: TEST CASE (三个策略的唯一差异) ==========
    if strategy == "no_tc":
        # Strategy 1: No test case
        pass  # 不添加任何测试用例信息
        
    elif strategy == "orig_tc":
        # Strategy 2: Original test case (不限制长度，完整显示)
        if testcase_hex:
            # 不截断原始测试用例，完整传给模型（最多200KB）
            tc_truncated, _ = truncate_smart(testcase_hex, 400000)  # 200KB = 400000 hex chars
            
            prompt += f"""### Failing Test Case
Input (hex):
```
{tc_truncated}
```
"""
            
            if wa_output and expected_output:
                wa_trunc, _ = truncate_smart(wa_output, 2048)
                exp_trunc, _ = truncate_smart(expected_output, 2048)
                
                prompt += f"""
Actual Output (crash):
```
{wa_trunc}
```

Expected Output (no crash):
```
{exp_trunc}
```

"""
    
    elif strategy == "reduced_tc":
        # Strategy 3: Reduced test case (ReduceFix) - 增强版
        if testcase_hex:
            reduced_bytes = len(testcase_hex) // 2
            original_bytes = None
            reduction_ratio = None
            
            if secondary_testcase_hex:
                original_bytes = len(secondary_testcase_hex) // 2
                if original_bytes > 0:
                    reduction_ratio = (1 - reduced_bytes / original_bytes) * 100
            
            # 关键优化：最多显示 1KB（2048 hex chars）
            # 如果测试用例太小(<1KB)，显示全部；如果太大，截断到1KB
            max_display_hex_chars = 2048  # 1KB = 2048 hex chars
            tc_truncated, truncation_note = truncate_smart(testcase_hex, max_display_hex_chars)
            
            # 分析测试用例特征
            tc_features = []
            try:
                test_bytes = bytes.fromhex(testcase_hex[:200] if len(testcase_hex) > 200 else testcase_hex)
                
                # 尺寸分析
                if reduced_bytes < 10:
                    tc_features.append("- Very small input (edge case: minimal data)")
                elif reduced_bytes < 100:
                    tc_features.append("- Small input (likely a specific trigger pattern)")
                elif reduced_bytes < 1000:
                    tc_features.append("- Medium-sized input")
                
                # 字节模式分析
                if len(test_bytes) > 0:
                    if all(b == 0 for b in test_bytes):
                        tc_features.append("- Pattern: All null bytes → tests null/empty handling")
                    elif len(set(test_bytes)) == 1:
                        tc_features.append(f"- Pattern: Repeated byte 0x{test_bytes[0]:02x}")
                    
                    printable_count = sum(1 for b in test_bytes if 32 <= b < 127)
                    if printable_count > len(test_bytes) * 0.8:
                        tc_features.append("- Mostly printable ASCII → likely text-based input")
                    
                    if 0 in test_bytes:
                        tc_features.append("- Contains null bytes → may test string termination")
            except:
                pass
            
            tc_analysis = ""
            if tc_features:
                tc_analysis = "\n**Input Characteristics**:\n" + "\n".join(tc_features) + "\n"
            
            # 构建缩减信息
            size_info = f"Minimized Size: {reduced_bytes:,} bytes"
            display_note = ""
            if original_bytes and reduction_ratio:
                size_info = f"Original: {original_bytes:,} bytes → Minimized: {reduced_bytes:,} bytes ({reduction_ratio:.1f}% reduction)"
            
            # 说明是否截断
            if truncation_note:
                display_note = f"\n**Note**: Showing first 1KB (1024 bytes) of minimized input for analysis. Full input is {reduced_bytes:,} bytes."
            elif reduced_bytes <= 1024:
                display_note = f"\n**Note**: Complete minimized input shown below ({reduced_bytes} bytes)."
            
            prompt += f"""### Failing Test Case (Minimized by Automated Reduction)

**Minimization Summary**:
{size_info}

**Purpose of Minimization**:
The test case has been automatically reduced using delta debugging to identify the MINIMAL input 
that still triggers the crash. This helps reveal the specific pattern or edge case that causes the bug.

**How to use this information**:
1. The minimized input reveals a specific triggering pattern (not just random data)
2. Consider: What makes this particular input trigger the bug? (boundary condition, special character, size, structure)
3. Your fix should handle this pattern and similar edge cases gracefully
{tc_analysis}{display_note}

**Minimized Input** (hex format):
```
{tc_truncated}
```

**Expected Behavior After Fix**:
- The program should handle this input without crashing
- Focus on preventing {crash_info.get('crash_type', 'the crash')}

"""
            
            if wa_output and expected_output:
                # wa_output 和 expected_output 通常只是占位符，不显示
                pass
    
    # ========== SECTION 4: TASK INSTRUCTIONS (完全统一) ==========
    task_instructions = """### Your Task
Analyze the crash and generate a patch to fix the bug.

**Instructions**:
1. Identify the root cause based on crash information and code
2. Generate a minimal fix targeting the buggy lines
3. Ensure the fix handles edge cases properly
4. Do not over-engineer - focus on the specific issue

"""
    
    # 为构建脚本添加额外的分析指导
    if is_build_script:
        task_instructions += """**🔍 Special Analysis for Build Scripts**:

Before generating the fix, consider these questions:
1. **Does the crash indicate a linking/dependency issue?**
   - Undefined references, symbol conflicts, or version mismatches
   - Consider disabling problematic features rather than adding flags

2. **Is the crash in a library that's being built?**
   - The fix might be in how that library is configured (CMake flags, configure options)
   - Check if similar libraries in the build script use different flags

3. **What features are currently enabled?**
   - Look for `-DWITH_XXX=on` or `--enable-xxx` that might trigger bugs
   - Try disabling optional features: `-DWITH_JPEG_DECODER=off`, `-DENABLE_PLUGIN_LOADING=off`

4. **Are all dependencies built consistently?**
   - Do other libraries use `-DCMAKE_C_FLAGS="$CFLAGS"`? Should this one too?
   - Or is adding sanitizer flags unnecessary/harmful in this case?

**💡 Tip**: For oss-fuzz builds, disabling non-essential features is often the right fix, not adding flags.

"""
    
    prompt += task_instructions
    
    # ========== SECTION 5: OUTPUT FORMAT (完全统一) ==========
    if use_search_replace_format:
        prompt += """### Output Format
Please first localize the bug, then generate *SEARCH/REPLACE* edits to fix the issue.

Every *SEARCH/REPLACE* edit must use this format:
1. The file path wrapped in ### (e.g., ### src/file.cpp)
2. The start and end line numbers (- start_line: N, - end_line: M)
3. The start of search block: <<<<<<< SEARCH
4. A contiguous chunk of lines to search for in the existing source code
5. The dividing line: =======
6. The lines to replace into the source code
7. The end of the replace block: >>>>>>> REPLACE

Example (MINIMAL edit with context awareness):
```cpp
### src/memory/allocator.cpp
- start_line: 145
- end_line: 149
<<<<<<< SEARCH
\tif (size > 0) {
\t\tptr = malloc(size);
\t\tuse_memory(ptr);
\t}
=======
\tif (size > 0) {
\t\tptr = malloc(size);
\t\tif (ptr != NULL)
\t\t\tuse_memory(ptr);
\t}
>>>>>>> REPLACE
```

**CRITICAL COMPILATION SAFETY REQUIREMENTS**:

1. **MINIMAL edits ONLY** - Include only 3-8 lines in SEARCH block (bug line + 1-3 context lines)
   - More lines = higher risk of breaking dependencies
   - Focus ONLY on the buggy statement and immediate neighbors

2. **Variable Dependency Check** - Before removing/modifying any line, verify:
   - ❌ NEVER remove variable declarations if they're used later
   - ❌ NEVER remove assignments if the variable is referenced afterwards
   - ✅ Check if variables in your SEARCH block are used outside it

3. **Macro Pairing Safety** - Special macros MUST stay paired:
   - `fz_try(ctx) { ... } fz_always(ctx) { ... } fz_catch(ctx) { ... }` → NEVER break this chain
   - `do { ... } while(...)` → NEVER remove the `while` if you keep the `do`
   - `if (...) { ... } else { ... }` → Be careful not to create dangling else

4. **Code Block Integrity**:
   - ❌ NEVER remove opening/closing braces unless removing entire block
   - ❌ NEVER remove function declarations/definitions
   - ✅ Preserve the structural indentation and nesting

5. **Indentation**:
   - **Use TAB characters (\\t)** for indentation, NOT spaces - the codebase uses tabs
   - The SEARCH block must match EXACTLY (preserve all tabs and spacing)

6. **Context Awareness** - When editing, mentally visualize:
   ```
   [Lines before SEARCH - you don't see these, assume they exist]
   <<<<<<< SEARCH
   your visible edit zone (3-8 lines)
   =======
   your proposed changes
   >>>>>>> REPLACE
   [Lines after SEARCH - you don't see these, assume they exist]
   ```
   Your edit should work correctly with unknown context before and after!

**Common Compilation Errors to AVOID**:
- ❌ "use of undeclared identifier 'X'" → You removed the declaration of X
- ❌ "expected 'while' in do/while loop" → You broke a macro pairing
- ❌ "function definition not allowed here" → You accidentally removed a closing brace
- ❌ "extraneous closing brace" → You removed code but left its closing brace

**Golden Rule**: If unsure whether a line is safe to remove, KEEP IT. Only modify the absolute minimum needed to fix the bug.
"""
    else:
        prompt += """### Output Format
Provide the patch in unified diff format:
```diff
--- a/path/to/file.c
+++ b/path/to/file.c
@@ -EXACT_START_LINE,line_count +new_start,new_count @@
 context line (unchanged)
-old buggy line (to remove)
+new fixed line (to add)
 context line (unchanged)
```

**CRITICAL REQUIREMENTS**:
1. Use the EXACT line numbers from the "Buggy Code" section
2. Include 2-3 lines of unchanged context before and after
3. Ensure the @@ header matches the actual code location
4. Use the correct file path shown in "Buggy Code"
"""
    
    return prompt, use_search_replace_format


# ==================== 并行生成（对齐 evaluate_repair.py）====================

def generate_single_repair(
    crash_info: dict,
    buggy_function: str,
    crash_description: str,
    strategy: str,
    version: int,
    buggy_code: Optional[str] = None,
    meta_info: Optional[Dict] = None,
    complete_files: Optional[Dict] = None,
    testcase_hex: Optional[str] = None,
    wa_output: Optional[str] = None,
    expected_output: Optional[str] = None,
    secondary_testcase_hex: Optional[str] = None,
    secondary_wa_output: Optional[str] = None,
    secondary_expected_output: Optional[str] = None,
    model: str = REPAIR_MODEL,
    docker_container_id: Optional[str] = None,
    project: Optional[str] = None,
    save_prompt_dir: Optional[str] = None,  # 保存 prompt 的目录
    ground_truth_patch_path: Optional[str] = None  # 新增：ground truth patch 文件路径
) -> Optional[str]:
    """
    生成单个修复版本 - 对齐 evaluate_repair.py 的 generate_single_version
    """
    # 使用不同的 temperature（循环使用）
    temperature = TEMPERATURE_RANGE[(version - 1) % len(TEMPERATURE_RANGE)]
    
    try:
        # 读取 ground truth patch 内容（如果提供）
        ground_truth_patch_content = None
        if ground_truth_patch_path:
            try:
                with open(ground_truth_patch_path, 'r', encoding='utf-8', errors='ignore') as f:
                    ground_truth_patch_content = f.read()
            except Exception as e:
                print(f"  [Warning] Failed to load ground truth patch: {e}")
        
        prompt, use_search_replace = generate_repair_prompt(
            crash_info, buggy_function, crash_description, strategy,
            buggy_code, meta_info, complete_files, testcase_hex, wa_output, expected_output,
            secondary_testcase_hex, secondary_wa_output, secondary_expected_output,
            ground_truth_patch_content
        )
        
        # 保存 prompt 到文件（如果指定了输出目录）
        if save_prompt_dir:
            prompt_file = Path(save_prompt_dir) / f"{strategy}_v{version}_prompt.txt"
            prompt_file.parent.mkdir(parents=True, exist_ok=True)
            with open(prompt_file, 'w', encoding='utf-8') as f:
                f.write(f"=== Prompt for {strategy} version {version} ===\n")
                f.write(f"Model: {model}\n")
                f.write(f"Temperature: {temperature}\n")
                f.write(f"Use SEARCH/REPLACE: {use_search_replace}\n")
                f.write("="*70 + "\n\n")
                f.write(prompt)
        
        prompt_history = [{'role': 'user', 'content': prompt}]
        raw_response = llm.call_llm(
            prompt_history=prompt_history,
            model_name=model,
            temperature=temperature,
        )
        
        # 保存原始 LLM 输出（如果指定了输出目录）
        if save_prompt_dir and raw_response:
            response_file = Path(save_prompt_dir) / f"{strategy}_v{version}_response.txt"
            response_file.parent.mkdir(parents=True, exist_ok=True)
            with open(response_file, 'w', encoding='utf-8') as f:
                f.write(f"=== LLM Response for {strategy} version {version} ===\n")
                f.write(f"Model: {model}\n")
                f.write(f"Temperature: {temperature}\n")
                f.write("="*70 + "\n\n")
                f.write(raw_response)
        
        if raw_response:
            # 根据格式提取和转换代码
            if use_search_replace and complete_files:
                # 从完整文件构建文件内容字典
                file_contents = {}
                for file_info in complete_files.get('files', []):
                    file_contents[file_info['path']] = file_info['content']
                
                # 提取 SEARCH/REPLACE 并生成 patch（使用Docker标准化）
                patch_code = extract_search_replace_and_generate_patch(
                    raw_response, file_contents, 
                    docker_container_id=docker_container_id,
                    project=project
                )
                
                if patch_code and test_patch_validity(patch_code):
                    print(f"    [SR] ✓ Generated valid patch via SEARCH/REPLACE")
                    return patch_code
                else:
                    # 如果 SEARCH/REPLACE 失败，尝试传统方法（提取diff格式）
                    print(f"    [Fallback] SEARCH/REPLACE failed or invalid patch, trying traditional extraction")
                    patch_code = extract_code_from_repair(raw_response)
                    
                    # 验证提取的patch是否是有效的diff格式（而非SEARCH/REPLACE格式）
                    if patch_code and test_patch_validity(patch_code):
                        # 额外检查：确保不是SEARCH/REPLACE格式
                        if '<<<<<<< SEARCH' not in patch_code and '>>>>>>> REPLACE' not in patch_code:
                            print(f"    [Fallback] ✓ Extracted valid diff patch via traditional method")
                            return patch_code
                        else:
                            print(f"    [Fallback] ✗ Extracted patch is still in SEARCH/REPLACE format, rejecting")
                            return None
                    else:
                        print(f"    [Fallback] ✗ No valid diff patch found in LLM output")
                        return None
            else:
                # 使用传统方法提取代码
                patch_code = extract_code_from_repair(raw_response)
                if patch_code:
                    print(f"    [Traditional] ✓ Extracted patch")
                return patch_code
        
        return None
    
    except Exception as e:
        print(f"    [Warning] Failed to generate version {version}: {e}")
        import traceback
        traceback.print_exc()
        return None


def generate_versions_parallel(
    crash_info: dict,
    buggy_function: str,
    crash_description: str,
    strategy: str,
    num_versions: int = TOP_K,
    buggy_code: Optional[str] = None,
    meta_info: Optional[Dict] = None,
    complete_files: Optional[Dict] = None,
    testcase_hex: Optional[str] = None,
    wa_output: Optional[str] = None,
    expected_output: Optional[str] = None,
    secondary_testcase_hex: Optional[str] = None,
    secondary_wa_output: Optional[str] = None,
    secondary_expected_output: Optional[str] = None,
    model: str = REPAIR_MODEL,
    max_threads: int = MAX_THREADS,
    docker_container_id: Optional[str] = None,
    project: Optional[str] = None,
    save_prompt_dir: Optional[str] = None,  # 保存 prompt 的目录
    ground_truth_patch_path: Optional[str] = None  # 新增：ground truth patch 文件路径
) -> List[Optional[str]]:
    """
    并行生成多个版本 - 完全对齐 evaluate_repair.py 的 generate_versions_parallel
    
    Returns:
        包含 num_versions 个元素的列表，成功生成的是代码字符串，失败的是 None
    """
    print(f"  Generating {num_versions} versions in parallel (strategy: {strategy})...")
    
    def generate_wrapper(version_num):
        """包装函数用于并行执行"""
        result = generate_single_repair(
            crash_info, buggy_function, crash_description, strategy, version_num,
            buggy_code, meta_info, complete_files, testcase_hex, wa_output, expected_output,
            secondary_testcase_hex, secondary_wa_output, secondary_expected_output,
            model, docker_container_id, project, save_prompt_dir, ground_truth_patch_path
        )
        return version_num, result
    
    results = {}
    
    # 使用 ThreadPoolExecutor 并行生成
    with ThreadPoolExecutor(max_workers=min(num_versions, max_threads)) as executor:
        futures = {executor.submit(generate_wrapper, i): i for i in range(1, num_versions + 1)}
        
        for future in as_completed(futures):
            version_num, code = future.result()
            results[version_num] = code
    
    # 按版本号顺序返回
    versions_list = [results[i] for i in range(1, num_versions + 1)]
    successful_count = sum(1 for v in versions_list if v is not None)
    
    print(f"  Generated {successful_count}/{num_versions} versions successfully")
    return versions_list


# ==================== 评估逻辑（对齐 evaluate_repair.py）====================

def evaluate_strategy_versions(
    strategy_name: str,
    strategy_key: str,
    patch_versions: List[Optional[str]],
    docker_tester: DockerPatchTester,
    testcase_data: bytes
) -> Dict:
    """
    评估一个策略的所有版本 - 对齐 evaluate_repair.py 的 evaluate_strategy_versions
    
    只要有1个版本通过 → 该策略成功
    
    Returns:
        {
            "passed": bool,  # 是否有至少1个版本通过
            "status": str,
            "successful_version": int or None,
            "versions": [{"version": int, "passed": bool, "status": str, ...}, ...]
        }
    """
    expected_count = TOP_K
    actual_count = len([p for p in patch_versions if p is not None])
    print(f"  Evaluating {strategy_name} ({actual_count}/{expected_count} versions)...")
    
    best_result = {
        "passed": False,
        "status": "No versions available",
        "successful_version": None,
        "versions": []
    }
    
    if actual_count == 0:
        print("    Result: No code generated")
        return best_result
    
    # 测试所有版本
    version_results = []
    passed_versions = []
    
    for version_idx, patch_code in enumerate(patch_versions, 1):
        if patch_code is None:
            # 生成失败
            version_results.append({
                "version": version_idx,
                "passed": False,
                "status": "Generation failed",
                "compiled": False,
                "fixed_crash": False,
                "duration": 0
            })
            continue
        
        # 真实验证
        print(f"    v{version_idx}: Real validation...")
        validation_result = docker_tester.validate_repair(
            patch_code,
            testcase_data,
            None
        )
        
        passed = validation_result.get('success', False)
        
        version_results.append({
            "version": version_idx,
            "passed": passed,
            "status": "Success" if passed else "Failed",
            "compiled": validation_result.get('compiled', False),
            "fixed_crash": validation_result.get('fixed_crash', False),
            "duration": validation_result.get('duration', 0),
            "error": validation_result.get('error')
        })
        
        if passed:
            passed_versions.append(version_idx)
            if not best_result["passed"]:  # 记录第一个成功的版本
                best_result = {
                    "passed": True,
                    "status": "Success",
                    "successful_version": version_idx
                }
    
    # 添加详细版本结果
    best_result["versions"] = version_results
    
    # 最终结果
    if passed_versions:
        print(f"    Result: SUCCESS ({len(passed_versions)}/{len(patch_versions)} passed)")
    else:
        print(f"    Result: FAILURE (0/{len(patch_versions)} passed)")
        if version_results:
            best_result["status"] = f"All {len(patch_versions)} versions failed"
    
    return best_result


# ==================== 主实验函数（对齐 evaluate_repair.py 的 main）====================

def run_repair_experiment(
    case_config: dict,
    crash_info: dict,
    original_testcase: bytes,
    reduced_testcase: bytes,
    output_dir: str,
    model: str = REPAIR_MODEL
) -> Dict:
    """
    运行完整的修复实验 - 完全对齐 evaluate_repair.py 的评估逻辑
    
    Args:
        case_config: 案例配置
        crash_info: 崩溃信息
        original_testcase: 原始测试用例
        reduced_testcase: 缩减后的测试用例
        output_dir: 输出目录
        model: LLM 模型
    
    Returns:
        修复结果字典
    """
    project = case_config.get('target', 'unknown')
    buggy_function = case_config.get('buggy_function', 'unknown')
    docker_image = case_config.get('docker_image_vul')
    arvo_id = case_config.get('arvo_id')
    
    # ==================== 加载 Ground Truth 数据 ====================
    buggy_code = None
    meta_info = None
    complete_files = None  # 完整文件内容（用于 SEARCH/REPLACE）
    
    if arvo_id:
        print(f"\n[Ground Truth] Loading data for ARVO-{arvo_id}...")
        
        # 加载 meta 信息
        meta_info = load_meta_info(arvo_id)
        if meta_info:
            print(f"[Ground Truth] ✓ Meta info loaded")
        else:
            print(f"[Ground Truth] ✗ No meta info available")
        
        # 加载 patch（获取文件列表和行号信息）
        buggy_code = load_buggy_code_from_patch(arvo_id)
        if buggy_code:
            print(f"[Ground Truth] ✓ Buggy code snippet loaded")
        else:
            print(f"[Ground Truth] ✗ No patch available")
    else:
        print(f"[Ground Truth] No ARVO ID in config, skipping data loading")
    
    # 准备 crash description（相当于 problem description）
    crash_description = f"""# Crash in {project}

Function: {buggy_function}
Type: {crash_info.get('crash_type', 'unknown')}

This is a memory safety bug that needs to be fixed.
"""
    
    # 准备测试用例的十六进制表示
    orig_tc_hex = original_testcase.hex()
    reduced_tc_hex = reduced_testcase.hex()
    
    print(f"Original testcase: {len(original_testcase):,} bytes")
    print(f"Reduced testcase: {len(reduced_testcase):,} bytes")
    print(f"Starting repair with {3} strategies × TOP_K={TOP_K}...")
    
    # ==================== 启动 Docker 容器 ====================
    docker_tester = None
    if USE_REAL_VALIDATION and docker_image:
        try:
            docker_tester = DockerPatchTester(docker_image, project, timeout=120)
            docker_tester.start_container()
            container_id = docker_tester.container_id
            print(f"  [Validation] Using real Docker validation (image: {docker_image})")
            print(f"  [Container] ID: {container_id[:12] if container_id else 'unknown'}")
        except Exception as e:
            print(f"  [Warning] Docker start failed, cannot proceed: {e}")
            return {"error": f"Docker initialization failed: {e}"}
    
    if not docker_tester:
        return {"error": "Docker tester not available"}
    
    try:
        # ==================== 从 Docker 容器获取完整文件（最准确的方法）====================
        if arvo_id and buggy_code and docker_tester:
            container_id = docker_tester.container_id
            if container_id:
                print(f"\n[Docker Files] 从容器获取完整文件内容...")
                complete_files = load_buggy_files_from_docker(container_id, buggy_code, project)
                
                if complete_files:
                    print(f"[Docker Files] ✓ 从 Docker 容器加载完整文件 ({len(complete_files['files'])} 个文件)")
                else:
                    print(f"[Docker Files] ✗ 从容器加载失败，将使用代码片段")
            else:
                print(f"[Docker Files] ✗ 无法获取容器 ID")
        
        # ==================== 3个策略：生成修复 ====================
        
        strategies_data = {}
        
        # Strategy 1: Without Test (no_tc)
        print("策略 1: Without Test (不使用测试用例)")
        versions_1 = generate_versions_parallel(
            crash_info, buggy_function, crash_description, "no_tc",
            num_versions=TOP_K, buggy_code=buggy_code, meta_info=meta_info,
            complete_files=complete_files,  # 传递完整文件
            model=model, max_threads=MAX_THREADS,
            docker_container_id=container_id, project=project  # 传递Docker容器信息
        )
        strategies_data["without_test"] = versions_1
        
        # Strategy 2: Origin Test (orig_tc)
        print("策略 2: Origin Test (使用原始测试用例)")
        versions_2 = generate_versions_parallel(
            crash_info, buggy_function, crash_description, "orig_tc",
            num_versions=TOP_K, buggy_code=buggy_code, meta_info=meta_info,
            complete_files=complete_files,  # 传递完整文件
            testcase_hex=orig_tc_hex,
            wa_output="(crash)",
            expected_output="(no crash)",
            model=model, max_threads=MAX_THREADS,
            docker_container_id=container_id, project=project  # 传递Docker容器信息
        )
        strategies_data["origin_test"] = versions_2
        
        # Strategy 3: Reduced Test (reduced_tc) - by ReduceFix
        print("策略 3: Reduced Test (使用 ReduceFix 缩减后的测试用例)")
        versions_3 = generate_versions_parallel(
            crash_info, buggy_function, crash_description, "reduced_tc",
            num_versions=TOP_K, buggy_code=buggy_code, meta_info=meta_info,
            complete_files=complete_files,  # 传递完整文件
            testcase_hex=reduced_tc_hex,
            wa_output="(crash)",
            expected_output="(no crash)",
            secondary_testcase_hex=orig_tc_hex,  # 传递原始测试用例用于显示缩减率
            model=model, max_threads=MAX_THREADS,
            docker_container_id=container_id, project=project  # 传递Docker容器信息
        )
        strategies_data["reduced_test"] = versions_3
        
        # ==================== 评估所有策略 ====================
        
        results = {}
        
        # 对每个策略评估
        result_1 = evaluate_strategy_versions(
            "Without Test", "without_test", versions_1,
            docker_tester, reduced_testcase
        )
        results["without_test"] = result_1
        
        result_2 = evaluate_strategy_versions(
            "Origin Test", "origin_test", versions_2,
            docker_tester, reduced_testcase
        )
        results["origin_test"] = result_2
        
        result_3 = evaluate_strategy_versions(
            "Reduced Test (ReduceFix)", "reduced_test", versions_3,
            docker_tester, reduced_testcase
        )
        results["reduced_test"] = result_3
        
        # ==================== 输出结果摘要 ====================
        print("\n--- 修复结果 (3个策略, K-Version方法) ---")
        print(f"生成: 每个策略 {TOP_K} 个版本")
        print(f"评估: 至少1个版本通过即成功")
        print("")
        
        for strategy_key in ["without_test", "origin_test", "reduced_test"]:
            result = results[strategy_key]
            passed_count = sum(1 for v in result["versions"] if v["passed"])
            total_count = len(result["versions"])
            status = "✓ 成功" if result["passed"] else "✗ 失败"
            print(f"  {strategy_key:20s}: {status} ({passed_count}/{total_count} 版本通过)")
        
        # ==================== 附加所有生成的补丁 ====================
        # 将所有策略的补丁添加到结果中，供后续保存
        results["patches"] = {
            "without_test": versions_1,  # List[Optional[str]]，None表示生成失败
            "origin_test": versions_2,
            "reduced_test": versions_3
        }
        
        return results
    
    finally:
        # 清理 Docker 容器
        if docker_tester:
            docker_tester.cleanup()


# ==================== 测试函数 ====================

if __name__ == "__main__":
    print("APR Repair Module v2 - Aligned with evaluate_repair.py")
    print("This module should be imported, not run directly")


# evaluate_repair.py
import os
import sys
import argparse
import json
import glob
import subprocess
import tempfile
import shutil
import time
import traceback # Needed for traceback.print_exc()
import hashlib # For code hashing
import re # For regular expressions
import math # For math.comb()
from typing import Optional, Tuple, List, Dict, Any
from concurrent.futures import ThreadPoolExecutor, as_completed
import threading
import fcntl # For file locking on Unix-like systems
from dataclasses import dataclass
from enum import Enum
# --- Import markdownify ---
import markdownify
# BeautifulSoup removed - using full problem description without HTML parsing 

# --- Import new LLM module --- 
import llm 

# --- Configuration ---
# Use relative paths for portability
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
BASE_TESTCASE_PATH = os.path.join(SCRIPT_DIR, "lftbench", "tests")  # Use tests from lftbench
COMPILE_TIMEOUT = 10 # Timeout for compilation
RUN_TIMEOUT = 5      # Timeout for running code on one test case
REDUCE_TIMEOUT = 30  # Timeout for reduction process in seconds
TOP_K = 10
# --- LLM Configuration for Repair --- 
REPAIR_MODEL_NAME = "qwen2.5-coder-7b-instruct" # Model to use for repairs
REPAIR_TEMPERATURE = 0.8
MAX_INPUT_LENGTH_FOR_LLM = 40960 # Max chars for failing input in prompt (10KB)
# --- Add max length for output context ---
MAX_OUTPUT_LENGTH_FOR_LLM = 8192 # Max chars for actual/expected output in prompt (2KB)
# Default max threads - can be overridden by command line argument
DEFAULT_MAX_THREADS = 5

# --- ChatRepair Configuration ---
MAX_CHATREPAIR_TRIES = 1
MAX_CHATREPAIR_CONVERSATION_LENGTH = 2
USE_TEMPERATURE_DIVERSITY = True  # Whether to vary temperature for different versions

# --- Try importing necessary components ---
try:
    # Assuming reduce.py is in the same directory or Python path
    from reduce import compile_program, _parse_problem_id
    print("[Info] Successfully imported required functions from reduce.")
except ImportError as e:
    print(f"[Error] Failed to import from reduce ({e}). Ensure reduce.py is accessible.", file=sys.stderr)
    sys.exit(1)

def _calculate_pass_at_k_util(n: int, c: int, k: int) -> float:
    """
    正确计算pass@k - 从n个版本中随机选择k个，至少有一个通过的概率
    pass@k = 1 - C(n-c, k) / C(n, k)
    其中n是总版本数，c是通过的版本数
    """
    if c == 0 or k <= 0 or n <= 0:
        return 0.0
    
    if k >= n:  # 选择的版本数大于等于总版本数
        return 1.0 if c > 0 else 0.0
    
    # 使用组合数学计算：pass@k = 1 - C(n-c, k) / C(n, k)
    # 即：1 - (从失败版本中选k个的方案数) / (从所有版本中选k个的方案数)
    try:
        if n - c < k:  # 失败版本数小于k，无法从失败版本中选出k个
            return 1.0
        
        prob = 1.0 - math.comb(n - c, k) / math.comb(n, k)
        return max(0.0, min(1.0, prob))  # 确保结果在[0,1]范围内
    except (ValueError, ZeroDivisionError):
        return 0.0

# --- ChatRepair Integration ---
class PatchType(Enum):
    """补丁类型枚举"""
    REPLACE = "replace"
    INSERT = "insert"
    DELETE = "delete"

class FeedbackType(Enum):
    """反馈类型枚举"""
    FAIL_NEW_TEST = 0  # 新测试失败
    FAIL_ORIGINAL_TEST = 1  # 原始测试失败
    COMPILATION_ERROR = 2  # 编译错误
    GENERAL_ERROR = 3  # 一般错误
    TIMEOUT = 4  # 超时
    PLAUSIBLE = 5  # 可行补丁

@dataclass
class BugInfo:
    """Bug信息数据类 - 适配 C++ 代码修复"""
    file_path: str
    buggy_code: str
    patch_type: PatchType
    original_buggy_code: str = ""
    test_input: str = ""
    test_output: str = ""
    expected_output: str = ""
    test_error: str = ""
    problem_description: str = ""

class ChatRepairAdapter:
    """ChatRepair适配器类 - 适配C++代码修复"""
    
    def __init__(self, model_name: str = REPAIR_MODEL_NAME, temperature: float = REPAIR_TEMPERATURE):
        self.model_name = model_name
        self.base_temperature = temperature
        
        # Template constants - Adapted for C++ (English version)
        self.INFILL = ">>>[INFILL]<<<\n"
        self.TEMPLATES = {
            'apr_tool': "You are an automated program repair tool specialized in fixing C++ code.\n",
            'example_start': "Here is an example of a repair task:\n",
            'single_line': "The following C++ code contains a removed buggy line:\n",
            'single_hunk': "The following C++ code contains a removed buggy code block:\n",
            'single_function': "The following C++ code contains an error:\n",
            'single_line_2': "This is the original buggy line removed at the infill location:\n",
            'single_hunk_2': "This is the original buggy code block removed at the infill location:\n",
            'failure_test': "The code fails on this test input:\n",
            'failure_test_output': "Produces incorrect output:\n",
            'failure_test_expected': "Expected output:\n",
            'failure_test_error': "Produces the following error:\n",
            'single_line_final': "\nPlease provide problem analysis, expected behavior of the correct fix, and provide the correct code line at the infill location in C++ Markdown code block format.\n",
            'single_hunk_final': "\nPlease provide problem analysis, expected behavior of the correct fix, and provide the correct code block at the infill location in C++ Markdown code block format.\n",
            'single_function_final': "\nPlease provide problem analysis, expected behavior of the correct fix, and provide the complete correct code in C++ Markdown code block format.\n",
            'feedback_0': "The previous repair attempt failed. Please analyze the error and provide a corrected version of the complete C++ code.",
            'feedback_1': "The code still fails the test case with incorrect output.",
            'feedback_2': "The code has compilation errors that need to be fixed:",
            'feedback_3': "The code has compilation errors that prevent it from running.",
            'feedback_4': "The program exceeded the time limit during execution.",
            'repair_instruction': "\n\nPlease provide the complete corrected C++ code in the following format:\n```cpp\n[Your complete corrected C++ code here]\n```\n\nMake sure to:\n1. Fix the specific error mentioned above\n2. Include all necessary headers and declarations\n3. Provide the complete working C++ program"
        }
        
        # C++ Example template - using string replacement to avoid format issues
        self.EXAMPLE_TEMPLATE = """
<Example Start>
Example buggy C++ code and request:
The following C++ code contains a removed buggy line:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    INFILL_PLACEHOLDER
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}
```
This is the original buggy line removed at the INFILL_PLACEHOLDER location:
sort(a.begin(), a.end(), greater<int>());
The code fails on this test input:
3
1 2 3
Produces incorrect output:
3 2 1
Expected output:
1 2 3
Please provide problem analysis, expected behavior of the correct fix, and provide the correct code line at the infill location in C++ Markdown code block format.

Example response:

1. Problem analysis:
The issue is with using `greater<int>()` as the comparator, which causes the array to be sorted in descending order, while the problem requires ascending order sorting.

2. Expected behavior of the correct fix:
The correct fix should use the default ascending sort, or explicitly use the `less<int>()` comparator.

3. Correct code at the infill location:

```cpp
sort(a.begin(), a.end());
```
<Example End>
""".replace("INFILL_PLACEHOLDER", self.INFILL)

    def extract_patch_from_response(self, response_text: str) -> str:
        """从LLM响应中提取代码补丁"""
        if response_text.count('```cpp') > 1:
            response_text = '\n'.join(response_text.split('\n')[1:])
        
        # 首先尝试匹配cpp代码块
        pattern = r"```cpp(.*)```"
        match = re.search(pattern, response_text, re.DOTALL)
        
        if match is None:
            # 如果没有cpp标签，尝试匹配c++代码块
            pattern = r"```c\+\+(.*)```"
            match = re.search(pattern, response_text, re.DOTALL)
        
        if match is None:
            # 如果没有特定标签，尝试匹配普通代码块
            pattern = r"```(.*)```"
            match = re.search(pattern, response_text, re.DOTALL)
        
        if match is None:
            print(f"  [Warning] Unable to extract code patch from response")
            return ""
        
        return match.group(1).strip()

    def construct_initial_prompt(self, bug_info: BugInfo) -> str:
        """构建初始修复提示"""
        prompt = self.TEMPLATES['apr_tool']
        
        # 添加问题描述（带长度限制）
        if bug_info.problem_description:
            # 限制问题描述长度，避免prompt过长
            max_desc_length = 20000  # 20KB for problem description
            if len(bug_info.problem_description) > max_desc_length:
                truncated_desc = bug_info.problem_description[:max_desc_length] + "\n\n[Description truncated...]"
                prompt += f"Problem description:\n{truncated_desc}\n\n"
                print(f"  [ChatRepair] Problem description truncated ({len(bug_info.problem_description)} -> {max_desc_length} chars)")
            else:
                prompt += f"Problem description:\n{bug_info.problem_description}\n\n"
        
        prompt += self.TEMPLATES['example_start']
        prompt += self.EXAMPLE_TEMPLATE
        
        # 根据补丁类型构建不同的提示
        if bug_info.patch_type == PatchType.REPLACE:
            # 检查是否是单行还是多行
            if bug_info.original_buggy_code and '\n' not in bug_info.original_buggy_code.strip():
                # 单行修复
                prompt += self.TEMPLATES['single_line']
                prompt += f"```cpp\n{bug_info.buggy_code}\n```\n"
                prompt += self.TEMPLATES['single_line_2']
                prompt += f"{bug_info.original_buggy_code}\n"
                final_template = self.TEMPLATES['single_line_final']
            else:
                # 多行修复
                prompt += self.TEMPLATES['single_hunk']
                prompt += f"```cpp\n{bug_info.buggy_code}\n```\n"
                prompt += self.TEMPLATES['single_hunk_2']
                prompt += f"{bug_info.original_buggy_code}\n"
                final_template = self.TEMPLATES['single_hunk_final']
        else:
            # 函数级修复
            prompt += self.TEMPLATES['single_function']
            prompt += f"```cpp\n{bug_info.buggy_code}\n```\n"
            final_template = self.TEMPLATES['single_function_final']
        
        # 添加测试失败信息（带长度限制）
        if bug_info.test_input:
            # 限制测试输入长度
            max_input_length = 8192  # 8KB for test input
            if len(bug_info.test_input) > max_input_length:
                truncated_input = bug_info.test_input[:max_input_length] + "\n\n[Input truncated...]"
                prompt += self.TEMPLATES['failure_test']
                prompt += f"```\n{truncated_input}\n```\n"
                print(f"  [ChatRepair] Test input truncated ({len(bug_info.test_input)} -> {max_input_length} chars)")
            else:
                prompt += self.TEMPLATES['failure_test']
                prompt += f"```\n{bug_info.test_input}\n```\n"
            
            if bug_info.test_output:
                # 限制测试输出长度
                max_output_length = 4096  # 4KB for test output
                if len(bug_info.test_output) > max_output_length:
                    truncated_output = bug_info.test_output[:max_output_length] + "\n\n[Output truncated...]"
                    prompt += self.TEMPLATES['failure_test_output']
                    prompt += f"```\n{truncated_output}\n```\n"
                    print(f"  [ChatRepair] Test output truncated ({len(bug_info.test_output)} -> {max_output_length} chars)")
                else:
                    prompt += self.TEMPLATES['failure_test_output']
                    prompt += f"```\n{bug_info.test_output}\n```\n"
                
            if bug_info.expected_output:
                # 限制期望输出长度
                if len(bug_info.expected_output) > max_output_length:
                    truncated_expected = bug_info.expected_output[:max_output_length] + "\n\n[Output truncated...]"
                    prompt += self.TEMPLATES['failure_test_expected']
                    prompt += f"```\n{truncated_expected}\n```\n"
                    print(f"  [ChatRepair] Expected output truncated ({len(bug_info.expected_output)} -> {max_output_length} chars)")
                else:
                    prompt += self.TEMPLATES['failure_test_expected']
                    prompt += f"```\n{bug_info.expected_output}\n```\n"
                
            if bug_info.test_error:
                # 限制错误信息长度
                max_error_length = 2048  # 2KB for error message
                if len(bug_info.test_error) > max_error_length:
                    truncated_error = bug_info.test_error[:max_error_length] + "\n\n[Error message truncated...]"
                    prompt += self.TEMPLATES['failure_test_error']
                    prompt += f"{truncated_error}\n"
                    print(f"  [ChatRepair] Error message truncated ({len(bug_info.test_error)} -> {max_error_length} chars)")
                else:
                    prompt += self.TEMPLATES['failure_test_error']
                    prompt += f"{bug_info.test_error}\n"
        
        prompt += final_template
        
        # 最终长度检查，确保不超过模型限制
        max_total_length = 120000  # 留一些余量，小于129024
        if len(prompt) > max_total_length:
            print(f"  [ChatRepair] Warning: Final prompt length {len(prompt)} exceeds limit {max_total_length}, performing additional truncation")
            # 如果还是太长，只保留关键部分：工具描述+示例+代码+简化的测试信息
            essential_parts = [
                self.TEMPLATES['apr_tool'],
                self.TEMPLATES['example_start'],
                self.EXAMPLE_TEMPLATE,
                self.TEMPLATES['single_function'],
                f"```cpp\n{bug_info.buggy_code}\n```\n",
                "Test failed, please fix the code.\n",
                final_template
            ]
            prompt = ''.join(essential_parts)
            print(f"  [ChatRepair] Using simplified prompt, length: {len(prompt)}")
        
        return prompt

    def validate_patch(self, patch: str, bug_info: BugInfo, reference_outputs: Dict[str, str], 
                      work_dir: str, test_case_dir: str) -> Tuple[bool, str, FeedbackType]:
        """验证补丁是否有效"""
        try:
            # 应用补丁到代码
            if bug_info.patch_type == PatchType.REPLACE:
                fixed_code = self._apply_replace_patch(bug_info.buggy_code, patch)
            elif bug_info.patch_type == PatchType.INSERT:
                fixed_code = self._apply_insert_patch(bug_info.buggy_code, patch)
            else:  # DELETE or 函数级修复
                fixed_code = patch
            
            # 使用现有的evaluate_fixed_code_refactored进行验证
            passed, status = evaluate_fixed_code_refactored(
                fixed_code, reference_outputs, work_dir, test_case_dir, 
                COMPILE_TIMEOUT, RUN_TIMEOUT, None
            )
            
            if passed:
                return True, status, FeedbackType.PLAUSIBLE
            else:
                # 分析失败类型
                if "Compilation Failed" in status:
                    return False, status, FeedbackType.COMPILATION_ERROR
                elif "Timeout" in status:
                    return False, status, FeedbackType.TIMEOUT
                else:
                    return False, status, FeedbackType.FAIL_ORIGINAL_TEST
                    
        except Exception as e:
            print(f"  [Error] 补丁验证失败: {e}")
            return False, str(e), FeedbackType.GENERAL_ERROR

    def _apply_replace_patch(self, buggy_code: str, patch: str) -> str:
        """应用替换类型的补丁"""
        lines = buggy_code.split('\n')
        infill_line = -1
        
        for i, line in enumerate(lines):
            if self.INFILL.strip() in line:
                infill_line = i
                break
        
        if infill_line >= 0:
            # 保持原有的缩进
            original_line = lines[infill_line]
            indent = len(original_line) - len(original_line.lstrip())
            indented_patch = '\n'.join([' ' * indent + line if line.strip() else line for line in patch.split('\n')])
            lines[infill_line] = indented_patch
        
        return '\n'.join(lines)

    def _apply_insert_patch(self, buggy_code: str, patch: str) -> str:
        """应用插入类型的补丁"""
        lines = buggy_code.split('\n')
        infill_line = -1
        
        for i, line in enumerate(lines):
            if self.INFILL.strip() in line:
                infill_line = i
                break
        
        if infill_line >= 0:
            # 保持原有的缩进
            original_line = lines[infill_line]
            indent = len(original_line) - len(original_line.lstrip())
            indented_patch = '\n'.join([' ' * indent + line if line.strip() else line for line in patch.split('\n')])
            lines.insert(infill_line, indented_patch)
            lines.pop(infill_line + 1)  # 移除INFILL行
        
        return '\n'.join(lines)

    def load_reusable_first_round(self, reuse_source: str, submission_id: str, version_num: int, strategies_to_check: List[str]) -> Optional[Dict[str, Any]]:
        """
        从基线结果中加载可复用的成功结果。
        只在指定的策略列表中查找并返回成功的记录。
        """
        try:
            # 获取脚本目录作为基准路径
            script_dir = os.path.dirname(os.path.abspath(__file__))
            
            # 尝试多种文件名格式
            possible_files = [
                os.path.join(script_dir, f"result_chatrepair_{reuse_source}.json"),
                os.path.join(script_dir, f"result_{reuse_source}.json"),
                os.path.join(script_dir, f"result_{reuse_source.replace('-', '_')}.json"),
                os.path.join(script_dir, f"result_{reuse_source.replace('_', '-')}.json"),
            ]
            if reuse_source.startswith("coder7b-"):
                modified_source = reuse_source.replace("coder7b-", "coder7b_", 1)
                possible_files.append(os.path.join(script_dir, f"result_{modified_source}.json"))
            
            reuse_file = next((f for f in possible_files if os.path.exists(f)), None)
            
            if not reuse_file:
                if version_num == 1:
                    # 仅在第一次检查时打印信息，避免刷屏
                    print(f"    [Reuse] Source file not found for '{reuse_source}'. Will generate all versions from scratch.")
                return None
            
            with open(reuse_file, 'r', encoding='utf-8') as f:
                reuse_data = json.load(f)
            
            # 查找对应的提交
            for problem_id, problem_data in reuse_data.items():
                if "results" not in problem_data:
                    continue
                    
                for submission in problem_data["results"]:
                    if submission.get("submission_id") == submission_id:
                        eval_data = submission.get("evaluation", {})
                        
                        # 只在指定的策略列表中检查
                        for strategy_to_check in strategies_to_check:
                            if strategy_to_check in eval_data:
                                strategy_data = eval_data[strategy_to_check]
                                
                                # 检查详细的版本列表 (新格式)
                                version_list = strategy_data.get("version_results", []) or strategy_data.get("versions", [])
                                if version_list:
                                    target_v_data = next((v for v in version_list if v.get("version") == version_num or v.get("version_num") == version_num), None)
                                    if target_v_data and target_v_data.get("passed", False):
                                        print(f"    [Reuse] v{version_num}: Found PASSED status from '{strategy_to_check}'")
                                        return {
                                            "success": True, "patches": ["REUSED_SUCCESS"], "reused": True,
                                            "original_version": version_num, "original_strategy": strategy_to_check,
                                            "status": target_v_data.get('status', 'Reused successful result')
                                        }
                                
                                # 兼容旧格式：检查顶级的 "passed" 标志
                                if not version_list and strategy_data.get("passed", False):
                                    successful_version = strategy_data.get("successful_version", 1)
                                    if version_num == successful_version:
                                        print(f"    [Reuse] v{version_num}: Found legacy PASSED status from '{strategy_to_check}'")
                                        return {
                                            "success": True, "patches": ["REUSED_SUCCESS"], "reused": True,
                                            "original_version": successful_version, "original_strategy": strategy_to_check,
                                            "status": strategy_data.get('status', 'Reused legacy successful result')
                                        }
                        
                        # 如果检查完该提交的所有指定策略都没有找到成功的版本，则判定为无法复用，返回None
                        return None
            
            # 如果遍历完文件都找不到对应的 submission_id
            return None
            
        except Exception as e:
            print(f"    [Reuse] Error loading reusable result for v{version_num}: {e}")
            import traceback
            traceback.print_exc()
            return None

    def _load_version_code(self, submission_id: str, strategy: str, version_num: int, reuse_source: str, artifact_dir: str) -> str:
        """加载特定版本的代码文件"""
        try:
            # 构建可能的代码文件路径
            possible_filenames = [
                f"{submission_id}.fixed_code_{strategy}_v{version_num}_{reuse_source}.cpp",
                f"{submission_id}_fixed_code_{strategy}_v{version_num}_{reuse_source}.cpp",
                f"{submission_id}.fixed_code_{strategy}_v{version_num}.cpp",
                f"{submission_id}_fixed_code_{strategy}_v{version_num}.cpp",
            ]
            
            # 特殊处理：转换格式
            if reuse_source and reuse_source.startswith("coder7b-"):
                modified_source = reuse_source.replace("coder7b-", "coder7b_", 1)
                possible_filenames.extend([
                    f"{submission_id}.fixed_code_{strategy}_v{version_num}_{modified_source}.cpp",
                    f"{submission_id}_fixed_code_{strategy}_v{version_num}_{modified_source}.cpp",
                ])

            # 尝试找到存在的文件并读取
            for filename in possible_filenames:
                candidate_file = os.path.join(artifact_dir, filename)
                if os.path.exists(candidate_file):
                    for encoding in ['utf-8', 'latin-1', 'cp1252', 'ascii']:
                        try:
                            with open(candidate_file, 'r', encoding=encoding) as f:
                                content = f.read()
                            if content.strip():
                                return content
                        except (UnicodeDecodeError, UnicodeError):
                            continue
            
            return None
            
        except Exception as e:
            print(f"    [Reuse] Error loading code for v{version_num} ({strategy}): {e}")
            return None

    def construct_feedback(self, is_success: bool, message: str, feedback_type: FeedbackType) -> str:
        """构建反馈消息"""
        if is_success:
            return ""
        
        # 构建具体的错误反馈
        if feedback_type == FeedbackType.COMPILATION_ERROR:
            feedback = f"{self.TEMPLATES['feedback_2']}\n\n{message}\n\n"
            feedback += "Please fix these compilation errors and provide the complete corrected C++ code."
        elif feedback_type == FeedbackType.TIMEOUT:
            feedback = f"{self.TEMPLATES['feedback_4']}\n\n"
            feedback += "Please optimize the algorithm to reduce time complexity and provide the complete corrected C++ code."
        elif feedback_type == FeedbackType.FAIL_ORIGINAL_TEST:
            feedback = f"{self.TEMPLATES['feedback_1']}\n\nError details:\n{message}\n\n"
            feedback += "Please analyze the logic error and provide the complete corrected C++ code."
        elif feedback_type == FeedbackType.GENERAL_ERROR:
            feedback = f"{self.TEMPLATES['feedback_3']}\n\nError details:\n{message}\n\n"
            feedback += "Please fix these errors and provide the complete corrected C++ code."
        else:
            feedback = f"{self.TEMPLATES['feedback_0']}\n\nError: {message}\n\n"
            feedback += "Please fix this issue and provide the complete corrected C++ code."
        
        # 添加统一的修复指令
        feedback += self.TEMPLATES['repair_instruction']
        
        return feedback

    def repair_bug(self, bug_info: BugInfo, reference_outputs: Dict[str, str], 
                   work_dir: str, test_case_dir: str, version_num: int = 1, 
                   reuse_source: str = None, baseline_strategies: Optional[List[str]] = None) -> Dict[str, Any]:
        """
        修复单个bug的主要方法。
        首先尝试从基线结果中复用成功的版本，如果不成功，则生成新的补丁。
        """
        # 使用创建时传入的温度，不再重复调整
        current_temperature = self.base_temperature
        
        # 步骤 1: 尝试从基线复用成功结果
        if reuse_source and baseline_strategies:
            # 从文件路径中提取submission_id
            path_parts = bug_info.file_path.split('/')
            if len(path_parts) >= 2 and path_parts[-2].isdigit():
                submission_id = path_parts[-2]
            else:
                filename = os.path.basename(bug_info.file_path)
                submission_id = re.search(r'(\d+)', filename).group(1) if re.search(r'(\d+)', filename) else filename.split('_')[1]

            reused_result = self.load_reusable_first_round(reuse_source, submission_id, version_num, baseline_strategies)
            
            if reused_result:
                # 如果找到了成功的记录，直接返回
                return reused_result
            else:
                # 未找到可复用的成功记录，将继续生成
                print(f"    [Generate] v{version_num}: No passed result found in baseline ({'/'.join(baseline_strategies)}), will generate from scratch.")
        
        # 步骤 2: 生成新的补丁（仅在无法复用成功结果时执行）
        initial_prompt = self.construct_initial_prompt(bug_info)
        
        current_tries = 0
        plausible_patches = []
        conversation_history = []
        
        while current_tries < MAX_CHATREPAIR_TRIES and len(plausible_patches) == 0:
            context = []
            current_conv_length = 0
            prompt = initial_prompt
            feedback_list = []
            
            print(f"    [ChatRepair] Entering conversation loop, current_conv_length={current_conv_length}, max={MAX_CHATREPAIR_CONVERSATION_LENGTH}")
            while current_conv_length < MAX_CHATREPAIR_CONVERSATION_LENGTH:
                try:
                    print(f"    [ChatRepair] Starting round {current_conv_length + 1}/{MAX_CHATREPAIR_CONVERSATION_LENGTH}")
                    
                    prompt_history = context + [{'role': 'user', 'content': prompt}]
                    
                    raw_response = llm.call_llm(
                        prompt_history=prompt_history,
                        model_name=self.model_name,
                        temperature=current_temperature,
                    )
                    
                    if not raw_response:
                        print(f"    [ChatRepair] Round {current_conv_length + 1} failed: LLM returned empty response")
                        break
                    
                    context.append({'role': 'user', 'content': prompt})
                    context.append({'role': 'assistant', 'content': raw_response})
                    
                    patch = self.extract_patch_from_response(raw_response)
                    if not patch:
                        print(f"    [ChatRepair] Round {current_conv_length + 1} failed: Could not extract patch from response")
                        break
                    
                    print(f"    [ChatRepair] Round {current_conv_length + 1}: Extracted patch, testing...")
                    
                    is_valid, validation_msg, feedback_type = self.validate_patch(
                        patch, bug_info, reference_outputs, work_dir, test_case_dir
                    )
                    feedback_list.append(feedback_type.value)
                    
                    if is_valid:
                        print(f"    [ChatRepair] Round {current_conv_length + 1}: Patch passed all tests!")
                        plausible_patches.append(patch)
                        break
                    
                    print(f"    [ChatRepair] Round {current_conv_length + 1}: Patch failed - {validation_msg}")
                    
                    feedback = self.construct_feedback(is_valid, validation_msg, feedback_type)
                    prompt = feedback
                    
                    current_conv_length += 1
                    
                except Exception as e:
                    print(f"    [ChatRepair] Round {current_conv_length + 1} failed with exception: {e}")
                    break
            
            conversation_history.append({
                'try': current_tries + 1,
                'context': context,
                'feedback_list': feedback_list
            })
            
            current_tries += 1
        
        # 返回修复结果
        return {
            'success': len(plausible_patches) > 0,
            'patches': plausible_patches,
            'total_tries': current_tries,
            'conversation_history': conversation_history
        }

# --- File Locking Helper ---
class FileLocker:
    """Context manager for file locking to prevent concurrent access to result.json"""
    
    def __init__(self, file_path: str, mode: str = 'r+', timeout: int = 30):
        self.file_path = file_path
        self.mode = mode
        self.timeout = timeout
        self.file_handle = None
        self.lock_acquired = False
    
    def __enter__(self):
        """Acquire file lock with timeout"""
        try:
            # Create file if it doesn't exist (for write operations)
            if 'w' in self.mode or 'a' in self.mode:
                os.makedirs(os.path.dirname(self.file_path) if os.path.dirname(self.file_path) else '.', exist_ok=True)
                if not os.path.exists(self.file_path):
                    with open(self.file_path, 'w') as f:
                        json.dump({}, f)
            
            # Open file with appropriate mode
            self.file_handle = open(self.file_path, self.mode, encoding='utf-8')
            
            # Try to acquire lock with timeout
            start_time = time.time()
            while time.time() - start_time < self.timeout:
                try:
                    fcntl.flock(self.file_handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
                    self.lock_acquired = True
                    print(f"[Lock] Acquired lock for {self.file_path}")
                    return self.file_handle
                except (IOError, OSError):
                    # Lock not available, wait and retry
                    time.sleep(0.1)
                    continue
            
            # Timeout occurred
            raise TimeoutError(f"Could not acquire lock for {self.file_path} within {self.timeout} seconds")
            
        except Exception as e:
            if self.file_handle:
                self.file_handle.close()
                self.file_handle = None
            raise e
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """Release file lock"""
        if self.file_handle:
            try:
                if self.lock_acquired:
                    fcntl.flock(self.file_handle.fileno(), fcntl.LOCK_UN)
                    print(f"[Lock] Released lock for {self.file_path}")
                self.file_handle.close()
                self.file_handle = None
                self.lock_acquired = False
            except Exception as e:
                print(f"[Warning] Error releasing lock for {self.file_path}: {e}", file=sys.stderr)

def load_results_with_lock(json_path: str) -> dict:
    """Load results from JSON file with file locking"""
    if not os.path.exists(json_path):
        return {}
    
    try:
        with FileLocker(json_path, 'r') as f:
            if os.path.getsize(json_path) > 0:
                f.seek(0)
                results = json.load(f)
                print(f"[Info] Loaded data from {json_path}")
                return results
            else:
                print(f"[Error] {json_path} is empty.", file=sys.stderr)
                return {}
    except json.JSONDecodeError:
        print(f"[Error] Failed to decode JSON from {json_path}.", file=sys.stderr)
        return {}
    except TimeoutError as e:
        print(f"[Error] Lock timeout when loading {json_path}: {e}", file=sys.stderr)
        return {}
    except Exception as e:
        print(f"[Error] Failed to load or parse {json_path}: {e}", file=sys.stderr)
        return {}

def save_results_with_lock(json_path: str, results_data: dict) -> bool:
    """Save results to JSON file with file locking and retry mechanism"""
    max_retries = 5
    base_wait_time = 2
    
    for attempt in range(max_retries):
        try:
            with FileLocker(json_path, 'w') as f:
                f.seek(0)
                f.truncate()
                json.dump(results_data, f, indent=2, ensure_ascii=False)
                f.flush()
                os.fsync(f.fileno())  # Ensure data is written to disk
                print(f"[Success] Saved updated evaluation results to {json_path}")
                return True
        except TimeoutError as e:
            wait_time = base_wait_time * (2 ** attempt)  # 指数退避
            print(f"[Warning] Lock timeout on attempt {attempt + 1}/{max_retries}: {e}")
            if attempt < max_retries - 1:
                print(f"[Retry] Waiting {wait_time} seconds before retry...")
                time.sleep(wait_time)
                continue
            else:
                print(f"[Error] Failed to save after {max_retries} attempts", file=sys.stderr)
                return False
        except Exception as e:
            wait_time = base_wait_time * (2 ** attempt)
            print(f"[Warning] Save error on attempt {attempt + 1}/{max_retries}: {e}")
            if attempt < max_retries - 1:
                print(f"[Retry] Waiting {wait_time} seconds before retry...")
                time.sleep(wait_time)
                continue
            else:
                print(f"[Error] Failed to save after {max_retries} attempts: {e}", file=sys.stderr)
                return False
    
    return False

# --- Helper Functions ---

def perform_reduction_for_reuse(failed_code: str, submission_id: str, problem_id_input: str, artifact_dir: str, reducer_model: str = "qwen-plus") -> Optional[str]:
    """使用现有的reduction函数为复用的失败代码生成新的reduced input，支持自定义reducer文件名"""
    try:
        print(f"    [Reduce] Using existing reduction pipeline for failed code from submission {submission_id}")
        
        # 解析problem_id来获取目录信息
        from reduce import _parse_problem_id
        parsed_ids = _parse_problem_id(problem_id_input)
        if not parsed_ids:
            print(f"    [Reduce] Invalid problem ID format: {problem_id_input}")
            return None
        contest_id, problem_letter = parsed_ids
        problem_dir = f"{contest_id}{problem_letter.lower()}"
        
        # 获取脚本目录
        script_dir = os.path.dirname(os.path.abspath(__file__))
        
        # 查找reducer文件 - 优先使用模型特定的reducer
        reducer_file_candidates = [
            os.path.join(script_dir, f"{problem_dir}/reducer_{reducer_model}.py"),
            os.path.join(script_dir, f"{problem_dir}/reducer.py")
        ]
        
        reducer_file = None
        for candidate in reducer_file_candidates:
            if os.path.exists(candidate):
                reducer_file = candidate
                print(f"    [Reduce] Found reducer file: {reducer_file}")
                break
        
        if not reducer_file:
            print(f"    [Reduce] No reducer file found. Tried: {reducer_file_candidates}")
            return None
        
        # 动态导入reducer模块
        import importlib.util
        spec = importlib.util.spec_from_file_location("temp_reducer", reducer_file)
        if not spec or not spec.loader:
            print(f"    [Reduce] Failed to create module spec for {reducer_file}")
            return None
        
        reducer_module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(reducer_module)
        
        if not hasattr(reducer_module, 'reduce_input'):
            print(f"    [Reduce] Reducer module {reducer_file} does not have 'reduce_input' function")
            return None
        
        reduce_input_func = reducer_module.reduce_input
        print(f"    [Reduce] Successfully loaded reducer function from {reducer_file}")
        
        # 创建临时工作目录
        temp_work_dir = tempfile.mkdtemp(prefix=f"reduce_reuse_{submission_id}_")
        
        try:
            # 准备失败代码和AC代码
            wa_code_path = os.path.join(temp_work_dir, "wa.cpp")
            ac_code_path = os.path.join(temp_work_dir, "ac.cpp")
            
            # 保存失败代码
            with open(wa_code_path, 'w', encoding='utf-8') as f:
                f.write(failed_code)
            
            # 复制AC代码
            original_ac_path = os.path.join(script_dir, problem_dir, "ac.cpp")
            if os.path.exists(original_ac_path):
                shutil.copy2(original_ac_path, ac_code_path)
            else:
                print(f"    [Reduce] Warning: AC code not found at {original_ac_path}")
                return None
            
            # 编译AC和WA代码
            from reduce import compile_program
            os.chdir(temp_work_dir)  # 切换到临时目录
            
            if not compile_program("ac.cpp", "ac", temp_work_dir):
                print(f"    [Reduce] Failed to compile AC code")
                return None
            
            if not compile_program("wa.cpp", "wa", temp_work_dir):
                print(f"    [Reduce] Failed to compile WA code")
                return None
            
            # 获取原始输入 - 使用第一个找到的输入文件
            import glob
            test_case_pattern = os.path.join(BASE_TESTCASE_PATH, contest_id, problem_letter.upper(), "in", "*")
            test_cases = glob.glob(test_case_pattern)
            
            if not test_cases:
                print(f"    [Reduce] No test cases found at {test_case_pattern}")
                return None
            
            # 使用第一个测试用例
            original_input_path = test_cases[0]
            with open(original_input_path, 'r', encoding='utf-8') as f:
                original_input = f.read()
            
            # 保存原始输入到工作目录
            input_path = os.path.join(temp_work_dir, "input.txt")
            with open(input_path, 'w', encoding='utf-8') as f:
                f.write(original_input)
            
            # 调用reducer函数
            reduced_output_path = os.path.join(temp_work_dir, "reduced_input.txt")
            
            print(f"    [Reduce] Running reduce_input function with {REDUCE_TIMEOUT}s timeout...")
            
            # 使用subprocess + timeout实现跨线程超时控制
            import subprocess
            import sys
            
            # 创建一个临时Python脚本来执行reduction
            script_dir = os.path.dirname(os.path.abspath(__file__))
            reduce_script_content = f'''
import sys
import os
sys.path.insert(0, r"{script_dir}")

# 动态导入reducer模块
import importlib.util
spec = importlib.util.spec_from_file_location("temp_reducer", r"{reducer_file}")
reducer_module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(reducer_module)

# 调用reduce_input函数
try:
    reducer_module.reduce_input(r"{input_path}", r"{reduced_output_path}")
    print("REDUCE_SUCCESS")
except Exception as e:
    print(f"REDUCE_ERROR: {{e}}")
    sys.exit(1)
'''
            
            reduce_script_path = os.path.join(temp_work_dir, "run_reduce.py")
            with open(reduce_script_path, 'w', encoding='utf-8') as f:
                f.write(reduce_script_content)
            
            try:
                # 使用subprocess运行reduction，并设置timeout
                result = subprocess.run(
                    [sys.executable, reduce_script_path],
                    cwd=temp_work_dir,
                    capture_output=True,
                    text=True,
                    timeout=REDUCE_TIMEOUT
                )
                
                if result.returncode == 0 and "REDUCE_SUCCESS" in result.stdout:
                    print(f"    [Reduce] Reduction completed successfully")
                else:
                    error_msg = result.stderr or result.stdout or "Unknown error"
                    print(f"    [Reduce] Reduction failed: {error_msg}")
                    return None
                    
            except subprocess.TimeoutExpired:
                print(f"    [Reduce] Reduction timed out after {REDUCE_TIMEOUT} seconds")
                return None
            except Exception as e:
                print(f"    [Reduce] Reduction failed with error: {e}")
                return None
            
            # 读取reduced结果
            if os.path.exists(reduced_output_path):
                with open(reduced_output_path, 'r', encoding='utf-8') as f:
                    reduced_content = f.read()
                
                if reduced_content.strip():
                    print(f"    [Reduce] Successfully generated reduced input: {len(reduced_content)} chars (was {len(original_input)} chars)")
                    return reduced_content
                else:
                    print(f"    [Reduce] Reduced output is empty")
                    return None
            else:
                print(f"    [Reduce] Reduced output file not created: {reduced_output_path}")
                return None
            
        finally:
            # 清理临时工作目录
            if os.path.exists(temp_work_dir):
                try:
                    shutil.rmtree(temp_work_dir)
                    print(f"    [Reduce] Cleaned up temporary work directory: {temp_work_dir}")
                except Exception as e:
                    print(f"    [Reduce] Warning: Failed to clean up temporary work directory: {e}")
                    
    except Exception as e:
        print(f"    [Reduce] Error in reduction setup: {e}")
        import traceback
        traceback.print_exc()
        return None



def generate_outputs_for_reduced_input(reduced_input: str, failed_code: str, work_dir: str, ac_executable: str) -> Tuple[Optional[str], Optional[str]]:
    """为新的reduced input生成对应的WA输出和AC输出"""
    try:
        # 创建临时文件
        reduced_input_path = os.path.join(work_dir, "reduced_input_temp.txt")
        failed_code_path = os.path.join(work_dir, "failed_code_temp.cpp")
        failed_exe_path = os.path.join(work_dir, "failed_exe_temp")
        
        # 写入文件
        with open(reduced_input_path, 'w', encoding='utf-8') as f:
            f.write(reduced_input)
        with open(failed_code_path, 'w', encoding='utf-8') as f:
            f.write(failed_code)
        
        # 编译失败代码
        if not compile_program("failed_code_temp.cpp", "failed_exe_temp", work_dir):
            print(f"    [Reduce] Failed to compile failed code for output generation")
            return None, None
        
        # 运行失败代码获取WA输出
        wa_stdout, wa_error = run_program(failed_exe_path, reduced_input_path, RUN_TIMEOUT)
        if wa_error:
            print(f"    [Reduce] Failed code produced error on reduced input: {wa_error}")
            # 仍然可以继续，错误输出也是有用的信息
        
        # 运行AC代码获取预期输出（使用传入的AC可执行文件）
        ac_stdout, ac_error = run_program(ac_executable, reduced_input_path, RUN_TIMEOUT)
        if ac_error:
            print(f"    [Reduce] AC code failed on reduced input: {ac_error}")
            return wa_stdout, None
        
        return wa_stdout, ac_stdout
        
    except Exception as e:
        print(f"    [Reduce] Error generating outputs for reduced input: {e}")
        return None, None

def run_program(executable_path: str, input_path: str, timeout: int) -> Tuple[Optional[str], Optional[str]]:
    """Runs the compiled program with given input, capturing stdout.
    Returns (stdout, error_message). error_message is None on success.
    """
    try:
        with open(input_path, 'r', encoding='utf-8') as f_in:
            input_content = f_in.read()

        result = subprocess.run(
            [executable_path],
            input=input_content,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False # Don't raise exception on non-zero exit code, check manually
        )

        if result.returncode != 0:
            err_msg = f"Runtime Error (Exit Code: {result.returncode})"
            # Include stderr if available
            if result.stderr:
                err_msg += f"\\nStderr:\\n{result.stderr.strip()}"
            return None, err_msg
        # Check for stderr even on success, could indicate warnings/issues
        # if result.stderr:
        #     print(f"  [Warning] Runtime produced stderr (but exit code 0):\\n{result.stderr.strip()}", file=sys.stderr)

        return result.stdout, None # Success

    except subprocess.TimeoutExpired:
        return None, "Timeout Error"
    except FileNotFoundError:
        return None, f"Executable not found at {executable_path}"
    except Exception as e:
        return None, f"Unexpected error during execution: {e}"

def get_reference_outputs(ac_executable_path: str, test_case_dir: str, test_case_names: List[str]) -> Tuple[Optional[Dict[str, str]], Optional[str]]:
    """Runs the AC executable on all specified test cases and returns a dict of {case_name: stdout}.
       Returns (output_dict, error_message). error_message is None if all runs succeed.
    """
    reference_outputs = {}
    print(f"  Generating reference outputs using {ac_executable_path}...")
    for case_name in test_case_names:
        input_path = os.path.join(test_case_dir, case_name)
        # print(f"    Running AC on: {case_name}") # Reduce verbosity
        stdout, error = run_program(ac_executable_path, input_path, RUN_TIMEOUT)
        if error:
            err_msg = f"Failed to get reference output for {case_name}: {error}"
            print(f"    [Error] {err_msg}", file=sys.stderr)
            return None, err_msg # Fatal error if AC fails/times out
        reference_outputs[case_name] = stdout
    print(f"  Successfully generated reference outputs for {len(test_case_names)} cases.")
    return reference_outputs, None

# --- Removed unused evaluate_fixed_code function ---
def get_code_hash(code: str) -> str:
    """Generate a hash for the given code to use as cache key"""
    return hashlib.sha256(code.encode('utf-8')).hexdigest()[:16]

def load_persistent_cache(cache_file: str) -> Dict:
    """Load evaluation cache from file"""
    if os.path.exists(cache_file):
        try:
            with open(cache_file, 'r', encoding='utf-8') as f:
                return json.load(f)
        except Exception as e:
            print(f"  [Warning] Failed to load cache from {cache_file}: {e}", file=sys.stderr)
    return {}

def save_persistent_cache(cache_file: str, cache_data: Dict):
    """Save evaluation cache to file"""
    try:
        # Ensure parent directory exists
        cache_dir = os.path.dirname(cache_file)
        if cache_dir:
            os.makedirs(cache_dir, exist_ok=True)
        
        with open(cache_file, 'w', encoding='utf-8') as f:
            json.dump(cache_data, f, indent=2)
    except Exception as e:
        print(f"  [Warning] Failed to save cache to {cache_file}: {e}", file=sys.stderr)

def evaluate_fixed_code_refactored(
    fixed_code_str: str,
    reference_outputs: Dict[str, str],
    work_dir: str,
    test_case_dir: str, # Added parameter
    compile_timeout: int,
    run_timeout: int,
    evaluation_cache: Optional[Dict] = None  # Added cache parameter
) -> Tuple[bool, str]:
    """
    Compiles the fixed code, runs it against all test cases, compares with reference outputs.
    Returns (passed_all, status_message).
    Now supports caching to avoid re-testing identical code.
    """
    # Check cache first if provided
    if evaluation_cache is not None:
        code_hash = get_code_hash(fixed_code_str)
        if code_hash in evaluation_cache:
            cached_result = evaluation_cache[code_hash]
            # Cache hit message now handled by caller
            return cached_result["passed"], cached_result["status"]
    fixed_src_path = os.path.join(work_dir, "fixed.cpp")
    fixed_exe_path = os.path.join(work_dir, "fixed")

    # 1. Write fixed code
    try:
        with open(fixed_src_path, "w", encoding="utf-8") as f:
            f.write(fixed_code_str)
    except IOError as e:
        return False, f"Failed to write fixed code: {e}"

    # 2. Compile fixed code
    if not compile_program("fixed.cpp", "fixed", work_dir):
        # --- Save failing code on compilation error (silently) --- 
        try:
            fail_save_path = os.path.join(work_dir, "fixed_compile_fail.cpp")
            with open(fail_save_path, "w", encoding="utf-8") as f_fail:
                f_fail.write(fixed_code_str)
            # Removed debug print and code content print
            error_message = "Compilation Failed" # Concise error message
            # --- Removed print failing code content --- 
            return False, error_message
        except Exception as save_e:
             # Fallback error message if saving fails
            error_message = f"Compilation Failed (Save Error: {save_e})"
            print(f"  [Error] {error_message}", file=sys.stderr)
            return False, error_message
        # --- End save failing code --- 

    # 3. Run on each test case and compare
    if not reference_outputs:
        return False, "Internal Error: No reference outputs provided"
    if not os.path.isdir(test_case_dir):
         return False, f"Internal Error: Invalid test case directory provided: {test_case_dir}"

    all_passed = True
    first_failure_details = ""

    # Ensure reference_outputs keys are sorted for consistent order if needed (glob might not be sorted)
    sorted_case_names = sorted(reference_outputs.keys())

    for case_base_name in sorted_case_names:
        ref_stdout = reference_outputs[case_base_name]
        input_path = os.path.join(test_case_dir, case_base_name)
        if not os.path.exists(input_path):
             print(f"  [Warning] Input case file {input_path} missing during evaluation. Skipping case.", file=sys.stderr)
             continue # Or mark as failure?

        fixed_stdout, error = run_program(fixed_exe_path, input_path, run_timeout)

        if error:
            all_passed = False
            first_failure_details = f"Failed on '{case_base_name}': {error}"
            break

        # Normalize whitespace for comparison - ignore trailing whitespace on each line
        def normalize_output(output):
            return '\n'.join(line.rstrip() for line in output.splitlines()).strip()
        
        if normalize_output(fixed_stdout) != normalize_output(ref_stdout):
            all_passed = False
            first_failure_details = f"Wrong Answer on '{case_base_name}'"
            
            # --- Add diff for the first line ---
            fixed_first_line = fixed_stdout.splitlines()[0].rstrip() if fixed_stdout.strip() else ""
            ref_first_line = ref_stdout.splitlines()[0].rstrip() if ref_stdout.strip() else ""

            if fixed_first_line != ref_first_line:
                first_failure_details += f"\\n  First line diff:\\n    Actual: '{fixed_first_line}'\\n    Expected: '{ref_first_line}'"
            # --- End add diff ---
            break

    # Determine final result
    if all_passed:
        result_passed, result_status = True, "Correct (Passed All Test Cases)"
    else:
        result_passed, result_status = False, first_failure_details
    
    # Cache the result if cache is provided
    if evaluation_cache is not None:
        code_hash = get_code_hash(fixed_code_str)
        evaluation_cache[code_hash] = {
            "passed": result_passed,
            "status": result_status,
            "timestamp": time.time()
        }
        # Only show save message in debug mode - removed to reduce noise
    
    return result_passed, result_status


# --- Removed unused functions and helpers ---

# --- Main Evaluation Logic ---
def main():
    # 全局变量声明
    global USE_TEMPERATURE_DIVERSITY, REDUCE_TIMEOUT, RESULT_JSON_PATH, REPAIR_MODEL_NAME
    
    parser = argparse.ArgumentParser(description="Evaluate ChatRepair performance using original vs reduced test cases.")
    parser.add_argument("problem_id", help="Target AtCoder problem ID (e.g., abc123a)")
    parser.add_argument("--model-tag", required=True, help="Tag for result file naming (e.g., 'qwen-coder7b' -> result_qwen-coder7b.json)")
    parser.add_argument("--reducer-model", default="qwen2.5coder-instruct", help="LLM model name for reducer generation (default: qwen2.5coder-instruct)")
    parser.add_argument("--repair-model", help="LLM model name for repair (overrides default REPAIR_MODEL_NAME)")
    parser.add_argument("--regenerate", action="store_true", 
                       help="Force regenerate all repair codes instead of loading cached versions (default: load cached)")
    parser.add_argument("--max-threads", type=int, default=DEFAULT_MAX_THREADS,
                       help=f"Maximum number of parallel threads for LLM generation (default: {DEFAULT_MAX_THREADS})")
    parser.add_argument("--no-temperature-diversity", action="store_true",
                       help="Use fixed temperature for all versions instead of varying temperature for diversity")
    parser.add_argument("--reuse-first-round", type=str, default=None,
                       help="Reuse first round results from specified model tag (e.g., 'coder7b-qwen2.5-coder-7b-instruct')")
    parser.add_argument("--reuse-strategy", choices=["first-round-only", "continue-on-failure"], default="continue-on-failure",
                       help="Strategy for reusing results: 'first-round-only' or 'continue-on-failure' (default)")
    parser.add_argument("--reduce-timeout", type=int, default=REDUCE_TIMEOUT,
                       help=f"Timeout for reduction process in seconds (default: {REDUCE_TIMEOUT})")
    args = parser.parse_args()
    target_problem_id_input = args.problem_id.strip().lower()
    max_threads = args.max_threads
    
    # 设置温度多样性配置
    USE_TEMPERATURE_DIVERSITY = not args.no_temperature_diversity
    
    # 设置reduction超时时间
    REDUCE_TIMEOUT = args.reduce_timeout

    # 结果保存到 chatrepair 专用文件中，避免与现有evaluate_repair.py冲突
    # 确保文件保存在脚本所在目录
    script_dir = os.path.dirname(os.path.abspath(__file__))
    RESULT_JSON_PATH = os.path.join(script_dir, f"result_chatrepair_{args.model_tag}.json")

    # 如果指定了 --repair-model，覆盖默认的repair模型
    if args.repair_model:
        REPAIR_MODEL_NAME = args.repair_model
        print(f"[Info] Using repair model: {REPAIR_MODEL_NAME} (overridden by --repair-model)")
    else:
        print(f"[Info] Using default repair model: {REPAIR_MODEL_NAME}")

    print(f"[Info] Using max threads: {max_threads}")

    # --- Load Reduction Data from unified reducer results file --- 
    REDUCER_RESULTS_FILE = os.path.join(script_dir, "reducer_results.json")
    
    print(f"[Info] Loading reduction results from {REDUCER_RESULTS_FILE}...")
    
    # Parse problem ID to get directory structure
    parsed_ids = _parse_problem_id(target_problem_id_input)
    if not parsed_ids:
        print(f"[Error] Invalid problem ID format: '{target_problem_id_input}'", file=sys.stderr)
        sys.exit(1)
    contest_id, problem_letter = parsed_ids
    problem_dir_name = f"{contest_id}{problem_letter.lower()}"
    
    # Load unified reducer results
    if not os.path.exists(REDUCER_RESULTS_FILE):
        print(f"[Error] Reducer results file '{REDUCER_RESULTS_FILE}' not found.")
        print(f"[Info] Please run: python3 consolidate_reducer_results.py")
        sys.exit(1)
    
    reducer_results_data = load_results_with_lock(REDUCER_RESULTS_FILE)
    if not reducer_results_data:
        print(f"[Error] Failed to load reducer results from {REDUCER_RESULTS_FILE} or file is empty.", file=sys.stderr)
        sys.exit(1)
    
    if target_problem_id_input not in reducer_results_data:
        print(f"[Error] Problem ID '{target_problem_id_input}' not found in {REDUCER_RESULTS_FILE}.")
        print(f"[Info] Available problems: {', '.join(reducer_results_data.keys())}")
        print(f"[Info] Please run: python3 consolidate_reducer_results.py {target_problem_id_input}")
        sys.exit(1)
    
    problem_data = reducer_results_data[target_problem_id_input]
    reduction_results = problem_data.get("results", [])
    
    if not reduction_results:
        print(f"[Error] No reduction results found for '{target_problem_id_input}' in {REDUCER_RESULTS_FILE}.")
        print(f"[Info] Please run: python3 consolidate_reducer_results.py {target_problem_id_input}")
        sys.exit(1)
    
    print(f"[Info] Found {len(reduction_results)} reduction results from unified file")
    
    # --- Get Problem Description ---
    # Get problem description from unified reducer results file
    problem_description = problem_data.get("problem_description", "")
    
    if not problem_description or problem_description.startswith("# Error"):
        print(f"[Warning] Problem description not found in {REDUCER_RESULTS_FILE}, trying fallback methods...")
        
        # Fallback 1: Try to find it in cache
        cache_desc_path = f".atcoder_cache/problems/{contest_id}/{contest_id}_{problem_letter.lower()}/description.md"
        if os.path.exists(cache_desc_path):
            print(f"[Info] Reading problem description from cache: {cache_desc_path}")
            try:
                with open(cache_desc_path, 'r', encoding='utf-8') as f:
                    problem_description = f.read()
            except Exception as e:
                print(f"[Warning] Failed to read cached description: {e}", file=sys.stderr)
        
        # Fallback 2: Try to load from lftbench
        if not problem_description:
            print("[Info] Problem description not found, attempting to load from lftbench...")
            try:
                import lftbench_utils
                problem_description = lftbench_utils.get_problem_description(target_problem_id_input)
                if problem_description and not problem_description.startswith("# Error"):
                    print("[Info] Successfully loaded problem description from lftbench")
                else:
                    print("[Warning] Failed to load problem description from lftbench")
                    problem_description = None
            except Exception as e:
                print(f"[Warning] Failed to load from lftbench: {e}", file=sys.stderr)
        
        if not problem_description:
            print(f"[Error] Could not obtain problem description for '{target_problem_id_input}'.")
            print(f"[Info] Please run: python3 consolidate_reducer_results.py {target_problem_id_input}")
            sys.exit(1)
    else:
        print(f"[Info] Using problem description from {REDUCER_RESULTS_FILE}")

    # --- Load/Initialize Repair Results file ---
    repair_results_data = load_results_with_lock(RESULT_JSON_PATH)
    if target_problem_id_input not in repair_results_data:
        # Initialize repair results entry with basic problem info
        repair_results_data[target_problem_id_input] = {
            "problem_description": problem_description,
            "reduction_source": REDUCER_RESULTS_FILE,  # Record that we read from unified file
            "results": []
        }
    
    wa_results = reduction_results  # Use the reduction_results we loaded earlier

    if not wa_results:
        print(f"[Info] No WA submission results found for '{target_problem_id_input}' to evaluate.", file=sys.stderr)
        sys.exit(0)

    # Use already parsed problem ID for paths
    ac_path = os.path.join(script_dir, problem_dir_name, "ac.cpp")
    # Correct test case dir path
    test_case_dir = os.path.join(BASE_TESTCASE_PATH, contest_id, problem_letter.upper(), "in") 

    if not os.path.exists(ac_path):
         print(f"[Error] AC code '{ac_path}' not found.", file=sys.stderr)
         sys.exit(1)
    if not os.path.isdir(test_case_dir):
         print(f"[Error] Test case directory '{test_case_dir}' not found.", file=sys.stderr)
         sys.exit(1)

    # --- Prepare AC Code and Reference Outputs --- 
    print("\n--- Preparing Reference AC Execution ---")
    ac_work_dir = tempfile.mkdtemp(prefix="eval_ac_")
    ac_executable_path = os.path.join(ac_work_dir, "ac_ref")
    reference_outputs: Optional[Dict[str, str]] = None
    ac_compile_success = False # Flag to track compilation
    print(f"  Compiling AC code: {ac_path} in {ac_work_dir}...")
    # Compile AC in its own temp dir to avoid CWD issues
    if not compile_program(os.path.abspath(ac_path), "ac_ref", ac_work_dir):
            print("[Error] Failed to compile reference AC code.", file=sys.stderr)
            # Don't exit immediately, but mark as failed. We might need to clean up.
            # sys.exit(1)
    else:
        ac_compile_success = True
        print(f"  Successfully compiled AC to {ac_executable_path}")

        # List test cases
        test_case_paths = glob.glob(os.path.join(test_case_dir, "*"))
        if not test_case_paths:
                print(f"[Error] No test cases found in '{test_case_dir}'.", file=sys.stderr)
                ac_compile_success = False # Mark as failed if no test cases
                # sys.exit(1)
        else:
            test_case_names = [os.path.basename(p) for p in test_case_paths]
            test_case_names.sort() # Ensure consistent order

            reference_outputs, ref_error = get_reference_outputs(ac_executable_path, test_case_dir, test_case_names)
            if ref_error:
                print(f"[Error] Failed to generate reference outputs: {ref_error}", file=sys.stderr)
                ac_compile_success = False # Mark as failed
                # sys.exit(1)

    # *** Do not clean up ac_work_dir here anymore ***
    # finally:
    #     # Clean up AC compilation directory

    # Check if AC compilation and reference output generation failed
    if not ac_compile_success or reference_outputs is None:
        print("[Error] AC compilation or reference output generation failed. Exiting.", file=sys.stderr)
        # Clean up now before exiting
        if os.path.exists(ac_work_dir):
             shutil.rmtree(ac_work_dir)
        sys.exit(1)

    # --- Iterate through WA Submissions and Evaluate Repairs --- 
    print(f"\n--- Evaluating ChatRepair for {len(wa_results)} WA Submissions --- ")

    # --- Add counters for ChatRepair strategies ---
    evaluated_submissions_count = 0


    # --- Add outer try/finally block for main loop cleanup ---
    try:
        for wa_result in wa_results:
            submission_id = str(wa_result.get("submission_id", "UNKNOWN"))
            print(f"\n-- Processing WA Submission: {submission_id} --")
            
            # --- (Removed) The high-level check for existing evaluation was here. ---
            # This check was flawed because it only looked at the final result JSON, not
            # the on-disk caches. By removing it, we now rely on the more granular
            # per-patch caching inside the evaluation loop, which allows the
            # `clear_successful_cache.py` script to function as intended.
            if args.regenerate:
                print(f"  → Regenerate mode is active. Note: this flag currently only affects this message.")
            
            wa_code_path = wa_result.get("wa_code_path")
            status_code = wa_result.get("status_code")

            # Fix wa_code_path to be absolute if it's relative
            if wa_code_path and not os.path.isabs(wa_code_path):
                wa_code_path = os.path.join(script_dir, wa_code_path)

            # Handle failed reductions by using original input as fallback
            reduction_failed = status_code != 200
            if reduction_failed:
                print(f"  Reduction failed (Status: {status_code}). Will use original input as reduced input fallback.")
            else:
                print(f"  Reduction successful (Status: {status_code}).")
            
            if not wa_code_path or not os.path.exists(wa_code_path):
                print(f"  Skipping evaluation: WA code path '{wa_code_path}' not found.", file=sys.stderr)
                # Store skip reason if not already evaluated
                if "evaluation" not in wa_result or wa_result["evaluation"] is None:
                    wa_result["evaluation"] = {"error": "Skipped (WA code path not found)"}
                continue

            # Construct artifact paths
            artifact_dir = os.path.dirname(wa_code_path)
            original_input_path = os.path.join(artifact_dir, "original_input.txt")
            reduced_input_path = os.path.join(artifact_dir, "reduced_input.txt")

            if not os.path.exists(original_input_path):
                 print(f"  Skipping evaluation: Original input '{original_input_path}' not found.", file=sys.stderr)
                 # Store skip reason if not already evaluated
                 if "evaluation" not in wa_result or wa_result["evaluation"] is None:
                     wa_result["evaluation"] = {"error": f"Skipped (Original input missing)"}
                 continue
            # --- Read necessary files FIRST ---
            try:
                with open(wa_code_path, 'r', encoding='utf-8') as f: wa_code = f.read()
                with open(original_input_path, 'r', encoding='utf-8') as f: original_input = f.read()
                
                # Handle reduced input: use original as fallback if reduction failed or file missing
                if reduction_failed or not os.path.exists(reduced_input_path):
                    if reduction_failed:
                        print(f"  Using original input as reduced input (reduction failed).")
                    else:
                        print(f"  Reduced input '{reduced_input_path}' not found. Using original input as reduced input.")
                    reduced_input = original_input
                    # Create the reduced input file for future use
                    try:
                        with open(reduced_input_path, 'w', encoding='utf-8') as f:
                            f.write(original_input)
                        print(f"  Created reduced input file: {reduced_input_path}")
                    except Exception as write_e:
                        print(f"  [Warning] Failed to create reduced input file: {write_e}", file=sys.stderr)
                        # Continue anyway, we have the content in memory
                else:
                    with open(reduced_input_path, 'r', encoding='utf-8') as f: reduced_input = f.read()
                    print(f"  Using successfully reduced input (size: {len(reduced_input)} chars vs original: {len(original_input)} chars).")
                
                print("  Successfully read WA code, original input, and reduced input.")
            except Exception as e:
                 print(f"  Skipping evaluation: Error reading code/input files: {e}", file=sys.stderr)
                 # Store skip reason if not already evaluated
                 if "evaluation" not in wa_result or wa_result["evaluation"] is None:
                     wa_result["evaluation"] = {"error": f"Skipped (Error reading files: {e})"}
                 continue
            # --- END Read necessary files FIRST ---
            
            # --- Increment evaluated count AFTER successful checks/reads ---
            evaluated_submissions_count += 1
            # --- End Increment ---

            # --- Evaluation result dictionary ---
            evaluation_results = {"error": None}

            # --- Ensure/Generate and Read Output Files ---
            original_output_wa_path = os.path.join(artifact_dir, "original_output_wa.txt")
            reduced_output_wa_path = os.path.join(artifact_dir, "reduced_output_wa.txt")
            original_output_ac_path = os.path.join(artifact_dir, "original_output_ac.txt")
            reduced_output_ac_path = os.path.join(artifact_dir, "reduced_output_ac.txt")

            original_wa_out, reduced_wa_out, original_ac_out, reduced_ac_out = None, None, None, None
            
            # --- Generate/Check WA Outputs ---
            wa_compile_dir = None
            wa_exe_path = None
            try:
                # Compile WA code once if needed for generating outputs
                if not os.path.exists(original_output_wa_path) or not os.path.exists(reduced_output_wa_path):
                    print("  Compiling WA code for output generation...")
                    wa_compile_dir = tempfile.mkdtemp(prefix=f"eval_wa_compile_{submission_id}_")
                    wa_src_path = os.path.join(wa_compile_dir, "wa.cpp")
                    wa_exe_path = os.path.join(wa_compile_dir, "wa_exe")
                    with open(wa_src_path, "w", encoding="utf-8") as f:
                        f.write(wa_code)
                    if not compile_program("wa.cpp", "wa_exe", wa_compile_dir):
                        print(f"  [Error] Failed to compile WA code for submission {submission_id}. Cannot generate WA outputs.", file=sys.stderr)
                        wa_exe_path = None # Ensure it's None if compilation fails
                    else:
                         print(f"  Successfully compiled WA code to {wa_exe_path}")

                # Generate Original WA Output if missing
                if wa_exe_path and not os.path.exists(original_output_wa_path):
                    print(f"  Generating WA output for original input: {original_input_path}")
                    stdout, error = run_program(wa_exe_path, original_input_path, RUN_TIMEOUT * 2) # Longer timeout maybe?
                    if error:
                        print(f"  [Error] Failed to run WA code on original input: {error}", file=sys.stderr)
                        # Save error message instead of output? Or leave file absent? Leave absent for now.
                    else:
                        try:
                            with open(original_output_wa_path, "w", encoding="utf-8") as f:
                                f.write(stdout)
                            print(f"  Saved WA output for original input to {original_output_wa_path}")
                        except IOError as e:
                            print(f"  [Error] Failed to write WA output for original input: {e}", file=sys.stderr)

                # Generate Reduced WA Output if missing
                if wa_exe_path and not os.path.exists(reduced_output_wa_path):
                    print(f"  Generating WA output for reduced input: {reduced_input_path}")
                    stdout, error = run_program(wa_exe_path, reduced_input_path, RUN_TIMEOUT * 2)
                    if error:
                         print(f"  [Error] Failed to run WA code on reduced input: {error}", file=sys.stderr)
                    else:
                        try:
                            with open(reduced_output_wa_path, "w", encoding="utf-8") as f:
                                f.write(stdout)
                            print(f"  Saved WA output for reduced input to {reduced_output_wa_path}")
                        except IOError as e:
                            print(f"  [Error] Failed to write WA output for reduced input: {e}", file=sys.stderr)
            
            finally:
                # Clean up WA compilation directory
                if wa_compile_dir and os.path.exists(wa_compile_dir):
                    shutil.rmtree(wa_compile_dir)


            # --- Generate/Check AC Outputs ---
            # Use the pre-compiled AC executable: ac_executable_path
            if not os.path.exists(original_output_ac_path):
                print(f"  Generating AC output for original input: {original_input_path}")
                stdout, error = run_program(ac_executable_path, original_input_path, RUN_TIMEOUT)
                if error:
                    print(f"  [Error] Failed to run AC code on original input: {error}", file=sys.stderr)
                else:
                     try:
                         with open(original_output_ac_path, "w", encoding="utf-8") as f:
                             f.write(stdout)
                         print(f"  Saved AC output for original input to {original_output_ac_path}")
                     except IOError as e:
                         print(f"  [Error] Failed to write AC output for original input: {e}", file=sys.stderr)

            if not os.path.exists(reduced_output_ac_path):
                print(f"  Generating AC output for reduced input: {reduced_input_path}")
                stdout, error = run_program(ac_executable_path, reduced_input_path, RUN_TIMEOUT)
                if error:
                     print(f"  [Error] Failed to run AC code on reduced input: {error}", file=sys.stderr)
                else:
                     try:
                         with open(reduced_output_ac_path, "w", encoding="utf-8") as f:
                             f.write(stdout)
                         print(f"  Saved AC output for reduced input to {reduced_output_ac_path}")
                     except IOError as e:
                         print(f"  [Error] Failed to write AC output for reduced input: {e}", file=sys.stderr)


            # --- Read Outputs ---
            try:
                if os.path.exists(original_output_wa_path):
                     with open(original_output_wa_path, 'r', encoding='utf-8') as f: original_wa_out = f.read()
                if os.path.exists(reduced_output_wa_path):
                     with open(reduced_output_wa_path, 'r', encoding='utf-8') as f: reduced_wa_out = f.read()
                if os.path.exists(original_output_ac_path):
                     with open(original_output_ac_path, 'r', encoding='utf-8') as f: original_ac_out = f.read()
                if os.path.exists(reduced_output_ac_path):
                     with open(reduced_output_ac_path, 'r', encoding='utf-8') as f: reduced_ac_out = f.read()
                print("  Successfully read available output files.")
            except Exception as e:
                 print(f"  [Error] Failed to read one or more output files: {e}", file=sys.stderr)
                 # Continue with potentially None values for outputs

            # --- Generate and Evaluate ChatRepair Versions for Both Strategies ---
            chatrepair_work_dir = tempfile.mkdtemp(prefix=f"chatrepair_{submission_id}_")
            
            # Helper for processing a single version (reuse or generate)
            def process_version(version_num, test_input, test_wa_out, test_ac_out, baseline_strats_to_check):
                if USE_TEMPERATURE_DIVERSITY:
                    temperature = REPAIR_TEMPERATURE + (version_num - 1) * 0.1
                else:
                    temperature = REPAIR_TEMPERATURE
                adapter = ChatRepairAdapter(model_name=REPAIR_MODEL_NAME, temperature=temperature)
                
                bug_info = BugInfo(
                    file_path=wa_code_path, buggy_code=wa_code, patch_type=PatchType.DELETE,
                    test_input=test_input, test_output=test_wa_out or "",
                    expected_output=test_ac_out or "", problem_description=problem_description
                )
                
                result = adapter.repair_bug(
                    bug_info, reference_outputs, chatrepair_work_dir, test_case_dir, version_num, 
                    args.reuse_first_round, baseline_strats_to_check
                )
                
                # --- Consolidate result format ---
                version_result = {
                    "version_num": version_num, "success": False, "patch": None, "error": None
                }
                if result and result.get("reused") and result.get("success"):
                    version_result.update({
                        "success": True, "patch": "REUSED_SUCCESS", "reused": True,
                        "original_version": result.get('original_version'),
                        "original_strategy": result.get('original_strategy')
                    })
                elif result and result.get("success") and result.get("patches"):
                    version_result.update({
                        "success": True, "patch": result["patches"][0] if result["patches"] else ""
                    })
                else:
                    version_result["error"] = "Repair failed or no success reused"
                return version_num, version_result

            # Helper for running a thread pool for a given strategy
            def run_strategy_in_parallel(strategy_name, test_input, test_wa_out, test_ac_out, baseline_strats_to_check):
                print(f"  Processing Strategy: {strategy_name}")
                results = []
                lock = threading.Lock()
                with ThreadPoolExecutor(max_workers=max_threads) as executor:
                    future_to_version = {
                        executor.submit(process_version, i, test_input, test_wa_out, test_ac_out, baseline_strats_to_check): i 
                        for i in range(1, TOP_K + 1)
                    }
                    for future in as_completed(future_to_version):
                        try:
                            _v_num, version_result = future.result()
                            with lock:
                                results.append(version_result)
                                status_msg = "✓ (reused)" if version_result.get("reused") else "✓ (generated)"
                                if version_result["success"]:
                                    print(f"    - Version {_v_num}: {status_msg}")
                                else:
                                    print(f"    - Version {_v_num}: ✗ (failed)")
                        except Exception as e:
                            print(f"    - Version {future_to_version[future]}: ✗ (error: {e})")
                results.sort(key=lambda x: x["version_num"])
                return results

            # Helper to calculate pass@k and format results
            def calculate_passk_for_strategy(all_version_results):
                if not all_version_results:
                    return {"pass@1": 0.0, "pass@5": 0.0, "pass@10": 0.0, "total_versions": 0, "passed_versions": 0, "version_results": []}
                
                total_versions = len(all_version_results)
                successful_patches = [r for r in all_version_results if r["success"]]
                
                print(f"  Evaluating {len(successful_patches)} successful generations out of {total_versions}...")
                
                eval_work_dir = tempfile.mkdtemp(prefix=f"eval_chatrepair_{submission_id}_")
                cache_file = os.path.join(artifact_dir, f"{submission_id}_evaluation_cache_{args.model_tag}.json")
                submission_evaluation_cache = load_persistent_cache(cache_file)
                initial_cache_size = len(submission_evaluation_cache)

                passed_count = 0
                evaluated_version_results = []
                
                try:
                    for result in all_version_results:
                        if result["success"]:
                            fixed_code = result["patch"]
                            if result.get("reused") and fixed_code == "REUSED_SUCCESS":
                                passed, status = True, f"Reused successful result from version {result.get('original_version', '?')} ({result.get('original_strategy', '?')})"
                            else:
                                if not fixed_code:
                                    passed, status = False, "Generation failed: Empty patch"
                                else:
                                    passed, status = evaluate_fixed_code_refactored(
                                        fixed_code, reference_outputs, eval_work_dir, test_case_dir, 
                                        COMPILE_TIMEOUT, RUN_TIMEOUT, submission_evaluation_cache
                                    )
                            
                            evaluated_version_results.append({"version": result["version_num"], "passed": passed, "status": status, "reused": result.get("reused", False)})
                            if passed:
                                passed_count += 1
                        else:
                            evaluated_version_results.append({"version": result["version_num"], "passed": False, "status": f"Generation/Reuse failed: {result['error']}"})
                finally:
                    if len(submission_evaluation_cache) > initial_cache_size:
                        save_persistent_cache(cache_file, submission_evaluation_cache)
                    shutil.rmtree(eval_work_dir)
                
                return {
                    "pass@1": _calculate_pass_at_k_util(total_versions, passed_count, 1),
                    "pass@5": _calculate_pass_at_k_util(total_versions, passed_count, 5),
                    "pass@10": _calculate_pass_at_k_util(total_versions, passed_count, 10),
                    "total_versions": total_versions, "passed_versions": passed_count,
                    "generated_or_reused_versions": len(successful_patches),
                    "version_results": evaluated_version_results
                }

            try:
                # --- Run Strategy 1: Continue from original test case ---
                from_orig_results = run_strategy_in_parallel(
                    "chatrepair_from_orig",
                    original_input, original_wa_out, original_ac_out,
                    ["orig_tc", "no_tc"]
                )
                evaluation_results["chatrepair_from_orig"] = calculate_passk_for_strategy(from_orig_results)

                # --- Run Strategy 2: Continue from reduced test case ---
                from_reduced_results = run_strategy_in_parallel(
                    "chatrepair_from_reduced",
                    reduced_input, reduced_wa_out, reduced_ac_out,
                    ["reduced_tc", "reduced_plus_diff"]
                )
                evaluation_results["chatrepair_from_reduced"] = calculate_passk_for_strategy(from_reduced_results)

            finally:
                if os.path.exists(chatrepair_work_dir):
                    shutil.rmtree(chatrepair_work_dir)

            # --- FINAL STEP: Store evaluation results in repair results file ---
            # Find or create entry for this submission in repair results
            repair_submission_entry = None
            for entry in repair_results_data[target_problem_id_input]["results"]:
                if entry.get("submission_id") == submission_id:
                    repair_submission_entry = entry
                    break
            
            if repair_submission_entry is None:
                # Create new entry with basic info from reduction results
                repair_submission_entry = {
                    "submission_id": submission_id,
                    "wa_code_path": wa_result.get("wa_code_path"),
                    "status_code": wa_result.get("status_code"),
                    "message": wa_result.get("message"),
                    "original_size_bytes": wa_result.get("original_size_bytes"),
                    "reduced_size_bytes": wa_result.get("reduced_size_bytes"),
                    "failing_case_name": wa_result.get("failing_case_name")
                }
                repair_results_data[target_problem_id_input]["results"].append(repair_submission_entry)
            
            repair_submission_entry["evaluation"] = evaluation_results
            
            # 立即保存结果，确保不丢失中间结果
            save_results_with_lock(RESULT_JSON_PATH, repair_results_data)

        # --- Calculate and Print Success Rates for ChatRepair Strategies ---
        print("\n--- Final ChatRepair Evaluation Summary ---")
        if evaluated_submissions_count > 0:
            print(f"Total WA submissions evaluated: {evaluated_submissions_count}")
            print(f"Generation Strategy: {TOP_K} versions per submission.")
            print(f"Logic: Reuse passed versions from baseline, otherwise generate new patches using corresponding test cases.")

            # 使用自动发现的策略名称进行总结
            final_evaluation_data = repair_results_data.get(target_problem_id_input, {}).get("results", [])
            final_success_counts = {}
            
            # 重新统计成功次数
            for entry in final_evaluation_data:
                eval_data = entry.get("evaluation", {})
                for strategy_key, strategy_result in eval_data.items():
                    if isinstance(strategy_result, dict) and strategy_result.get("passed_versions", 0) > 0:
                        if strategy_key not in final_success_counts:
                            final_success_counts[strategy_key] = 0
                        final_success_counts[strategy_key] += 1

            for strategy_key in sorted(final_success_counts.keys()):
                count = final_success_counts.get(strategy_key, 0)
                rate = (count / evaluated_submissions_count) * 100
                print(f"  - Strategy '{strategy_key}':   {count}/{evaluated_submissions_count} ({rate:.2f}%)")

        else:
            print("No WA submissions were eligible for evaluation in this run.")
        # --- End Success Rate Calculation ---

        # --- Results Already Saved Per Submission ---
        print(f"\n--- All results have been saved incrementally to {RESULT_JSON_PATH} ---")

    finally:
        # --- Clean up AC compilation directory at the very end --- 
        if ac_work_dir and os.path.exists(ac_work_dir):
            try:
                shutil.rmtree(ac_work_dir)
                print(f"\n[Cleanup] Successfully cleaned up AC work directory: {ac_work_dir}")
            except Exception as e:
                print(f"\n[Cleanup Error] Failed to remove AC work directory {ac_work_dir}: {e}", file=sys.stderr)


if __name__ == "__main__":
    main() 
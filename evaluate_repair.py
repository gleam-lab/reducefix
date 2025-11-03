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
from typing import Optional, Tuple, List, Dict, Any
from concurrent.futures import ThreadPoolExecutor, as_completed
import threading
import fcntl # For file locking on Unix-like systems
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
TOP_K = 10
# --- LLM Configuration for Repair --- 
REPAIR_MODEL_NAME = "qwen2.5-coder-7b-instruct" # Model to use for repairs
REPAIR_TEMPERATURE = 0.8
MAX_INPUT_LENGTH_FOR_LLM = 40960 # Max chars for failing input in prompt (10KB)
# --- Add max length for output context ---
MAX_OUTPUT_LENGTH_FOR_LLM = 8192 # Max chars for actual/expected output in prompt (2KB)
# Default max threads - can be overridden by command line argument
DEFAULT_MAX_THREADS = 5

# --- Try importing necessary components ---
try:
    # Assuming reduce.py is in the same directory or Python path
    from reduce import compile_program, _parse_problem_id
    print("[Info] Successfully imported required functions from reduce.")
except ImportError as e:
    print(f"[Error] Failed to import from reduce ({e}). Ensure reduce.py is accessible.", file=sys.stderr)
    sys.exit(1)

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

def evaluate_fixed_code(
    fixed_code_str: str,
    reference_outputs: Dict[str, str],
    work_dir: str,
    compile_timeout: int,
    run_timeout: int
) -> Tuple[bool, str]:
    """
    Compiles the fixed code, runs it against all test cases, compares with reference outputs.
    Returns (passed_all, status_message).
    """
    fixed_src_path = os.path.join(work_dir, "fixed.cpp")
    fixed_exe_path = os.path.join(work_dir, "fixed")

    # 1. Write fixed code
    try:
        with open(fixed_src_path, "w", encoding="utf-8") as f:
            f.write(fixed_code_str)
    except IOError as e:
        return False, f"Failed to write fixed code: {e}"

    # 2. Compile fixed code
    # Assuming compile_program works correctly with relative paths within work_dir
    if not compile_program("fixed.cpp", "fixed", work_dir):
        return False, "Compilation Failed"

    # 3. Run on each test case and compare
    # Infer test case directory structure based on how reference_outputs keys were formed
    # This assumes reference_outputs keys are just the base filenames
    if not reference_outputs:
        return False, "Internal Error: No reference outputs provided"
    # Get one key to find the directory
    one_case_name = next(iter(reference_outputs.keys()))
    # Assume the test case dir is where this file would be
    # This part is fragile and depends on how test_case_names was created in get_reference_outputs
    # Let's assume the full path was not stored, only basename. Reconstruct path needed.
    # Need the original test_case_dir path here. Pass it as an argument.

    # *** Need to pass test_case_dir to this function ***
    # Let's refactor to pass test_case_dir
    # Refactored signature: evaluate_fixed_code(..., test_case_dir: str)

    all_passed = True
    first_failure_details = ""

    for case_base_name, ref_stdout in reference_outputs.items():
        # This assumes case_base_name is JUST the filename, need dir.
        # Correction: We need the test case directory passed in.
        # We'll assume it's passed in for now.
        input_path = os.path.join("PLACEHOLDER_TEST_CASE_DIR", case_base_name) # Placeholder!
        fixed_stdout, error = run_program(fixed_exe_path, input_path, run_timeout)

        if error:
            all_passed = False
            first_failure_details = f"Failed on '{case_base_name}': {error}"
            break # Stop on first error

        # Normalize whitespace/newlines for comparison - ignore trailing whitespace on each line
        def normalize_output(output):
            return '\n'.join(line.rstrip() for line in output.splitlines()).strip()
        
        if normalize_output(fixed_stdout) != normalize_output(ref_stdout):
            all_passed = False
            first_failure_details = f"Wrong Answer on '{case_base_name}'"
            # Optionally include diff here for debugging
            break # Stop on first WA

    if all_passed:
        return True, "Correct (Passed All Test Cases)"
    else:
        return False, first_failure_details


# --- Refactored evaluate_fixed_code (passing test_case_dir) ---
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


# --- Enhanced LLM Repair Function with Optimization --- 
def generate_llm_repair(
    problem_description: str,
    wa_code: str,
    submission_id: str, # Added submission_id
    repair_context_label: str, # Added context label (e.g., "no_tc", "orig_tc", "reduced_tc")
    failing_input: Optional[str] = None,
    artifact_dir: Optional[str] = None,
    wa_output: Optional[str] = None, 
    expected_output: Optional[str] = None,
    # --- NEW: Support for dual test case strategy ---
    secondary_input: Optional[str] = None,
    secondary_wa_output: Optional[str] = None,
    secondary_expected_output: Optional[str] = None,
    model_tag: str = ""
) -> Optional[str]:
    """
    Enhanced repair function with optimized prompt strategy:
    - Full problem description (including samples)
    - Smart truncation with structure preservation
    - Dual test case support for better generalization
    - Precise diff information
    """
    
    # --- Step 1: Use full problem description ---
    print(f"  [Prompt] Using full problem description ({len(problem_description)} chars)")
    
    # --- Step 2: Build prompt with full problem description ---
    prompt = f"""### Problem Description
{problem_description}

### Your Incorrect Code
```cpp
{wa_code}
```

"""

    # --- Step 3: Handle test case information ---
    input_for_llm_str = None
    wa_output_for_llm_str = None
    expected_output_for_llm_str = None
    prompt_context_type = "no_tc"
    
    if failing_input:
        prompt_context_type = "with_tc"
        
        # Smart truncation for primary input
        input_for_llm_str, input_note = truncate_smart(failing_input, MAX_INPUT_LENGTH_FOR_LLM, "input")
        if input_note:
            print(f"  [Smart Truncation] Primary input{input_note}")
        
        # --- Dual test case strategy ---
        dual_case_info = ""
        if secondary_input and secondary_input != failing_input and len(secondary_input.strip()) > 0:
            # Adjust truncation length: keep total (primary + secondary) roughly within MAX_INPUT_LENGTH_FOR_LLM
            avail_len = max(0, MAX_INPUT_LENGTH_FOR_LLM - len(input_for_llm_str))
            # If reduced_plus_diff strategy, try to use full budget; else default to half budget
            sec_limit = avail_len if repair_context_label.startswith("reduced_plus_diff") else MAX_INPUT_LENGTH_FOR_LLM // 2
            secondary_input_truncated, secondary_note = truncate_smart(secondary_input, sec_limit, "input")
            if secondary_note:
                print(f"  [Smart Truncation] Secondary input{secondary_note}")
            
            dual_case_info = f"""
### Failing Case #2 (Alternative Size)
Input:
```
{secondary_input_truncated}
```"""
            
            if secondary_wa_output and secondary_expected_output:
                sec_wa_truncated, _ = truncate_smart(secondary_wa_output, MAX_OUTPUT_LENGTH_FOR_LLM // 2, "output")
                sec_exp_truncated, _ = truncate_smart(secondary_expected_output, MAX_OUTPUT_LENGTH_FOR_LLM // 2, "output")
                diff_info_2 = get_diff_lines(sec_wa_truncated, sec_exp_truncated)
                dual_case_info += f"""
Error: {diff_info_2}"""
        
        # Primary test case
        prompt += f"""### Failing Case #1
Input:
```
{input_for_llm_str}
```"""
        
        # Add output diff information
        if wa_output is not None and expected_output is not None:
            prompt_context_type = "with_tc_outputs"
            
            wa_output_for_llm_str, wa_note = truncate_smart(wa_output, MAX_OUTPUT_LENGTH_FOR_LLM, "output")
            expected_output_for_llm_str, exp_note = truncate_smart(expected_output, MAX_OUTPUT_LENGTH_FOR_LLM, "output")
            
            if wa_note:
                print(f"  [Smart Truncation] Actual output{wa_note}")
            if exp_note:
                print(f"  [Smart Truncation] Expected output{exp_note}")
            
            # Different strategies for different repair contexts
            if repair_context_label.startswith("diff_only"):
                # For diff-only strategy, only show diff information
                diff_info = get_diff_lines(wa_output_for_llm_str, expected_output_for_llm_str, max_lines=10)
                prompt += f"""
Error: {diff_info}"""
            else:
                # For full context strategies (orig_tc, reduced_tc, reduced_plus_diff), show full outputs
                prompt += f"""
Your Output:
```
{wa_output_for_llm_str}
```
Expected Output:
```
{expected_output_for_llm_str}
```"""
                
                # Also include diff info for clarity, but after showing full outputs
                diff_info = get_diff_lines(wa_output_for_llm_str, expected_output_for_llm_str, max_lines=10)
                prompt += f"""
Error Analysis: {diff_info}"""
        
        # Add dual case information
        prompt += dual_case_info
        
        # --- Enhanced task instructions ---
        prompt += f"""

### Your Task
Fix the C++ code to pass ALL test cases (including hidden ones).

### Critical Guidelines
1. Focus on algorithmic correctness - NO hard-coded values or special cases
2. Ensure proper data structures and complexity (aim for O(N log N) or better when possible)
3. Handle edge cases (empty input, single elements, max constraints)
4. Use standard C++20 features; avoid non-portable code

### Output Format
Provide ONLY the complete fixed C++ code in a single ```cpp block.
"""
    else:
        # No test case provided
        prompt += f"""### Your Task
Analyze and fix the algorithmic errors in the C++ code.

### Guidelines
1. Focus on correctness and efficiency
2. Consider edge cases and constraint limits
3. Use clean, readable code structure

### Output Format
Provide ONLY the complete fixed C++ code in a single ```cpp block.
"""

    # --- Save Prompt and Components (Moved Up) ---
    if artifact_dir:
        os.makedirs(artifact_dir, exist_ok=True)
        
        def save_component(filename, content):
            if content is None: return # Don't save if content is None
            path = os.path.join(artifact_dir, filename)
            try:
                with open(path, "w", encoding="utf-8") as f: f.write(content)
                # Removed info print about saving component
                # print(f"  [Info] Saved component to: {path}") 
            except IOError as e:
                print(f"  [Warning] Failed to save {filename}: {e}", file=sys.stderr)

        # --- Modify filenames to include repair_context_label --- 
        context_suffix = f"_{repair_context_label}_{model_tag}" # e.g., "_no_tc_qwen-plus", "_orig_tc_llama3"
        save_component(f"{submission_id}.prompt{context_suffix}.txt", prompt)
        save_component(f"{submission_id}.llm_input{context_suffix}.txt", input_for_llm_str)
        save_component(f"{submission_id}.actual_output{context_suffix}.txt", wa_output_for_llm_str)
        save_component(f"{submission_id}.expected_output{context_suffix}.txt", expected_output_for_llm_str)
        # --- End modify filenames ---
    # --- End Save ---

    # Removed verbose logging per user request

    fixed_code = None # Initialize fixed_code
    raw_response = None # Initialize raw_response
    try:
        prompt_history = [{'role': 'user', 'content': prompt}]
        raw_response = llm.call_llm(
            prompt_history=prompt_history,
            model_name=REPAIR_MODEL_NAME,
            temperature=REPAIR_TEMPERATURE,
        )

        if raw_response:
            # --- Save Raw LLM Response ---
            if artifact_dir:
                 # --- Modify response filename to include context suffix --- 
                 save_component(f"{submission_id}.llm_response_{repair_context_label}_{model_tag}.txt", raw_response)
                 # --- End modify response filename ---
            # --- End Save Raw Response ---

            # --- Extract C++ code block directly --- 
            start_marker = "```cpp\n"
            end_marker = "\n```"
            start_index = raw_response.find(start_marker)

            if start_index != -1:
                code_start_index = start_index + len(start_marker)
                end_index = raw_response.find(end_marker, code_start_index)
                if end_index != -1:
                    fixed_code = raw_response[code_start_index:end_index].strip()
                    print("[Info] Successfully extracted C++ code block using ```cpp markers.")
                else:
                    end_marker_alt = "```"
                    if raw_response.strip().endswith(end_marker_alt):
                        temp_end_index = raw_response.rfind(end_marker_alt)
                        if temp_end_index > code_start_index:
                             fixed_code = raw_response[code_start_index:temp_end_index].strip()
                             print("[Info] Successfully extracted C++ code block using ```cpp start and final ``` end markers.")

                if fixed_code:
                    # --- Save Extracted Fixed Code ---
                    if artifact_dir:
                         # --- Modify fixed code filename to include context suffix --- 
                         save_component(f"{submission_id}.fixed_code_{repair_context_label}_{model_tag}.cpp", fixed_code)
                         # --- End modify fixed code filename ---
                    # --- End Save Fixed Code ---
                    return fixed_code
                else:
                    # Failed to extract code
                    return None
            else:
                # Failed to extract code
                return None
        else:
            print("[Error] LLM call returned None (likely an API error or client issue).", file=sys.stderr)
            return None

    except Exception as e:
        print(f"[Error] Exception during LLM call or extraction in generate_llm_repair: {e}", file=sys.stderr)
        traceback.print_exc()
        # --- Save Raw LLM Response on Exception (if available) ---
        if artifact_dir and raw_response is not None:
             # --- Modify error response filename to include context suffix --- 
             save_component(f"{submission_id}.llm_response_on_error_{repair_context_label}_{model_tag}.txt", raw_response)
             # --- End modify error response filename ---
        # --- End Save Raw Response ---
        return None

# --- Add new prompt optimization helpers ---
# extract_problem_essentials function removed - using full problem description instead

def get_diff_lines(actual_output: str, expected_output: str, max_lines: int = 20) -> str:
    """Return up to `max_lines` lines where actual and expected outputs differ.
    Format: "Line i: Got '...', Expected '...'". If line counts differ, note that too.
    """
    if not actual_output or not expected_output:
        return "Missing output data"

    actual_lines = actual_output.splitlines()
    expected_lines = expected_output.splitlines()

    diffs = []
    for i in range(max(len(actual_lines), len(expected_lines))):
        a_line = actual_lines[i].rstrip() if i < len(actual_lines) else "<EOF>"
        e_line = expected_lines[i].rstrip() if i < len(expected_lines) else "<EOF>"
        if a_line != e_line:
            diffs.append(f"Line {i+1}: Got '{a_line}', Expected '{e_line}'")
            if len(diffs) >= max_lines:
                break
    if not diffs:
        return "Outputs appear identical (possibly whitespace issue)"
    return "\n".join(diffs)

def truncate_smart(text: str, max_length: int, label: str = "") -> tuple:
    """Hard truncation: simply return the first `max_length` characters to ensure更多上下文。"""
    # 若文本长度已在限制以内，直接返回
    if len(text) <= max_length:
        return text, ""

    # 直接硬截断前 max_length 个字符
    truncated = text[:max_length]
    note = f" (truncated from {len(text)} chars)"
    return truncated, note

def generate_versions_parallel(problem_description: str, wa_code: str, submission_id: str, 
                             base_context_label: str, artifact_dir: str, 
                             num_versions: int, 
                             start_version: int = 1,  # Added start_version parameter
                             failing_input: Optional[str] = None,
                             wa_output: Optional[str] = None, 
                             expected_output: Optional[str] = None,
                             secondary_input: Optional[str] = None,
                             secondary_wa_output: Optional[str] = None,
                             secondary_expected_output: Optional[str] = None,
                             model_tag: str = "",
                             max_threads: int = DEFAULT_MAX_THREADS) -> List[str]:
    """
    Parallel generation of multiple repair versions.
    Returns a list of successfully generated code strings.
    """
    
    def generate_single_version(version_num):
        """Generate a single version - thread-safe."""
        context_label = f"{base_context_label}_v{version_num}"
        try:
            result = generate_llm_repair(
                problem_description, wa_code, submission_id=submission_id,
                repair_context_label=context_label, artifact_dir=artifact_dir,
                failing_input=failing_input, wa_output=wa_output, 
                expected_output=expected_output,
                secondary_input=secondary_input,
                secondary_wa_output=secondary_wa_output,
                secondary_expected_output=secondary_expected_output,
                model_tag=model_tag
            )
            return version_num, result
        except Exception as e:
            print(f"    [Warning] Failed to generate version {version_num}: {e}", file=sys.stderr)
            return version_num, None
    
    print(f"  Generating {num_versions} versions in parallel (starting from v{start_version})...")
    successful_versions = []
    
    # Use ThreadPoolExecutor for parallel generation
    with ThreadPoolExecutor(max_workers=min(num_versions, max_threads)) as executor:  # Limit concurrent threads
        # Submit all generation tasks with correct version numbers
        futures = {executor.submit(generate_single_version, i): i for i in range(start_version, start_version + num_versions)}
        
        # Collect results as they complete
        results = {}
        for future in as_completed(futures):
            version_num, code = future.result()
            results[version_num] = code
            # Removed verbose output per user request
    
    # Collect successful results in order
    for i in range(start_version, start_version + num_versions):
        if i in results and results[i]:
            successful_versions.append(results[i])
    
    print(f"  Generated {len(successful_versions)}/{num_versions} versions successfully")
    return successful_versions

# --- Main Evaluation Logic ---
def main():
    parser = argparse.ArgumentParser(description="Evaluate LLM repair performance using different test case inputs.")
    parser.add_argument("problem_id", help="Target AtCoder problem ID (e.g., abc123a)")
    parser.add_argument("--model-tag", required=True, help="Tag for result file naming (e.g., 'qwen-coder7b' -> result_qwen-coder7b.json)")
    parser.add_argument("--reducer-model", default="qwen-plus", help="LLM model name for reducer generation (default: qwen-plus)")
    parser.add_argument("--repair-model", help="LLM model name for repair (overrides default REPAIR_MODEL_NAME)")
    parser.add_argument("--regenerate", action="store_true", 
                       help="Force regenerate all repair codes instead of loading cached versions (default: load cached)")
    parser.add_argument("--max-threads", type=int, default=DEFAULT_MAX_THREADS,
                       help=f"Maximum number of parallel threads for LLM generation (default: {DEFAULT_MAX_THREADS})")
    args = parser.parse_args()
    target_problem_id_input = args.problem_id.strip().lower()
    max_threads = args.max_threads

    # Repair 结果保存到 model_tag 对应的文件中
    global RESULT_JSON_PATH
    RESULT_JSON_PATH = f"result_{args.model_tag}.json"

    # 如果指定了 --repair-model，覆盖默认的repair模型
    if args.repair_model:
        global REPAIR_MODEL_NAME
        REPAIR_MODEL_NAME = args.repair_model
        print(f"[Info] Using repair model: {REPAIR_MODEL_NAME} (overridden by --repair-model)")
    else:
        print(f"[Info] Using default repair model: {REPAIR_MODEL_NAME}")

    print(f"[Info] Using max threads: {max_threads}")

    # --- Load Reduction Data from unified reducer results file --- 
    REDUCER_RESULTS_FILE = "reducer_results.json"
    
    print(f"[Info] Loading reduction results from {REDUCER_RESULTS_FILE}...")
    
    # Parse problem ID to get directory structure
    parsed_ids = _parse_problem_id(target_problem_id_input)
    if not parsed_ids:
        print(f"[Error] Invalid problem ID format: '{target_problem_id_input}'", file=sys.stderr)
        sys.exit(1)
    contest_id, problem_letter = parsed_ids
    problem_dir_name = f"results/{contest_id}{problem_letter.lower()}"
    
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
    ac_path = os.path.join(problem_dir_name, "ac.cpp")
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
    print(f"\n--- Evaluating Repairs for {len(wa_results)} WA Submissions --- ")
    needs_saving = False # Flag to save JSON only if changes were made

    # --- Add counters for 5 fair strategies ---
    evaluated_submissions_count = 0
    success_counts = {"no_tc": 0, "orig_tc": 0, "diff_only": 0, "reduced_tc": 0, "reduced_plus_diff": 0}
    success_submissions = {"no_tc": [], "orig_tc": [], "diff_only": [], "reduced_tc": [], "reduced_plus_diff": []}
    # --- End Add counters ---

    # --- Add outer try/finally block for main loop cleanup ---
    try:
        for wa_result in wa_results:
            submission_id = str(wa_result.get("submission_id", "UNKNOWN"))
            print(f"\n-- Processing WA Submission: {submission_id} --")

            # -------------------------------------------------------------
            # Early Skip Logic: If all strategies already have TOP_K (10)
            # repaired code versions on disk, we can safely skip this WA
            # submission to save time and avoid redundant LLM calls.
            # -------------------------------------------------------------
            strategies_labels = ["no_tc", "orig_tc", "diff_only", "reduced_tc", "reduced_plus_diff"]
            all_versions_done = True
            for label in strategies_labels:
                # 确保始终从 results/abc* 目录下检索已生成的修复版本，而不是 abc* 目录
                wa_code_relative_path = wa_result.get("wa_code_path", "")  # e.g. "abc123a/wa.cpp"
                wa_code_full_path = os.path.join("results", wa_code_relative_path)  # e.g. "results/abc123a/wa.cpp"
                wa_dir = os.path.dirname(wa_code_full_path)  # e.g. "results/abc123a"
                pattern = os.path.join(wa_dir, f"{submission_id}.fixed_code_{label}_v*_{args.model_tag}.cpp")
                existing_versions = len(glob.glob(pattern))
                if existing_versions < TOP_K:
                    all_versions_done = False
                    break

            if all_versions_done and not args.regenerate:
                print("  Detected all TOP_K repaired versions already exist for every strategy. Skipping this submission.")
                continue
             
            wa_code_path = 'results/' + wa_result.get("wa_code_path")
            status_code = wa_result.get("status_code")

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
                    needs_saving = True
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
                     needs_saving = True
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
                     needs_saving = True
                 continue
            # --- END Read necessary files FIRST ---
            
            # --- Increment evaluated count AFTER successful checks/reads ---
            evaluated_submissions_count += 1
            # --- End Increment ---

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


            # --- Perform 4 Fair Repair Attempts (Load or Generate with Multi-Version Support) ---
            
            # Strategy 1: Pure Baseline - No Test Case (Generate TOP_K versions)
            print("  Strategy 1: Pure Baseline (No Test Case)")
            fixed_codes_1 = []
            if not args.regenerate:
                # Try to load existing versions
                for version in range(1, TOP_K + 1):
                    fixed_code_path = os.path.join(artifact_dir, f"{submission_id}.fixed_code_no_tc_v{version}_{args.model_tag}.cpp")
                    if os.path.exists(fixed_code_path):
                        try:
                            with open(fixed_code_path, 'r', encoding='utf-8') as f:
                                fixed_codes_1.append(f.read())
                        except Exception as e:
                            print(f"  [Warning] Failed to read {fixed_code_path}: {e}", file=sys.stderr)
                            break
                    else:
                        break
            
            # Generate missing versions in parallel
            missing_count = TOP_K - len(fixed_codes_1)
            if missing_count > 0:
                start_version = len(fixed_codes_1) + 1  # Start from next version number
                new_versions = generate_versions_parallel(
                    problem_description, wa_code, submission_id=submission_id,
                    base_context_label="no_tc", artifact_dir=artifact_dir,
                    num_versions=missing_count, start_version=start_version,
                    model_tag=args.model_tag,
                    max_threads=max_threads
                )
                fixed_codes_1.extend(new_versions)
            
            print(f"  Strategy 1: {len(fixed_codes_1)}/{TOP_K} versions ready")

            # Strategy 2: Original Test Case (Full Info) (Generate TOP_K versions)
            print("  Strategy 2: Original Test Case (Full Info)")
            fixed_codes_2 = []
            if not args.regenerate:
                # Try to load existing versions
                for version in range(1, TOP_K + 1):
                    fixed_code_path = os.path.join(artifact_dir, f"{submission_id}.fixed_code_orig_tc_v{version}_{args.model_tag}.cpp")
                    if os.path.exists(fixed_code_path):
                        try:
                            with open(fixed_code_path, 'r', encoding='utf-8') as f:
                                fixed_codes_2.append(f.read())
                        except Exception as e:
                            print(f"  [Warning] Failed to read {fixed_code_path}: {e}", file=sys.stderr)
                            break
                    else:
                        break
            
            # Generate missing versions in parallel
            missing_count = TOP_K - len(fixed_codes_2)
            if missing_count > 0:
                start_version = len(fixed_codes_2) + 1  # Start from next version number
                new_versions = generate_versions_parallel(
                    problem_description, wa_code, submission_id=submission_id,
                    base_context_label="orig_tc", artifact_dir=artifact_dir,
                    num_versions=missing_count, start_version=start_version,
                    failing_input=original_input, 
                    wa_output=original_wa_out, 
                    expected_output=original_ac_out,
                    model_tag=args.model_tag,
                    max_threads=max_threads
                )
                fixed_codes_2.extend(new_versions)
            
            print(f"  Strategy 2: {len(fixed_codes_2)}/{TOP_K} versions ready")

            # Strategy 3: Test Diff Only (Generate TOP_K versions)
            print("  Strategy 3: Test Diff Only")
            fixed_codes_3 = []
            if not args.regenerate:
                # Try to load existing versions
                for version in range(1, TOP_K + 1):
                    fixed_code_path = os.path.join(artifact_dir, f"{submission_id}.fixed_code_diff_only_v{version}_{args.model_tag}.cpp")
                    if os.path.exists(fixed_code_path):
                        try:
                            with open(fixed_code_path, 'r', encoding='utf-8') as f:
                                fixed_codes_3.append(f.read())
                        except Exception as e:
                            print(f"  [Warning] Failed to read {fixed_code_path}: {e}", file=sys.stderr)
                            break
                    else:
                        break
            
            # Generate missing versions in parallel - Only provide diff info
            missing_count = TOP_K - len(fixed_codes_3)
            if missing_count > 0:
                start_version = len(fixed_codes_3) + 1  # Start from next version number
                # For diff-only strategy, we provide ONLY the diff information, no input
                diff_info = get_diff_lines(original_wa_out, original_ac_out, max_lines=10)
                new_versions = generate_versions_parallel(
                    problem_description, wa_code, submission_id=submission_id,
                    base_context_label="diff_only", artifact_dir=artifact_dir,
                    num_versions=missing_count, start_version=start_version,
                    failing_input=None,  # No input for diff-only strategy to keep prompt minimal
                    wa_output=diff_info,  # Use diff info instead of full output
                    expected_output="(See diff above)",
                    model_tag=args.model_tag,
                    max_threads=max_threads
                )
                fixed_codes_3.extend(new_versions)
            
            print(f"  Strategy 3: {len(fixed_codes_3)}/{TOP_K} versions ready")

            # Strategy 4: Reduced Test Case Only (Generate TOP_K versions)
            print("  Strategy 4: Reduced Test Case Only")
            fixed_codes_4 = []
            if not args.regenerate:
                # Try to load existing versions
                for version in range(1, TOP_K + 1):
                    fixed_code_path = os.path.join(artifact_dir, f"{submission_id}.fixed_code_reduced_tc_v{version}_{args.model_tag}.cpp")
                    if os.path.exists(fixed_code_path):
                        try:
                            with open(fixed_code_path, 'r', encoding='utf-8') as f:
                                fixed_codes_4.append(f.read())
                        except Exception as e:
                            print(f"  [Warning] Failed to read {fixed_code_path}: {e}", file=sys.stderr)
                            break
                    else:
                        break
            
            # Generate missing versions in parallel
            missing_count = TOP_K - len(fixed_codes_4)
            if missing_count > 0:
                start_version = len(fixed_codes_4) + 1  # Start from next version number
                new_versions = generate_versions_parallel(
                    problem_description, wa_code, submission_id=submission_id,
                    base_context_label="reduced_tc", artifact_dir=artifact_dir,
                    num_versions=missing_count, start_version=start_version,
                    failing_input=reduced_input, 
                    wa_output=reduced_wa_out, 
                    expected_output=reduced_ac_out,
                    model_tag=args.model_tag,
                    max_threads=max_threads
                )
                fixed_codes_4.extend(new_versions)
            
            print(f"  Strategy 4: {len(fixed_codes_4)}/{TOP_K} versions ready")

            # Strategy 5: Reduced Test Case + Original Test Diff (Generate TOP_K versions)
            print("  Strategy 5: Reduced Test Case + Original Test Diff")
            fixed_codes_5 = []
            if not args.regenerate:
                # Try to load existing versions
                for version in range(1, TOP_K + 1):
                    fixed_code_path = os.path.join(artifact_dir, f"{submission_id}.fixed_code_reduced_plus_diff_v{version}_{args.model_tag}.cpp")
                    if os.path.exists(fixed_code_path):
                        try:
                            with open(fixed_code_path, 'r', encoding='utf-8') as f:
                                fixed_codes_5.append(f.read())
                        except Exception as e:
                            print(f"  [Warning] Failed to read {fixed_code_path}: {e}", file=sys.stderr)
                            break
                    else:
                        break
            
            # Generate missing versions in parallel
            missing_count = TOP_K - len(fixed_codes_5)
            if missing_count > 0:
                start_version = len(fixed_codes_5) + 1  # Start from next version number
                # Provide reduced test case as primary + original test case with full outputs as secondary
                new_versions = generate_versions_parallel(
                    problem_description, wa_code, submission_id=submission_id,
                    base_context_label="reduced_plus_diff", artifact_dir=artifact_dir,
                    num_versions=missing_count, start_version=start_version,
                    failing_input=reduced_input,  # Primary: reduced test case
                    wa_output=reduced_wa_out,
                    expected_output=reduced_ac_out,
                    # Secondary: original test case with full outputs for comprehensive context
                    secondary_input=original_input,          # 附原始用例
                    secondary_wa_output=original_wa_out,     # 原始用例的WA输出
                    secondary_expected_output=original_ac_out,  # 原始用例的期望输出
                    model_tag=args.model_tag,
                    max_threads=max_threads
                )
                fixed_codes_5.extend(new_versions)
            
            print(f"  Strategy 5: {len(fixed_codes_5)}/{TOP_K} versions ready")


            # --- Evaluate Results with 5 Fair Strategies (Multi-Version Support) --- 
            evaluation_results = {"error": None}
            eval_work_dir = tempfile.mkdtemp(prefix=f"eval_repair_{submission_id}_")
            
            # Load persistent evaluation cache for this submission
            cache_file = os.path.join(artifact_dir, f"{submission_id}_evaluation_cache_{args.model_tag}.json")
            submission_evaluation_cache = load_persistent_cache(cache_file)
            initial_cache_size = len(submission_evaluation_cache)
            if initial_cache_size > 0:
                print(f"  [Cache] Loaded {initial_cache_size} cached results from previous runs")
            
            try:
                # Helper function to evaluate multiple versions
                def evaluate_strategy_versions(strategy_name, fixed_codes, strategy_key):
                    expected_count = TOP_K
                    actual_count = len(fixed_codes)
                    print(f"  Evaluating {strategy_name} ({actual_count}/{expected_count} versions)...")
                    
                    best_result = {"passed": False, "status": "No versions available", "successful_version": None, "versions": []}
                    
                    if not fixed_codes:
                        print("    Result: No code generated")
                        return best_result
                    
                    # Test all versions to find if at least one passes
                    passed_versions = []
                    failed_versions = []
                    version_results = []  # Store detailed results for each version
                    cache_hits_this_strategy = 0
                    initial_cache_size = len(submission_evaluation_cache)
                    
                    for version, fixed_code in enumerate(fixed_codes, 1):
                        # Check cache first before any compilation/testing
                        code_hash = get_code_hash(fixed_code)
                        was_cached = code_hash in submission_evaluation_cache
                        
                        if was_cached:
                            # Use cached result directly
                            cached_result = submission_evaluation_cache[code_hash]
                            passed = cached_result["passed"]
                            status = cached_result["status"]
                            cache_hits_this_strategy += 1
                            result_short = "PASS" if passed else "FAIL"
                            print(f"      [Cache Hit] Version {version}: {result_short}")
                        else:
                            # Need to test this code
                            passed, status = evaluate_fixed_code_refactored(
                                fixed_code, reference_outputs, eval_work_dir, test_case_dir, 
                                COMPILE_TIMEOUT, RUN_TIMEOUT, submission_evaluation_cache
                            )
                        
                        # Record this version's result
                        version_results.append({
                            "version": version,
                            "passed": passed,
                            "status": status
                        })
                        
                        if passed:
                            passed_versions.append(version)
                            if not best_result["passed"]:  # Record first successful result
                                best_result = {"passed": True, "status": status, "successful_version": version}
                        else:
                            failed_versions.append(version)
                    
                    # Add detailed version results to best_result
                    best_result["versions"] = version_results
                    
                    # Show cache statistics for this strategy
                    new_codes_tested = len(submission_evaluation_cache) - initial_cache_size
                    total_evaluations = len(fixed_codes)
                    if cache_hits_this_strategy > 0:
                        print(f"    [Cache Stats] {cache_hits_this_strategy}/{total_evaluations} cache hits, {new_codes_tested} new codes tested")
                    
                    # Final result summary
                    if passed_versions:
                        print(f"    Result: SUCCESS ({len(passed_versions)}/{len(fixed_codes)} passed)")
                        success_counts[strategy_key] += 1
                        success_submissions[strategy_key].append(submission_id)  # Record successful submission ID
                    else:
                        print(f"    Result: FAILURE (0/{len(fixed_codes)} passed)")
                        # Use the status from the first version as representative
                        if fixed_codes:
                            _, first_status = evaluate_fixed_code_refactored(
                                fixed_codes[0], reference_outputs, eval_work_dir, test_case_dir,
                                COMPILE_TIMEOUT, RUN_TIMEOUT, submission_evaluation_cache
                            )
                            best_result["status"] = f"All {len(fixed_codes)} versions failed (first: {first_status})"
                    
                    return best_result

                # Evaluate each strategy
                result_1 = evaluate_strategy_versions("Strategy 1 (Pure Baseline)", fixed_codes_1, "no_tc")
                evaluation_results["no_tc"] = result_1

                result_2 = evaluate_strategy_versions("Strategy 2 (Original Test Case)", fixed_codes_2, "orig_tc")
                evaluation_results["orig_tc"] = result_2

                result_3 = evaluate_strategy_versions("Strategy 3 (Test Diff Only)", fixed_codes_3, "diff_only")
                evaluation_results["diff_only"] = result_3

                result_4 = evaluate_strategy_versions("Strategy 4 (Reduced Test Case)", fixed_codes_4, "reduced_tc")
                evaluation_results["reduced_tc"] = result_4

                result_5 = evaluate_strategy_versions("Strategy 5 (Reduced + Diff)", fixed_codes_5, "reduced_plus_diff")
                evaluation_results["reduced_plus_diff"] = result_5

            except Exception as eval_err:
                 print(f"  [Error] Unexpected error during evaluation: {eval_err}", file=sys.stderr)
                 traceback.print_exc()
                 evaluation_results["error"] = f"Unexpected evaluation error: {eval_err}"
            finally:
                 # Save persistent cache
                 final_cache_size = len(submission_evaluation_cache)
                 new_entries = final_cache_size - initial_cache_size
                 if new_entries > 0:
                     save_persistent_cache(cache_file, submission_evaluation_cache)
                     print(f"  [Cache] Saved {new_entries} new evaluation results to cache")
                 
                 if os.path.exists(eval_work_dir):
                     shutil.rmtree(eval_work_dir)

            # Store evaluation results in repair results file
            if "results" not in repair_results_data[target_problem_id_input]:
                repair_results_data[target_problem_id_input]["results"] = []
            
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
            needs_saving = True

        # --- Calculate and Print Success Rates for 5 Fair Strategies ---
        print("\n--- Final Evaluation Summary (5 Fair Strategies with K-Version Support) ---")
        if evaluated_submissions_count > 0:
            print(f"Total WA submissions evaluated: {evaluated_submissions_count}")
            print(f"Generation Strategy: Exactly {TOP_K} versions per strategy")
            print(f"Evaluation Strategy: Success if at least 1 version passes")
            
            rate_no_tc = (success_counts['no_tc'] / evaluated_submissions_count) * 100
            rate_orig_tc = (success_counts['orig_tc'] / evaluated_submissions_count) * 100
            rate_diff_only = (success_counts['diff_only'] / evaluated_submissions_count) * 100
            rate_reduced_tc = (success_counts['reduced_tc'] / evaluated_submissions_count) * 100
            rate_reduced_plus_diff = (success_counts['reduced_plus_diff'] / evaluated_submissions_count) * 100
            
            print(f"  Strategy 1 (Pure Baseline):         {success_counts['no_tc']}/{evaluated_submissions_count} ({rate_no_tc:.2f}%)")
            if success_submissions['no_tc']:
                print(f"    -> Successful IDs: {', '.join(success_submissions['no_tc'])}")
            
            print(f"  Strategy 2 (Original TC Full):      {success_counts['orig_tc']}/{evaluated_submissions_count} ({rate_orig_tc:.2f}%)")
            if success_submissions['orig_tc']:
                print(f"    -> Successful IDs: {', '.join(success_submissions['orig_tc'])}")
            
            print(f"  Strategy 3 (Test Diff Only):        {success_counts['diff_only']}/{evaluated_submissions_count} ({rate_diff_only:.2f}%)")
            if success_submissions['diff_only']:
                print(f"    -> Successful IDs: {', '.join(success_submissions['diff_only'])}")
            
            print(f"  Strategy 4 (Reduced TC Only):       {success_counts['reduced_tc']}/{evaluated_submissions_count} ({rate_reduced_tc:.2f}%)")
            if success_submissions['reduced_tc']:
                print(f"    -> Successful IDs: {', '.join(success_submissions['reduced_tc'])}")
            
            print(f"  Strategy 5 (Reduced + Diff):        {success_counts['reduced_plus_diff']}/{evaluated_submissions_count} ({rate_reduced_plus_diff:.2f}%)")
            if success_submissions['reduced_plus_diff']:
                print(f"    -> Successful IDs: {', '.join(success_submissions['reduced_plus_diff'])}")
            
            print(f"\n--- Performance Analysis ---")
            baseline_rate = rate_no_tc
            orig_improvement = rate_orig_tc - baseline_rate
            diff_improvement = rate_diff_only - baseline_rate
            reduced_improvement = rate_reduced_tc - baseline_rate
            combined_improvement = rate_reduced_plus_diff - baseline_rate
            
            print(f"  Original TC Full vs Baseline:    {orig_improvement:+.2f}% improvement")
            print(f"  Test Diff Only vs Baseline:      {diff_improvement:+.2f}% improvement")
            print(f"  Reduced TC Only vs Baseline:     {reduced_improvement:+.2f}% improvement")
            print(f"  Reduced + Diff vs Baseline:      {combined_improvement:+.2f}% improvement")
            
            # Strategy comparisons
            print(f"\n--- Strategy Comparisons ---")
            print(f"  Original TC Full vs Diff Only:    {rate_orig_tc - rate_diff_only:+.2f}% (full info vs diff)")
            print(f"  Reduced TC vs Diff Only:          {rate_reduced_tc - rate_diff_only:+.2f}% (simple case vs diff)")
            print(f"  Reduced + Diff vs Reduced Only:   {rate_reduced_plus_diff - rate_reduced_tc:+.2f}% (combined vs single)")
            
            # Find best strategy
            best_rate = max(rate_no_tc, rate_orig_tc, rate_diff_only, rate_reduced_tc, rate_reduced_plus_diff)
            best_strategies = []
            if rate_no_tc == best_rate: best_strategies.append("Pure Baseline")
            if rate_orig_tc == best_rate: best_strategies.append("Original TC Full")
            if rate_diff_only == best_rate: best_strategies.append("Test Diff Only")
            if rate_reduced_tc == best_rate: best_strategies.append("Reduced TC Only")
            if rate_reduced_plus_diff == best_rate: best_strategies.append("Reduced + Diff")
            
            print(f"  Best performing strategy(ies): {', '.join(best_strategies)} ({best_rate:.2f}%)")
            print(f"  K-Version approach: TOP_K={TOP_K}, success = at least 1 passes")
        else:
            print("No WA submissions were eligible for evaluation in this run.")
        # --- End Success Rate Calculation ---


        # --- Save Updated Results to Repair Results File --- 
        if needs_saving:
            print(f"\n--- Saving updated evaluation results to {RESULT_JSON_PATH} ---")
            if save_results_with_lock(RESULT_JSON_PATH, repair_results_data):
                print("[Success] Successfully saved updated results.")
            else:
                print(f"[Error] Failed to write updated results to {RESULT_JSON_PATH}", file=sys.stderr)
        else:
            print(f"\n--- No changes made to results in {RESULT_JSON_PATH} during this run. ---")

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

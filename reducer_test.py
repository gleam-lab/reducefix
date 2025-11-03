"""Test reducer script that loads data from lftbench dataset and performs test case reduction"""
import os
import sys
import argparse
import re
import glob
import time
import traceback
from typing import Optional, Tuple, List, Dict
import shutil
import json
import multiprocessing
import queue
import fcntl

try:
    import reduce as root_reducer
    from reduce import _parse_problem_id
except ImportError as e:
    print(f"[Error] Failed to import necessary modules ({e}). Ensure reduce.py is in the Python path.", file=sys.stderr)
    sys.exit(1)

# Configuration
AC_FILENAME = "ac.cpp"
WA_FILENAME_PREFIX = "wa_"
REDUCER_FILENAME = "reducer.py"
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
BASE_TESTCASE_PATH = os.path.join(SCRIPT_DIR, "lftbench", "tests")
MIN_INPUT_SIZE_KB = 1
MAX_WA_SUBMISSIONS = 10
SEARCH_MULTIPLIER = 2
RESULT_JSON_PATH = "result.json"
REDUCER_TIMEOUT = 60
LFTBENCH_PATH = os.path.join(SCRIPT_DIR, "lftbench")


class FileLocker:
    """File lock manager to prevent concurrent access to result.json"""
    
    def __init__(self, file_path: str, mode: str = 'r+', timeout: int = 30):
        self.file_path = file_path
        self.mode = mode
        self.timeout = timeout
        self.file_handle = None
        self.lock_acquired = False
    
    def __enter__(self):
        try:
            if 'w' in self.mode or 'a' in self.mode:
                os.makedirs(os.path.dirname(self.file_path) if os.path.dirname(self.file_path) else '.', exist_ok=True)
                if not os.path.exists(self.file_path):
                    with open(self.file_path, 'w') as f:
                        json.dump({}, f)
            
            self.file_handle = open(self.file_path, self.mode, encoding='utf-8')
            
            start_time = time.time()
            while time.time() - start_time < self.timeout:
                try:
                    fcntl.flock(self.file_handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
                    self.lock_acquired = True
                    return self.file_handle
                except (IOError, OSError):
                    time.sleep(0.1)
                    continue
            
            raise TimeoutError(f"Could not acquire lock for {self.file_path} within {self.timeout} seconds")
            
        except Exception as e:
            if self.file_handle:
                self.file_handle.close()
                self.file_handle = None
            raise e
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        if self.file_handle:
            try:
                if self.lock_acquired:
                    fcntl.flock(self.file_handle.fileno(), fcntl.LOCK_UN)
                self.file_handle.close()
            except Exception:
                pass


def load_results_with_lock(json_path: str) -> dict:
    """Load results from JSON file with file locking"""
    if not os.path.exists(json_path):
        return {}
    
    try:
        with FileLocker(json_path, 'r') as f:
            if os.path.getsize(json_path) > 0:
                f.seek(0)
                return json.load(f)
            return {}
    except (json.JSONDecodeError, TimeoutError, Exception):
        return {}


def save_results_with_lock(json_path: str, results_data: dict) -> bool:
    """Save results to JSON file with file locking and retry mechanism"""
    for attempt in range(5):
        try:
            with FileLocker(json_path, 'w') as f:
                f.seek(0)
                f.truncate()
                json.dump(results_data, f, indent=2, ensure_ascii=False)
                f.flush()
                os.fsync(f.fileno())
                print(f"[Success] Saved results to {json_path}")
                return True
        except (TimeoutError, Exception) as e:
            if attempt < 4:
                time.sleep(2 * (2 ** attempt))
                continue
            print(f"[Error] Failed to save after 5 attempts: {e}", file=sys.stderr)
            return False
    return False


def find_existing_wa_submission(problem_dir: str) -> List[Tuple[str, str]]:
    """Find existing wa_*.cpp files in the problem directory"""
    wa_pattern = os.path.join(problem_dir, f"{WA_FILENAME_PREFIX}*.cpp")
    wa_files = glob.glob(wa_pattern)
    found_submissions = []

    for f_path in wa_files:
        basename = os.path.basename(f_path)
        match = re.match(rf"^{WA_FILENAME_PREFIX}(\d+)\.cpp$", basename)
        if match:
            submission_id = match.group(1)
            found_submissions.append((f_path, submission_id))

    found_submissions.sort(key=lambda x: int(x[1]), reverse=True)
    return found_submissions


def save_wa_code(submission_id: str, source_code: str, artifact_dir: str) -> Optional[str]:
    """Save WA code to the specified directory"""
    wa_filename = f"{WA_FILENAME_PREFIX}{submission_id}.cpp"
    wa_path = os.path.join(artifact_dir, wa_filename)
    try:
        os.makedirs(artifact_dir, exist_ok=True)
        with open(wa_path, 'w', encoding='utf-8') as f:
            f.write(source_code)
        print(f"    [Info] Saved WA code for submission {submission_id} to: {wa_path}")
        return wa_path
    except IOError as e:
        print(f"    [Error] Failed to write WA code to {wa_path}: {e}", file=sys.stderr)
        return None


def load_ac_code_from_lftbench(problem_id: str, problem_dir: str) -> bool:
    """Load AC code from lftbench dataset"""
    print(f"[Info] Loading AC code from lftbench for {problem_id}...")
    
    ac_source_path = os.path.join(LFTBENCH_PATH, "data", "ground_truth", "cpp", f"{problem_id}.cpp")
    ac_target_path = os.path.join(problem_dir, AC_FILENAME)
    
    if not os.path.exists(ac_source_path):
        print(f"  [Error] AC code not found in lftbench: {ac_source_path}", file=sys.stderr)
        return False
    
    try:
        os.makedirs(problem_dir, exist_ok=True)
        shutil.copy2(ac_source_path, ac_target_path)
        print(f"[Success] Copied AC code from lftbench to: {ac_target_path}")
        return True
    except Exception as e:
        print(f"[Error] Failed to copy AC code: {e}", file=sys.stderr)
        return False


def load_wa_submissions_from_lftbench(problem_id: str, 
                                      exclude_ids: List[str],
                                      max_to_fetch: int) -> List[Tuple[str, str, str]]:
    """Load WA submissions from lftbench dataset"""
    print(f"[Info] Loading WA submissions from lftbench for {problem_id}...")
    
    cpp_metadata_path = os.path.join(LFTBENCH_PATH, "metadata", "cpp_submissions.jsonl")
    
    if not os.path.exists(cpp_metadata_path):
        print(f"  [Error] Metadata file not found: {cpp_metadata_path}", file=sys.stderr)
        return []
    
    found_submissions = []
    exclude_id_set = set(exclude_ids)
    
    try:
        with open(cpp_metadata_path, 'r', encoding='utf-8') as f:
            for line in f:
                if not line.strip():
                    continue
                    
                entry = json.loads(line)
                
                if entry.get('problem_id') != problem_id:
                    continue
                
                submission_id = str(entry.get('submission_id', ''))
                
                if submission_id in exclude_id_set:
                    continue
                
                wa_code_path = os.path.join(LFTBENCH_PATH, entry.get('wa_code_path', ''))
                original_input_path = os.path.join(LFTBENCH_PATH, entry.get('original_test_input_path', ''))
                
                if not os.path.exists(wa_code_path):
                    continue
                
                try:
                    with open(wa_code_path, 'r', encoding='utf-8') as code_file:
                        source_code = code_file.read()
                except Exception:
                    continue
                
                if not os.path.exists(original_input_path):
                    continue
                
                input_size = os.path.getsize(original_input_path)
                print(f"  Found submission {submission_id}: {input_size / 1024:.1f} KB input")
                
                found_submissions.append((submission_id, source_code, original_input_path))
                
                if max_to_fetch > 0 and len(found_submissions) >= max_to_fetch:
                    break
        
        print(f"[Info] Loaded {len(found_submissions)} WA submissions from lftbench")
        return found_submissions
        
    except Exception as e:
        print(f"[Error] Failed to load submissions from lftbench: {e}", file=sys.stderr)
        traceback.print_exc()
        return []


def select_best_submissions(all_results: List[Dict], target_count: int, problem_dir_name: str) -> List[Dict]:
    """Select best submissions (prioritize successful reductions, sorted by reduction ratio)"""
    if len(all_results) <= target_count:
        return all_results
        
    print(f"  [Selection] Selecting best {target_count} submissions from {len(all_results)} candidates...")
    
    successful = []
    failed = []
    
    for result in all_results:
        if result.get('status_code') == 200:
            successful.append(result)
        else:
            failed.append(result)
    
    print(f"    Successful reductions: {len(successful)}, Failed: {len(failed)}")
    
    successful_sorted = []
    for result in successful:
        original_size = result.get('original_size_bytes')
        reduced_size = result.get('reduced_size_bytes')
        if original_size and reduced_size and original_size > 0:
            reduction_ratio = (original_size - reduced_size) / original_size
            successful_sorted.append((reduction_ratio, result))
        else:
            successful_sorted.append((0.0, result))
    
    successful_sorted.sort(key=lambda x: x[0], reverse=True)
    successful = [result for _, result in successful_sorted]
    
    failed.sort(key=lambda x: int(x.get('submission_id', 0)), reverse=True)
    
    selected = []
    unselected = []
    
    selected.extend(successful[:target_count])
    unselected.extend(successful[target_count:])
    
    remaining_slots = target_count - len(selected)
    if remaining_slots > 0:
        selected.extend(failed[:remaining_slots])
        unselected.extend(failed[remaining_slots:])
    else:
        unselected.extend(failed)
    
    print(f"    Selected: {len(selected)} submissions ({sum(1 for r in selected if r.get('status_code') == 200)} successful)")
    
    if unselected:
        for result in unselected:
            submission_id = result.get('submission_id')
            artifact_dir = os.path.join(problem_dir_name, str(submission_id))
            if os.path.isdir(artifact_dir):
                try:
                    shutil.rmtree(artifact_dir)
                except Exception:
                    pass
    
    return selected


def run_reduction_with_timeout(q, submission_id, problem_id_input, base_testcase_path, artifact_dir):
    """Run reduction in a separate process"""
    try:
        result = root_reducer.reduce_submission(
            submission_id=submission_id,
            problem_id_input=problem_id_input,
            base_testcase_path=base_testcase_path,
            artifact_dir=artifact_dir
        )
        q.put(result)
    except Exception as e:
        q.put((500, f"Exception in reduction process: {e}", None, None, None, None))
        traceback.print_exc()


def main():
    parser = argparse.ArgumentParser(
        description="Test the reducer for a specific AtCoder problem using lftbench dataset.",
        epilog="Example: python reducer_test.py abc375c --model-tag qwen-coder7b"
    )
    parser.add_argument("problem_id", help="Target AtCoder problem ID (e.g., abc375c)")
    parser.add_argument("--model-tag", required=True, help="Tag for result file naming")
    parser.add_argument("--reducer-model", default="qwen-plus", help="LLM model name for reducer generation")
    parser.add_argument('--force', action='store_true', help='Force re-testing of submissions from lftbench')
    parser.add_argument('--retry-failed', action='store_true', help='Retry previously failed reduction attempts')
    parser.add_argument('--lftbench-path', default=None, help='Path to lftbench directory')
    parser.add_argument('--testcase-path', default=None, help='Path to test cases directory')
    args = parser.parse_args()
    
    global LFTBENCH_PATH, BASE_TESTCASE_PATH, RESULT_JSON_PATH
    if args.lftbench_path:
        LFTBENCH_PATH = os.path.abspath(args.lftbench_path)
    if args.testcase_path:
        BASE_TESTCASE_PATH = os.path.abspath(args.testcase_path)
    
    if not os.path.exists(LFTBENCH_PATH):
        print(f"[Error] lftbench directory not found: {LFTBENCH_PATH}", file=sys.stderr)
        sys.exit(1)
    
    if not os.path.exists(BASE_TESTCASE_PATH):
        print(f"[Error] Test cases directory not found: {BASE_TESTCASE_PATH}", file=sys.stderr)
        sys.exit(1)
    
    print(f"[Info] Using lftbench path: {LFTBENCH_PATH}")
    print(f"[Info] Using testcase path: {BASE_TESTCASE_PATH}")
    
    RESULT_JSON_PATH = f"result_{args.model_tag}.json"
    target_problem_id_input = args.problem_id.strip().lower()
    force_retest = args.force
    retry_failed = args.retry_failed

    UNIFIED_REDUCER_FILE = "reducer_results.json"
    
    try:
        import subprocess
        subprocess.run(
            [sys.executable, "consolidate_reducer_results.py", "--incremental"],
            capture_output=True, text=True, timeout=30
        )
    except Exception:
        pass
    
    skip_reduction = False
    
    if os.path.exists(UNIFIED_REDUCER_FILE):
        unified_data = load_results_with_lock(UNIFIED_REDUCER_FILE)
        if unified_data and target_problem_id_input in unified_data:
            unified_results = unified_data[target_problem_id_input].get("results", [])
            
            if len(unified_results) >= MAX_WA_SUBMISSIONS and not args.force:
                print(f"[Info] Found {len(unified_results)} existing results. Target achieved. Use --force to override.")
                skip_reduction = True
    
    results_data = load_results_with_lock(RESULT_JSON_PATH)

    print(f"\n--- Processing Problem: {target_problem_id_input} ---")
    parsed_ids = _parse_problem_id(target_problem_id_input)
    if not parsed_ids:
        print(f"[Error] Invalid problem ID format: '{target_problem_id_input}'", file=sys.stderr)
        sys.exit(1)
    contest_id, problem_letter = parsed_ids
    problem_dir_name = f"{contest_id}{problem_letter.lower()}"
    reducer_path = os.path.join(problem_dir_name, REDUCER_FILENAME)
    ac_path = os.path.join(problem_dir_name, AC_FILENAME)

    if not os.path.isdir(problem_dir_name):
        print(f"[Error] Problem directory '{problem_dir_name}' not found. Cannot proceed.", file=sys.stderr)
        sys.exit(1)

    if target_problem_id_input not in results_data:
        results_data[target_problem_id_input] = {"reducer_code": "", "results": []}
    elif "results" not in results_data[target_problem_id_input]:
        results_data[target_problem_id_input]["results"] = []

    if not os.path.exists(reducer_path):
        print(f"[Error] Reducer file '{reducer_path}' not found. Cannot proceed.", file=sys.stderr)
        save_results_with_lock(RESULT_JSON_PATH, results_data)
        sys.exit(1)
    
    try:
        with open(reducer_path, 'r', encoding='utf-8') as f:
            reducer_code_content = f.read()
        results_data[target_problem_id_input]["reducer_code"] = reducer_code_content
        results_data[target_problem_id_input].pop("error", None)
    except Exception as e:
        print(f"[Error] Failed to read reducer code: {e}", file=sys.stderr)
        sys.exit(1)

    problem_desc = results_data[target_problem_id_input].get("problem_description", "")
    if not problem_desc or (isinstance(problem_desc, str) and problem_desc.strip().startswith("# Error:")):
        problems_json_path = os.path.join(LFTBENCH_PATH, "metadata", "problems.json")
        
        if os.path.exists(problems_json_path):
            try:
                with open(problems_json_path, 'r', encoding='utf-8') as f:
                    problems_data = json.load(f)
                
                if target_problem_id_input in problems_data:
                    description = problems_data[target_problem_id_input].get("description", "")
                    if description:
                        results_data[target_problem_id_input]["problem_description"] = description
            except Exception:
                pass

    if not os.path.exists(ac_path):
        if not load_ac_code_from_lftbench(target_problem_id_input, problem_dir_name):
            print(f"[Error] Failed to load AC code from lftbench.", file=sys.stderr)
            sys.exit(1)

    try:
        with open(ac_path, 'r', encoding='utf-8') as f_ac:
            ac_content = f_ac.read()
        if "#include <atcoder/" in ac_content:
            print(f"[Error] AC file contains unsupported ACL include.", file=sys.stderr)
            sys.exit(1)
    except Exception as e:
        print(f"[Error] Failed to validate AC file: {e}", file=sys.stderr)
        sys.exit(1)

    local_wa_files = find_existing_wa_submission(problem_dir_name)
    local_ids = {str(sub_id) for _, sub_id in local_wa_files}

    existing_results_list = results_data[target_problem_id_input].get("results", [])
    processed_ids = {str(result['submission_id']) for result in existing_results_list if 'submission_id' in result}
    
    unified_ids = set()
    if os.path.exists(UNIFIED_REDUCER_FILE):
        unified_data = load_results_with_lock(UNIFIED_REDUCER_FILE)
        if unified_data and target_problem_id_input in unified_data:
            unified_results = unified_data[target_problem_id_input].get("results", [])
            unified_ids = {str(result['submission_id']) for result in unified_results if 'submission_id' in result}

    failed_submissions = []
    if retry_failed:
        for result in existing_results_list:
            submission_id = str(result.get('submission_id', ''))
            status_code = result.get('status_code', 200)
            if submission_id not in local_ids and status_code != 200:
                artifact_dir = os.path.join(problem_dir_name, submission_id)
                wa_code_path = result.get('wa_code_path')
                
                if not wa_code_path or not os.path.exists(wa_code_path):
                    default_wa_path = os.path.join(artifact_dir, f"{WA_FILENAME_PREFIX}{submission_id}.cpp")
                    if os.path.exists(default_wa_path):
                        wa_code_path = default_wa_path
                    else:
                        continue
                
                try:
                    with open(wa_code_path, 'r', encoding='utf-8') as f:
                        wa_code_content = f.read()
                    failed_submissions.append((submission_id, wa_code_content, wa_code_path))
                except Exception:
                    continue

    exclude_from_online_search = set(local_ids)
    num_to_fetch = 0

    if retry_failed and not force_retest:
        exclude_from_online_search.update(processed_ids)
        num_to_fetch = 0
    elif force_retest:
        non_local_processed_count = len(processed_ids - local_ids)
        
        if non_local_processed_count < MAX_WA_SUBMISSIONS:
            search_target = MAX_WA_SUBMISSIONS * SEARCH_MULTIPLIER
            num_to_fetch = max(0, search_target - non_local_processed_count)
        else:
            num_to_fetch = min(MAX_WA_SUBMISSIONS // 2, 5)
    else:
        exclude_from_online_search.update(processed_ids)
        exclude_from_online_search.update(unified_ids)
        
        all_existing_ids = unified_ids.union(processed_ids)
        non_local_existing_count = len(all_existing_ids - local_ids)
        if non_local_existing_count < MAX_WA_SUBMISSIONS:
            needed_new = MAX_WA_SUBMISSIONS - non_local_existing_count
            num_to_fetch = needed_new * SEARCH_MULTIPLIER
        else:
            num_to_fetch = 0

    if skip_reduction:
        print("[Success] Sufficient reduction results found. Processing completed.")
        sys.exit(0)

    if not retry_failed and not force_retest and num_to_fetch == 0 and not failed_submissions:
        print("[Success] Processing completed - no additional work required.")
        sys.exit(0)

    online_submissions_to_process = []
    if num_to_fetch > 0:
        lftbench_submissions = load_wa_submissions_from_lftbench(
            target_problem_id_input,
            list(exclude_from_online_search),
            num_to_fetch
        )
        online_submissions_to_process = [(sub_id, source_code) for sub_id, source_code, _ in lftbench_submissions]

    retry_reduction_results = []
    if failed_submissions:
        print(f"\n--- Retrying {len(failed_submissions)} Failed Submissions ---")
        for submission_id, wa_code_content, wa_code_path in failed_submissions:
            artifact_dir = os.path.dirname(wa_code_path)

            result_queue = multiprocessing.Queue()
            reduction_process = multiprocessing.Process(
                target=run_reduction_with_timeout,
                args=(result_queue, submission_id, target_problem_id_input, BASE_TESTCASE_PATH, artifact_dir)
            )

            start_time = time.time()
            reduction_process.start()
            reduction_process.join(timeout=REDUCER_TIMEOUT)
            duration = time.time() - start_time

            if reduction_process.is_alive():
                reduction_process.terminate()
                reduction_process.join()
                result_status = 408
                result_message = f"Reducer timed out after {REDUCER_TIMEOUT} seconds."
                original_size = reduced_size = failing_case_name = None
            else:
                try:
                    q_result = result_queue.get_nowait()
                    if isinstance(q_result, tuple) and len(q_result) >= 5:
                        result_status, result_message, original_size, reduced_size, failing_case_name = q_result[:5]
                    else:
                        result_status = 500
                        result_message = "Unexpected result format."
                        original_size = reduced_size = failing_case_name = None
                except (queue.Empty, ValueError):
                    result_status = 500
                    result_message = "Reduction process ended unexpectedly."
                    original_size = reduced_size = failing_case_name = None

            retry_reduction_results.append({
                "submission_id": str(submission_id),
                "status_code": result_status,
                "message": result_message,
                "original_size_bytes": original_size,
                "reduced_size_bytes": reduced_size,
                "failing_case_name": failing_case_name,
                "wa_code_path": wa_code_path,
                "execution_time_seconds": round(duration, 2)
            })
            time.sleep(1)

    new_reduction_results = []
    if online_submissions_to_process:
        print(f"\n--- Processing {len(online_submissions_to_process)} Online Submissions ---")
        for submission_id, source_code in online_submissions_to_process:
            artifact_dir = os.path.join(problem_dir_name, submission_id)
            os.makedirs(artifact_dir, exist_ok=True)

            final_wa_path = save_wa_code(submission_id, source_code, artifact_dir)
            if not final_wa_path:
                new_reduction_results.append({
                   "submission_id": submission_id,
                   "status_code": 500,
                   "message": "Failed to save WA code.",
                   "original_size_bytes": None,
                   "reduced_size_bytes": None,
                   "failing_case_name": None,
                   "wa_code_path": os.path.join(artifact_dir, f"{WA_FILENAME_PREFIX}{submission_id}.cpp"),
                   "execution_time_seconds": 0.0
                })
                continue

            result_queue = multiprocessing.Queue()
            reduction_process = multiprocessing.Process(
                target=run_reduction_with_timeout,
                args=(result_queue, submission_id, target_problem_id_input, BASE_TESTCASE_PATH, artifact_dir)
            )

            start_time = time.time()
            reduction_process.start()
            reduction_process.join(timeout=REDUCER_TIMEOUT)
            duration = time.time() - start_time

            if reduction_process.is_alive():
                reduction_process.terminate()
                reduction_process.join()
                result_status = 408
                result_message = f"Reducer timed out after {REDUCER_TIMEOUT} seconds."
                original_size = reduced_size = failing_case_name = None
            else:
                try:
                    q_result = result_queue.get_nowait()
                    if isinstance(q_result, tuple) and len(q_result) >= 5:
                        result_status, result_message, original_size, reduced_size, failing_case_name = q_result[:5]
                    else:
                        result_status = 500
                        result_message = "Unexpected result format."
                        original_size = reduced_size = failing_case_name = None
                except (queue.Empty, ValueError):
                    result_status = 500
                    result_message = "Reduction process ended unexpectedly."
                    original_size = reduced_size = failing_case_name = None

            new_reduction_results.append({
                "submission_id": str(submission_id),
                "status_code": result_status,
                "message": result_message,
                "original_size_bytes": original_size,
                "reduced_size_bytes": reduced_size,
                "failing_case_name": failing_case_name,
                "wa_code_path": final_wa_path,
                "execution_time_seconds": round(duration, 2)
            })
            time.sleep(1)

    all_new_results = new_reduction_results + retry_reduction_results
    
    if new_reduction_results and len(new_reduction_results) > MAX_WA_SUBMISSIONS:
        selected_new_results = select_best_submissions(new_reduction_results, MAX_WA_SUBMISSIONS, problem_dir_name)
        all_new_results = selected_new_results + retry_reduction_results
    
    ids_processed_this_run = {str(res['submission_id']) for res in all_new_results}

    final_results_list = []
    processed_in_final = set()

    for res in existing_results_list:
        sub_id = str(res.get('submission_id'))
        if sub_id in local_ids and sub_id not in processed_in_final:
            final_results_list.append(res)
            processed_in_final.add(sub_id)

    for res in existing_results_list:
        sub_id = str(res.get('submission_id'))
        if sub_id not in local_ids and sub_id not in ids_processed_this_run and sub_id not in processed_in_final:
            final_results_list.append(res)
            processed_in_final.add(sub_id)

    for res in all_new_results:
        sub_id = str(res.get('submission_id'))
        if sub_id not in processed_in_final:
            final_results_list.append(res)
            processed_in_final.add(sub_id)

    non_local_results = [res for res in final_results_list if str(res.get('submission_id')) not in local_ids]
    if len(non_local_results) > MAX_WA_SUBMISSIONS:
        selected_non_local = select_best_submissions(non_local_results, MAX_WA_SUBMISSIONS, problem_dir_name)
        local_results = [res for res in final_results_list if str(res.get('submission_id')) in local_ids]
        final_results_list = local_results + selected_non_local
    
    final_results_list.sort(key=lambda x: int(x.get('submission_id', 0)), reverse=True)

    results_data[target_problem_id_input]["results"] = final_results_list
    results_data[target_problem_id_input].pop("error", None)

    if save_results_with_lock(RESULT_JSON_PATH, results_data):
        print(f"\n[Success] Updated and saved results for {target_problem_id_input} to {RESULT_JSON_PATH}")
        
        if all_new_results:
            execution_times = [res.get('execution_time_seconds', 0) for res in all_new_results if res.get('execution_time_seconds') is not None]
            if execution_times:
                print(f"\n--- Execution Time Statistics ---")
                print(f"  Total submissions processed: {len(execution_times)}")
                print(f"  Total time: {sum(execution_times):.2f}s")
                print(f"  Average time: {sum(execution_times) / len(execution_times):.2f}s")
                print(f"  Successful: {sum(1 for res in all_new_results if res.get('status_code') == 200)}")
                print(f"  Timeouts: {sum(1 for res in all_new_results if res.get('status_code') == 408)}")
                print(f"  Errors: {sum(1 for res in all_new_results if res.get('status_code') not in [200, 408])}")
    else:
        print(f"[Error] Failed to write final results to {RESULT_JSON_PATH}", file=sys.stderr)


if __name__ == "__main__":
    main()

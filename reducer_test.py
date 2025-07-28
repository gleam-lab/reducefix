# reducer_test.py
import os
import sys
import argparse
import re
import glob
import time
import traceback
import requests # For scraping submissions page
from bs4 import BeautifulSoup # For parsing HTML
from typing import Optional, Tuple, List, Dict
import shutil
import json # Import json module
import multiprocessing # Add multiprocessing
import queue # Add queue
import fcntl # For file locking on Unix-like systems
import threading # For lock timeout handling

# --- Try importing necessary components ---
try:
    import tools
    from tools import (
                       load_session, # Import the new function
                       get_first_failed_case_info,
                       get_submission_source_code, # Import the new function
                       get_problem_description # Import the new function
                      )
    import reduce as root_reducer # Import the main orchestrator
    from reduce import _parse_problem_id # Import helper if needed, or copy
    print("[Info] Successfully imported required modules: tools, reduce.")
except ImportError as e:
    print(f"[Error] Failed to import necessary modules ({e}). Ensure tools.py and reduce.py are in the Python path.", file=sys.stderr)
    sys.exit(1)
except Exception as e:
    print(f"[Error] Unexpected error during imports: {e}", file=sys.stderr)
    traceback.print_exc()
    sys.exit(1)

# --- Configuration ---
AC_FILENAME = "ac.cpp"
WA_FILENAME_PREFIX = "wa_"
REDUCER_FILENAME = "reducer.py"
BASE_TESTCASE_PATH = "/home/barty/research/atcoder-testcases/test/" # Must match reduce.py/webapp.py
MIN_INPUT_SIZE_KB = 1 # Minimum size in KB for the input file of the first failed test case
SUBMISSIONS_PER_PAGE = 20 # Number of submissions listed per AtCoder page
MAX_PAGES_TO_SCRAPE = 200   # Limit scraping to avoid excessive requests
MAX_WA_SUBMISSIONS = 10 # Final target number of WA submissions to keep
SEARCH_MULTIPLIER = 2 # Search for 2x submissions, then select best ones
RESULT_JSON_PATH = "result.json" # Path for the output JSON
REDUCER_TIMEOUT = 60 # Timeout for the reducer process in seconds (as per paper)

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
                print(f"[Info] Loaded existing results from {json_path}")
                return results
            else:
                print(f"[Info] {json_path} is empty. Starting with empty results.")
                return {}
    except json.JSONDecodeError:
        print(f"[Warning] Failed to decode JSON from {json_path}. Starting with empty results.", file=sys.stderr)
        return {}
    except TimeoutError as e:
        print(f"[Warning] Lock timeout when loading {json_path}: {e}. Starting with empty results.", file=sys.stderr)
        return {}
    except Exception as e:
        print(f"[Warning] Failed to load results from {json_path}: {e}. Starting with empty results.", file=sys.stderr)
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
                print(f"[Success] Saved results to {json_path}")
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

def find_existing_wa_submission(problem_dir: str) -> List[Tuple[str, str]]:
    """Looks for all wa_*.cpp files and returns a list of (path, submission_id) tuples."""
    wa_pattern = os.path.join(problem_dir, f"{WA_FILENAME_PREFIX}*.cpp")
    wa_files = glob.glob(wa_pattern)
    found_submissions = []

    if not wa_files:
        # print("[Info] No existing wa_*.cpp files found locally.") # Reduced verbosity
        return found_submissions

    # print(f"[Info] Found {len(wa_files)} potential local wa_*.cpp files. Checking IDs...") # Reduced verbosity
    for f_path in wa_files:
        basename = os.path.basename(f_path)
        match = re.match(rf"^{WA_FILENAME_PREFIX}(\d+)\.cpp$", basename)
        if match:
            submission_id = match.group(1)
            # print(f"  -> Found local WA: {f_path} (ID: {submission_id})") # Reduced verbosity
            found_submissions.append((f_path, submission_id))
        # else: # Reduced verbosity
             # print(f"  -> Skipping file (does not match pattern): {f_path}")

    # Sort by submission ID (as string might be sufficient, or convert to int)
    found_submissions.sort(key=lambda x: int(x[1]), reverse=True)
    # print(f"[Info] Successfully identified {len(found_submissions)} local WA submissions.") # Reduced verbosity
    return found_submissions

def get_input_file_size(base_path: str, contest_id: str, problem_letter: str, case_name: str) -> Optional[int]:
    """Gets the size of the specified input file in bytes."""
    # Construct path like /base/abc330/D/in/test_05
    # Ensure case name doesn't accidentally contain .txt
    if case_name.lower().endswith('.txt'):
        case_name = case_name[:-4]
    input_path = os.path.join(base_path, contest_id, problem_letter.upper(), "in", case_name)
    try:
        if os.path.exists(input_path):
            size = os.path.getsize(input_path)
            # print(f"  [Info] Size of input file '{input_path}': {size} bytes") # Reduce verbosity
            return size
        else:
            print(f"  [Warning] Input file not found for size check: {input_path}", file=sys.stderr)
            return None
    except Exception as e:
        print(f"  [Error] Failed to get size for input file {input_path}: {e}", file=sys.stderr)
        return None

def save_wa_code(submission_id: str, source_code: str, artifact_dir: str) -> Optional[str]:
    """Saves the WA source code to the specified artifact directory.
       Returns the full path to the saved file, or None on error.
    """
    wa_filename = f"{WA_FILENAME_PREFIX}{submission_id}.cpp"
    wa_path = os.path.join(artifact_dir, wa_filename)
    try:
        os.makedirs(artifact_dir, exist_ok=True) # Ensure artifact dir exists
        with open(wa_path, 'w', encoding='utf-8') as f:
            f.write(source_code)
        print(f"    [Info] Saved WA code for submission {submission_id} to: {wa_path}")
        return wa_path
    except IOError as e:
        print(f"    [Error] Failed to write WA code to {wa_path}: {e}", file=sys.stderr)
        return None

def find_and_save_ac_code(contest_id: str, problem_id_str: str, problem_dir: str, session: requests.Session) -> bool:
    """Finds the latest AC C++ submission *without AtCoder Library includes* and saves its code as ac.cpp.
       Returns True on success, False on failure.
    """
    print(f"[Info] Searching for a recent AC C++ submission (without ACL) for {problem_id_str}...")
    submissions_url = f"https://atcoder.jp/contests/{contest_id}/submissions"
    params = {
        "f.Task": problem_id_str, # e.g., abc330_d
        "f.LanguageName": "C++",
        "f.Status": "AC",
        "page": "1" # We only need the first page for the latest AC
    }

    try:
        # print(f"  - Sending request to: {submissions_url} with params {params}") # Reduced verbosity
        resp = session.get(submissions_url, params=params, timeout=15)
        # print(f"  - Received response status code: {resp.status_code}") # Reduced verbosity
        resp.raise_for_status()
        soup = BeautifulSoup(resp.text, 'lxml')

        table = soup.select_one('table')
        if not table:
            print(f"  [Error] No submission table found on AC search page.", file=sys.stderr)
            return False

        rows = table.select('tbody > tr')
        if not rows:
            print(f"  [Info] No AC C++ submissions found on the first page for {problem_id_str}.")
            return False

        # Iterate through submissions on the page to find a suitable one
        for row_idx, row in enumerate(rows):
            # print(f"    -- Processing row {row_idx+1}/{len(rows)} --") # Reduced verbosity
            cells = row.find_all('td')
            if len(cells) < 4:
                # print("       -> Skipping row: Malformed (less than 4 cells).") # Reduced verbosity
                continue

            details_link = cells[-1].find('a')
            if not details_link or 'href' not in details_link.attrs:
                # print("       -> Skipping row: No details link found.") # Reduced verbosity
                continue

            href = details_link['href']
            match = re.search(r'/submissions/(\d+)', href)
            if not match:
                # print(f"       -> Skipping row: Could not extract submission ID from link: {href}") # Reduced verbosity
                continue

            ac_submission_id = match.group(1)
            submission_detail_url = f"https://atcoder.jp/contests/{contest_id}/submissions/{ac_submission_id}"
            print(f"       -> Checking AC submission ID: {ac_submission_id}")

            # Fetch its source code using the tool function
            ac_source_code = get_submission_source_code(submission_detail_url, session)

            if not ac_source_code:
                print(f"         -> Source code fetch FAILED for {ac_submission_id}.")
                continue # Try next submission
            # else: # Reduced verbosity
                # print(f"         -> Source code fetch SUCCEEDED for {ac_submission_id} (length: {len(ac_source_code)}).")

            # Check for AtCoder Library include
            if "#include <atcoder/" in ac_source_code:
                print(f"         -> Skipping {ac_submission_id}: Uses AtCoder Library.")
                continue # Try next submission

            # Found a suitable submission
            print(f"         -> Found suitable AC code (ID: {ac_submission_id})! Saving...")
            # Save the code as ac.cpp
            target_path = os.path.join(problem_dir, AC_FILENAME)
            try:
                os.makedirs(problem_dir, exist_ok=True)
                with open(target_path, 'w', encoding='utf-8') as f:
                    f.write(ac_source_code)
                print(f"[Success] Saved suitable AC code from submission {ac_submission_id} to: {target_path}")
                return True # Found and saved, exit function
            except IOError as e:
                print(f"[Error] Failed to write AC code to {target_path}: {e}", file=sys.stderr)
                return False # Fatal error during saving, stop searching

        # If the loop finishes without finding a suitable submission
        print(f"  [Info] Finished checking all {len(rows)} rows on page 1. No suitable AC C++ submission (without AtCoder Library) found.")
        return False # Indicate failure to find a suitable AC code

    except requests.exceptions.RequestException as e:
        print(f"  [Error] Network error searching for AC submissions: {e}", file=sys.stderr)
        return False
    except Exception as e:
        print(f"  [Error] Error processing AC submissions page: {e}", file=sys.stderr)
        traceback.print_exc()
        return False

def find_suitable_wa_submission_online(contest_id: str,
                                     problem_id_str: str,
                                     problem_letter: str,
                                     session: requests.Session,
                                     exclude_ids: List[str], # Now expects list of strings
                                     max_to_fetch: int) -> List[Tuple[str, str]]:
    """
    Searches online submissions for WA C++ submissions meeting criteria.
    - Without AtCoder Library includes.
    - Input file size >= MIN_INPUT_SIZE_KB.
    - First failing case status is exactly 'WA'.
    - Submission ID is not in exclude_ids.
    - Fetches up to max_to_fetch submissions.
    Returns a list of (submission_id, source_code) tuples.
    """
    print(f"[Info] Searching online for up to {max_to_fetch if max_to_fetch > 0 else 'unlimited'} suitable WA C++ submissions (no ACL, >= {MIN_INPUT_SIZE_KB}KB, not in excluded list) for {problem_id_str}...")
    if max_to_fetch > MAX_WA_SUBMISSIONS:
        print(f"  [Strategy] Will process all {max_to_fetch} found submissions, then select best {MAX_WA_SUBMISSIONS} based on reduction effectiveness.")
    min_bytes = MIN_INPUT_SIZE_KB * 1024
    found_submissions = []
    exclude_id_set = set(exclude_ids) # Use set for faster lookups
    print(f"  - Will exclude {len(exclude_id_set)} IDs from online search results.")

    task_screen_name = problem_id_str
    current_submission_cnt = 0
    for page in range(1, MAX_PAGES_TO_SCRAPE + 1):
        # Check if we have fetched enough ONLY if max_to_fetch is a positive limit
        if max_to_fetch > 0 and len(found_submissions) >= max_to_fetch:
            print(f"  [Info] Reached target of {max_to_fetch} new online submissions. Stopping search.")
            break

        submissions_url = f"https://atcoder.jp/contests/{contest_id}/submissions"
        params = {
            "f.Task": task_screen_name,
            "f.LanguageName": "C++", # Filter for C++ variants
            "f.Status": "WA",
            "page": str(page)
        }
        print(f"  Scraping page {page}/{MAX_PAGES_TO_SCRAPE} (Found {len(found_submissions)}/{max_to_fetch if max_to_fetch > 0 else 'unlimited'} so far): {submissions_url} ...")

        try:
            resp = session.get(submissions_url, params=params, timeout=20)
            resp.raise_for_status()
            soup = BeautifulSoup(resp.text, 'lxml')

            table = soup.select_one('table')
            if not table:
                print(f"  [Warning] No submission table found on page {page}.")
                break

            rows = table.select('tbody > tr')
            if not rows:
                 print(f"  [Info] No submissions found on page {page}.")
                 break

            # print(f"    Found {len(rows)} submissions on page {page}. Checking...") # Reduced verbosity
            submissions_checked_on_page = 0
            submissions_added_on_page = 0
            for row_idx, row in enumerate(rows):
                # Check again inside loop if we reached the fetch limit
                if max_to_fetch > 0 and len(found_submissions) >= max_to_fetch:
                     # print(f"    [Info] Reached target {max_to_fetch} during page processing. Stopping page scan.") # Reduced verbosity
                     break

                cells = row.find_all('td')
                if len(cells) < 4: continue

                details_link = cells[-1].find('a')
                if not details_link or 'href' not in details_link.attrs: continue
                href = details_link['href']
                match = re.search(r'/submissions/(\d+)', href)
                if not match: continue
                submission_id = match.group(1)
                submissions_checked_on_page += 1

                # --- Check 1: Already Excluded? ---
                if submission_id in exclude_id_set:
                     # print(f"      -> Skipping submission {submission_id}: ID is in the exclusion list.") # Reduced verbosity
                     continue

                # print(f"      Checking submission ID: {submission_id} (Not excluded)...") # Reduced verbosity

                # --- Check 2: Fetch Source & Check for ACL ---
                submission_detail_url = f"https://atcoder.jp/contests/{contest_id}/submissions/{submission_id}"
                wa_source_code = get_submission_source_code(submission_detail_url, session)
                if not wa_source_code:
                     print(f"        -> Failed to fetch source code for {submission_id}.")
                     continue
                if "#include <atcoder/" in wa_source_code:
                     print(f"        -> Skipping submission {submission_id}: Uses AtCoder Library.")
                     continue

                # --- Check 3: Get Failing Case Info & Status ---
                case_name, case_status, _, _ = get_first_failed_case_info(submission_detail_url, session)
                if case_name is None or case_status != 'WA':
                     print(f"        -> Skipping submission {submission_id}: Status is '{case_status or 'unknown'}' (expected WA) or details unavailable.")
                     continue

                # --- Check 4: Input Size ---
                input_size_bytes = get_input_file_size(BASE_TESTCASE_PATH, contest_id, problem_letter, case_name)
                if input_size_bytes is None:
                     print(f"        -> Skipping submission {submission_id}: Failed to get input size for case {case_name}.")
                     continue
                if input_size_bytes < min_bytes:
                     print(f"        -> Skipping submission {submission_id}: Input size {input_size_bytes / 1024:.1f} KB is too small for case {case_name} (min: {MIN_INPUT_SIZE_KB} KB).")
                     continue

                # --- Suitable Submission Found! ---
                current_submission_cnt += 1
                print(f"        -> Found suitable No.{current_submission_cnt} online WA submission {submission_id}! (Status: {case_status}, Case: {case_name}, Size: {input_size_bytes / 1024:.1f} KB)")
                found_submissions.append((submission_id, wa_source_code))
                submissions_added_on_page += 1
                # No need to add to exclude_id_set here, as it was constructed before the loop

            # print(f"    Finished page {page}. Checked {submissions_checked_on_page}, Added {submissions_added_on_page}. Total found: {len(found_submissions)}/{max_to_fetch if max_to_fetch > 0 else 'unlimited'}") # Reduced verbosity

        except requests.exceptions.RequestException as e:
            print(f"  [Error] Network error scraping page {page}: {e}", file=sys.stderr)
            break
        except Exception as e:
            print(f"  [Error] Error processing submissions page {page}: {e}", file=sys.stderr)
            traceback.print_exc()
            break

        time.sleep(0.5) # Delay between pages

    if not found_submissions and max_to_fetch != 0: # Only print if we were trying to fetch
        print(f"[Info] Finished scraping {MAX_PAGES_TO_SCRAPE} pages. No suitable new online WA submissions found meeting the criteria.")
    elif found_submissions:
         print(f"[Info] Finished scraping. Found {len(found_submissions)} suitable online WA submissions for processing.")
    return found_submissions

# --- Function to select best submissions after processing ---
def select_best_submissions(all_results: List[Dict], target_count: int, problem_dir_name: str) -> List[Dict]:
    """
    Select the best submissions from all processed results.
    Priority:
    1. Successful reductions (status_code == 200) - sorted by reduction effectiveness
    2. Failed reductions - sorted by submission ID (newer first)
    
    Also cleans up artifact directories for unselected submissions.
    """
    if len(all_results) <= target_count:
        print(f"  [Selection] Have {len(all_results)} results, target {target_count}. Keeping all.")
        return all_results
        
    print(f"  [Selection] Selecting best {target_count} submissions from {len(all_results)} candidates...")
    
    # Separate successful and failed reductions
    successful = []
    failed = []
    
    for result in all_results:
        if result.get('status_code') == 200:
            successful.append(result)
        else:
            failed.append(result)
    
    print(f"    Successful reductions: {len(successful)}, Failed: {len(failed)}")
    
    # Sort successful by reduction effectiveness (higher reduction ratio is better)
    successful_sorted = []
    for result in successful:
        original_size = result.get('original_size_bytes')
        reduced_size = result.get('reduced_size_bytes')
        if original_size and reduced_size and original_size > 0:
            reduction_ratio = (original_size - reduced_size) / original_size
            successful_sorted.append((reduction_ratio, result))
        else:
            # If size info is missing, put at end with 0 ratio
            successful_sorted.append((0.0, result))
    
    successful_sorted.sort(key=lambda x: x[0], reverse=True)  # Higher ratio first
    successful = [result for _, result in successful_sorted]
    
    # Show top successful submissions for info
    if successful_sorted:
        print(f"    Top successful reductions:")
        for i, (ratio, result) in enumerate(successful_sorted[:min(5, len(successful_sorted))]):
            original = result.get('original_size_bytes')
            reduced = result.get('reduced_size_bytes')
            print(f"      {i+1}. Submission {result.get('submission_id')}: {original}→{reduced} bytes ({ratio:.1%} reduction)")
            if i >= 4:  # Show max 5
                break
    
    # Sort failed by submission ID (newer first)
    failed.sort(key=lambda x: int(x.get('submission_id', 0)), reverse=True)
    
    # Select best ones
    selected = []
    unselected = []
    
    # First take successful ones
    selected.extend(successful[:target_count])
    unselected.extend(successful[target_count:])
    
    # Then take failed ones if we need more
    remaining_slots = target_count - len(selected)
    if remaining_slots > 0:
        selected.extend(failed[:remaining_slots])
        unselected.extend(failed[remaining_slots:])
    else:
        unselected.extend(failed)
    
    print(f"    Selected: {len(selected)} submissions ({sum(1 for r in selected if r.get('status_code') == 200)} successful)")
    
    # Clean up unselected submissions' artifacts
    if unselected:
        print(f"    Cleaning up {len(unselected)} unselected submissions...")
        for result in unselected:
            submission_id = result.get('submission_id')
            artifact_dir = os.path.join(problem_dir_name, str(submission_id))
            if os.path.isdir(artifact_dir):
                try:
                    shutil.rmtree(artifact_dir)
                    print(f"      Removed: {artifact_dir}")
                except Exception as e:
                    print(f"      [Warning] Failed to remove {artifact_dir}: {e}", file=sys.stderr)
    
    return selected

# --- Function to run reduction in a separate process ---
def run_reduction_with_timeout(q, submission_id, problem_id_input, base_testcase_path, artifact_dir):
    """Runs the reduction process and puts the result in a queue."""
    try:
        # Note: timeout argument is removed here
        result = root_reducer.reduce_submission(
            submission_id=submission_id,
            problem_id_input=problem_id_input,
            base_testcase_path=base_testcase_path,
            artifact_dir=artifact_dir
        )
        q.put(result)
    except Exception as e:
        # Capture any exception during the reduction itself
        q.put((500, f"Exception in reduction process: {e}", None, None, None, None)) # Match expected tuple structure slightly
        traceback.print_exc()

# --- Main Execution ---
def main():
    parser = argparse.ArgumentParser(description="Test the reducer for a specific AtCoder problem and record results.")
    parser.add_argument("problem_id", help="Target AtCoder problem ID (e.g., abc123a)")
    parser.add_argument("--model-tag", required=True, help="Tag for result file naming (e.g., 'qwen-coder7b' -> result_qwen-coder7b.json)")
    parser.add_argument("--reducer-model", default="qwen-plus", help="LLM model name for reducer generation (default: qwen-plus)")
    parser.add_argument('--force', action='store_true', help='Force re-testing of online WA submissions, even if already in results.json. Does NOT re-test local wa_*.cpp files.')
    parser.add_argument('--retry-failed', action='store_true', help='Retry previously failed reduction attempts (status_code != 200). Takes priority over --force for failed submissions.')
    args = parser.parse_args()
    # 修复：使用 model_tag 参数来与 evaluate_repair.py 保持一致
    global RESULT_JSON_PATH
    RESULT_JSON_PATH = f"result_{args.model_tag}.json"
    target_problem_id_input = args.problem_id.strip().lower()
    force_retest = args.force
    retry_failed = args.retry_failed

    # --- Ensure Unified Reducer Results File is Up-to-Date ---
    UNIFIED_REDUCER_FILE = "reducer_results.json"
    
    # Auto-consolidate results to ensure unified file is current
    print(f"[Info] Ensuring unified reducer results file is up-to-date...")
    try:
        import subprocess
        consolidate_result = subprocess.run(
            [sys.executable, "consolidate_reducer_results.py", "--incremental"],
            capture_output=True, text=True, timeout=30
        )
        if consolidate_result.returncode == 0:
            print(f"[Info] Successfully updated {UNIFIED_REDUCER_FILE}")
        else:
            print(f"[Warning] Failed to update {UNIFIED_REDUCER_FILE}: {consolidate_result.stderr}")
    except Exception as e:
        print(f"[Warning] Could not run consolidation script: {e}")
    
    # --- Check Unified Reducer Results File ---
    skip_reduction = False
    
    if os.path.exists(UNIFIED_REDUCER_FILE):
        print(f"[Info] Checking unified reducer results file: {UNIFIED_REDUCER_FILE}")
        unified_data = load_results_with_lock(UNIFIED_REDUCER_FILE)
        if unified_data and target_problem_id_input in unified_data:
            unified_results = unified_data[target_problem_id_input].get("results", [])
            successful_results = [r for r in unified_results if r.get("status_code") == 200]
            
            # Skip reduction only if we already have enough results (unless forced)
            if len(unified_results) >= MAX_WA_SUBMISSIONS:
                print(f"[Info] Found {len(unified_results)} existing reduction results in {UNIFIED_REDUCER_FILE}")
                print(f"      - {len(successful_results)} successful")
                print(f"      - {len(unified_results) - len(successful_results)} failed")
                print(f"[Info] Target of {MAX_WA_SUBMISSIONS} results already achieved. Skipping reduction step.")
                print(f"[Info] Use --force to override this check and redo reduction.")
                if not args.force:
                    skip_reduction = True
            elif len(unified_results) > 0:
                print(f"[Info] Found {len(unified_results)} existing reduction results in {UNIFIED_REDUCER_FILE}")
                print(f"      - {len(successful_results)} successful")
                print(f"      - {len(unified_results) - len(successful_results)} failed")
                print(f"[Info] Still need {MAX_WA_SUBMISSIONS - len(unified_results)} more results to reach target of {MAX_WA_SUBMISSIONS}.")
                print(f"[Info] Will continue with reduction process to add more results.")
    
    # --- Load Existing Results ---
    results_data = load_results_with_lock(RESULT_JSON_PATH)

    # 1. Parse Problem ID and check directories/files
    print(f"\n--- Processing Problem: {target_problem_id_input} ---")
    parsed_ids = _parse_problem_id(target_problem_id_input)
    if not parsed_ids:
        print(f"[Error] Invalid problem ID format: '{target_problem_id_input}'", file=sys.stderr)
        sys.exit(1)
    contest_id, problem_letter = parsed_ids
    problem_dir_name = f"{contest_id}{problem_letter.lower()}" # e.g., abc123a
    reducer_path = os.path.join(problem_dir_name, REDUCER_FILENAME)
    ac_path = os.path.join(problem_dir_name, AC_FILENAME)

    # Ensure problem directory exists
    if not os.path.isdir(problem_dir_name):
        print(f"[Error] Problem directory '{problem_dir_name}' not found. Cannot proceed.", file=sys.stderr)
        # Optionally update JSON with error? For now, just exit.
        sys.exit(1)

    # --- Initialize/Update Problem Entry in Results ---
    if target_problem_id_input not in results_data:
        results_data[target_problem_id_input] = {"reducer_code": "", "results": []}
        print(f"[Info] Initializing results entry for {target_problem_id_input}.")
    elif "results" not in results_data[target_problem_id_input]: # Handle case where entry exists but no 'results' key
        results_data[target_problem_id_input]["results"] = []
        print(f"[Info] 'results' key missing for {target_problem_id_input}, initializing.")


    # Check and Read/Update reducer code
    if not os.path.exists(reducer_path):
         print(f"[Error] Reducer file '{reducer_path}' not found. Cannot proceed.", file=sys.stderr)
         results_data[target_problem_id_input]["reducer_code"] = "# Error: Reducer file not found"
         results_data[target_problem_id_input]["error"] = "Reducer file not found"
         # Save error state before exiting?
         if not save_results_with_lock(RESULT_JSON_PATH, results_data):
             print(f"[Error] Failed to save error state to {RESULT_JSON_PATH}", file=sys.stderr)
         sys.exit(1)
    else:
        try:
            with open(reducer_path, 'r', encoding='utf-8') as f:
                reducer_code_content = f.read()
            # Only update if different? For simplicity, just update always for now.
            results_data[target_problem_id_input]["reducer_code"] = reducer_code_content
            results_data[target_problem_id_input].pop("error", None) # Clear error if reducer is readable now
            print(f"[Info] Read reducer code from: {reducer_path}")
        except Exception as e:
            print(f"[Error] Failed to read reducer code file '{reducer_path}': {e}", file=sys.stderr)
            results_data[target_problem_id_input]["reducer_code"] = f"# Error reading reducer source: {e}"
            results_data[target_problem_id_input]["error"] = f"Failed to read reducer code: {e}"

    # --- Fetch and Store Problem Description (if missing or contains error) ---
    problem_desc = results_data[target_problem_id_input].get("problem_description", "")
    needs_fetch = (
        not problem_desc or
        (isinstance(problem_desc, str) and problem_desc.strip().startswith("# Error:"))
    )

    if needs_fetch:
        print("[Info] Problem description missing or invalid in results. Fetching...")
        problem_url = f"https://atcoder.jp/contests/{contest_id}/tasks/{contest_id}_{problem_letter.lower()}"
        session = tools.load_session() # Get session for fetching
        if session:
            description = tools.get_problem_description(problem_url, session)
            if description:
                results_data[target_problem_id_input]["problem_description"] = description
                print("[Info] Successfully fetched and stored problem description.")
            else:
                print("[Warning] Failed to fetch problem description.", file=sys.stderr)
                results_data[target_problem_id_input]["problem_description"] = "# Error: Failed to fetch description on retry"
        else:
            print("[Warning] Failed to get session for fetching problem description.", file=sys.stderr)
            results_data[target_problem_id_input]["problem_description"] = "# Error: Failed to get session for fetching description on retry"

    # Check AC file (fetch if missing, validate content)
    if not os.path.exists(ac_path):
        print(f"[Info] AC file '{ac_path}' not found. Attempting to fetch...")
        session = tools.load_session()
        if not session:
             print("[Error] Cannot fetch AC code: Failed to load session. Cannot proceed.", file=sys.stderr)
             results_data[target_problem_id_input]["error"] = "AC fetch failed (session load error)"
             # Save error state
             if not save_results_with_lock(RESULT_JSON_PATH, results_data):
                 print(f"[Error] Failed to save error state to {RESULT_JSON_PATH}", file=sys.stderr)
             sys.exit(1)

        if not find_and_save_ac_code(contest_id, f"{contest_id}_{problem_letter.lower()}", problem_dir_name, session):
            print(f"[Error] Failed to find and save AC code for {target_problem_id_input}. Cannot proceed.", file=sys.stderr)
            results_data[target_problem_id_input]["error"] = "AC fetch failed (suitable code not found/saved)"
             # Save error state
            if not save_results_with_lock(RESULT_JSON_PATH, results_data):
                print(f"[Error] Failed to save error state to {RESULT_JSON_PATH}", file=sys.stderr)
            sys.exit(1)

    print(f"[Info] Found AC file: '{ac_path}'")
    try:
        with open(ac_path, 'r', encoding='utf-8') as f_ac:
            ac_content = f_ac.read()
        if "#include <atcoder/" in ac_content:
            print(f"[Error] Existing AC file '{ac_path}' contains '#include <atcoder/'. Cannot proceed.", file=sys.stderr)
            results_data[target_problem_id_input]["error"] = "AC file contains unsupported ACL include"
            # Save error state
            if not save_results_with_lock(RESULT_JSON_PATH, results_data):
                print(f"[Error] Failed to save error state to {RESULT_JSON_PATH}", file=sys.stderr)
            sys.exit(1)
        else:
            print(f"[Info] AC file '{ac_path}' content validated.")
    except Exception as e:
        print(f"[Error] Failed to read or validate AC file '{ac_path}': {e}", file=sys.stderr)
        results_data[target_problem_id_input]["error"] = f"Failed to read/validate AC file: {e}"
        # Save error state
        if not save_results_with_lock(RESULT_JSON_PATH, results_data):
            print(f"[Error] Failed to save error state to {RESULT_JSON_PATH}", file=sys.stderr)
        sys.exit(1)

    # 2. Identify Local WA Submissions (These will be skipped)
    local_wa_files = find_existing_wa_submission(problem_dir_name) # Returns list of (path, id)
    local_ids = {str(sub_id) for _, sub_id in local_wa_files} # Store IDs as strings
    if local_ids:
        print(f"[Info] Found {len(local_ids)} local WA submission files. These will *always* be skipped.")
    else:
        print(f"[Info] No local WA submission files found.")

    # 3. Get existing processed submission IDs from JSON for this problem
    existing_results_list = results_data[target_problem_id_input].get("results", [])
    processed_ids = {str(result['submission_id']) for result in existing_results_list if 'submission_id' in result} # Store IDs as strings
    print(f"[Info] Found {len(processed_ids)} submission results recorded in {RESULT_JSON_PATH}.")
    
    # 3.5. Also get IDs from unified reducer results file to avoid reprocessing
    unified_ids = set()
    if os.path.exists(UNIFIED_REDUCER_FILE):
        unified_data = load_results_with_lock(UNIFIED_REDUCER_FILE)
        if unified_data and target_problem_id_input in unified_data:
            unified_results = unified_data[target_problem_id_input].get("results", [])
            unified_ids = {str(result['submission_id']) for result in unified_results if 'submission_id' in result}
            print(f"[Info] Found {len(unified_ids)} submission IDs in unified reducer results file.")
            
            # Show overlap/difference for transparency
            overlap_ids = processed_ids.intersection(unified_ids)
            only_in_unified = unified_ids - processed_ids
            only_in_specific = processed_ids - unified_ids
            if overlap_ids:
                print(f"      - {len(overlap_ids)} IDs are in both files")
            if only_in_unified:
                print(f"      - {len(only_in_unified)} IDs only in unified file")
            if only_in_specific:
                print(f"      - {len(only_in_specific)} IDs only in specific result file")

    # 4. Identify failed submissions that need retry
    failed_submissions = []
    if retry_failed:
        print("[Info] --retry-failed specified: Identifying previously failed reduction attempts...")
        for result in existing_results_list:
            submission_id = str(result.get('submission_id', ''))
            status_code = result.get('status_code', 200)  # Default to success if not recorded
            # Skip local IDs and successful submissions
            if submission_id not in local_ids and status_code != 200:
                # Check if we have the necessary files to retry
                artifact_dir = os.path.join(problem_dir_name, submission_id)
                wa_code_path = result.get('wa_code_path')
                
                # Try to find WA code in artifact directory or use recorded path
                if not wa_code_path or not os.path.exists(wa_code_path):
                    # Try default path
                    default_wa_path = os.path.join(artifact_dir, f"{WA_FILENAME_PREFIX}{submission_id}.cpp")
                    if os.path.exists(default_wa_path):
                        wa_code_path = default_wa_path
                    else:
                        print(f"    [Warning] Skipping failed submission {submission_id}: WA code file not found")
                        continue
                
                # Read WA code to include in retry processing
                try:
                    with open(wa_code_path, 'r', encoding='utf-8') as f:
                        wa_code_content = f.read()
                    failed_submissions.append((submission_id, wa_code_content, wa_code_path))
                    print(f"    Found failed submission {submission_id} (status: {status_code}): {result.get('message', 'Unknown error')}")
                except Exception as e:
                    print(f"    [Warning] Skipping failed submission {submission_id}: Could not read WA code: {e}")
                    continue
        
        print(f"[Info] Found {len(failed_submissions)} failed submissions to retry.")

    # 5. Determine IDs to exclude from online search and how many to fetch
    # ==============================================================
    # CORE LOGIC FOR --force AND --retry-failed HANDLING
    # ==============================================================
    exclude_from_online_search = set(local_ids) # START with local IDs, they are ALWAYS excluded.
    num_to_fetch = 0 # How many submissions to fetch online. Set to > 0 if fetching is needed.

    if retry_failed and not force_retest:
        print("[Info] --retry-failed specified: Will retry failed submissions only, no new online fetching.")
        # When retrying failed, we don't fetch new submissions
        exclude_from_online_search.update(processed_ids)
        num_to_fetch = 0
    elif force_retest:
        print("[Info] --force specified: Will re-test online submissions, excluding local files. Previously recorded online results may be re-tested and replaced.")
        # When forcing, we DON'T add processed_ids to the exclude list.
        # This allows find_suitable_wa_submission_online to find them again if they meet criteria.
        non_local_processed_count = len(processed_ids - local_ids)
        
        if non_local_processed_count < MAX_WA_SUBMISSIONS:
            # Still need more submissions to reach target, so search for additional ones
            search_target = MAX_WA_SUBMISSIONS * SEARCH_MULTIPLIER
            needed_new = max(0, search_target - non_local_processed_count)
            num_to_fetch = needed_new
            print(f"   (Force mode: Final target: {MAX_WA_SUBMISSIONS}, Search target: {search_target}, Already processed (non-local): {non_local_processed_count}, Will fetch: {num_to_fetch})")
        else:
            # Already have enough, but in force mode, allow limited re-testing of some submissions
            # Fetch a smaller number to refresh/replace some existing results
            num_to_fetch = min(MAX_WA_SUBMISSIONS // 2, 5)  # Fetch at most 5 submissions for refresh
            print(f"   (Force mode: Final target: {MAX_WA_SUBMISSIONS}, Already processed (non-local): {non_local_processed_count}, Will fetch: {num_to_fetch} - refreshing some existing results)")
            print(f"   [Info] In force mode, will search for {num_to_fetch} submissions to potentially replace existing ones with better reduction results.")
    else:
        print("[Info] No --force or --retry-failed: Will fetch new online submissions, excluding local files and previously recorded results.")
        # When NOT forcing, ADD processed IDs (from both files) to the exclude list.
        exclude_from_online_search.update(processed_ids)
        exclude_from_online_search.update(unified_ids)  # Also exclude unified file IDs
        
        # Calculate how many *new* results we need to reach the target,
        # Use unified file count as the primary reference since it's the most complete
        all_existing_ids = unified_ids.union(processed_ids)
        non_local_existing_count = len(all_existing_ids - local_ids)
        if non_local_existing_count < MAX_WA_SUBMISSIONS:
            # We need more to reach the final target
            needed_new = MAX_WA_SUBMISSIONS - non_local_existing_count
            # But search for more to have selection options (use multiplier only for the new ones needed)
            search_for_new = needed_new * SEARCH_MULTIPLIER
            num_to_fetch = search_for_new
            print(f"   (Final target: {MAX_WA_SUBMISSIONS}, Already have (non-local): {non_local_existing_count}, Need {needed_new} more, Will search for: {num_to_fetch})")
        else:
            # Already have enough or more than target
            num_to_fetch = 0
            print(f"   (Final target: {MAX_WA_SUBMISSIONS}, Already have (non-local): {non_local_existing_count}, Need to fetch: {num_to_fetch})")
    # ==============================================================

    # Early exit if unified results are sufficient
    if skip_reduction:
        print("[Success] Sufficient reduction results found in unified file. Processing completed.")
        sys.exit(0)

    print(f"[Info] Final exclusion list for online search contains {len(exclude_from_online_search)} IDs.")

    # Debug: Show early exit conditions
    print(f"[Debug] Early exit check - retry_failed: {retry_failed}, force_retest: {force_retest}, num_to_fetch: {num_to_fetch}, failed_submissions count: {len(failed_submissions)}")

    # Early exit if no work needed in normal mode
    if not retry_failed and not force_retest and num_to_fetch == 0 and not failed_submissions:
        print("[Info] No new online submissions needed based on target and existing results.")
        # Use the combined count from both files
        if 'non_local_existing_count' in locals():
            print(f"[Info] Target achieved: {non_local_existing_count}/{MAX_WA_SUBMISSIONS} non-local submissions found across all result files")
        else:
            # Fallback for older logic paths
            non_local_count = len(processed_ids - local_ids)
            print(f"[Info] Target achieved: {non_local_count}/{MAX_WA_SUBMISSIONS} non-local submissions found in {RESULT_JSON_PATH}")
        print("[Success] Processing completed - no additional work required.")
        sys.exit(0)
    else:
        print(f"[Debug] Early exit NOT triggered - continuing with processing...")
        if retry_failed:
            print(f"[Debug] - retry_failed is True")
        if force_retest:
            print(f"[Debug] - force_retest is True") 
        if num_to_fetch > 0:
            print(f"[Debug] - num_to_fetch is {num_to_fetch} (> 0)")
        if failed_submissions:
            print(f"[Debug] - failed_submissions has {len(failed_submissions)} items")

    online_submissions_to_process : List[Tuple[str, str]] = [] # (id, source_code)
    if num_to_fetch > 0:
        print(f"[Info] Two-stage strategy: Searching for {num_to_fetch} submissions, will select best {MAX_WA_SUBMISSIONS} after reduction...")
        session = tools.load_session() # Get session for online search
        if session:
            problem_id_str = f"{contest_id}_{problem_letter.lower()}"
            # Pass the final exclude list and the calculated number to fetch
            online_submissions_to_process = find_suitable_wa_submission_online(
                contest_id, problem_id_str, problem_letter, session,
                list(exclude_from_online_search),
                num_to_fetch
            )
        else:
            print("[Warning] Failed to get session, cannot search for online WA submissions.")
    elif num_to_fetch == 0 and force_retest:
         # This case is unlikely unless MAX_WA_SUBMISSIONS is 0, but handle for completeness
         print("[Info] No online submissions will be fetched as MAX_WA_SUBMISSIONS target is 0 or less.")


    # 5. Process failed submissions first (if --retry-failed is specified)
    # ==============================================================
    # RETRY FAILED SUBMISSIONS LOGIC
    # ==============================================================
    retry_reduction_results = [] # Store retry results
    if failed_submissions:
        print(f"\n--- Starting Retry Processing for {len(failed_submissions)} Failed Submissions ---")
        retry_count = 0
        for submission_id, wa_code_content, wa_code_path in failed_submissions:
            retry_count += 1
            print(f"\n--- [{retry_count}/{len(failed_submissions)}] Retrying Reduction for Failed Submission ID: {submission_id} ---")
            
            artifact_dir = os.path.dirname(wa_code_path)
            print(f"    Problem Dir: {problem_dir_name}")
            print(f"    Artifact Dir: {artifact_dir}")
            print(f"    AC Code: {ac_path}")
            print(f"    WA Code: {wa_code_path} (Retry)")

            # Call the main reduction function from reduce.py using multiprocessing
            result_queue = multiprocessing.Queue()
            reduction_process = multiprocessing.Process(
                target=run_reduction_with_timeout,
                args=(result_queue, submission_id, target_problem_id_input, BASE_TESTCASE_PATH, artifact_dir)
            )

            print(f"    Starting retry reduction process for {submission_id} with timeout {REDUCER_TIMEOUT}s...")
            start_time = time.time()
            reduction_process.start()
            reduction_process.join(timeout=REDUCER_TIMEOUT)
            end_time = time.time()
            duration = end_time - start_time
            print(f"    Retry reduction process finished or timed out after {duration:.2f}s.")

            if reduction_process.is_alive():
                print(f"    [Timeout] Retry reduction process for {submission_id} exceeded timeout ({REDUCER_TIMEOUT}s). Terminating.")
                reduction_process.terminate()
                reduction_process.join() # Wait for termination
                result_status = 408 # Request Timeout
                result_message = f"Reducer timed out after {REDUCER_TIMEOUT} seconds (retry)."
                original_size = None
                reduced_size = None
                failing_case_name = None # Timeout likely means we don't know the case
            else:
                try:
                    # Handle potential tuple structure variations gracefully
                    q_result = result_queue.get_nowait()
                    if isinstance(q_result, tuple) and len(q_result) >= 5:
                        result_status = q_result[0]
                        result_message = q_result[1]
                        original_size = q_result[2]
                        reduced_size = q_result[3]
                        failing_case_name = q_result[4]
                        print(f"    Retry Result Status: {result_status} - {result_message}")
                    else:
                        print(f"    [Error] Unexpected result structure from queue for retry {submission_id}: {q_result}", file=sys.stderr)
                        result_status = 500
                        result_message = "Unexpected result format from reduction process (retry)."
                        original_size = None
                        reduced_size = None
                        failing_case_name = None

                except queue.Empty:
                    print(f"    [Error] Retry reduction process for {submission_id} finished but no result was found in queue.", file=sys.stderr)
                    result_status = 500 # Internal Server Error
                    result_message = "Reduction process ended unexpectedly without returning a result (retry)."
                    original_size = None
                    reduced_size = None
                    failing_case_name = None
                except ValueError as e:
                    print(f"    [Error] Could not unpack result from queue for retry {submission_id}: {e}. Result: {q_result}", file=sys.stderr)
                    result_status = 500
                    result_message = f"Could not unpack result from queue (retry): {e}"
                    original_size = None
                    reduced_size = None
                    failing_case_name = None

            # Store retry result
            retry_reduction_results.append({
                "submission_id": str(submission_id), # Ensure ID is string
                "status_code": result_status,
                "message": result_message,
                "original_size_bytes": original_size,
                "reduced_size_bytes": reduced_size,
                "failing_case_name": failing_case_name,
                "wa_code_path": wa_code_path, # Use existing path
                "execution_time_seconds": round(duration, 2)  # Record execution time for analysis
            })
            time.sleep(1) # Add a small delay
    # ==============================================================

    # 6. Process ONLY the fetched online submissions
    # ==============================================================
    # PROCESSING LOGIC (Only processes `online_submissions_to_process`)
    # ==============================================================
    online_ids_to_process = {str(sub_id) for sub_id, _ in online_submissions_to_process} # Ensure IDs are strings
    online_sources = {str(sub_id): source for sub_id, source in online_submissions_to_process} # Ensure IDs are strings
    new_reduction_results = [] # Store results from THIS run

    if not online_ids_to_process:
        print("\n[Info] No online submissions to process in this run.")
    else:
        print(f"\n--- Starting Reduction Processing for {len(online_ids_to_process)} Online Submissions ---")
        processed_count_this_run = 0
        # Sort IDs for consistent processing order
        sorted_online_ids = sorted(list(online_ids_to_process), key=int, reverse=True)

        for submission_id in sorted_online_ids: # Loop ONLY over online IDs found in this run
            processed_count_this_run += 1
            print(f"\n--- [{processed_count_this_run}/{len(online_ids_to_process)}] Running Reduction for Submission ID: {submission_id} --- ")

            source_code = online_sources.get(submission_id)
            if source_code is None:
                 print(f"    [Error] Internal inconsistency: Source code not found for online ID {submission_id}. Skipping.", file=sys.stderr)
                 continue

            artifact_dir = os.path.join(problem_dir_name, submission_id) # ID is already string
            os.makedirs(artifact_dir, exist_ok=True) # Ensure artifact dir exists

            # Save the fetched WA code to the artifact dir
            final_wa_path = save_wa_code(submission_id, source_code, artifact_dir)
            if not final_wa_path:
                print(f"    [Error] Failed to save WA code for {submission_id} to {artifact_dir}. Skipping reduction.", file=sys.stderr)
                new_reduction_results.append({
                   "submission_id": submission_id,
                   "status_code": 500,
                   "message": "Failed to save WA code to artifact directory.",
                   "original_size_bytes": None,
                   "reduced_size_bytes": None,
                   "failing_case_name": None,
                   "wa_code_path": os.path.join(artifact_dir, f"{WA_FILENAME_PREFIX}{submission_id}.cpp"), # Record attempted path
                   "execution_time_seconds": 0.0  # No execution time for save failure
                })
                continue

            print(f"    Problem Dir: {problem_dir_name}")
            print(f"    Artifact Dir: {artifact_dir}")
            print(f"    AC Code: {ac_path}")
            print(f"    WA Code: {final_wa_path} (Fetched Online)")

            # Call the main reduction function from reduce.py using multiprocessing
            result_queue = multiprocessing.Queue()
            reduction_process = multiprocessing.Process(
                target=run_reduction_with_timeout,
                args=(result_queue, submission_id, target_problem_id_input, BASE_TESTCASE_PATH, artifact_dir)
            )

            print(f"    Starting reduction process for {submission_id} with timeout {REDUCER_TIMEOUT}s...")
            start_time = time.time()
            reduction_process.start()
            reduction_process.join(timeout=REDUCER_TIMEOUT)
            end_time = time.time()
            duration = end_time - start_time
            print(f"    Reduction process finished or timed out after {duration:.2f}s.")


            if reduction_process.is_alive():
                print(f"    [Timeout] Reduction process for {submission_id} exceeded timeout ({REDUCER_TIMEOUT}s). Terminating.")
                reduction_process.terminate()
                reduction_process.join() # Wait for termination
                result_status = 408 # Request Timeout
                result_message = f"Reducer timed out after {REDUCER_TIMEOUT} seconds."
                original_size = None
                reduced_size = None
                failing_case_name = None # Timeout likely means we don't know the case
            else:
                # print(f"    Reduction process for {submission_id} completed within timeout.") # Reduced verbosity
                try:
                    # Handle potential tuple structure variations gracefully
                    q_result = result_queue.get_nowait()
                    if isinstance(q_result, tuple) and len(q_result) >= 5:
                        result_status = q_result[0]
                        result_message = q_result[1]
                        original_size = q_result[2]
                        reduced_size = q_result[3]
                        # Index 4 might be reduced content or failing case name depending on reduce.py - assume failing case for now based on previous context
                        failing_case_name = q_result[4]
                        print(f"    Result Status: {result_status} - {result_message}") # Log summary
                    else:
                        # If tuple is not as expected, log error and default values
                        print(f"    [Error] Unexpected result structure from queue for {submission_id}: {q_result}", file=sys.stderr)
                        result_status = 500
                        result_message = "Unexpected result format from reduction process."
                        original_size = None
                        reduced_size = None
                        failing_case_name = None

                except queue.Empty:
                    print(f"    [Error] Reduction process for {submission_id} finished but no result was found in queue.", file=sys.stderr)
                    result_status = 500 # Internal Server Error
                    result_message = "Reduction process ended unexpectedly without returning a result."
                    original_size = None
                    reduced_size = None
                    failing_case_name = None
                except ValueError as e: # Catch potential unpacking errors if tuple structure differs
                    print(f"    [Error] Could not unpack result from queue for {submission_id}: {e}. Result: {q_result}", file=sys.stderr)
                    result_status = 500
                    result_message = f"Could not unpack result from queue: {e}"
                    original_size = None
                    reduced_size = None
                    failing_case_name = None


            # Store result from this run (including execution time)
            new_reduction_results.append({
                "submission_id": str(submission_id), # Ensure ID is string
                "status_code": result_status,
                "message": result_message,
                "original_size_bytes": original_size,
                "reduced_size_bytes": reduced_size,
                "failing_case_name": failing_case_name,
                "wa_code_path": final_wa_path, # Record the actual path used
                "execution_time_seconds": round(duration, 2)  # Record execution time for analysis
            })
            time.sleep(1) # Add a small delay
    # ==============================================================


    # 7. Select Best Submissions (if we have more than target)
    # ==============================================================
    # SELECTION LOGIC (Choose best submissions from all processed)
    # ==============================================================
    # Combine all results from this run (new online results + retry results)
    all_new_results = new_reduction_results + retry_reduction_results
    
    # Apply selection logic for new online submissions
    if new_reduction_results and len(new_reduction_results) > MAX_WA_SUBMISSIONS:
        print(f"\n--- Selecting Best Submissions from {len(new_reduction_results)} New Online Submissions ---")
        selected_new_results = select_best_submissions(new_reduction_results, MAX_WA_SUBMISSIONS, problem_dir_name)
        print(f"Selected {len(selected_new_results)} best submissions from {len(new_reduction_results)} candidates.")
        
        # Update all_new_results with selected ones
        all_new_results = selected_new_results + retry_reduction_results
    
    # Get IDs processed in this run (all IDs from this run after selection)
    ids_processed_this_run = {str(res['submission_id']) for res in all_new_results} # Ensure strings

    # 8. Update Results and Save to JSON
    # ==============================================================
    # SAVING LOGIC (Preserves local results, updates/adds online results and retries)
    # ==============================================================

    # Build the final list of results for this problem
    final_results_list = []
    processed_in_final = set() # Keep track of IDs added to avoid duplicates

    # Add existing results for local files FIRST (these were never processed this run)
    for res in existing_results_list:
        sub_id = str(res.get('submission_id')) # Ensure string
        if sub_id in local_ids:
             # Only add if not somehow already added (safety check)
             if sub_id not in processed_in_final:
                final_results_list.append(res)
                processed_in_final.add(sub_id)

    # Add existing results that are NOT local AND were NOT processed in this run
    # These are old online results that we are keeping because --force was not used OR
    # they weren't fetched again even with --force (e.g., didn't meet criteria anymore).
    for res in existing_results_list:
        sub_id = str(res.get('submission_id')) # Ensure string
        if sub_id not in local_ids and sub_id not in ids_processed_this_run:
            # Only add if not already added (e.g., wasn't mistakenly identified as local earlier)
            if sub_id not in processed_in_final:
                final_results_list.append(res)
                processed_in_final.add(sub_id)

    # Add the new results from THIS run (online results + retry results)
    # This will overwrite any previous results for the same ID if --force or --retry-failed was used,
    # because those old results would have been excluded by the `sub_id not in ids_processed_this_run` check above.
    for res in all_new_results:
         sub_id = str(res.get('submission_id')) # Ensure string
         # Add if it wasn't somehow added already (should always be true, but good practice)
         if sub_id not in processed_in_final:
             final_results_list.append(res)
             processed_in_final.add(sub_id)


    # Apply final selection if we have too many non-local results
    non_local_results = [res for res in final_results_list if str(res.get('submission_id')) not in local_ids]
    if len(non_local_results) > MAX_WA_SUBMISSIONS:
        print(f"\n--- Final Selection: Reducing {len(non_local_results)} non-local results to {MAX_WA_SUBMISSIONS} ---")
        selected_non_local = select_best_submissions(non_local_results, MAX_WA_SUBMISSIONS, problem_dir_name)
        
        # Rebuild final list with local results + selected non-local results
        local_results = [res for res in final_results_list if str(res.get('submission_id')) in local_ids]
        final_results_list = local_results + selected_non_local
        
        print(f"Final selection: {len(final_results_list)} total results ({len(local_ids)} local + {len(selected_non_local)} online)")
    
    # Sort final list by submission ID (numeric, descending) for consistency
    final_results_list.sort(key=lambda x: int(x.get('submission_id', 0)), reverse=True)

    results_data[target_problem_id_input]["results"] = final_results_list
    # Clear any top-level error if we managed to process or determine no processing needed
    # This assumes errors during processing are captured within the specific result entry's message/status code.
    results_data[target_problem_id_input].pop("error", None)

    # ==============================================================


    if save_results_with_lock(RESULT_JSON_PATH, results_data):
        print(f"\n[Success] Updated and saved results for {target_problem_id_input} to {RESULT_JSON_PATH}")
        
        # --- Print execution time statistics for this run ---
        if all_new_results:
            execution_times = [res.get('execution_time_seconds', 0) for res in all_new_results if res.get('execution_time_seconds') is not None]
            if execution_times:
                avg_time = sum(execution_times) / len(execution_times)
                min_time = min(execution_times)
                max_time = max(execution_times)
                total_time = sum(execution_times)
                print(f"\n--- Execution Time Statistics (This Run) ---")
                print(f"  Total submissions processed: {len(execution_times)}")
                if new_reduction_results:
                    print(f"    New online submissions: {len(new_reduction_results)}")
                if retry_reduction_results:
                    print(f"    Retried failed submissions: {len(retry_reduction_results)}")
                print(f"  Total execution time: {total_time:.2f}s")
                print(f"  Average execution time: {avg_time:.2f}s")
                print(f"  Min execution time: {min_time:.2f}s")
                print(f"  Max execution time: {max_time:.2f}s")
                
                # Count by status
                success_times = [res.get('execution_time_seconds', 0) for res in all_new_results 
                               if res.get('status_code') == 200 and res.get('execution_time_seconds') is not None]
                timeout_count = sum(1 for res in all_new_results if res.get('status_code') == 408)
                error_count = sum(1 for res in all_new_results if res.get('status_code') not in [200, 408])
                
                print(f"  Successful reductions: {len(success_times)}")
                print(f"  Timeouts: {timeout_count}")
                print(f"  Other errors: {error_count}")
                
                if success_times:
                    avg_success_time = sum(success_times) / len(success_times)
                    print(f"  Average time for successful reductions: {avg_success_time:.2f}s")
                    
                # Show retry-specific statistics if any retries were performed
                if retry_reduction_results:
                    retry_success_count = sum(1 for res in retry_reduction_results if res.get('status_code') == 200)
                    print(f"\n--- Retry Statistics ---")
                    print(f"  Failed submissions retried: {len(retry_reduction_results)}")
                    print(f"  Successful after retry: {retry_success_count}")
                    print(f"  Retry success rate: {(retry_success_count / len(retry_reduction_results) * 100):.1f}%")
    else:
        print(f"[Error] Failed to write final results to {RESULT_JSON_PATH}", file=sys.stderr)


if __name__ == "__main__":
    main()
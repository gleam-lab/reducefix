import requests
import http.cookiejar
import time
import bs4
import onlinejudge._implementation.utils as utils
import sys
import traceback
import os
import glob
import threading
from typing import Optional, Any
import json
import re
from bs4 import BeautifulSoup
import random
import markdownify

# --- Cache Configuration ---
CACHE_DIR = ".atcoder_cache"
PROBLEMS_CACHE_SUBDIR = "problems"
SUBMISSIONS_CACHE_SUBDIR = "submissions"

# Ensure base cache directory exists on module load
try:
    os.makedirs(CACHE_DIR, exist_ok=True)
except Exception as e:
    print(f"[Cache Warning] Failed to create base cache directory {CACHE_DIR}: {e}", file=sys.stderr)

# --- Cache Helper Functions ---

def _get_problem_cache_path(contest_id: str, problem_id: str) -> str:
    """Gets the cache path for problem details JSON."""
    # problem_id likely contains underscore, e.g., abc330_d
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, problem_id, "details.json")

def _get_submission_source_cache_path(submission_id: str) -> str:
    """Gets the cache path for submission source code text.
       Note: Using .txt instead of .cpp as it might not always be C++.
    """
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "source.txt")

def _get_submission_results_cache_path(submission_id: str) -> str:
    """Gets the cache path for submission results JSON (case_name, status, ac_count)."""
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "results.json")

def _get_submission_status_cache_path(submission_id: str) -> str:
    """Gets the cache path for submission status text."""
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "status.txt")

def _get_problem_description_md_cache_path(contest_id: str, task_screen_name: str) -> str:
    """Gets the cache path for the problem description Markdown."""
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, task_screen_name, "description.md")

def _get_problem_description_html_cache_path(contest_id: str, task_screen_name: str) -> str:
    """Gets the cache path for the problem description HTML."""
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, task_screen_name, "description.html")

def read_cache(cache_path: str, is_json: bool = True) -> Optional[Any]:
    """Reads data from a cache file.
       Returns parsed data (dict if JSON, str if not) or None if not found/error.
    """
    if not os.path.exists(cache_path):
        return None
    try:
        with open(cache_path, 'r', encoding='utf-8') as f:
            if is_json:
                data = json.load(f)
                print(f"  [Cache Hit] Read JSON from: {cache_path}")
                return data
            else:
                data = f.read()
                print(f"  [Cache Hit] Read text from: {cache_path}")
                return data
    except Exception as e:
        print(f"  [Cache Warning] Failed to read cache file {cache_path}: {e}", file=sys.stderr)
        # Attempt to remove potentially corrupted cache file
        try:
            os.remove(cache_path)
            print(f"    [Cache Info] Removed potentially corrupted cache file: {cache_path}")
        except OSError as remove_err:
            print(f"    [Cache Warning] Failed to remove corrupted cache file {cache_path}: {remove_err}", file=sys.stderr)
        return None

def write_cache(cache_path: str, data: Any, is_json: bool = True):
    """Writes data to a cache file.
       Creates necessary directories.
    """
    try:
        os.makedirs(os.path.dirname(cache_path), exist_ok=True)
        with open(cache_path, 'w', encoding='utf-8') as f:
            if is_json:
                json.dump(data, f, ensure_ascii=False, indent=2)
                print(f"  [Cache Miss] Wrote JSON to: {cache_path}")
            else:
                f.write(str(data))
                print(f"  [Cache Miss] Wrote text to: {cache_path}")
    except Exception as e:
        print(f"  [Cache Warning] Failed to write cache file {cache_path}: {e}", file=sys.stderr)

# --- Cookie Management (Moved from tutor.py) ---
COOKIE_DIR_PATH = "/home/barty/.local/share/online-judge-tools" # 包含 Cookie 文件的目录
AVAILABLE_COOKIE_FILES = []
current_cookie_index = 0
cookie_load_lock = threading.Lock() # 用于线程安全的锁

def load_cookie_files():
    """在指定目录中查找所有 .cookie.jar 文件。"""
    global AVAILABLE_COOKIE_FILES
    cookie_pattern = os.path.join(COOKIE_DIR_PATH, '*-cookie.jar')
    # 使用 with cookie_load_lock 确保加载过程的原子性
    with cookie_load_lock:
        AVAILABLE_COOKIE_FILES = glob.glob(cookie_pattern)
        if not AVAILABLE_COOKIE_FILES:
            print(f"警告: 在目录 '{COOKIE_DIR_PATH}' 中未找到任何 '*-cookie.jar' 文件。评测和爬取功能可能无法使用认证。")
        else:
            AVAILABLE_COOKIE_FILES.sort() # 排序以获得可预测的轮换顺序
            print(f"[Cookie] 找到 {len(AVAILABLE_COOKIE_FILES)} 个 Cookie 文件: {', '.join(os.path.basename(f) for f in AVAILABLE_COOKIE_FILES)}") 

def get_next_cookie_path() -> Optional[str]: # Added type hint
    """从列表中获取下一个 Cookie 文件路径，并循环使用。"""
    global current_cookie_index
    with cookie_load_lock: # 在访问共享资源时使用锁
        if not AVAILABLE_COOKIE_FILES:
            return None # 没有找到 Cookie 文件

        # 确保索引在范围内，如果超出则回绕
        if current_cookie_index >= len(AVAILABLE_COOKIE_FILES):
            current_cookie_index = 0

        cookie_path = AVAILABLE_COOKIE_FILES[current_cookie_index]
        print(f"[Cookie] 使用 Cookie: {os.path.basename(cookie_path)} (Index: {current_cookie_index})")
        current_cookie_index += 1
        return cookie_path
# --- End Cookie Management ---

# --- New Session Loader Function ---
def load_session() -> Optional[requests.Session]:
    """Loads a requests.Session using the next available cookie file in a round-robin fashion.
    
    Returns:
        A requests.Session object with cookies loaded, or None if no cookies are available
        or loading fails.
    """
    cookie_path = get_next_cookie_path()
    if not cookie_path:
        print("[Error] load_session: No cookie files available via get_next_cookie_path(). Cannot create authenticated session.", file=sys.stderr)
        # Decide if you want to return a non-authenticated session or None.
        # Returning None seems safer if authentication is expected.
        return None 
    
    session = load_session_with_cookie_file(cookie_path)
    # load_session_with_cookie_file already prints success/error messages
    return session
# --- End New Session Loader Function ---

def load_session_with_cookie_file(cookie_path: Optional[str]) -> Optional[requests.Session]: # Added Optional type hint
    """显式加载 cookie 文件到 requests Session 中"""
    if cookie_path is None:
         print("[Session] Warning: cookie_path is None, creating session without cookies.")
         return requests.Session() # Return a session without cookies if path is None
    if not os.path.exists(cookie_path):
         print(f"[Session] Error: Cookie file not found at {cookie_path}", file=sys.stderr)
         return None # Indicate failure to load session due to missing file
         
    session = requests.Session()
    jar = http.cookiejar.LWPCookieJar(cookie_path)
    try:
        jar.load(ignore_discard=True, ignore_expires=True)
        session.cookies = jar
        print(f"[Session] Successfully loaded cookies from {os.path.basename(cookie_path)}")
        return session
    except Exception as e:
         print(f"[Session] Error loading cookie file {cookie_path}: {e}", file=sys.stderr)
         return None # Indicate failure

def get_first_failed_case_info(submission_url, session):
    """访问提交详情页面(使用认证 session)并解析第一个非 AC 测试用例、源代码以及总 AC 用例数
       Uses cache for submission results and source code.
    """
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    错误：无法从 URL 中提取 submission_id: {submission_url}", file=sys.stderr)
        return None, None, None, None
    submission_id = submission_id_match.group(1)

    # --- Cache Check for Results (case_name, status, ac_count) ---
    results_cache_path = _get_submission_results_cache_path(submission_id)
    cached_results = read_cache(results_cache_path, is_json=True)
    
    # --- Cache Check for Source Code ---
    source_cache_path = _get_submission_source_cache_path(submission_id)
    cached_source = read_cache(source_cache_path, is_json=False)

    # If both results and source are cached, return them directly
    if cached_results is not None and cached_source is not None:
        # Ensure cached_results is a dictionary with expected keys before unpacking
        if isinstance(cached_results, dict) and all(k in cached_results for k in ['case_name', 'status', 'ac_count']):
             print(f"  [Cache Hit] Returning cached results and source for submission {submission_id}")
             return cached_results['case_name'], cached_results['status'], cached_source, cached_results['ac_count']
        else:
             print(f"  [Cache Warning] Corrupted results cache for {submission_id}, proceeding to fetch.", file=sys.stderr)
             # Attempt to remove corrupted cache
             try: os.remove(results_cache_path) 
             except OSError: pass
             cached_results = None # Force refetch
    elif cached_results is not None and cached_source is None:
         print(f"  [Cache Info] Results cache hit, but source cache miss for submission {submission_id}. Will fetch page anyway.")
         # We need to fetch the page again to get the source, but we know the results already.
         # Let the fetch proceed, but we'll use cached_results if parsing results fails later?
         # Or maybe just force refetch both? Let's force refetch for simplicity.
         cached_results = None # Force refetch results too if source is missing
    elif cached_source is not None and cached_results is None:
         print(f"  [Cache Info] Source cache hit, but results cache miss for submission {submission_id}. Will fetch page anyway.")
         cached_source = None # Force refetch source too if results are missing

    # --- Network Fetch (Cache Miss for either results or source) ---
    print(f"Fetching details page for submission {submission_id} (Cache Miss)")
    time.sleep(0.5) # Be polite
    source_code = None 
    ac_count = 0 
    first_failed_case_name = None
    first_failed_case_status = None
    try:
        resp = utils.request('GET', submission_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        soup = bs4.BeautifulSoup(resp.text, 'lxml')

        # Find the source code
        code_pre = soup.select_one('pre#submission-code')
        if code_pre:
            source_code = code_pre.get_text()
            # --- Write Source Code to Cache --- 
            write_cache(source_cache_path, source_code, is_json=False)
            # ----------------------------------
        else:
            print(f"    警告：在 {submission_url} 页面找不到源代码元素 (pre#submission-code)。", file=sys.stderr)
            # If source fetch fails, we can't really cache results either? Return failure.
            return None, None, None, None 

        # Find the results table
        target_table = None
        all_tables = soup.find_all('table')
        for i, table in enumerate(all_tables):
            headers = [th.get_text(strip=True) for th in table.find_all('th')]
            if "Case Name" in headers:
                target_table = table # Keep the last table found with this header

        if not target_table:
            # Case info table not found, return source code if found, count is 0 or None? Let's use None.
            return None, None, source_code, None

        tbody = target_table.find('tbody')
        if not tbody: return None, None, source_code, None # Return None for count if tbody missing

        rows = tbody.find_all('tr')
        if not rows: return None, None, source_code, None # Return None for count if rows missing

        for row in rows:
            cells = row.find_all('td')
            if len(cells) >= 2:
                case_name = cells[0].get_text(strip=True)
                case_status = cells[1].get_text(strip=True)
                if case_status == "AC":
                    ac_count += 1 # Increment total AC count
                elif first_failed_case_name is None: # Record the *first* non-AC case encountered
                    first_failed_case_name = case_name
                    first_failed_case_status = case_status
                    # Don't return yet, continue counting total ACs

        # After iterating through all rows
        final_case_name = None
        final_status = None
        if first_failed_case_name is None:
            final_case_name = "All Passed"
            final_status = "AC"
        else:
            final_case_name = first_failed_case_name
            final_status = first_failed_case_status
           
        # --- Write Results to Cache --- 
        results_to_cache = {
            "case_name": final_case_name,
            "status": final_status,
            "ac_count": ac_count
        }
        write_cache(results_cache_path, results_to_cache, is_json=True)
        # ------------------------------

        # Return the fetched and parsed results
        return final_case_name, final_status, source_code, ac_count

    except requests.exceptions.RequestException as e:
        # Network errors are common when scraping, return None gracefully for cases and count
        print(f"    错误：访问提交详情页时网络错误 {submission_url}: {e}", file=sys.stderr)
        return None, None, None, None 
    except Exception as e:
        # Other parsing errors
        print(f"    错误：解析提交详情页时出错 {submission_url}: {e}", file=sys.stderr)
        # 添加更详细的错误追踪信息
        print(traceback.format_exc(), file=sys.stderr)
        return None, None, None, None # Indicate complete failure, None for count

def get_submission_source_code(submission_url: str, session: requests.Session) -> Optional[str]:
    """访问提交详情页面并仅解析和返回源代码字符串 (using cache)."""
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    错误：无法从 URL 中提取 submission_id: {submission_url}", file=sys.stderr)
        return None
    submission_id = submission_id_match.group(1)

    # --- Cache Check ---
    cache_path = _get_submission_source_cache_path(submission_id)
    cached_data = read_cache(cache_path, is_json=False)
    if cached_data is not None:
        return cached_data
    # --- End Cache Check ---

    print(f"Fetching source code for submission {submission_id} (Cache Miss)")
    try:
        # Add a small delay
        time.sleep(0.5) 
        resp = utils.request('GET', submission_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        soup = bs4.BeautifulSoup(resp.text, 'lxml')
        code_pre = soup.select_one('pre#submission-code')
        if code_pre:
            source_code = code_pre.get_text()
            # --- Write to Cache ---
            write_cache(cache_path, source_code, is_json=False)
            # ---------------------
            return source_code
        else:
            # Don't cache if source element not found
            print(f"    警告：在 {submission_url} 页面找不到源代码元素 (pre#submission-code)。", file=sys.stderr)
            return None
    except requests.exceptions.RequestException as e:
        print(f"    错误：访问提交详情页时网络错误 {submission_url}: {e}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"    错误：解析提交详情页源代码时出错 {submission_url}: {e}", file=sys.stderr)
        return None

def get_submission_status(submission_url, session):
    """访问提交详情页面并解析核心状态 (AC, WA, WJ, TLE, etc.), using cache."""
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    错误：无法从 URL 中提取 submission_id: {submission_url}", file=sys.stderr)
        return None
    submission_id = submission_id_match.group(1)
    
    # --- Cache Check ---
    cache_path = _get_submission_status_cache_path(submission_id)
    cached_data = read_cache(cache_path, is_json=False)
    if cached_data is not None:
        return cached_data
    # --- End Cache Check ---

    print(f"Fetching status for submission {submission_id} (Cache Miss)")
    try:
        resp = utils.request('GET', submission_url, session=session, allow_redirects=True)
        resp.raise_for_status()
        soup = bs4.BeautifulSoup(resp.text, 'lxml')
        status_span = soup.select_one('#judge-status .label')

        if status_span:
            full_status_text = status_span.text.strip()
            parts = full_status_text.split()
            if parts:
                core_status = parts[-1] # 取最后一部分
                # --- Write to Cache --- 
                write_cache(cache_path, core_status, is_json=False)
                # ---------------------
                return core_status
            else:
                 # Don't cache if parsing fails
                 print(f"警告：状态标签文本 '{full_status_text}' 为空或无法分割。", file=sys.stderr)
                 return None
        else:
            # Don't cache if element not found
            print(f"警告：无法在 {submission_url} 找到明确的状态标签 (如 #judge-status .label)。页面结构可能已更改。", file=sys.stderr)
            return None

    except requests.exceptions.RequestException as e:
        print(f"查询状态时网络错误: {e}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"解析状态时发生未知错误: {e}", file=sys.stderr)
        return None

def get_problem_description(problem_url: str, session: requests.Session) -> Optional[str]:
    """Fetches/caches the problem description, returning Markdown.

    Checks cache order: Markdown -> HTML -> Fetch from network.
    Saves both HTML and Markdown to cache upon fetch or HTML cache hit.
    Returns the Markdown content as a string, or None on failure.
    """
    match = re.match(r"https://atcoder\.jp/contests/([^/]+)/tasks/([^/]+)", problem_url)
    if not match:
        print(f"    [Error] Could not parse contest_id/task_screen_name from URL: {problem_url}", file=sys.stderr)
        return None
    contest_id = match.group(1)
    task_screen_name = match.group(2)

    md_cache_path = _get_problem_description_md_cache_path(contest_id, task_screen_name)
    html_cache_path = _get_problem_description_html_cache_path(contest_id, task_screen_name)

    # 1. Check Markdown Cache
    cached_md = read_cache(md_cache_path, is_json=False)
    if cached_md is not None:
        print(f"  [Cache Hit] Read description (Markdown) from: {md_cache_path}")
        # --- Ensure samples are removed even from cache hit ---
        try:
            sample_markers = ["### Sample Input", "### Sample Output", "### 例"]
            sample_start_index = -1
            for marker in sample_markers:
                 idx = cached_md.find(marker)
                 if idx != -1:
                      if sample_start_index == -1 or idx < sample_start_index:
                           sample_start_index = idx
            if sample_start_index != -1:
                cached_md = cached_md[:sample_start_index].strip()
        except Exception: 
             pass # Ignore error during sample removal from cache
        # --- End ensure samples removed ---
        return cached_md

    # 2. Check HTML Cache
    cached_html = read_cache(html_cache_path, is_json=False)
    if cached_html is not None:
        print(f"  [Cache Hit] Read description (HTML) from: {html_cache_path}. Converting to Markdown...")
        try:
            # Convert HTML to Markdown
            markdown_content = _convert_html_to_markdown(cached_html)
            if markdown_content:
                # Save the generated Markdown
                write_cache(md_cache_path, markdown_content, is_json=False)
                return markdown_content
            else:
                print(f"  [Warning] Failed to convert cached HTML to Markdown.", file=sys.stderr)
                # Proceed to fetch? Or return error? Let's return error here.
                return f"# Error: Failed to convert cached HTML {html_cache_path}"
        except Exception as e:
            print(f"  [Error] Error converting cached HTML {html_cache_path} to Markdown: {e}", file=sys.stderr)
            return f"# Error: Exception converting cached HTML: {e}"

    # 3. Fetch from Network
    print(f"Fetching problem description for {task_screen_name} (Network Fetch)")
    fetched_html = None
    try:
        time.sleep(0.5) # Be polite
        resp = utils.request('GET', problem_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        fetched_html = resp.text # Get raw HTML content
        print(f"  [Success] Fetched HTML content for {task_screen_name} (length: {len(fetched_html)}).")

        # Save Fetched HTML
        write_cache(html_cache_path, fetched_html, is_json=False)

    except requests.exceptions.RequestException as e:
        print(f"    [Error] Network error fetching problem description {problem_url}: {e}", file=sys.stderr)
        return f"# Error: Network error fetching description: {e}"
    except Exception as e:
        print(f"    [Error] Unexpected error fetching {problem_url}: {e}", file=sys.stderr)
        return f"# Error: Unexpected fetch error: {e}"

    # 4. Convert Fetched HTML to Markdown (if fetch succeeded)
    if fetched_html:
        try:
            markdown_content = _convert_html_to_markdown(fetched_html)
            if markdown_content:
                # Save the generated Markdown
                write_cache(md_cache_path, markdown_content, is_json=False)
                return markdown_content
            else:
                print(f"  [Warning] Failed to convert fetched HTML to Markdown.", file=sys.stderr)
                return "# Error: Failed to convert fetched HTML"
        except Exception as e:
            print(f"  [Error] Error converting fetched HTML to Markdown: {e}", file=sys.stderr)
            traceback.print_exc()
            return f"# Error: Exception converting fetched HTML: {e}"
    else:
         # Should not happen if fetch logic is correct, but as a safeguard
         return "# Error: Fetch succeeded but HTML content was empty?"

def _convert_html_to_markdown(html_content: str) -> Optional[str]:
    """Helper function to convert HTML string to clean Markdown.
       Extracts relevant section, uses markdownify, and removes samples.
       Returns Markdown string or None on failure.
    """
    try:
        soup = BeautifulSoup(html_content, 'lxml')
        relevant_html_str = html_content # Default

        # Find relevant part (task statement, then English)
        statement_div = soup.select_one('#task-statement')
        if statement_div:
            english_span = statement_div.select_one('.lang-en')
            if english_span:
                relevant_html_str = str(english_span)
            else:
                relevant_html_str = str(statement_div)
        # Else: Use full HTML if #task-statement not found

        # Convert selected HTML to Markdown
        markdown_content = markdownify.markdownify(relevant_html_str)

        # # Remove Sample sections
        # sample_markers = ["### Sample Input", "### Sample Output", "### 例"]
        # sample_start_index = -1
        # for marker in sample_markers:
        #      idx = markdown_content.find(marker)
        #      if idx != -1:
        #           if sample_start_index == -1 or idx < sample_start_index:
        #                sample_start_index = idx
                           
        # if sample_start_index != -1:
        #     markdown_content = markdown_content[:sample_start_index].strip()
        #     print("  [Info] Removed sample sections during conversion.")

        return markdown_content.strip()

    except ImportError:
        print("  [Error] _convert_html_to_markdown: BeautifulSoup or markdownify not found.", file=sys.stderr)
        return None
    except Exception as e:
        print(f"  [Error] _convert_html_to_markdown: Failed conversion: {e}", file=sys.stderr)
        # traceback.print_exc() # Optional: for more detail
        return None

# --- Initialize Cookie Files on Module Load --- 
load_cookie_files()
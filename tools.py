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

CACHE_DIR = ".atcoder_cache"
PROBLEMS_CACHE_SUBDIR = "problems"
SUBMISSIONS_CACHE_SUBDIR = "submissions"

try:
    os.makedirs(CACHE_DIR, exist_ok=True)
except Exception as e:
    print(f"[Cache Warning] Failed to create base cache directory {CACHE_DIR}: {e}", file=sys.stderr)

def _get_problem_cache_path(contest_id: str, problem_id: str) -> str:
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, problem_id, "details.json")

def _get_submission_source_cache_path(submission_id: str) -> str:
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "source.txt")

def _get_submission_results_cache_path(submission_id: str) -> str:
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "results.json")

def _get_submission_status_cache_path(submission_id: str) -> str:
    return os.path.join(CACHE_DIR, SUBMISSIONS_CACHE_SUBDIR, str(submission_id), "status.txt")

def _get_problem_description_md_cache_path(contest_id: str, task_screen_name: str) -> str:
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, task_screen_name, "description.md")

def _get_problem_description_html_cache_path(contest_id: str, task_screen_name: str) -> str:
    return os.path.join(CACHE_DIR, PROBLEMS_CACHE_SUBDIR, contest_id, task_screen_name, "description.html")

def read_cache(cache_path: str, is_json: bool = True) -> Optional[Any]:
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
        try:
            os.remove(cache_path)
            print(f"    [Cache Info] Removed potentially corrupted cache file: {cache_path}")
        except OSError as remove_err:
            print(f"    [Cache Warning] Failed to remove corrupted cache file {cache_path}: {remove_err}", file=sys.stderr)
        return None

def write_cache(cache_path: str, data: Any, is_json: bool = True):
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

COOKIE_DIR_PATH = "/home/barty/.local/share/online-judge-tools"
AVAILABLE_COOKIE_FILES = []
current_cookie_index = 0
cookie_load_lock = threading.Lock()

def load_cookie_files():
    global AVAILABLE_COOKIE_FILES
    cookie_pattern = os.path.join(COOKIE_DIR_PATH, '*-cookie.jar')
    with cookie_load_lock:
        AVAILABLE_COOKIE_FILES = glob.glob(cookie_pattern)
        if not AVAILABLE_COOKIE_FILES:
            print(f"Warning: No '*-cookie.jar' files found in directory '{COOKIE_DIR_PATH}'. Judge and scraping functions may not work with authentication.")
        else:
            AVAILABLE_COOKIE_FILES.sort()
            print(f"[Cookie] Found {len(AVAILABLE_COOKIE_FILES)} cookie files: {', '.join(os.path.basename(f) for f in AVAILABLE_COOKIE_FILES)}") 

def get_next_cookie_path() -> Optional[str]:
    global current_cookie_index
    with cookie_load_lock:
        if not AVAILABLE_COOKIE_FILES:
            return None

        if current_cookie_index >= len(AVAILABLE_COOKIE_FILES):
            current_cookie_index = 0

        cookie_path = AVAILABLE_COOKIE_FILES[current_cookie_index]
        print(f"[Cookie] Using cookie: {os.path.basename(cookie_path)} (Index: {current_cookie_index})")
        current_cookie_index += 1
        return cookie_path

def load_session() -> Optional[requests.Session]:
    cookie_path = get_next_cookie_path()
    if not cookie_path:
        print("[Error] load_session: No cookie files available via get_next_cookie_path(). Cannot create authenticated session.", file=sys.stderr)
        return None 
    
    session = load_session_with_cookie_file(cookie_path)
    return session

def load_session_with_cookie_file(cookie_path: Optional[str]) -> Optional[requests.Session]:
    if cookie_path is None:
         print("[Session] Warning: cookie_path is None, creating session without cookies.")
         return requests.Session()
    if not os.path.exists(cookie_path):
         print(f"[Session] Error: Cookie file not found at {cookie_path}", file=sys.stderr)
         return None
         
    session = requests.Session()
    jar = http.cookiejar.LWPCookieJar(cookie_path)
    try:
        jar.load(ignore_discard=True, ignore_expires=True)
        session.cookies = jar
        print(f"[Session] Successfully loaded cookies from {os.path.basename(cookie_path)}")
        return session
    except Exception as e:
         print(f"[Session] Error loading cookie file {cookie_path}: {e}", file=sys.stderr)
         return None

def get_first_failed_case_info(submission_url, session):
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    Error: Unable to extract submission_id from URL: {submission_url}", file=sys.stderr)
        return None, None, None, None
    submission_id = submission_id_match.group(1)

    results_cache_path = _get_submission_results_cache_path(submission_id)
    cached_results = read_cache(results_cache_path, is_json=True)
    
    source_cache_path = _get_submission_source_cache_path(submission_id)
    cached_source = read_cache(source_cache_path, is_json=False)

    if cached_results is not None and cached_source is not None:
        if isinstance(cached_results, dict) and all(k in cached_results for k in ['case_name', 'status', 'ac_count']):
             print(f"  [Cache Hit] Returning cached results and source for submission {submission_id}")
             return cached_results['case_name'], cached_results['status'], cached_source, cached_results['ac_count']
        else:
             print(f"  [Cache Warning] Corrupted results cache for {submission_id}, proceeding to fetch.", file=sys.stderr)
             try: os.remove(results_cache_path) 
             except OSError: pass
             cached_results = None
    elif cached_results is not None and cached_source is None:
         print(f"  [Cache Info] Results cache hit, but source cache miss for submission {submission_id}. Will fetch page anyway.")
         cached_results = None
    elif cached_source is not None and cached_results is None:
         print(f"  [Cache Info] Source cache hit, but results cache miss for submission {submission_id}. Will fetch page anyway.")
         cached_source = None

    print(f"Fetching details page for submission {submission_id} (Cache Miss)")
    time.sleep(0.5)
    source_code = None 
    ac_count = 0 
    first_failed_case_name = None
    first_failed_case_status = None
    try:
        resp = utils.request('GET', submission_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        soup = bs4.BeautifulSoup(resp.text, 'lxml')

        code_pre = soup.select_one('pre#submission-code')
        if code_pre:
            source_code = code_pre.get_text()
            write_cache(source_cache_path, source_code, is_json=False)
        else:
            print(f"    Warning: Cannot find source code element (pre#submission-code) on page {submission_url}.", file=sys.stderr)
            return None, None, None, None 

        target_table = None
        all_tables = soup.find_all('table')
        for i, table in enumerate(all_tables):
            headers = [th.get_text(strip=True) for th in table.find_all('th')]
            if "Case Name" in headers:
                target_table = table

        if not target_table:
            return None, None, source_code, None

        tbody = target_table.find('tbody')
        if not tbody: return None, None, source_code, None

        rows = tbody.find_all('tr')
        if not rows: return None, None, source_code, None

        for row in rows:
            cells = row.find_all('td')
            if len(cells) >= 2:
                case_name = cells[0].get_text(strip=True)
                case_status = cells[1].get_text(strip=True)
                if case_status == "AC":
                    ac_count += 1
                elif first_failed_case_name is None:
                    first_failed_case_name = case_name
                    first_failed_case_status = case_status

        final_case_name = None
        final_status = None
        if first_failed_case_name is None:
            final_case_name = "All Passed"
            final_status = "AC"
        else:
            final_case_name = first_failed_case_name
            final_status = first_failed_case_status
           
        results_to_cache = {
            "case_name": final_case_name,
            "status": final_status,
            "ac_count": ac_count
        }
        write_cache(results_cache_path, results_to_cache, is_json=True)

        return final_case_name, final_status, source_code, ac_count

    except requests.exceptions.RequestException as e:
        print(f"    Error: Network error when accessing submission details page {submission_url}: {e}", file=sys.stderr)
        return None, None, None, None 
    except Exception as e:
        print(f"    Error: Error parsing submission details page {submission_url}: {e}", file=sys.stderr)
        print(traceback.format_exc(), file=sys.stderr)
        return None, None, None, None

def get_submission_source_code(submission_url: str, session: requests.Session) -> Optional[str]:
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    Error: Unable to extract submission_id from URL: {submission_url}", file=sys.stderr)
        return None
    submission_id = submission_id_match.group(1)

    cache_path = _get_submission_source_cache_path(submission_id)
    cached_data = read_cache(cache_path, is_json=False)
    if cached_data is not None:
        return cached_data

    print(f"Fetching source code for submission {submission_id} (Cache Miss)")
    try:
        time.sleep(0.5) 
        resp = utils.request('GET', submission_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        soup = bs4.BeautifulSoup(resp.text, 'lxml')
        code_pre = soup.select_one('pre#submission-code')
        if code_pre:
            source_code = code_pre.get_text()
            write_cache(cache_path, source_code, is_json=False)
            return source_code
        else:
            print(f"    Warning: Cannot find source code element (pre#submission-code) on page {submission_url}.", file=sys.stderr)
            return None
    except requests.exceptions.RequestException as e:
        print(f"    Error: Network error when accessing submission details page {submission_url}: {e}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"    Error: Error parsing source code from submission details page {submission_url}: {e}", file=sys.stderr)
        return None

def get_submission_status(submission_url, session):
    submission_id_match = re.search(r'/submissions/(\d+)', submission_url)
    if not submission_id_match:
        print(f"    Error: Unable to extract submission_id from URL: {submission_url}", file=sys.stderr)
        return None
    submission_id = submission_id_match.group(1)
    
    cache_path = _get_submission_status_cache_path(submission_id)
    cached_data = read_cache(cache_path, is_json=False)
    if cached_data is not None:
        return cached_data

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
                core_status = parts[-1]
                write_cache(cache_path, core_status, is_json=False)
                return core_status
            else:
                 print(f"Warning: Status label text '{full_status_text}' is empty or cannot be split.", file=sys.stderr)
                 return None
        else:
            print(f"Warning: Cannot find clear status label (such as #judge-status .label) at {submission_url}. Page structure may have changed.", file=sys.stderr)
            return None

    except requests.exceptions.RequestException as e:
        print(f"Network error when querying status: {e}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"Unknown error occurred when parsing status: {e}", file=sys.stderr)
        return None

def get_problem_description(problem_url: str, session: requests.Session) -> Optional[str]:
    match = re.match(r"https://atcoder\.jp/contests/([^/]+)/tasks/([^/]+)", problem_url)
    if not match:
        print(f"    [Error] Could not parse contest_id/task_screen_name from URL: {problem_url}", file=sys.stderr)
        return None
    contest_id = match.group(1)
    task_screen_name = match.group(2)

    md_cache_path = _get_problem_description_md_cache_path(contest_id, task_screen_name)
    html_cache_path = _get_problem_description_html_cache_path(contest_id, task_screen_name)

    cached_md = read_cache(md_cache_path, is_json=False)
    if cached_md is not None:
        print(f"  [Cache Hit] Read description (Markdown) from: {md_cache_path}")
        try:
            sample_markers = ["### Sample Input", "### Sample Output", "### Example"]
            sample_start_index = -1
            for marker in sample_markers:
                 idx = cached_md.find(marker)
                 if idx != -1:
                      if sample_start_index == -1 or idx < sample_start_index:
                           sample_start_index = idx
            if sample_start_index != -1:
                cached_md = cached_md[:sample_start_index].strip()
        except Exception: 
             pass
        return cached_md

    cached_html = read_cache(html_cache_path, is_json=False)
    if cached_html is not None:
        print(f"  [Cache Hit] Read description (HTML) from: {html_cache_path}. Converting to Markdown...")
        try:
            markdown_content = _convert_html_to_markdown(cached_html)
            if markdown_content:
                write_cache(md_cache_path, markdown_content, is_json=False)
                return markdown_content
            else:
                print(f"  [Warning] Failed to convert cached HTML to Markdown.", file=sys.stderr)
                return f"# Error: Failed to convert cached HTML {html_cache_path}"
        except Exception as e:
            print(f"  [Error] Error converting cached HTML {html_cache_path} to Markdown: {e}", file=sys.stderr)
            return f"# Error: Exception converting cached HTML: {e}"

    print(f"Fetching problem description for {task_screen_name} (Network Fetch)")
    fetched_html = None
    try:
        time.sleep(0.5)
        resp = utils.request('GET', problem_url, session=session, allow_redirects=True, timeout=15)
        resp.raise_for_status()
        fetched_html = resp.text
        print(f"  [Success] Fetched HTML content for {task_screen_name} (length: {len(fetched_html)}).")

        write_cache(html_cache_path, fetched_html, is_json=False)

    except requests.exceptions.RequestException as e:
        print(f"    [Error] Network error fetching problem description {problem_url}: {e}", file=sys.stderr)
        return f"# Error: Network error fetching description: {e}"
    except Exception as e:
        print(f"    [Error] Unexpected error fetching {problem_url}: {e}", file=sys.stderr)
        return f"# Error: Unexpected fetch error: {e}"

    if fetched_html:
        try:
            markdown_content = _convert_html_to_markdown(fetched_html)
            if markdown_content:
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
         return "# Error: Fetch succeeded but HTML content was empty?"

def _convert_html_to_markdown(html_content: str) -> Optional[str]:
    try:
        soup = BeautifulSoup(html_content, 'lxml')
        relevant_html_str = html_content

        statement_div = soup.select_one('#task-statement')
        if statement_div:
            english_span = statement_div.select_one('.lang-en')
            if english_span:
                relevant_html_str = str(english_span)
            else:
                relevant_html_str = str(statement_div)

        markdown_content = markdownify.markdownify(relevant_html_str)

        return markdown_content.strip()

    except ImportError:
        print("  [Error] _convert_html_to_markdown: BeautifulSoup or markdownify not found.", file=sys.stderr)
        return None
    except Exception as e:
        print(f"  [Error] _convert_html_to_markdown: Failed conversion: {e}", file=sys.stderr)
        return None

load_cookie_files()
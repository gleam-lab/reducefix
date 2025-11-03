import sys
import os
import getpass
import requests
import http.cookiejar
import time
import bs4
import re
import traceback
from onlinejudge.service.atcoder import AtCoderService, AtCoderProblem
from onlinejudge.type import LanguageId, LoginError, NotLoggedInError, SubmissionError
import onlinejudge._implementation.utils as utils
from tools import load_session_with_cookie_file, get_submission_status, get_first_failed_case_info

def submit_and_get_results(contest_id: str,
                           problem_id: str,
                           code_str: str,
                           language_id: LanguageId = '5001', # 5001: C++, 5055: Python
                           cookie_file_path: str = None,  # Default to None, will use environment variable
                           max_poll_attempts: int = 30,
                           poll_wait_seconds: int = 3) -> dict:
    result = {
        "success": False,
        "submission_url": None,
        "final_status": None,
        "failed_case_name": None,
        "failed_case_status": None,
        "ac_count": None,
        "error_message": None
    }
    # Use default cookie path if not provided
    if cookie_file_path is None:
        cookie_file_path = os.path.expanduser("~/.local/share/online-judge-tools/cookie.jar")
    
    print(f"[Core] Attempting to load session from {cookie_file_path}...")
    session = load_session_with_cookie_file(cookie_file_path)
    if session is None:
        result["error_message"] = f"Cannot load cookie file: {cookie_file_path}"
        return result
    service = AtCoderService()
    problem = AtCoderProblem(contest_id=contest_id, problem_id=problem_id)
    try:
        print("[Core] Validating cookie validity...")
        _ = [language.id for language in problem.get_available_languages(session=session)]
        print("[Core] Cookie validation successful!")
    except NotLoggedInError:
        result["error_message"] = "Cookie invalid or expired"
        return result
    except Exception as e:
        result["error_message"] = f"Error validating cookie: {e}"
        if isinstance(e, requests.exceptions.HTTPError) and e.response.status_code == 404:
             result["error_message"] += f". Cannot find contest '{contest_id}' or problem '{problem_id}'."
        return result
    submission = None
    try:
        print(f"[Core] Submitting code to {problem.get_url()} using language {language_id}...")
        code_bytes = code_str.encode('utf-8')
        submission = problem.submit_code(code_bytes, language_id, session=session)
        result["submission_url"] = submission.get_url()
        print(f"[Core] Submission successful! URL: {result['submission_url']}")
    except NotLoggedInError:
        result["error_message"] = "Submission failed: Not logged in or session expired"
        return result
    except SubmissionError as e:
        result["error_message"] = f"Submission failed: {e}"
        return result
    except Exception as e:
        print(traceback.format_exc())
        result["error_message"] = f"Unexpected error during submission: {type(e).__name__}: {e}"
        return result
    if submission:
        print("[Core] Starting to query judging status...")
        submission_url = result["submission_url"]
        final_status = None
        basic_pending_statuses = {"WJ", "WR", "Judging", "Compiling"}
        partial_status_pattern = re.compile(r"^\d+/\d+$")

        for attempt in range(max_poll_attempts):
            current_status = get_submission_status(submission_url, session)
            if current_status is None:
                print(f"[Core] Attempt {attempt + 1} to get status failed, retrying in {poll_wait_seconds} seconds...")
            elif current_status in basic_pending_statuses or partial_status_pattern.match(current_status):
                print(f"[Core] Current status: {current_status} (attempt {attempt + 1}/{max_poll_attempts}), retrying in {poll_wait_seconds} seconds...")
            else:
                final_status = current_status
                print(f"[Core] Got final status: {final_status}")
                break
            time.sleep(poll_wait_seconds)
        else:
            print("[Core] Query timeout, unable to get final judging status.")
            final_status = current_status

        result["final_status"] = final_status

        # -- Modification start: Try to get case details/AC count for both failed and AC status --
        # Define status set that needs details query (failed status + AC status)
        statuses_to_get_details = {"WA", "TLE", "MLE", "RE", "OLE", "AC"}

        if final_status in statuses_to_get_details:
            print(f"[Core] Status is {final_status}, querying case details/AC count...")
            # Wait a bit to ensure page update is complete
            time.sleep(1)
            failed_name, failed_status, _, ac_count = get_first_failed_case_info(submission_url, session)

            result["ac_count"] = ac_count # Always record ac_count (might be None)

            if final_status == "AC":
                 if ac_count is not None:
                     print(f"[Core] Judging passed! Total {ac_count} test cases passed.")
                 else:
                     print("[Core] Judging passed! But unable to parse the number of passed test cases.")
            elif failed_name is None and ac_count is None:
                 # For failed status but parsing failed
                 print("[Core] Attempted to parse HTML page, but unable to find failure details or AC count.")
                 result["failed_case_name"] = "Unknown - Parse Failed"
                 result["failed_case_status"] = final_status # Report original failure status
            elif failed_name == "All Passed":
                 # Theoretically shouldn't enter this branch when final_status is not AC, but as robustness check
                 print(f"[Core] Warning: Status is {final_status} but details parsed as 'All Passed'? AC count: {ac_count if ac_count is not None else 'Unknown'}")
                 # Even in this case, record AC count
            elif failed_name is not None: # Explicitly found failed case
                 print(f"[Core] Found first failed case: {failed_name} ({failed_status}), previous AC count: {ac_count if ac_count is not None else 'Unknown'}")
                 result["failed_case_name"] = failed_name
                 result["failed_case_status"] = failed_status
            # else: No need to handle, ac_count has been recorded
        else:
             # For CE, IE, WJ etc. status, don't query case details
             print(f"[Core] Final status is {final_status}, not querying case details/AC count.")
        # -- Modification end --

        result["success"] = True

    else:
        result["error_message"] = "Unknown error caused submission object not created"

    return result

def main():
    print("--- AtCoder Submission Script (Test Mode) ---")
    contest_id = "abc330"
    problem_id = "abc330_d"
    code_file_path = "my_solution.cc"
    # Use default cookie file path
    cookie_file = os.path.expanduser("~/.local/share/online-judge-tools/cookie.jar")
    
    print(f"Test configuration:")
    print(f"  Contest: {contest_id}")
    print(f"  Problem: {problem_id}")
    print(f"  Code file: {code_file_path}")
    print(f"  Cookie file: {cookie_file}")

    print(f"\nReading code file: {code_file_path}...")
    with open(code_file_path, 'r', encoding='utf-8') as f: 
        code_str = f.read()
    result = submit_and_get_results(contest_id=contest_id,
                                    problem_id=problem_id,
                                    code_str=code_str,
                                    cookie_file_path=cookie_file)

    print("\n--- Submission Results ---")
    print(f"Operation successful: {result['success']}")
    print(f"Submission URL: {result['submission_url'] or 'N/A'}")
    print(f"Final status: {result['final_status'] or 'Unknown'}")
    if result['failed_case_name'] and result['failed_case_name'] != "All Passed":
        print(f"First failed case: {result['failed_case_name']} ({result['failed_case_status']}), AC count: {result['ac_count'] if result['ac_count'] is not None else 'Unknown'}" )
    elif result['failed_case_name'] == "All Passed":
         print(f"First failed case: (All parsed cases passed), AC count: {result['ac_count'] if result['ac_count'] is not None else 'Unknown'}")
    elif result['final_status'] == "AC":
         print(f"Number of passed test cases: {result['ac_count'] if result['ac_count'] is not None else 'Failed to query AC count or not implemented'}")
    else:
         print(f"First failed case: (Not found, not applicable, or parse failed), AC count: {result['ac_count'] if result['ac_count'] is not None else 'Unknown'}")
    if result['error_message']:
        print(f"Error message: {result['error_message']}")
    print("---------------")


if __name__ == "__main__":
    # Ensure online-judge-tools, bs4, and lxml are installed
    try:
        import onlinejudge
        import bs4
        import lxml 
    except ImportError as missing_lib:
        module_name = str(missing_lib).split("'")[1]
        package_name = 'lxml'
        if module_name == 'bs4':
             package_name = 'beautifulsoup4'
        elif module_name == 'onlinejudge':
             package_name = 'online-judge-tools'
        # Add other potential direct imports from onlinejudge if needed
        
        print(f"Error: Cannot find library '{module_name}'.", file=sys.stderr)
        print(f"Please run: pip install {package_name}", file=sys.stderr)
        sys.exit(1)

    main()
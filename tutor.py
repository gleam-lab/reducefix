import os
import json
import re
import html2text
from openai import OpenAI, BadRequestError
from concurrent.futures import ThreadPoolExecutor, as_completed
import shlex
import time
import judge
import requests
from bs4 import BeautifulSoup
import traceback
import Levenshtein
from typing import Dict, Any, Optional, Tuple

from tools import get_next_cookie_path, load_session_with_cookie_file
from tools import read_cache, write_cache, _get_problem_cache_path

# Import API configurations from config.py
try:
    # Add current script directory to FRONT of path to avoid conflicts
    import sys
    _script_dir = os.path.dirname(os.path.abspath(__file__))
    # Remove any existing entries and add to front
    sys.path = [p for p in sys.path if p != _script_dir]
    sys.path.insert(0, _script_dir)
    
    # Force reload if already imported
    if 'config' in sys.modules:
        import importlib
        importlib.reload(sys.modules['config'])
    
    from config import (
        DEEPSEEK_API_KEY, DEEPSEEK_BASE_URL,
        QWEN_API_KEY, QWEN_BASE_URL,
        DEFAULT_LANGUAGE, ATCODER_CPP_LANG_ID,
        LLM_REQUEST_COUNT, JUDGE_POLL_ATTEMPTS, JUDGE_POLL_WAIT
    )
except ImportError as e:
    print(f"[Warning] config.py not found ({e}), using default values")
    DEEPSEEK_API_KEY = 'YOUR_DEEPSEEK_API_KEY'
    DEEPSEEK_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'
    QWEN_API_KEY = 'YOUR_QWEN_API_KEY'
    QWEN_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1'
    DEFAULT_LANGUAGE = 'cpp'
    ATCODER_CPP_LANG_ID = '5001'
    LLM_REQUEST_COUNT = 2
    JUDGE_POLL_ATTEMPTS = 60
    JUDGE_POLL_WAIT = 5

deepseek_client = None
qwen_client = None

if DEEPSEEK_API_KEY and DEEPSEEK_API_KEY != 'YOUR_DEEPSEEK_API_KEY' and DEEPSEEK_BASE_URL:
    try:
        deepseek_client = OpenAI(api_key=DEEPSEEK_API_KEY, base_url=DEEPSEEK_BASE_URL)
        print("DeepSeek client configured using hardcoded credentials.")
    except Exception as e:
        print(f"Failed to configure DeepSeek client with hardcoded credentials: {e}")
else:
    if not DEEPSEEK_API_KEY or DEEPSEEK_API_KEY == 'YOUR_DEEPSEEK_API_KEY':
        print("DeepSeek API key is missing or still a placeholder in the code. Please replace 'YOUR_DEEPSEEK_API_KEY'.")
    if not DEEPSEEK_BASE_URL:
         print("DeepSeek Base URL is missing in the code.")

if QWEN_API_KEY and QWEN_API_KEY != 'YOUR_QWEN_API_KEY' and QWEN_BASE_URL:
    try:
        qwen_client = OpenAI(api_key=QWEN_API_KEY, base_url=QWEN_BASE_URL)
        print("Qwen client configured using hardcoded credentials.")
    except Exception as e:
        print(f"Failed to configure Qwen client with hardcoded credentials: {e}")
else:
    if not QWEN_API_KEY or QWEN_API_KEY == 'YOUR_QWEN_API_KEY':
        print("Qwen API key is missing or still a placeholder in the code. Please replace 'YOUR_QWEN_API_KEY'.")
    if not QWEN_BASE_URL:
        print("Qwen Base URL is missing in the code.")

def extract_longest_code_block(text):
    if not text:
        return None
    code_blocks = re.findall(r'```(?:cpp|c\+\+|)\s*\n?(.*?)```', text, re.DOTALL)
    if not code_blocks:
         lines = text.strip().splitlines()
         if len(lines) > 1 and any(l.strip().startswith(('#include', 'int main', 'using namespace', '//', '/*')) for l in lines):
             return text.strip()
         return None
    return max(code_blocks, key=len).strip()

def normalize_whitespace(code_str):
    if not code_str:
        return ""
    normalized = re.sub(r'\s+', ' ', code_str)
    return normalized.strip()

def build_debug_prompt(problem_title, problem_description, language, code, samples, judge_status=None, compile_error=None):
    prompts = []

    try:
        h = html2text.HTML2Text()
        h.ignore_links = True
        description_text = h.handle(problem_description)
    except Exception as e:
        print(f"html2text processing error: {e}")
        description_text = problem_description

    prompt = f'I am solving an algorithm problem on AtCoder using {language} language and need help debugging. Please read the following information carefully.\n\n'
    prompt += f'# Problem: {problem_title}\n\n{description_text}\n'

    if samples:
        prompt += "\n## Sample Data\n"
        try:
            samples_list = json.loads(samples)
            for i, sample in enumerate(samples_list):
                input_text = sample.get('input', '')
                output_text = sample.get('output', '')
                prompt += f"\n### Sample {i+1}\n"
                prompt += f"Input:\n```\n{input_text}\n```\n"
                prompt += f"Output:\n```\n{output_text}\n```\n"
        except (json.JSONDecodeError, TypeError) as e:
            print(f"Error parsing sample data: {e}")
            prompt += f"\n(Unable to parse sample data: {samples})\n"
        prompt += "\n"

    prompts.append(prompt)

    code_prompt = f'## My Code and Status\n\nMy code is as follows:\n```{language}\n{code}\n```\n'
    if judge_status:
        code_prompt += f"\nJudge status: {judge_status}\n"
    if compile_error:
        code_prompt += f"\nCompile information:\n```\n{compile_error}\n```\n"
    prompts.append(code_prompt)

    instruction_prompt = (
        "## Your Task\n"
        "Please carefully analyze the problem description, samples, my code, and judge/compile status I provided, find errors in the code and fix them.\n\n"
        "**Requirements:**\n"
        "1.  **Minimal changes**: Modify my code as little as possible, maintaining the original code style and variable naming.\n"
        "2.  **Code only**: Your answer should **only contain** the complete fixed C++ code block, wrapped with ```cpp ... ``` markers. **Do not** include any explanations, analysis, apologies, or additional conversational text.\n"
        "3.  **Focus on fixing**: Your goal is to fix errors in the code to make it correctly solve the problem. Do not add irrelevant features or perform unnecessary code refactoring.\n\n"
        "Please directly provide the fixed code."
    )
    prompts.append(instruction_prompt)
    return prompts

def get_llm_suggestions(client: OpenAI, model_name: str, history: list, count: int = 1, max_tokens: int = 2048, temperature: float = 0.1):
    if not client:
        return [], f"Client for model '{model_name}' is not configured or configuration failed."

    thread_history = history.copy()
    suggestions = []
    error_message = None

    print(f"Preparing to send {count} separate requests (n=1) to {model_name} (Base URL: {client.base_url})...", flush=True)

    try:
        for i in range(count):
            print(f"  > Sending request {i+1}/{count} to {model_name} (n=1)...", flush=True)
            chat_completion = client.chat.completions.create(
                model=model_name,
                messages=thread_history,
                temperature=temperature,
                max_tokens=max_tokens,
                n=1,
                timeout=180,
            )
            if chat_completion.choices:
                response_content = chat_completion.choices[0].message.content
                fixed_code = extract_longest_code_block(response_content)
                if fixed_code:
                    print(f"    >> Extracted code from {model_name} request {i+1}.", flush=True)
                    suggestions.append(fixed_code)
                else:
                    print(f"    >> Failed to extract code block from {model_name} request {i+1}. Response: {response_content[:100]}...", flush=True)
                    if error_message is None:
                        error_message = f"At least one response from model '{model_name}' failed to extract a valid code block."
            else:
                    print(f"    >> {model_name} request {i+1} did not return a valid choice.", flush=True)

    except Exception as e:
        error_message = f"General error when calling {model_name}: {type(e).__name__}: {e}"
        print(error_message, flush=True)

    if not suggestions and error_message is None:
        error_message = f"Model '{model_name}' did not return any valid code suggestions or extraction failed."

    return suggestions, error_message

def process_debug_request(data: Dict[str, Any]) -> Tuple[Dict[str, Any], int]:
    problem_title = data.get('problem_title')
    problem_description = data.get('problem_description')
    language = data.get('language', DEFAULT_LANGUAGE)
    code = data.get('code')
    samples = data.get('samples')
    judge_status = data.get('judge_status')
    compile_error = data.get('compile_error')
    contest_id = data.get('contest_id')
    problem_id = data.get('problem_id')

    required_fields = ["problem_title", "problem_description", "code", "contest_id", "problem_id"]
    missing_fields = [field for field in required_fields if not data.get(field)]
    if missing_fields:
        return {"error": f"Missing required fields: {', '.join(missing_fields)}"}, 400

    if language.lower() != 'cpp':
         return {"error": f"Currently only supports C++ ({DEFAULT_LANGUAGE}) language"}, 400

    print("Received debug request, preparing...")

    system_prompt = "You are an AI assistant specialized in fixing C++ algorithm contest code. Based on the problem information and code provided by the user, find errors and provide the complete fixed code. Your answer must only contain the code itself, wrapped with ```cpp ... ```."
    prompts_content = build_debug_prompt(
        problem_title, problem_description, language, code, samples, judge_status, compile_error
    )
    history = [{'role': 'system', 'content': system_prompt}]
    for content in prompts_content:
        history.append({'role': 'user', 'content': content})

    all_suggestions = []
    llm_errors = {}
    models_to_run = []
    if deepseek_client:
        models_to_run.append({"client": deepseek_client, "name": "deepseek-v3"})
    if qwen_client:
        models_to_run.append({"client": qwen_client, "name": "qwen-plus"}) 

    if not models_to_run:
        return {"error": "No LLM clients configured."}, 500

    model_names_str = ", ".join([m['name'] for m in models_to_run])
    print(f"Preparing to call models: {model_names_str} (requesting {LLM_REQUEST_COUNT} suggestions per model)", flush=True)

    with ThreadPoolExecutor(max_workers=len(models_to_run)) as executor:
        future_to_model = {
            executor.submit(get_llm_suggestions, model_info["client"], model_info["name"], history, count=LLM_REQUEST_COUNT): model_info["name"]
            for model_info in models_to_run
        }
        for future in as_completed(future_to_model):
            model_name = future_to_model[future]
            try:
                print(f"Waiting for response from model {model_name}...")
                suggestions_list, error = future.result()
                if error:
                    llm_errors[model_name] = error
                    print(f"Model {model_name} call error: {error}") 
                if suggestions_list:
                    for sugg_code in suggestions_list:
                         all_suggestions.append({"code": sugg_code, "source_model": model_name})
                    print(f"Collected {len(suggestions_list)} suggestions from {model_name}.", flush=True)
            except Exception as exc:
                error_msg = f'{model_name} generated exception during execution: {exc}'
                print(error_msg, flush=True)
                llm_errors[model_name] = error_msg

    if not all_suggestions:
        error_summary = "Failed to get valid code suggestions from any model."
        if llm_errors:
             error_summary += " Error details: " + json.dumps(llm_errors)
        return {"error": error_summary}, 500

    total_suggestions = len(all_suggestions)
    print(f"Collected {total_suggestions} code suggestions in total, preparing for judging...", flush=True)

    judging_results = []
    for i, suggestion in enumerate(all_suggestions):
        status_msg = f'[{i+1}/{total_suggestions}] Submitting suggestion from {suggestion["source_model"]} for judging...'
        print(status_msg, flush=True)

        current_cookie_path = get_next_cookie_path() 
        if not current_cookie_path:
            error_msg = "Error: Unable to get Cookie file for judging. Please ensure the Cookie storage directory is configured correctly and files exist."
            print(error_msg, flush=True)
            judging_results.append({
                "code": suggestion['code'],
                "source_model": suggestion['source_model'],
                "judge_details": {"success": False, "final_status": "Cookie Error", "ac_count": 0, "error_message": "No cookie file available via tools.get_next_cookie_path()"}
            })
            continue

        try: 
            judge_result = judge.submit_and_get_results(
                contest_id=contest_id,
                problem_id=problem_id,
                code_str=suggestion['code'],
                language_id=ATCODER_CPP_LANG_ID, 
                cookie_file_path=current_cookie_path,
                max_poll_attempts=JUDGE_POLL_ATTEMPTS,
                poll_wait_seconds=JUDGE_POLL_WAIT
            )
            print(f"Judging result: Success={judge_result['success']}, Status={judge_result['final_status']}, AC Count={judge_result['ac_count']}, Err={judge_result['error_message']}", flush=True)
            judging_results.append({
                "code": suggestion['code'],
                "source_model": suggestion['source_model'],
                "judge_details": judge_result
            })
            result_status_msg = f'[{i+1}/{total_suggestions}] Judging completed (from {suggestion["source_model"]}): Status={judge_result.get("final_status", "Unknown")}, AC={judge_result.get("ac_count", "N/A")}'
            if not judge_result.get('success'):
                 result_status_msg += f', Error: {judge_result.get("error_message", "Unknown judging error")}'
                 print(f"Judging {i+1} warning: {result_status_msg}") 
            else:
                 print(f"Judging {i+1} success: {result_status_msg}") 

        except Exception as judge_exc:
             error_msg = f'Error occurred while judging suggestion {i+1} (from {suggestion["source_model"]}): {judge_exc}'
             print(error_msg, flush=True)
             judging_results.append({
                 "code": suggestion['code'],
                 "source_model": suggestion['source_model'],
                 "judge_details": {"success": False, "final_status": "Judge Error", "ac_count": 0, "error_message": str(judge_exc)}
             })

        time.sleep(1) 

    best_result = None
    ac_results = []
    max_ac_count = -1 
    min_edit_distance = float('inf') 

    print("\nStarting to filter best result...")
    
    for result in judging_results:
        details = result.get("judge_details", {})
        if details.get("success") and details.get("final_status") == "AC":
            print(f"Found AC result (from {result.get('source_model', 'Unknown')}).")
            ac_results.append(result)

    if len(ac_results) == 1:
        best_result = ac_results[0]
        print(f"Only one AC result, selecting it as the best.")
        ac_details = best_result.get("judge_details", {})
        final_ac_count = ac_details.get("ac_count")
        if isinstance(final_ac_count, int):
             max_ac_count = final_ac_count
    elif len(ac_results) > 1:
        print(f"Found {len(ac_results)} AC results, will select based on edit distance to original code...")
        original_code = data.get('code', '') 
        best_ac_result_by_distance = None

        for ac_result in ac_results:
            normalized_original = normalize_whitespace(original_code)
            normalized_suggested = normalize_whitespace(ac_result.get('code', ''))
            distance = Levenshtein.distance(normalized_original, normalized_suggested)
            print(f"  - AC code from {ac_result.get('source_model', 'Unknown')}, edit distance: {distance}")
            if distance < min_edit_distance:
                min_edit_distance = distance
                best_ac_result_by_distance = ac_result
                print(f"    ^-- Currently minimum edit distance.")
            elif distance == min_edit_distance:
                 print(f"    ^-- Edit distance equals current minimum, keeping the first found.")

        best_result = best_ac_result_by_distance
        if best_result:
             print(f"Selected AC result with minimum edit distance ({min_edit_distance}) as the best.")
             ac_details = best_result.get("judge_details", {})
             final_ac_count = ac_details.get("ac_count")
             if isinstance(final_ac_count, int):
                  max_ac_count = final_ac_count
        else:
             print("Warning: Failed to select best result after comparing AC edit distances?")

    if not best_result:
        print("No AC result found, will filter best non-AC result based on AC count...")
        for result in judging_results:
            details = result.get("judge_details", {})
            if details.get("success") and details.get("final_status") != "CE" and isinstance(details.get("ac_count"), int):
                current_ac_count = details["ac_count"]
                if current_ac_count > max_ac_count:
                    print(f"Found new higher AC count: {current_ac_count} (from {result.get('source_model', 'Unknown')}, status: {details.get('final_status')}), currently the best.")
                    max_ac_count = current_ac_count
                    best_result = result
                elif current_ac_count == max_ac_count:
                     print(f"Found same AC count: {current_ac_count} (from {result.get('source_model', 'Unknown')}, status: {details.get('final_status')}), keeping the previous best.")

    response_payload = {
        "total_suggestions_received": total_suggestions,
        "judging_attempts": len(judging_results),
        "llm_errors": llm_errors if llm_errors else None,
        "best_suggestion": None,
        "all_judged_results": judging_results
    }

    if best_result:
        print(f"Found best suggestion (from {best_result['source_model']}): AC Count = {max_ac_count}", flush=True)
        response_payload["best_suggestion"] = {
            "code": best_result["code"],
            "source_model": best_result["source_model"],
            "judge_result": best_result["judge_details"]
        }
        response_payload["message"] = f"Found best suggestion, passed {max_ac_count} test cases."
        return response_payload, 200
    else:
        print("Failed to find any suggestion that successfully judged and passed some test cases.", flush=True)
        response_payload["message"] = "All suggestions failed to judge successfully or pass any test cases (or encountered compile errors)."
        return response_payload, 200

def fetch_problem_details(contest_id: str, problem_id: str) -> Tuple[Dict[str, Any], int]:
    if not contest_id or not problem_id:
        return {"error": "Missing contest_id or problem_id parameter"}, 400

    cache_path = _get_problem_cache_path(contest_id, problem_id)
    cached_data = read_cache(cache_path, is_json=True)
    if cached_data is not None:
        return cached_data, 200 

    problem_url = f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}"
    print(f"Fetching problem details from: {problem_url} (Cache Miss)")

    try:
        current_cookie_path = get_next_cookie_path()
        if not current_cookie_path:
             print("[Warning] No Cookie file found, will attempt to scrape problem information without authentication.")
             session = requests.Session()
        else:
             session = load_session_with_cookie_file(current_cookie_path)
             if not session:
                 print(f"[Warning] Unable to load Session from {os.path.basename(current_cookie_path)}, will attempt unauthenticated scraping.")
                 session = requests.Session()

        headers = {
            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
        }
        response = session.get(problem_url, headers=headers, timeout=15)
        response.raise_for_status() 

        soup = BeautifulSoup(response.text, 'lxml')

        title_span = soup.select_one('#main-container .h2')
        problem_title = title_span.get_text(strip=True) if title_span else f"Title not found for {problem_id}"

        statement_div = soup.select_one('#task-statement')
        if not statement_div:
            return {"error": f"Could not find problem statement div (#task-statement) at {problem_url}"}, 500

        english_statement_span = statement_div.select_one('span.lang-en')
        if english_statement_span:
            print("Found English statement span (.lang-en).")
            target_html_content = str(english_statement_span)
        else:
            print("Warning: Did not find English statement span (.lang-en). Using the whole #task-statement.")
            target_html_content = str(statement_div)

        try:
            h = html2text.HTML2Text()
            h.ignore_links = True 
            problem_description_markdown = h.handle(target_html_content)
        except Exception as e:
            print(f"html2text conversion failed: {e}")
            problem_description_markdown = "Error converting problem description to Markdown." 

        samples = []
        sections = statement_div.select('.part > section')
        input_text = None
        output_text = None
        sample_count = 0

        for section in sections:
            h3 = section.find('h3')
            pre = section.find('pre')
            if h3 and pre:
                header_text = h3.get_text(strip=True).lower()
                pre_text = pre.get_text()

                if "sample input" in header_text:
                    if input_text is not None and output_text is not None:
                        sample_count += 1
                        samples.append({"input": input_text, "output": output_text})
                        output_text = None 
                    input_text = pre_text
                elif "sample output" in header_text:
                    output_text = pre_text
        if input_text is not None and output_text is not None:
             sample_count += 1
             samples.append({"input": input_text, "output": output_text})

        if not samples:
             print(f"Warning: Could not find samples using selectors at {problem_url}")

        print(f"Successfully fetched: Title='{problem_title}', Samples Found={len(samples)}")

        try:
            samples_json = json.dumps(samples, ensure_ascii=False, indent=2)
        except TypeError:
            print("[Warning] Failed to serialize samples to JSON.")
            samples_json = "[]"

        result_data = {
            "title": problem_title,
            "description_markdown": problem_description_markdown,
            "samples_json": samples_json,
        }
        
        write_cache(cache_path, result_data, is_json=True)

        return result_data, 200

    except requests.exceptions.HTTPError as e:
         error_msg = f"HTTP error fetching problem: {e.response.status_code} for URL: {problem_url}"
         print(error_msg)
         return {"error": error_msg}, e.response.status_code
    except requests.exceptions.RequestException as e:
        error_msg = f"Error fetching problem details from {problem_url}: {e}"
        print(error_msg)
        return {"error": error_msg}, 500
    except Exception as e:
        error_msg = f"Error parsing problem details from {problem_url}: {e}"
        print(traceback.format_exc())
        return {"error": error_msg}, 500
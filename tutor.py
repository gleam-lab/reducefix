# atcoder_debugger.py
import os
import json
import re
import html2text # 需要安装： pip install html2text
from openai import OpenAI, BadRequestError
from concurrent.futures import ThreadPoolExecutor, as_completed
import shlex # 用于安全地格式化 curl 命令中的 JSON
import time # 添加 time 模块
import judge # <--- 添加 judge 模块导入
import requests # <--- Import requests for scraping
from bs4 import BeautifulSoup # <--- Import BeautifulSoup for scraping
import traceback # For detailed error logging
import Levenshtein # <--- Import Levenshtein library
from typing import Dict, Any, Optional, Tuple

# --- Import cookie and cache helpers from tools --- 
from tools import get_next_cookie_path, load_session_with_cookie_file
from tools import read_cache, write_cache, _get_problem_cache_path

# --- 配置 (Hardcoded API Keys and Base URLs) ---
# !! 请将下面的占位符替换为你的实际 API 密钥和 Base URL !!
DEEPSEEK_API_KEY = 'sk-78a884bc7162400b89b72ff35d90d83f' # <--- 在这里替换你的 DeepSeek Key
DEEPSEEK_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1' # <--- 在这里替换 DeepSeek Base URL (如果需要)

# 假设 Qwen 提供 OpenAI 兼容接口
QWEN_API_KEY = 'sk-78a884bc7162400b89b72ff35d90d83f' # <--- 在这里替换你的 Qwen Key (已移除末尾制表符)
QWEN_BASE_URL = 'https://dashscope.aliyuncs.com/compatible-mode/v1' # <--- 在这里替换 Qwen Base URL (如果需要)

# --- 初始化 API 客户端 ---
deepseek_client = None
qwen_client = None

# 检查硬编码的 Key 是否为占位符
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
        # 假设 Qwen 使用与 OpenAI 相同的库和认证方式
        qwen_client = OpenAI(api_key=QWEN_API_KEY, base_url=QWEN_BASE_URL)
        print("Qwen client configured using hardcoded credentials.")
    except Exception as e:
        print(f"Failed to configure Qwen client with hardcoded credentials: {e}")
else:
    if not QWEN_API_KEY or QWEN_API_KEY == 'YOUR_QWEN_API_KEY':
        print("Qwen API key is missing or still a placeholder in the code. Please replace 'YOUR_QWEN_API_KEY'.")
    if not QWEN_BASE_URL:
        print("Qwen Base URL is missing in the code.")


# --- Flask 应用 ---
# app = Flask(__name__, template_folder='templates', static_folder='static')
# CORS(app) # 允许所有来源的 CORS 请求

# --- 常量 ---
DEFAULT_LANGUAGE = 'cpp' # C++
ATCODER_CPP_LANG_ID = '5001' # AtCoder C++ (GCC) Language ID
LLM_REQUEST_COUNT = 2 # 每个 LLM 请求的建议数量
JUDGE_POLL_ATTEMPTS = 60 # 评测状态轮询次数
JUDGE_POLL_WAIT = 5 # 评测状态轮询间隔 (秒)

# --- Cookie Management (REMOVED - Now in tools.py) ---
# COOKIE_DIR_PATH, AVAILABLE_COOKIE_FILES, current_cookie_index, cookie_load_lock removed
# load_cookie_files function removed
# get_next_cookie_path function removed

# --- 工具函数 ---

def extract_longest_code_block(text):
    """从文本中提取最长的代码块 (Markdown格式)"""
    if not text:
        return None
    # 匹配 ```cpp ... ``` 或 ``` ... ```
    # 改进正则以处理可选的语言标识符
    code_blocks = re.findall(r'```(?:cpp|c\+\+|)\s*\n?(.*?)```', text, re.DOTALL)
    if not code_blocks:
         # 如果没有找到 ``` 块，尝试匹配没有标记的纯代码块
         # 仅当文本看起来像代码时（例如，包含 #include 或 main）
         lines = text.strip().splitlines()
         # 更宽松的检查，允许 // 或 /* 开头
         if len(lines) > 1 and any(l.strip().startswith(('#include', 'int main', 'using namespace', '//', '/*')) for l in lines):
             return text.strip()
         return None
    # 返回最长的代码块
    return max(code_blocks, key=len).strip()

def normalize_whitespace(code_str):
    """Removes leading/trailing whitespace and compresses internal whitespace."""
    if not code_str:
        return ""
    # Replace all whitespace sequences (space, tab, newline, etc.) with a single space
    normalized = re.sub(r'\s+', ' ', code_str)
    return normalized.strip() # Remove leading/trailing space

def build_debug_prompt(problem_title, problem_description, language, code, samples, judge_status=None, compile_error=None):
    """构建调试任务的提示信息 (简化版)"""
    prompts = []

    # 1. 问题上下文
    # 假设 problem_description 是 HTML 格式
    try:
        # 使用 ignore_links=True 避免生成 Markdown 链接
        h = html2text.HTML2Text()
        h.ignore_links = True
        description_text = h.handle(problem_description)
    except Exception as e:
        print(f"html2text 处理时出错: {e}")
        description_text = problem_description # Fallback if html2text fails

    prompt = f'我正在用 {language} 语言解决 AtCoder 上的算法问题，需要帮助调试。请仔细阅读以下信息。\n\n'
    prompt += f'# 题目: {problem_title}\n\n{description_text}\n'

    # 2. 样例数据
    if samples:
        prompt += "\n## 样例数据\n"
        try:
            # 假设 samples 是 JSON 字符串: '[{"input": "...", "output": "..."}, ...]'
            samples_list = json.loads(samples)
            for i, sample in enumerate(samples_list):
                input_text = sample.get('input', '')
                output_text = sample.get('output', '')
                prompt += f"\n### 样例 {i+1}\n"
                prompt += f"输入:\n```\n{input_text}\n```\n"
                prompt += f"输出:\n```\n{output_text}\n```\n"
        except (json.JSONDecodeError, TypeError) as e:
            print(f"解析样例数据时出错: {e}")
            prompt += f"\n(无法解析样例数据: {samples})\n" # 包含原始字符串以便调试
        prompt += "\n"

    prompts.append(prompt)

    # 3. 用户代码及状态
    code_prompt = f'## 我的代码和状态\n\n我的代码如下:\n```{language}\n{code}\n```\n'
    if judge_status:
        code_prompt += f"\n判题状态: {judge_status}\n"
    if compile_error:
        # 简单处理编译错误信息
        code_prompt += f"\n编译信息:\n```\n{compile_error}\n```\n"
    prompts.append(code_prompt)

    # 4. 对 LLM 的指令
    instruction_prompt = (
        "## 你的任务\n"
        "请仔细分析我提供的题目描述、样例、我的代码以及判题/编译状态，找出代码中的错误并进行修复。\n\n"
        "**要求:**\n"
        "1.  **最小改动**: 尽可能少地修改我的代码，保持原有的代码风格和变量命名。\n"
        "2.  **仅返回代码**: 你的回答应该**只包含**修复后的完整 C++ 代码块，使用 ```cpp ... ``` 标记包围。**不要**包含任何解释、分析、道歉或额外的对话文字。\n"
        "3.  **专注修复**: 你的目标是修复代码中的错误，使其能够正确解决问题。不要添加无关的功能或进行不必要的代码重构。\n\n"
        "请直接给出修复后的代码。"
    )
    prompts.append(instruction_prompt)
    return prompts

def get_llm_suggestions(client: OpenAI, model_name: str, history: list, count: int = 1, max_tokens: int = 2048, temperature: float = 0.1):
    """向指定模型发送请求并获取多个代码建议 (处理 n > 1)"""
    if not client:
        return [], f"模型 '{model_name}' 的客户端未配置或配置失败。"

    thread_history = history.copy() # 确保线程安全
    suggestions = []
    error_message = None

    # --- Force n=1 calls for all models to avoid potential instability with n > 1 --- 
    # The original logic for attempting n > 1 and falling back is removed.

    print(f"准备向 {model_name} (Base URL: {client.base_url}) 发起 {count} 次单独请求 (n=1)...", flush=True)

    try:
        for i in range(count):
            print(f"  > 向 {model_name} 发起第 {i+1}/{count} 次请求 (n=1)...", flush=True)
            chat_completion = client.chat.completions.create(
                model=model_name,
                messages=thread_history,
                temperature=temperature,
                max_tokens=max_tokens,
                n=1, # Force n=1
                timeout=180, # Timeout per single request
            )
            if chat_completion.choices:
                response_content = chat_completion.choices[0].message.content
                fixed_code = extract_longest_code_block(response_content)
                if fixed_code:
                    print(f"    >> 从 {model_name} 第 {i+1} 次请求提取到代码。", flush=True)
                    suggestions.append(fixed_code)
                else:
                    print(f"    >> 未能从 {model_name} 第 {i+1} 次请求提取代码块。响应: {response_content[:100]}...", flush=True)
                    if error_message is None:
                        error_message = f"模型 '{model_name}' 的至少一个响应未能提取有效的代码块。"
            else:
                    print(f"    >> {model_name} 第 {i+1} 次请求未返回有效 choice。", flush=True)
            # Optional delay between loop calls if needed
            # time.sleep(0.2)

    except Exception as e:
        # 捕获其他所有错误，包括连接错误
        error_message = f"调用 {model_name} 时发生一般错误: {type(e).__name__}: {e}"
        print(error_message, flush=True)

    # 最终检查是否有建议，如果没有且无错误信息，则设置一个通用错误信息
    if not suggestions and error_message is None:
        error_message = f"模型 '{model_name}' 未返回任何有效的代码建议或提取失败。"

    return suggestions, error_message

# --- Core Logic Functions (Formerly Flask Routes) ---

def process_debug_request(data: Dict[str, Any]) -> Tuple[Dict[str, Any], int]:
    """Processes the debug request data and returns results."""
    # --- 提取和校验必要字段 ---
    problem_title = data.get('problem_title')
    problem_description = data.get('problem_description') # HTML
    language = data.get('language', DEFAULT_LANGUAGE)
    code = data.get('code')
    samples = data.get('samples') # JSON string
    judge_status = data.get('judge_status') # Optional
    compile_error = data.get('compile_error') # Optional
    contest_id = data.get('contest_id') # 新增
    problem_id = data.get('problem_id') # 新增
    # cookie_file_path = data.get('cookie_file_path', DEFAULT_COOKIE_PATH) # Not used anymore

    required_fields = ["problem_title", "problem_description", "code", "contest_id", "problem_id"]
    missing_fields = [field for field in required_fields if not data.get(field)]
    if missing_fields:
        return {"error": f"缺少必要字段: {', '.join(missing_fields)}"}, 400 # Return error dict

    if language.lower() != 'cpp':
         return {"error": f"目前仅支持 C++ ({DEFAULT_LANGUAGE}) 语言"}, 400 # Return error dict

    print("收到调试请求，正在准备...")

    # --- 构建 LLM 消息历史 ---
    system_prompt = "你是一个专门修复 C++ 算法竞赛代码的 AI 助手。请根据用户提供的题目信息和代码，找出错误并给出修复后的完整代码。你的回答必须只包含代码本身，用 ```cpp ... ``` 包裹。"
    prompts_content = build_debug_prompt(
        problem_title, problem_description, language, code, samples, judge_status, compile_error
    )
    history = [{'role': 'system', 'content': system_prompt}]
    for content in prompts_content:
        history.append({'role': 'user', 'content': content})

    # --- 并发调用 LLM 获取建议 ---
    all_suggestions = []
    llm_errors = {}
    models_to_run = []
    if deepseek_client:
        models_to_run.append({"client": deepseek_client, "name": "deepseek-v3"})
    if qwen_client:
        models_to_run.append({"client": qwen_client, "name": "qwen-plus"}) 

    if not models_to_run:
        return {"error": "没有配置任何 LLM 客户端。"}, 500 # Return error dict

    model_names_str = ", ".join([m['name'] for m in models_to_run])
    print(f"准备调用模型: {model_names_str} (每个模型请求 {LLM_REQUEST_COUNT} 个建议)", flush=True)

    with ThreadPoolExecutor(max_workers=len(models_to_run)) as executor:
        future_to_model = {
            executor.submit(get_llm_suggestions, model_info["client"], model_info["name"], history, count=LLM_REQUEST_COUNT): model_info["name"]
            for model_info in models_to_run
        }
        for future in as_completed(future_to_model):
            model_name = future_to_model[future]
            try:
                print(f"正在等待模型 {model_name} 的响应...")
                suggestions_list, error = future.result()
                if error:
                    llm_errors[model_name] = error
                    print(f"模型 {model_name} 调用出错: {error}") 
                if suggestions_list:
                    for sugg_code in suggestions_list:
                         all_suggestions.append({"code": sugg_code, "source_model": model_name})
                    print(f"从 {model_name} 收集到 {len(suggestions_list)} 个建议。", flush=True)
            except Exception as exc:
                error_msg = f'{model_name} 执行时产生异常: {exc}'
                print(error_msg, flush=True)
                llm_errors[model_name] = error_msg

    if not all_suggestions:
        error_summary = "未能从任何模型获取有效的代码建议。"
        if llm_errors:
             error_summary += " 错误详情: " + json.dumps(llm_errors)
        return {"error": error_summary}, 500 # Return error dict

    total_suggestions = len(all_suggestions)
    print(f"共收集到 {total_suggestions} 个代码建议，准备进行评测...", flush=True)

    # --- 对每个建议进行评测 ---
    judging_results = []
    for i, suggestion in enumerate(all_suggestions):
        status_msg = f'[{i+1}/{total_suggestions}] 正在提交来自 {suggestion["source_model"]} 的建议进行评测...'
        print(status_msg, flush=True)

        # Get cookie path using the imported function from tools
        current_cookie_path = get_next_cookie_path() 
        if not current_cookie_path:
            error_msg = "错误：无法获取用于评测的 Cookie 文件。请确保存储 Cookie 的目录配置正确且文件存在。"
            print(error_msg, flush=True)
            # Append error result and continue to next suggestion
            judging_results.append({
                "code": suggestion['code'],
                "source_model": suggestion['source_model'],
                "judge_details": {"success": False, "final_status": "Cookie Error", "ac_count": 0, "error_message": "No cookie file available via tools.get_next_cookie_path()"}
            })
            continue # Skip judging this suggestion

        try: 
            # Pass the obtained cookie path to judge
            judge_result = judge.submit_and_get_results(
                contest_id=contest_id,
                problem_id=problem_id,
                code_str=suggestion['code'],
                language_id=ATCODER_CPP_LANG_ID, 
                cookie_file_path=current_cookie_path, # Use the path obtained from tools
                max_poll_attempts=JUDGE_POLL_ATTEMPTS,
                poll_wait_seconds=JUDGE_POLL_WAIT
            )
            print(f"评测结果: Success={judge_result['success']}, Status={judge_result['final_status']}, AC Count={judge_result['ac_count']}, Err={judge_result['error_message']}", flush=True)
            judging_results.append({
                "code": suggestion['code'],
                "source_model": suggestion['source_model'],
                "judge_details": judge_result
            })
            result_status_msg = f'[{i+1}/{total_suggestions}] 评测完成 (来自 {suggestion["source_model"]}): 状态={judge_result.get("final_status", "未知")}, AC={judge_result.get("ac_count", "N/A")}'
            if not judge_result.get('success'):
                 result_status_msg += f', 错误: {judge_result.get("error_message", "未知评测错误")}'
                 print(f"评测 {i+1} 警告: {result_status_msg}") 
            else:
                 print(f"评测 {i+1} 成功: {result_status_msg}") 

        except Exception as judge_exc:
             error_msg = f'评测建议 {i+1} (来自 {suggestion["source_model"]}) 时发生错误: {judge_exc}'
             print(error_msg, flush=True)
             judging_results.append({
                 "code": suggestion['code'],
                 "source_model": suggestion['source_model'],
                 "judge_details": {"success": False, "final_status": "Judge Error", "ac_count": 0, "error_message": str(judge_exc)}
             })

        time.sleep(1) 

    # --- 筛选最佳结果 ---
    best_result = None
    ac_results = []
    max_ac_count = -1 
    min_edit_distance = float('inf') 

    print("\n开始筛选最佳结果...")
    
    for result in judging_results:
        details = result.get("judge_details", {})
        if details.get("success") and details.get("final_status") == "AC":
            print(f"找到 AC 结果 (来自 {result.get('source_model', '未知')})。")
            ac_results.append(result)

    if len(ac_results) == 1:
        best_result = ac_results[0]
        print(f"只有一个 AC 结果，选择它作为最佳。")
        ac_details = best_result.get("judge_details", {})
        final_ac_count = ac_details.get("ac_count")
        if isinstance(final_ac_count, int):
             max_ac_count = final_ac_count
    elif len(ac_results) > 1:
        print(f"找到 {len(ac_results)} 个 AC 结果，将根据与原始代码的编辑距离进行选择...")
        original_code = data.get('code', '') 
        best_ac_result_by_distance = None

        for ac_result in ac_results:
            normalized_original = normalize_whitespace(original_code)
            normalized_suggested = normalize_whitespace(ac_result.get('code', ''))
            distance = Levenshtein.distance(normalized_original, normalized_suggested)
            print(f"  - 来自 {ac_result.get('source_model', '未知')} 的 AC 代码，编辑距离: {distance}")
            if distance < min_edit_distance:
                min_edit_distance = distance
                best_ac_result_by_distance = ac_result
                print(f"    ^-- 当前编辑距离最小。")
            elif distance == min_edit_distance:
                 print(f"    ^-- 编辑距离与当前最小相同，保留第一个找到的。")

        best_result = best_ac_result_by_distance
        if best_result:
             print(f"选择编辑距离最小 ({min_edit_distance}) 的 AC 结果作为最佳。")
             ac_details = best_result.get("judge_details", {})
             final_ac_count = ac_details.get("ac_count")
             if isinstance(final_ac_count, int):
                  max_ac_count = final_ac_count
        else:
             print("警告：比较 AC 编辑距离后未能选出最佳结果？")

    if not best_result:
        print("未找到 AC 结果，将根据 AC 数量筛选非 AC 的最佳结果...")
        for result in judging_results:
            details = result.get("judge_details", {})
            if details.get("success") and details.get("final_status") != "CE" and isinstance(details.get("ac_count"), int):
                current_ac_count = details["ac_count"]
                if current_ac_count > max_ac_count:
                    print(f"找到新的更高 AC 数量: {current_ac_count} (来自 {result.get('source_model', '未知')}，状态: {details.get('final_status')})，当前最佳。")
                    max_ac_count = current_ac_count
                    best_result = result
                elif current_ac_count == max_ac_count:
                     print(f"找到相同 AC 数量: {current_ac_count} (来自 {result.get('source_model', '未知')}，状态: {details.get('final_status')})，保留之前的最佳。")

    # --- 返回结果 --- # <-- 修改为返回字典
    response_payload = {
        "total_suggestions_received": total_suggestions,
        "judging_attempts": len(judging_results),
        "llm_errors": llm_errors if llm_errors else None,
        "best_suggestion": None,
        "all_judged_results": judging_results
    }

    if best_result:
        print(f"找到最佳建议 (来自 {best_result['source_model']}): AC Count = {max_ac_count}", flush=True)
        response_payload["best_suggestion"] = {
            "code": best_result["code"],
            "source_model": best_result["source_model"],
            "judge_result": best_result["judge_details"]
        }
        response_payload["message"] = f"找到最佳建议，通过了 {max_ac_count} 个测试点。"
        return response_payload, 200 # Return dict and status code
    else:
        print("未能找到任何成功评测且通过部分测试点的建议。", flush=True)
        response_payload["message"] = "所有建议均未能成功评测或通过任何测试点（或遇到编译错误）。"
        return response_payload, 200 # Return dict and status code

def fetch_problem_details(contest_id: str, problem_id: str) -> Tuple[Dict[str, Any], int]:
    """Fetches problem details from AtCoder, using cache if available."""
    if not contest_id or not problem_id:
        return {"error": "Missing contest_id or problem_id parameter"}, 400

    # --- Cache Check ---
    cache_path = _get_problem_cache_path(contest_id, problem_id)
    cached_data = read_cache(cache_path, is_json=True)
    if cached_data is not None:
        # Assuming we cache the successful result dictionary directly
        return cached_data, 200 
    # --- End Cache Check ---

    problem_url = f"https://atcoder.jp/contests/{contest_id}/tasks/{problem_id}"
    print(f"Fetching problem details from: {problem_url} (Cache Miss)")

    try:
        # Get cookie path using the imported function from tools
        current_cookie_path = get_next_cookie_path()
        if not current_cookie_path:
             print("[Warning] 未找到 Cookie 文件，将尝试无认证爬取题目信息。")
             session = requests.Session() # Create session without cookies
        else:
             # Load session using the path obtained from tools
             session = load_session_with_cookie_file(current_cookie_path)
             if not session:
                 print(f"[Warning] 无法从 {os.path.basename(current_cookie_path)} 加载 Session，将尝试无认证爬取。")
                 session = requests.Session() # Fallback to session without cookies

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

        # --- Convert samples to JSON string --- 
        try:
            samples_json = json.dumps(samples, ensure_ascii=False, indent=2)
        except TypeError:
            print("[Warning] Failed to serialize samples to JSON.")
            samples_json = "[]"

        # Prepare result dictionary
        result_data = {
            "title": problem_title,
            "description_markdown": problem_description_markdown,
            "samples_json": samples_json,
        }
        
        # --- Write to Cache on Success ---
        write_cache(cache_path, result_data, is_json=True)
        # --- End Write to Cache ---

        return result_data, 200

    except requests.exceptions.HTTPError as e:
         error_msg = f"HTTP error fetching problem: {e.response.status_code} for URL: {problem_url}"
         print(error_msg)
         return {"error": error_msg}, e.response.status_code # Don't cache errors
    except requests.exceptions.RequestException as e:
        error_msg = f"Error fetching problem details from {problem_url}: {e}"
        print(error_msg)
        return {"error": error_msg}, 500 # Don't cache errors
    except Exception as e:
        error_msg = f"Error parsing problem details from {problem_url}: {e}"
        print(traceback.format_exc())
        return {"error": error_msg}, 500 # Don't cache errors
# llm.py
import os
import re
import sys
import time
import traceback
from typing import Optional, List, Dict
import json
import requests

# Import configurations from config.py
try:
    # Add current script directory to FRONT of path to avoid conflicts
    _script_dir = os.path.dirname(os.path.abspath(__file__))
    # Remove any existing entries and add to front
    sys.path = [p for p in sys.path if p != _script_dir]
    sys.path.insert(0, _script_dir)
    
    # Force reload if already imported
    if 'config' in sys.modules:
        import importlib
        importlib.reload(sys.modules['config'])
    
    from config import (
        DEFAULT_MODEL, DEFAULT_MAX_TOKENS, DEFAULT_TEMPERATURE, DEFAULT_TIMEOUT,
        BAIDU_QIANFAN_URL, BAIDU_QIANFAN_TOKEN,
        MAX_BAIDU_TOKENS, BAIDU_RATE_LIMIT_BACKOFF, BAIDU_RATE_LIMIT_RETRIES
    )
except ImportError as e:
    print(f"[LLM Init Warning] config.py not found ({e}), using default values", file=sys.stderr)
    DEFAULT_MODEL = "qwen-plus"
    DEFAULT_MAX_TOKENS = 4096
    DEFAULT_TEMPERATURE = 0.0
    DEFAULT_TIMEOUT = 300
    BAIDU_QIANFAN_URL = "https://qianfan.baidubce.com/v2/chat/completions"
    BAIDU_QIANFAN_TOKEN = ""
    MAX_BAIDU_TOKENS = 3000
    BAIDU_RATE_LIMIT_BACKOFF = 30
    BAIDU_RATE_LIMIT_RETRIES = 5

# Attempt to import the client from tutor.py
try:
    import tutor
    if not hasattr(tutor, 'qwen_client') or not tutor.qwen_client:
        print("[LLM Init Error] Qwen client (tutor.qwen_client) not found or not initialized in tutor.py.", file=sys.stderr)
        qwen_client = None
    else:
        qwen_client = tutor.qwen_client
        print("[LLM Init Info] Successfully accessed tutor.qwen_client.")
except ImportError:
    print("[LLM Init Error] Failed to import 'tutor' module. LLM calls will fail.", file=sys.stderr)
    qwen_client = None
except Exception as e:
    print(f"[LLM Init Error] Unexpected error importing/accessing tutor client: {e}", file=sys.stderr)
    traceback.print_exc()
    qwen_client = None


def _rough_token_count(text: str) -> int:
    """Roughly estimate token count; prioritize tiktoken, fallback to character length/3 if unavailable."""
    try:
        import tiktoken  # type: ignore
        enc = tiktoken.get_encoding("cl100k_base")
        return len(enc.encode(text))
    except Exception:
        return max(1, len(text) // 3)


def _estimate_messages_tokens(messages: List[Dict[str, str]]) -> int:
    return sum(_rough_token_count(m.get("content", "")) for m in messages)


# ----------------------- Baidu Qianfan Helper -----------------------

def call_baidu_llm(
    prompt_history: List[Dict[str, str]],
    model_name: str,
    temperature: float,
    max_tokens: int,
    timeout: int,
    stream: bool = True,
    retries_left: int = BAIDU_RATE_LIMIT_RETRIES,
) -> Optional[str]:
    """
    Call Baidu Qianfan LLM chat/completions API for conversation requests.

    Currently only implements non-streaming calls, streaming support can be added later if needed.
    """

    if not BAIDU_QIANFAN_TOKEN:
        print("[Error] BAIDU_QIANFAN_TOKEN environment variable not set, cannot call Baidu Qianfan API.", file=sys.stderr)
        return None

    # ========= Truncate overly long input =========
    total_tokens_est = _estimate_messages_tokens(prompt_history)
    if total_tokens_est > MAX_BAIDU_TOKENS:
        excess = total_tokens_est - MAX_BAIDU_TOKENS
        approx_char_per_token = 3  # Corresponds to _rough_token_count
        cut_chars = excess * approx_char_per_token + 128  # Extra buffer

        # Only truncate the last message content
        last_idx = len(prompt_history) - 1
        last_content = prompt_history[last_idx]["content"]
        if len(last_content) > cut_chars:
            prompt_history = prompt_history.copy()
            prompt_history[last_idx] = prompt_history[last_idx].copy()
            prompt_history[last_idx]["content"] = last_content[:-cut_chars]
            print(
                f"[Info] Total tokens≈{total_tokens_est}>={MAX_BAIDU_TOKENS}, truncated last message by {cut_chars} characters.",
                file=sys.stderr,
            )
        else:
            print(
                f"[Warning] Need to truncate {cut_chars} characters, but last message length insufficient, keeping original.",
                file=sys.stderr,
            )

    payload = {
        "model": model_name,
        "messages": prompt_history,
        "temperature": temperature,
        "stream": stream,
    }

    headers = {
        "Content-Type": "application/json",
        "Authorization": f"Bearer {BAIDU_QIANFAN_TOKEN}",
    }

    try:
        start_time = time.time()
        resp = requests.post(
            BAIDU_QIANFAN_URL,
            headers=headers,
            json=payload,
            timeout=timeout,
            stream=stream,
        )

        elapsed = time.time() - start_time
        print(f"[Info] Baidu Qianfan HTTP request sent, took {elapsed:.2f}s, status {resp.status_code}.")

        if resp.status_code != 200:
            print(f"[Error] Baidu Qianfan API returned non-200 status code: {resp.status_code}, response: {resp.text}", file=sys.stderr)
            return None

        final_response_content = ""

        if stream:
            print("\n" + "="*20 + " Baidu Qianfan Response Stream " + "="*20 + "\n")
            for raw_line in resp.iter_lines(decode_unicode=True):
                if not raw_line:
                    continue  # Skip heartbeat or empty lines
                line = raw_line.strip()
                # Handle data: prefix compatibility
                if line.startswith("data:"):
                    line = line[len("data:"):].strip()
                if line == "[DONE]":
                    break
                try:
                    data_json = json.loads(line)
                except Exception:
                    print(f"[Warning] Failed to parse JSON: {line}", file=sys.stderr)
                    continue

                delta_content = None
                # Qianfan streaming currently uses 'result' field for continuous output
                if "result" in data_json:
                    delta_content = data_json["result"]
                elif data_json.get("choices"):
                    delta = data_json["choices"][0].get("delta") or {}
                    delta_content = delta.get("content")

                if delta_content:
                    final_response_content += delta_content
                    print(delta_content, end="", flush=True)

            print()  # Final newline
        else:
            data = resp.json()

            # If contains error_code and not 0, consider API returning error
            if data.get("error_code") and data.get("error_code") != 0:
                print(f"[Error] Baidu Qianfan API error {data.get('error_code')}: {data.get('error_msg')}", file=sys.stderr)
                return None

            # OpenAI compatible format
            if data.get("choices"):
                final_response_content = data["choices"][0]["message"]["content"]
            # Qianfan native format
            elif data.get("result"):
                final_response_content = data["result"]
            else:
                print("[Warning] Cannot extract result content from Baidu Qianfan response.", file=sys.stderr)
                return None

        # --------- Rate Limit Handling ---------
        if resp.status_code == 429:
            try:
                err_json = resp.json()
                err_code = err_json.get("error", {}).get("code") or err_json.get("error_code")
            except Exception:
                err_code = None

            if err_code == "tpm_rate_limit_exceeded" and retries_left > 0:
                print(
                    f"[Warning] TPM rate limit exceeded. Will retry in {BAIDU_RATE_LIMIT_BACKOFF}s, {retries_left} retries left.",
                    file=sys.stderr,
                )
                time.sleep(BAIDU_RATE_LIMIT_BACKOFF)
                return call_baidu_llm(
                    prompt_history=prompt_history,
                    model_name=model_name,
                    temperature=temperature,
                    max_tokens=max_tokens,
                    timeout=timeout,
                    stream=stream,
                    retries_left=retries_left - 1,
                )

        # For non-streaming and HTTP 200 cases, if response body still indicates rate limit, retry
        if not stream and "data" in locals():
            err_code_inner = data.get("error", {}).get("code") or data.get("error_code")
            if err_code_inner == "tpm_rate_limit_exceeded" and retries_left > 0:
                print(
                    f"[Warning] TPM rate limit exceeded (200). Retry in {BAIDU_RATE_LIMIT_BACKOFF}s, {retries_left} retries left.",
                    file=sys.stderr,
                )
                time.sleep(BAIDU_RATE_LIMIT_BACKOFF)
                return call_baidu_llm(
                    prompt_history=prompt_history,
                    model_name=model_name,
                    temperature=temperature,
                    max_tokens=max_tokens,
                    timeout=timeout,
                    stream=stream,
                    retries_left=retries_left - 1,
                )

        return final_response_content

    except Exception as e:
        print(f"[Error] Failed to call Baidu Qianfan API: {type(e).__name__}: {e}", file=sys.stderr)
        traceback.print_exc()
        return None

def call_llm(
    prompt_history: List[Dict[str, str]],
    model_name: str = DEFAULT_MODEL,
    temperature: float = DEFAULT_TEMPERATURE,
    max_tokens: int = DEFAULT_MAX_TOKENS,
    timeout: int = DEFAULT_TIMEOUT,
    stream: bool = True # Keep streaming enabled by default for feedback
) -> Optional[str]:
    """
    Calls the configured Qwen LLM with the provided prompt history.

    Args:
        prompt_history: A list of message dictionaries (e.g., [{'role': 'user', 'content': '...'}]).
        model_name: The name of the LLM model to use.
        temperature: The sampling temperature.
        max_tokens: The maximum number of tokens to generate.
        timeout: Request timeout in seconds.
        stream: Whether to use streaming mode.

    Returns:
        The final concatenated response content as a string, or None if an error occurred
        or the client is unavailable.
    """
    # Auto-select backend based on model name: contains 'qwen' -> Alibaba Qwen; otherwise use Baidu Qianfan
    if 'qwen' not in model_name.lower():
        return call_baidu_llm(
            prompt_history=prompt_history,
            model_name=model_name,
            temperature=temperature,
            max_tokens=max_tokens,
            timeout=timeout,
            stream=stream,
        )

    if not qwen_client:
        print("[Error] LLM client is not available. Cannot make API call.", file=sys.stderr)
        return None

    print(f"[Info] Sending request to LLM: {model_name} (Temp: {temperature}, Max Tokens: {max_tokens})...")
    final_response_content = ""
    start_time = time.time()

    try:
        if stream:
            chat_completion = qwen_client.chat.completions.create(
                model=model_name,
                messages=prompt_history,
                temperature=temperature,
                max_tokens=max_tokens,
                stream=True,
                timeout=timeout,
            )
            print(f"[Info] LLM stream initiated in {time.time() - start_time:.2f} seconds.")
            print("\n" + "="*20 + " LLM Response Stream " + "="*20 + "\n")
            stream_start_time = time.time()

            for chunk in chat_completion:
                if chunk.choices and hasattr(chunk.choices[0], 'delta') and chunk.choices[0].delta.content:
                    content_chunk = chunk.choices[0].delta.content
                    final_response_content += content_chunk
                    print(content_chunk, end="", flush=True) # Print final answer live

            print() # Newline after stream
            print(f"[Info] Finished receiving stream in {time.time() - stream_start_time:.2f} seconds.")

        else: # Non-streaming call
             chat_completion = qwen_client.chat.completions.create(
                model=model_name,
                messages=prompt_history,
                temperature=temperature,
                max_tokens=max_tokens,
                stream=False,
                timeout=timeout,
            )
             print(f"[Info] LLM non-streaming call completed in {time.time() - start_time:.2f} seconds.")
             if chat_completion.choices:
                 final_response_content = chat_completion.choices[0].message.content
             else:
                  print("[Warning] LLM response did not contain expected choices.", file=sys.stderr)
                  final_response_content = "" # Or None? Let's return empty string for now

        print(f"[Info] Received Final Response Length: {len(final_response_content)}")
        return final_response_content

    except Exception as e:
        print(f"[Error] LLM API call failed: {type(e).__name__}: {e}", file=sys.stderr)
        traceback.print_exc()
        return None


def extract_python_code(text: Optional[str]) -> Optional[str]:
    """
    Extracts the first Python code block from text marked with ```python or ```.
    Handles potential edge cases like empty input or no blocks found.
    """
    if not text:
        return None

    # Prioritize ```python blocks, including optional newline after marker
    match_python = re.search(r'```python\s*\n?(.*?)```', text, re.DOTALL)
    if match_python:
        return match_python.group(1).strip()

    # Fallback to generic ``` blocks
    match_generic = re.search(r'```\s*\n?(.*?)```', text, re.DOTALL)
    if match_generic:
        return match_generic.group(1).strip()

    # Fallback: if the whole text looks like code (simple heuristic)
    # Check if it contains typical Python keywords/structures and multiple lines
    lines = text.strip().splitlines()
    if len(lines) > 1 and ('def ' in text or 'import ' in text or 'class ' in text or 'print(' in text):
        print("[Warning] No ``` markers found, but text looks like Python code. Returning entire text.", file=sys.stderr)
        return text.strip()

    print("[Warning] Could not extract Python code block using ```python or ``` markers.", file=sys.stderr)
    return None # Explicitly return None if no code block is found 
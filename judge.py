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
                           cookie_file_path: str = "/home/barty/.local/share/online-judge-tools/cookie.jar",
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
    print(f"[Core] 尝试从 {cookie_file_path} 加载会话...")
    session = load_session_with_cookie_file(cookie_file_path)
    if session is None:
        result["error_message"] = f"无法加载 cookie 文件: {cookie_file_path}"
        return result
    service = AtCoderService()
    problem = AtCoderProblem(contest_id=contest_id, problem_id=problem_id)
    try:
        print("[Core] 验证 Cookie 有效性...")
        _ = [language.id for language in problem.get_available_languages(session=session)]
        print("[Core] Cookie 验证成功！")
    except NotLoggedInError:
        result["error_message"] = "Cookie 无效或已过期"
        return result
    except Exception as e:
        result["error_message"] = f"验证 Cookie 时出错: {e}"
        if isinstance(e, requests.exceptions.HTTPError) and e.response.status_code == 404:
             result["error_message"] += f". 无法找到比赛 '{contest_id}' 或题目 '{problem_id}'。"
        return result
    submission = None
    try:
        print(f"[Core] 提交代码到 {problem.get_url()} 使用语言 {language_id}...")
        code_bytes = code_str.encode('utf-8')
        submission = problem.submit_code(code_bytes, language_id, session=session)
        result["submission_url"] = submission.get_url()
        print(f"[Core] 提交成功！URL: {result['submission_url']}")
    except NotLoggedInError:
        result["error_message"] = "提交失败：未登录或 Session 过期"
        return result
    except SubmissionError as e:
        result["error_message"] = f"提交失败: {e}"
        return result
    except Exception as e:
        print(traceback.format_exc())
        result["error_message"] = f"提交过程中发生意外错误: {type(e).__name__}: {e}"
        return result
    if submission:
        print("[Core] 开始查询评测状态...")
        submission_url = result["submission_url"]
        final_status = None
        basic_pending_statuses = {"WJ", "WR", "Judging", "Compiling"}
        partial_status_pattern = re.compile(r"^\d+/\d+$")

        for attempt in range(max_poll_attempts):
            current_status = get_submission_status(submission_url, session)
            if current_status is None:
                print(f"[Core] 第 {attempt + 1} 次尝试获取状态失败，{poll_wait_seconds} 秒后重试...")
            elif current_status in basic_pending_statuses or partial_status_pattern.match(current_status):
                print(f"[Core] 当前状态: {current_status} (尝试 {attempt + 1}/{max_poll_attempts})，{poll_wait_seconds} 秒后重试...")
            else:
                final_status = current_status
                print(f"[Core] 获取到最终状态: {final_status}")
                break
            time.sleep(poll_wait_seconds)
        else:
            print("[Core] 查询超时，未能获取到最终评测状态。")
            final_status = current_status

        result["final_status"] = final_status

        # -- 修改开始: 无论失败还是 AC，都尝试获取 Case 详情/AC 数量 --
        # 定义需要查询详情的状态集合 (失败状态 + AC 状态)
        statuses_to_get_details = {"WA", "TLE", "MLE", "RE", "OLE", "AC"}

        if final_status in statuses_to_get_details:
            print(f"[Core] 状态为 {final_status}，查询 Case 详情/AC 数量...")
            # 稍微等待一下，确保页面更新完毕
            time.sleep(1)
            failed_name, failed_status, _, ac_count = get_first_failed_case_info(submission_url, session)

            result["ac_count"] = ac_count # 始终记录 ac_count (可能是 None)

            if final_status == "AC":
                 if ac_count is not None:
                     print(f"[Core] 评测通过！共通过 {ac_count} 个测试点。")
                 else:
                     print("[Core] 评测通过！但未能解析通过的测试点数量。")
            elif failed_name is None and ac_count is None:
                 # 针对失败状态，但解析失败的情况
                 print("[Core] 尝试解析HTML页面，但未能找到失败详情或 AC 计数。")
                 result["failed_case_name"] = "Unknown - Parse Failed"
                 result["failed_case_status"] = final_status # 报告原始失败状态
            elif failed_name == "All Passed":
                 # 理论上 final_status 不是 AC 时不应进入此分支，但作为健壮性检查
                 print(f"[Core] 警告：状态为 {final_status} 但详情解析为 'All Passed'? AC 数量: {ac_count if ac_count is not None else '未知'}")
                 # 即使是这种情况，也记录 AC 数量
            elif failed_name is not None: # 明确找到失败 case
                 print(f"[Core] 找到首个失败 Case: {failed_name} ({failed_status}), 之前 AC 数量: {ac_count if ac_count is not None else '未知'}")
                 result["failed_case_name"] = failed_name
                 result["failed_case_status"] = failed_status
            # else: 不需要处理，ac_count 已被记录
        else:
             # 对于 CE, IE, WJ 等状态，不查询 Case 详情
             print(f"[Core] 最终状态为 {final_status}，不查询 Case 详情/AC 数量。")
        # -- 修改结束 --

        result["success"] = True

    else:
        result["error_message"] = "未知错误导致提交对象未创建"

    return result

def main():
    print("--- AtCoder 提交脚本 (测试模式) ---")
    contest_id = "abc330"
    problem_id = "abc330_d"
    code_file_path = "my_solution.cc"
    cookie_file = "/home/barty/.local/share/online-judge-tools/cookie.jar"
    
    print(f"测试配置:")
    print(f"  比赛: {contest_id}")
    print(f"  题目: {problem_id}")
    print(f"  代码文件: {code_file_path}")
    print(f"  Cookie 文件: {cookie_file}")

    print(f"\n正在读取代码文件: {code_file_path}...")
    with open(code_file_path, 'r', encoding='utf-8') as f: 
        code_str = f.read()
    result = submit_and_get_results(contest_id=contest_id,
                                    problem_id=problem_id,
                                    code_str=code_str,
                                    cookie_file_path=cookie_file)

    print("\n--- 提交结果 ---")
    print(f"操作成功: {result['success']}")
    print(f"提交 URL: {result['submission_url'] or 'N/A'}")
    print(f"最终状态: {result['final_status'] or '未知'}")
    if result['failed_case_name'] and result['failed_case_name'] != "All Passed":
        print(f"首个失败Case: {result['failed_case_name']} ({result['failed_case_status']}), AC 数量: {result['ac_count'] if result['ac_count'] is not None else '未知'}" )
    elif result['failed_case_name'] == "All Passed":
         print(f"首个失败Case: (所有解析的 Case 均通过), AC 数量: {result['ac_count'] if result['ac_count'] is not None else '未知'}")
    elif result['final_status'] == "AC":
         print(f"通过的测试点数: {result['ac_count'] if result['ac_count'] is not None else '查询AC数量失败或未实现'}")
    else:
         print(f"首个失败Case: (未找到、不适用或解析失败), AC 数量: {result['ac_count'] if result['ac_count'] is not None else '未知'}")
    if result['error_message']:
        print(f"错误信息: {result['error_message']}")
    print("---------------")


if __name__ == "__main__":
    # 确保 online-judge-tools, bs4, and lxml 安装
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
        
        print(f"错误: 找不到库 '{module_name}'。", file=sys.stderr)
        print(f"请运行: pip install {package_name}", file=sys.stderr)
        sys.exit(1)

    main()
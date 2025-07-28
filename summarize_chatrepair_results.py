#!/usr/bin/env python3
"""summarize_chatrepair_results.py

专门用于统计ChatRepair结果的脚本，能够正确解析ChatRepair的数据格式并重新计算pass@k

用法：
    python3 summarize_chatrepair_results.py chatrepair_coder7b-reuse-coder7b_qwen2.5-coder-7b-instruct
"""
import argparse, json, os, sys, collections, statistics, math
from typing import Dict, List

def load_json(path: str) -> Dict:
    if not os.path.exists(path):
        print(f"[Error] File not found: {path}", file=sys.stderr)
        sys.exit(1)
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def get_difficulty(problem_id: str) -> str:
    """根据题号后缀字母判断难度"""
    if problem_id and len(problem_id) > 0:
        suffix = problem_id[-1].lower()
        if suffix in ['b', 'c']:
            return 'Easy'
        elif suffix == 'd':
            return 'Medium'
        elif suffix in ['e', 'f']:
            return 'Hard'
    return 'Unknown'

def pass_at_k(n: int, c: int, k:int) -> float:
    """
    正确计算pass@k - 从n个版本中随机选择k个，至少有一个通过的概率
    pass@k = 1 - C(n-c, k) / C(n, k)
    其中n是总版本数，c是通过的版本数
    """
    if n < k:
        # 如果总版本数小于k，但有成功版本，则pass@k为1
        return 1.0 if c > 0 else 0.0
    if c == 0:
        return 0.0
    if n - c < k:
        # 如果失败的版本数小于k，那么选k个必然包含成功版本
        return 1.0
    
    try:
        # 1 - (从失败版本中选k个的组合数) / (从所有版本中选k个的组合数)
        return 1.0 - math.comb(n - c, k) / math.comb(n, k)
    except (ValueError, ZeroDivisionError):
        return 0.0

def summarize_problem_pass_at_k(problem_data: Dict, strategies: List[str], k: int) -> Dict:
    """Summarize pass@k results for a single problem."""
    counters = {s: {"pass_sum": 0.0, "count": 0} for s in strategies}
    
    problem_results = problem_data.get("results", [])
    for entry in problem_results:
        eval_data = entry.get("evaluation")
        if not eval_data or eval_data.get("error"):
            continue
            
        for strat in strategies:
            strat_res = eval_data.get(strat)
            
            # 如果策略不存在，跳过
            if not strat_res:
                continue

            # 从version_results重新计算pass@k
            version_results = strat_res.get("version_results", [])
            if not version_results:
                counters[strat]["count"] += 1 # 计为运行了，但失败
                continue

            n = len(version_results)
            c = sum(1 for v in version_results if v.get("passed", False))
            
            pass_at_k_val = pass_at_k(n, c, k)
            
            counters[strat]["pass_sum"] += pass_at_k_val
            counters[strat]["count"] += 1
    
    return counters

def format_rate(pass_sum: float, count: int) -> str:
    if count == 0:
        return "N/A"
    avg = pass_sum / count * 100
    return f"{avg:.1f}%"

def main():
    parser = argparse.ArgumentParser(description="Summarize ChatRepair results with corrected pass@k calculation using combinatorics")
    parser.add_argument("model_tag", help="model tag, e.g. chatrepair_coder7b-reuse-coder7b_qwen2.5-coder-7b-instruct")
    parser.add_argument("--strategies", nargs="*", default=None,
                        help="Strategy keys to summarize. If not provided, all available strategies will be summarized.")
    args = parser.parse_args()

    json_path = f"result_{args.model_tag}.json"
    data = load_json(json_path)

    # --- 自动检测策略 ---
    strategies_to_summarize = args.strategies
    if not strategies_to_summarize:
        detected_strategies = set()
        for problem_data in data.values():
            if "results" in problem_data:
                for submission in problem_data["results"]:
                    evaluation = submission.get("evaluation")
                    if evaluation:
                        for key in evaluation.keys():
                            if key != "error" and isinstance(evaluation[key], dict):
                                detected_strategies.add(key)
        
        if not detected_strategies:
            print(f"[Error] No evaluation strategies found in result file: {json_path}", file=sys.stderr)
            sys.exit(1)
            
        strategies_to_summarize = sorted(list(detected_strategies))
        print(f"[Info] No strategies specified via --strategies. Auto-detected and using: {', '.join(strategies_to_summarize)}")
    # --- 结束自动检测 ---

    print(f"\n=== ChatRepair Summary (Corrected pass@k using combinatorics) for {json_path} ===\n")
    
    # 计算表头宽度
    col_width = 10
    count_width = 6
    header_parts = ["Problem".ljust(9)]
    subheader_parts = ["".ljust(9)]
    
    for strat in strategies_to_summarize:
        header_parts.append(f"{strat}".center(col_width * 3 + count_width + 3))
        subheader_parts.extend([
            f"{'pass@1':>{col_width}}", 
            f"{'pass@5':>{col_width}}", 
            f"{'pass@10':>{col_width}}",
            f"{'count':>{count_width}}"
        ])
    
    print(" ".join(header_parts))
    print(" ".join(subheader_parts))
    print("-" * (9 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    
    # 总体统计
    overall_results = {s: {f"pass@{k}": {"pass_sum": 0.0, "count": 0} for k in [1, 5, 10]} for s in strategies_to_summarize}
    
    # 按难度统计
    difficulty_results = {
        'Easy': {s: {f"pass@{k}": {"pass_sum": 0.0, "count": 0} for k in [1, 5, 10]} for s in strategies_to_summarize},
        'Medium': {s: {f"pass@{k}": {"pass_sum": 0.0, "count": 0} for k in [1, 5, 10]} for s in strategies_to_summarize},
        'Hard': {s: {f"pass@{k}": {"pass_sum": 0.0, "count": 0} for k in [1, 5, 10]} for s in strategies_to_summarize}
    }
    
    for problem_id, problem_data in sorted(data.items()):
        line_parts = [f"{problem_id:9}"]
        
        # 计算所有k值的counters
        all_counters = {}
        for k in [1, 5, 10]:
            all_counters[k] = summarize_problem_pass_at_k(problem_data, strategies_to_summarize, k)
        
        difficulty = get_difficulty(problem_id)
        
        for strat in strategies_to_summarize:
            # 显示结果
            pass_1_counter = all_counters[1][strat]
            pass_5_counter = all_counters[5][strat]
            pass_10_counter = all_counters[10][strat]
            
            line_parts.append(f"{format_rate(pass_1_counter['pass_sum'], pass_1_counter['count'])[:9]}".rjust(col_width))
            line_parts.append(f"{format_rate(pass_5_counter['pass_sum'], pass_5_counter['count'])[:9]}".rjust(col_width))
            line_parts.append(f"{format_rate(pass_10_counter['pass_sum'], pass_10_counter['count'])[:9]}".rjust(col_width))
            line_parts.append(f"({pass_1_counter['count']})".rjust(count_width))
            
            # 累积到总体统计
            for k, counter in all_counters.items():
                overall_results[strat][f"pass@{k}"]["pass_sum"] += counter[strat]["pass_sum"]
                overall_results[strat][f"pass@{k}"]["count"] += counter[strat]["count"]
            
            # 累积到难度统计
            if difficulty in difficulty_results:
                for k, counter in all_counters.items():
                    difficulty_results[difficulty][strat][f"pass@{k}"]["pass_sum"] += counter[strat]["pass_sum"]
                    difficulty_results[difficulty][strat][f"pass@{k}"]["count"] += counter[strat]["count"]
        
        print(" ".join(line_parts))

    # 输出总体统计
    print("\n" + "=" * (9 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    print("OVERALL SUMMARY")
    print("=" * (9 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    print(f"{'Strategy':<25} {'pass@1':>12} {'pass@5':>12} {'pass@10':>12} {'count':>8}")
    print("-" * 70)
    
    for strat in strategies_to_summarize:
        result = overall_results[strat]
        pass_1_str = format_rate(result["pass@1"]["pass_sum"], result["pass@1"]["count"])
        pass_5_str = format_rate(result["pass@5"]["pass_sum"], result["pass@5"]["count"])
        pass_10_str = format_rate(result["pass@10"]["pass_sum"], result["pass@10"]["count"])
        count_str = f"({result['pass@1']['count']})"
        
        print(f"{strat:25} {pass_1_str:>12} {pass_5_str:>12} {pass_10_str:>12} {count_str:>8}")
    
    print("=" * 70)
    
    # 输出按难度统计
    print("\n" + "=" * (10 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    print("DIFFICULTY-BASED SUMMARY")
    print("=" * (10 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    
    # 表头
    header_parts = ["Difficulty".ljust(10)]
    subheader_parts = ["".ljust(10)]
    
    for strat in strategies_to_summarize:
        header_parts.append(f"{strat}".center(col_width * 3 + count_width + 3))
        subheader_parts.extend([
            f"{'pass@1':>{col_width}}", 
            f"{'pass@5':>{col_width}}", 
            f"{'pass@10':>{col_width}}",
            f"{'count':>{count_width}}"
        ])
    
    print(" ".join(header_parts))
    print(" ".join(subheader_parts))
    print("-" * (10 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))
    
    # 显示各难度结果
    difficulty_labels = {'Easy': 'Easy (bc)', 'Medium': 'Medium (d)', 'Hard': 'Hard (ef)'}
    
    for diff in ['Easy', 'Medium', 'Hard']:
        label = difficulty_labels[diff]
        line_parts = [f"{label:10}"]
        
        for strat in strategies_to_summarize:
            result = difficulty_results[diff][strat]
            
            pass_1_str = format_rate(result["pass@1"]["pass_sum"], result["pass@1"]["count"])
            pass_5_str = format_rate(result["pass@5"]["pass_sum"], result["pass@5"]["count"])
            pass_10_str = format_rate(result["pass@10"]["pass_sum"], result["pass@10"]["count"])
            count_str = f"({result['pass@1']['count']})"

            line_parts.append(f"{pass_1_str[:9]}".rjust(col_width))
            line_parts.append(f"{pass_5_str[:9]}".rjust(col_width))
            line_parts.append(f"{pass_10_str[:9]}".rjust(col_width))
            line_parts.append(f"{count_str}".rjust(count_width))
        
        print(" ".join(line_parts))
    
    print("=" * (10 + len(strategies_to_summarize) * (col_width * 3 + count_width + 4)))

if __name__ == "__main__":
    main() 
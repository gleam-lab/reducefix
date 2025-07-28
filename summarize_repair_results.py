#!/usr/bin/env python3
"""summarize_repair_results.py

Quick statistics for specified model_tag (result_<tag>.json) showing Top-1 / Top-5 success rates 
for each problem and strategy, where:
    • Top-1 success: successful_version == 1
    • Top-5 success: passed == True (at least one version passed out of five)
    • pass@1: accuracy calculated using pass@k formula

Script only reads JSON, does not recompile/run any code.

Usage:
    python3 summarize_repair_results.py qwenplus-qwencoderturbo  [--strategies no_tc orig_tc ...]
    python3 summarize_repair_results.py qwenplus-qwencoderturbo --latex [--model-name "GLM4-9B-chat"]
"""
import argparse, json, os, sys, collections, statistics, textwrap
import math
from typing import Dict, List

DEFAULT_STRATEGIES = [
    "no_tc",
    "orig_tc",
    "diff_only",
    "reduced_tc",
    "reduced_plus_diff",
]

def pass_at_k(n: int, c: int, k: int) -> float:
    """Calculate pass@k metric
    n: total submissions
    c: passed submissions
    k: evaluation sample size
    """
    if n - c < k:
        return 1.0
    return 1.0 - math.comb(n - c, k) / math.comb(n, k)

def load_json(path: str) -> Dict:
    if not os.path.exists(path):
        print(f"[Error] File not found: {path}", file=sys.stderr)
        sys.exit(1)
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def summarize_problem(problem_data: Dict, strategies: List[str]) -> Dict:
    """Summarize results for a single problem."""
    counters = {s: collections.Counter({"top1": 0, "top5": 0, "total": 0, "pass_at_1_sum": 0, "pass_at_1_count": 0}) for s in strategies}
    
    results = problem_data.get("results", [])
    for entry in results:
        eval_data = entry.get("evaluation")
        if not eval_data or eval_data.get("error"):
            continue
            
        for strat in strategies:
            strat_res = eval_data.get(strat)
            
            if strat not in eval_data:
                continue
            
            counters[strat]["total"] += 1
            
            if strat_res is None or not strat_res:
                counters[strat]["pass_at_1_sum"] += 0.0
                counters[strat]["pass_at_1_count"] += 1
                continue
            
            successful_version = strat_res.get("successful_version")
            if successful_version is not None:
                counters[strat]["top1"] += 1
                if successful_version <= 5:
                    counters[strat]["top5"] += 1
            
            versions = strat_res.get("versions", [])
            if versions:
                total_versions = len(versions)
                passed_count = sum(1 for v in versions if v.get("passed", False))
                pass_at_1_val = pass_at_k(total_versions, passed_count, 1)
            else:
                if successful_version is not None:
                    pass_at_1_val = pass_at_k(5, 1, 1)
                else:
                    pass_at_1_val = 0.0
            
            counters[strat]["pass_at_1_sum"] += pass_at_1_val
            counters[strat]["pass_at_1_count"] += 1
    
    return counters

def is_reduce_successful(eval_data: Dict) -> bool:
    """Check if reduce was successful - strict standard: check if there's actual reduction effect"""
    if not eval_data:
        return False
    
    orig_tc = eval_data.get("orig_tc")
    reduced_tc = eval_data.get("reduced_tc")
    
    if not reduced_tc:
        return False
    
    if not orig_tc:
        return True
    
    orig_versions = orig_tc.get("versions", [])
    reduced_versions = reduced_tc.get("versions", [])
    
    if orig_versions and reduced_versions:
        orig_success = sum(1 for v in orig_versions if v.get("passed", False))
        reduced_success = sum(1 for v in reduced_versions if v.get("passed", False))
        
        if orig_success != reduced_success:
            return True
        
        if len(orig_versions) != len(reduced_versions):
            return True
    
    orig_success_ver = orig_tc.get("successful_version")
    reduced_success_ver = reduced_tc.get("successful_version")
    
    if orig_success_ver != reduced_success_ver:
        return True
    
    return False

def summarize_problem_pass_at_k(problem_data: Dict, strategies: List[str], k: int, only_reduced_success: bool = False) -> Dict:
    """Summarize pass@k results for a single problem."""
    counters = {s: {"pass_sum": 0.0, "count": 0} for s in strategies}
    
    results = problem_data.get("results", [])
    for entry in results:
        eval_data = entry.get("evaluation")
        if not eval_data or eval_data.get("error"):
            continue
        
        if only_reduced_success and not is_reduce_successful(eval_data):
            continue
            
        for strat in strategies:
            strat_res = eval_data.get(strat)
            
            if strat not in eval_data:
                continue

            versions = strat_res.get("versions", [])
            if not versions:
                continue

            total_versions = len(versions)
            passed_count = sum(1 for v in versions if v.get("passed", False))
            
            if total_versions > 0 and total_versions >= k:
                pass_at_k_val = pass_at_k(total_versions, passed_count, k)
            elif total_versions > 0 and passed_count > 0:
                pass_at_k_val = 1.0
            elif total_versions > 0:
                pass_at_k_val = 0.0
            else:
                pass_at_k_val = 0.0
                
            counters[strat]["pass_sum"] += pass_at_k_val
            counters[strat]["count"] += 1
    
    return counters

def format_rate(success: int, total: int) -> str:
    if total == 0:
        return "N/A"
    return f"{success}/{total} ({success/total*100:.1f}%)"

def format_pass_at_1(pass_sum: float, count: int) -> str:
    if count == 0:
        return "N/A"
    return f"{pass_sum/count*100:.1f}%"

def get_difficulty(problem_id: str) -> str:
    """Determine difficulty based on problem ID suffix letter"""
    if problem_id and len(problem_id) > 0:
        suffix = problem_id[-1].lower()
        if suffix in ['b', 'c']:
            return 'Easy'
        elif suffix == 'd':
            return 'Medium'
        elif suffix in ['e', 'f']:
            return 'Hard'
    return 'Unknown'

def calculate_pass_at_k_for_difficulty(data: Dict, strategies: List[str], difficulty: str, k: int, exclude_problems: List[str] = None, only_reduced_success: bool = False) -> Dict:
    """Calculate pass@k for each strategy under specific difficulty"""
    if exclude_problems is None:
        exclude_problems = []
    
    result = {s: {"pass_sum": 0.0, "count": 0} for s in strategies}
    
    for problem_id, problem_data in data.items():
        if problem_id in exclude_problems:
            continue
        if get_difficulty(problem_id) != difficulty:
            continue
            
        results = problem_data.get("results", [])
        for entry in results:
            eval_data = entry.get("evaluation")
            if not eval_data or eval_data.get("error"):
                continue
            
            if only_reduced_success and not is_reduce_successful(eval_data):
                continue
                
            for strat in strategies:
                strat_res = eval_data.get(strat)
                
                if strat not in eval_data:
                    continue

                versions = strat_res.get("versions", [])
                if not versions:
                    continue

                total_versions = len(versions)
                passed_count = sum(1 for v in versions if v.get("passed", False))
                
                if total_versions > 0 and total_versions >= k:
                    pass_at_k_val = pass_at_k(total_versions, passed_count, k)
                elif total_versions > 0 and passed_count > 0:
                    pass_at_k_val = 1.0
                elif total_versions > 0:
                    pass_at_k_val = 0.0
                else:
                    pass_at_k_val = 0.0
                    
                result[strat]["pass_sum"] += pass_at_k_val
                result[strat]["count"] += 1
    
    return result

def format_latex_value(value: float, baseline: float, is_best: bool = False) -> str:
    """Format LaTeX value with colors and bold"""
    if value == 0.0 and baseline == 0.0:
        return "0.0\\,(0.0\\%)"
    
    diff = value - baseline
    
    if is_best:
        base_str = f"\\textbf{{{value:.1f}}}"
    else:
        base_str = f"{value:.1f}"
    
    if abs(diff) < 0.05:
        diff_str = f"\\,({diff:+.1f}\\%)"
    elif diff > 0:
        diff_str = f"\\,(\\textcolor{{ForestGreen}}{{${diff:+.1f}\\%$}})"
    else:
        diff_str = f"\\,(\\textcolor{{Maroon}}{{${diff:+.1f}\\%$}})"
    
    return base_str + diff_str

def generate_latex_table(data: Dict, strategies: List[str], model_name: str, exclude_problems: List[str] = None, only_reduced_success: bool = False) -> str:
    """Generate LaTeX table paragraph"""
    if exclude_problems is None:
        exclude_problems = []
    
    filtered_data = {k: v for k, v in data.items() if k not in exclude_problems}
    
    difficulties = ['Easy', 'Medium', 'Hard']
    difficulty_labels = ['Easy', 'Medium', 'Hard']
    
    results = {}
    for diff in difficulties:
        results[diff] = {}
        for k in [1, 5, 10]:
            pass_k_stats = calculate_pass_at_k_for_difficulty(filtered_data, strategies, diff, k, exclude_problems, only_reduced_success)
            results[diff][k] = {}
            for strat in strategies:
                if pass_k_stats[strat]["count"] > 0:
                    results[diff][k][strat] = pass_k_stats[strat]["pass_sum"] / pass_k_stats[strat]["count"] * 100
                else:
                    results[diff][k][strat] = 0.0
    
    overall_pass_at_k = {k: {s: {"pass_sum": 0.0, "count": 0} for s in strategies} for k in [1, 5, 10]}
    
    for problem_id, problem_data in filtered_data.items():
        for k in [1, 5, 10]:
            counters = summarize_problem_pass_at_k(problem_data, strategies, k, only_reduced_success)
            for strat in strategies:
                overall_pass_at_k[k][strat]["pass_sum"] += counters[strat]["pass_sum"]
                overall_pass_at_k[k][strat]["count"] += counters[strat]["count"]
    
    overall_results = {}
    for k in [1, 5, 10]:
        overall_results[k] = {}
        for strat in strategies:
            if overall_pass_at_k[k][strat]["count"] > 0:
                overall_results[k][strat] = overall_pass_at_k[k][strat]["pass_sum"] / overall_pass_at_k[k][strat]["count"] * 100
            else:
                overall_results[k][strat] = 0.0
    
    latex_lines = []
    latex_lines.append(f"\\multicolumn{{10}}{{c}}{{\\textbf{{{model_name}}}}}\\\\")
    
    main_strategies = ["no_tc", "orig_tc", "reduced_tc"]
    
    for i, (diff, label) in enumerate(zip(difficulties + ['Overall'], difficulty_labels + ['Overall'])):
        if diff == 'Overall':
            current_results = overall_results
        else:
            current_results = results[diff]
        
        baseline_values = [f"{current_results[k]['no_tc']:.1f}" for k in [1, 5, 10]]
        line1 = f"{label:<8} & {' & '.join(baseline_values)}"
        
        for strat in main_strategies[1:]:
            strat_values = []
            for k in [1, 5, 10]:
                value = current_results[k][strat]
                baseline = current_results[k]['no_tc']
                
                all_values = [current_results[k][s] for s in main_strategies]
                is_best = value == max(all_values) and value > baseline
                
                formatted_value = format_latex_value(value, baseline, is_best)
                strat_values.append(formatted_value)
            
            line1 += f"\n         & {' & '.join(strat_values)}"
        
        line1 += "\\\\"
        latex_lines.append(line1)
    
    return '\n'.join(latex_lines)

def main():
    parser = argparse.ArgumentParser(description="Summarize repair success rates from result_<tag>.json")
    parser.add_argument("model_tag", help="model tag, e.g. qwenplus-qwencoderturbo -> result_<tag>.json")
    parser.add_argument("--strategies", nargs="*", default=DEFAULT_STRATEGIES,
                        help="strategy keys to summarize (default: common 5)")
    parser.add_argument("--latex", action="store_true", help="output LaTeX table format")
    parser.add_argument("--model-name", default="", help="model name for LaTeX output")
    parser.add_argument("--exclude-problems", nargs="*", default=[],
                        help="problem IDs to exclude from analysis (e.g., abc377c)")
    parser.add_argument("--only-reduced-success", action="store_true",
                        help="only include cases where reduce was successful (filter out cases where test cases are identical or reduce failed)")
    args = parser.parse_args()

    json_path = f"result_{args.model_tag}.json"
    data = load_json(json_path)

    if args.exclude_problems:
        print(f"Excluding problems: {', '.join(args.exclude_problems)}")
        filtered_data = {k: v for k, v in data.items() if k not in args.exclude_problems}
    else:
        filtered_data = data

    if args.only_reduced_success:
        print("Only counting cases where reduce was successful")

    if args.latex:
        model_name = args.model_name or args.model_tag
        latex_output = generate_latex_table(filtered_data, args.strategies, model_name, args.exclude_problems, args.only_reduced_success)
        print(latex_output)
        return

    overall_pass_at_k = {k: {s: {"pass_sum": 0.0, "count": 0} for s in args.strategies} for k in [1, 5, 10]}

    print("\n=== Summary for", json_path, "===\n")
    if args.exclude_problems:
        print(f"Excluding problems: {', '.join(args.exclude_problems)}\n")
    if args.only_reduced_success:
        print("Only counting cases where reduce was successful\n")
    
    col_width = 10
    count_width = 6
    header_parts = ["Problem".ljust(9)]
    subheader_parts = ["".ljust(9)]
    
    for strat in args.strategies:
        header_parts.append(f"{strat}".center(col_width * 3 + count_width + 3))
        subheader_parts.extend([
            f"{'pass@1':>{col_width}}", 
            f"{'pass@5':>{col_width}}", 
            f"{'pass@10':>{col_width}}",
            f"{'count':>{count_width}}"
        ])
    
    print(" ".join(header_parts))
    print(" ".join(subheader_parts))
    print("-" * (9 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    
    for problem_id, problem_data in sorted(filtered_data.items()):
        line_parts = [f"{problem_id:9}"]
        
        all_counters = {}
        for k in [1, 5, 10]:
            all_counters[k] = summarize_problem_pass_at_k(problem_data, args.strategies, k, args.only_reduced_success)
        
        for strat in args.strategies:
            for k in [1, 5, 10]:
                c = all_counters[k][strat]
                if c["count"] > 0:
                    pass_rate = c["pass_sum"] / c["count"] * 100
                    line_parts.append(f"{pass_rate:.1f}%".rjust(col_width))
                else:
                    line_parts.append("N/A".rjust(col_width))
                
                overall_pass_at_k[k][strat]["pass_sum"] += c["pass_sum"]
                overall_pass_at_k[k][strat]["count"] += c["count"]
            
            count = all_counters[1][strat]["count"]
            line_parts.append(f"({count})".rjust(count_width))
        
        print(" ".join(line_parts))

    print("\n" + "=" * (9 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    print("OVERALL SUMMARY")
    print("=" * (9 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    print(f"{'Strategy':<15} {'pass@1':>12} {'pass@5':>12} {'pass@10':>12} {'count':>8}")
    print("-" * 60)
    
    for strat in args.strategies:
        pass_at_1_stat = overall_pass_at_k[1][strat]
        pass_at_5_stat = overall_pass_at_k[5][strat]
        pass_at_10_stat = overall_pass_at_k[10][strat]
        
        pass_at_1_str = f"{pass_at_1_stat['pass_sum']/pass_at_1_stat['count']*100:.1f}%" if pass_at_1_stat['count'] > 0 else "N/A"
        pass_at_5_str = f"{pass_at_5_stat['pass_sum']/pass_at_5_stat['count']*100:.1f}%" if pass_at_5_stat['count'] > 0 else "N/A"
        pass_at_10_str = f"{pass_at_10_stat['pass_sum']/pass_at_10_stat['count']*100:.1f}%" if pass_at_10_stat['count'] > 0 else "N/A"
        count_str = f"({pass_at_1_stat['count']})"
        
        print(f"{strat:15} {pass_at_1_str:>12} {pass_at_5_str:>12} {pass_at_10_str:>12} {count_str:>8}")
    
    print("=" * 60)
    
    print("\n" + "=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    print("DIFFICULTY-BASED PASS@K SUMMARY")
    print("=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    
    header_parts = ["Difficulty".ljust(10)]
    subheader_parts = ["".ljust(10)]
    
    for strat in args.strategies:
        header_parts.append(f"{strat}".center(col_width * 3 + count_width + 3))
        subheader_parts.extend([
            f"{'pass@1':>{col_width}}", 
            f"{'pass@5':>{col_width}}", 
            f"{'pass@10':>{col_width}}",
            f"{'count':>{count_width}}"
        ])
    
    print(" ".join(header_parts))
    print(" ".join(subheader_parts))
    print("-" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    
    difficulties = ['Easy', 'Medium', 'Hard']
    difficulty_labels = ['Easy (c)', 'Medium (d)', 'Hard (ef)']
    
    for diff, label in zip(difficulties, difficulty_labels):
        line_parts = [f"{label:10}"]
        
        all_stats = {}
        for k in [1, 5, 10]:
            all_stats[k] = calculate_pass_at_k_for_difficulty(filtered_data, args.strategies, diff, k, args.exclude_problems, args.only_reduced_success)
        
        for strat in args.strategies:
            for k in [1, 5, 10]:
                stat = all_stats[k][strat]
                if stat["count"] > 0:
                    pass_rate = stat["pass_sum"] / stat["count"] * 100
                    line_parts.append(f"{pass_rate:.1f}%".rjust(col_width))
                else:
                    line_parts.append("N/A".rjust(col_width))
            
            count = all_stats[1][strat]["count"]
            line_parts.append(f"({count})".rjust(count_width))
        
        print(" ".join(line_parts))
    
    print("=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))

if __name__ == "__main__":
    main() 

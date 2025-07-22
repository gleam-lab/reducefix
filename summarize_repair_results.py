#!/usr/bin/env python3
"""summarize_repair_results.py

快速统计指定 model_tag (即 result_<tag>.json) 中各题目、各策略的 Top-1 / Top-5 成功率，
其中：
    • Top-1 成功： successful_version == 1
    • Top-5 成功： passed == True (五个版本里至少有一个通过)
    • pass@1： 使用 pass@k 公式计算的准确率

脚本只读取 json，不重新编译/运行任何代码。

用法：
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
    """
    计算 pass@k 指标
    n: 总提交数
    c: 通过的提交数
    k: 评估的样本数
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
            
            # 如果策略不存在，说明该策略没有运行，跳过
            if strat not in eval_data:
                continue
            
            counters[strat]["total"] += 1
            
            # 如果策略运行了但结果为None或空，计为失败
            if strat_res is None or not strat_res:
                # patch没生成，计为完全失败
                counters[strat]["pass_at_1_sum"] += 0.0
                counters[strat]["pass_at_1_count"] += 1
                continue
            
            # Check top1 and top5
            successful_version = strat_res.get("successful_version")
            if successful_version is not None:
                counters[strat]["top1"] += 1
                if successful_version <= 5:
                    counters[strat]["top5"] += 1
            
            # Calculate pass@1 using versions data if available
            versions = strat_res.get("versions", [])
            if versions:
                total_versions = len(versions)
                passed_count = sum(1 for v in versions if v.get("passed", False))
                pass_at_1_val = pass_at_k(total_versions, passed_count, 1)
            else:
                # Fallback: if successful_version exists, assume 1 success out of 5
                if successful_version is not None:
                    pass_at_1_val = pass_at_k(5, 1, 1)
                else:
                    pass_at_1_val = 0.0
            
            counters[strat]["pass_at_1_sum"] += pass_at_1_val
            counters[strat]["pass_at_1_count"] += 1
    
    return counters

def is_reduce_successful(eval_data: Dict) -> bool:
    """判断reduce是否成功 - 采用严格标准：检查是否真正有缩减效果"""
    if not eval_data:
        return False
    
    orig_tc = eval_data.get("orig_tc")
    reduced_tc = eval_data.get("reduced_tc")
    
    # 如果reduced_tc策略不存在，认为reduce失败
    if not reduced_tc:
        return False
    
    # 如果orig_tc不存在，但reduced_tc存在，需要进一步判断
    if not orig_tc:
        # 没有原始数据对比，但有reduced数据，保守认为成功
        return True
    
    # 尝试从versions数据中获取文件大小信息进行比较
    orig_versions = orig_tc.get("versions", [])
    reduced_versions = reduced_tc.get("versions", [])
    
    # 检查是否有明显的reduce效果指标
    if orig_versions and reduced_versions:
        # 比较成功率变化 - 如果有显著变化说明reduce有效果
        orig_success = sum(1 for v in orig_versions if v.get("passed", False))
        reduced_success = sum(1 for v in reduced_versions if v.get("passed", False))
        
        # 如果成功率有变化，认为reduce有效果
        if orig_success != reduced_success:
            return True
        
        # 如果版本数量不同，说明reduce有效果
        if len(orig_versions) != len(reduced_versions):
            return True
    
    # 检查successful_version字段的变化
    orig_success_ver = orig_tc.get("successful_version")
    reduced_success_ver = reduced_tc.get("successful_version")
    
    # 如果successful_version有变化，认为reduce有效果
    if orig_success_ver != reduced_success_ver:
        return True
    
    # 更严格的判断：如果没有明显的效果指标变化，认为reduce失败
    # 这与analyze_reducer_stats.py的逻辑一致
    # 在没有文件大小信息的情况下，如果性能指标没有变化，可能reduce没有实际效果
    return False

def summarize_problem_pass_at_k(problem_data: Dict, strategies: List[str], k: int, only_reduced_success: bool = False) -> Dict:
    """Summarize pass@k results for a single problem."""
    counters = {s: {"pass_sum": 0.0, "count": 0} for s in strategies}
    
    results = problem_data.get("results", [])
    for entry in results:
        eval_data = entry.get("evaluation")
        if not eval_data or eval_data.get("error"):
            continue
        
        # 如果启用了只统计reduce成功的case，进行过滤
        if only_reduced_success and not is_reduce_successful(eval_data):
            continue
            
        for strat in strategies:
            strat_res = eval_data.get(strat)
            
            # 如果策略不存在，说明该策略没有运行，跳过
            if strat not in eval_data:
                continue

            # 优先使用详细的versions信息。如果没有，则无法准确计算pass@k，因此跳过。
            versions = strat_res.get("versions", [])
            if not versions:
                continue

            total_versions = len(versions)
            passed_count = sum(1 for v in versions if v.get("passed", False))
            
            # 计算 pass@k
            if total_versions > 0 and total_versions >= k:
                pass_at_k_val = pass_at_k(total_versions, passed_count, k)
            elif total_versions > 0 and passed_count > 0:
                # 如果版本数不足k但有成功，则为1.0
                pass_at_k_val = 1.0
            elif total_versions > 0:
                # 版本数不足k且无成功，则为0.0
                pass_at_k_val = 0.0
            else:
                # 如果没有版本信息，计为失败
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

def calculate_pass_at_k_for_difficulty(data: Dict, strategies: List[str], difficulty: str, k: int, exclude_problems: List[str] = None, only_reduced_success: bool = False) -> Dict:
    """计算特定难度下各策略的 pass@k"""
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
            
            # 如果启用了只统计reduce成功的case，进行过滤
            if only_reduced_success and not is_reduce_successful(eval_data):
                continue
                
            for strat in strategies:
                strat_res = eval_data.get(strat)
                
                # 如果策略不存在，说明该策略没有运行，跳过
                if strat not in eval_data:
                    continue

                # 优先使用详细的versions信息。如果没有，则无法准确计算pass@k，因此跳过。
                versions = strat_res.get("versions", [])
                if not versions:
                    continue

                total_versions = len(versions)
                passed_count = sum(1 for v in versions if v.get("passed", False))
                
                # 计算 pass@k
                if total_versions > 0 and total_versions >= k:
                    pass_at_k_val = pass_at_k(total_versions, passed_count, k)
                elif total_versions > 0 and passed_count > 0:
                    # 如果版本数不足k但有成功，则为1.0
                    pass_at_k_val = 1.0
                elif total_versions > 0:
                    # 版本数不足k且无成功，则为0.0
                    pass_at_k_val = 0.0
                else:
                    # 如果没有版本信息，计为失败
                    pass_at_k_val = 0.0
                    
                result[strat]["pass_sum"] += pass_at_k_val
                result[strat]["count"] += 1
    
    return result

def format_latex_value(value: float, baseline: float, is_best: bool = False) -> str:
    """格式化LaTeX值，包括颜色和粗体"""
    if value == 0.0 and baseline == 0.0:
        return "0.0\\,(0.0\\%)"
    
    diff = value - baseline
    
    # 格式化基础值
    if is_best:
        base_str = f"\\textbf{{{value:.1f}}}"
    else:
        base_str = f"{value:.1f}"
    
    # 格式化差值
    if abs(diff) < 0.05:  # 基本相等
        diff_str = f"\\,({diff:+.1f}\\%)"
    elif diff > 0:
        diff_str = f"\\,(\\textcolor{{ForestGreen}}{{${diff:+.1f}\\%$}})"
    else:
        diff_str = f"\\,(\\textcolor{{Maroon}}{{${diff:+.1f}\\%$}})"
    
    return base_str + diff_str

def generate_latex_table(data: Dict, strategies: List[str], model_name: str, exclude_problems: List[str] = None, only_reduced_success: bool = False) -> str:
    """生成LaTeX表格段落"""
    if exclude_problems is None:
        exclude_problems = []
    
    # 过滤掉指定的题目
    filtered_data = {k: v for k, v in data.items() if k not in exclude_problems}
    
    # 计算每个难度的pass@k值
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
    
    # 计算总体结果
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
    
    # 生成LaTeX输出
    latex_lines = []
    latex_lines.append(f"\\multicolumn{{10}}{{c}}{{\\textbf{{{model_name}}}}}\\\\")
    
    # 使用三个主要策略：no_tc, orig_tc, reduced_tc
    main_strategies = ["no_tc", "orig_tc", "reduced_tc"]
    
    for i, (diff, label) in enumerate(zip(difficulties + ['Overall'], difficulty_labels + ['Overall'])):
        if diff == 'Overall':
            current_results = overall_results
        else:
            current_results = results[diff]
        
        # 第一行：难度标签和baseline值
        baseline_values = [f"{current_results[k]['no_tc']:.1f}" for k in [1, 5, 10]]
        line1 = f"{label:<8} & {' & '.join(baseline_values)}"
        
        # 后续行：其他策略的值和差值
        for strat in main_strategies[1:]:  # 跳过no_tc
            strat_values = []
            for k in [1, 5, 10]:
                value = current_results[k][strat]
                baseline = current_results[k]['no_tc']
                
                # 检查是否是该行的最佳值
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

    # 过滤掉指定的题目
    if args.exclude_problems:
        print(f"排除题目: {', '.join(args.exclude_problems)}")
        filtered_data = {k: v for k, v in data.items() if k not in args.exclude_problems}
    else:
        filtered_data = data

    if args.only_reduced_success:
        print("只统计reduce成功的case")

    if args.latex:
        # 生成LaTeX格式输出
        model_name = args.model_name or args.model_tag
        latex_output = generate_latex_table(filtered_data, args.strategies, model_name, args.exclude_problems, args.only_reduced_success)
        print(latex_output)
        return

    # 存储每个策略的pass@k结果
    overall_pass_at_k = {k: {s: {"pass_sum": 0.0, "count": 0} for s in args.strategies} for k in [1, 5, 10]}

    print("\n=== Summary for", json_path, "===\n")
    if args.exclude_problems:
        print(f"排除题目: {', '.join(args.exclude_problems)}\n")
    if args.only_reduced_success:
        print("只统计reduce成功的case\n")
    
    # 计算表头宽度
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
        
        # 先计算所有k值的counters，然后显示
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
                
                # 累积到总体统计
                overall_pass_at_k[k][strat]["pass_sum"] += c["pass_sum"]
                overall_pass_at_k[k][strat]["count"] += c["count"]
            
            # 添加样本数量（使用pass@1的count，因为所有k值的count应该相同）
            count = all_counters[1][strat]["count"]
            line_parts.append(f"({count})".rjust(count_width))
        
        print(" ".join(line_parts))

    # Print overall
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
    
    # Print difficulty-based pass@k summary
    print("\n" + "=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    print("DIFFICULTY-BASED PASS@K SUMMARY")
    print("=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))
    
    # 表头
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
    
    # 计算并显示各难度的pass@k
    difficulties = ['Easy', 'Medium', 'Hard']
    difficulty_labels = ['Easy (c)', 'Medium (d)', 'Hard (ef)']
    
    for diff, label in zip(difficulties, difficulty_labels):
        line_parts = [f"{label:10}"]
        
        # 先计算所有k值的统计数据
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
            
            # 添加样本数量（使用pass@1的count）
            count = all_stats[1][strat]["count"]
            line_parts.append(f"({count})".rjust(count_width))
        
        print(" ".join(line_parts))
    
    print("=" * (10 + len(args.strategies) * (col_width * 3 + count_width + 4)))

if __name__ == "__main__":
    main() 

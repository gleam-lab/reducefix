#!/usr/bin/env python3
"""
根据 experiment_overview.json 生成两个 LaTeX 表格：
1. 压缩效果对比表格（成功率 + 压缩率）
2. 修复成功率对比表格（pass@1/5/10）

按项目分组，包含总体汇总。
"""

import json
import sys
from pathlib import Path
from typing import Dict, List


def load_experiment_results(json_path: Path) -> Dict:
    """加载实验结果 JSON"""
    if not json_path.exists():
        print(f"错误: 找不到文件 {json_path}", file=sys.stderr)
        print(f"请先运行: python3 oss_fuzz/compute_experiment_stats.py --model-tag reducefix_qwen", file=sys.stderr)
        sys.exit(1)
    
    with open(json_path, "r", encoding="utf-8") as f:
        return json.load(f)


def generate_compression_table(reduce_results: Dict[str, Dict]) -> str:
    """
    生成压缩效果对比表格 (LaTeX)
    
    格式：
    Project | Samples | ddmin (SR | CR) | ReduceFix (SR | CR) | Pure LLM (SR | CR)
    """
    
    # 按项目名称排序，过滤掉 unknown 项目
    projects = sorted([p for p in reduce_results.keys() if p.lower() != 'unknown'])
    
    # 计算总体统计
    total_samples = 0
    total_eligible = 0
    
    # 用于计算 Overall 行
    overall_stats = {
        'ddmin': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
        'reducefix': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
        'llm_generated': {'success': 0, 'total': 0, 'compression_sum': 0.0, 'count': 0},
    }
    
    # 收集各项目的统计（已经过滤掉 unknown）
    rows = []
    for project in projects:
        data = reduce_results[project]
        eligible = data['samples_eligible']
        total_samples += data['samples_total']
        total_eligible += eligible
        
        if eligible == 0:
            continue
        
        # 提取各策略数据
        dd = data['ddmin']
        rf = data['reducefix']
        lg = data['llm_generated']
        
        # 更新 overall 统计
        for strategy, stats in [('ddmin', dd), ('reducefix', rf), ('llm_generated', lg)]:
            overall_stats[strategy]['success'] += stats['success']
            overall_stats[strategy]['total'] += stats['total']
            
            # 计算压缩率（对所有样本，不成功的压缩率也计入）
            case_details = data.get('case_details', [])
            for detail in case_details:
                compression_ratio = detail[strategy]['compression_ratio']
                overall_stats[strategy]['compression_sum'] += compression_ratio
                overall_stats[strategy]['count'] += 1
        
        # 格式化当前项目的一行
        row = (
            f"{project.upper():8s} & "
            f"{eligible:3d} & "
            f"{dd['success_rate']*100:4.1f} & {dd['avg_compression_ratio']*100:4.1f} & "
            f"{rf['success_rate']*100:4.1f} & {rf['avg_compression_ratio']*100:4.1f} & "
            f"{lg['success_rate']*100:4.1f} & {lg['avg_compression_ratio']*100:4.1f} \\\\"
        )
        rows.append(row)
    
    # 计算 Overall 行
    overall_dd_sr = (overall_stats['ddmin']['success'] / overall_stats['ddmin']['total']) * 100 if overall_stats['ddmin']['total'] > 0 else 0.0
    overall_dd_cr = (overall_stats['ddmin']['compression_sum'] / overall_stats['ddmin']['count']) * 100 if overall_stats['ddmin']['count'] > 0 else 0.0
    
    overall_rf_sr = (overall_stats['reducefix']['success'] / overall_stats['reducefix']['total']) * 100 if overall_stats['reducefix']['total'] > 0 else 0.0
    overall_rf_cr = (overall_stats['reducefix']['compression_sum'] / overall_stats['reducefix']['count']) * 100 if overall_stats['reducefix']['count'] > 0 else 0.0
    
    overall_lg_sr = (overall_stats['llm_generated']['success'] / overall_stats['llm_generated']['total']) * 100 if overall_stats['llm_generated']['total'] > 0 else 0.0
    overall_lg_cr = (overall_stats['llm_generated']['compression_sum'] / overall_stats['llm_generated']['count']) * 100 if overall_stats['llm_generated']['count'] > 0 else 0.0
    
    overall_row = (
        f"{'Overall':8s} & "
        f"{total_eligible:3d} & "
        f"{overall_dd_sr:4.1f} & {overall_dd_cr:4.1f} & "
        f"{overall_rf_sr:4.1f} & {overall_rf_cr:4.1f} & "
        f"{overall_lg_sr:4.1f} & {overall_lg_cr:4.1f} \\\\"
    )
    
    # 构建完整表格
    latex = r"""\begin{table*}[ht]
\centering
\caption{Test case reduction: success rate and compression ratio comparison (Qwen-Plus).}
\label{tab:reduction-comparison}
\begin{tabular}{lcccccccc}
\toprule
\multirow{2.5}{*}{Project} & \multirow{2.5}{*}{Samples} & \multicolumn{2}{c}{\textit{ddmin}-only} & \multicolumn{2}{c}{\tool\ (LLM + \textit{ddmin})} & \multicolumn{2}{c}{Pure LLM} \\
\cmidrule(lr){3-4}\cmidrule(lr){5-6}\cmidrule(lr){7-8}
 &  & SR & CR & SR & CR & SR & CR \\
\midrule
"""
    
    # 添加各项目行
    for row in rows:
        latex += row + "\n"
    
    # 添加分隔线和 Overall 行
    latex += r"\midrule" + "\n"
    latex += overall_row + "\n"
    
    latex += r"""\bottomrule
\end{tabular}
\end{table*}"""
    
    return latex


def generate_repair_table(repair_results: Dict[str, Dict], reduce_results: Dict[str, Dict]) -> str:
    """
    生成修复成功率对比表格 (LaTeX)
    
    格式：
    Project | Samples | Baseline (p@1 | p@5 | p@10) | Origin Test (p@1 | p@5 | p@10) | ReduceFix (p@1 | p@5 | p@10)
    
    显示相对于 Baseline 的增益/下降
    
    只显示在 reduce_results 中也有数据的项目（保持两个表格项目一致），过滤掉 unknown 项目
    """
    
    # 按项目名称排序，只包含有 reduce 数据的项目，过滤掉 unknown
    projects = sorted([p for p in repair_results.keys() if p in reduce_results and p.lower() != 'unknown'])
    
    # 计算总体统计
    total_samples = 0
    overall_stats = {
        'without_test': {'p1': 0.0, 'p5': 0.0, 'p10': 0.0, 'count': 0},
        'origin_test': {'p1': 0.0, 'p5': 0.0, 'p10': 0.0, 'count': 0},
        'reduced_test': {'p1': 0.0, 'p5': 0.0, 'p10': 0.0, 'count': 0},
    }
    
    # 收集各项目的统计（已经过滤掉 unknown）
    rows = []
    for project in projects:
        data = repair_results[project]
        samples = data['samples_total']
        total_samples += samples
        
        if samples == 0:
            continue
        
        # 提取三种策略数据
        wt = data['without_test']  # Baseline
        ot = data['origin_test']
        rt = data['reduced_test']
        
        # 更新 overall 统计
        overall_stats['without_test']['p1'] += wt['pass_at_1']
        overall_stats['without_test']['p5'] += wt['pass_at_5']
        overall_stats['without_test']['p10'] += wt['pass_at_10']
        overall_stats['without_test']['count'] += 1
        
        overall_stats['origin_test']['p1'] += ot['pass_at_1']
        overall_stats['origin_test']['p5'] += ot['pass_at_5']
        overall_stats['origin_test']['p10'] += ot['pass_at_10']
        overall_stats['origin_test']['count'] += 1
        
        overall_stats['reduced_test']['p1'] += rt['pass_at_1']
        overall_stats['reduced_test']['p5'] += rt['pass_at_5']
        overall_stats['reduced_test']['p10'] += rt['pass_at_10']
        overall_stats['reduced_test']['count'] += 1
        
        # 计算 delta（相对于 baseline）
        def format_with_delta(value: float, baseline: float) -> str:
            """格式化百分比，显示与baseline的差异"""
            val_pct = value * 100
            delta = (value - baseline) * 100
            
            if abs(delta) < 0.05:  # 差异小于0.05%，视为无变化
                return f"{val_pct:4.1f}"
            elif delta > 0:
                return f"\\textbf{{{val_pct:4.1f}}}\\,(\\textcolor{{ForestGreen}}{{$+{delta:.1f}\\%$}})"
            else:
                return f"{val_pct:4.1f}\\,(\\textcolor{{Maroon}}{{${delta:.1f}\\%$}})"
        
        # Baseline 列（不显示 delta）
        baseline_str = (
            f"{wt['pass_at_1']*100:4.1f} & "
            f"{wt['pass_at_5']*100:4.1f} & "
            f"{wt['pass_at_10']*100:4.1f}"
        )
        
        # Origin Test 列（显示与 baseline 的 delta）
        origin_str = (
            f"{format_with_delta(ot['pass_at_1'], wt['pass_at_1'])} & "
            f"{format_with_delta(ot['pass_at_5'], wt['pass_at_5'])} & "
            f"{format_with_delta(ot['pass_at_10'], wt['pass_at_10'])}"
        )
        
        # ReduceFix 列（显示与 baseline 的 delta）
        reduced_str = (
            f"{format_with_delta(rt['pass_at_1'], wt['pass_at_1'])} & "
            f"{format_with_delta(rt['pass_at_5'], wt['pass_at_5'])} & "
            f"{format_with_delta(rt['pass_at_10'], wt['pass_at_10'])}"
        )
        
        # 格式化当前项目的一行
        row = (
            f"{project.upper():8s} & {samples:3d} & "
            f"{baseline_str} & "
            f"{origin_str} & "
            f"{reduced_str} \\\\"
        )
        rows.append(row)
    
    # 计算 Overall 行
    def avg_overall(stats_dict: Dict, count: int) -> tuple:
        """计算平均 pass@k"""
        if count == 0:
            return 0.0, 0.0, 0.0
        return (
            stats_dict['p1'] / count,
            stats_dict['p5'] / count,
            stats_dict['p10'] / count,
        )
    
    overall_wt_p1, overall_wt_p5, overall_wt_p10 = avg_overall(overall_stats['without_test'], overall_stats['without_test']['count'])
    overall_ot_p1, overall_ot_p5, overall_ot_p10 = avg_overall(overall_stats['origin_test'], overall_stats['origin_test']['count'])
    overall_rt_p1, overall_rt_p5, overall_rt_p10 = avg_overall(overall_stats['reduced_test'], overall_stats['reduced_test']['count'])
    
    def format_with_delta(value: float, baseline: float) -> str:
        """格式化百分比，显示与baseline的差异"""
        val_pct = value * 100
        delta = (value - baseline) * 100
        
        if abs(delta) < 0.05:
            return f"{val_pct:4.1f}"
        elif delta > 0:
            return f"\\textbf{{{val_pct:4.1f}}}\\,(\\textcolor{{ForestGreen}}{{$+{delta:.1f}\\%$}})"
        else:
            return f"{val_pct:4.1f}\\,(\\textcolor{{Maroon}}{{${delta:.1f}\\%$}})"
    
    overall_baseline_str = (
        f"{overall_wt_p1*100:4.1f} & "
        f"{overall_wt_p5*100:4.1f} & "
        f"{overall_wt_p10*100:4.1f}"
    )
    
    overall_origin_str = (
        f"{format_with_delta(overall_ot_p1, overall_wt_p1)} & "
        f"{format_with_delta(overall_ot_p5, overall_wt_p5)} & "
        f"{format_with_delta(overall_ot_p10, overall_wt_p10)}"
    )
    
    overall_reduced_str = (
        f"{format_with_delta(overall_rt_p1, overall_wt_p1)} & "
        f"{format_with_delta(overall_rt_p5, overall_wt_p5)} & "
        f"{format_with_delta(overall_rt_p10, overall_wt_p10)}"
    )
    
    overall_row = (
        f"{'Overall':8s} & {total_samples:3d} & "
        f"{overall_baseline_str} & "
        f"{overall_origin_str} & "
        f"{overall_reduced_str} \\\\"
    )
    
    # 构建完整表格
    latex = r"""\begin{table*}[ht]
\centering
\footnotesize
\caption{Pass@\textit{K} (\%) across projects (Qwen-Plus; deltas vs. Baseline; green = gain, red = drop).}
\label{tab:repair-pass-at-k}
\resizebox{\textwidth}{!}{
\begin{tabular}{lcccccccccc}
\toprule
\multirow{2.5}{*}{Project} & \multirow{2.5}{*}{Samples} &
\multicolumn{3}{c}{Baseline (No Test)} &
\multicolumn{3}{c}{Origin Test} &
\multicolumn{3}{c}{Reduced Test (\tool)}\\
\cmidrule(lr){3-5}\cmidrule(lr){6-8}\cmidrule(lr){9-11}
 &  & pass@1 & pass@5 & pass@10 & pass@1 & pass@5 & pass@10 & pass@1 & pass@5 & pass@10\\
\midrule
"""
    
    # 添加各项目行
    for row in rows:
        latex += row + "\n"
    
    # 添加分隔线和 Overall 行
    latex += r"\midrule" + "\n"
    latex += overall_row + "\n"
    
    latex += r"""\bottomrule
\end{tabular}}
\end{table*}"""
    
    return latex


def main():
    import argparse
    parser = argparse.ArgumentParser(description="生成 ReduceFix 实验的 LaTeX 表格")
    parser.add_argument("--input", type=str, default="oss_fuzz/experiment_results/experiment_overview.json",
                        help="输入的实验结果 JSON 文件路径")
    parser.add_argument("--output-dir", type=str, default="oss_fuzz/experiment_results",
                        help="输出目录")
    args = parser.parse_args()
    
    input_path = Path(args.input)
    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    
    # 加载数据
    print(f"[Info] 正在加载实验结果: {input_path}")
    data = load_experiment_results(input_path)
    
    reduce_results = data.get("reduce", {})
    repair_results = data.get("repair", {})
    
    # 生成表格1: 压缩效果
    print("[Info] 生成压缩效果对比表格...")
    table1 = generate_compression_table(reduce_results)
    table1_path = output_dir / "table_compression.tex"
    with open(table1_path, "w", encoding="utf-8") as f:
        f.write(table1)
    print(f"[✓] 压缩表格已保存: {table1_path}")
    
    # 生成表格2: 修复成功率（只包含有 reduce 数据的项目）
    print("[Info] 生成修复成功率对比表格...")
    table2 = generate_repair_table(repair_results, reduce_results)
    table2_path = output_dir / "table_repair.tex"
    with open(table2_path, "w", encoding="utf-8") as f:
        f.write(table2)
    print(f"[✓] 修复表格已保存: {table2_path}")
    
    print("\n" + "="*70)
    print("表格生成完成！")
    print(f"  1. 压缩效果表格: {table1_path}")
    print(f"  2. 修复成功率表格: {table2_path}")
    print("="*70)
    
    # 打印预览
    print("\n" + "="*70)
    print("【表格 1: 压缩效果对比】")
    print("="*70)
    print(table1)
    
    print("\n" + "="*70)
    print("【表格 2: 修复成功率对比】")
    print("="*70)
    print(table2)


if __name__ == "__main__":
    main()


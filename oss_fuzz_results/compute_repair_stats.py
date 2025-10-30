#!/usr/bin/env python3
"""
计算修复实验的统计数据

统计三种策略的成功率：
- without_test (no_tc): 不使用测试用例
- origin_test (orig_tc): 使用原始测试用例
- reduced_test (reduced_tc): 使用 ReduceFix 缩减后的测试用例
"""

import json
import os
import sys
from pathlib import Path
from typing import Dict, List
from collections import defaultdict


def find_all_repair_results(base_dir: str = None) -> List[Path]:
    """
    查找所有的 repair results.json 文件
    
    Returns:
        包含 results.json 路径的列表
    """
    base_path = Path(base_dir)
    results_files = []
    
    # 递归搜索所有 repair_results/.../results.json
    for results_json in base_path.rglob("**/repair_results/**/results.json"):
        results_files.append(results_json)
    
    return results_files


def parse_repair_result(results_path: Path) -> Dict:
    """
    解析单个修复结果文件
    
    Returns:
        {
            "case_id": str,
            "model_tag": str,
            "repair_model": str,
            "without_test": {"passed": bool, "passed_count": int, "total_count": int},
            "origin_test": {...},
            "reduced_test": {...}
        }
    """
    try:
        with open(results_path, "r", encoding="utf-8") as f:
            data = json.load(f)
        
        # 从路径推断 case_id 和模型
        # 路径格式: cases_data/<project>/<case_id>/<model_tag>/repair_results/<repair_model>/results.json
        parts = results_path.parts
        
        case_id = None
        model_tag = None
        repair_model = None
        
        # 找 arvo- 开头的部分作为 case_id
        for i, part in enumerate(parts):
            if part.startswith("arvo-"):
                case_id = part
                if i + 1 < len(parts):
                    model_tag = parts[i + 1]  # 下一个是 model_tag
                break
        
        # repair_model 在倒数第二个位置
        if len(parts) >= 2:
            repair_model = parts[-2]
        
        result = {
            "case_id": case_id or "unknown",
            "model_tag": model_tag or "unknown",
            "repair_model": repair_model or "unknown"
        }
        
        # 解析三种策略的结果
        for strategy_key in ["without_test", "origin_test", "reduced_test"]:
            strategy_data = data.get(strategy_key, {})
            
            passed = strategy_data.get("passed", False)
            versions = strategy_data.get("versions", [])
            
            passed_count = sum(1 for v in versions if v.get("passed", False))
            total_count = len(versions)
            
            result[strategy_key] = {
                "passed": passed,
                "passed_count": passed_count,
                "total_count": total_count
            }
        
        return result
        
    except Exception as e:
        print(f"[Warning] 解析失败 {results_path}: {e}", file=sys.stderr)
        return None


def deduplicate_results(results: List[Dict]) -> List[Dict]:
    """
    去重：每个 case_id 只保留最新的结果（优先选择有更多版本的）
    
    Returns:
        去重后的结果列表
    """
    # 按 case_id 分组
    by_case = defaultdict(list)
    for r in results:
        by_case[r["case_id"]].append(r)
    
    # 每个 case 选择最佳结果
    deduped = []
    for case_id, case_results in by_case.items():
        if len(case_results) == 1:
            deduped.append(case_results[0])
        else:
            # 选择总版本数最多的（说明是最新的完整结果）
            best = max(case_results, key=lambda r: (
                r["without_test"]["total_count"] +
                r["origin_test"]["total_count"] +
                r["reduced_test"]["total_count"]
            ))
            deduped.append(best)
    
    return deduped


def compute_statistics(results: List[Dict]) -> Dict:
    """
    计算总体统计数据
    
    Returns:
        {
            "total_cases": int,
            "without_test": {"success": int, "total": int, "rate": float},
            "origin_test": {...},
            "reduced_test": {...}
        }
    """
    if not results:
        empty_stats = {
            "total_cases": 0,
            "without_test": {"success": 0, "total": 0, "rate": 0.0},
            "origin_test": {"success": 0, "total": 0, "rate": 0.0},
            "reduced_test": {"success": 0, "total": 0, "rate": 0.0}
        }
        return empty_stats, []
    
    # 去重
    results = deduplicate_results(results)
    
    total_cases = len(results)
    
    stats = {
        "total_cases": total_cases,
        "without_test": {"success": 0, "total": 0, "rate": 0.0},
        "origin_test": {"success": 0, "total": 0, "rate": 0.0},
        "reduced_test": {"success": 0, "total": 0, "rate": 0.0}
    }
    
    for strategy_key in ["without_test", "origin_test", "reduced_test"]:
        success_count = sum(1 for r in results if r[strategy_key]["passed"])
        total_count = total_cases
        rate = (success_count / total_count * 100) if total_count > 0 else 0.0
        
        stats[strategy_key] = {
            "success": success_count,
            "total": total_count,
            "rate": rate
        }
    
    return stats, results  # 返回去重后的结果


def print_summary_table(stats: Dict, detailed_results: List[Dict] = None):
    """打印美化的统计表格"""
    
    print("\n" + "="*70)
    print("修复实验结果统计 (TOP_K=10, K-Version 方法)")
    print("="*70)
    print(f"\n总案例数: {stats['total_cases']}")
    print(f"评估标准: 每个策略生成10个版本，至少1个版本通过即为成功\n")
    
    # 策略成功率表格
    print("┌" + "─"*68 + "┐")
    print("│" + " "*22 + "三种修复策略成功率对比" + " "*22 + "│")
    print("├" + "─"*25 + "┬" + "─"*14 + "┬" + "─"*14 + "┬" + "─"*12 + "┤")
    print("│ {:23s} │ {:12s} │ {:12s} │ {:10s} │".format(
        "策略", "成功案例", "总案例", "成功率"
    ))
    print("├" + "─"*25 + "┼" + "─"*14 + "┼" + "─"*14 + "┼" + "─"*12 + "┤")
    
    # 三种策略
    strategies = [
        ("without_test", "无测试用例 (Baseline)"),
        ("origin_test", "原始测试用例"),
        ("reduced_test", "缩减测试用例 (ReduceFix)")
    ]
    
    for key, name in strategies:
        s = stats[key]
        # 高亮最佳结果
        if s["rate"] == max(stats["without_test"]["rate"], stats["origin_test"]["rate"], stats["reduced_test"]["rate"]):
            marker = " ★"
        else:
            marker = "  "
        
        print("│ {:23s} │ {:>12d} │ {:>12d} │ {:>9.1f}%{} │".format(
            name, s["success"], s["total"], s["rate"], marker
        ))
    
    print("└" + "─"*25 + "┴" + "─"*14 + "┴" + "─"*14 + "┴" + "─"*12 + "┘")
    
    # 改进幅度分析
    baseline_rate = stats["without_test"]["rate"]
    origin_rate = stats["origin_test"]["rate"]
    reduced_rate = stats["reduced_test"]["rate"]
    
    print("\n改进幅度分析:")
    print(f"  原始测试用例 vs 无测试用例: {origin_rate - baseline_rate:+.1f} 百分点")
    print(f"  缩减测试用例 vs 无测试用例: {reduced_rate - baseline_rate:+.1f} 百分点")
    print(f"  缩减测试用例 vs 原始测试用例: {reduced_rate - origin_rate:+.1f} 百分点")
    
    # 如果提供了详细结果，显示各项目的情况
    if detailed_results:
        print("\n" + "─"*70)
        print("各项目详细结果:")
        print("─"*70)
        
        # 按项目分组
        by_project = defaultdict(list)
        for r in detailed_results:
            case_id = r["case_id"]
            project = case_id.split("-")[0] if "-" in case_id else "unknown"
            by_project[project].append(r)
        
        for project, cases in sorted(by_project.items()):
            print(f"\n{project.upper()}:")
            for case in cases:
                wt = "✓" if case["without_test"]["passed"] else "✗"
                ot = "✓" if case["origin_test"]["passed"] else "✗"
                rt = "✓" if case["reduced_test"]["passed"] else "✗"
                
                print(f"  {case['case_id']:20s}  无测试:{wt}  原始:{ot}  缩减:{rt}")
    
    print("\n" + "="*70 + "\n")


def main():
    import argparse
    
    parser = argparse.ArgumentParser(description="计算修复实验统计数据")
    parser.add_argument(
        "--base-dir",
        type=str,
        default=None,
        help="案例数据基础目录（默认: 自动检测 cases_data 或 oss_fuzz/cases_data）"
    )
    parser.add_argument(
        "--output",
        type=str,
        help="输出 JSON 文件路径（可选）"
    )
    parser.add_argument(
        "--detailed",
        action="store_true",
        help="显示各项目的详细结果"
    )
    
    args = parser.parse_args()
    
    # 自动检测 base_dir
    if args.base_dir is None:
        import os
        if os.path.exists("cases_data"):
            args.base_dir = "cases_data"
        elif os.path.exists("oss_fuzz/cases_data"):
            args.base_dir = "oss_fuzz/cases_data"
        else:
            print("[错误] 未找到 cases_data 目录", file=sys.stderr)
            sys.exit(1)
    
    # 查找所有结果文件
    print(f"正在扫描 {args.base_dir}...", file=sys.stderr)
    results_files = find_all_repair_results(args.base_dir)
    
    if not results_files:
        print(f"[错误] 未找到任何修复结果文件", file=sys.stderr)
        print(f"请确认路径: {args.base_dir}", file=sys.stderr)
        sys.exit(1)
    
    print(f"找到 {len(results_files)} 个结果文件\n", file=sys.stderr)
    
    # 解析所有结果
    parsed_results = []
    for results_path in results_files:
        result = parse_repair_result(results_path)
        if result:
            parsed_results.append(result)
    
    if not parsed_results:
        print(f"[错误] 无法解析任何结果文件", file=sys.stderr)
        sys.exit(1)
    
    # 计算统计（会自动去重）
    stats, deduped_results = compute_statistics(parsed_results)
    
    # 打印表格
    print_summary_table(stats, deduped_results if args.detailed else None)
    
    # 保存 JSON（如果指定）
    if args.output:
        output_data = {
            "statistics": stats,
            "detailed_results": deduped_results
        }
        
        with open(args.output, "w", encoding="utf-8") as f:
            json.dump(output_data, f, ensure_ascii=False, indent=2)
        
        print(f"[Info] 统计数据已保存到: {args.output}\n", file=sys.stderr)


if __name__ == "__main__":
    main()


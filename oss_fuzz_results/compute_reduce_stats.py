#!/usr/bin/env python3
"""
统计各 project 内所有样本的平均 reduce 效果（三种策略：ddmin/reducefix/llm-generated）。

规则：
- 只统计三种策略都已完成的样本（stats.json 中存在 ddmin/reducefix/generated 三种结果字段）。
- 成功率：若该策略输出大小 < 原始大小，则视为成功；否则失败。
- 平均压缩率：对所有样本（包括失败的）计算平均压缩率（ratio）。

输出：
- 控制台打印每个 project 的样本数、每策略成功率与平均压缩率。
- 默认显示每个样本 ID 的详细信息（原始大小、三种策略的压缩后大小、压缩率和是否成功）。
- 可通过 --no-details 参数关闭详细信息显示。
- 同时保存 JSON 到 oss_fuzz/experiment_results/reduce_overview.json（包含每个样本的详细信息）。
"""

import json
import os
from pathlib import Path
from typing import Dict, List, Tuple

# 支持从当前目录或 oss_fuzz 子目录读取
import os
if os.path.exists("cases.json"):
    CASES_JSON = Path("cases.json")
    CASES_DATA_DIR = Path("cases_data")
    OUT_DIR = Path("experiment_results")
else:
    CASES_JSON = Path("oss_fuzz/cases.json")
    CASES_DATA_DIR = Path("oss_fuzz/cases_data")
    OUT_DIR = Path("oss_fuzz/experiment_results")
OUT_FILE = OUT_DIR / "reduce_overview.json"


def load_cases() -> Dict[str, Dict]:
    if not CASES_JSON.exists():
        raise FileNotFoundError(f"cases.json not found: {CASES_JSON}")
    with open(CASES_JSON, "r", encoding="utf-8") as f:
        return json.load(f)


def get_project_for_case(cases_map: Dict[str, Dict], case_id: str) -> str:
    info = cases_map.get(case_id) or {}
    return str(info.get("target", "unknown"))


def read_stats(stats_path: Path) -> Dict:
    with open(stats_path, "r", encoding="utf-8") as f:
        return json.load(f)


def has_all_three(stats: Dict) -> bool:
    # 三策略字段是否完整
    keys = [
        "original_size",
        "ddmin_size", "ddmin_compression_ratio",
        "reducefix_size", "reducefix_compression_ratio",
        "generated_size", "generated_compression_ratio",
    ]
    return all(k in stats for k in keys)


def summarize_project(project: str, case_stats_list: List[Tuple[str, Dict]]) -> Dict:
    # 只保留三策略都完成的样本
    eligible = [(cid, s) for cid, s in case_stats_list if has_all_three(s)]

    def success_and_ratios(method_key_prefix: str) -> Tuple[int, int, float]:
        total = len(eligible)
        success = 0
        all_ratios: List[float] = []  # 所有样本的压缩率
        for _, s in eligible:
            orig = int(s.get("original_size", 0) or 0)
            size = int(s.get(f"{method_key_prefix}_size", orig) or orig)
            ratio = float(s.get(f"{method_key_prefix}_compression_ratio", 0.0) or 0.0)
            all_ratios.append(ratio)
            # 成功：有压缩
            if orig > 0 and size < orig:
                success += 1
        avg_ratio_all = (sum(all_ratios) / len(all_ratios)) if all_ratios else 0.0
        return success, total, avg_ratio_all

    dd_succ, dd_total, dd_avg_ratio = success_and_ratios("ddmin")
    rf_succ, rf_total, rf_avg_ratio = success_and_ratios("reducefix")
    lg_succ, lg_total, lg_avg_ratio = success_and_ratios("generated")

    # 构建每个样本的详细信息
    case_details = []
    for case_id, stats in eligible:
        orig = int(stats.get("original_size", 0) or 0)
        case_details.append({
            "case_id": case_id,
            "original_size": orig,
            "ddmin": {
                "size": int(stats.get("ddmin_size", orig) or orig),
                "compression_ratio": float(stats.get("ddmin_compression_ratio", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("ddmin_size", orig) or orig) < orig,
            },
            "reducefix": {
                "size": int(stats.get("reducefix_size", orig) or orig),
                "compression_ratio": float(stats.get("reducefix_compression_ratio", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("reducefix_size", orig) or orig) < orig,
            },
            "llm_generated": {
                "size": int(stats.get("generated_size", orig) or orig),
                "compression_ratio": float(stats.get("generated_compression_ratio", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("generated_size", orig) or orig) < orig,
            },
        })

    return {
        "project": project,
        "samples_total": len(case_stats_list),
        "samples_eligible_all_three": len(eligible),
        "ddmin": {
            "success": dd_succ,
            "total": dd_total,
            "success_rate": (dd_succ / dd_total) if dd_total else 0.0,
            "avg_compression_ratio": dd_avg_ratio,
        },
        "reducefix": {
            "success": rf_succ,
            "total": rf_total,
            "success_rate": (rf_succ / rf_total) if rf_total else 0.0,
            "avg_compression_ratio": rf_avg_ratio,
        },
        "llm_generated": {
            "success": lg_succ,
            "total": lg_total,
            "success_rate": (lg_succ / lg_total) if lg_total else 0.0,
            "avg_compression_ratio": lg_avg_ratio,
        },
        "case_details": case_details,
    }


def collect_all_stats(model_tag: str) -> Dict[str, List[Tuple[str, Dict]]]:
    """返回 per-project → [(case_id, stats)] 列表。"""
    cases_map = load_cases()
    per_project: Dict[str, List[Tuple[str, Dict]]] = {}

    # 遍历 cases_data 下的所有 case 目录
    if not CASES_DATA_DIR.exists():
        return per_project

    # 递归查找：支持 cases_data/case_id 和 cases_data/project/case_id 两种结构
    for item in CASES_DATA_DIR.iterdir():
        if not item.is_dir():
            continue
        
        # 情况1: 直接是案例目录 (cases_data/arvo-xxx)
        if item.name.startswith('arvo-'):
            case_id = item.name
            stats_path = item / model_tag / "stats.json"
            if stats_path.exists():
                try:
                    stats = read_stats(stats_path)
                    project = get_project_for_case(cases_map, case_id)
                    per_project.setdefault(project, []).append((case_id, stats))
                except Exception:
                    pass
        
        # 情况2: 项目目录 (cases_data/project/arvo-xxx)
        else:
            for case_dir in item.iterdir():
                if not case_dir.is_dir() or not case_dir.name.startswith('arvo-'):
                    continue
                
                case_id = case_dir.name
                stats_path = case_dir / model_tag / "stats.json"
                if not stats_path.exists():
                    continue

                try:
                    stats = read_stats(stats_path)
                    project = get_project_for_case(cases_map, case_id)
                    per_project.setdefault(project, []).append((case_id, stats))
                except Exception:
                    pass

    return per_project


def print_report(results: Dict[str, Dict], show_details: bool = True):
    print("\n" + "="*70)
    print("OSS-Fuzz Reduce 效果统计（按 Project）")
    print("="*70)

    def pct(x: float) -> str:
        return f"{x*100:.1f}%"
    
    def format_size(size: int) -> str:
        if size < 1024:
            return f"{size}B"
        elif size < 1024 * 1024:
            return f"{size/1024:.1f}KB"
        else:
            return f"{size/(1024*1024):.1f}MB"

    for project in sorted(results.keys()):
        r = results[project]
        print(f"\n[{project}]")
        print(f"  样本总数: {r['samples_total']}")
        print(f"  三法均完成样本: {r['samples_eligible_all_three']}")
        print("  ddmin       : 成功率", pct(r['ddmin']['success_rate']), 
              "| 平均压缩率", pct(r['ddmin']['avg_compression_ratio']))
        print("  reducefix   : 成功率", pct(r['reducefix']['success_rate']), 
              "| 平均压缩率", pct(r['reducefix']['avg_compression_ratio']))
        print("  llm-generated: 成功率", pct(r['llm_generated']['success_rate']), 
              "| 平均压缩率", pct(r['llm_generated']['avg_compression_ratio']))
        
        # 打印每个样本的详细信息
        if show_details and r.get("case_details"):
            print(f"\n  样本详情:")
            for detail in r["case_details"]:
                case_id = detail["case_id"]
                orig_size = detail["original_size"]
                dd = detail["ddmin"]
                rf = detail["reducefix"]
                lg = detail["llm_generated"]
                
                print(f"    {case_id} (原始: {format_size(orig_size)})")
                print(f"      ddmin:     {format_size(dd['size'])} ({pct(dd['compression_ratio'])}) {'✓' if dd['success'] else '✗'}")
                print(f"      reducefix: {format_size(rf['size'])} ({pct(rf['compression_ratio'])}) {'✓' if rf['success'] else '✗'}")
                print(f"      generated: {format_size(lg['size'])} ({pct(lg['compression_ratio'])}) {'✓' if lg['success'] else '✗'}")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="统计各 project 的 reduce 平均效果（ddmin/reducefix/llm-generated）")
    parser.add_argument("--model-tag", default="reducefix_qwen", help="artifacts 下的模型标签目录名，默认 reducefix_qwen")
    parser.add_argument("--no-details", action="store_true", help="不显示每个样本的详细信息")
    args = parser.parse_args()

    per_project_stats = collect_all_stats(args.model_tag)
    results: Dict[str, Dict] = {}
    for project, case_stats_list in per_project_stats.items():
        results[project] = summarize_project(project, case_stats_list)

    print_report(results, show_details=not args.no_details)

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    with open(OUT_FILE, "w", encoding="utf-8") as f:
        json.dump({"model_tag": args.model_tag, "projects": results}, f, ensure_ascii=False, indent=2)
    print(f"\n[Info] 统计结果已保存: {OUT_FILE}")


if __name__ == "__main__":
    main()



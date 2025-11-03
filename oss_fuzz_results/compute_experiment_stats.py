#!/usr/bin/env python3
"""
统计完整的 ReduceFix 实验结果：
1. Reduce 效果统计（三种策略：ddmin/reducefix/llm-generated）
2. Repair 成功率统计（pass@1, pass@5, pass@10）

规则：
- Reduce: 只统计三种策略都已完成的样本
- Repair: 统计三种策略（无测试用例/原始测试用例/缩减测试用例）的 pass@k 成功率

输出：
- 控制台打印每个 project 的详细统计信息
- 保存 JSON 到 oss_fuzz/experiment_results/experiment_overview.json
"""

import json
import os
from pathlib import Path
from typing import Dict, List, Tuple
from math import comb

CASES_JSON = Path("oss_fuzz/cases.json")
CASES_DATA_DIR = Path("oss_fuzz/cases_data")
OUT_DIR = Path("oss_fuzz/experiment_results")
OUT_FILE = OUT_DIR / "experiment_overview.json"


def load_cases() -> Dict[str, Dict]:
    if not CASES_JSON.exists():
        raise FileNotFoundError(f"cases.json not found: {CASES_JSON}")
    with open(CASES_JSON, "r", encoding="utf-8") as f:
        return json.load(f)


def get_project_for_case(cases_map: Dict[str, Dict], case_id: str) -> str:
    info = cases_map.get(case_id) or {}
    return str(info.get("target", "unknown"))


def read_json(path: Path) -> Dict:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


# ==================== Reduce 统计 ====================

def has_all_three_reduce(stats: Dict) -> bool:
    """检查是否完成了三种 reduce 策略"""
    keys = [
        "original_size",
        "ddmin_size", "ddmin_compression_ratio",
        "reducefix_size", "reducefix_compression_ratio",
        "generated_size", "generated_compression_ratio",
    ]
    return all(k in stats for k in keys)


def summarize_reduce(project: str, case_stats_list: List[Tuple[str, Dict]]) -> Dict:
    """统计 reduce 效果"""
    eligible = [(cid, s) for cid, s in case_stats_list if has_all_three_reduce(s)]

    def success_and_ratios(method_key_prefix: str) -> Tuple[int, int, float, float]:
        total = len(eligible)
        success = 0
        all_ratios: List[float] = []
        all_times: List[float] = []
        for _, s in eligible:
            orig = int(s.get("original_size", 0) or 0)
            size = int(s.get(f"{method_key_prefix}_size", orig) or orig)
            ratio = float(s.get(f"{method_key_prefix}_compression_ratio", 0.0) or 0.0)
            time_sec = float(s.get(f"{method_key_prefix}_time_seconds", 0.0) or 0.0)
            all_ratios.append(ratio)
            all_times.append(time_sec)
            if orig > 0 and size < orig:
                success += 1
        avg_ratio_all = (sum(all_ratios) / len(all_ratios)) if all_ratios else 0.0
        avg_time_all = (sum(all_times) / len(all_times)) if all_times else 0.0
        return success, total, avg_ratio_all, avg_time_all

    dd_succ, dd_total, dd_avg_ratio, dd_avg_time = success_and_ratios("ddmin")
    rf_succ, rf_total, rf_avg_ratio, rf_avg_time = success_and_ratios("reducefix")
    lg_succ, lg_total, lg_avg_ratio, lg_avg_time = success_and_ratios("generated")

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
                "time_seconds": float(stats.get("ddmin_time_seconds", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("ddmin_size", orig) or orig) < orig,
            },
            "reducefix": {
                "size": int(stats.get("reducefix_size", orig) or orig),
                "compression_ratio": float(stats.get("reducefix_compression_ratio", 0.0) or 0.0),
                "time_seconds": float(stats.get("reducefix_time_seconds", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("reducefix_size", orig) or orig) < orig,
            },
            "llm_generated": {
                "size": int(stats.get("generated_size", orig) or orig),
                "compression_ratio": float(stats.get("generated_compression_ratio", 0.0) or 0.0),
                "time_seconds": float(stats.get("generated_time_seconds", 0.0) or 0.0),
                "success": orig > 0 and int(stats.get("generated_size", orig) or orig) < orig,
            },
        })

    return {
        "samples_total": len(case_stats_list),
        "samples_eligible": len(eligible),
        "ddmin": {
            "success": dd_succ,
            "total": dd_total,
            "success_rate": (dd_succ / dd_total) if dd_total else 0.0,
            "avg_compression_ratio": dd_avg_ratio,
            "avg_time_seconds": dd_avg_time,
        },
        "reducefix": {
            "success": rf_succ,
            "total": rf_total,
            "success_rate": (rf_succ / rf_total) if rf_total else 0.0,
            "avg_compression_ratio": rf_avg_ratio,
            "avg_time_seconds": rf_avg_time,
        },
        "llm_generated": {
            "success": lg_succ,
            "total": lg_total,
            "success_rate": (lg_succ / lg_total) if lg_total else 0.0,
            "avg_compression_ratio": lg_avg_ratio,
            "avg_time_seconds": lg_avg_time,
        },
        "case_details": case_details,
    }


def collect_reduce_stats(model_tag: str) -> Dict[str, List[Tuple[str, Dict]]]:
    """收集所有 reduce stats.json (从 cases_data 目录读取)"""
    cases_map = load_cases()
    per_project: Dict[str, List[Tuple[str, Dict]]] = {}

    if not CASES_DATA_DIR.exists():
        return per_project

    # cases_data 目录结构: cases_data/<project>/<case_id>/<model_tag>/stats.json
    for project_dir in CASES_DATA_DIR.iterdir():
        if not project_dir.is_dir():
            continue
        
        project_name = project_dir.name
        
        for case_dir in project_dir.iterdir():
            if not case_dir.is_dir() or not case_dir.name.startswith('arvo-'):
                continue
            
            case_id = case_dir.name
            stats_path = case_dir / model_tag / "stats.json"
            if stats_path.exists():
                try:
                    stats = read_json(stats_path)
                    # 使用 cases.json 中的 target，如果找不到就用目录名
                    project = get_project_for_case(cases_map, case_id)
                    if project == "unknown":
                        project = project_name
                    per_project.setdefault(project, []).append((case_id, stats))
                except Exception as e:
                    print(f"[Warning] Failed to read {stats_path}: {e}")

    return per_project


# ==================== Repair 统计 ====================

def calculate_pass_at_k(versions: List[Dict], k: int) -> float:
    """
    计算 pass@k 概率估计（基于无偏估计器）
    
    公式：pass@k = 1 - C(n-c, k) / C(n, k)
    其中：
    - n = 总生成版本数
    - c = 通过的版本数
    - k = 采样数量
    
    含义：从 n 个版本中随机选择 k 个，至少有 1 个通过的概率
    """
    if not versions or k <= 0:
        return 0.0
    
    n = len(versions)
    c = sum(1 for v in versions if v.get("passed", False))
    
    # 边界情况
    if c == 0:
        return 0.0  # 没有通过的版本，概率为 0
    if n < k:
        k = n  # 如果版本数不足 k，则用全部版本
    if n - c < k:
        return 1.0  # 失败版本数 < k，必然至少选到 1 个通过的
    
    # 使用 comb 计算组合数（与其他 RQ 保持一致）
    try:
        numerator = comb(n - c, k)  # 从失败版本中选 k 个的组合数
        denominator = comb(n, k)     # 从所有版本中选 k 个的组合数
        return 1.0 - (numerator / denominator)
    except (ValueError, ZeroDivisionError):
        return 0.0


def summarize_repair(project: str, case_results_list: List[Tuple[str, Dict]]) -> Dict:
    """统计 repair 成功率（pass@1/5/10）- 使用概率估计"""
    
    strategies = ["without_test", "origin_test", "reduced_test"]
    
    # 统计每个策略的 pass@k（使用概率平均）
    strategy_stats = {}
    
    for strategy in strategies:
        pass_at_1_sum = 0.0
        pass_at_5_sum = 0.0
        pass_at_10_sum = 0.0
        total = len(case_results_list)
        
        for case_id, result in case_results_list:
            strategy_data = result.get(strategy, {})
            versions = strategy_data.get("versions", [])
            
            # 累加每个案例的 pass@k 概率
            pass_at_1_sum += calculate_pass_at_k(versions, 1)
            pass_at_5_sum += calculate_pass_at_k(versions, 5)
            pass_at_10_sum += calculate_pass_at_k(versions, 10)
        
        # 计算平均概率作为最终的 pass@k 指标
        strategy_stats[strategy] = {
            "total": total,
            "pass_at_1": pass_at_1_sum / total if total > 0 else 0.0,
            "pass_at_5": pass_at_5_sum / total if total > 0 else 0.0,
            "pass_at_10": pass_at_10_sum / total if total > 0 else 0.0,
        }
    
    # 构建每个案例的详细信息
    case_details = []
    for case_id, result in case_results_list:
        detail = {"case_id": case_id}
        
        for strategy in strategies:
            strategy_data = result.get(strategy, {})
            versions = strategy_data.get("versions", [])
            
            detail[strategy] = {
                "pass_at_1": calculate_pass_at_k(versions, 1),  # 现在是概率值 (0.0-1.0)
                "pass_at_5": calculate_pass_at_k(versions, 5),
                "pass_at_10": calculate_pass_at_k(versions, 10),
                "total_versions": len(versions),
                "passed_versions": sum(1 for v in versions if v.get("passed", False)),
            }
        
        case_details.append(detail)
    
    return {
        "samples_total": total,
        "without_test": strategy_stats["without_test"],
        "origin_test": strategy_stats["origin_test"],
        "reduced_test": strategy_stats["reduced_test"],
        "case_details": case_details,
    }


def collect_repair_results(model_tag: str) -> Dict[str, List[Tuple[str, Dict]]]:
    """收集所有 repair results.json（去重，每个案例只保留一个结果）"""
    cases_map = load_cases()
    per_project: Dict[str, List[Tuple[str, Dict]]] = {}
    
    # 用于去重：case_id -> (mtime, result)
    case_to_result: Dict[str, Tuple[float, Dict, str]] = {}

    if not CASES_DATA_DIR.exists():
        return per_project

    # 查找所有 repair_results/**/results.json
    for results_json in CASES_DATA_DIR.rglob("**/repair_results/**/results.json"):
        try:
            result = read_json(results_json)
            
            # 从路径提取 case_id
            case_id = None
            for part in results_json.parts:
                if part.startswith("arvo-"):
                    case_id = part
                    break
            
            if not case_id:
                continue
            
            # 获取文件修改时间
            mtime = results_json.stat().st_mtime
            
            # 如果该案例还没有结果，或者当前文件更新，则保存
            if case_id not in case_to_result or mtime > case_to_result[case_id][0]:
                project = get_project_for_case(cases_map, case_id)
                case_to_result[case_id] = (mtime, result, project)
        except Exception as e:
            continue
    
    # 按项目分组
    for case_id, (_, result, project) in case_to_result.items():
        per_project.setdefault(project, []).append((case_id, result))

    return per_project


# ==================== 报告生成 ====================

def print_report(reduce_results: Dict, repair_results: Dict, show_details: bool = True):
    """打印完整报告"""
    
    def pct(x: float) -> str:
        return f"{x*100:.1f}%"
    
    def format_size(size: int) -> str:
        if size < 1024:
            return f"{size}B"
        elif size < 1024 * 1024:
            return f"{size/1024:.1f}KB"
        else:
            return f"{size/(1024*1024):.1f}MB"
    
    def format_time(seconds: float) -> str:
        """格式化时间，单位：秒 -> 分秒 或 时分秒"""
        if seconds < 60:
            return f"{seconds:.1f}s"
        elif seconds < 3600:
            minutes = int(seconds // 60)
            secs = int(seconds % 60)
            return f"{minutes}m{secs}s"
        else:
            hours = int(seconds // 3600)
            minutes = int((seconds % 3600) // 60)
            return f"{hours}h{minutes}m"
    
    print("\n" + "="*70)
    print("ReduceFix 完整实验统计")
    print("="*70)
    
    all_projects = sorted(set(reduce_results.keys()) | set(repair_results.keys()))
    
    for project in all_projects:
        print(f"\n{'='*70}")
        print(f"【{project.upper()}】")
        print(f"{'='*70}")
        
        # ===== Reduce 统计 =====
        if project in reduce_results:
            r = reduce_results[project]
            print(f"\n▶ Reduce 效果统计")
            print(f"  样本总数: {r['samples_total']}, 三法均完成: {r['samples_eligible']}")
            print(f"  ddmin       : 成功率 {pct(r['ddmin']['success_rate'])} | 平均压缩率 {pct(r['ddmin']['avg_compression_ratio'])} | 平均耗时 {format_time(r['ddmin']['avg_time_seconds'])}")
            print(f"  reducefix   : 成功率 {pct(r['reducefix']['success_rate'])} | 平均压缩率 {pct(r['reducefix']['avg_compression_ratio'])} | 平均耗时 {format_time(r['reducefix']['avg_time_seconds'])}")
            print(f"  llm-generated: 成功率 {pct(r['llm_generated']['success_rate'])} | 平均压缩率 {pct(r['llm_generated']['avg_compression_ratio'])} | 平均耗时 {format_time(r['llm_generated']['avg_time_seconds'])}")
            
            if show_details and r.get("case_details"):
                print(f"\n  样本详情:")
                for detail in r["case_details"]:
                    case_id = detail["case_id"]
                    orig_size = detail["original_size"]
                    dd = detail["ddmin"]
                    rf = detail["reducefix"]
                    lg = detail["llm_generated"]
                    
                    print(f"    {case_id} (原始: {format_size(orig_size)})")
                    print(f"      ddmin:     {format_size(dd['size'])} ({pct(dd['compression_ratio'])}) 耗时 {format_time(dd['time_seconds'])} {'✓' if dd['success'] else '✗'}")
                    print(f"      reducefix: {format_size(rf['size'])} ({pct(rf['compression_ratio'])}) 耗时 {format_time(rf['time_seconds'])} {'✓' if rf['success'] else '✗'}")
                    print(f"      generated: {format_size(lg['size'])} ({pct(lg['compression_ratio'])}) 耗时 {format_time(lg['time_seconds'])} {'✓' if lg['success'] else '✗'}")
        else:
            print(f"\n▶ Reduce 效果统计: 无数据")
        
        # ===== Repair 统计 =====
        if project in repair_results:
            rep = repair_results[project]
            print(f"\n▶ Repair 成功率统计 (TOP_K=10)")
            print(f"  样本总数: {rep['samples_total']}")
            print(f"\n  ┌─────────────────────┬─────────┬─────────┬──────────┐")
            print(f"  │ 策略                  │ pass@1  │ pass@5  │ pass@10  │")
            print(f"  ├─────────────────────┼─────────┼─────────┼──────────┤")
            
            wt = rep['without_test']
            ot = rep['origin_test']
            rt = rep['reduced_test']
            
            print(f"  │ 无测试用例 (Baseline)  │ {pct(wt['pass_at_1']):>7s} │ {pct(wt['pass_at_5']):>7s} │ {pct(wt['pass_at_10']):>8s} │")
            print(f"  │ 原始测试用例            │ {pct(ot['pass_at_1']):>7s} │ {pct(ot['pass_at_5']):>7s} │ {pct(ot['pass_at_10']):>8s} │")
            print(f"  │ 缩减测试用例 (ReduceFix) │ {pct(rt['pass_at_1']):>7s} │ {pct(rt['pass_at_5']):>7s} │ {pct(rt['pass_at_10']):>8s} │")
            print(f"  └─────────────────────┴─────────┴─────────┴──────────┘")
            
            if show_details and rep.get("case_details"):
                print(f"\n  样本详情:")
                for detail in rep["case_details"]:
                    case_id = detail["case_id"]
                    wt_d = detail["without_test"]
                    ot_d = detail["origin_test"]
                    rt_d = detail["reduced_test"]
                    
                    print(f"    {case_id}:")
                    print(f"      无测试:   pass@1={pct(wt_d['pass_at_1'])}  pass@5={pct(wt_d['pass_at_5'])}  pass@10={pct(wt_d['pass_at_10'])}  ({wt_d['passed_versions']}/{wt_d['total_versions']} 版本通过)")
                    print(f"      原始测试: pass@1={pct(ot_d['pass_at_1'])}  pass@5={pct(ot_d['pass_at_5'])}  pass@10={pct(ot_d['pass_at_10'])}  ({ot_d['passed_versions']}/{ot_d['total_versions']} 版本通过)")
                    print(f"      缩减测试: pass@1={pct(rt_d['pass_at_1'])}  pass@5={pct(rt_d['pass_at_5'])}  pass@10={pct(rt_d['pass_at_10'])}  ({rt_d['passed_versions']}/{rt_d['total_versions']} 版本通过)")
        else:
            print(f"\n▶ Repair 成功率统计: 无数据")


def main():
    import argparse
    parser = argparse.ArgumentParser(description="统计完整的 ReduceFix 实验结果（Reduce + Repair）")
    parser.add_argument("--model-tag", default="reducefix_qwen", help="模型标签目录名，默认 reducefix_qwen")
    parser.add_argument("--no-details", action="store_true", help="不显示每个样本的详细信息")
    args = parser.parse_args()

    # 收集 Reduce 统计
    per_project_reduce = collect_reduce_stats(args.model_tag)
    reduce_results: Dict[str, Dict] = {}
    for project, case_stats_list in per_project_reduce.items():
        reduce_results[project] = summarize_reduce(project, case_stats_list)

    # 收集 Repair 统计
    per_project_repair = collect_repair_results(args.model_tag)
    repair_results: Dict[str, Dict] = {}
    for project, case_results_list in per_project_repair.items():
        repair_results[project] = summarize_repair(project, case_results_list)

    # 打印报告
    print_report(reduce_results, repair_results, show_details=not args.no_details)

    # 保存 JSON
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    output_data = {
        "model_tag": args.model_tag,
        "reduce": reduce_results,
        "repair": repair_results,
    }
    with open(OUT_FILE, "w", encoding="utf-8") as f:
        json.dump(output_data, f, ensure_ascii=False, indent=2)
    
    print(f"\n{'='*70}")
    print(f"[Info] 统计结果已保存: {OUT_FILE}")
    print(f"{'='*70}\n")


if __name__ == "__main__":
    main()


#!/usr/bin/env python3
"""
重跑所有三个策略的修复结果

功能：
1. 重跑 no_tc, orig_tc, reduced_tc 三个策略
2. 每个策略生成 10 个版本
3. 使用统一的温度配置（temperature = 1.0）
4. 保存结果到标准位置
"""

import argparse
import json
import os
import sys
from pathlib import Path
from typing import Dict, List, Optional
import time

# 导入必要的模块
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from oss_fuzz_results.docker_patch_tester import DockerPatchTester
from oss_fuzz_results.apr_repair import (
    generate_versions_parallel,
    evaluate_strategy_versions,
    load_meta_info,
    load_buggy_code_from_patch,
    load_buggy_files_from_docker
)


# ==================== 配置 ====================
TOP_K = 10  # 每个策略生成 10 个版本
REPAIR_MODEL = "qwen-plus"
TEMPERATURE_RANGE = [1.0] * 10  # 统一使用 temperature = 1.0


def load_cases() -> Dict:
    """加载 cases.json"""
    cases_path = Path("oss_fuzz_results/cases.json")
    if not cases_path.exists():
        raise FileNotFoundError(f"cases.json not found: {cases_path}")
    with open(cases_path, "r", encoding="utf-8") as f:
        return json.load(f)


def rerun_all_strategies_for_case(
    case_id: str,
    model_tag: str = "reducefix_qwen"
) -> Dict:
    """
    重跑一个 case 的所有三个策略
    
    Args:
        case_id: 案例 ID (e.g., "arvo-22430")
        model_tag: reducer 标签（用于目录结构）
    
    Returns:
        包含三个策略结果的字典
    """
    
    print(f"\n{'='*70}")
    print(f"重跑所有策略: {case_id}")
    print(f"{'='*70}\n")
    
    # 1. 加载 case 配置
    cases = load_cases()
    case = cases.get(case_id)
    if not case:
        print(f"[Error] Case {case_id} not found in cases.json")
        return {"success": False, "error": "case_not_found"}
    
    target = case.get("target")
    docker_image = case.get("docker_image_vul")
    arvo_id = case.get("arvo_id")
    
    print(f"[Info] Target: {target}")
    print(f"[Info] Docker image: {docker_image}")
    print(f"[Info] ARVO ID: {arvo_id}")
    
    # 2. 加载测试用例
    testcase_path = Path(f"oss_fuzz_results/cases_data/{target}/{case_id}/testcase")
    if not testcase_path.exists():
        print(f"[Error] Testcase not found: {testcase_path}")
        return {"success": False, "error": "testcase_not_found"}
    
    testcase_data = testcase_path.read_bytes()
    testcase_hex = testcase_data.hex()
    print(f"[Info] ✓ Original testcase loaded: {len(testcase_data)} bytes")
    
    # 3. 检查是否有 reduced testcase
    reduced_testcase_path = Path(f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}/reduced.reducefix")
    reduced_testcase_hex = None
    if reduced_testcase_path.exists():
        reduced_testcase_data = reduced_testcase_path.read_bytes()
        reduced_testcase_hex = reduced_testcase_data.hex()
        print(f"[Info] ✓ Reduced testcase loaded: {len(reduced_testcase_data)} bytes")
    else:
        print(f"[Warning] Reduced testcase not found: {reduced_testcase_path}")
    
    # 4. 启动 Docker
    print(f"\n[Info] Starting Docker container...")
    docker_tester = DockerPatchTester(docker_image, target, timeout=120)
    docker_tester.start_container()
    container_id = docker_tester.container_id
    print(f"[Info] Container started: {container_id[:12]}")
    
    all_results = {}
    
    try:
        # 5. 加载 meta 信息和 buggy code
        print(f"\n[Info] Loading metadata and buggy code...")
        
        meta_info = load_meta_info(arvo_id) if arvo_id else None
        buggy_code = load_buggy_code_from_patch(arvo_id) if arvo_id else None
        
        if not meta_info or not buggy_code:
            print(f"[Error] Failed to load meta info or buggy code")
            return {"success": False, "error": "metadata_load_failed"}
        
        print(f"[Info] ✓ Metadata loaded")
        print(f"[Info] ✓ Buggy code loaded: {len(buggy_code.get('files', []))} files")
        
        # 6. 加载完整文件内容
        complete_files = load_buggy_files_from_docker(container_id, buggy_code, target)
        if not complete_files:
            print(f"[Error] Failed to load complete files from Docker")
            return {"success": False, "error": "files_load_failed"}
        
        print(f"[Info] ✓ Complete files loaded")
        
        # 7. 准备 crash 信息
        crash_info = {
            "crash_type": meta_info.get("crash_type", "unknown") if meta_info else "unknown",
            "stack_top": case.get("buggy_function", "unknown"),
            "stderr": ""
        }
        
        buggy_function = case.get("buggy_function", "unknown")
        crash_description = f"Crash in {buggy_function}"
        
        # 8. 运行三个策略
        strategies = [
            ("no_tc", None, "无测试用例"),
            ("orig_tc", testcase_hex, "原始测试用例"),
            ("reduced_tc", reduced_testcase_hex, "缩减测试用例")
        ]
        
        for strategy_key, tc_hex, strategy_name in strategies:
            print(f"\n{'='*70}")
            print(f"策略: {strategy_name} ({strategy_key})")
            print(f"{'='*70}\n")
            
            # 跳过没有 reduced testcase 的情况
            if strategy_key == "reduced_tc" and not tc_hex:
                print(f"[Skip] No reduced testcase available")
                all_results[strategy_key] = {
                    "success": False,
                    "error": "no_reduced_testcase",
                    "passed": False,
                    "versions": []
                }
                continue
            
            start_time = time.time()
            
            # 准备输出目录
            output_dir = Path(f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}/{strategy_key}")
            output_dir.mkdir(parents=True, exist_ok=True)
            
            # 生成修复版本
            print(f"[Info] Generating {TOP_K} repair attempts...")
            
            # 根据策略设置 testcase_hex
            if strategy_key == "reduced_tc":
                # reduced_tc: 使用 reduced testcase 作为主要的，原始的作为 secondary
                strategy_testcase_hex = tc_hex
                secondary_testcase_hex = testcase_hex
            else:
                # no_tc 和 orig_tc: 直接使用对应的 testcase
                strategy_testcase_hex = tc_hex
                secondary_testcase_hex = None
            
            versions = generate_versions_parallel(
                crash_info=crash_info,
                buggy_function=buggy_function,
                crash_description=crash_description,
                strategy=strategy_key,
                num_versions=TOP_K,
                buggy_code=buggy_code,
                meta_info=meta_info,
                complete_files=complete_files,
                testcase_hex=strategy_testcase_hex,
                secondary_testcase_hex=secondary_testcase_hex,
                model=REPAIR_MODEL,
                max_threads=4,
                docker_container_id=container_id,
                project=target,
                save_prompt_dir=str(output_dir)  # 保存 prompt 到策略目录
            )
            
            generation_time = time.time() - start_time
            print(f"\n[Info] ✓ Generated {len(versions)} versions in {generation_time:.1f}s")
            
            # 评估所有版本（使用原始测试用例）
            print(f"\n[Info] Evaluating versions against original testcase...")
            
            eval_start = time.time()
            
            strategy_result = evaluate_strategy_versions(
                strategy_name=strategy_name,
                strategy_key=strategy_key,
                patch_versions=versions,
                docker_tester=docker_tester,
                testcase_data=testcase_data  # 始终使用原始测试用例进行评估
            )
            
            eval_time = time.time() - eval_start
            print(f"[Info] ✓ Evaluation completed in {eval_time:.1f}s")
            
            # 统计成功率
            version_details = strategy_result.get("versions", [])
            passed_versions = [v for v in version_details if v.get("passed", False)]
            success_count = len(passed_versions)
            
            print(f"\n{'='*70}")
            print(f"修复结果统计 - {strategy_name}")
            print(f"{'='*70}")
            print(f"总尝试次数: {len(version_details)}")
            print(f"成功修复数: {success_count}")
            print(f"成功率: {success_count}/{len(version_details)} = {100*success_count/len(version_details) if version_details else 0:.1f}%")
            
            # 计算 pass@k
            pass_at_1 = 100.0 if success_count >= 1 else 0.0
            pass_at_5 = 100.0 if success_count >= 5 else (100.0 * success_count / 5 if success_count > 0 else 0.0)
            pass_at_10 = 100.0 * success_count / 10 if version_details else 0.0
            
            print(f"\npass@1:  {pass_at_1:.1f}%")
            print(f"pass@5:  {pass_at_5:.1f}%")
            print(f"pass@10: {pass_at_10:.1f}%")
            
            # 保存所有版本的 patch（不管是否成功）
            patches_dir = output_dir / "patches"
            patches_dir.mkdir(parents=True, exist_ok=True)
            
            for i, patch_code in enumerate(versions, 1):
                if patch_code:
                    patch_file = patches_dir / f"v{i}.patch"
                    patch_file.write_text(patch_code)
            
            print(f"\n[Info] ✓ Saved {len([p for p in versions if p])} patches to: {patches_dir}")
            
            # 保存评估结果（包含每个版本的详细信息）
            # 为了与统计脚本兼容，同时保存到上级目录
            parent_output_dir = Path(f"oss_fuzz_results/cases_data/{target}/{case_id}/{model_tag}")
            parent_output_dir.mkdir(parents=True, exist_ok=True)
            
            results_file = parent_output_dir / f"{strategy_key}_evaluation.json"
            with open(results_file, 'w', encoding='utf-8') as f:
                json.dump(strategy_result, f, indent=2)
            print(f"[Info] ✓ Evaluation results saved to: {results_file}")
            
            # 同时也保存到策略子目录
            detailed_results_file = output_dir / "evaluation.json"
            with open(detailed_results_file, 'w', encoding='utf-8') as f:
                json.dump(strategy_result, f, indent=2)
            
            # 创建一个包含 patch 内容的详细结果文件
            detailed_results_with_patches = {
                "strategy": strategy_key,
                "strategy_name": strategy_name,
                "evaluation": strategy_result,
                "patches": []
            }
            
            for i, (patch_code, version_info) in enumerate(zip(versions, version_details), 1):
                detailed_results_with_patches["patches"].append({
                    "version": i,
                    "patch": patch_code if patch_code else None,
                    "passed": version_info.get("passed", False),
                    "compiled": version_info.get("compiled", False),
                    "status": version_info.get("status", "unknown")
                })
            
            detailed_file = output_dir / "detailed_results.json"
            with open(detailed_file, 'w', encoding='utf-8') as f:
                json.dump(detailed_results_with_patches, f, indent=2)
            print(f"[Info] ✓ Detailed results (with patches) saved to: {detailed_file}")
            
            all_results[strategy_key] = {
                "success": True,
                "strategy_name": strategy_name,
                "total_versions": len(version_details),
                "passed_versions": success_count,
                "pass@1": pass_at_1,
                "pass@5": pass_at_5,
                "pass@10": pass_at_10,
                "generation_time": generation_time,
                "evaluation_time": eval_time,
                "result": strategy_result
            }
        
        return {
            "success": True,
            "case_id": case_id,
            "target": target,
            "strategies": all_results
        }
    
    except Exception as e:
        print(f"\n[Error] Exception occurred: {e}")
        import traceback
        traceback.print_exc()
        return {"success": False, "error": str(e)}
    
    finally:
        print(f"\n[Info] Cleaning up Docker container...")
        docker_tester.cleanup()


def main():
    """主函数：重跑指定样本的所有策略"""
    
    parser = argparse.ArgumentParser(
        description="重跑所有三个策略的修复结果"
    )
    parser.add_argument(
        "--model-tag",
        default="reducefix_qwen",
        help="Reducer model tag (for directory structure)"
    )
    parser.add_argument(
        "--case-ids",
        nargs="+",
        help="Case IDs to rerun (if not specified, run all cases with existing data)"
    )
    parser.add_argument(
        "--target",
        help="Target project (if specified, only run cases from this project)"
    )
    
    args = parser.parse_args()
    
    # 如果没有指定 case_ids，从 cases.json 中读取所有样本
    if not args.case_ids:
        cases = load_cases()
        case_ids = list(cases.keys())
        if args.target:
            case_ids = [cid for cid in case_ids if cases[cid].get("target") == args.target]
    else:
        case_ids = args.case_ids
    
    print(f"\n{'='*70}")
    print(f"重跑所有策略修复脚本")
    print(f"{'='*70}")
    print(f"目标样本数: {len(case_ids)}")
    print(f"Model: {REPAIR_MODEL}")
    print(f"Versions per strategy: {TOP_K}")
    print(f"Temperature: {TEMPERATURE_RANGE[0]} (unified)")
    print(f"{'='*70}\n")
    
    all_results = {}
    
    for i, case_id in enumerate(case_ids, 1):
        print(f"\n{'#'*70}")
        print(f"# Processing {i}/{len(case_ids)}: {case_id}")
        print(f"{'#'*70}")
        
        result = rerun_all_strategies_for_case(case_id, model_tag=args.model_tag)
        all_results[case_id] = result
        
        # 保存中间结果
        summary_file = Path("oss_fuzz_results/experiment_results/all_strategies_rerun_summary.json")
        summary_file.parent.mkdir(parents=True, exist_ok=True)
        with open(summary_file, 'w', encoding='utf-8') as f:
            json.dump(all_results, f, indent=2)
    
    # 打印总结
    print(f"\n{'='*70}")
    print(f"所有样本修复完成")
    print(f"{'='*70}\n")
    
    for case_id, result in all_results.items():
        if result.get("success") and "strategies" in result:
            print(f"\n{case_id}:")
            for strategy_key, strategy_result in result["strategies"].items():
                if strategy_result.get("success"):
                    print(f"  {strategy_result['strategy_name']} ({strategy_key}):")
                    print(f"    pass@1:  {strategy_result['pass@1']:.1f}%")
                    print(f"    pass@5:  {strategy_result['pass@5']:.1f}%")
                    print(f"    pass@10: {strategy_result['pass@10']:.1f}%")
                    print(f"    成功数:  {strategy_result['passed_versions']}/{strategy_result['total_versions']}")
                else:
                    print(f"  {strategy_key}: SKIPPED/FAILED - {strategy_result.get('error', 'unknown')}")
        else:
            print(f"\n{case_id}: FAILED - {result.get('error', 'unknown error')}")
    
    print(f"\n[Info] 汇总结果已保存: {summary_file}")
    
    # 返回成功状态
    success = all(r.get("success", False) for r in all_results.values())
    sys.exit(0 if success else 1)


if __name__ == "__main__":
    main()


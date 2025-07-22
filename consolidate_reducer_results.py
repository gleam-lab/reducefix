#!/usr/bin/env python3
"""
整理所有题目的 reduction 结果到统一的 reducer_results.json 文件中
从现有的 result_*.json 文件和文件系统中收集 reduction 结果
"""

import os
import json
import glob
from typing import Dict, List, Optional
import sys

# 从 run_batch.sh 中提取的题目列表
PROBLEMS = [
    "abc361c", "abc362d", "abc363e", "abc364d", "abc365d", "abc366c", 
    "abc367d", "abc368c", "abc369d", "abc370d", "abc371d", "abc372e", 
    "abc373e", "abc374e", "abc375c", "abc376c", "abc376e", "abc376d", 
    "abc377c", "abc377f"
]

reduced_input_file = "llm_reduced_input.txt"

# 可以从命令行添加更多题目
if len(sys.argv) > 1:
    additional_problems = sys.argv[1:]
    PROBLEMS.extend(additional_problems)
    print(f"[Info] 添加了额外的题目: {', '.join(additional_problems)}")

OUTPUT_FILE = "llm_reducer_results.json"

def load_json_safe(file_path: str) -> Optional[Dict]:
    """安全地加载JSON文件"""
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            return json.load(f)
    except Exception as e:
        print(f"[Warning] 无法加载 {file_path}: {e}")
        return None

def scan_file_system_for_reductions(problem_id: str) -> List[Dict]:
    """扫描文件系统中的 reduction 结果"""
    results = []
    problem_dir = problem_id
    
    if not os.path.isdir(problem_dir):
        return results
    
    for item in os.listdir(problem_dir):
        item_path = os.path.join(problem_dir, item)
        if os.path.isdir(item_path) and item.isdigit():
            submission_id = item
            
            # 检查必要文件
            reduced_input_path = os.path.join(item_path, reduced_input_file)
            wa_code_path = os.path.join(item_path, f"wa_{submission_id}.cpp")
            
            if os.path.exists(reduced_input_path) and os.path.exists(wa_code_path):
                # 收集更多信息
                original_input_path = os.path.join(item_path, "original_input.txt")
                
                # 获取文件大小
                original_size = None
                reduced_size = None
                try:
                    if os.path.exists(original_input_path):
                        original_size = os.path.getsize(original_input_path)
                    reduced_size = os.path.getsize(reduced_input_path)
                except Exception as e:
                    print(f"[Warning] 无法获取文件大小 {submission_id}: {e}")
                
                results.append({
                    "submission_id": submission_id,
                    "wa_code_path": wa_code_path,
                    "status_code": 200,
                    "message": "Successful reduction (from file system)",
                    "original_size_bytes": original_size,
                    "reduced_size_bytes": reduced_size,
                    "failing_case_name": None,  # 文件系统中没有这个信息
                    "execution_time_seconds": None  # 文件系统中没有这个信息
                })
    
    return results

def collect_problem_data(problem_id: str) -> Optional[Dict]:
    """收集单个题目的完整数据"""
    print(f"正在收集 {problem_id} 的数据...")
    
    # 1. 从文件系统扫描 reduction 结果
    file_system_results = scan_file_system_for_reductions(problem_id)
    
    # 2. 如果文件系统中没有找到任何结果，返回 None
    if not file_system_results:
        print(f"  {problem_id} 在文件系统中没有找到任何 reduction 结果")
        return None
    
    print(f"  从文件系统找到 {len(file_system_results)} 个 reduction 结果")
    
    # 3. 尝试从现有的 JSON 文件中找到最完整的数据来获取元数据
    json_files = glob.glob("result_*.json")
    best_data = None
    best_source = None
    
    for json_file in json_files:
        data = load_json_safe(json_file)
        if data and problem_id in data:
            problem_data = data[problem_id]
            
            # 检查数据完整性
            has_description = bool(problem_data.get("problem_description"))
            has_reducer_code = bool(problem_data.get("reducer_code"))
            has_results = bool(problem_data.get("results"))
            
            score = sum([has_description, has_reducer_code, has_results])
            
            if best_data is None or score > best_data["score"]:
                best_data = {
                    "data": problem_data,
                    "score": score,
                    "source": json_file
                }
                best_source = json_file
    
    if best_data:
        print(f"  从 {best_source} 获取到最佳数据 (完整性: {best_data['score']}/3)")
        problem_data = best_data["data"].copy()
        
        # 只保留文件系统中实际存在的结果，但保留现有结果的元数据
        file_system_ids = {r["submission_id"] for r in file_system_results}
        existing_results = problem_data.get("results", [])
        
        # 合并结果：文件系统为主，现有数据提供额外的元数据
        final_results = []
        for fs_result in file_system_results:
            # 查找现有结果中的匹配项
            matching_result = None
            for existing_result in existing_results:
                if str(existing_result.get("submission_id")) == fs_result["submission_id"]:
                    matching_result = existing_result.copy()
                    break
            
            if matching_result:
                # 合并：文件系统数据优先，但保留现有的额外元数据
                matching_result.update(fs_result)
                final_results.append(matching_result)
            else:
                # 只有文件系统数据
                final_results.append(fs_result)
        
        problem_data["results"] = final_results
    else:
        print(f"  未在现有JSON文件中找到 {problem_id} 的数据，创建新条目")
        problem_data = {
            "problem_description": "",
            "reducer_code": "",
            "results": file_system_results
        }
    
    # 4. 尝试获取缺失的 reducer_code
    if not problem_data.get("reducer_code"):
        reducer_file = os.path.join(problem_id, "reducer.py")
        if os.path.exists(reducer_file):
            try:
                with open(reducer_file, 'r', encoding='utf-8') as f:
                    problem_data["reducer_code"] = f.read()
                print(f"  从 {reducer_file} 读取了 reducer 代码")
            except Exception as e:
                print(f"  [Warning] 无法读取 {reducer_file}: {e}")
    
    # 5. 尝试获取缺失的 problem_description
    if not problem_data.get("problem_description"):
        # 尝试从缓存中获取
        cache_path = f".atcoder_cache/problems/{problem_id[:6]}/{problem_id}/description.md"
        if os.path.exists(cache_path):
            try:
                with open(cache_path, 'r', encoding='utf-8') as f:
                    problem_data["problem_description"] = f.read()
                print(f"  从缓存获取了问题描述")
            except Exception as e:
                print(f"  [Warning] 无法读取缓存描述: {e}")
    
    return problem_data

def main():
    print(f"开始整理 {len(PROBLEMS)} 个题目的 reduction 结果...")
    print(f"输出文件: {OUTPUT_FILE}")
    
    # 加载现有的整理结果（如果存在）
    consolidated_data = {}
    if os.path.exists(OUTPUT_FILE):
        print(f"加载现有的整理结果: {OUTPUT_FILE}")
        consolidated_data = load_json_safe(OUTPUT_FILE) or {}
    
    # 收集所有题目的数据
    for problem_id in PROBLEMS:
        problem_data = collect_problem_data(problem_id)
        if problem_data:
            consolidated_data[problem_id] = problem_data
            result_count = len(problem_data.get("results", []))
            print(f"  ✓ {problem_id}: {result_count} 个 reduction 结果")
        else:
            print(f"  ✗ {problem_id}: 没有找到 reduction 结果")
    
    # 保存整理后的结果
    try:
        with open(OUTPUT_FILE, 'w', encoding='utf-8') as f:
            json.dump(consolidated_data, f, indent=2, ensure_ascii=False)
        
        print(f"\n整理完成！")
        print(f"输出文件: {OUTPUT_FILE}")
        print(f"包含题目: {len(consolidated_data)} 个")
        
        # 统计信息
        total_results = sum(len(data.get("results", [])) for data in consolidated_data.values())
        print(f"总计 reduction 结果: {total_results} 个")
        
        # 按题目显示结果数量
        print("\n各题目结果数量:")
        for problem_id, data in consolidated_data.items():
            result_count = len(data.get("results", []))
            print(f"  {problem_id}: {result_count} 个")
            
    except Exception as e:
        print(f"[Error] 保存失败: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main() 

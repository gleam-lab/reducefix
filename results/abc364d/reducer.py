import os
import subprocess
from typing import List, Tuple, Optional
import sys

def run_program(program_path: str, input_data: bytes) -> bytes:
    result = subprocess.run(
        [program_path], 
        input=input_data,
        capture_output=True,
        check=True,  
        timeout=10   
    )
    return result.stdout

def create_input_bytes(a_list: List[int], queries: List[Tuple[int, int]]) -> bytes:
    if not a_list and not queries:
        return b"0 0\n\n"
    
    lines = [f"{len(a_list)} {len(queries)}\n"]
    lines.append(" ".join(map(str, a_list)) + "\n")
    for b_val, k_val in queries:
        lines.append(f"{b_val} {k_val}\n")
    
    return "".join(lines).encode("utf-8")

def test_interesting(a_list: List[int], queries: List[Tuple[int, int]]) -> bool:
    if not a_list or not queries:
        return False
    
    input_data = create_input_bytes(a_list, queries)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except:
        return True  # Assume interesting on error

def reduce_queries_ddmin(original_queries: List[Tuple[int, int]], a_list: List[int]) -> List[Tuple[int, int]]:
    if not test_interesting(a_list, original_queries):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_queries
    
    print(f"[Info] 初始查询数量={len(original_queries)}，开始 ddmin 缩减...\n")
    current_indices = list(range(len(original_queries)))
    granularity = 2
    
    while len(current_indices) >= 1:
        print(f"[Reduce] 当前查询索引数={len(current_indices)}: {current_indices}")
        print(f"         尝试粒度: {granularity}")
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        start_idx = 0
        made_progress = False
        
        def check_candidate(candidate_indices: List[int]) -> bool:
            if not candidate_indices:
                return False
            reduced_queries = [original_queries[i] for i in candidate_indices]
            return test_interesting(a_list, reduced_queries)
        
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_indices:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = [i for i in current_indices if i not in block]
            print(f"            - 移除 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新查询索引数={len(candidate_indices)}")
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            else:
                print("失败")
                start_idx += subset_size
        
        if made_progress:
            continue
        
        print(f"         2) 尝试『只保留』大小约={subset_size} 的分块...")
        start_idx = 0
        while start_idx < num_indices:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = block
            if len(candidate_indices) == 0 or len(candidate_indices) == num_indices:
                start_idx += subset_size
                continue
            print(f"            - 只保留 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新查询索引数={len(candidate_indices)}")
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            else:
                print("失败")
            start_idx += subset_size
        
        if made_progress:
            continue
        
        if granularity < num_indices:
            new_gran = min(granularity * 2, num_indices)
            print(f"         -> 无进展，增大粒度至 {new_gran}\n")
            granularity = new_gran
        else:
            print("\n[Reduce] 已无法进一步缩减 —— 到达 1-minimal。")
            break
    
    reduced_queries = [original_queries[i] for i in current_indices]
    print(f"\n[Result] 缩减后查询数={len(reduced_queries)}，保留下标: {current_indices}")
    return reduced_queries

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if not lines:
        raise ValueError("输入文件为空")
    
    header = lines[0].split()
    if len(header) != 2:
        raise ValueError(f"首行格式错误: {header}")
    
    N, Q = map(int, header)
    a_line = lines[1].split()
    
    if len(a_line) != N:
        raise ValueError(f"A数组长度不匹配: 预期 {N}, 实际 {len(a_line)}")
    
    a_list = list(map(int, a_line))
    query_lines = lines[2:2+Q]
    
    if len(query_lines) != Q:
        raise ValueError(f"查询行数不匹配: 预期 {Q}, 实际 {len(query_lines)}")
    
    queries = []
    for line in query_lines:
        parts = line.split()
        if len(parts) != 2:
            raise ValueError(f"查询行格式错误: {line}")
        b_val, k_val = map(int, parts)
        queries.append((b_val, k_val))
    
    reduced_queries = reduce_queries_ddmin(queries, a_list)
    
    output_bytes = create_input_bytes(a_list, reduced_queries)
    
    with open(output_file, "wb") as f:
        f.write(output_bytes)
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
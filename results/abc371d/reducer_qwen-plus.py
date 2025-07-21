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

def create_input_bytes(X: List[int], P: List[int], queries: List[Tuple[int, int]]) -> bytes:
    lines = []
    N = len(X)
    Q = len(queries)
    lines.append(f"{N}\n")
    lines.append(" ".join(map(str, X)) + "\n")
    lines.append(" ".join(map(str, P)) + "\n")
    lines.append(f"{Q}\n")
    for L, R in queries:
        lines.append(f"{L} {R}\n")
    return "".join(lines).encode("utf-8")

def test_interesting(data: Tuple[List[int], List[int], List[Tuple[int, int]]]) -> bool:
    X, P, queries = data
    if not X or not P or not queries:
        return False
    input_data = create_input_bytes(X, P, queries)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except:
        return False

def reduce_queries_ddmin(original_queries: List[Tuple[int, int]], X: List[int], P: List[int]) -> List[Tuple[int, int]]:
    if not original_queries:
        return []
    
    def check_candidate(candidate_queries: List[Tuple[int, int]]) -> bool:
        return test_interesting((X, P, candidate_queries))
    
    current_queries = original_queries.copy()
    granularity = 2
    
    while len(current_queries) >= 1:
        print(f"[Reduce Queries] 当前查询数={len(current_queries)}")
        print(f"         尝试粒度: {granularity}")
        num_queries = len(current_queries)
        subset_size = max(1, num_queries // granularity)
        start_idx = 0
        made_progress = False
        
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_queries:
            block = current_queries[start_idx:start_idx + subset_size]
            candidate_queries = [q for i, q in enumerate(current_queries) if i not in range(start_idx, start_idx + subset_size)]
            print(f"            - 移除索引 {start_idx}~{start_idx + subset_size - 1} ... ", end="")
            if check_candidate(candidate_queries):
                print(f"成功! 新查询数={len(candidate_queries)}")
                current_queries = candidate_queries
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
        while start_idx < num_queries:
            block = current_queries[start_idx:start_idx + subset_size]
            candidate_queries = block
            if len(candidate_queries) == 0 or len(candidate_queries) == num_queries:
                start_idx += subset_size
                continue
            print(f"            - 只保留索引 {start_idx}~{start_idx + subset_size - 1} ... ", end="")
            if check_candidate(candidate_queries):
                print(f"成功! 新查询数={len(candidate_queries)}")
                current_queries = candidate_queries
                granularity = 2  
                made_progress = True
                break
            else:
                print("失败")
            start_idx += subset_size
            
        if made_progress:
            continue
            
        if granularity < num_queries:
            new_gran = min(granularity * 2, num_queries)
            print(f"         -> 无进展，增大粒度至 {new_gran}\n")
            granularity = new_gran
        else:
            print("\n[Reduce Queries] 已无法进一步缩减 —— 到达 1-minimal。")
            break
            
    print(f"\n[Result] 缩减后查询数={len(current_queries)}")
    return current_queries

def reduce_villages_ddmin(original_X: List[int], original_P: List[int], queries: List[Tuple[int, int]]) -> Tuple[List[int], List[int]]:
    if not original_X or not original_P:
        return ([], [])
        
    if not test_interesting((original_X, original_P, queries)):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return (original_X, original_P)
        
    print(f"[Info] 初始村庄数 N={len(original_X)} 已确认导致输出差异，开始 ddmin 缩减...\n")
    
    current_indices = list(range(len(original_X)))
    granularity = 2
    
    while len(current_indices) >= 1:
        print(f"[Reduce Villages] 当前村庄数={len(current_indices)}")
        print(f"         尝试粒度: {granularity}")
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        start_idx = 0
        made_progress = False
        
        def check_candidate(candidate_indices: List[int]) -> bool:
            if not candidate_indices:
                return False
            X = [original_X[i] for i in candidate_indices]
            P = [original_P[i] for i in candidate_indices]
            return test_interesting((X, P, queries))
            
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_indices:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = [x for x in current_indices if x not in block]
            print(f"            - 移除 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新村庄数={len(candidate_indices)}")
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
                print(f"成功! 新村庄数={len(candidate_indices)}")
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
            print("\n[Reduce Villages] 已无法进一步缩减 —— 到达 1-minimal。")
            break
            
    final_X = [original_X[i] for i in current_indices]
    final_P = [original_P[i] for i in current_indices]
    print(f"\n[Result] 缩减后村庄数={len(final_X)}，保留下标: {current_indices}")
    return (final_X, final_P)

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if not lines:
        raise ValueError("输入文件为空")
    
    # 解析输入
    ptr = 0
    N = int(lines[ptr])
    ptr += 1
    
    X = list(map(int, lines[ptr].split()))
    ptr += 1
    
    P = list(map(int, lines[ptr].split()))
    ptr += 1
    
    Q = int(lines[ptr])
    ptr += 1
    
    queries = []
    for _ in range(Q):
        L, R = map(int, lines[ptr].split())
        queries.append((L, R))
        ptr += 1
    
    # 先缩减村庄数据
    reduced_X, reduced_P = reduce_villages_ddmin(X, P, queries)
    
    # 再缩减查询数据
    reduced_queries = reduce_queries_ddmin(queries, reduced_X, reduced_P)
    
    # 写入输出文件
    output_bytes = create_input_bytes(reduced_X, reduced_P, reduced_queries)
    with open(output_file, "wb") as f:
        f.write(output_bytes)
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
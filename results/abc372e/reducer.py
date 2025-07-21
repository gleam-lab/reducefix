import os
import subprocess
from typing import List, Tuple, Set, Dict
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

def create_input_bytes(queries: List[str], N: int) -> bytes:
    if not queries:
        return b"0 0\n"
    lines = [f"{N} {len(queries)}\n"]
    for q in queries:
        lines.append(q + "\n")
    return "".join(lines).encode("utf-8")

def test_interesting(queries: List[str], N: int) -> bool:
    if not queries:
        return False
    input_data = create_input_bytes(queries, N)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except:
        return False

def get_vertices_in_queries(queries: List[str]) -> Set[int]:
    vertices = set()
    for query in queries:
        parts = query.split()
        if parts[0] == '1':  # Type 1: u v
            vertices.add(int(parts[1]))
            vertices.add(int(parts[2]))
        elif parts[0] == '2':  # Type 2: v k
            vertices.add(int(parts[1]))
    return vertices

def reduce_queries_ddmin(original_queries: List[str], original_N: int) -> Tuple[List[str], int]:
    if not test_interesting(original_queries, original_N):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_queries, original_N
    
    print(f"[Info] 初始查询数={len(original_queries)}，开始 ddmin 缩减...\n")
    
    # First try to reduce the number of queries
    current_queries = original_queries.copy()
    granularity = 2
    
    while len(current_queries) >= 1:
        print(f"[Reduce] 当前查询数={len(current_queries)}")
        print(f"         尝试粒度: {granularity}")
        subset_size = max(1, len(current_queries) // granularity)
        made_progress = False
        
        # Try removing a block
        start_idx = 0
        while start_idx < len(current_queries):
            block = current_queries[start_idx:start_idx+subset_size]
            candidate_queries = [q for idx, q in enumerate(current_queries) if idx not in range(start_idx, start_idx+subset_size)]
            
            print(f"         尝试移除从 {start_idx} 开始的 {subset_size} 个查询...", end="")
            if test_interesting(candidate_queries, original_N):
                print("成功!")
                current_queries = candidate_queries
                granularity = 2
                made_progress = True
                break
            else:
                print("失败")
                start_idx += subset_size
        
        if made_progress:
            continue
            
        # Try keeping only a block
        start_idx = 0
        while start_idx < len(current_queries):
            block = current_queries[start_idx:start_idx+subset_size]
            candidate_queries = block
            
            print(f"         尝试只保留从 {start_idx} 开始的 {subset_size} 个查询...", end="")
            if test_interesting(candidate_queries, original_N):
                print("成功!")
                current_queries = candidate_queries
                granularity = 2
                made_progress = True
                break
            else:
                print("失败")
                start_idx += subset_size
                
        if made_progress:
            continue
            
        if granularity < len(current_queries):
            new_gran = min(granularity * 2, len(current_queries))
            print(f"         -> 无进展，增大粒度至 {new_gran}\n")
            granularity = new_gran
        else:
            print("\n[Reduce] 已无法进一步缩减查询数量 —— 到达 1-minimal。")
            break
    
    # Now try to reduce the vertex numbers while preserving the structure
    vertices_used = get_vertices_in_queries(current_queries)
    if vertices_used:
        vertex_mapping = {}
        new_vertex_id = 1
        for vid in sorted(vertices_used):
            vertex_mapping[vid] = new_vertex_id
            new_vertex_id += 1
        
        remapped_queries = []
        for query in current_queries:
            parts = query.split()
            if parts[0] == '1':
                u, v = int(parts[1]), int(parts[2])
                remapped = f"1 {vertex_mapping[u]} {vertex_mapping[v]}"
                remapped_queries.append(remapped)
            elif parts[0] == '2':
                v, k = int(parts[1]), int(parts[2])
                remapped = f"2 {vertex_mapping[v]} {k}"
                remapped_queries.append(remapped)
        
        final_N = len(vertex_mapping)
    else:
        remapped_queries = []
        final_N = 0
    
    print(f"\n[Result] 缩减后查询数={len(remapped_queries)}，顶点编号={final_N}")
    return remapped_queries, final_N

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 
    
    lines = []
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if not lines:
        raise ValueError("输入文件为空")
    
    first_line = lines[0].strip().split()
    if len(first_line) != 2:
        raise ValueError(f"第一行应包含两个整数: N Q")
    
    N, Q = int(first_line[0]), int(first_line[1])
    
    if len(lines) != Q + 1:
        raise ValueError(f"输入应包含 {Q + 1} 行, 实际为 {len(lines)} 行.")
    
    queries = lines[1:]  # Skip first line
    
    reduced_queries, reduced_N = reduce_queries_ddmin(queries, N)
    
    output_data = create_input_bytes(reduced_queries, reduced_N)
    
    with open(output_file, "wb") as f:
        f.write(output_data)
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
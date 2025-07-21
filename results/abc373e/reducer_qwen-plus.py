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

def create_input_bytes(N: int, M: int, K: int, A: List[int]) -> bytes:
    input_str = f"{N} {M} {K}\n{' '.join(map(str, A))}\n"
    return input_str.encode("utf-8")

def test_interesting(data: Tuple[int, int, int, List[int]]) -> bool:
    N, M, K, A = data
    input_data = create_input_bytes(N, M, K, A)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except:
        return True  # Assume interesting if program fails

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 

    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if len(lines) < 2:
        raise ValueError("输入文件不完整，缺少必要的行数")
    
    header = list(map(int, lines[0].split()))
    if len(header) != 3:
        raise ValueError("第一行应包含三个整数 N, M, K")
    N, M, K = header
    
    A = list(map(int, lines[1].split()))
    if len(A) != N:
        raise ValueError(f"第二行应包含 {N} 个整数，实际为 {len(A)} 个")
    
    total_votes = sum(A)
    remaining_votes = K - total_votes
    if remaining_votes < 0:
        raise ValueError("剩余票数为负数")

    # Initial test to confirm this is an interesting case
    if not test_interesting((N, M, K, A)):
        print("[Info] 初始输入未造成差异，无需缩减")
        with open(output_file, "w") as f:
            f.write(f"{N} {M} {K}\n{' '.join(map(str, A))}\n")
        return

    print(f"[Info] 初始输入已确认导致输出差异，开始缩减 N={N}")
    
    # Try reducing candidates
    candidate_indices = list(range(N))
    granularity = 2
    
    while len(candidate_indices) > 1:
        print(f"[Reduce] 当前候选人数量={len(candidate_indices)}, 粒度={granularity}")
        subset_size = max(1, len(candidate_indices) // granularity)
        made_progress = False
        
        # Try removing subsets
        start_idx = 0
        while start_idx < len(candidate_indices):
            block = candidate_indices[start_idx:start_idx + subset_size]
            reduced_A = [A[i] if i in block else 0 for i in candidate_indices]
            reduced_K = sum(reduced_A) + remaining_votes
            
            if test_interesting((len(block), M, reduced_K, reduced_A)):
                candidate_indices = block
                granularity = 2
                made_progress = True
                break
            
            start_idx += subset_size
        
        if made_progress:
            continue
            
        # Try keeping only subsets
        start_idx = 0
        while start_idx < len(candidate_indices):
            block = candidate_indices[start_idx:start_idx + subset_size]
            if len(block) == len(candidate_indices):
                start_idx += subset_size
                continue
                
            reduced_A = [A[i] for i in block]
            reduced_K = sum(reduced_A) + remaining_votes
            
            if test_interesting((len(block), M, reduced_K, reduced_A)):
                candidate_indices = block
                granularity = 2
                made_progress = True
                break
            
            start_idx += subset_size
        
        if made_progress:
            continue
            
        if granularity < len(candidate_indices):
            granularity = min(granularity * 2, len(candidate_indices))
            print(f"[Reduce] 增大粒度至 {granularity}")
        else:
            print("[Reduce] 已无法进一步缩减")
            break
    
    # Final reduction
    reduced_A = [A[i] for i in candidate_indices]
    reduced_N = len(reduced_A)
    reduced_K = sum(reduced_A) + remaining_votes
    
    print(f"[Result] 缩减后数据: N={reduced_N}, M={M}, K={reduced_K}")
    
    with open(output_file, "w") as f:
        f.write(f"{reduced_N} {M} {reduced_K}\n{' '.join(map(str, reduced_A))}\n")
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
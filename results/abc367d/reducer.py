# START --- abc367d/reducer.py --- START
import os
import subprocess
from typing import List, Optional
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

def create_input_bytes(reduced_A: List[int]) -> bytes:
    if not reduced_A:
        return b"0 0\n"
    N = len(reduced_A)
    M = 1  # Placeholder; actual M will be determined from original input
    lines = [f"{N} {M}\n", " ".join(map(str, reduced_A)) + "\n"]
    return "".join(lines).encode("utf-8")

def test_interesting(reduced_A: List[int]) -> bool:
    if not reduced_A:
        return False
    input_data = create_input_bytes(reduced_A)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except subprocess.CalledProcessError as e:
        print(f"[Error] Program execution failed: {e}")
        return False

def reduce_array_ddmin(original_A: List[int]) -> List[int]:
    if not test_interesting(original_A):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_A
    
    print(f"[Info] 初始数组长度={len(original_A)} 已确认导致输出差异，开始 ddmin 缩减...\n")
    current_indices = list(range(len(original_A)))
    granularity = 2
    
    while len(current_indices) >= 1:
        print(f"[Reduce] 当前下标集大小={len(current_indices)}: {current_indices}")
        print(f"         尝试粒度: {granularity}")
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        start_idx = 0
        made_progress = False
        
        def check_candidate(candidate_indices: List[int]) -> bool:
            if not candidate_indices:
                return False
            reduced_A = [original_A[i] for i in sorted(candidate_indices)]
            return test_interesting(reduced_A)
        
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_indices:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = [i for i in current_indices if i not in block]
            print(f"            - 移除 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新下标集大小={len(candidate_indices)}")
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
                print(f"成功! 新下标集大小={len(candidate_indices)}")
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
    
    reduced_A = [original_A[i] for i in sorted(current_indices)]
    print(f"\n[Result] 缩减后数组长度={len(reduced_A)}，保留下标: {current_indices}")
    return reduced_A

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if not lines:
        raise ValueError("输入文件为空")
    
    header = lines[0].strip().split()
    if len(header) != 2 or not header[0].isdigit() or not header[1].isdigit():
        raise ValueError(f"首行为非有效数字: {header}")
    
    N = int(header[0])
    A_strs = lines[1].strip().split()
    if len(A_strs) != N:
        raise ValueError(f"A 数组长度不匹配: 期望 {N}, 实际 {len(A_strs)}")
    
    try:
        A = list(map(int, A_strs))
    except ValueError:
        raise ValueError("A 数组包含非整数值")
    
    reduced_A = reduce_array_ddmin(A)
    
    # Write reduced input
    with open(output_file, "w", encoding="utf-8") as f:
        f.write(f"{len(reduced_A)} 1\n")  # M is placeholder 1
        f.write(" ".join(map(str, reduced_A)) + "\n")
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
# END --- abc367d/reducer.py --- END
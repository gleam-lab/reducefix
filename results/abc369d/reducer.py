# START --- abc369d/reducer.py --- START
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

def create_input_bytes(values: List[int]) -> bytes:
    if not values:
        return b"0\n\n"
    N = len(values)
    a_line = " ".join(map(str, values))
    return f"{N}\n{a_line}\n".encode("utf-8")

def test_interesting(values: List[int]) -> bool:
    if not values:
        return False
    input_data = create_input_bytes(values)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except Exception as e:
        print(f"[Error] 测试有趣性时发生异常: {e}")
        return False

def reduce_array_ddmin(original_values: List[int]) -> List[int]:
    if not test_interesting(original_values):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_values
    print(f"[Info] 初始数组长度={len(original_values)} 已确认导致输出差异，开始 ddmin 缩减...\n")
    
    current_indices = list(range(len(original_values)))
    granularity = 2
    
    while len(current_indices) >= 1:
        print(f"[Reduce] 当前索引集大小={len(current_indices)}: {current_indices}")
        print(f"         尝试粒度: {granularity}")
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        start_idx = 0
        made_progress = False
        
        def check_candidate(candidate_indices: List[int]) -> bool:
            if not candidate_indices:
                return False
            values = [original_values[i] for i in candidate_indices]
            return test_interesting(values)
        
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_indices:
            block_start = start_idx
            block_end = min(start_idx + subset_size, num_indices)
            block = current_indices[block_start:block_end]
            candidate_indices = [x for x in current_indices if x not in block]
            print(f"            - 移除 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新索引集大小={len(candidate_indices)}")
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
            block_start = start_idx
            block_end = min(start_idx + subset_size, num_indices)
            block = current_indices[block_start:block_end]
            candidate_indices = block
            if len(candidate_indices) == 0 or len(candidate_indices) == num_indices:
                start_idx += subset_size
                continue
            print(f"            - 只保留 {block} ... ", end="")
            if check_candidate(candidate_indices):
                print(f"成功! 新索引集大小={len(candidate_indices)}")
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
    
    final_values = [original_values[i] for i in current_indices]
    print(f"\n[Result] 缩减后数组大小 M={len(final_values)}，保留下标: {current_indices}")
    return final_values

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]
    
    if not lines:
        raise ValueError("输入文件为空")
    
    n_str = lines[0].strip()
    if not n_str.isdigit():
        raise ValueError(f"第一行为非数字: {n_str}")
    
    N = int(n_str)
    
    if len(lines) < 2:
        raise ValueError(f"输入行数不足: 至少需要 2 行, 实际只有 {len(lines)} 行.")
    
    A_line = lines[1].split()
    if len(A_line) != N:
        raise ValueError(f"A 数组长度不匹配: 期望 {N}, 实际 {len(A_line)}")
    
    try:
        A = list(map(int, A_line))
    except ValueError:
        raise ValueError("A 数组包含非整数值")
    
    reduced_A = reduce_array_ddmin(A)
    
    output_bytes = create_input_bytes(reduced_A)
    
    with open(output_file, "wb") as f:
        f.write(output_bytes)
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
# END --- abc369d/reducer.py --- END
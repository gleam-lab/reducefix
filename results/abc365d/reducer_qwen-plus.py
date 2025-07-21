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

def create_input_bytes(s: str) -> bytes:
    return f"{len(s)}\n{s}\n".encode("utf-8")

def test_interesting(s: str) -> bool:
    if not s:
        return False
    input_data = create_input_bytes(s)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except subprocess.CalledProcessError:
        return True  # Assume interesting if either program fails

def reduce_string_ddmin(original_s: str) -> str:
    if not test_interesting(original_s):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_s
    print(f"[Info] 初始字符串长度={len(original_s)} 已确认导致输出差异，开始 ddmin 缩减...\n")
    
    current_indices = list(range(len(original_s)))
    granularity = 2
    
    while len(current_indices) >= 1:
        print(f"[Reduce] 当前索引集大小={len(current_indices)}")
        print(f"         尝试粒度: {granularity}")
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        start_idx = 0
        made_progress = False
        
        def indices_to_str(indices: List[int]) -> str:
            return ''.join(original_s[i] for i in sorted(indices))
        
        def check_candidate(candidate_indices: List[int]) -> bool:
            if not candidate_indices:
                return False
            candidate_str = indices_to_str(candidate_indices)
            return test_interesting(candidate_str)
        
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < num_indices:
            block = current_indices[start_idx:start_idx + subset_size]
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
            block = current_indices[start_idx:start_idx + subset_size]
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
    
    final_str = indices_to_str(current_indices)
    print(f"\n[Result] 缩减后字符串长度={len(final_str)}")
    print(f"         内容: {final_str}")
    return final_str

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return
    
    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip('\n') for line in f]
    
    if len(lines) < 2:
        raise ValueError("输入数据不完整")
    
    N_str = lines[0].strip()
    if not N_str.isdigit():
        raise ValueError(f"第一行不是有效整数: {N_str}")
    
    N = int(N_str)
    S = lines[1]
    
    if len(S) != N:
        raise ValueError(f"字符串长度不匹配: 应为 {N}, 实为 {len(S)}")
    
    reduced_S = reduce_string_ddmin(S)
    
    output_bytes = create_input_bytes(reduced_S)
    
    with open(output_file, "wb") as f:
        f.write(output_bytes)
    
    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
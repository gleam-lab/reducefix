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

def create_input_bytes(processes: List[Tuple[int, int, int, int]]) -> bytes:
    if not processes:
        return b"0 0\n"
    lines = []
    N = len(processes)
    lines.append(f"{N} 0\n")  # X is irrelevant for reduction; kept as 0
    for a, p, b, q in processes:
        lines.append(f"{a} {p} {b} {q}\n")
    return "".join(lines).encode("utf-8")

def test_interesting(processes: List[Tuple[int, int, int, int]]) -> bool:
    if not processes:
        return False
    input_data = create_input_bytes(processes)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except subprocess.CalledProcessError:
        return False

def reduce_processes_ddmin(original_processes: List[Tuple[int, int, int, int]]) -> List[Tuple[int, int, int, int]]:
    if not test_interesting(original_processes):
        print("[Error] 初始输入并未造成 WA 与 AC 不一致，无法缩减。")
        return original_processes
    print("[Info] 初始输入已确认导致输出差异，开始 ddmin 缩减...\n")
    N = len(original_processes)
    current_indices = list(range(N))
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
            sub_processes = [original_processes[i] for i in candidate_indices]
            return test_interesting(sub_processes)

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

    final_processes = [original_processes[i] for i in current_indices]
    print(f"\n[Result] 缩减后工序数量 M={len(final_processes)}，保留下标: {current_indices}")
    return final_processes

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return 

    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.rstrip("\n") for line in f]

    if not lines:
        raise ValueError("输入文件为空")

    first_line = lines[0].split()
    if len(first_line) != 2:
        raise ValueError(f"第一行格式错误: {lines[0]}")

    N = int(first_line[0])
    X = int(first_line[1])

    processes = []
    for i in range(N):
        if i + 1 >= len(lines):
            raise ValueError(f"输入行数不足: 缺少第 {i+2} 行")
        parts = lines[i+1].split()
        if len(parts) != 4:
            raise ValueError(f"第 {i+2} 行格式错误: {lines[i+1]}")
        A, P, B, Q = map(int, parts)
        processes.append((A, P, B, Q))

    reduced_processes = reduce_processes_ddmin(processes)

    output_lines = []
    M = len(reduced_processes)
    output_lines.append(f"{M} 0\n")  # X is irrelevant for reduction
    for a, p, b, q in reduced_processes:
        output_lines.append(f"{a} {p} {b} {q}\n")

    output_bytes = "".join(output_lines).encode("utf-8")

    with open(output_file, "wb") as f:
        f.write(output_bytes)

    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
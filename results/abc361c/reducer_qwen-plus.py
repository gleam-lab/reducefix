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

def create_input_bytes(subsequence: List[int]) -> bytes:
    if not subsequence:
        return b"0 0\n\n"
    N = len(subsequence)
    K = 0  # Since we're testing reduced cases, K is adjusted accordingly in reduce_input
    line = f"{N} {K}\n"
    line += " ".join(map(str, subsequence)) + "\n"
    return line.encode("utf-8")

def test_interesting(subseq: List[int]) -> bool:
    if not subseq:
        return False
    input_data = create_input_bytes(subseq)
    try:
        wa_output = run_program("./wa", input_data)
        ac_output = run_program("./ac", input_data)
        return (wa_output.strip() != ac_output.strip())
    except Exception as e:
        print(f"[Error] 执行程序时出错: {e}")
        return False

def reduce_ddmin(original_seq: List[int]) -> List[int]:
    N = len(original_seq)
    current_indices = list(range(N))
    granularity = 2

    while len(current_indices) > 1:
        print(f"[Reduce] 当前下标集大小={len(current_indices)}: {current_indices}")
        print(f"         尝试粒度: {granularity}")
        subset_size = max(1, len(current_indices) // granularity)
        made_progress = False

        # Try removing a block
        start_idx = 0
        print(f"         1) 尝试『移除』大小约={subset_size} 的分块...")
        while start_idx < len(current_indices):
            block = current_indices[start_idx:start_idx + subset_size]
            candidate = [x for x in current_indices if x not in block]
            if len(candidate) < 2:
                start_idx += subset_size
                continue
            subseq = [original_seq[i] for i in candidate]
            print(f"            - 移除索引 {block} ... ", end="")
            if test_interesting(subseq):
                print(f"成功! 新下标集大小={len(candidate)}")
                current_indices = candidate
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
        print(f"         2) 尝试『只保留』大小约={subset_size} 的分块...")
        while start_idx < len(current_indices):
            block = current_indices[start_idx:start_idx + subset_size]
            candidate = block
            if len(candidate) == len(current_indices) or len(candidate) < 2:
                start_idx += subset_size
                continue
            subseq = [original_seq[i] for i in candidate]
            print(f"            - 只保留索引 {block} ... ", end="")
            if test_interesting(subseq):
                print(f"成功! 新下标集大小={len(candidate)}")
                current_indices = candidate
                granularity = 2
                made_progress = True
                break
            else:
                print("失败")
            start_idx += subset_size
        if made_progress:
            continue

        # Increase granularity
        if granularity < len(current_indices):
            new_gran = min(granularity * 2, len(current_indices))
            print(f"         -> 无进展，增大粒度至 {new_gran}\n")
            granularity = new_gran
        else:
            print("\n[Reduce] 已无法进一步缩减 —— 到达 1-minimal。")
            break

    reduced_seq = [original_seq[i] for i in current_indices]
    print(f"\n[Result] 缩减后序列为: {reduced_seq}")
    return reduced_seq

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] 输入文件不存在: {input_file}", file=sys.stderr)
        return

    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.strip() for line in f]

    if not lines:
        raise ValueError("输入文件为空")

    header = lines[0].split()
    if len(header) != 2:
        raise ValueError(f"第一行应包含 N 和 K: {lines[0]}")

    N_str, K_str = header
    if not N_str.isdigit() or not K_str.isdigit():
        raise ValueError(f"非数字的 N 或 K: {lines[0]}")

    N = int(N_str)
    K = int(K_str)

    if N <= K:
        raise ValueError(f"无效输入: K >= N")

    A_line = lines[1].split()
    if len(A_line) != N:
        raise ValueError(f"数组 A 长度不匹配: 期望 {N}, 实际 {len(A_line)}")

    A = list(map(int, A_line))

    reduced_seq = reduce_ddmin(A)

    M = len(reduced_seq)
    K_reduced = max(0, K - (N - M))  # Adjust K accordingly

    output_lines = [f"{M} {K_reduced}", " ".join(map(str, reduced_seq))]
    output_bytes = "\n".join(output_lines).encode("utf-8")

    with open(output_file, "wb") as f:
        f.write(output_bytes)

    print(f"[Info] 缩减过程完成，结果已写入: {output_file}")
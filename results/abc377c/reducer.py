import os
import subprocess
from typing import List, Tuple

def run_program(program_path: str, input_data: bytes) -> bytes:
    result = subprocess.run(
        [program_path],
        input=input_data,
        capture_output=True,
        check=True,
        timeout=10
    )
    return result.stdout

def create_input_bytes(N: int, pieces: List[Tuple[int, int]]) -> bytes:
    lines = [f"{N} {len(pieces)}"]
    for a, b in pieces:
        lines.append(f"{a} {b}")
    return "\n".join(lines).encode("utf-8")

def test_interesting(N: int, pieces: List[Tuple[int, int]]) -> bool:
    input_data = create_input_bytes(N, pieces)
    wa_out = run_program("./wa", input_data)
    ac_out = run_program("./ac", input_data)
    return wa_out.strip() != ac_out.strip()

def reduce_pieces(original_N: int, pieces: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    if not test_interesting(original_N, pieces):
        print("[Error] 初始输入未造成差异，无法缩减。", file=sys.stderr)
        return pieces

    current_indices = list(range(len(pieces)))
    granularity = 2

    while True:
        num_indices = len(current_indices)
        subset_size = max(1, num_indices // granularity)
        made_progress = False

        # Try removing a block
        start_idx = 0
        while start_idx < num_indices:
            block_start = start_idx
            block_end = start_idx + subset_size
            block = current_indices[block_start:block_end]
            candidate_indices = [i for i in current_indices if i not in block]
            if not candidate_indices:
                start_idx += subset_size
                continue
            candidate_pieces = [pieces[i] for i in candidate_indices]
            if test_interesting(original_N, candidate_pieces):
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            else:
                start_idx += subset_size
        if made_progress:
            continue

        # Try keeping only the block
        start_idx = 0
        while start_idx < num_indices:
            block_start = start_idx
            block_end = start_idx + subset_size
            block = current_indices[block_start:block_end]
            candidate_indices = block
            if not candidate_indices or len(candidate_indices) == num_indices:
                start_idx += subset_size
                continue
            candidate_pieces = [pieces[i] for i in candidate_indices]
            if test_interesting(original_N, candidate_pieces):
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            else:
                start_idx += subset_size
        if made_progress:
            continue

        # Increase granularity if no progress
        if granularity < num_indices:
            granularity *= 2
        else:
            break

    return [pieces[i] for i in current_indices]

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"Error: 输入文件不存在: {input_file}", file=sys.stderr)
        return

    with open(input_file, "r") as f:
        lines = [line.rstrip() for line in f]

    if not lines:
        raise ValueError("输入文件为空")

    first_line = lines[0].split()
    if len(first_line) != 2:
        raise ValueError("第一行格式错误，应包含N和M")

    N = int(first_line[0])
    M = int(first_line[1])
    if len(lines) != M + 1:
        raise ValueError(f"输入行数不匹配，期望{M+1}行，实际{len(lines)}行")

    pieces = []
    for line in lines[1:]:
        a, b = map(int, line.split())
        pieces.append((a, b))

    reduced_pieces = reduce_pieces(N, pieces)
    output_data = create_input_bytes(N, reduced_pieces)

    with open(output_file, "wb") as f:
        f.write(output_data)

    print(f"[Info] 缩减完成，剩余{len(reduced_pieces)}个棋子，已保存到{output_file}")
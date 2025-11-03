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
    line = " ".join(map(str, subsequence)) + "\n"
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
        print(f"[Error] Error occurred when executing the program: {e}")
        return False

def reduce_ddmin(original_seq: List[int]) -> List[int]:
    N = len(original_seq)
    current_indices = list(range(N))
    granularity = 2

    while len(current_indices) > 1:
        print(f"[Reduce] Current index set size={len(current_indices)}: {current_indices}")
        print(f"         Trying granularity: {granularity}")
        subset_size = max(1, len(current_indices) // granularity)
        made_progress = False

        # Try removing a block
        start_idx = 0
        print(f"         1) Try to 『remove』 a block of size about={subset_size} ...")
        while start_idx < len(current_indices):
            block = current_indices[start_idx:start_idx + subset_size]
            candidate = [x for x in current_indices if x not in block]
            if len(candidate) < 2:
                start_idx += subset_size
                continue
            subseq = [original_seq[i] for i in candidate]
            print(f"            - Remove indices {block} ... ", end="")
            if test_interesting(subseq):
                print(f"Success! New index set size={len(candidate)}")
                current_indices = candidate
                granularity = 2
                made_progress = True
                break
            else:
                print("Failed")
            start_idx += subset_size
        if made_progress:
            continue

        # Try keeping only a block
        start_idx = 0
        print(f"         2) Try to 『keep only』 a block of size about={subset_size} ...")
        while start_idx < len(current_indices):
            block = current_indices[start_idx:start_idx + subset_size]
            candidate = block
            if len(candidate) == len(current_indices) or len(candidate) < 2:
                start_idx += subset_size
                continue
            subseq = [original_seq[i] for i in candidate]
            print(f"            - Keep only indices {block} ... ", end="")
            if test_interesting(subseq):
                print(f"Success! New index set size={len(candidate)}")
                current_indices = candidate
                granularity = 2
                made_progress = True
                break
            else:
                print("Failed")
            start_idx += subset_size
        if made_progress:
            continue

        # Increase granularity
        if granularity < len(current_indices):
            new_gran = min(granularity * 2, len(current_indices))
            print(f"         -> No progress, increasing granularity to {new_gran}\n")
            granularity = new_gran
        else:
            print("\n[Reduce] Cannot reduce further — reached 1-minimal.")
            break

    reduced_seq = [original_seq[i] for i in current_indices]
    print(f"\n[Result] Reduced sequence: {reduced_seq}")
    return reduced_seq

def reduce_input(input_file: str, output_file: str):
    if not os.path.exists(input_file):
        print(f"[Error] Input file does not exist: {input_file}", file=sys.stderr)
        return

    with open(input_file, "r", encoding="utf-8") as f:
        lines = [line.strip() for line in f]

    if not lines:
        raise ValueError("Input file is empty")

    A = " ".join(lines)
    A = list(A.split(" "))

    reduced_seq = reduce_ddmin(A)

    output_bytes = create_input_bytes(reduced_seq)

    with open(output_file, "wb") as f:
        f.write(output_bytes)

    print(f"[Info] Reduction complete, result written to: {output_file}")

if __name__ == "__main__":
    reduce_input("11.in", "11.out")

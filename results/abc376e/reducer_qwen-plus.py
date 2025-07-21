import os
import subprocess
from typing import List, Tuple
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

def parse_input(input_file: str) -> List[Tuple[int, int, List[int], List[int]]]:
    with open(input_file, 'r') as f:
        lines = [line.strip() for line in f]
    if not lines:
        return []
    T = int(lines[0])
    test_cases = []
    idx = 1
    for _ in range(T):
        if idx >= len(lines):
            raise ValueError("Unexpected end of input")
        nk_line = lines[idx]
        idx += 1
        n, k = map(int, nk_line.split())
        a_line = lines[idx]
        idx += 1
        a = list(map(int, a_line.split()))
        if len(a) != n:
            raise ValueError(f"Invalid A array length for test case: {len(a)} vs N={n}")
        b_line = lines[idx]
        idx += 1
        b = list(map(int, b_line.split()))
        if len(b) != n:
            raise ValueError(f"Invalid B array length for test case: {len(b)} vs N={n}")
        test_cases.append((n, k, a, b))
    return test_cases

def generate_input_bytes(test_cases: List[Tuple[int, int, List[int], List[int]]]) -> bytes:
    lines = [str(len(test_cases))]
    for tc in test_cases:
        n, k, a, b = tc
        lines.append(f"{n} {k}")
        lines.append(' '.join(map(str, a)))
        lines.append(' '.join(map(str, b)))
    return '\n'.join(lines).encode('utf-8')

def test_interesting(test_cases: List[Tuple[int, int, List[int], List[int]]]) -> bool:
    if not test_cases:
        return False
    input_data = generate_input_bytes(test_cases)
    wa_out = run_program("./wa", input_data)
    ac_out = run_program("./ac", input_data)
    return wa_out.strip() != ac_out.strip()

def reduce_test_case_list(original_test_cases: List[Tuple[int, int, List[int], List[int]]]) -> List[Tuple[int, int, List[int], List[int]]]:
    if not test_interesting(original_test_cases):
        return original_test_cases
    current_indices = list(range(len(original_test_cases)))
    granularity = 2
    while True:
        n = len(current_indices)
        if n == 1:
            break
        subset_size = max(1, n // granularity)
        made_progress = False
        start_idx = 0
        while start_idx < n:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = [i for i in current_indices if i not in block]
            if len(candidate_indices) >= 1:
                sub_test_cases = [original_test_cases[i] for i in candidate_indices]
                if test_interesting(sub_test_cases):
                    current_indices = candidate_indices
                    granularity = 2
                    made_progress = True
                    break
            start_idx += subset_size
        if made_progress:
            continue
        start_idx = 0
        while start_idx < n:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = block
            if len(candidate_indices) == 0 or len(candidate_indices) == n:
                start_idx += subset_size
                continue
            sub_test_cases = [original_test_cases[i] for i in candidate_indices]
            if test_interesting(sub_test_cases):
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            start_idx += subset_size
        if made_progress:
            continue
        if granularity < n:
            granularity = min(granularity * 2, n)
        else:
            break
    return [original_test_cases[i] for i in current_indices]

def reduce_test_case(tc: Tuple[int, int, List[int], List[int]]) -> Tuple[int, int, List[int], List[int]]:
    n, k, a, b = tc
    if k > n:
        return tc
    if n == k:
        return tc
    current_indices = list(range(n))
    granularity = 2
    while True:
        m = len(current_indices)
        if m <= k:
            break
        subset_size = max(1, m // granularity)
        made_progress = False
        start_idx = 0
        while start_idx < m:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = [x for x in current_indices if x not in block]
            if len(candidate_indices) >= k:
                new_n = len(candidate_indices)
                new_a = [a[i] for i in candidate_indices]
                new_b = [b[i] for i in candidate_indices]
                new_tc = (new_n, k, new_a, new_b)
                temp_test = [new_tc]
                if test_interesting(temp_test):
                    current_indices = candidate_indices
                    granularity = 2
                    made_progress = True
                    break
            start_idx += subset_size
        if made_progress:
            continue
        start_idx = 0
        while start_idx < m:
            block = current_indices[start_idx:start_idx + subset_size]
            candidate_indices = block
            if len(candidate_indices) < k:
                start_idx += subset_size
                continue
            new_n = len(candidate_indices)
            new_a = [a[i] for i in candidate_indices]
            new_b = [b[i] for i in candidate_indices]
            new_tc = (new_n, k, new_a, new_b)
            temp_test = [new_tc]
            if test_interesting(temp_test):
                current_indices = candidate_indices
                granularity = 2
                made_progress = True
                break
            start_idx += subset_size
        if made_progress:
            continue
        if granularity < m:
            granularity *= 2
        else:
            break
    new_n = len(current_indices)
    new_a = [a[i] for i in current_indices]
    new_b = [b[i] for i in current_indices]
    return (new_n, k, new_a, new_b)

def reduce_input(input_file: str, output_file: str):
    test_cases = parse_input(input_file)
    if not test_interesting(test_cases):
        print(f"[Error] Input does not cause discrepancy between AC and WA.", file=sys.stderr)
        return
    reduced_test_cases = reduce_test_case_list(test_cases)
    final_test_cases = []
    for tc in reduced_test_cases:
        reduced_tc = reduce_test_case(tc)
        final_test_cases.append(reduced_tc)
    output_data = generate_input_bytes(final_test_cases)
    with open(output_file, 'wb') as f:
        f.write(output_data)
    print(f"[Info] Reduced input written to {output_file}")
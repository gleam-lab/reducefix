from typing import Callable, List
import time


TestFn = Callable[[bytes], bool]


def _partition_indices(n: int, granularity: int) -> List[range]:
    if n <= 0:
        return []
    chunk = max(1, n // granularity)
    parts = []
    start = 0
    while start < n:
        end = min(n, start + chunk)
        parts.append(range(start, end))
        start = end
    return parts


def ddmin_reduce(data: bytes, test_fn: TestFn, *, by_lines: bool = True, verbose: bool = True) -> bytes:
    """Classic ddmin algorithm on lines or byte-chunks.

    Args:
        data: original input
        test_fn: returns True iff the candidate still reproduces the bug
        by_lines: if True, split by lines; else operate on bytes (256-byte chunks)
        verbose: if True, print detailed progress information
    """
    if by_lines:
        units = data.splitlines(keepends=True)
        if not units:
            return data
        
        original_size = len(data)
        original_units = len(units)
        if verbose:
            print(f"[DDMin] Starting reduction (line-based)")
            print(f"[DDMin] Original: {original_units} lines, {original_size} bytes")
        
        granularity = 2
        iteration = 0
        test_count = 0
        start_time = time.time()
        
        while len(units) >= 1:
            n = len(units)
            made_progress = False
            iteration += 1
            
            if verbose:
                current_size = len(b"".join(units))
                elapsed = time.time() - start_time
                print(f"[DDMin] Iteration #{iteration}: {n} units, {current_size} bytes, "
                      f"granularity={granularity}, tests={test_count}, elapsed={elapsed:.1f}s")
            
            # Phase 1: try removing subsets (deletion)
            for part in _partition_indices(n, granularity):
                candidate = units[: part.start] + units[part.stop :]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] Tested {test_count} candidates...")
                
                if test_fn(candidate_bytes):
                    removed = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ Deletion succeeded: removed {removed} units "
                              f"({n} → {len(candidate)}), {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if made_progress:
                continue
            
            # Phase 2: try keeping subsets (retention)
            for part in _partition_indices(n, granularity):
                candidate = units[part.start : part.stop]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                # Avoid infinite loops: skip if the subset is the entire input
                if part.start == 0 and part.stop == n:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] Tested {test_count} candidates...")
                
                if test_fn(candidate_bytes):
                    kept = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ Retention succeeded: kept {kept}/{n} units, {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if not made_progress:
                if granularity >= n:
                    if verbose:
                        print(f"  [DDMin] Granularity {granularity} >= unit count {n}, stopping")
                    break
                granularity = min(n, granularity * 2)
                if verbose:
                    print(f"  [DDMin] No progress, increasing granularity: {granularity//2} → {granularity}")
        
        final_size = len(b"".join(units))
        reduction = (1 - final_size / original_size) * 100
        elapsed = time.time() - start_time
        
        if verbose:
            print(f"[DDMin] Finished: {original_units} lines → {len(units)} lines")
            print(f"[DDMin] Size: {original_size} → {final_size} bytes ({reduction:.1f}% reduction)")
            print(f"[DDMin] Total tests: {test_count}, total time: {elapsed:.1f}s")
        
        return b"".join(units)
    else:
        # Chunk-based ddmin for binary-like data
        chunk_size = 256
        units = [data[i : i + chunk_size] for i in range(0, len(data), chunk_size)]
        if not units:
            return data
        
        original_size = len(data)
        original_units = len(units)
        if verbose:
            print(f"[DDMin] Starting reduction (chunk-based, chunk size={chunk_size} bytes)")
            print(f"[DDMin] Original: {original_units} chunks, {original_size} bytes")
        
        granularity = 2
        iteration = 0
        test_count = 0
        start_time = time.time()
        
        while len(units) >= 1:
            n = len(units)
            made_progress = False
            iteration += 1
            
            if verbose:
                current_size = len(b"".join(units))
                elapsed = time.time() - start_time
                print(f"[DDMin] Iteration #{iteration}: {n} units, {current_size} bytes, "
                      f"granularity={granularity}, tests={test_count}, elapsed={elapsed:.1f}s")
            
            # Phase 1: try removing subsets (deletion)
            for part in _partition_indices(n, granularity):
                candidate = units[: part.start] + units[part.stop :]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] Tested {test_count} candidates...")
                
                if test_fn(candidate_bytes):
                    removed = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ Deletion succeeded: removed {removed} units "
                              f"({n} → {len(candidate)}), {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if made_progress:
                continue
            
            # Phase 2: try keeping subsets (retention)
            for part in _partition_indices(n, granularity):
                candidate = units[part.start : part.stop]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                # Avoid infinite loops: skip if the subset is the entire input
                if part.start == 0 and part.stop == n:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] Tested {test_count} candidates...")
                
                if test_fn(candidate_bytes):
                    kept = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ Retention succeeded: kept {kept}/{n} units, {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if not made_progress:
                if granularity >= n:
                    if verbose:
                        print(f"  [DDMin] Granularity {granularity} >= unit count {n}, stopping")
                    break
                granularity = min(n, granularity * 2)
                if verbose:
                    print(f"  [DDMin] No progress, increasing granularity: {granularity//2} → {granularity}")
        
        final_size = len(b"".join(units))
        reduction = (1 - final_size / original_size) * 100
        elapsed = time.time() - start_time
        
        if verbose:
            print(f"[DDMin] Finished: {original_units} chunks → {len(units)} chunks")
            print(f"[DDMin] Size: {original_size} → {final_size} bytes ({reduction:.1f}% reduction)")
            print(f"[DDMin] Total tests: {test_count}, total time: {elapsed:.1f}s")
        
        return b"".join(units)



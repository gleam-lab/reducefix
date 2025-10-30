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
            print(f"[DDMin] 开始缩减（基于行）")
            print(f"[DDMin] 原始: {original_units} 行, {original_size} bytes")
        
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
                print(f"[DDMin] 迭代 #{iteration}: {n} 单位, {current_size} bytes, "
                      f"粒度={granularity}, 测试数={test_count}, 耗时={elapsed:.1f}s")
            
            # Phase 1: 尝试删除子集（减法）
            for part in _partition_indices(n, granularity):
                candidate = units[: part.start] + units[part.stop :]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] 已测试 {test_count} 个候选...")
                
                if test_fn(candidate_bytes):
                    removed = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ 减法成功: 删除 {removed} 单位 "
                              f"({n} → {len(candidate)}), {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if made_progress:
                continue
            
            # Phase 2: 尝试仅保留子集（保留）
            for part in _partition_indices(n, granularity):
                candidate = units[part.start : part.stop]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                # 避免无限循环：如果保留的就是全部，跳过
                if part.start == 0 and part.stop == n:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] 已测试 {test_count} 个候选...")
                
                if test_fn(candidate_bytes):
                    kept = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ 保留成功: 保留 {kept}/{n} 单位, {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if not made_progress:
                if granularity >= n:
                    if verbose:
                        print(f"  [DDMin] 粒度 {granularity} >= 单位数 {n}，算法结束")
                    break
                granularity = min(n, granularity * 2)
                if verbose:
                    print(f"  [DDMin] 无进展，增加粒度: {granularity//2} → {granularity}")
        
        final_size = len(b"".join(units))
        reduction = (1 - final_size / original_size) * 100
        elapsed = time.time() - start_time
        
        if verbose:
            print(f"[DDMin] 完成: {original_units} 行 → {len(units)} 行")
            print(f"[DDMin] 大小: {original_size} → {final_size} bytes ({reduction:.1f}% 缩减)")
            print(f"[DDMin] 总测试数: {test_count}, 总耗时: {elapsed:.1f}s")
        
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
            print(f"[DDMin] 开始缩减（基于块, 块大小={chunk_size}bytes）")
            print(f"[DDMin] 原始: {original_units} 块, {original_size} bytes")
        
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
                print(f"[DDMin] 迭代 #{iteration}: {n} 单位, {current_size} bytes, "
                      f"粒度={granularity}, 测试数={test_count}, 耗时={elapsed:.1f}s")
            
            # Phase 1: 尝试删除子集（减法）
            for part in _partition_indices(n, granularity):
                candidate = units[: part.start] + units[part.stop :]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] 已测试 {test_count} 个候选...")
                
                if test_fn(candidate_bytes):
                    removed = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ 减法成功: 删除 {removed} 单位 "
                              f"({n} → {len(candidate)}), {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if made_progress:
                continue
            
            # Phase 2: 尝试仅保留子集（保留）
            for part in _partition_indices(n, granularity):
                candidate = units[part.start : part.stop]
                candidate_bytes = b"".join(candidate)
                if not candidate_bytes:
                    continue
                
                # 避免无限循环：如果保留的就是全部，跳过
                if part.start == 0 and part.stop == n:
                    continue
                
                test_count += 1
                if verbose and test_count % 10 == 0:
                    print(f"  [DDMin] 已测试 {test_count} 个候选...")
                
                if test_fn(candidate_bytes):
                    kept = part.stop - part.start
                    new_size = len(candidate_bytes)
                    if verbose:
                        print(f"  [DDMin] ✓ 保留成功: 保留 {kept}/{n} 单位, {new_size} bytes")
                    units = candidate
                    granularity = 2
                    made_progress = True
                    break
            
            if not made_progress:
                if granularity >= n:
                    if verbose:
                        print(f"  [DDMin] 粒度 {granularity} >= 单位数 {n}，算法结束")
                    break
                granularity = min(n, granularity * 2)
                if verbose:
                    print(f"  [DDMin] 无进展，增加粒度: {granularity//2} → {granularity}")
        
        final_size = len(b"".join(units))
        reduction = (1 - final_size / original_size) * 100
        elapsed = time.time() - start_time
        
        if verbose:
            print(f"[DDMin] 完成: {original_units} 块 → {len(units)} 块")
            print(f"[DDMin] 大小: {original_size} → {final_size} bytes ({reduction:.1f}% 缩减)")
            print(f"[DDMin] 总测试数: {test_count}, 总耗时: {elapsed:.1f}s")
        
        return b"".join(units)



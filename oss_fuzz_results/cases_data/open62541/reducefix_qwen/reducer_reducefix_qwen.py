def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    Format-aware test case reducer for open62541
    Handles small structured binary messages (mDNS, OPC UA) with high padding content.
    Uses byte-level DDMin as primary strategy due to small file size and binary structure.
    """
    import time

    if verbose:
        print(f"[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {len(input_bytes)} bytes")

    start_time = time.time()
    total_tests = 0
    current = input_bytes

    def _test(candidate: bytes) -> bool:
        nonlocal total_tests
        total_tests += 1
        return test_fn(candidate)

    # Stage 1: Truncation test - many parser bugs are size-dependent
    if len(current) > 1 and verbose:
        print("[ReduceFix] Stage 1: Testing message truncation (common in parser bugs)")
    truncated = False
    for i in range(len(current), 0, -1):
        candidate = current[:i]
        if len(candidate) < len(current) and _test(candidate):
            current = candidate
            truncated = True
            break
    if truncated and verbose:
        print(f"  [ReduceFix] ✓ Truncation successful: reduced to {len(current)} bytes")
    elif verbose:
        print(f"  [ReduceFix] → Truncation failed, proceeding")

    # Stage 2: Remove trailing padding (0x00, 0x20, 0xFF)
    if len(current) > 1 and verbose:
        print("[ReduceFix] Stage 2: Removing trailing padding bytes (0x00, 0x20, 0xFF)")
    orig_len = len(current)
    padding_bytes = {0x00, 0x20, 0xFF}
    stripped = current.rstrip(bytes([b for b in padding_bytes]))
    if len(stripped) < len(current) and _test(stripped):
        current = stripped
    if verbose:
        reduction = orig_len - len(current)
        if reduction > 0:
            print(f"  [ReduceFix] ✓ Removed {reduction} trailing padding bytes")
        else:
            print(f"  [ReduceFix] → No reducible trailing padding")

    # Stage 3: Byte-level DDMin (most effective for small binary messages)
    if len(current) <= 1:
        if verbose:
            print(f"[ReduceFix] Complete: final size {len(current)} bytes")
            print(f"[ReduceFix] Total tests: {total_tests}, total time: {time.time() - start_time:.1f}s")
        return current

    if verbose:
        print("[ReduceFix] Stage 3: Byte-level DDMin (fine-grained removal)")

    progress_interval = max(1, len(current) // 10)
    n = len(current)
    changed = True
    while changed and n > 1:
        changed = False
        i = 0
        while i < n:
            # Try removing one byte
            candidate = current[:i] + current[i+1:]
            if _test(candidate):
                current = candidate
                n = len(current)
                changed = True
                if verbose and total_tests % progress_interval == 0:
                    elapsed = time.time() - start_time
                    print(f"  [ReduceFix] Tested {total_tests} candidates, current: {len(current)} bytes, elapsed={elapsed:.1f}s")
                if n == 1:
                    break
            else:
                i += 1

    # Stage 4: Replace internal padding runs (>=4 consecutive 0x00/0x20/0xFF) with single byte
    if verbose:
        print("[ReduceFix] Stage 4: Compressing internal padding sequences")

    def compress_padding(data: bytes) -> bytes:
        if len(data) < 4:
            return data
        result = bytearray()
        i = 0
        padding_bytes = {0x00, 0x20, 0xFF}
        while i < len(data):
            if data[i] in padding_bytes:
                # Measure run length
                run_start = i
                while i < len(data) and data[i] in padding_bytes:
                    i += 1
                run_len = i - run_start
                if run_len >= 4:
                    # Replace long padding runs with single byte
                    result.append(data[run_start])
                else:
                    result.extend(data[run_start:i])
            else:
                result.append(data[i])
                i += 1
        return bytes(result)

    compressed = compress_padding(current)
    if len(compressed) < len(current) and _test(compressed):
        current = compressed
        if verbose:
            print(f"  [ReduceFix] ✓ Compressed internal padding, new size: {len(current)} bytes")

    # Final validation and output
    final_size = len(current)
    original_size = len(input_bytes)
    reduction_rate = (1 - final_size / original_size) * 100 if original_size > 0 else 0
    elapsed_time = time.time() - start_time

    if verbose:
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({reduction_rate:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {total_tests}, total time: {elapsed_time:.1f}s")

    return current
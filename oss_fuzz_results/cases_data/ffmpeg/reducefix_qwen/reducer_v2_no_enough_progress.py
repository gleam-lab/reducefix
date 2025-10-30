def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    Format-aware test case reducer for ffmpeg
    Handles diverse media formats with aggressive DDMin strategy optimized for fuzzer-generated inputs.
    """
    import time

    if verbose:
        print(f"[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {len(input_bytes)} bytes")

    start_time = time.time()
    test_count = 0

    # Stage 1: Quick pruning of fuzzer signatures and padding
    def remove_fuzzer_trailers(data: bytes) -> bytes:
        nonlocal test_count
        candidates = [
            b'UZZ-T', b'FUZZ', b'UZZG',
            b'OSS-Fuzz', b'ClusterFuzz', b'libFuzzer'
        ]
        for sig in candidates:
            pos = data.rfind(sig)
            if pos != -1 and pos > len(data) * 0.8:  # Only if in last 20%
                for extra in [32, 16, 8, 4]:
                    end_pos = min(pos + len(sig) + extra, len(data))
                    candidate = data[:pos]
                    if len(candidate) > 0 and test_fn(candidate):
                        test_count += 1
                        if verbose:
                            print(f"  [ReduceFix] Removed fuzzer trailer '{sig.decode('latin1', errors='ignore')}' at {pos}")
                        return candidate
        return data

    current = input_bytes
    if len(current) > 0 and test_fn(current):
        temp = remove_fuzzer_trailers(current)
        if len(temp) < len(current):
            current = temp
            if verbose:
                print(f"  [ReduceFix] ✓ Removed fuzzer signature, size: {len(current)} bytes")
    else:
        if verbose:
            print("[ReduceFix] Initial input fails test, returning original")
        return input_bytes

    # Stage 2: Remove long runs of repetitive bytes (common in fuzzer inputs)
    def remove_repetitive_runs(data: bytes) -> bytes:
        nonlocal test_count
        changed = True
        result = data
        while changed:
            changed = False
            i = 0
            while i < len(result) - 16:
                byte_val = result[i]
                run_len = 1
                while i + run_len < len(result) and result[i + run_len] == byte_val and run_len < 1000:
                    run_len += 1
                
                if run_len >= 16:  # Long padding run
                    # Try truncating the run
                    for keep_len in [8, 4, 2, 1]:
                        if run_len > keep_len:
                            candidate = result[:i + keep_len] + result[i + run_len:]
                            if len(candidate) > 0 and test_fn(candidate):
                                test_count += 1
                                result = candidate
                                changed = True
                                if verbose:
                                    print(f"  [ReduceFix] Shortened byte run (0x{byte_val:02x}) from {run_len} to {keep_len}")
                                break
                    if changed:
                        break
                i += 1
        return result

    before_size = len(current)
    current = remove_repetitive_runs(current)
    after_size = len(current)
    if verbose and after_size < before_size:
        print(f"[ReduceFix] Stage 1 complete: {before_size} → {after_size} bytes ({100*(before_size-after_size)/before_size:.1f}% reduction)")

    # Stage 3: Adaptive DDMin with decreasing chunk sizes based on file size
    def ddmin_pass(data: bytes, chunk_size: int) -> bytes:
        nonlocal test_count
        if len(data) <= chunk_size:
            return data
        
        current_data = data
        progress_made = True
        while progress_made:
            progress_made = False
            i = 0
            while i < len(current_data):
                chunk_start = i
                chunk_end = min(i + chunk_size, len(current_data))
                
                candidate = current_data[:chunk_start] + current_data[chunk_end:]
                if len(candidate) > 0 and test_fn(candidate):
                    current_data = candidate
                    test_count += 1
                    progress_made = True
                    # Don't advance i - recheck same position
                    if test_count % 25 == 0 and verbose:
                        elapsed = time.time() - start_time
                        print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(current_data)} bytes, elapsed={elapsed:.1f}s")
                else:
                    i += chunk_size
                
                if len(current_data) == 0:
                    break
                    
        return current_data

    # Determine chunk size strategy based on input size
    file_size = len(current)
    if file_size <= 1024:
        chunk_sizes = [32, 16, 8, 4, 2, 1]
    elif file_size <= 5120:
        chunk_sizes = [128, 64, 32, 16, 8, 4, 2, 1]
    elif file_size <= 20480:
        chunk_sizes = [512, 256, 128, 64, 32, 16, 8]
    else:
        chunk_sizes = [2048, 1024, 512, 256, 128, 64, 32]

    if verbose:
        print(f"[ReduceFix] Stage 2: Adaptive DDMin reduction")
        print(f"  [ReduceFix] Using chunk sizes: {chunk_sizes}")

    initial_size_stage2 = len(current)
    for idx, chunk_size in enumerate(chunk_sizes):
        before = len(current)
        current = ddmin_pass(current, chunk_size)
        after = len(current)
        reduction = (before - after) / before * 100 if before > 0 else 0
        if verbose and after < before:
            print(f"  [ReduceFix] ✓ Chunk size {chunk_size}: {before} → {after} bytes ({reduction:.1f}% reduction)")

    if verbose:
        stage2_reduction = initial_size_stage2 - len(current)
        reduction_rate = 100 * stage2_reduction / initial_size_stage2 if initial_size_stage2 > 0 else 0
        print(f"[ReduceFix] Stage 2 complete: {initial_size_stage2} → {len(current)} bytes ({reduction_rate:.1f}% reduction)")

    # Stage 4: Final byte-level simplification (replace with simpler bytes where possible)
    def simplify_bytes(data: bytes) -> bytes:
        nonlocal test_count
        if len(data) == 0:
            return data
            
        result = bytearray(data)
        simplified_any = True
        while simplified_any and len(result) > 1:
            simplified_any = False
            i = 0
            while i < len(result):
                orig_byte = result[i]
                # Try replacing with common neutral bytes
                for replacement in [0x00, 0x20, 0xFF]:
                    if result[i] != replacement:
                        result[i] = replacement
                        candidate = bytes(result)
                        if test_fn(candidate):
                            test_count += 1
                            simplified_any = True
                            if verbose and test_count % 50 == 0:
                                elapsed = time.time() - start_time
                                print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(candidate)} bytes, elapsed={elapsed:.1f}s")
                            break
                        else:
                            result[i] = orig_byte
                    i += 1
                if simplified_any:
                    break
        return bytes(result)

    if len(current) > 1:
        before_simplify = len(current)
        current = simplify_bytes(current)
        after_simplify = len(current)
        if verbose and after_simplify < before_simplify:
            simplify_reduction = (before_simplify - after_simplify) / before_simplify * 100
            print(f"[ReduceFix] Stage 3 complete: {before_simplify} → {after_simplify} bytes ({simplify_reduction:.1f}% reduction)")

    final_size = len(current)
    original_size = len(input_bytes)
    total_reduction = (original_size - final_size) / original_size * 100 if original_size > 0 else 0
    total_time = time.time() - start_time

    if verbose:
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({total_reduction:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")

    return current
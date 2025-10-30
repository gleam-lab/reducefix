def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    Format-aware test case reducer for ffmpeg
    Handles fuzzer-generated binary inputs with repeated patterns and signatures.
    Uses aggressive DDMin with adaptive chunk sizing based on file size.
    """
    import time

    start_time = time.time()
    test_count = 0
    current = input_bytes

    if verbose:
        print("[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {len(current)} bytes")

    # Stage 1: Remove fuzzer signatures and trailing padding
    if verbose:
        print("[ReduceFix] Stage 1: Remove fuzzer signatures and trailing padding")
        print(f"  Starting size: {len(current)} bytes")

    # Common fuzzer markers
    signatures = [b'UZZ-T', b'UZZG', b'FUZZ']
    sig_found = False

    # Try removing from the end (most common location)
    for sig in signatures:
        pos = current.rfind(sig)
        if pos != -1 and pos > len(current) * 0.8:  # Only if in last 20%
            # Also remove surrounding padding (common: runs of 0x60, 0x20, 0xFF)
            # Extend backward to include repeated bytes
            trim_pos = pos
            while trim_pos > 0 and current[trim_pos - 1] in [0x60, 0x20, 0xFF]:
                trim_pos -= 1
            candidate = current[:trim_pos]
            if len(candidate) > 0:
                test_count += 1
                if test_fn(candidate):
                    current = candidate
                    sig_found = True
                    if verbose:
                        print(f"  [ReduceFix] ✓ Removed signature '{sig.decode()}' and padding at offset {pos}")
                    break

    if not sig_found and verbose:
        print("  [ReduceFix] No fuzzer signatures found or removal failed")

    if verbose:
        print(f"[ReduceFix] Stage 1 complete: {len(input_bytes)} → {len(current)} bytes ({(len(input_bytes)-len(current))/len(input_bytes)*100:.1f}% reduction)")

    # Stage 2: Strip long runs of repeated padding bytes from tail
    if verbose:
        print("[ReduceFix] Stage 2: Trim trailing repeated bytes")
        print(f"  Starting size: {len(current)} bytes")

    before_stage2 = len(current)
    padding_bytes = [0x60, 0x20, 0xFF, 0x00]
    i = len(current) - 1
    run_length = 0
    last_byte = None

    # Count trailing run of padding byte
    while i >= 0:
        if current[i] in padding_bytes and (last_byte is None or current[i] == last_byte):
            run_length += 1
            last_byte = current[i]
        else:
            break
        i -= 1

    if run_length > 16:  # Long run likely safe to reduce
        for trim_len in range(run_length - 1, 15, -1):  # Try reducing to 16 or less
            candidate = current[:-trim_len]
            if len(candidate) == 0:
                continue
            test_count += 1
            if test_fn(candidate):
                current = candidate
                if verbose:
                    print(f"  [ReduceFix] ✓ Trimmed {trim_len} trailing repeated bytes (0x{last_byte:02x})")
                break

    if verbose:
        print(f"[ReduceFix] Stage 2 complete: {before_stage2} → {len(current)} bytes ({(before_stage2-len(current))/before_stage2*100:.1f}% reduction)")

    # Stage 3: DDMin with adaptive chunk sizing
    if verbose:
        print("[ReduceFix] Stage 3: Adaptive DDMin reduction")
        print(f"  Starting size: {len(current)} bytes")

    def ddmin_pass(data: bytes, chunk_size: int) -> bytes:
        nonlocal test_count
        if len(data) <= chunk_size:
            return data

        result = data
        i = 0
        while i < len(result):
            start = i
            end = min(i + chunk_size, len(result))
            candidate = result[:start] + result[end:]
            
            if len(candidate) == 0:
                i += chunk_size
                continue
                
            test_count += 1
            if test_fn(candidate):
                result = candidate
                # Do not increment i, recheck same position with new data
            else:
                i += chunk_size
                
            # Progress output
            if verbose and test_count % 100 == 0:
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Progress: {test_count} tests, {len(result)} bytes, {elapsed:.1f}s")
                
        return result

    # Determine chunk sizes based on current file size
    size = len(current)
    if size <= 1024:
        chunk_sizes = [32, 16, 8, 4, 2, 1]
    elif size <= 5 * 1024:
        chunk_sizes = [128, 64, 32, 16, 8, 4, 2, 1]
    elif size <= 20 * 1024:
        chunk_sizes = [512, 256, 128, 64, 32, 16, 8, 4, 1]
    else:
        chunk_sizes = [2048, 1024, 512, 256, 128, 64, 32, 16, 8]

    if verbose:
        print(f"  [ReduceFix] Chunk sizes: {chunk_sizes}")

    for chunk_size in chunk_sizes:
        before_chunk = len(current)
        changed = True
        pass_num = 0
        
        while changed:
            pass_num += 1
            prev_len = len(current)
            current = ddmin_pass(current, chunk_size)
            changed = len(current) < prev_len
            
            # Avoid infinite loops
            if pass_num > 10:
                break
                
        after_chunk = len(current)
        reduction = (before_chunk - after_chunk) / before_chunk * 100 if before_chunk > 0 else 0
        
        if verbose:
            action = "→" if after_chunk < before_chunk else "→ (no change)"
            print(f"  [ReduceFix] Chunk {chunk_size}: {before_chunk} {action} {after_chunk} bytes ({reduction:.1f}% reduction)")

    # Final validation
    if len(current) == 0:
        # If we removed everything, fallback to original
        if test_fn(input_bytes):
            current = input_bytes
        else:
            # Try single-byte version if nothing works
            current = b'\x00'

    # Final progress
    final_size = len(current)
    original_size = len(input_bytes)
    reduction_rate = (original_size - final_size) / original_size * 100
    total_time = time.time() - start_time

    if verbose:
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({reduction_rate:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")

    return current
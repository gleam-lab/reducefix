def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    Format-aware test case reducer for imagemagick
    Handles various image formats (PNG, JPEG, GIF, TIFF, etc.) with structured reduction.
    """
    import time
    start_time = time.time()
    original_size = len(input_bytes)
    
    if verbose:
        print(f"[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {original_size} bytes")

    # Preserve file signature (first 8-16 bytes) which identifies the format
    # Most image formats have magic bytes at start
    sig_size = min(16, len(input_bytes))
    file_signature = input_bytes[:sig_size]
    
    # If file is small, just return after testing
    if original_size <= 32:
        if test_fn(input_bytes):
            if verbose:
                print(f"[ReduceFix] Input already minimal: {original_size} bytes")
                print(f"[ReduceFix] Complete: {original_size} → {original_size} bytes (0.0% reduction)")
                print(f"[ReduceFix] Total tests: 1, total time: {time.time() - start_time:.1f}s")
            return input_bytes
        return b""

    current = input_bytes
    test_count = 0

    # Stage 1: Remove large trailing blocks (common in TIFF, PNG, etc.)
    # Many image formats store metadata or auxiliary data at end
    if verbose:
        print(f"[ReduceFix] Stage 1: Trimming trailing blocks")

    candidate = current
    block_size = 256
    progress_interval = 10
    tested_in_stage = 0
    
    # Try removing trailing blocks in decreasing sizes
    for bs in [512, 256, 128, 64, 32, 16]:
        if len(candidate) <= sig_size + bs:
            continue
            
        # Try trimming from the end
        while len(candidate) > sig_size + bs:
            # Keep signature + some middle part
            new_candidate = candidate[:sig_size] + candidate[sig_size:-bs]
            if len(new_candidate) == len(candidate):
                break  # No reduction possible
            
            if test_fn(new_candidate):
                candidate = new_candidate
                test_count += 1
                tested_in_stage += 1
                if verbose and tested_in_stage % progress_interval == 0:
                    elapsed = time.time() - start_time
                    temp = f"{tested_in_stage} candidates"
                    print(f"  [ReduceFix] Tested {temp}, current: {len(candidate)} bytes, elapsed={elapsed:.1f}s")
            else:
                test_count += 1
                break  # Can't reduce further with this block size
    
    if len(candidate) < len(current):
        reduction = (original_size - len(candidate)) / original_size * 100
        if verbose:
            print(f"  [ReduceFix] ✓ Reduced from {len(current)} to {len(candidate)} bytes")
        current = candidate
    stage1_size = len(current)

    # Stage 2: Attempt to reduce internal structure by removing nulls and padding
    # Many image formats use padding or contain null-separated metadata
    if verbose:
        print(f"[ReduceFix] Stage 2: Reducing internal padding and null blocks")

    # Replace large null blocks with smaller ones
    candidate = current
    tested_in_stage = 0
    
    # Find long sequences of null bytes and reduce them
    import re
    null_blocks = list(re.finditer(b'\x00{4,}', candidate))
    for match in reversed(null_blocks):  # reverse to not mess up indices
        start, end = match.span()
        # Try reducing to 2 nulls
        reduced = candidate[:start+2] + candidate[end:]
        if test_fn(reduced):
            candidate = reduced
            test_count += 1
            tested_in_stage += 1
            if verbose and tested_in_stage % 10 == 0:
                elapsed = time.time() - start_time
                temp = f"{tested_in_stage} candidates"
                print(f"  [ReduceFix] Tested {temp}, current: {len(candidate)} bytes, elapsed={elapsed:.1f}s")
        else:
            test_count += 1
    
    if len(candidate) < len(current):
        if verbose:
            print(f"  [ReduceFix] ✓ Reduced null padding, new size: {len(candidate)} bytes")
        current = candidate

    # Stage 3: Line-oriented reduction (if file has line structure)
    # Some image metadata (TIFF, EXIF) may be line-structured
    if b'\n' in current and current.count(b'\n') >= 4:
        if verbose:
            print(f"[ReduceFix] Stage 3: Line-based reduction")

        lines = current.split(b'\n')
        candidate_lines = lines[:]
        tested_in_stage = 0
        
        # First pass: remove non-header/footer lines
        preserved_indices = set()
        preserved_indices.add(0)  # keep first line (header)
        if len(lines) > 1:
            preserved_indices.add(len(lines)-1)  # keep last line
        
        # Try removing middle lines
        i = 1
        while i < len(candidate_lines) - 1:
            if i in preserved_indices:
                i += 1
                continue
                
            # Try removing line i
            test_lines = candidate_lines[:i] + candidate_lines[i+1:]
            test_data = b'\n'.join(test_lines)
            if len(test_data) == 0:
                i += 1
                continue
                
            if test_fn(test_data):
                candidate_lines = test_lines
                test_count += 1
                tested_in_stage += 1
                if verbose and tested_in_stage % 20 == 0:
                    elapsed = time.time() - start_time
                    temp = f"{tested_in_stage} candidates"
                    print(f"  [ReduceFix] Tested {temp}, current: {len(candidate_lines)} lines, {len(b''.join(test_lines))} bytes, elapsed={elapsed:.1f}s")
            else:
                test_count += 1
                i += 1
        
        final_from_lines = b'\n'.join(candidate_lines)
        if len(final_from_lines) < len(current) and test_fn(final_from_lines):
            current = final_from_lines
            if verbose:
                print(f"  [ReduceFix] ✓ Applied line reduction: {len(current)} bytes")

    # Stage 4: Fine-grained byte-level reduction near the end
    # Focus on trailing bytes which often contain less critical data
    if verbose:
        print(f"[ReduceFix] Stage 4: Fine-grained trailing byte reduction")

    candidate = current
    tested_in_stage = 0
    window = 1  # Reduce one byte at a time from end
    
    while len(candidate) > sig_size:
        if len(candidate) <= sig_size + window:
            break
            
        # Try removing last 'window' bytes
        new_candidate = candidate[:-window]
        if len(new_candidate) == 0:
            break
            
        if test_fn(new_candidate):
            candidate = new_candidate
            test_count += 1
            tested_in_stage += 1
            if verbose and tested_in_stage % 50 == 0:
                elapsed = time.time() - start_time
                temp = f"{tested_in_stage} candidates"
                print(f"  [ReduceFix] Tested {temp}, current: {len(candidate)} bytes, elapsed={elapsed:.1f}s")
        else:
            test_count += 1
            if window == 1:
                break  # Can't reduce further
            else:
                window = 1  # Drop to single-byte mode
    
    if len(candidate) < len(current):
        if verbose:
            print(f"  [ReduceFix] ✓ Fine reduction complete: {len(candidate)} bytes")
        current = candidate

    # Final validation
    if not test_fn(current):
        # Fallback: return original if we broke it (should not happen)
        if verbose:
            print(f"[ReduceFix] Warning: Final candidate failed test! Returning minimal working version.")
        current = input_bytes if test_fn(input_bytes) else b""

    final_size = len(current)
    total_time = time.time() - start_time
    reduction_rate = (original_size - final_size) / original_size * 100 if original_size > 0 else 0

    if verbose:
        if 'stage1_size' in locals():
            stage1_reduction = (original_size - stage1_size) / original_size * 100
            print(f"[ReduceFix] Stage 1 complete: {original_size} → {stage1_size} bytes ({stage1_reduction:.1f}% reduction)")
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({reduction_rate:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")

    return current
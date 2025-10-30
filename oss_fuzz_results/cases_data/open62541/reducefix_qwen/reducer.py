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

    # Stage 1: Strategic binary search deletion (smarter than exhaustive)
    if len(current) > 1 and verbose:
        print("[ReduceFix] Stage 1: Binary search deletion")
    
    # Try progressively smaller deletion sizes
    for del_size in [32, 16, 8, 4, 2, 1]:
        if del_size >= len(current):
            continue
        
        changed = True
        while changed and len(current) > del_size:
            changed = False
            
            # Binary search for deletable region
            left, right = 0, len(current) - del_size
            while left <= right:
                mid = (left + right) // 2
                candidate = current[:mid] + current[mid + del_size:]
                
                if _test(candidate):
                    current = candidate
                    changed = True
                    if verbose:
                        print(f"  [ReduceFix] ✓ Deleted {del_size} bytes at offset {mid}")
                    break
                else:
                    # Try next position
                    left = mid + 1
                    if left <= right:
                        mid2 = (left + right) // 2
                        if mid2 != mid:
                            candidate2 = current[:mid2] + current[mid2 + del_size:]
                            if _test(candidate2):
                                current = candidate2
                                changed = True
                                if verbose:
                                    print(f"  [ReduceFix] ✓ Deleted {del_size} bytes at offset {mid2}")
                                break
                    right = mid - 1
            
            if verbose and total_tests % 50 == 0:
                print(f"  [ReduceFix] Progress: {total_tests} tests, current size: {len(current)} bytes")
    
    if len(current) < len(input_bytes) and verbose:
        reduction = len(input_bytes) - len(current)
        print(f"  [ReduceFix] ✓ Stage 1: {len(input_bytes)} → {len(current)} bytes ({reduction} bytes removed)")
    elif verbose:
        print(f"  [ReduceFix] → Stage 1: no deletion found")

    # Stage 2: Binary search truncation with header fix (much faster)
    if len(current) > 10 and verbose:
        print("[ReduceFix] Stage 2: Binary search truncation with header fix")
    
    # Binary search for minimal size
    left, right = max(10, len(current) // 2), len(current) - 1
    best_size = len(current)
    
    while left <= right:
        mid = (left + right) // 2
        truncated = current[:mid]
        
        # Try simple truncation first
        if _test(truncated):
            best_size = mid
            current = truncated
            right = mid - 1
            if verbose:
                print(f"  [ReduceFix] ✓ Truncate to {mid} bytes works!")
            continue
        
        # Try with length field adjustment at known positions
        found = False
        for length_pos in [4, 5, 6, 7]:
            if length_pos >= len(truncated):
                continue
            
            # Try single-byte length
            c = bytearray(truncated)
            c[length_pos] = mid & 0xFF
            if _test(bytes(c)):
                best_size = mid
                current = bytes(c)
                found = True
                if verbose:
                    print(f"  [ReduceFix] ✓ Truncate to {mid} bytes with length[{length_pos}]={mid}")
                break
        
        if found:
            right = mid - 1
        else:
            left = mid + 1
        
        if verbose and total_tests % 50 == 0:
            print(f"  [ReduceFix] Progress: {total_tests} tests, trying size {mid}")
    
    if best_size < len(input_bytes) and verbose:
        print(f"  [ReduceFix] ✓ Stage 2: {len(input_bytes)} → {best_size} bytes")
    elif verbose:
        print(f"  [ReduceFix] → Stage 2: no truncation found")
    
    # Stage 3: Remove trailing padding (0x00, 0x20, 0xFF)
    if len(current) > 1 and verbose:
        print("[ReduceFix] Stage 3: Removing trailing padding bytes")
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

    # Stage 4: Byte value simplification (replace bytes with 0x00) - for content reduction
    if len(current) > 1 and verbose:
        print("[ReduceFix] Stage 4: Byte value simplification (zero-filling)")
    
    # Try large blocks first (faster)
    for block_size in [32, 16, 8, 4, 2, 1]:
        if len(current) < block_size:
            continue
        changed_in_pass = True
        while changed_in_pass:
            changed_in_pass = False
            for i in range(0, len(current) - block_size + 1, block_size):
                # Skip if already all zeros
                if all(b == 0 for b in current[i:i+block_size]):
                    continue
                
                candidate = bytearray(current)
                candidate[i:i+block_size] = bytes(block_size)  # Fill with zeros
                
                if _test(bytes(candidate)):
                    current = bytes(candidate)
                    changed_in_pass = True
                    if verbose:
                        print(f"  [ReduceFix] ✓ Zero-filled {block_size} bytes at offset {i}")
                    break
        
        if verbose and total_tests % 50 == 0:
            elapsed = time.time() - start_time
            print(f"  [ReduceFix] Tested {total_tests} candidates, elapsed={elapsed:.1f}s")

    # Stage 5: Byte-level DDMin with chunk removal (faster than one-by-one)
    if len(current) <= 1:
        if verbose:
            print(f"[ReduceFix] Complete: final size {len(current)} bytes")
            print(f"[ReduceFix] Total tests: {total_tests}, total time: {time.time() - start_time:.1f}s")
        return current

    if verbose:
        print("[ReduceFix] Stage 5: Byte-level DDMin (chunk removal)")

    # Try removing chunks of bytes (faster than one-by-one)
    for chunk_size in [8, 4, 2, 1]:
        changed = True
        while changed and len(current) > 1:
            changed = False
            i = 0
            while i < len(current):
                remove_size = min(chunk_size, len(current) - i)
                if remove_size == 0:
                    break
                    
                candidate = current[:i] + current[i+remove_size:]
                if len(candidate) > 0 and _test(candidate):
                    current = candidate
                    changed = True
                    if verbose and chunk_size == 1:
                        print(f"  [ReduceFix] ✓ Removed byte at offset {i}")
                    break
                else:
                    i += remove_size

    # Stage 6: Replace internal padding runs with single byte
    if verbose:
        print("[ReduceFix] Stage 6: Compressing internal padding sequences")

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
    
    # Stage 7: Byte value minimization - DISABLED to focus on length reduction
    # (This doesn't reduce file size, only simplifies content)

    # Final validation and output
    final_size = len(current)
    original_size = len(input_bytes)
    reduction_rate = (1 - final_size / original_size) * 100 if original_size > 0 else 0
    elapsed_time = time.time() - start_time

    if verbose:
        if final_size < original_size:
            bytes_saved = original_size - final_size
            print(f"[ReduceFix] ✓ SUCCESS! {original_size} → {final_size} bytes")
            print(f"[ReduceFix] Length reduction: {bytes_saved} bytes removed ({reduction_rate:.1f}%)")
        else:
            print(f"[ReduceFix] ✗ FAILED: No length reduction achieved")
            print(f"[ReduceFix] File remains at {original_size} bytes")
        
        print(f"[ReduceFix] Total tests: {total_tests}, total time: {elapsed_time:.1f}s")

    return current
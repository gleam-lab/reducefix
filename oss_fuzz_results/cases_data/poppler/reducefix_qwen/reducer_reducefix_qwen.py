def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    Format-aware test case reducer for poppler (PDF files)
    
    Strategy:
      - Stage 1: Remove entire PDF objects (obj...endobj blocks)
      - Stage 2: Reduce stream data within objects
      - Stage 3: Prune dictionary entries in objects
      - Stage 4: Line-based reduction for remaining content
    """
    import time
    import re
    
    if verbose:
        print(f"[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {len(input_bytes)} bytes")

    start_time = time.time()
    test_count = 0
    current_data = input_bytes

    # Keep header if present
    header_end = current_data.find(b'\n', 0, 50)
    header = current_data[:header_end+1] if header_end != -1 else b''
    
    # Decode to string for easier manipulation (PDF is mostly text with binary streams)
    try:
        content_str = current_data.decode('latin-1')
    except:
        content_str = current_data.decode('utf-8', errors='replace')
    
    lines = content_str.split('\n')
    original_line_count = len(lines)

    def make_candidate(data):
        nonlocal test_count
        candidate = data.encode('latin-1') if isinstance(data, str) else data
        test_count += 1
        return candidate

    def validate(candidate, success_msg):
        if test_fn(candidate):
            if verbose:
                temp = len(candidate)
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] ✓ {success_msg}, {temp} bytes, elapsed={elapsed:.1f}s")
            return True
        return False

    # Stage 1: Remove complete obj...endobj blocks
    if verbose:
        print("[ReduceFix] Stage 1: Removing PDF object blocks")

    obj_pattern = re.compile(r'(\d+ \d+ obj.*?endobj)', re.DOTALL)
    obj_blocks = obj_pattern.findall(content_str)
    kept_objects = []
    
    for i, block in enumerate(obj_blocks):
        # Try removing this object
        test_content = content_str
        for keep_block in kept_objects:
            pos = test_content.find(keep_block)
            if pos != -1:
                test_content = test_content[:pos] + " " * len(keep_block) + test_content[pos+len(keep_block):]
        
        # Remove current block temporarily
        temp_content = test_content.replace(block, "", 1)
        candidate = make_candidate(header + temp_content)
        
        if len(kept_objects) % 10 == 0 and verbose:
            current_size = len(candidate)
            print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(kept_objects)} objs, {current_size} bytes, elapsed={time.time()-start_time:.1f}s")
        
        if validate(candidate, f"Object {i} removed"):
            content_str = temp_content
            lines = content_str.split('\n')
        else:
            kept_objects.append(block)

    if verbose:
        final_obj_count = len(kept_objects)
        final_size = len(content_str.encode('latin-1'))
        reduction = (len(input_bytes) - final_size) / len(input_bytes) * 100
        print(f"[ReduceFix] Stage 1 complete: {len(input_bytes)} → {final_size} bytes ({reduction:.1f}% reduction)")

    # Stage 2: Reduce stream data within objects
    if verbose:
        print("[ReduceFix] Stage 2: Reducing stream content")

    stream_pattern = re.compile(r'(stream\r?\n)(.*?)(\r?\nendstream)', re.DOTALL)
    matches = stream_pattern.findall(content_str)
    
    for i, match in enumerate(matches):
        prefix, stream_data, suffix = match
        # Try replacing stream with minimal content
        minimal_stream = prefix + ' ' + suffix
        temp_content = content_str.replace(match[0] + match[1] + match[2], minimal_stream, 1)
        candidate = make_candidate(header + temp_content)
        
        if validate(candidate, f"Stream {i} reduced"):
            content_str = temp_content
            lines = content_str.split('\n')

    if verbose:
        final_size = len(content_str.encode('latin-1'))
        reduction = (len(input_bytes) - final_size) / len(input_bytes) * 100
        print(f"[ReduceFix] Stage 2 complete: → {final_size} bytes ({reduction:.1f}% reduction)")

    # Stage 3: Prune dictionary entries
    if verbose:
        print("[ReduceFix] Stage 3: Pruning dictionary entries")

    dict_pattern = re.compile(r'<<\s*(.*?)\s*>>', re.DOTALL)
    dicts = dict_pattern.findall(content_str)
    
    for dict_content in dicts:
        entries = dict_content.strip().split('/')
        if len(entries) <= 1:
            continue
            
        # Try removing each entry one by one
        entry_list = [e for e in entries if e.strip()]
        modified = False
        
        for i in range(len(entry_list)-1, -1, -1):
            test_entries = entry_list[:i] + entry_list[i+1:]
            if not test_entries:
                continue
                
            replacement = '<< ' + ''.join(f'/{e}' for e in test_entries) + ' >>'
            original_dict = '<< ' + ''.join(f'/{e}' for e in entry_list) + ' >>'
            temp_content = content_str.replace(original_dict, replacement, 1)
            candidate = make_candidate(header + temp_content)
            
            if validate(candidate, f"Dictionary entry removed"):
                content_str = temp_content
                lines = content_str.split('\n')
                entry_list = test_entries
                modified = True
                
        if modified:
            # Update the full pattern
            pass

    if verbose:
        final_size = len(content_str.encode('latin-1'))
        reduction = (len(input_bytes) - final_size) / len(input_bytes) * 100
        print(f"[ReduceFix] Stage 3 complete: → {final_size} bytes ({reduction:.1f}% reduction)")

    # Stage 4: Line-based reduction
    if verbose:
        print("[ReduceFix] Stage 4: Line-level reduction")

    lines = content_str.split('\n')
    line_indices = list(range(len(lines)))
    
    i = 0
    while i < len(line_indices):
        # Skip empty lines or likely critical lines
        line_idx = line_indices[i]
        if not lines[line_idx].strip() or lines[line_idx].startswith('%'):
            i += 1
            continue
            
        # Try removing this line
        temp_lines = lines[:line_idx] + lines[line_idx+1:]
        temp_content = '\n'.join(temp_lines)
        candidate = make_candidate(header + temp_content)
        
        if len(line_indices) % 20 == 0 and verbose:
            current_size = len(candidate)
            print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(line_indices)} lines, {current_size} bytes, elapsed={time.time()-start_time:.1f}s")
        
        if validate(candidate, f"Line {line_idx} removed"):
            lines = temp_lines
            line_indices = [idx if idx < line_idx else idx - 1 for idx in line_indices]
            line_indices.pop(i)
        else:
            i += 1

    final_result = header + '\n'.join(lines)
    final_bytes = final_result.encode('latin-1')
    final_reduction = (len(input_bytes) - len(final_bytes)) / len(input_bytes) * 100
    total_time = time.time() - start_time
    
    if verbose:
        print(f"[ReduceFix] Complete: {len(input_bytes)} → {len(final_bytes)} bytes ({final_reduction:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")

    return final_bytes
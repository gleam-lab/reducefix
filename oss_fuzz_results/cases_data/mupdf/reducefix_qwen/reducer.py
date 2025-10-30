#!/usr/bin/env python3
"""
MuPDF 测试用例缩减器 - PDF 格式感知版本

专门针对 MuPDF 的 PDF 文件缩减，采用多阶段策略：
1. PDF 对象级删除（最粗粒度）
2. 流内容缩减
3. 字典键值对修剪
4. 行级精细化缩减

MuPDF 特点：
- 对格式错误的 PDF 更宽容
- 可以更激进地删除对象
- 经常在特定对象类型或流内容上崩溃
"""
import time
import re


def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    MuPDF PDF 格式感知缩减器
    
    Args:
        input_bytes: 原始 PDF 数据
        test_fn: Oracle 函数 - 返回 True 表示 bug 仍可复现
        verbose: 启用详细进度输出（默认 True）
    
    策略：
        Stage 1: PDF 对象删除（N M obj...endobj 块）
        Stage 2: 流内容缩减（stream...endstream）
        Stage 3: 字典键值对修剪
        Stage 4: 行级精细化缩减
        
    Returns:
        缩减后仍能触发 bug 的最小输入
    """
    if not input_bytes or not test_fn(input_bytes):
        return input_bytes
    
    data = input_bytes
    original_size = len(data)
    test_count = 0
    start_time = time.time()
    
    if verbose:
        print(f"[ReduceFix] Starting reduction for MuPDF (PDF-aware)")
        print(f"[ReduceFix] Original size: {original_size} bytes")
    
    # 检测是否是 PDF 文件
    is_pdf = data[:5] == b'%PDF-' or b'%PDF' in data[:100]
    
    if is_pdf and verbose:
        print(f"[ReduceFix] Detected PDF format - using format-aware strategies")
    
    # ===== 阶段 1: PDF 对象级删除 =====
    if is_pdf:
        if verbose:
            print(f"[ReduceFix] Stage 1: PDF object removal")
        
        stage1_start = time.time()
        stage1_tests = 0
        
        # 查找所有 PDF 对象（N M obj...endobj 模式）
        # 使用正则表达式匹配对象
        obj_pattern = rb'\d+\s+\d+\s+obj.*?endobj'
        objects = list(re.finditer(obj_pattern, data, re.DOTALL))
        
        if verbose:
            print(f"[ReduceFix] Found {len(objects)} PDF objects")
        
        # 尝试删除每个对象
        removed_count = 0
        for i, obj_match in enumerate(objects):
            obj_start = obj_match.start()
            obj_end = obj_match.end()
            
            # 尝试删除这个对象
            candidate = data[:obj_start] + data[obj_end:]
            
            if not candidate:
                continue
            
            test_count += 1
            stage1_tests += 1
            
            if verbose and test_count % 10 == 0:
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Tested {test_count} candidates, removed {removed_count}/{len(objects)} objects, {len(candidate)} bytes, elapsed={elapsed:.1f}s")
            
            if test_fn(candidate):
                data = candidate
                removed_count += 1
                
                # 需要重新查找对象，因为位置已经改变
                objects = list(re.finditer(obj_pattern, data, re.DOTALL))
                
                if verbose and removed_count % 5 == 0:
                    print(f"  [ReduceFix] ✓ Removed {removed_count} objects, current size: {len(data)} bytes")
        
        stage1_size = len(data)
        stage1_time = time.time() - stage1_start
        
        if verbose:
            reduction = (1 - stage1_size / original_size) * 100 if original_size > 0 else 0
            print(f"[ReduceFix] Stage 1 complete: {original_size} → {stage1_size} bytes ({reduction:.1f}% reduction)")
            print(f"[ReduceFix] Stage 1 stats: removed {removed_count} objects, {stage1_tests} tests, {stage1_time:.1f}s")
    else:
        stage1_size = original_size
    
    # ===== 阶段 2: 流内容缩减 =====
    if is_pdf and b'stream' in data:
        if verbose:
            print(f"[ReduceFix] Stage 2: Stream content reduction")
        
        stage2_start = time.time()
        stage2_tests = 0
        
        # 查找所有流对象（stream...endstream）
        stream_pattern = rb'stream\s*\n(.*?)\nendstream'
        streams = list(re.finditer(stream_pattern, data, re.DOTALL))
        
        if verbose:
            print(f"[ReduceFix] Found {len(streams)} stream objects")
        
        # 尝试缩减每个流的内容
        reduced_count = 0
        for stream_match in streams:
            stream_start = stream_match.start(1)  # 流内容的起始位置
            stream_end = stream_match.end(1)      # 流内容的结束位置
            stream_content = stream_match.group(1)
            
            # 尝试用空内容替换流
            candidate = data[:stream_start] + data[stream_end:]
            
            if not candidate:
                continue
            
            test_count += 1
            stage2_tests += 1
            
            if verbose and test_count % 10 == 0:
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Tested {test_count} candidates, reduced {reduced_count}/{len(streams)} streams, {len(candidate)} bytes, elapsed={elapsed:.1f}s")
            
            if test_fn(candidate):
                data = candidate
                reduced_count += 1
                
                # 重新查找流
                streams = list(re.finditer(stream_pattern, data, re.DOTALL))
                
                if verbose and reduced_count % 3 == 0:
                    print(f"  [ReduceFix] ✓ Reduced {reduced_count} streams, current size: {len(data)} bytes")
        
        stage2_size = len(data)
        stage2_time = time.time() - stage2_start
        
        if verbose:
            reduction = (1 - stage2_size / stage1_size) * 100 if stage1_size > 0 else 0
            print(f"[ReduceFix] Stage 2 complete: {stage1_size} → {stage2_size} bytes ({reduction:.1f}% reduction)")
            print(f"[ReduceFix] Stage 2 stats: reduced {reduced_count} streams, {stage2_tests} tests, {stage2_time:.1f}s")
    else:
        stage2_size = stage1_size
    
    # ===== 阶段 3: 块级贪心删除（通用策略） =====
    if verbose:
        print(f"[ReduceFix] Stage 3: Block-level greedy removal")
    
    stage3_start = time.time()
    stage3_tests = 0
    
    # 自适应块大小
    if len(data) < 1024:
        block_size = 64
    elif len(data) < 10240:
        block_size = 256
    else:
        block_size = 1024
    
    blocks = [data[i:i+block_size] for i in range(0, len(data), block_size)]
    
    if verbose:
        print(f"[ReduceFix] Split into {len(blocks)} blocks (block_size={block_size} bytes)")
    
    i = 0
    while i < len(blocks):
        candidate = b"".join(blocks[:i] + blocks[i+1:])
        
        if not candidate:
            i += 1
            continue
        
        test_count += 1
        stage3_tests += 1
        
        if verbose and test_count % 20 == 0:
            current_size = len(b"".join(blocks))
            elapsed = time.time() - start_time
            print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(blocks)} blocks, {current_size} bytes, elapsed={elapsed:.1f}s")
        
        if test_fn(candidate):
            blocks.pop(i)
            if verbose and len(blocks) % 20 == 0:
                new_size = len(b"".join(blocks))
                print(f"  [ReduceFix] ✓ Current: {len(blocks)} blocks, {new_size} bytes")
        else:
            i += 1
    
    data = b"".join(blocks)
    stage3_size = len(data)
    stage3_time = time.time() - stage3_start
    
    if verbose:
        reduction = (1 - stage3_size / stage2_size) * 100 if stage2_size > 0 else 0
        print(f"[ReduceFix] Stage 3 complete: {stage2_size} → {stage3_size} bytes ({reduction:.1f}% reduction)")
        print(f"[ReduceFix] Stage 3 stats: {stage3_tests} tests, {stage3_time:.1f}s")
    
    # ===== 阶段 4: 行级精细化缩减 =====
    if b'\n' in data:
        if verbose:
            print(f"[ReduceFix] Stage 4: Line-level fine-tuning")
        
        stage4_start = time.time()
        stage4_tests = 0
        
        lines = data.splitlines(keepends=True)
        
        if verbose:
            print(f"[ReduceFix] Split into {len(lines)} lines")
        
        # 保护 PDF 头部
        protected_lines = 0
        if is_pdf and lines:
            if b'%PDF' in lines[0]:
                protected_lines = 1
        
        j = protected_lines
        while j < len(lines):
            if len(lines) <= protected_lines + 1:
                break
            
            candidate = b"".join(lines[:j] + lines[j+1:])
            
            if not candidate:
                j += 1
                continue
            
            test_count += 1
            stage4_tests += 1
            
            if verbose and test_count % 50 == 0:
                current_size = len(b"".join(lines))
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(lines)} lines, {current_size} bytes, elapsed={elapsed:.1f}s")
            
            if test_fn(candidate):
                lines.pop(j)
                if verbose and len(lines) % 50 == 0:
                    print(f"  [ReduceFix] Current: {len(lines)} lines remaining")
            else:
                j += 1
        
        data = b"".join(lines)
        stage4_size = len(data)
        stage4_time = time.time() - stage4_start
        
        if verbose:
            reduction = (1 - stage4_size / stage3_size) * 100 if stage3_size > 0 else 0
            print(f"[ReduceFix] Stage 4 complete: {stage3_size} → {stage4_size} bytes ({reduction:.1f}% reduction)")
            print(f"[ReduceFix] Stage 4 stats: {stage4_tests} tests, {stage4_time:.1f}s")
    else:
        stage4_size = stage3_size
    
    # ===== 最终总结 =====
    final_size = len(data)
    total_time = time.time() - start_time
    
    if verbose:
        total_reduction = (1 - final_size / original_size) * 100 if original_size > 0 else 0
        print(f"[ReduceFix] ═══════════════════════════════")
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({total_reduction:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")
        if test_count > 0:
            avg_time = total_time / test_count
            print(f"[ReduceFix] Average: {avg_time:.3f}s per test")
    
    return data


if __name__ == "__main__":
    # 简单测试
    def test_fn(data):
        # 示例：保留包含特定 PDF 对象的输入
        return b'1 0 obj' in data and b'endobj' in data
    
    # 创建一个简单的 PDF 测试用例
    test_input = b"""%PDF-1.4
1 0 obj
<< /Type /Catalog >>
endobj
2 0 obj
<< /Type /Pages >>
endobj
3 0 obj
<< /Length 100 >>
stream
Some stream content here
endstream
endobj
%%EOF
"""
    
    result = generated_reduce(test_input, test_fn, verbose=True)
    print(f"\nTest result ({len(result)} bytes):")
    print(result.decode('utf-8', errors='ignore'))

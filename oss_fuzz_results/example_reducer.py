#!/usr/bin/env python3
"""
通用的多阶段测试用例缩减器示例

这是一个方法论参考，展示如何实现多阶段缩减策略。
实际使用时应该根据具体的数据格式调整各个阶段。
"""
import time
import re


def generated_reduce(input_bytes: bytes, test_fn, verbose: bool = True) -> bytes:
    """
    多阶段测试用例缩减器（通用示例）
    
    Args:
        input_bytes: 原始输入数据
        test_fn: Oracle函数，返回 True 表示 bug 仍可复现
        verbose: 是否输出详细进度
    
    Returns:
        缩减后仍能触发 bug 的最小输入
    
    示例方法论：
        1. 粗粒度删除（大块）
        2. 中粒度删除（结构单元）
        3. 细粒度删除（行）
        4. 内容缩减（字符）
    """
    if not input_bytes or not test_fn(input_bytes):
        return input_bytes
    
    data = input_bytes
    original_size = len(data)
    test_count = 0
    start_time = time.time()
    
    if verbose:
        print(f"[ReduceFix] Starting reduction")
        print(f"[ReduceFix] Original size: {original_size} bytes")
    
    # ===== 阶段 1: 块级贪心删除 =====
    if verbose:
        print(f"[ReduceFix] Stage 1: Block-level greedy removal")
    
    stage1_start = time.time()
    stage1_tests = 0
    
    # 决定块大小（自适应）
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
        # 尝试删除当前块
        candidate = b"".join(blocks[:i] + blocks[i+1:])
        
        if not candidate:
            i += 1
            continue
        
        test_count += 1
        stage1_tests += 1
        
        if verbose and test_count % 10 == 0:
            current_size = len(b"".join(blocks))
            elapsed = time.time() - start_time
            print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(blocks)} blocks, {current_size} bytes, elapsed={elapsed:.1f}s")
        
        if test_fn(candidate):
            # 成功删除
            blocks.pop(i)
            if verbose and len(blocks) % 10 == 0:
                new_size = len(b"".join(blocks))
                print(f"  [ReduceFix] ✓ Removed block {i} ({len(blocks)+1} → {len(blocks)} blocks), {new_size} bytes")
            # 不增加 i，继续尝试删除同一位置的下一个块
        else:
            i += 1
    
    data = b"".join(blocks)
    stage1_size = len(data)
    stage1_time = time.time() - stage1_start
    
    if verbose:
        reduction = (1 - stage1_size / original_size) * 100 if original_size > 0 else 0
        print(f"[ReduceFix] Stage 1 complete: {original_size} → {stage1_size} bytes ({reduction:.1f}% reduction)")
        print(f"[ReduceFix] Stage 1 stats: {stage1_tests} tests, {stage1_time:.1f}s")
    
    # ===== 阶段 2: 行级缩减（如果是文本） =====
    if b'\n' in data:
        if verbose:
            print(f"[ReduceFix] Stage 2: Line-level reduction")
        
        stage2_start = time.time()
        stage2_tests = 0
        
        lines = data.splitlines(keepends=True)
        
        if verbose:
            print(f"[ReduceFix] Split into {len(lines)} lines")
        
        j = 0
        while j < len(lines):
            if len(lines) <= 1:
                break
            
            candidate = b"".join(lines[:j] + lines[j+1:])
            
            if not candidate:
                j += 1
                continue
            
            test_count += 1
            stage2_tests += 1
            
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
        stage2_size = len(data)
        stage2_time = time.time() - stage2_start
        
        if verbose:
            reduction = (1 - stage2_size / stage1_size) * 100 if stage1_size > 0 else 0
            print(f"[ReduceFix] Stage 2 complete: {stage1_size} → {stage2_size} bytes ({reduction:.1f}% reduction)")
            print(f"[ReduceFix] Stage 2 stats: {stage2_tests} tests, {stage2_time:.1f}s")
    
    # ===== 阶段 3: 字符级缩减（细粒度优化） =====
    if len(data) < 10000:  # 只对较小的文件做字符级缩减
        if verbose:
            print(f"[ReduceFix] Stage 3: Character-level reduction (for small files)")
        
        stage3_start = time.time()
        stage3_tests = 0
        
        # 尝试删除单个字符
        k = 0
        max_char_tests = 1000  # 限制字符级测试次数
        
        while k < len(data) and stage3_tests < max_char_tests:
            if len(data) <= 1:
                break
            
            candidate = data[:k] + data[k+1:]
            
            test_count += 1
            stage3_tests += 1
            
            if verbose and test_count % 100 == 0:
                elapsed = time.time() - start_time
                print(f"  [ReduceFix] Tested {test_count} candidates, current: {len(data)} bytes, elapsed={elapsed:.1f}s")
            
            if test_fn(candidate):
                data = candidate
                # 不增加 k
            else:
                k += 1
        
        stage3_size = len(data)
        stage3_time = time.time() - stage3_start
        
        if verbose:
            prev_size = stage2_size if b'\n' in input_bytes else stage1_size
            reduction = (1 - stage3_size / prev_size) * 100 if prev_size > 0 else 0
            print(f"[ReduceFix] Stage 3 complete: {prev_size} → {stage3_size} bytes ({reduction:.1f}% reduction)")
            print(f"[ReduceFix] Stage 3 stats: {stage3_tests} tests, {stage3_time:.1f}s")
    
    # ===== 最终总结 =====
    final_size = len(data)
    total_time = time.time() - start_time
    
    if verbose:
        total_reduction = (1 - final_size / original_size) * 100 if original_size > 0 else 0
        print(f"[ReduceFix] ═══════════════════════════════")
        print(f"[ReduceFix] Complete: {original_size} → {final_size} bytes ({total_reduction:.1f}% reduction)")
        print(f"[ReduceFix] Total tests: {test_count}, total time: {total_time:.1f}s")
        if test_count > 0:
            print(f"[ReduceFix] Average: {total_time/test_count:.3f}s per test")
    
    return data


# 如果直接运行此脚本（测试用）
if __name__ == "__main__":
    # 简单测试
    def test_fn(data):
        # 示例：保留包含 "important" 的输入
        return b"important" in data
    
    test_input = b"This is some text.\nimportant line\nother stuff\n"
    result = generated_reduce(test_input, test_fn, verbose=True)
    print(f"\nTest result: {result}")


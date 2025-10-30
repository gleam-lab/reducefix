from typing import Callable, List, Optional


TestFn = Callable[[bytes], bool]


def _split_into_blocks(data: bytes, *, block_size: int = 2048) -> List[bytes]:
    return [data[i : i + block_size] for i in range(0, len(data), block_size)]


def _merge_blocks(blocks: List[bytes]) -> bytes:
    return b"".join(blocks)


def _try_shrink_greedily(blocks: List[bytes], test_fn: TestFn) -> List[bytes]:
    i = 0
    while i < len(blocks):
        candidate = blocks[:i] + blocks[i + 1 :]
        if candidate and test_fn(_merge_blocks(candidate)):
            blocks = candidate
            # keep i (same index now points to next item)
        else:
            i += 1
    return blocks


def reduce_fix(data: bytes, test_fn: TestFn, *, block_size: int = 2048, line_mode: bool = True) -> bytes:
    """Heuristic block-first reducer with optional line-level finesse.

    Strategy:
      1) Remove whole blocks greedily
      2) Binary split blocks and try removals (coarse-to-fine)
      3) Optional: per-block line ddmin
    """
    if not data:
        return data

    blocks = _split_into_blocks(data, block_size=block_size)
    if not test_fn(data):
        return data

    # 1) Greedy whole-block removal
    blocks = _try_shrink_greedily(blocks, test_fn)

    # 2) Coarse-to-fine splitting
    granularity = 2
    while len(blocks) >= 2:
        n = len(blocks)
        made_progress = False
        chunk = max(1, n // granularity)
        start = 0
        while start < n:
            end = min(n, start + chunk)
            candidate = blocks[:start] + blocks[end:]
            if candidate and test_fn(_merge_blocks(candidate)):
                blocks = candidate
                granularity = 2
                made_progress = True
                break
            start = end
        if not made_progress:
            if granularity >= n:
                break
            granularity = min(n, granularity * 2)

    result = _merge_blocks(blocks)

    if line_mode and b"\n" in result:
        # Fine-tune with line-level ddmin-like removal inside the final data
        lines = result.splitlines(keepends=True)
        made_progress = True
        while made_progress and len(lines) > 1:
            made_progress = False
            i = 0
            while i < len(lines):
                candidate = lines[:i] + lines[i + 1 :]
                candidate_bytes = b"".join(candidate)
                if candidate and test_fn(candidate_bytes):
                    lines = candidate
                    made_progress = True
                else:
                    i += 1
        result = b"".join(lines)

    return result



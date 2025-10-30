n, m = map(int, input().split())
blocked = set()

# The 8 possible knight move offsets that can capture a piece
capture_offsets = [
    (2, 1), (1, 2), (-1, 2), (-2, 1),
    (-2, -1), (-1, -2), (1, -2), (2, -1)
]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, determine which squares it can capture
    for dx, dy in capture_offsets:
        x = a + dx
        y = b + dy
        # Only consider valid grid positions
        if 1 <= x <= n and 1 <= y <= n:
            blocked.add((x, y))

# Total empty squares where we can place = all squares minus squares under threat
# Note: We don't subtract the occupied squares because they are not "empty"
# We only care about empty squares that are NOT capturable
total_safe_empty = n * n - len(blocked)

print(total_safe_empty)
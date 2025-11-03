n, m = map(int, input().split())
captured = set()

# Define the 8 possible capture positions relative to a piece
capture_offsets = [
    (2, 1), (1, 2), (-1, 2), (-2, 1),
    (-2, -1), (-1, -2), (1, -2), (2, -1)
]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, mark all squares it can capture
    for dx, dy in capture_offsets:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Total empty squares minus the ones that are capturable
ans = n * n - m - len(captured)

print(ans)
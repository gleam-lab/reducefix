n, m = map(int, input().split())
captured = set()

# Define the 8 possible knight move offsets
moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, mark all squares it can capture
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Total empty squares where we can place = total squares - occupied - captured
# But note: some captured squares might be already occupied, so we don't double count

# First, collect all occupied positions
occupied = set()
for _ in range(m):
    a, b = map(int, input().split())
    occupied.add((a, b))

# Recompute captured squares (since we need to read input again, better to do it once)
captured.clear()
for a, b in occupied:
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Valid positions are those that are not occupied and not captured
# Total safe positions = N*N - |occupied| - |captured but not occupied|
# Since captured and occupied may overlap, we subtract only non-overlapping captured

ans = n * n - len(occupied) - len(captured - occupied)

print(ans)
n, m = map(int, input().split())
s = set()

# Define the 8 possible capture directions (knight moves)
moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    # Add all positions that this piece can capture
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            s.add((x, y))

# Total empty squares where we can place our piece safely
ans = n * n - len(s)

print(ans)
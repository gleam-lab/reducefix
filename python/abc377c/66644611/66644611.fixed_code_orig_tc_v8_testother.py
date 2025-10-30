n, m = map(int, input().split())
s = set()

# Define the 8 knight move directions
dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

for _ in range(m):
    a, b = map(int, input().split())
    # Add the piece itself to the set of occupied squares
    s.add((a, b))
    # For each of the 8 possible knight moves from this piece
    for i in range(8):
        nx, ny = a + dx[i], b + dy[i]
        # Only add if within grid bounds
        if 1 <= nx <= n and 1 <= ny <= n:
            s.add((nx, ny))

# Total squares minus all squares that are either occupied or under attack
ans = n * n - len(s)
print(ans)
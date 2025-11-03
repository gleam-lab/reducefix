n, m = map(int, input().split())
captured = set()

# The 8 possible knight moves (i, j) -> (i+di, j+dj)
moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, mark all squares it can capture
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Total empty squares that are not under capture
ans = n * n - len(captured)

# But we must subtract the squares where pieces are already placed
# because those are not available for placing our piece
# However, note: captured set does not include the original pieces
# So we need to ensure we don't double count or miss anything

# Actually, we only need to subtract the M occupied squares from total
# But only if they were not already excluded? No — our `captured` set is only about capture targets.
# Our piece cannot be placed on any occupied square, but also cannot be placed on captured squares.

# However, note: the problem says "empty square" and "cannot be captured"
# So valid squares = all grid squares
#                  - occupied squares (M of them)
#                  - captured squares (that are not occupied, but might overlap)

# But wait: can an existing piece be in a captured square? Yes, but we cannot place on occupied anyway.
# So total forbidden = occupied + (captured \ occupied)

# However, we are only counting captured squares that are within bounds.
# And we want: total_empty_and_safe = N*N - (occupied ∪ captured)

# So:
# ans = N*N - |occupied ∪ captured| = N*N - (|occupied| + |captured| - |occupied ∩ captured|)

# We already have:
#   |occupied| = m
#   |captured| = len(captured)
#   |occupied ∩ captured| = number of occupied squares that are in `captured`

overlap = 0
for _ in range(m):
    # We need to re-read the input or store the pieces
    pass

# So better: store the pieces first
pieces = []
captured.clear()

for _ in range(m):
    a, b = map(int, input().split())
    pieces.append((a, b))

# Now compute captured squares
for a, b in pieces:
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Count overlap: how many pieces are in the captured set?
overlap = sum(1 for (a, b) in pieces if (a, b) in captured)

# Total invalid squares = pieces (m) + captured squares not already counted
# = m + (len(captured) - overlap)
total_invalid = m + len(captured) - overlap

ans = n * n - total_invalid

print(ans)
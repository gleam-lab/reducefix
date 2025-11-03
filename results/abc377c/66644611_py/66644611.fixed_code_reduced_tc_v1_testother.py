n, m = map(int, input().split())
captured = set()

# The 8 possible knight moves (these are the squares that can be captured by a piece)
moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, mark all squares it can capture
    for dx, dy in moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Total empty squares: n*n minus the M occupied squares
# But we must subtract only those captured squares that are both valid and not already occupied
# However, note: a captured square might be occupied by another piece — but we can't place on occupied anyway.
# So we just need to avoid placing on any captured square (whether empty or not, but only count empty ones that are safe)

# All squares we cannot use:
# 1. Squares with existing pieces (M of them)
# 2. Empty squares that are under capture

# But note: some captured squares might be outside [1,n]x[1,n], and duplicates are handled by set.

# We compute total safe empty squares as:
#   total squares (n*n)
#   - M (occupied by other pieces)
#   - number of captured squares that are within bounds and not already occupied

# However, if a captured square coincides with an existing piece, we shouldn't double-count
# But since we're only disallowing placement on empty squares, we care about captured squares that are empty.
# But our captured set includes only squares that are within bounds.

# Actually, we can do:
# safe_squares = n*n - M - (number of captured squares that are not occupied)

# But wait: what if a captured square is occupied? Then we don't want to subtract it again.
# However, in our `captured` set, we added only positions reachable by knight move, which may or may not be occupied.

# Important: we must not subtract occupied squares again.

# So: total forbidden for us = 
#   occupied squares (M) -> we can't place there
#   captured squares that are NOT occupied -> we can't place there either

# But we don't know which captured squares are occupied.

# Alternative approach:
# Let S = set of occupied squares (we'll store it)
# Let C = set of captured squares (that are in bounds)

# Then the number of squares we can use = n*n - |S ∪ C|
# Because we cannot place on any occupied or captured square.

# But note: if a square is both occupied and captured, it's still only one square.

occupied = set()
for i in range(m):
    a, b = map(int, input().split() if i > 0 else lambda: (a,b))  # This won't work

# We need to read input again properly
# Let's restructure
n, m = map(int, input().split())
blocked = set()

# Directions for the 8 possible capture moves
capture_moves = [
    (2, 1), (1, 2), (-1, 2), (-2, 1),
    (-2, -1), (-1, -2), (1, -2), (2, -1)
]

for _ in range(m):
    a, b = map(int, input().split())
    # Mark all squares that this piece can capture (i.e. where placing our piece would be unsafe)
    for dx, dy in capture_moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            blocked.add((x, y))

# Total empty squares that are safe to place
# Note: We cannot place on occupied squares (pieces already there), but those are not in `blocked` unless they are under threat
# However, we only need to subtract the safe candidate squares that are threatened

# Initially, total available squares is n*n minus the M occupied squares
total_safe = n * n - m

# But we must subtract any threatened square that is both empty and within bounds
# However, note: some threatened squares might coincide or fall on already occupied squares
# So we count only distinct threatened positions that are valid

threatened_count = 0
for pos in blocked:
    x, y = pos
    if 1 <= x <= n and 1 <= y <= n:
        threatened_count += 1

# But wait: we must not double-count or include occupied squares in threatened?
# Actually, `blocked` contains only positions under threat. Even if multiple pieces threaten same square, set handles uniqueness.

# However, what if a threatened square is already occupied? Then we cannot place there anyway (because it's not empty), 
# so we should not subtract it again — but our `blocked` set may include such squares.

# Important: We are only allowed to place on **empty** squares that are **not threatened**.
# So the answer = total empty squares - (threatened squares that are empty)

# But currently:
# total_empty = n*n - m
# threatened_and_empty = (# of threatened squares) - (# of threatened squares that are occupied)

# Instead, simpler: collect all squares where placement is invalid:
# 1. The M occupied squares
# 2. The threatened squares (even if overlapping with occupied, set union handles it)

# So total forbidden = M + {threatened safe squares not occupied}
# But better: total allowed = total grid - (occupied ∪ threatened)

# Let total_forbidden = occupied ∪ threatened
# We already have occupied as input, and we built `blocked` as threatened

# So:
forbidden = set()
# Add all occupied
for _ in range(m):
    # We already read them, so re-reading won't work — need to store or reread logic
    pass

# Let's refactor: store occupied
occupied = set()
blocked_by_capture = set()

for i in range(m):
    a, b = map(int, input().split())  # Wait, we already consumed input!
# Mistake: we read input once above, now can't read again.

# So fix: read input first and store

# Rewriting from scratch:

import sys

def main():
    data = sys.stdin.read().split()
    n = int(data[0])
    m = int(data[1])
    
    occupied = set()
    capture_moves = [
        (2, 1), (1, 2), (-1, 2), (-2, 1),
        (-2, -1), (-1, -2), (1, -2), (2, -1)
    ]
    
    idx = 2
    for _ in range(m):
        a = int(data[idx]); b = int(data[idx+1]); idx += 2
        occupied.add((a, b))
    
    # Compute all squares that are threatened (can be captured by existing pieces)
    threatened = set()
    # Re-iterate over occupied to compute threats
    for (a, b) in occupied:
        for dx, dy in capture_moves:
            x, y = a + dx, b + dy
            if 1 <= x <= n and 1 <= y <= n:
                threatened.add((x, y))
    
    # Forbidden squares = occupied OR threatened
    forbidden = occupied | threatened  # union
    total_forbidden = len(forbidden)
    
    total_squares = n * n
    answer = total_squares - total_forbidden
    print(answer)

main()
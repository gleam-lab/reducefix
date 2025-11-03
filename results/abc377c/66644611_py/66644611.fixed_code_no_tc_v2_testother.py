n, m = map(int, input().split())
captured = set()

# Define the 8 knight move offsets
knight_moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    # For each existing piece, mark all squares it can capture
    for dx, dy in knight_moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Total empty squares that are not under capture
ans = n * n - len(captured)

# But we must ensure we don't count occupied squares as available
# However, captured set only includes squares that can be attacked
# The problem allows placing on any empty square not capturable
# So final answer is: total squares - occupied squares - capturable empty squares?
# Wait: no. We want: empty squares that are NOT capturable.

# Actually:
# - You cannot place on occupied squares
# - You cannot place on empty squares that are capturable
# So valid squares = total squares - occupied squares - (capturable squares that are not occupied)

# But note: some capturable squares might be occupied, so we shouldn't double subtract

# Better approach:
# Start with all squares: n*n
# Subtract: M (occupied squares)
# Subtract: capturable empty squares (i.e., capturable squares that are not occupied)

# But wait — our `captured` set includes squares that might be occupied.
# We only care about whether a square is capturable, regardless of occupancy.
# However, you can't place on occupied squares anyway.

# Actually, correct logic:
# A square is invalid for placement if:
#   - It is occupied, OR
#   - It is capturable (even if empty, you can't place there because it would be captured)
#
# But wait! Read problem again: "place your piece on an empty square in such a way that it cannot be captured"
# So:
#   - Must be empty
#   - Must not be capturable by any existing piece
#
# Therefore:
#   Valid squares = (all squares) - (occupied squares) - (empty squares that are capturable)
#                 = n*n - M - [number of capturable squares that are NOT occupied]

# Alternatively:
#   Let C = set of capturable squares (regardless of occupancy)
#   Then valid squares = (all squares) - (occupied squares) - (C \ occupied)
#                      = n*n - M - (|C| - |C ∩ occupied|)
#
# But easier: 
#   Invalid squares for placement = occupied squares ∪ capturable squares
#   So answer = n*n - |occupied ∪ capturable|

# Since occupied and capturable may overlap, we do:
#   total_invalid = len(occupied_set ∪ captured_set)
#   answer = n*n - total_invalid

# We already have captured set (from above)
# Now build full set of invalid positions

invalid = set()
# Add all occupied
for _ in range(m):
    # We need to re-read or store inputs
    pass

# So let's restructure:

n, m = map(int, input().split())
pieces = []
captured = set()
knight_moves = [(2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)]

for _ in range(m):
    a, b = map(int, input().split())
    pieces.append((a,b))
    # Mark all squares this piece can capture
    for dx, dy in knight_moves:
        x, y = a + dx, b + dy
        if 1 <= x <= n and 1 <= y <= n:
            captured.add((x, y))

# Set of occupied squares
occupied = set(pieces)

# Invalid squares are those that are either occupied or capturable
invalid = occupied | captured  # union

ans = n * n - len(invalid)
print(ans)
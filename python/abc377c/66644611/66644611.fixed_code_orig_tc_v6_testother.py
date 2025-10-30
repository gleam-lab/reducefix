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
        nx, ny = a + dx, b + dy
        if 1 <= nx <= n and 1 <= ny <= n:
            captured.add((nx, ny))

# Count total empty squares minus those that are capturable
total_squares = n * n
occupied_or_captured = set()

# Add all existing pieces
for _ in range(m):
    # We need to re-read the input since we consumed it earlier
    pass

# Re-process input to get occupied squares
import sys
lines = sys.stdin.read().splitlines()
if lines:
    pieces = [tuple(map(int, line.split())) for line in lines[1:]]
else:
    pieces = []

occupied = set(pieces)
# Combine occupied and capturable squares
all_invalid = occupied | captured

# The answer is total squares minus invalid squares
ans = total_squares - len(all_invalid)
print(ans)
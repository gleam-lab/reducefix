N, M = map(int, input().split())
pieces = [tuple(map(int, input().split())) for _ in range(M)]

# If there are no pieces, every empty square is valid
if M == 0:
    print(N * N)
    exit()

# Sets to store unique lines attacked by existing pieces
rows = set()
cols = set()
diag1 = set()  # i + j = constant (anti-diagonal)
diag2 = set()  # i - j = constant (main diagonal)

# For each piece, mark the lines it attacks
for a, b in pieces:
    rows.add(a)
    cols.add(b)
    diag1.add(a + b)
    diag2.add(a - b)

# Total squares under attack (union of all rows, cols, diag1, diag2)
# We calculate using inclusion-exclusion principle

total_attacked = 0

# Add: all squares in attacked rows
total_attacked += len(rows) * N

# Add: all squares in attacked columns
total_attacked += len(cols) * N

# Add: all squares in attacked diag1 (i+j = c)
for s in diag1:
    # Number of integer solutions (i,j) such that i+j = s, 1<=i<=N, 1<=j<=N
    if s < 2:
        count = 0
    elif s <= N + 1:
        count = s - 1
    else:
        count = 2 * N - s + 1
    total_attacked += count

# Add: all squares in attacked diag2 (i-j = d)
for d in diag2:
    # Number of integer solutions (i,j) such that i-j = d, 1<=i<=N, 1<=j<=N
    if d >= 0:
        # i = j + d => j >= 1, i <= N => j <= N - d
        count = N - d if d < N else 0
    else:
        # j = i - d => i >= 1, j <= N => i <= N + d (since d is negative)
        count = N + d
    total_attacked += max(0, count)

# Subtract overlaps: attacked rows ∩ attacked cols (each (r,c) where r in rows, c in cols)
total_attacked -= len(rows) * len(cols)

# Subtract overlaps: attacked rows ∩ diag1
for r in rows:
    for s in diag1:
        # On row r, diag1: r + j = s => j = s - r
        j = s - r
        if 1 <= j <= N:
            total_attacked -= 1

# Subtract overlaps: attacked rows ∩ diag2
for r in rows:
    for d in diag2:
        # On row r, diag2: r - j = d => j = r - d
        j = r - d
        if 1 <= j <= N:
            total_attacked -= 1

# Subtract overlaps: attacked cols ∩ diag1
for c in cols:
    for s in diag1:
        # On col c, diag1: i + c = s => i = s - c
        i = s - c
        if 1 <= i <= N:
            total_attacked -= 1

# Subtract overlaps: attacked cols ∩ diag2
for c in cols:
    for d in diag2:
        # On col c, diag2: i - c = d => i = d + c
        i = d + c
        if 1 <= i <= N:
            total_attacked -= 1

# Subtract overlaps: diag1 ∩ diag2
for s in diag1:
    for d in diag2:
        # Solve: i + j = s, i - j = d => i = (s+d)/2, j = (s-d)/2
        if (s + d) % 2 == 0:
            i = (s + d) // 2
            j = (s - d) // 2
            if 1 <= i <= N and 1 <= j <= N:
                total_attacked -= 1

# Add back: triple overlaps (we subtracted too much)
# rows ∩ cols ∩ diag1
for r in rows:
    for c in cols:
        s = r + c
        if s in diag1:
            total_attacked += 1

# rows ∩ cols ∩ diag2
for r in rows:
    for c in cols:
        d = r - c
        if d in diag2:
            total_attacked += 1

# rows ∩ diag1 ∩ diag2
for r in rows:
    for s in diag1:
        for d in diag2:
            if (s + d) % 2 == 0:
                i = (s + d) // 2
                j = (s - d) // 2
                if i == r and 1 <= i <= N and 1 <= j <= N:
                    total_attacked += 1

# cols ∩ diag1 ∩ diag2
for c in cols:
    for s in diag1:
        for d in diag2:
            if (s + d) % 2 == 0:
                i = (s + d) // 2
                j = (s - d) // 2
                if j == c and 1 <= i <= N and 1 <= j <= N:
                    total_attacked += 1

# Add back: quadruple overlap (rows ∩ cols ∩ diag1 ∩ diag2)
for r in rows:
    for c in cols:
        s = r + c
        d = r - c
        if s in diag1 and d in diag2:
            total_attacked += 1

# But we have overcounted: the original M pieces are counted in multiple sets
# Actually, inclusion-exclusion already handles this — but we must remember:
# The total_attacked now counts every square that lies on any attacked line.

# However, we haven't yet removed duplicates properly. Instead, let's use a simpler idea:
# Since M <= 1000, we can compute the union of attacked squares directly?

# But N up to 1e9 — cannot iterate over grid.

# Alternative correct approach: inclusion-exclusion was messy above.
# Let's do it cleanly with set operations via formulas.

from collections import defaultdict

# Instead, we calculate the union size using inclusion exclusion properly:

R = len(rows)
C = len(cols)
D1 = len(diag1)
D2 = len(diag2)

# |R ∪ C ∪ D1 ∪ D2| = 
#   |R| + |C| + |D1| + |D2|
# - |R∩C| - |R∩D1| - |R∩D2| - |C∩D1| - |C∩D2| - |D1∩D2|
# + |R∩C∩D1| + |R∩C∩D2| + |R∩D1∩D2| + |C∩D1∩D2|
# - |R∩C∩D1∩D2|

total = 0

# Single sets
total += R * N
total += C * N
for s in diag1:
    if 2 <= s <= N+1:
        total += s - 1
    elif N+2 <= s <= 2*N:
        total += 2*N - s + 1

for d in diag2:
    if -N+1 <= d <= N-1:
        total += N - abs(d)

# Subtract pairwise intersections

# R ∩ C: points (r,c) for r in rows, c in cols -> R*C
total -= R * C

# R ∩ D1: for each r in rows, s in diag1: point (r, s-r) exists iff 1<=s-r<=N
for r in rows:
    for s in diag1:
        j = s - r
        if 1 <= j <= N:
            total -= 1

# R ∩ D2: for each r in rows, d in diag2: point (r, r-d) exists iff 1<=r-d<=N
for r in rows:
    for d in diag2:
        j = r - d
        if 1 <= j <= N:
            total -= 1

# C ∩ D1: for each c in cols, s in diag1: point (s-c, c) exists iff 1<=s-c<=N
for c in cols:
    for s in diag1:
        i = s - c
        if 1 <= i <= N:
            total -= 1

# C ∩ D2: for each c in cols, d in diag2: point (d+c, c) exists iff 1<=d+c<=N
for c in cols:
    for d in diag2:
        i = d + c
        if 1 <= i <= N:
            total -= 1

# D1 ∩ D2: for each s in diag1, d in diag2: solution i=(s+d)/2, j=(s-d)/2 must be integer and in range
for s in diag1:
    for d in diag2:
        if (s + d) % 2 == 0:
            i = (s + d) // 2
            j = (s - d) // 2
            if 1 <= i <= N and 1 <= j <= N:
                total -= 1

# Add back triple intersections

# R ∩ C ∩ D1: (r,c) such that r+c in diag1
for r in rows:
    for c in cols:
        if r + c in diag1:
            total += 1

# R ∩ C ∩ D2: (r,c) such that r-c in diag2
for r in rows:
    for c in cols:
        if r - c in diag2:
            total += 1

# R ∩ D1 ∩ D2: (r,j) such that r+j in diag1 and r-j in diag2
for r in rows:
    for s in diag1:
        for d in diag2:
            if (s + d) % 2 == 0:
                i = (s + d) // 2
                j = (s - d) // 2
                if 1 <= i <= N and 1 <= j <= N and i == r:
                    total += 1

# C ∩ D1 ∩ D2: (i,c) such that i+c in diag1 and i-c in diag2
for c in cols:
    for s in diag1:
        for d in diag2:
            if (s + d) % 2 == 0:
                i = (s + d) // 2
                j = (s - d) // 2
                if 1 <= i <= N and 1 <= j <= N and j == c:
                    total += 1

# R ∩ C ∩ D1 ∩ D2: (r,c) such that r+c in diag1 and r-c in diag2
quad = 0
for r in rows:
    for c in cols:
        if (r + c) in diag1 and (r - c) in diag2:
            quad += 1
total -= quad

# Now `total` is the number of squares attacked by at least one piece

# But note: some of these attacked squares may have pieces on them, but they are not empty anyway.
# We just need to subtract from total grid size.

# However, our calculation counts only attacked squares — regardless of whether they're occupied or not.
# But we are only allowed to place on **empty** squares that are **not attacked**.

# So answer = total empty squares - (attacked empty squares)
# But easier: total safe squares = (N*N - total_attacked_squares)

# But wait: our `total` is exactly the number of distinct squares that are attacked (via inclusion-exclusion).
# So the number of squares where we can safely place is:
#   total_safe = N*N - total

# However, we must ensure we didn't make logic error.

# But note: inclusion-exclusion computed the size of the union of all attacked squares.
# So yes.

ans = N * N - total

# However, we must consider: could it be negative? No, because total <= N*N.

print(ans)
N, M = map(int, input().split())
pieces = [tuple(map(int, input().split())) for _ in range(M)]

if M == 0:
    print(N * N)
else:
    # Sets to store attacked lines and diagonals
    rows = set()
    cols = set()
    diag1 = set()  # i + j
    diag2 = set()  # i - j

    for a, b in pieces:
        rows.add(a)
        cols.add(b)
        diag1.add(a + b)
        diag2.add(a - b)

    # Total squares under attack
    total_attacked = set()

    for a, b in pieces:
        # Add all squares in the same row
        for r in [a]:
            if r >= 1 and r <= N:
                for c in range(1, N + 1):
                    total_attacked.add((r, c))
        
        # Add all squares in the same column
        for c in [b]:
            if c >= 1 and c <= N:
                for r in range(1, N + 1):
                    total_attacked.add((r, c))

        # Add all squares in diagonal: i + j = a + b
        s = a + b
        for i in range(max(1, s - N), min(N, s - 1) + 1):
            j = s - i
            if 1 <= j <= N:
                total_attacked.add((i, j))

        # Add all squares in anti-diagonal: i - j = a - b
        d = a - b
        for i in range(max(1, 1 + d), min(N, N + d) + 1):
            j = i - d
            if 1 <= j <= N:
                total_attacked.add((i, j))

    # Count empty safe squares: total grid - (occupied or attacked)
    occupied_or_attacked = set(pieces) | total_attacked
    safe_squares = N * N - len(occupied_or_attacked)
    
    print(max(0, safe_squares))
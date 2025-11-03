N, M = map(int, input().split())
pieces = [tuple(map(int, input().split())) for _ in range(M)]

if M == 0:
    print(N * N)
else:
    # Sets to store attacked lines/diagonals
    rows = set()
    cols = set()
    diag1 = set()  # i + j
    diag2 = set()  # i - j

    for a, b in pieces:
        rows.add(a)
        cols.add(b)
        diag1.add(a + b)
        diag2.add(a - b)

    total_attacked = set()

    for a, b in pieces:
        # Add all cells in the same row
        for c in [(a, j) for j in cols]:
            total_attacked.add(c)
        # Add all cells in the same column
        for c in [(i, b) for i in rows]:
            total_attacked.add(c)
        # Add all cells in the same diagonal (a+b)
        s = a + b
        if s - 1 <= N:
            r_start = max(1, s - N)
            r_end = min(N, s - 1)
            for r in range(r_start, r_end + 1):
                c_val = s - r
                if 1 <= c_val <= N:
                    total_attacked.add((r, c_val))
        # Add all cells in the same anti-diagonal (a-b)
        d = a - b
        r_start = max(1, 1 + d)
        r_end = min(N, N + d)
        for r in range(r_start, r_end + 1):
            c_val = r - d
            if 1 <= c_val <= N:
                total_attacked.add((r, c_val))

    # Also include existing piece positions
    for pos in pieces:
        total_attacked.add(pos)

    # Count safe empty cells
    safe_count = 0
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if (i, j) not in total_attacked:
                safe_count += 1

    print(safe_count)
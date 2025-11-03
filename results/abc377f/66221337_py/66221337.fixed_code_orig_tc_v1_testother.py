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

    total_attacked = 0

    # Count unique squares attacked by row, column, and diagonal coverage
    # Use inclusion-exclusion principle

    # Add all squares in attacked rows
    total_attacked += len(rows) * N
    # Add all squares in attacked columns
    total_attacked += len(cols) * N
    # Add all squares in attacked main diagonals (i+j constant)
    for s in diag1:
        # Number of squares where i+j = s, with 1<=i<=N, 1<=j<=N
        if s < 2:
            continue
        elif s <= N + 1:
            total_attacked += s - 1
        else:
            total_attacked += 2 * N - s + 1
    # Add all squares in attacked anti-diagonals (i-j constant)
    for d in diag2:
        # Number of squares where i-j = d
        # i = j + d, with 1<=i<=N => 1<=j+d<=N => max(1,1-d) <= j <= min(N, N-d)
        low_j = max(1, 1 - d)
        high_j = min(N, N - d)
        if low_j <= high_j:
            total_attacked += high_j - low_j + 1

    # Subtract overcounted intersections: row ∩ col
    for r in rows:
        for c in cols:
            total_attacked -= 1

    # Subtract overcounted intersections: row ∩ diag1
    for r in rows:
        for s in diag1:
            c = s - r
            if 1 <= c <= N:
                total_attacked -= 1

    # Subtract overcounted intersections: row ∩ diag2
    for r in rows:
        for d in diag2:
            c = r - d
            if 1 <= c <= N:
                total_attacked -= 1

    # Subtract overcounted intersections: col ∩ diag1
    for c in cols:
        for s in diag1:
            r = s - c
            if 1 <= r <= N:
                total_attacked -= 1

    # Subtract overcounted intersections: col ∩ diag2
    for c in cols:
        for d in diag2:
            r = c + d
            if 1 <= r <= N:
                total_attacked -= 1

    # Subtract overcounted intersections: diag1 ∩ diag2
    for s in diag1:
        for d in diag2:
            # Solve: r + c = s, r - c = d  =>  r = (s+d)/2, c = (s-d)/2
            if (s + d) % 2 == 0:
                r = (s + d) // 2
                c = (s - d) // 2
                if 1 <= r <= N and 1 <= c <= N:
                    total_attacked -= 1

    # Add back triple intersections: row ∩ col ∩ diag1
    for r in rows:
        for c in cols:
            s = r + c
            if s in diag1:
                total_attacked += 1

    # Add back triple intersections: row ∩ col ∩ diag2
    for r in rows:
        for c in cols:
            d = r - c
            if d in diag2:
                total_attacked += 1

    # Add back triple intersections: row ∩ diag1 ∩ diag2
    for r in rows:
        for s in diag1:
            for d in diag2:
                if (s + d) % 2 == 0:
                    rr = (s + d) // 2
                    cc = (s - d) // 2
                    if rr == r and 1 <= cc <= N:
                        total_attacked += 1

    # Add back triple intersections: col ∩ diag1 ∩ diag2
    for c in cols:
        for s in diag1:
            for d in diag2:
                if (s + d) % 2 == 0:
                    rr = (s + d) // 2
                    cc = (s - d) // 2
                    if cc == c and 1 <= rr <= N:
                        total_attacked += 1

    # Add back quadruple intersections: row ∩ col ∩ diag1 ∩ diag2
    for r in rows:
        for c in cols:
            s = r + c
            d = r - c
            if s in diag1 and d in diag2:
                total_attacked -= 1

    # The above inclusion-exclusion counts every square that is under attack at least once.
    # But we must subtract the original piece positions because they are not empty.
    # However, note: our attack count includes occupied squares. We want only empty safe squares.
    # So: safe_empty_squares = total_empty_squares - (attacked_empty_squares)
    # But easier: total_safe_squares = N*N - (set of all attacked squares including occupied ones)
    # But wait: a square may be attacked even if occupied. We cannot place on non-empty squares anyway.

    # Actually, our `total_attacked` from inclusion-exclusion counts the number of distinct squares
    # that lie in any attacked row, column, or diagonal — this is exactly the union of all attacked squares.
    # Let U = |union of all attacked squares| = total_attacked_after_IE
    # Then answer = N*N - U, because:
    #   - All squares in U are unsafe (either attacked or occupied doesn't matter — you can't place there safely)
    #   - But note: some squares in U are occupied, but we already cannot use them.
    #   - And unoccupied squares not in U are safe.

    # However, the inclusion-exclusion above was meant to compute |U|.
    # But we did it via adding and subtracting counts — so we must ensure it's correct.

    # Actually, the standard way is to compute the union size using inclusion-exclusion:
    # |R ∪ C ∪ D1 ∪ D2| = 
    #   |R| + |C| + |D1| + |D2|
    # - |R∩C| - |R∩D1| - |R∩D2| - |C∩D1| - |C∩D2| - |D1∩D2|
    # + |R∩C∩D1| + |R∩C∩D2| + |R∩D1∩D2| + |C∩D1∩D2|
    # - |R∩C∩D1∩D2|

    # We have computed:
    #   S1 = |R| + |C| + |D1| + |D2|
    #   S2 = |R∩C| + |R∩D1| + |R∩D2| + |C∩D1| + |C∩D2| + |D1∩D2|
    #   S3 = |R∩C∩D1| + |R∩C∩D2| + |R∩D1∩D2| + |C∩D1∩D2|
    #   S4 = |R∩C∩D1∩D2|

    # So |U| = S1 - S2 + S3 - S4

    # But in our code above:
    #   total_attacked starts as S1
    #   then we subtract each pairwise intersection -> now it's S1 - S2
    #   then we add back each triple intersection -> now it's S1 - S2 + S3
    #   then we subtract quadruple -> now it's S1 - S2 + S3 - S4

    # So total_attacked is exactly |U|

    safe_squares = N * N - total_attacked
    print(safe_squares)
python
N, M = map(int, input().split())
pieces = [tuple(map(int, input().split())) for _ in range(M)]

if M == 0:
    print(N * N)
else:
    # Sets to store occupied lines (row, col, diag1: i+j, diag2: i-j)
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

    # Count all squares attacked by at least one piece
    # Use inclusion-exclusion is too expensive, so we use coordinate compression on events
    # But note: N up to 1e9, M only up to 1000 -> we can consider candidate cells?

    # Instead: compute total attacked cells using union of lines
    # Each piece attacks: row, col, diag1, diag2
    # But overlapping lines must be deduplicated.

    # Total attacked = union of all rows, cols, diag1s, diag2s

    # However, direct union over coordinates is impossible due to large N.
    # Instead, we calculate the union size using inclusion exclusion among lines.

    # Let R = number of distinct rows covered
    # Let C = number of distinct cols covered
    # Let D1 = number of distinct diag1 (i+j) covered
    # Let D2 = number of distinct diag2 (i-j) covered

    R = len(rows)
    C = len(cols)
    D1 = len(diag1)
    D2 = len(diag2)

    # Now compute intersections between each pair of line types
    from itertools import product

    # We need to subtract overcounts from inclusion-exclusion

    # |R ∪ C ∪ D1 ∪ D2| = 
    #   |R|*N + |C|*N + |D1|*len_diag + |D2|*len_diag
    # - |R∩C| - |R∩D1| - |R∩D2| - |C∩D1| - |C∩D2| - |D1∩D2|
    # + |R∩C∩D1| + |R∩C∩D2| + |R∩D1∩D2| + |C∩D1∩D2|
    # - |R∩C∩D1∩D2|

    # But easier: iterate over all unique rows, cols, diag1, diag2 and collect candidate points?
    # That would be O(M*N), too slow.

    # Alternative: use principle that total attacked cells = sum of sizes of lines minus overlaps.
    # But overlaps are hard.

    # Better idea: since M <= 1000, the number of distinct lines is at most 4*M = 4000.
    # But each line has up to N points -> total union cannot be computed directly.

    # Instead, we use the inclusion–exclusion formula over the four sets:

    # Let A = union of all attacked cells.
    # Then |A| = Σ|line| - Σ|line_i ∩ line_j| + Σ|line_i ∩ line_j ∩ line_k| - |line_i ∩ line_j ∩ line_k ∩ line_l|

    # There are 4 types: R, C, D1, D2.

    lines = []

    # Add row lines
    for r in rows:
        lines.append(('r', r))

    # Add col lines
    for c in cols:
        lines.append(('c', c))

    # Add diag1 lines: i+j = s
    for s in diag1:
        lines.append(('d1', s))

    # Add diag2 lines: i-j = d
    for d in diag2:
        lines.append(('d2', d))

    total = 0
    n_lines = len(lines)

    # We'll do inclusion exclusion up to 4-way, but with care about geometry

    # Single lines
    for typ, val in lines:
        if typ == 'r':
            total += N
        elif typ == 'c':
            total += N
        elif typ == 'd1':
            # i+j = val, 1<=i<=N, 1<=j<=N
            # i from max(1, val-N) to min(N, val-1)
            low = max(1, val - N)
            high = min(N, val - 1)
            if low <= high:
                total += high - low + 1
        elif typ == 'd2':
            # i-j = val => i = j + val
            # j from max(1, 1-val) to min(N, N-val)
            low_j = max(1, 1 - val)
            high_j = min(N, N - val)
            if low_j <= high_j:
                total += high_j - low_j + 1

    # Subtract pairwise intersections
    for i in range(n_lines):
        for j in range(i+1, n_lines):
            t1, v1 = lines[i]
            t2, v2 = lines[j]
            cnt = 0
            if t1 == 'r' and t2 == 'c':
                # row v1, col v2 -> point (v1, v2)
                if 1 <= v1 <= N and 1 <= v2 <= N:
                    cnt = 1
            elif t1 == 'r' and t2 == 'd1':
                # row v1, diag1 v2: i=v1, i+j=v2 -> j = v2 - v1
                j = v2 - v1
                if 1 <= j <= N:
                    cnt = 1
            elif t1 == 'r' and t2 == 'd2':
                # row v1, diag2 v2: i=v1, i-j=v2 -> j = v1 - v2
                j = v1 - v2
                if 1 <= j <= N:
                    cnt = 1
            elif t1 == 'c' and t2 == 'd1':
                # col v1, diag1 v2: j=v1, i+j=v2 -> i = v2 - v1
                i = v2 - v1
                if 1 <= i <= N:
                    cnt = 1
            elif t1 == 'c' and t2 == 'd2':
                # col v1, diag2 v2: j=v1, i-j=v2 -> i = v2 + v1
                i = v2 + v1
                if 1 <= i <= N:
                    cnt = 1
            elif t1 == 'd1' and t2 == 'd2':
                # diag1 v1, diag2 v2: i+j=v1, i-j=v2
                # 2i = v1+v2 -> i = (v1+v2)/2, j = (v1-v2)/2
                if (v1 + v2) % 2 == 0:
                    i = (v1 + v2) // 2
                    j = (v1 - v2) // 2
                    if 1 <= i <= N and 1 <= j <= N:
                        cnt = 1
            total -= cnt

    # Add back triple intersections
    for i in range(n_lines):
        for j in range(i+1, n_lines):
            for k in range(j+1, n_lines):
                t1, v1 = lines[i]
                t2, v2 = lines[j]
                t3, v3 = lines[k]
                cnt = 0
                # We solve for (i,j) satisfying all three
                # There can be at most one solution.

                # Try to determine i and j from the three equations.
                # Cases:
                if t1 == 'r' and t2 == 'c':
                    i_val, j_val = v1, v2
                    # Check against t3
                    valid = True
                    if t3 == 'd1' and i_val + j_val != v3:
                        valid = False
                    elif t3 == 'd2' and i_val - j_val != v3:
                        valid = False
                    if valid and 1 <= i_val <= N and 1 <= j_val <= N:
                        cnt = 1
                elif t1 == 'r' and t2 == 'd1':
                    i_val = v1
                    j_val = v2 - v1
                    if t3 == 'c' and j_val != v3:
                        continue
                    elif t3 == 'd2' and i_val - j_val != v3:
                        continue
                    if 1 <= j_val <= N and 1 <= i_val <= N:
                        cnt = 1
                elif t1 == 'r' and t2 == 'd2':
                    i_val = v1
                    j_val = v1 - v2
                    if t3 == 'c' and j_val != v3:
                        continue
                    elif t3 == 'd1' and i_val + j_val != v3:
                        continue
                    if 1 <= j_val <= N and 1 <= i_val <= N:
                        cnt = 1
                elif t1 == 'c' and t2 == 'd1':
                    j_val = v1
                    i_val = v2 - v1
                    if t3 == 'r' and i_val != v3:
                        continue
                    elif t3 == 'd2' and i_val - j_val != v3:
                        continue
                    if 1 <= i_val <= N and 1 <= j_val <= N:
                        cnt = 1
                elif t1 == 'c' and t2 == 'd2':
                    j_val = v1
                    i_val = v2 + v1
                    if t3 == 'r' and i_val != v3:
                        continue
                    elif t3 == 'd1' and i_val + j_val != v3:
                        continue
                    if 1 <= i_val <= N and 1 <= j_val <= N:
                        cnt = 1
                elif t1 == 'd1' and t2 == 'd2':
                    if (v1 + v2) % 2 == 0:
                        i_val = (v1 + v2) // 2
                        j_val = (v1 - v2) // 2
                        if t3 == 'r' and i_val != v3:
                            continue
                        elif t3 == 'c' and j_val != v3:
                            continue
                        if 1 <= i_val <= N and 1 <= j_val <= N:
                            cnt = 1
                total += cnt

    # Subtract quadruple intersections
    for i in range(n_lines):
        for j in range(i+1, n_lines):
            for k in range(j+1, n_lines):
                for l in range(k+1, n_lines):
                    t1, v1 = lines[i]
                    t2, v2 = lines[j]
                    t3, v3 = lines[k]
                    t4, v4 = lines[l]
                    cnt = 0
                    # Solve the system — there can be at most one point.
                    # Use two equations to find candidate, check against others.
                    # Prefer using row/col or diag pairs.

                    # Try to get candidate from first two
                    candidate = None
                    if t1 == 'r' and t2 == 'c':
                        candidate = (v1, v2)
                    elif t1 == 'r' and t2 == 'd1':
                        j = v2 - v1
                        candidate = (v1, j)
                    elif t1 == 'r' and t2 == 'd2':
                        j = v1 - v2
                        candidate = (v1, j)
                    elif t1 == 'c' and t2 == 'd1':
                        i = v2 - v1
                        candidate = (i, v1)
                    elif t1 == 'c' and t2 == 'd2':
                        i = v2 + v1
                        candidate = (i, v1)
                    elif t1 == 'd1' and t2 == 'd2':
                        if (v1 + v2) % 2 == 0:
                            i = (v1 + v2) // 2
                            j = (v1 - v2) // 2
                            candidate = (i, j)
                    if candidate is None:
                        # Try next pair? Actually, any two should determine at most one point.
                        # But if no pair gives candidate, skip.
                        continue

                    i_val, j_val = candidate
                    if not (1 <= i_val <= N and 1 <= j_val <= N):
                        continue

                    # Check against t3 and t4
                    match3 = False
                    if t3 == 'r' and i_val == v3:
                        match3 = True
                    elif t3 == 'c' and j_val == v3:
                        match3 = True
                    elif t3 == 'd1' and i_val + j_val == v3:
                        match3 = True
                    elif t3 == 'd2' and i_val - j_val == v3:
                        match3 = True

                    match4 = False
                    if t4 == 'r' and i_val == v4:
                        match4 = True
                    elif t4 == 'c' and j_val == v4:
                        match4 = True
                    elif t4 == 'd1' and i_val + j_val == v4:
                        match4 = True
                    elif t4 == 'd2' and i_val - j_val == v4:
                        match4 = True

                    if match3 and match4:
                        cnt = 1

                    total -= cnt

    # But wait: some attacked cells may be occupied by existing pieces, but we don't want to count them multiple times?
    # No: the attacked set includes all cells under attack, regardless of occupancy.
    # However, we are counting every cell that lies on any attacking line.

    # But: the above inclusion-exclusion counts the union of all lines — that is exactly the set of attacked cells.

    # However, note: a cell might be attacked by multiple pieces, but we count it once.

    # So total_attacked = total (from inclusion-exclusion)

    # But: we must not place on occupied cells. However, occupied cells are already included in attacked cells?
    # Yes: each piece's cell is attacked by itself (same row, etc.), so they are included.

    # Therefore, the safe empty squares = total grid - attacked cells
    # But wait: what if an empty square is not attacked? It should be allowed.

    # So answer = N*N - total_attacked

    # However, let's test with small case.

    # But note: our inclusion-exclusion counts every cell that is on at least one of the lines defined by the pieces.
    # That is correct.

    print(N * N - total)
from collections import defaultdict

def main():
    import sys
    data = sys.stdin.read().split()
    N = int(data[0])
    M = int(data[1])
    
    if M == 0:
        print(N * N)
        return
        
    pieces = []
    rows = set()
    cols = set()
    diag1 = set()  # i + j
    diag2 = set()  # i - j
    
    index = 2
    for _ in range(M):
        a = int(data[index])
        b = int(data[index + 1])
        index += 2
        pieces.append((a, b))
        rows.add(a)
        cols.add(b)
        diag1.add(a + b)
        diag2.add(a - b)
    
    # Total squares attacked by all pieces (union of all lines)
    total_attacked = set()
    
    for a, b in pieces:
        # We cannot iterate over entire rows/cols/diags when N is up to 1e9
        # Instead, we calculate the union size using inclusion-exclusion on sets of lines
        pass
    
    # Instead: compute total attacked via inclusion-exclusion over row, col, diag1, diag2 lines
    # But avoid double counting intersections
    
    # Use principle: |R ∪ C ∪ D1 ∪ D2| = |R| + |C| + |D1| + |D2| 
    #                - |R∩C| - |R∩D1| - |R∩D2| - |C∩D1| - |C∩D2| - |D1∩D2|
    #                + ... → too complex
    
    # Alternate approach:
    # Since M <= 1000, we can collect all attacked positions that are duplicates
    # BUT N can be 1e9 so we cannot enumerate positions.
    
    # Correct idea:
    # Total attacked = (# of distinct rows) * N + (# of distinct cols) * N + 
    #                  (# of distinct diag1) * avg_len + (# of distinct diag2) * avg_len
    # but subtract overlaps.

    # Better: use inclusion exclusion with sets of lines.
    R = len(rows)
    C = len(cols)
    D1 = len(diag1)
    D2 = len(diag2)
    
    # Now subtract pairwise intersections
    RC = 0  # cells in both some row and some col → intersections of specific (r,c)
    RD1 = 0
    RD2 = 0
    CD1 = 0
    CD2 = 0
    D1D2 = 0
    
    # Intersections between two lines contribute overlap counts
    
    # Every row and every col intersect exactly once → R*C points in R∩C
    # But only if they are within bounds? They always are since r∈[1,N], c∈[1,N]
    RC = R * C
    
    # Each row intersects each diag1: row=r, diag1=s → cell (r, s-r), valid if 1<=s-r<=N
    for r in rows:
        for s in diag1:
            c = s - r
            if 1 <= c <= N:
                RD1 += 1
    
    # Each row and diag2: row=r, diag2=d → (r, r-d), valid if 1<=r-d<=N
    for r in rows:
        for d in diag2:
            c = r - d
            if 1 <= c <= N:
                RD2 += 1
                
    # Each col and diag1: col=c, diag1=s → (s-c, c), valid if 1<=s-c<=N
    for c in cols:
        for s in diag1:
            r = s - c
            if 1 <= r <= N:
                CD1 += 1
                
    # Each col and diag2: col=c, diag2=d → (c+d, c), valid if 1<=c+d<=N
    for c in cols:
        for d in diag2:
            r = c + d
            if 1 <= r <= N:
                CD2 += 1
                
    # Each diag1 and diag2: solve r+c = s, r-c = d → r=(s+d)/2, c=(s-d)/2
    # Valid if r,c ∈ [1,N] and integer
    for s in diag1:
        for d in diag2:
            if (s + d) % 2 == 0:
                r = (s + d) // 2
                c = (s - d) // 2
                if 1 <= r <= N and 1 <= c <= N:
                    D1D2 += 1
    
    # Triple intersections
    RCD1 = 0
    RCD2 = 0
    RD1D2 = 0
    CD1D2 = 0
    
    # R∩C∩D1: cell (r,c) where r∈rows, c∈cols, r+c ∈ diag1
    for r in rows:
        for c in cols:
            if (r + c) in diag1:
                RCD1 += 1
                
    for r in rows:
        for c in cols:
            if (r - c) in diag2:
                RCD2 += 1
                
    # R∩D1∩D2: fixed r, solve r+c=s, r-c=d → c=s-r, and d=r-c=r-(s-r)=2r-s → must have d=2r-s
    for r in rows:
        for s in diag1:
            c = s - r
            if 1 <= c <= N:
                d = r - c
                if d in diag2:
                    RD1D2 += 1
                    
    # C∩D1∩D2: fixed c, r+c=s → r=s-c, d=r-c=s-2c → check if d in diag2
    for c in cols:
        for s in diag1:
            r = s - c
            if 1 <= r <= N:
                d = r - c
                if d in diag2:
                    CD1D2 += 1
                    
    # Quadruple intersection: R∩C∩D1∩D2
    RCD1D2 = 0
    for r in rows:
        for c in cols:
            if (r + c) in diag1 and (r - c) in diag2:
                RCD1D2 += 1
    
    # Inclusion-Exclusion for four sets
    total_attacked_size = (
        R * N + C * N + 
        sum(min(s - 1, N, N, 2*N - s + 1) for s in diag1) +   # length of diag1: s from 2 to 2N
        sum(min(d + N, N, N, N - d) for d in diag2)           # length of diag2: d from -(N-1) to N-1
    )
    
    # But above line lengths are not simply added — we need to recompute properly
    
    # Let's instead calculate the union by inclusion-exclusion:
    # |A∪B∪C∪D| = Σ|single| - Σ|pair| + Σ|triple| - |quad|
    
    # First, compute total area covered by any row, col, diag1, diag2
    singles = (
        R * N + 
        C * N + 
        sum(min(s-1, 2*N-s+1, N) for s in diag1) + 
        sum(min(N + d, 2*N - d, N) for d in diag2)  # wait, better formula
    )
    
    # Actually, length of diagonal i+j=s is:
    # if s <= N+1: s-1
    # else: 2*N - s + 1
    def get_diag1_len(s):
        if s < 2 or s > 2*N:
            return 0
        return s - 1 if s <= N + 1 else 2*N - s + 1
    
    # Length of diagonal i-j=d:
    # d ranges from -(N-1) to (N-1)
    # number of solutions: N - |d|
    def get_diag2_len(d):
        if d < -(N-1) or d > N-1:
            return 0
        return N - abs(d)
    
    singles = 0
    singles += R * N
    singles += C * N
    singles += sum(get_diag1_len(s) for s in diag1)
    singles += sum(get_diag2_len(d) for d in diag2)
    
    pairs = RC + RD1 + RD2 + CD1 + CD2 + D1D2
    
    triples = RCD1 + RCD2 + RD1D2 + CD1D2
    
    quad = RCD1D2
    
    total_attacked_size = singles - pairs + triples - quad
    
    # However, this inclusion-exclusion counts every grid point with multiplicity equal to how many sets it belongs to
    # But we want the *size* of the union, not weighted sum!
    # So this method fails.
    
    # Correct approach: The attacked region is the union of:
    # - all full rows r where r ∈ rows
    # - all full cols c where c ∈ cols
    # - all full diag1 s where s ∈ diag1
    # - all full diag2 d where d ∈ diag2
    #
    # We want |∪|
    #
    # Standard way: use inclusion exclusion:
    # |R ∪ C ∪ D1 ∪ D2| = 
    #   |R| + |C| + |D1| + |D2|
    #   - |R∩C| - |R∩D1| - |R∩D2| - |C∩D1| - |C∩D2| - |D1∩D2|
    #   + |R∩C∩D1| + |R∩C∩D2| + |R∩D1∩D2| + |C∩D1∩D2|
    #   - |R∩C∩D1∩D2|
    #
    # Where:
    # |R| = R * N
    # |C| = C * N
    # |D1| = sum_{s∈diag1} get_diag1_len(s)
    # |D2| = sum_{d∈diag2} get_diag2_len(d)
    #
    # |R∩C| = number of (r,c) with r∈rows, c∈cols = R*C
    # |R∩D1| = number of (r,x) such that r∈rows, x=s-r for s∈diag1 and 1<=x<=N
    #         = for each r,s: count valid c
    #         = as before: RD1 computed earlier
    # Similarly for others.
    #
    # And so on.
    #
    # So:
    total_union = (
        (R * N) +
        (C * N) +
        sum(get_diag1_len(s) for s in diag1) +
        sum(get_diag2_len(d) for d in diag2)
        -
        (RC + RD1 + RD2 + CD1 + CD2 + D1D2)
        +
        (RCD1 + RCD2 + RD1D2 + CD1D2)
        -
        RCD1D2
    )
    
    # But wait: inclusion-exclusion formula is:
    # |A∪B∪C∪D| = Σ|A| - Σ|A∩B| + Σ|A∩B∩C| - |A∩B∩C∩D|
    # Here A,B,C,D are the unions themselves. But our terms like |R| are already unions.
    # Actually no: we are treating R as one set (union of full rows), etc.
    # But the standard IE applies to union of sets.
    #
    # However, the issue is that |R| = sum_{r∈rows} |row_r|, but then |R∩C| = sum_{r,c} |row_r ∩ col_c|, etc.
    # This is correct.
    #
    # But note: this formula gives the exact size of the union of all attacked squares.
    
    attacked_count = total_union
    
    # But we must ensure no square is counted beyond its presence
    # The above inclusion-exclusion should be correct.
    
    # However, there's a catch: a piece might lie at intersection, but we are just computing geometric union
    # So it's fine.
    
    # Finally, remove squares that are occupied (they are attacked but cannot be placed anyway)
    # But the question asks for empty squares that are NOT attacked
    # So:
    # available = total_empty_squares - (attacked squares that are empty)
    #          = (N*N - M) - (attacked_count - |occupied ∩ attacked|)
    #
    # But all occupied squares are attacked (by their own row/col/diag), so |occupied ∩ attacked| = M
    # Thus:
    # empty_attacked = attacked_count - M
    # available = (N*N - M) - (attacked_count - M) = N*N - attacked_count
    #
    # But wait: is every occupied square counted in attacked_count?
    # Yes, because each piece at (a,b) contributes to row a, which is included, so (a,b) is in attacked_count.
    #
    # However, could a piece be counted multiple times? Yes, but attacked_count is the *size of union*, so each cell only once.
    # So yes, each occupied square is in attacked_count.
    #
    # Therefore, the number of unattacked **and** empty squares is:
    #   total_squares - attacked_count
    # because unattacked squares are automatically empty of existing pieces? No: they might be non-empty but we don't care — we can't place on non-empty anyway.
    #
    # We want: squares that are (empty) AND (not attacked)
    # = total_squares - (attacked OR non-empty)
    # = N*N - |attacked ∪ occupied|
    #
    # But occupied ⊆ attacked (since each piece attacks its own position via its row/col/etc.), so
    # attacked ∪ occupied = attacked
    #
    # Therefore:
    result = N * N - attacked_count
    
    # However, result must be non-negative
    result = max(0, result)
    
    print(result)

if __name__ == '__main__':
    main()
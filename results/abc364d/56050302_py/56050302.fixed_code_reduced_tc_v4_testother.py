import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

results = []
for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted in sorted array a
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from both left and right sides around pos
    # Use two pointers expanding outwards from pos-1 and pos
    left = pos - 1
    right = pos
    
    distances = []
    
    # Instead of collecting all N distances (which is too slow),
    # we can simulate finding the k-th smallest distance
    # But since k can be up to N and we need exact k-th, we must consider efficient approach
    
    # However, note: we cannot avoid looking at potentially many points
    # But worst-case N=1e5, Q=1e5 -> total 10^10 operations if naive
    # So we need a better method.
    
    # Alternative idea: use binary search on answer (the distance)
    # For a given distance d, count how many A_i satisfy |a_i - b| <= d
    # Then find minimal d such that count >= k
    
    def count_points_within_distance(d):
        # Count number of points in a within distance d from b
        # i.e., count a_i such that b-d <= a_i <= b+d
        left_bound = b - d
        right_bound = b + d
        l_idx = bisect.bisect_left(a, left_bound)
        r_idx = bisect.bisect_right(a, right_bound)
        return r_idx - l_idx
    
    # Binary search on the answer (distance)
    lo = 0
    hi = 2 * 10**8  # max possible distance is 2e8 (from -1e8 to 1e8)
    
    while lo < hi:
        mid = (lo + hi) // 2
        if count_points_within_distance(mid) >= k:
            hi = mid
        else:
            lo = mid + 1
    
    results.append(lo)

for result in results:
    print(result)
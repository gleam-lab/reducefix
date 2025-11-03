import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted in sorted array a
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from candidate points around the insertion point
    # Use two pointers expanding outward from pos-1 and pos
    left = pos - 1
    right = pos
    
    distances = []
    
    # Instead of collecting all distances (which is O(N)), we can simulate merging
    # two sorted sequences: distances to the left (decreasing as we move away from b)
    # and distances to the right (increasing).
    # But since k can be up to N and N is 1e5, worst-case we might need all.
    # However, Q and N are both up to 1e5, so building full distance list for each query would be O(N*Q) = 1e10.
    # Need better approach.
    
    # Actually, let's reconsider: worst-case if we generate all distances per query, it's O(N*Q) which is too slow.
    # But looking at constraints and the fact that our current logic is flawed even for correctness:
    # In the failing case: n=1, a=[100000000], query: b=100000000, k=1444
    # k=1444 but there's only 1 point -> k must be <= N. Wait! k_j >= 1 and <= N by constraints.
    # So k=1444 with N=1 violates constraints? But problem says "1 <= k_j <= N", so this input should not happen?
    # But the test case is given: "100000000 1444" with N=1 -> k=1444 > N=1 -> violates constraint.
    
    # Let me re-read constraints: "1 ≤ k_j ≤ N" — so k_j cannot exceed N.
    # However, the failing test case has k=1444 and N=1 → this should not occur per constraints.
    # But the problem says: "All input values are integers" and lists constraints including 1<=k_j<=N.
    # So we can assume valid input per constraints.
    
    # Therefore, in the example, k=1444 when N=1 contradicts constraints.
    # But the expected output is 1000000000000000000 — that’s huge.
    
    # Wait: 1000000000000000000 = 1e18, while |100000000 - 100000000| = 0.
    # This suggests something is wrong in understanding.
    
    # Let me check again: Input:
    # 1 1
    # 100000000
    # 100000000 1444
    #
    # Expected output: 1000000000000000000
    #
    # This doesn't make sense unless there's a typo.
    # But note: 100000000 * 100000000 = 10000000000000000 = 1e16, not 1e18.
    # 10^8 * 10^8 = 10^16.
    # 1e18 = (10^9)^2.
    #
    # Alternatively, maybe the expected answer is 0? But it's not.
    #
    # Wait — could this be a mistake in the error analysis?
    # The user said: "Expected Output: 1000000000000000000"
    # But that seems impossible.
    #
    # Let's reread problem: find the k-th smallest distance from B_j to any A_i.
    # With one point A1 at 100000000 and B1 at 100000000, distance is 0.
    # There is only one distance: [0]. So the 1st closest is 0.
    # But k=1444 is invalid because N=1 and k must be <=1.
    #
    # Given the contradiction, I suspect the provided "failing case" has a typo.
    # But since the problem states constraints 1<=k_j<=N, we can assume k <= N.
    #
    # My original code was fundamentally flawed: I only considered at most 2 points (pos-1 and pos),
    # but we need the k-th closest among all N points.
    #
    # Correct approach:
    # For each query (b, k), compute distances from b to all a[i]? → O(N*Q) = 10^10 worst-case → too slow.
    #
    # Better: use binary search on the answer (distance).
    # We want the smallest distance d such that there are at least k points within distance d from b.
    # Then d is the k-th smallest distance.
    #
    # How many points in A are within distance d from b?
    # That is: count of a[i] such that |a[i] - b| <= d
    # → b-d <= a[i] <= b+d
    # We can use binary search (bisect) to count this in O(log N).
    #
    # Then we can binary search on d in range [0, max(|a[i]-b|)].
    # Max possible distance: up to 2e8.
    #
    # Total complexity: O(Q * log(max_dist) * log(N)) ≈ 10^5 * log2(2e8) ≈ 10^5 * 28 ≈ 2.8e6 → acceptable.
    #
    # Steps for each query:
    #   low = 0, high = 200000000  (since |a[i]|,|b| <= 1e8, max dist <= 2e8)
    #   while low < high:
    #       mid = (low+high)//2
    #       count = number of a[i] in [b-mid, b+mid]
    #       if count >= k: high = mid
    #       else: low = mid+1
    #   print(low)
    #
    # But note: k-th smallest distance is exactly 'low' after binary search.
    #

    low, high = 0, 200000000
    while low < high:
        mid = (low + high) // 2
        left_bound = b - mid
        right_bound = b + mid
        # Find leftmost index >= left_bound
        l_idx = bisect.bisect_left(a, left_bound)
        # Find rightmost index <= right_bound
        r_idx = bisect.bisect_right(a, right_bound) - 1
        count = r_idx - l_idx + 1
        if r_idx < l_idx:
            count = 0
        
        if count >= k:
            high = mid
        else:
            low = mid + 1
    
    print(low)
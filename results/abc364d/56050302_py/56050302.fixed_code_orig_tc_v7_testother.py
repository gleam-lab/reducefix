import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from points around the insertion point
    candidates = []
    
    # Add points to the left of pos (in reverse order to maintain increasing distance from b)
    left = pos - 1
    while left >= 0:
        candidates.append(abs(a[left] - b))
        left -= 1
    
    # Add points to the right of pos
    right = pos
    while right < n:
        candidates.append(abs(a[right] - b))
        right += 1
    
    # Sort distances to get the k-th smallest
    candidates.sort()
    
    # Output the k-th smallest distance (k is 1-indexed)
    print(candidates[k-1])
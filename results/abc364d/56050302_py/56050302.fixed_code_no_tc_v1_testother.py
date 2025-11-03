import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

results = []
for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted in sorted array a
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from points around the insertion point
    # But we need to find the k-th smallest distance, so we can't just take 1-2 points
    
    # Instead, we can use binary search on the answer (distance)
    # Or we can extract all distances? -> Too slow for N, Q up to 10^5
    
    # Better approach: Use two pointers expanding from the insertion point
    left = pos - 1  # index of largest element <= b
    right = pos     # index of smallest element >= b
    
    # We'll simulate getting the first k closest points by expanding outward
    for step in range(k):
        # Check if we can take from left and/or right
        if left >= 0 and right < n:
            # Take the closer one
            if abs(a[left] - b) <= abs(a[right] - b):
                chosen_dist = abs(a[left] - b)
                left -= 1
            else:
                chosen_dist = abs(a[right] - b)
                right += 1
        elif left >= 0:
            chosen_dist = abs(a[left] - b)
            left -= 1
        elif right < n:
            chosen_dist = abs(a[right] - b)
            right += 1
        else:
            chosen_dist = 0  # Should not happen when k <= N
    
    results.append(chosen_dist)

for result in results:
    print(result)
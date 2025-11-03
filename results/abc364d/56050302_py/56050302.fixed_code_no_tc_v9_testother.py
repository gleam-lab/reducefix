import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted in sorted array a
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from points around the insertion point
    # But instead of just left and right, we need to consider more points
    # to find the k-th smallest distance
    
    # Use two pointers expanding from the insertion point
    left = pos - 1  # index of largest element <= b
    right = pos     # index of smallest element >= b
    
    # We'll simulate finding k closest points by expanding outward
    count = 0
    result = 0
    
    while count < k:
        # Check if we can take from left or right
        if left >= 0 and right < n:
            # Both sides have elements, pick the closer one
            dist_left = abs(a[left] - b)
            dist_right = abs(a[right] - b)
            if dist_left <= dist_right:
                result = dist_left
                left -= 1
            else:
                result = dist_right
                right += 1
        elif left >= 0:
            # Only left side has elements
            result = abs(a[left] - b)
            left -= 1
        elif right < n:
            # Only right side has elements
            result = abs(a[right] - b)
            right += 1
        count += 1
        
    print(result)
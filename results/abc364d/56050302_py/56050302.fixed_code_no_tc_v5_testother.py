import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted in sorted array a
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from points around the insertion point
    # But instead of just checking neighbors, we need to consider more points
    
    # Use two pointers expanding from the insertion point
    left = pos - 1  # index of largest element <= b
    right = pos     # index of smallest element >= b
    
    # We want to find the k-th smallest distance
    count = 0
    
    while count < k:
        # Check which side gives smaller distance
        if left >= 0 and right < n:
            dist_left = abs(a[left] - b)
            dist_right = abs(a[right] - b)
            if dist_left <= dist_right:
                chosen_dist = dist_left
                left -= 1
            else:
                chosen_dist = dist_right
                right += 1
        elif left >= 0:
            chosen_dist = abs(a[left] - b)
            left -= 1
        elif right < n:
            chosen_dist = abs(a[right] - b)
            right += 1
        else:
            break
            
        count += 1
        
        if count == k:
            print(chosen_dist)
            break
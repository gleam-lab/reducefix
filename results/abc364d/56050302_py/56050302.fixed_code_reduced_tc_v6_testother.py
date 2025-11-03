import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from candidates around the insertion point
    # But we don't need to collect all distances at once
    # Instead, we can use two pointers expanding from the closest point
    
    left = pos - 1   # index of largest element <= b
    right = pos      # index of smallest element >= b
    
    count = 0
    result = 0
    
    # We need the k-th smallest distance
    while count < k:
        # Check which side gives smaller distance
        if left >= 0 and right < n:
            dist_left = abs(a[left] - b)
            dist_right = abs(a[right] - b)
            if dist_left <= dist_right:
                result = dist_left
                left -= 1
            else:
                result = dist_right
                right += 1
        elif left >= 0:
            result = abs(a[left] - b)
            left -= 1
        elif right < n:
            result = abs(a[right] - b)
            right += 1
        count += 1
        
    print(result)
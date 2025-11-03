import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted
    pos = bisect.bisect_left(a, b)
    
    # We'll collect distances from points around the insertion point
    # Consider points to the left and right of the insertion position
    candidates = []
    
    # Add points from the left side (decreasing index)
    left = pos - 1
    while left >= 0:
        candidates.append(abs(a[left] - b))
        left -= 1
    
    # Add points from the right side (increasing index) 
    right = pos
    while right < n:
        candidates.append(abs(a[right] - b))
        right += 1
    
    # Sort the distances to find the k-th smallest
    candidates.sort()
    
    # k is 1-indexed, so we want the (k-1)-th element
    print(candidates[k-1])
import bisect

n, q = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

for _ in range(q):
    b, k = map(int, input().split())
    
    # Find the position where b would be inserted
    pos = bisect.bisect_left(a, b)
    
    # We need to consider points around the insertion position
    candidates = []
    
    # Add points from the right side (pos to end)
    for i in range(pos, min(pos + k, n)):
        candidates.append(abs(a[i] - b))
    
    # Add points from the left side (pos-1 down to 0)
    for i in range(pos - 1, max(pos - k - 1, -1), -1):
        candidates.append(abs(a[i] - b))
    
    # Sort the distances and get the k-th smallest
    candidates.sort()
    print(candidates[k - 1])
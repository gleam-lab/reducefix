import sys

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    # We need to remove exactly K elements, so we keep (n - k) elements.
    # To minimize (max(B) - min(B)), we should choose a contiguous subsequence
    # in the sorted array of length (n - k), because the optimal set of elements 
    # will lie within some interval [x, y] with minimal difference.
    
    A.sort()
    window_size = n - k
    min_diff = float('inf')
    
    for i in range(n - window_size + 1):
        j = i + window_size - 1
        diff = A[j] - A[i]
        if diff < min_diff:
            min_diff = diff
    
    print(min_diff)

solve()
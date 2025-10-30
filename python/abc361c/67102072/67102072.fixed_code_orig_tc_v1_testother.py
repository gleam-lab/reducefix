import sys

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    # We are removing exactly K elements, so we keep (n - k) elements.
    # To minimize (max(B) - min(B)), we should consider contiguous subarrays
    # of the sorted array, because the optimal remaining elements will be consecutive
    # in sorted order (otherwise we could get a smaller range by shifting).
    
    A.sort()
    m = n - k  # size of B
    
    if m == 1:
        print(0)
        return
    
    # Try all contiguous subarrays of length m in the sorted array
    min_diff = float('inf')
    for i in range(n - m + 1):
        diff = A[i + m - 1] - A[i]
        if diff < min_diff:
            min_diff = diff
    
    print(min_diff)

if __name__ == "__main__":
    main()
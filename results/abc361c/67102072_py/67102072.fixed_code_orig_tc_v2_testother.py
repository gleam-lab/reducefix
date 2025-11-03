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
    # of length (n - k) in the sorted array, but preserving original order isn't needed
    # because we can choose any K elements to remove. So optimal strategy:
    # Sort the array, then try all contiguous subarrays of length (n - k)
    
    A.sort()
    m = n - k  # size of B
    if m == 1:
        print(0)
        return
    
    min_diff = float('inf')
    for i in range(n - m + 1):
        diff = A[i + m - 1] - A[i]
        if diff < min_diff:
            min_diff = diff
    
    print(min_diff)

if __name__ == "__main__":
    main()
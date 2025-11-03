n, k = map(int, input().split())
A = list(map(int, input().split()))

# Sort the array to enable sliding window on sorted values
A.sort()

# We are removing exactly K elements, so we keep (n - k) elements
# To minimize (max - min) of the remaining sequence, we want to choose a contiguous segment of (n - k) elements in sorted order
# Because if the chosen elements are not contiguous, we can always shift to get a smaller or equal range

min_diff = float('inf')
window_size = n - k

for i in range(n - window_size + 1):
    j = i + window_size - 1
    diff = A[j] - A[i]
    if diff < min_diff:
        min_diff = diff

print(min_diff)
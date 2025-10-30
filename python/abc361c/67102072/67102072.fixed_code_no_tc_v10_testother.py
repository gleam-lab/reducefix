n, k = map(int, input().split())
A = list(map(int, input().split()))

# We are removing exactly K elements, so we keep (n - k) elements.
# We want to minimize (max(B) - min(B)) for the remaining sequence B.

# Sort the array to consider candidates efficiently.
A.sort()

# The remaining elements must be a contiguous subarray in the sorted order
# to minimize the difference between max and min.
# Why? Because if we skip non-contiguous elements, we can always get a smaller or equal range by taking a contiguous block.

# We try all possible contiguous subarrays of length (n - k)
min_diff = float('inf')
length = n - k

for i in range(n - length + 1):
    j = i + length - 1
    diff = A[j] - A[i]
    if diff < min_diff:
        min_diff = diff

print(min_diff)
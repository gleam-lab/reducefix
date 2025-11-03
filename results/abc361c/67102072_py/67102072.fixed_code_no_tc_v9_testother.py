n, k = map(int, input().split())
A = list(map(int, input().split()))

# Sort the array to consider elements in increasing order
A.sort()

# We are removing exactly K elements, so we keep (n - k) elements.
# To minimize (max(B) - min(B)), we should choose a contiguous subsequence of length (n - k)
# from the sorted array. Why? Because any non-contiguous selection would have a larger range.

min_range = float('inf')
length = n - k

# Try every possible contiguous subarray of length (n - k)
for i in range(n - length + 1):
    j = i + length - 1
    current_range = A[j] - A[i]
    if current_range < min_range:
        min_range = current_range

print(min_range)
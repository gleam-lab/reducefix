n, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort()

# We are removing exactly K elements, so we keep (n - k) elements.
# We want to minimize (max(B) - min(B)) where B is a subsequence of a with (n-k) elements in original order.
# But since we can choose any K elements to remove, and we care only about the values (not indices for value diff),
# we can sort A and consider contiguous subarrays of length (n-k) — because the smallest range comes from consecutive values.

# After sorting, any kept elements will form a contiguous block in sorted order to minimize max-min.
# So we try all contiguous subarrays of length (n - k)

if n - k == 1:
    print(0)
else:
    min_diff = float('inf')
    window_size = n - k
    for i in range(n - window_size + 1):
        diff = a[i + window_size - 1] - a[i]
        if diff < min_diff:
            min_diff = diff
    print(min_diff)
n, k = map(int, input().split())
A = list(map(int, input().split()))

# We are removing exactly K elements, so we keep (n - k) elements.
# To minimize (max(B) - min(B)), we should choose a contiguous subsequence of the sorted array,
# because the optimal remaining elements will be consecutive in value.

# Sort the array along with original indices to preserve order? 
# But note: we must preserve the original order when forming B — however, since we can choose any K to remove,
# and we want to minimize max - min, the best set of values to keep must be close in value.

# Insight: We can sort the array, but then consider all contiguous segments of length (n-k) in the sorted array.
# However, after removal, the remaining elements must appear in the original order. 
# BUT: we are allowed to remove arbitrary elements. So if we decide to keep a set S of values, 
# as long as they appear in increasing index order in the original array, we can form B.

# However, here's a key observation:
# The final sequence B is formed by keeping some elements in their original order.
# But the value (max(B) - min(B)) depends only on which values we keep, not their positions.
# To minimize this difference, we would like to keep values that are close together.

# Alternate approach:
# Since we can remove any K elements, we can choose which (n-k) elements to keep.
# We want to minimize (max(kept) - min(kept)).
# So we can sort the array, and consider every contiguous segment of length (n-k) in the sorted array.
# For each such segment, check whether the corresponding elements (with these values) appear in the original array 
# in an order that allows them to form a valid subsequence (i.e., their indices are increasing).

# But checking subsequence for each segment would be O(n) per segment, and there are O(n) segments -> O(n^2), too slow.

# Another insight:
# Actually, we don't care about the actual order of kept elements for the value (max-min). 
# The minimal possible difference will come from a set of (n-k) numbers that are as close as possible in value.
# And importantly: **any** subset of (n-k) elements can be kept as long as we remove the others — 
# and since we're allowed to remove arbitrarily, the only constraint is that we keep (n-k) elements.

# But wait: the problem says "concatenate the remaining elements in their original order" — 
# so we cannot reorder them. However, the value max(B)-min(B) does not depend on the order — 
# it only depends on which elements are present.

# Therefore, the answer only depends on the multiset of kept elements, not their order.
# So we are free to choose any (n-k) elements from A, and we want to minimize (max(chosen) - min(chosen)).

# So the problem reduces to:
# Find a subset of (n-k) elements from A such that (max(subset) - min(subset)) is minimized.

# This is equivalent to: sort A, and find the minimum difference between A[i+(n-k)-1] and A[i] for i from 0 to k.
# Why? Because in a sorted array, the smallest range containing (n-k) elements is achieved by a contiguous block.

# Proof: If you fix the smallest and largest element in the subset, then including all elements in between doesn't hurt.
# So the optimal subset is always a contiguous block in the sorted array.

# Therefore:
# Step 1: sort A
# Step 2: for every i from 0 to k (inclusive), consider the window A[i : i + (n-k)]
#         the cost is A[i + (n-k) - 1] - A[i]
# Step 3: take the minimum over i

# Example: N=2, K=0 -> keep 2 elements
# A = [780031076, 658404808] -> sorted: [658404808, 780031076]
# n-k = 2, so i from 0 to 0 (since k=0): only window [0:2]
# diff = 780031076 - 658404808 = 121626268 -> matches expected.

n_keep = n - k
A.sort()
min_diff = float('inf')

for i in range(k + 1):  # i from 0 to k
    j = i + n_keep - 1
    if j < n:
        diff = A[j] - A[i]
        if diff < min_diff:
            min_diff = diff

print(min_diff)
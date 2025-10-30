n, k = map(int, input().split())
a = list(map(int, input().split()))

# We are removing exactly K elements, so we keep (n - k) elements.
# We want to minimize (max(B) - min(B)) where B is the remaining subsequence in original order.

# Since we can only remove elements but must preserve the order of the remaining ones,
# one optimal strategy is to consider contiguous subarrays of length (n - k) in the sorted array?
# BUT: we cannot reorder. However, note that to minimize max - min, we likely want to keep values close together.

# Insight:
# The best way is to try all possible ways of keeping a contiguous segment of (n-k) elements
# in the original array? -> No, because we can remove arbitrary elements, not necessarily from ends.

# Alternate Insight:
# Since we are allowed to remove any K elements, the resulting sequence B must be a subsequence of A of length (n-k).
# To minimize (max(B) - min(B)), we should choose B such that its values are as close as possible.

# How?
# Sort the array along with indices to track original positions.
# Then, for every possible window of size (n-k) in the sorted array, check if the corresponding elements
# (in the original array) can form a valid subsequence (i.e., appear in increasing index order).

# But checking subsequence for each window would be O(n) per window → O(n²), which may be too slow for n=2e5.

# Better Insight:
# Instead, note that we can always choose to remove some prefix and suffix from the original array.
# Specifically, suppose we decide to keep a contiguous block in the original array — is that sufficient?
# NO: Consider A = [1, 100, 2, 101], K=2. Removing 100 and 101 gives B=[1,2], which is non-contiguous but optimal.
# So we can pick non-contiguous elements.

# However, here's a key idea:
# In the final subsequence B, let the smallest element be x and largest be y.
# Then the cost is y - x.
# To minimize this, we can fix the smallest and largest values among the kept elements.

# Another known solution approach:
# Sort by value, keep indices.
# For any valid selection of (n-k) elements, the minimal difference will come from a set of values within a small range.
# So slide a window of size (n-k) over the sorted array and for each such window, check whether the indices of those elements
# (in the original array) allow them to appear in increasing order (i.e., form a subsequence of the original array).

# How to check quickly?
# Actually, we don't need to check arbitrary windows. There's a simpler method:

# Known similar problem: "Minimum Difference Between Largest and Smallest Value in Three Moves" etc.

# Alternate efficient solution:
# We can consider: the optimal B will have its minimum and maximum among the smallest and largest values in A.
# Moreover, since we can remove K elements, we can think about how many of the smallest and largest values we remove.

# Important observation:
# The optimal solution involves keeping a subsequence of (n-k) elements. But note: we can simulate this by considering
# that we remove some number of elements from the left part (smallest values) and some from the right part (largest values)
# in the sorted order — but again, we must preserve order.

# Actually, here’s a better-known solution:
# After sorting A along with original indices, we can try all splits where we take (n-k) consecutive elements in the sorted array.
# For each such group, we extract their original indices and check if they are in increasing order (so they can appear in the original sequence without violating order).
# If yes, then candidate answer = last_value - first_value in that sorted group.

# But worst-case there are O(n) such groups, and checking increasing order of indices takes O(n-k) → total O(n²) ≈ 4e10 operations worst-case → too slow.

# We need a more efficient idea.

# Even better insight:
# Instead of sorting by value, note that the final subsequence B must consist of (n-k) elements in original order.
# What if we try to fix how many elements we remove from the prefix and suffix?

# Let’s say we remove i elements from the beginning and (k-i) from the end? Not sufficient because removals can be anywhere.

# But wait: another known trick:
# We can only remove K elements. So the remaining elements form a subsequence of length (n-k).
# We can use two pointers or sliding window on the original array?

# Actually, here's an efficient correct solution:
# Sort the array by value, but remember original indices.
# Then, for each contiguous segment of length (n-k) in the sorted array, get the list of indices.
# Then check if the indices in this segment are in increasing order (which means they appear in order in the original array).
# But again, O(n*(n-k)) worst-case.

# We need to optimize the check.

# Alternative approach from known problems (e.g., CodeForces, AtCoder):
# We can precompute the earliest position where we can have a subsequence of certain values.

# Actually, there's a simpler and correct method:
# Try all possibilities of how many smallest elements we keep/remove and how many largest.
# Specifically, we can consider: remove x elements from the left (smallest) and (k-x) from the right (largest) in the sorted array.
# But we must ensure that the remaining (n-k) elements can be selected in the original order.

# However, there's a well-known solution:
# After sorting by value, we can consider only windows of size (n-k) in the sorted array.
# For each such window, collect the indices of the elements in that window.
# Then, if the maximum index in the window minus the minimum index >= (n-k)-1, it doesn't help.

# Actually, no — what matters is whether the indices are in increasing order. But they are not required to be consecutive.

# The condition is: the indices of the selected elements (from the window) must be strictly increasing.

# But since we're taking multiple elements, we just need to know if there exists a subsequence of length (n-k) using only these values.

# But easier: once we have the list of indices for the current window, we can sort them and see if they are increasing — they always are when sorted.
# But that doesn’t tell us if they appear in order — actually, if we sort the indices, we get the order they appear in the array.
# And since we are allowed to pick in original order, we can always pick them in increasing index order.

# Wait! That’s true: if we select a set of elements, we can always arrange them in the output in increasing index order (which is the original order).
# But the catch: the original order is fixed, and we are not allowed to reorder.
# However, when we remove elements, the remaining ones stay in their original relative order.

# Therefore, any subset of elements will appear in the result in increasing order of their indices.

# So, for any set S of (n-k) elements, as long as we list them in increasing index order, that is the resulting sequence B.

# Therefore, the only requirement is that we pick any (n-k) elements — their relative order is automatically preserved.

# So the problem reduces to: 
# Find a subset of (n-k) elements from A such that (max(subset) - min(subset)) is minimized.

# And that is achieved by taking (n-k) consecutive elements in the sorted array!

# Why? Because if you sort the array, the minimal range for m consecutive elements is obtained by a sliding window.

# Therefore, algorithm:
# 1. Pair each element with its index.
# 2. Sort by value.
# 3. Slide a window of size (n-k) over the sorted array.
# 4. For each window, compute (last_value - first_value).
# 5. Take the minimum over all windows.

# But wait: is this valid?
# Example: A = [1, 3, 2], K=1 → keep 2 elements.
# Sorted: [(1,0), (2,2), (3,1)]
# Window [1,2]: values [1,2] → diff=1, indices [0,2] → in original array, after removing index1 (value=3), we get [1,2] → valid.
# Window [2,3]: values [2,3] → diff=1, indices [2,1] → if we keep both, in original order: first index1 (3), then index2 (2) → B=[3,2]
#   But that has min=2, max=3 → diff=1, same.
# However, the values in B are 3 and 2 → min=2, max=3 → diff=1.

# So regardless of order, the min and max of the set are 2 and 3.

# Therefore, the difference depends only on the set of values, not their order.

# So we can indeed ignore the order for the purpose of computing (max - min).

# Hence, the answer is simply the minimum difference between the maximum and minimum of any (n-k) elements.
# And that is achieved by taking (n-k) consecutive elements in the sorted array.

# Therefore, we don't even need the indices!

# But wait: what if we are forced to keep elements that are far apart in value because of ordering constraints?
# Example: A = [1, 100, 2], K=1.
# We can remove one element.
# Option 1: remove 100 → B=[1,2] → diff=1.
# Option 2: remove 1 → B=[100,2] → diff=98.
# Option 3: remove 2 → B=[1,100] → diff=99.
# Best is 1.

# Now sort A: [1,2,100], window size=2.
# Window [1,2]: diff=1 → matches.
# Window [2,100]: diff=98.

# So answer=1.

# Another example: A = [1, 100, 2, 101], K=2 → keep 2 elements.
# Best: keep 1 and 2 → diff=1.
# Sorted: [1,2,100,101], window size=2.
# [1,2] → 1, [2,100]→98, [100,101]→1 → min=1.

# But can we keep both 1 and 2? Yes, remove 100 and 101 → B=[1,2].

# So it works.

# However, consider: A = [1, 3, 2, 4], K=2, keep 2.
# Possibilities: 
#  [1,2] → diff=1
#  [1,3] → 2
#  [1,4] → 3
#  [3,2] → 1 (but B=[3,2] → min=2, max=3 → diff=1)
#  [3,4] → 1
#  [2,4] → 2
# So minimum diff is 1.

# Sorted: [1,2,3,4], window size=2:
# [1,2]→1, [2,3]→1, [3,4]→1 → min=1.

# So it still works.

# Conclusion: the constraint of preserving order does NOT affect the set of possible values we can keep.
# Because we can remove any K elements arbitrarily, we can keep any subset of (n-k) elements.

# Therefore, the problem reduces to: given an array, choose (n-k) elements to minimize (max - min).
# Solution: sort the array, and take a contiguous block of (n-k) elements with minimal (last - first).

# Therefore, code:

# Edge: if n-k == 1, then max-min=0.

sorted_a = sorted(a)
m = n - k
if m == 1:
    print(0)
else:
    min_diff = float('inf')
    for i in range(n - m + 1):
        diff = sorted_a[i + m - 1] - sorted_a[i]
        if diff < min_diff:
            min_diff = diff
    print(min_diff)
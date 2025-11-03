n, k = map(int, input().split())
a = list(map(int, input().split()))

# We need to remove exactly K elements, so we keep (n - k) elements.
# The goal is to minimize (max(B) - min(B)) for the remaining sequence B.

# Since we can only remove elements (not reorder), the remaining elements must be contiguous in the original array?
# Actually, no: we can choose any K elements to remove, so the remaining elements stay in order but may not be contiguous.
# However, to minimize max - min, it's optimal to keep a contiguous block? Not necessarily — but note:
# If we fix which elements are kept, then B is just those elements in order. To minimize (max - min),
# we would prefer to keep values that are close together.

# Important observation:
# The final sequence B will have some minimum and maximum. To minimize max - min,
# we should try to avoid very large and very small values.
# One effective approach: sort the possible values, but we cannot change order.

# Alternate idea:
# Since the relative order must be preserved, we can consider what subsequence of length (n-k) we keep.
# But trying all subsequences is too expensive.

# Better idea:
# Note: The answer is at least 0, and we want to minimize max - min.
# We can use sliding window after sorting by value, but preserving index?

# Insight:
# We can choose which K elements to remove arbitrarily. So we are choosing a subsequence of length (n-K).
# The cost is (max of chosen - min of chosen).
# We want to minimize this.

# How about: sort the array along with original indices. Then, we look for a subsequence of length (n-K)
# that has minimal difference between max and min, and whose indices are increasing (to preserve order).

# But checking all such windows in sorted order that form an increasing subsequence in index is complex.

# Alternate known solution idea:
# Instead, note that the optimal set of kept elements will have its minimum and maximum among the smallest or largest values.
# We can try all possible left and right bounds in the original array.

# Actually, a known efficient solution:
# Sort the array with indices. Then, slide a window of size (n-K) over the sorted array.
# For each window, check if the corresponding indices in the original array allow us to pick these elements in increasing order.
# That is, if the indices of the selected elements (in the window) are in increasing order, then they can form a valid subsequence.

# But checking increasing indices for every window is O(n) per window -> O(n^2), too slow.

# Another known approach:
# We can observe that the optimal solution involves keeping a contiguous segment in the sorted order? 
# But again, the indices must be increasing.

# Actually, there’s a simpler idea:
# Try all possible numbers of elements taken from the prefix and suffix.
# Specifically: since removing K elements, we can think of keeping a sequence that consists of:
#   - the first i elements, and
#   - the last (n-K - i) elements
# But wait: this only considers keeping a prefix and a suffix. Is that sufficient?

# Claim: The optimal remaining sequence can always be represented as taking some elements from the beginning and some from the end.
# Why? Because if you skip an element in the middle, you could potentially skip one on the edge instead? Not obvious.

# Counterexample? Consider A = [1, 10, 2, 11], K=2. We want to keep 2 elements.
# Option: keep [1,2] -> diff=1
#         keep [10,11] -> diff=1
#         keep [1,11] -> diff=10
#         keep [1,10] -> diff=9
#         keep [2,11] -> diff=9
#         keep [10,2] -> invalid order? No: [10,2] appears as 10 then 2 -> allowed? Yes, because 10 comes before 2.
# But wait: in the array [1,10,2,11], 10 is before 2, so [10,2] is allowed -> diff=8.
# But [1,2] gives 1, which is better.

# Now, can we get [1,2] by taking prefix and suffix? 
# prefix: take 1 element: [1]
# suffix: take 1 element: [11] -> [1,11]
# or prefix 2: [1,10], suffix 0 -> [1,10]
# or prefix 0, suffix 2: [2,11]
# or prefix 1, suffix 1: [1,11]
# we cannot get [1,2] because 2 is not in the suffix unless we take at least 2 from the end, but then we get [2,11].

# So [1,2] is not a prefix + suffix combination? But 1 is in prefix, 2 is not in the suffix if we take only 1 from the end.

# Actually, we can define:
# Let’s say we remove K elements. Then the remaining sequence must start at some index i and end at some index j, but not necessarily contiguous.

# However, here's a different known solution:
# Sort by value, and then use two pointers or sliding window to find a set of (n-K) elements with minimal range (max-min) such that their indices are increasing.

# But we can do: 
# Sort the elements by value: (value, original_index)
# Then, for a fixed window of size (n-K) in this sorted list, we can check if the indices of the elements in the window are in increasing order? 
# But we don't require consecutive indices, just increasing. So we need to check if the indices in the window form an increasing sequence when traversed in order of appearance in the array.

# Actually, no: the condition is automatically satisfied if we can pick them in the order of the original array. But the window in sorted order does not correspond to the order in the array.

# However, if we have a set S of (n-K) elements, they can be kept in the final sequence in the order of their indices. So the only requirement is that we can extract them in increasing index order.

# But any set of elements can be extracted in increasing index order — that’s always possible by scanning left to right.

# Wait! That’s true: no matter which set of (n-K) elements we choose, we can always arrange to keep them in the original order simply by removing the others. The resulting sequence is the values at the chosen indices, in increasing order of index.

# Therefore, **any** subset of (n-K) elements is achievable.

# Then the problem reduces to: choose any (n-K) elements from A to minimize (max(chosen) - min(chosen)).

# And that is achieved by taking (n-K) consecutive elements in the sorted array.

# Why? Because if the values are sorted, the minimal range for a fixed number of elements is achieved by a contiguous block.

# Therefore, algorithm:
# 1. Sort the array.
# 2. Consider all contiguous subarrays of length (n-K) in the sorted array.
# 3. Compute the difference between the last and first element in each such subarray.
# 4. Answer is the minimum of these differences.

# But wait: is that correct? 
# Example: A = [780031076, 658404808], K=0 -> remove 0 elements, so we must keep both.
# Sorted: [658404808, 780031076], n-K = 2, so only one window: diff = 780031076 - 658404808 = 121626268 -> matches expected.

# Another example: A = [1, 10, 2, 11], K=2 -> keep 2 elements.
# Sorted: [1,2,10,11]
# Contiguous windows of size 2:
#   [1,2] -> 1
#   [2,10] -> 8
#   [10,11] -> 1
# So answer = 1.

# But earlier we thought [10,2] was allowed? But [10,2] has values 10 and 2, which are not consecutive in sorted order, and their range is 8, which is worse than 1.

# And indeed, we can achieve 1 by keeping [1,2] or [10,11]. Both are valid.

# So the algorithm works.

# However, note: the above reasoning relies on the fact that **any** subset of size (n-K) is allowed. 
# And that is true: we can remove any K elements arbitrarily, so we can keep any (n-K) elements we want.

# Therefore, the problem reduces to: given an array, choose (n-K) elements to minimize the difference between the maximum and minimum of the chosen set.

# This is minimized when the chosen elements are consecutive in the sorted order.

# Steps:
# - Read N, K and the list A.
# - Sort A.
# - Let L = n - K (number of elements to keep).
# - If L == 1, then max - min = 0.
# - Otherwise, slide a window of length L over sorted A and compute A[i+L-1] - A[i] for each i from 0 to n-L.
# - Answer is the minimum of these values.

# Edge: L = n-K >= 1 since K < N.

# Let's test with sample: N=2, K=0 -> L=2
# A = [780031076, 658404808] -> sorted: [658404808, 780031076]
# i=0: A[1]-A[0] = 780031076 - 658404808 = 121626268

# Code:

n, k = map(int, input().split())
a = list(map(int, input().split()))

l = n - k
a.sort()

ans = float('inf')
for i in range(n - l + 1):
    diff = a[i + l - 1] - a[i]
    if diff < ans:
        ans = diff

print(ans)
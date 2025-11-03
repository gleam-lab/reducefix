n, k = map(int, input().split())
a = list(map(int, input().split()))

# We are removing exactly K elements, so we keep (n - k) elements.
# We want to minimize (max(B) - min(B)) for the remaining subsequence B in original order.

# Since we can only remove elements and must preserve order, the remaining elements form a contiguous
# subsequence in terms of indices? Not necessarily — but note: we can choose any K elements to remove.
# However, the optimal solution will be a contiguous segment of length (n-k) in the sorted array?
# But wait: the elements must remain in original order. So we cannot sort.

# Insight:
# The remaining elements must appear in the original order. To minimize max-min, we should consider
# choosing a subsequence of n-k elements that are as close in value as possible, while preserving order.

# Alternate approach:
# Sort the array along with keeping original indices.
# Then, we can try all possible contiguous segments of length (n-k) in the sorted array, and check if
# the corresponding indices in the original array allow a valid subsequence (i.e., indices increasing).
# But checking validity for each segment would be O(n) and overall O(n^2), which might be too slow (n=2e5).

# Better insight:
# Instead, note that after removal, the remaining sequence B has its min and max. Let’s denote them.
# The min of B must be one of the elements in A, and same for max.
# Also, since we remove exactly K elements, we can think greedily.

# Another idea:
# We can fix the smallest element in B and then find the smallest possible largest element such that
# there exists a subsequence of length (n-k) starting from that smallest element (in value) and going up,
# with indices increasing.

# Even better known approach:
# We can use sliding window on the sorted array, but ensure that the indices of the chosen elements are increasing.
# However, there is a simpler way:

# Observation: The remaining elements form a subsequence of the original array of length (n-k).
# We want to minimize (max - min) over all such subsequences.

# Known trick: 
# Sort by value, keep index. Then consider every contiguous subarray of length (n-k) in this sorted list.
# For each such contiguous subarray, check whether the corresponding indices have an increasing subsequence of length (n-k)?
# Actually, we don't need to check full subsequence — if the indices of these (n-k) elements (in order of appearance in original array)
# are increasing, then they can form a valid remaining sequence.

# But note: we are allowed to remove arbitrary elements, so as long as the indices of the selected elements are in increasing order,
# we can keep them (by removing others). So for a set of (n-k) elements, they can be kept if their indices are increasing.

# Therefore, for a contiguous segment in sorted order of length (n-k), if the indices of these elements are not decreasing (i.e., we can
# pick them in order), then it's valid. But actually, we just need that when we look at the positions, we can arrange them in increasing
# order — which we always can because we process by increasing index. The issue is: do the indices of these (n-k) elements form an increasing sequence?

# Actually, no matter what the indices are, we can always extract them in increasing order of index. Because we are allowed to remove others.
# So if we pick any set S of (n-k) elements, we can keep them in the final array in the order of increasing index, which preserves the original order.

# BUT: is that correct? Yes! Because we are only removing elements. So any subset of elements can be kept in the order they originally appeared.

# Therefore, the only constraint is that we pick (n-k) elements whose values are as close as possible.

# So the answer is: the minimum difference between max and min over all subsets of size (n-k) of A.

# And since we can reorder by value (but the subset doesn't require ordering), the minimal max-min difference is achieved by taking
# (n-k) consecutive elements in the sorted array.

# Why? Because if the values are sorted: v0 <= v1 <= ... <= v_{n-1}, then any subset of (n-k) elements will have min at least v_i and max at most v_j,
# and the minimal possible difference is min_{i} (v[i+n-k-1] - v[i]) for i from 0 to k.

# Example: 
#   N=2, K=0 -> keep 2 elements. Then answer = max(A)-min(A) = |780031076 - 658404808| = 121626268.

# So algorithm:
#   sort A
#   ans = min{ A[i + (n-k) - 1] - A[i] } for i in range(0, k+1)

# Why i from 0 to k? Because we are choosing (n-k) consecutive elements. There are k+1 such windows.

# Example: n=5, k=2 -> keep 3 elements. Then we try:
#   i=0: A[2]-A[0]
#   i=1: A[3]-A[1]
#   i=2: A[4]-A[2]
#   i from 0 to k (which is 2) inclusive -> 3 windows.

# This matches: number of windows of length L in array of length n is n-L+1 = n - (n-k) + 1 = k+1.

# Therefore, code:

sorted_a = sorted(a)
L = n - k  # length of remaining sequence
ans = min(sorted_a[i + L - 1] - sorted_a[i] for i in range(k + 1))

print(ans)
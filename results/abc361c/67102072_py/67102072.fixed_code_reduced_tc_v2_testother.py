n, k = map(int, input().split())
a = list(map(int, input().split()))

# We are removing exactly K elements, so we keep (n - k) elements.
# To minimize (max(B) - min(B)), we should choose a contiguous segment of (n-k) elements
# from the sorted array, but note: the remaining elements must stay in original order.
#
# However, since we can remove any K elements arbitrarily, the optimal strategy is:
# Sort the array, and consider all contiguous subarrays of length (n-k) in the sorted array.
# But wait: the catch is that the selected elements must appear in the original order?
# Actually, no: we cannot reorder. But we can remove arbitrary elements, so the remaining ones
# preserve their relative order.

# Important insight:
# The final sequence B must be a subsequence of A (with order preserved) of length (n-k).
# We want to minimize (max(B) - min(B)).

# Alternate approach:
# Since we can choose which K elements to remove, we can think greedily:
# To minimize the difference, we likely want to remove the extreme values.
# So, one idea: try all possibilities where we remove x elements from the left (smallest)
# and (k - x) from the right (largest), but this only works if we sort?

# But note: we cannot change the order. However, if we fix the minimum and maximum in B,
# then all elements outside [minB, maxB] must be removed, and also we need to ensure that
# there exists a subsequence of length (n-k) with values in [minB, maxB] that appears in order.

# Simpler and correct idea:
# Since we are allowed to remove any K elements, one good strategy is to consider keeping a
# contiguous block in the original array? Not necessarily — because non-contiguous might be better.

# But here's a known solution for this problem:
# Sort the array along with indices. Then, we want to pick (n-k) elements such that they form
# an increasing index sequence (to preserve order) and minimize (max - min).
# We can use sliding window on the sorted array: consider each possible window of size (n-k)
# in the sorted array, and check whether the indices of these elements are in increasing order?
# But that would be O(n^2).

# Better idea:
# Instead, note that we can always achieve a range by choosing a set of values within [L, R]
# such that there are at least (n-k) elements in A that lie in [L, R] and we can pick them in order.
# But how to verify if we can pick (n-k) elements in increasing index order within [L,R]?

# Actually, known solution:
# We can try to fix the leftmost element we keep and the rightmost, but it's complex.

# Insight from known problems: "Minimum Difference After Removing K Elements"
# Actually, a common solution is:
#   Sort the array by value, but remember original indices.
#   Then, use a sliding window of size (n-k) over the sorted array.
#   For each window, check if the indices of the elements in the window can form a valid subsequence
#   (i.e., the indices are in increasing order). But that doesn't guarantee we can pick exactly those.

# Even simpler and correct:
# We can remove K elements arbitrarily. So, the best way to minimize the range is to remove
# the K elements that are most "extreme". But because order matters, we cannot simply take the middle.

# Alternate known solution:
# Consider that the remaining elements form a subsequence of length (n-k). We want to minimize
# (max - min). We can try:
#   Let’s sort the array, but we need to preserve the possibility of forming a subsequence.

# Actually, here's a simpler idea:
# We can always get a candidate by taking a prefix of length i and suffix of length (n-k-i),
# but that may not be optimal.

# Known similar problem: 
# Solution: try all splits where we remove x from the left and (k-x) from the right in the sorted order?
# But again, we must preserve original order.

# Correction: There is a well-known solution:
#   Sort the array, but keep track of indices.
#   Then, use a deque or two pointers to maintain a window of (n-k) elements in sorted order,
#   and for each such window, check if the indices of the elements in the window have an increasing subsequence of length (n-k)? 
#   But that is too expensive.

# Actually, a simpler and correct approach:
# We can observe that the optimal answer can be achieved by keeping a contiguous segment in the original array?
# No, not necessarily.

# Another known solution from competitive programming:
#   We can try all possible pairs of left and right pointers in the original array such that
#   the number of elements between them (inclusive) is at least (n-k), but that doesn't help.

# Insight:
# Since we can remove any K elements, the minimal range will be achieved by a set of (n-k) elements
# whose values are as close as possible. So, if we sort the array by value, then the optimal set must
# be a contiguous block in the sorted array? Yes, because if you skip a value in the middle, you could
# include it and possibly reduce the range.

# BUT: we must be able to pick them in the original order. However, if we have a set S of (n-k) elements
# that are consecutive in sorted order, can we always pick them in increasing index order? Not necessarily.

# However, note: we don't require the values to be consecutive in the array, only that the indices are increasing.
# So, given a set of elements (with their indices), we can pick them in increasing index order if we ignore the rest.

# Therefore, for a fixed contiguous segment in the sorted array of length (n-k), we can form a valid subsequence
# if the indices of these elements are not decreasing? Actually, we can always pick them in increasing index order
# by going through the array once and picking every element that belongs to the set. But wait: what if the indices
# are scattered? As long as we can traverse and pick them in order, yes.

# However, the issue is: we are forced to preserve the original order, but we can skip arbitrary elements.
# So, any subset of elements can be picked in increasing index order — just skip the ones not in the set.

# Therefore, for any set of (n-k) elements, we can form a valid sequence B by traversing A and including
# the elements that are in the set.

# So the only constraint is that the set has (n-k) elements.

# Thus, the problem reduces to:
#   Find a set S of (n-k) elements from A such that (max(S) - min(S)) is minimized.
# And this is achieved when S is a contiguous block in the sorted array.

# Therefore, algorithm:
#   Sort the array.
#   Consider every contiguous subarray of length (n-k) in the sorted array.
#   Compute the difference between the last and first element in the subarray.
#   Answer is the minimum such difference.

# But wait: does this work?
# Example: 
#   Input: N=2, K=0 -> remove 0 elements, so we keep both.
#   A = [780031076, 658404808]
#   Sorted: [658404808, 780031076]
#   Contiguous block of length 2: difference = 780031076 - 658404808 = 121626268 -> matches expected.

# Another example: 
#   N=3, K=1, A=[1, 3, 2]
#   Keep 2 elements.
#   Sorted: [1,2,3]
#   Possible contiguous blocks of length 2:
#       [1,2] -> diff=1
#       [2,3] -> diff=1
#   So answer = 1.
#   Can we achieve 1? 
#       If we remove 3: B = [1,2] -> diff=1 -> yes.
#       Or remove 1: B = [3,2] -> diff=1 -> yes.
#   So it works.

# But what about: 
#   N=4, K=2, A=[1, 4, 2, 3]
#   Keep 2 elements.
#   Sorted: [1,2,3,4]
#   Contiguous blocks of length 2: min diff = 1 (e.g., [1,2], [2,3], [3,4])
#   Can we achieve 1? 
#       We need two elements with difference 1: e.g., 1 and 2: in A, 1 is at index0, 2 at index2 -> we can keep them: B=[1,2] -> diff=1 -> yes.
#   So it works.

# Therefore, the solution is:
#   Sort the array
#   Slide a window of size (n-k) and compute min(arr[i + (n-k) - 1] - arr[i]) for i from 0 to k

# Why up to k? Because there are k+1 possible windows: from i=0 to i=k (since n-k + k = n)

# Example: n=4, k=2 -> window size=2, i from 0 to 2: 
#   i=0: [0:2] -> arr[1]-arr[0]
#   i=1: [1:3] -> arr[2]-arr[1]
#   i=2: [2:4] -> arr[3]-arr[2]

# So loop i from 0 to k (inclusive)

# Code:

if n - k == 0:
    print(0)
else:
    a.sort()
    min_diff = float('inf')
    for i in range(k + 1):
        j = i + (n - k) - 1
        if j < n:
            diff = a[j] - a[i]
            if diff < min_diff:
                min_diff = diff
    print(min_diff)
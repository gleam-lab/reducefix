n, k = map(int, input().split())
A = list(map(int, input().split()))

# Sort the array to consider optimal removals
A.sort()

# We are removing exactly K elements, so we keep (n - k) elements
# To minimize (max(B) - min(B)), we should choose a contiguous subsequence of length (n - k)
# in the sorted array, because rearrangement isn't allowed but we can remove arbitrary elements.
# Since we want to preserve original order? Actually: we remove K elements and concatenate remaining in original order.
# But note: we can choose *any* K elements to remove. So we can pick a set of indices to keep.

# However, since we want to minimize max - min, it's best to keep values that are close together.
# The optimal solution will be to keep a contiguous segment in the sorted array? Not exactly — 
# but we can only keep elements in their original order? No: we remove some, and the rest stay in original order.
# BUT: we are free to choose which ones to remove. So we can simulate keeping any subsequence (not necessarily contiguous in original array), 
# but they will appear in B in the same relative order as in A.

# However, here's the key insight:
# We want to minimize (max(B) - min(B)). The minimal range is achieved when the kept values are as close as possible.
# So we can sort the array and consider all windows of size (n-k), but we must ensure that the elements in such a window
# can appear in increasing index order in the original array? That would be too complex.

# Alternate approach:
# Actually, note: we are allowed to remove any K elements. So we can choose which ones to keep.
# But the kept elements must appear in B in their original order. However, if we fix the smallest and largest value in B,
# then we must keep all values between them? Not necessarily.

# Better idea from known problems:
# This is a classic "sliding window after sorting with index tracking" type problem.

# Actually, known solution:
# Sort the array along with original indices.
# Then, try every contiguous segment of length (n-k) in the sorted array.
# For each such segment, check whether the corresponding indices in the original array allow these elements to appear in increasing order (i.e., their indices are increasing).
# But that check is O(n) per segment, leading to O(n^2) worst-case — too slow for 2e5.

# Another known solution:
# Instead, realize that the answer is the minimum over i of (A[i + (n-k) - 1] - A[i]) for i from 0 to k, 
# **but only if** the elements in that window can be selected while preserving order? 

# Wait — actually, we don’t need to preserve the entire order globally; we just need to know that there exists a way to pick (n-k) elements 
# including this window, such that they appear in order. But if we fix a range [L,R] in the sorted array, we can always pick those elements 
# in the order of their appearance in the original array — as long as we are allowed to skip others.

# But here's the catch: the kept elements must appear in the same relative order as in the original array. 
# However, if we pick any subset of elements, their relative order in B is the same as in A. 
# So as long as we pick a set of elements whose indices in the original array are increasing, we're fine.

# Now, can we always pick all elements in a sorted contiguous window of size (n-k)? 
# Not necessarily — their original indices might be decreasing.

# But here’s a better idea: 
# We can use the following strategy:
# After sorting by value, we want to find a set S of (n-k) elements such that:
#   max(S) - min(S) is minimized
#   and the indices of elements in S are in increasing order (so they appear in correct order in B)

# This is equivalent to finding the smallest range such that there exists an increasing subsequence (in terms of index) of length (n-k) within that range.

# But that is complex.

# Known similar problem: "Minimum Difference Between Largest and Smallest Value in Array After Removing Elements"
# Insight: we can remove K elements arbitrarily, so we can choose to keep a subsequence of (n-k) elements.
# But to minimize max - min, we should only consider candidates where the kept values are consecutive in sorted order.

# However, there is a simpler solution:

# Alternate approach:
# Note: We are allowed to remove any K elements. So we can decide to keep a subsequence of (n-k) elements.
# Let’s suppose we fix the smallest and largest element in the final array B.
# Then all other kept elements must be between them.
# But we also need to be able to pick (n-k) elements with values in [minB, maxB] such that their indices are increasing.

# But instead, known efficient solution:

# Sort by value, and consider all windows of size (n-k). For each window, we want to know if the elements in that window 
# have indices that can form an increasing sequence of length (n-k) — but actually, we just need to know if we can pick at least (n-k) elements 
# from the entire array that lie in this value range AND appear in increasing index order.

# But wait — we are restricted to exactly (n-k) elements.

# Simpler idea from known contests:
# https://atcoder.jp/contests/abc282/tasks/abc282_d
# Actually not.

# Found: This is similar to CodeForces or AtCoder problems.

# Actually, correct known solution:
# We can try all possible left pointers in sorted array, and take the window [i, i + (n-k) - 1], and compute A[i+(n-k)-1] - A[i].
# Then the answer is the minimum over i from 0 to k of that difference.

# Why is that valid?
# Because we can always remove elements outside this window. And within the window, even if their indices are not in order, 
# we can still choose to keep them in the order of their appearance? No — we cannot reorder.

# But note: we are not required to keep *all* elements in the window. We only need to keep (n-k) elements.

# However, the above method assumes that we can keep the entire window. But what if the indices are decreasing?

# Counterexample:
# A = [10, 1, 2], n=3, k=1 -> keep 2 elements.
# Sorted: [1,2,10]
# Window size = 2.
# Window [1,2]: diff = 1. Can we keep both 1 and 2? Their indices: 1 has index 1, 2 has index 2 -> increasing -> yes. B = [1,2] -> diff=1.
# Window [2,10]: diff=8 -> worse.

# Another: A = [10, 2, 1], n=3, k=1
# Sorted: [1,2,10]
# Window [1,2]: values 1 (index2), 2 (index1) -> indices: 2 then 1 -> decreasing -> cannot keep both in order? 
# But when we remove one element, we get:
# Remove 10: B = [2,1] -> max-min = 2-1 = 1.
# Remove 2: B = [10,1] -> 9
# Remove 1: B = [10,2] -> 8
# So answer is 1.

# Even though 1 comes after 2 in the array, we can still keep both — because in the resulting array, 2 comes first, then 1.
# But that means B = [2,1] -> min=1, max=2 -> diff=1.

# So the values in B do not need to be in sorted order. We only care about (max - min).

# Therefore, as long as we keep a set S of (n-k) elements, the min and max of S determine the difference.
# And we can always keep any set S of (n-k) elements regardless of their index order? 
# No: we cannot change the order. But we are not required to output the values in sorted order — they remain in original order.

# However, the min and max of B depend only on the set of values kept, not on their order.

# Therefore, the problem reduces to:
# Choose any subset S of (n-k) elements from A such that (max(S) - min(S)) is minimized.

# And this is achieved by taking a contiguous block of (n-k) elements in the sorted array.

# Why? Because if the chosen values are not contiguous in sorted order, we can slide the window to reduce the gap.

# Therefore, algorithm:
# Sort A
# Answer = min_{i=0}^{k} (A[i + (n-k) - 1] - A[i])

# Example: A=[10,2,1], n=3, k=1 -> keep 2 elements.
# Sorted: [1,2,10]
# i=0: A[0+2-1] - A[0] = A[1]-A[0] = 2-1 = 1
# i=1: A[2]-A[1] = 10-2 = 8
# min = 1 -> correct.

# Another example: A = [1,2,3,4,5], n=5, k=2 -> keep 3
# sorted: [1,2,3,4,5]
# i=0: A[2]-A[0]=3-1=2
# i=1: A[3]-A[1]=4-2=2
# i=2: A[4]-A[2]=5-3=2
# min=2

# Is it possible to get less than 2? No.

# But what if we keep [1,3,5]? diff=4 -> worse.
# Or [2,3,4] -> diff=2.

# So it works.

# Why can we ignore the order constraint?
# Because the value of (max - min) depends only on the set of values we keep, not on their order.
# And we are allowed to keep any set of (n-k) values (by removing the others), regardless of their positions.
# The fact that they appear in B in original order does not affect the min and max.

# Therefore, the only thing that matters is which values we keep.

# So we can solve by:
# sort A
# ans = min(A[i + (n-k) - 1] - A[i] for i in range(0, k+1))

# Note: i goes from 0 to k (inclusive) because we have k+1 choices: remove i smallest and (k-i) largest, for i in [0,k]

# Number of windows: from i=0 to i = n - (n-k) = k

# So range is 0 to k inclusive.

# Edge: k < n, so n-k >= 1.

# Let's code accordingly.

n, k = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
keep = n - k
ans = min(A[i + keep - 1] - A[i] for i in range(k + 1))
print(ans)
import heapq

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order to handle largest toys first
A.sort(reverse=True)
# Use a max-heap for available boxes (simulate with negative values)
box_heap = [-b for b in B]
heapq.heapify(box_heap)

# Try to assign the largest unassigned toy to the smallest sufficient existing box
# But we'll use greedy: for each toy from large to small, try to use an existing box
# If no existing box can fit the current toy, then x must be at least this toy's size

# However, the original logic is flawed: we should not greedily pop the largest box.
# Instead, we want to save larger boxes for larger toys. So process toys from largest to smallest,
# and for each toy, check if the largest remaining box can fit it.
# But actually: better approach is to try to use smallest sufficient box for each toy? 
# Actually, since we are allowed one new box, we want to see which toy *must* go into the new box.

# Correct idea:
# We want to find the minimum x such that we can pack all toys using the N-1 boxes and one box of size x.
# This is equivalent to: which one toy can we "remove", and then check if the rest can be packed into the N-1 boxes?
# Then x must be at least the size of that removed toy.
# So we try every toy as candidate to be put in the new box, and check if the remaining N-1 toys can be packed
# into the N-1 boxes (with matching condition: toy size <= box size). We want the minimum such x = min over all candidates
# where packing is possible, and x must be >= the toy assigned to it.

# How to check if N-1 toys can be packed into N-1 boxes?
# Classic greedy: sort both toys and boxes in increasing order, and assign smallest box that fits each toy.

# Steps:
# 1. Precompute: sort boxes B
# 2. For each i in range(N): try removing toy A[i], then check if the other N-1 toys can be packed into B.
#    To do this efficiently, we can pre-sort everything and use two pointers or binary search.

# But N up to 200,000 -> O(N log N) per check would be O(N^2 log N) -> too slow.

# Better: 
# - Sort all toys and boxes.
# - Precompute whether the k smallest toys can be packed into the k smallest boxes for k=1..N-1? 
#   Specifically, we want to know: if we remove one toy, can the rest be packed?

# Alternate efficient solution:
# Let’s sort toys and boxes.
# We can precompute:
#   prefix_ok[i]: whether the first i smallest toys can be packed into the first i smallest boxes
#   suffix_ok[i]: whether the last i smallest toys (i.e., largest ones) can be packed into the last i smallest boxes?

# Actually, standard method: 
# Sort toys: a0 <= a1 <= ... <= a_{N-1}
# Sort boxes: b0 <= b1 <= ... <= b_{N-2}

# We want to know: for each j (toy index), if we remove toy j, can the remaining toys be packed?
# After removal, we have N-1 toys. Sort them, and match with sorted boxes.

# Idea: 
#   Try to simulate matching without one toy.
#   We can do:
#     Let sorted_toys = sorted(A)
#     sorted_boxes = sorted(B)
#
#     Precompute:
#       prefix[i] = True if the first i toys (smallest i) can be matched with first i boxes
#         -> for i from 0 to N-1: prefix[0]=True, for i>=1: prefix[i] = prefix[i-1] and (sorted_toys[i-1] <= sorted_boxes[i-1])? 
#         -> NO: because we may skip some toy.
#
#     Actually, we need: when we remove one toy, we form a new sorted list of N-1 toys.
#     We can use two arrays:
#       left[i]: whether the first i toys (from sorted_toys[0:i]) can be packed into sorted_boxes[0:i]
#       right[i]: whether the last (N-1-i) toys (sorted_toys[i+1:N]) can be packed into sorted_boxes[i:N-1]

# How to compute left:
#   left[0] = True
#   for i in range(1, N):
#       left[i] = left[i-1] and (sorted_toys[i-1] <= sorted_boxes[i-1])
#   But wait: if we remove toy at position j, then the toys before j are matched to some boxes, and after j to others.
#   But we need to reassign indices.

# Actually, correct method:
#   left[i] = whether the first i toys (indices 0..i-1) can be matched with the first i boxes (0..i-1)
#   We can compute:
#       left[0] = True
#       for i in range(1, N):
#           # we need to match i toys with i boxes
#           # but note: we only have N-1 boxes, so i <= N-1
#           if i > len(sorted_boxes): break
#           left[i] = left[i-1] and (sorted_toys[i-1] <= sorted_boxes[i-1])
#   But this is wrong: greedy doesn't work like that.

# Actually, for matching sorted lists: 
#   To check if a set of k toys T and k boxes B can be packed: sort both, then for all i, T[i] <= B[i].
#   This is a well-known greedy fact.

# Therefore:
#   If we remove toy j, then take the remaining toys, sort them -> call it T'
#   Then we need: for all i in [0, N-2], T'[i] <= sorted_boxes[i]

# Now, how to do this fast for each j?
#   Let sorted_toys = sorted(A)
#   sorted_boxes = sorted(B)
#
#   Precompute:
#     left[j] = whether the first j toys (0..j-1) satisfy: for i in [0, j-1]: sorted_toys[i] <= sorted_boxes[i]
#     But if we remove a toy at position k, then:
#         The new toy array is: sorted_toys[0:k] + sorted_toys[k+1:N]
#         And we want: for i in [0, N-2]:
#             new_toys[i] <= sorted_boxes[i]
#
#     We can split at k:
#         For i < k: new_toys[i] = sorted_toys[i], so we require sorted_toys[i] <= sorted_boxes[i]
#         For i >= k: new_toys[i] = sorted_toys[i+1], so we require sorted_toys[i+1] <= sorted_boxes[i]
#
#   So define:
#       left[i] = True for i==0, and for i>=1: left[i] = left[i-1] and (sorted_toys[i-1] <= sorted_boxes[i-1])
#       right[i] = True for i==N-1, and for i<=N-2: right[i] = right[i+1] and (sorted_toys[i+1] <= sorted_boxes[i])
#   But note: right[i] means: starting from index i, for positions i, i+1, ..., N-2: we require sorted_toys[j+1] <= sorted_boxes[j]
#   So right[i] = (sorted_toys[i+1] <= sorted_boxes[i]) and right[i+1]

# Then, for removal of toy at position k (in sorted order), the assignment is possible if:
#   left[k] is True (first k toys can be matched with first k boxes) 
#   and right[k] is True (toys from k+1 to end can be matched with boxes from k to end)

# Then the required x for this choice is sorted_toys[k] (since the new box must be at least that big)
# We want the minimum such x over all k where the condition holds.

# Special case: if no such k exists, return -1.

# Steps:
#   sorted_A = sorted(A)
#   sorted_B = sorted(B)
#   Precompute left[0..N]: left[0]=True, for i in 1..N: left[i] = left[i-1] and (i-1 < N-1 and sorted_A[i-1] <= sorted_B[i-1]) 
#        but wait: for left[i] we are checking first i toys vs first i boxes -> requires i <= N-1
#        Actually, left[i] defined for i in [0, N], but when i > N-1, we cannot have that many boxes.
#        But in our use, k from 0 to N-1, and we need left[k] for k in [0, N-1] and right[k] for k in [0, N-1]
#        For left[k]: we need k <= N-1 (which is true) and we use boxes[0:k] -> k boxes needed -> k <= N-1 -> ok.
#        But if k==N, we don't consider.

#   Actually, left[k] = whether for all j in [0, k-1]: sorted_A[j] <= sorted_B[j]
#   But note: if k==0, no toy before, so valid.
#   Similarly, right[k] = whether for all j in [k, N-2]: sorted_A[j+1] <= sorted_B[j]
#   Because: after removing k, the toy at position j>=k becomes new position j, and comes from old j+1, and must fit in box j.

#   Example: N=3, A=[1,2,3], B=[2,3]
#     sorted_A = [1,2,3], sorted_B = [2,3]
#     Try remove k=0: toys become [2,3]; need 2<=2 and 3<=3 -> yes. left[0]=True, right[0] = (sorted_A[1]<=sorted_B[0]) and (sorted_A[2]<=sorted_B[1]) = (2<=2) and (3<=3)=True -> valid, x=1
#     Try remove k=1: toys become [1,3]; need 1<=2 and 3<=3 -> yes. left[1] = (1<=2)=True; right[1] = (sorted_A[2]<=sorted_B[1]) = (3<=3)=True -> valid, x=2
#     Try remove k=2: toys become [1,2]; need 1<=2 and 2<=3 -> yes. left[2] = (1<=2) and (2<=3)? -> but left[2] uses first 2 boxes: sorted_B[0] and sorted_B[1] -> (1<=2) and (2<=3) -> True; 
#            right[2]: j from 2 to N-2=1 -> no j, so by convention True? 
#            We define right[k] for k from 0 to N-1, and for k=N-1, right[N-1]=True (no elements after)
#            So right[2]=True -> valid, x=3
#     Then min x = 1.

#   But is x=1 sufficient? Yes, because we can put toy 1 in the new box of size 1, and put toy 2 in box 2, toy 3 in box 3.

#   However, what if we have A=[3,3,3], B=[2,2]? 
#     sorted_A=[3,3,3], sorted_B=[2,2]
#     Try remove k=0: toys=[3,3]; need 3<=2 and 3<=2 -> fails.
#     k=1: toys=[3,3]; same -> fails.
#     k=2: toys=[3,3]; same -> fails.
#     So no solution -> output -1.

# Implementation:

sorted_A = sorted(A)
sorted_B = sorted(B)

# If there is only one box, then N=2, so B has one element.
n = N
m = n - 1  # number of boxes

# Edge: if N==1? but N>=2.

# Precompute left[i] for i in range(0, n+1): left[i] means the first i toys (0..i-1) can be matched with first i boxes (0..i-1)
# But only if i <= m, otherwise impossible? Actually, we only use i<=m because we have only m boxes.
# But in our loop, i will be from 0 to n, but for left[i] we require i<=m, else it's invalid.
# Actually, we only need left[k] for k in [0, n] but k is the number of toys before the removed one, so k<=n, but also k<=m for the boxes? 
# But we are going to use left[k] only when we have k boxes available for the first k toys -> so we need k <= m = n-1 -> always true since k<=n-1 (because k from 0 to n-1).

left = [True] * (n+1)
# left[0] = True
for i in range(1, n):
    # left[i] = left[i-1] and (sorted_A[i-1] <= sorted_B[i-1])
    if i > m:
        left[i] = False
    else:
        left[i] = left[i-1] and (sorted_A[i-1] <= sorted_B[i-1])
# For i==n: we don't really need it, but let's extend: if n>m then left[n] should be False, but we won't use it.
if n > m:
    left[n] = False

# Precompute right[i] for i in range(0, n): 
#   right[i] = whether for all j from i to m-1 (i.e., j from i to n-2): sorted_A[j+1] <= sorted_B[j]
#   We can compute backwards.
right = [True] * (n+1)  # right[i] for i in [0, n]; right[n] = True (no elements after)
# right[n] = True
# right[n-1] = True (since no j from n-1 to n-2 -> empty)
# For i from n-2 down to 0:
#   right[i] = (sorted_A[i+1] <= sorted_B[i]) and right[i+1]
# But note: j runs from i to m-1 = n-2, so the condition for j=i is sorted_A[i+1] <= sorted_B[i], and then j>i is covered by right[i+1].

# Initialize right for i from 0 to n: set right[n] = True, and for i>n-1, we don't use, but set to True.
right[n] = True
# If n-1 > m-1? m-1 = n-2, so n-1 > n-2 -> yes, so right[n-1] should be True (no j in [n-1, n-2] because n-1>n-2)
# So for i from n-2 down to 0:
for i in range(n-2, -1, -1):
    # Check if we have enough boxes: j goes up to n-2, and we have sorted_B[i] for i in [0, n-2]
    # Condition: sorted_A[i+1] <= sorted_B[i] and right[i+1]
    right[i] = (sorted_A[i+1] <= sorted_B[i]) and right[i+1]

# Now try each k in range(n): remove the toy at position k in sorted_A
ans = 10**18
found = False

for k in range(n):
    # Can we remove toy k?
    # The first k toys: indices 0..k-1 -> need to match boxes 0..k-1 -> condition: left[k] 
    # The remaining toys: k+1..n-1 -> become positions k..n-2 in the new array, and must match boxes k..n-2
    #   -> condition: right[k] 
    if left[k] and right[k]:
        found = True
        ans = min(ans, sorted_A[k])

if found:
    print(ans)
else:
    print(-1)
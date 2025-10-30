import heapq

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order to handle largest toys first
A.sort(reverse=True)
# Use a max-heap for available boxes (using negative values for min-heap simulation)
box_heap = [-b for b in B]
heapq.heapify(box_heap)

# Try to assign the largest unassigned toy to an existing box greedily
for size in A:
    if box_heap and -box_heap[0] >= size:
        # There's a box that can fit this toy
        heapq.heappop(box_heap)
    else:
        # No existing box can fit this toy, so we need a new box of at least `size`
        print(size)
        exit()

# If all toys are placed, no new box is needed? But we must use exactly one new box.
# However, problem requires purchasing one box. So even if all fit in old boxes, we still must buy one?
# But we want minimal x such that we can place all toys using the N boxes (N-1 old + 1 new).
# Important: We **must** use the purchased box for one toy.

# Therefore, it's not enough that all toys fit in old boxes — we must leave one box unused among the old ones,
# and put one toy in the new box.

# Revised plan:
# We are required to use exactly one new box (purchased). So one toy must go into the new box of size x,
# and the remaining N-1 toys must fit into the N-1 existing boxes.

# So try each toy as candidate to be placed in the new box.
# For each candidate toy i (with size a_i), check whether the other N-1 toys can be packed into the N-1 boxes.
# We want the minimum such a_i (since x must be at least a_i) for which packing is possible.

# How to check if N-1 toys can be packed into N-1 boxes?
# -> Classic greedy matching: sort both toys (excluding candidate) and boxes in increasing order,
#    and check if each toy fits in the corresponding box.

# Since N can be up to 2e5, trying all N candidates naively with sorting each time would be O(N^2 log N) -> too slow.

# Instead:
# Precompute:
#   Sort all toys and all boxes.
#   Then, for each candidate toy (to be removed), we want to know if the rest can be matched.

# Idea:
# Let’s sort toys in ascending order: T[0..N-1]
# Sort boxes in ascending order: C[0..N-2]

# We can precompute:
#   prefix_ok[i]: whether the first i smallest toys (among all except candidate?) — not directly.

# Alternate idea:
# Consider: if we remove a toy of size 'a', then we need to match the remaining N-1 toys with the N-1 boxes.
# We can do:
#   Sort A -> sorted_A
#   Sort B -> sorted_B

# Now, try to simulate matching from smallest to largest.

# But note: we are free to choose which toy goes to the new box.

# We can use greedy matching with two pointers or use binary search on x?

# Actually, let's reframe:
# We want the smallest x such that there exists a toy of size <= x that we can assign to the new box,
# and the remaining toys can be assigned to the existing boxes.

# So x must be at least the size of the toy we assign to it.

# So minimize x => minimize the size of the toy assigned to the new box? Not exactly: we might have to assign a large toy
# to the new box if small toys cannot be left out (because they require small boxes).

# But we want minimal x, so we want to assign the smallest possible toy to the new box? Not necessarily: maybe a large toy
# blocks nothing, but a small toy is essential for fitting in a small box.

# Better: iterate over which toy is assigned to the new box, and find the minimum x (which is the toy's size) such that
# the rest can be packed.

# How to quickly check if after removing one toy, the rest can be packed into sorted_B?

# Step:
#   Sort A -> a_sorted
#   Sort B -> b_sorted

#   Precompute:
#     prefix_match[i]: for the first i boxes, how many of the smallest i+1 toys (excluding candidate?) — not easy.

# Insight:
#   Suppose we decide to exclude a toy of value 't'. Then we have N-1 toys to pack into N-1 boxes.
#   We can try greedy matching:
#       Sort the remaining toys: we can do this fast if we know the full sorted array and skip one element.
#       Then match smallest remaining toy to smallest box, etc.

# But doing this for each candidate is O(N^2). We need O(N) or O(N log N).

# Alternate efficient method:
#   Let’s try to compute the "matching requirement" without skipping.

#   Without removal, what is the condition for being able to pack k smallest toys into k smallest boxes?
#   We can define:
#       feasible(i): whether the i-th smallest toy can be packed in the i-th smallest box when matching greedily.

#   But if we skip one toy, then we shift the alignment.

# Known trick: 
#   Let’s define an array ok[i] = (a_sorted[i] <= b_sorted[i]) for i in range(N-1)? But we have N toys and N-1 boxes.

# Actually, we have N-1 boxes. So when we remove one toy, we have N-1 toys.

# Consider:
#   Sort A: a0 <= a1 <= ... <= a_{N-1}
#   Sort B: b0 <= b1 <= ... <= b_{N-2}

#   Now, suppose we remove toy at index k.
#   Then the new toy array is: a0, ..., a_{k-1}, a_{k+1}, ..., a_{N-1} (length N-1)

#   We want to check if for all i in [0, N-2]:
#       toy[i] <= box[i]
#   where toy[i] is the i-th smallest among the remaining.

#   Specifically:
#       For i < k: toy[i] = a_i
#       For i >= k: toy[i] = a_{i+1}

#   So condition becomes:
#       For i in [0, k-1]: a_i <= b_i
#       For i in [k, N-2]: a_{i+1} <= b_i

#   So overall, the condition is:
#       max( 
#           max_{i=0}^{k-1} (a_i > b_i ? inf : 0), 
#           max_{i=k}^{N-2} (a_{i+1} > b_i ? inf : 0)
#       ) == 0

#   Or simply:
#       For all i in [0, k-1]: a_i <= b_i
#       For all i in [k, N-2]: a_{i+1} <= b_i

#   We can precompute:
#       prefix_ok[k] = True if for all i in [0, k-1]: a_i <= b_i
#       suffix_ok[k] = True if for all i in [k, N-2]: a_{i+1} <= b_i

#   Then candidate k is valid if prefix_ok[k] and suffix_ok[k].

#   Then the minimal x is min{ a_k | k such that prefix_ok[k] and suffix_ok[k] }.

# Steps:
#   Sort A
#   Sort B
#   Precompute:
#       prefix_valid[0] = True
#       for k from 1 to N: prefix_valid[k] = prefix_valid[k-1] and (a[k-1] <= b[k-1])   ??? 

#   But note: for candidate k (removing a_sorted[k]), the prefix part uses indices i=0 to k-1: compare a[i] vs b[i]
#   So we need k <= N-1 because b has only N-1 elements.

#   Specifically, for k from 0 to N-1:
#       prefix_condition: for i in [0, k-1]: a[i] <= b[i]  --> if k==0, no prefix, so true.
#       suffix_condition: for i in [k, N-2]: a[i+1] <= b[i] --> if k == N-1, then i from N-1 to N-2 -> empty, so true.

#   But note: when k = N-1, we are removing the largest toy.
#       Then we match a[0] to b[0], a[1] to b[1], ..., a[N-2] to b[N-2] -> standard matching.

#   When k = 0, we remove the smallest toy.
#       Then we match a[1] to b[0], a[2] to b[1], ..., a[N-1] to b[N-2]
#       Condition: for i from 0 to N-2: a[i+1] <= b[i]

#   So algorithm:

#   a_sorted = sorted(A)
#   b_sorted = sorted(B)

#   Precompute:
#       prefix[i] for i in range(0, N): 
#           prefix[0] = True
#           for i in range(1, N):
#               prefix[i] = prefix[i-1] and (i-1 < len(b_sorted) and a_sorted[i-1] <= b_sorted[i-1])
#           But wait: prefix[k] should mean: for all j in [0, k-1]: a_sorted[j] <= b_sorted[j]
#           So we can define an array P of length N+1: P[0]=True, P[i] = P[i-1] and (a_sorted[i-1] <= b_sorted[i-1]) for i=1..N-1, and for i>=N, not used.

#   Actually, we only need P[k] for k in [0, N], meaning the first k pairs (a[0]..a[k-1]) with (b[0]..b[k-1]) are all valid.

#   Similarly, suffix: S[k] = True if for all i from k to N-2: a_sorted[i+1] <= b_sorted[i]
#       We can compute backwards:
#       S[N-1] = True
#       S[k] = S[k+1] and (a_sorted[k+1] <= b_sorted[k]) for k from N-2 down to 0.

#   But note: for k = N-1, S[N-1] = True (no suffix to check)
#   for k = N-2: S[N-2] = (a_sorted[N-1] <= b_sorted[N-2]) and S[N-1]
#   ...

#   Then for each k in range(0, N):
#       if P[k] and S[k]:
#           candidate_x = a_sorted[k]
#           and we want the minimum such candidate_x.

#   If no k satisfies, output -1.

# Example test:
#   N=3
#   A = [3, 1, 4] -> sorted: [1,3,4]
#   B = [2, 5] -> sorted: [2,5]

#   Try k=0 (remove 1):
#       prefix[0]: True
#       suffix[0]: check i=0: a[1]=3<=b[0]=2? -> 3<=2? False; i=1: a[2]=4<=b[1]=5 -> True. But since i=0 fails, suffix[0]=False.
#       -> invalid
#   k=1 (remove 3):
#       prefix[1]: a[0]<=b[0] -> 1<=2 -> True
#       suffix[1]: i from 1 to 1: a[2]=4 <= b[1]=5 -> True -> valid
#       candidate x = 3
#   k=2 (remove 4):
#       prefix[2]: check i=0:1<=2, i=1:3<=5 -> True
#       suffix[2]: True (no i in [2,1])
#       candidate x = 4
#   So min x = 3.

#   Is that correct?
#       Remove toy 3 (size 3), put it in new box of size 3.
#       Put toy 1 (size 1) in box 2 (size 2) -> OK
#       Put toy 4 (size 4) in box 5 (size 5) -> OK
#       Yes.

#   What if we try to use x=2? Then we could only put a toy of size <=2 in the new box.
#       Only toy 1 (size 1) can go in the new box.
#       Then we have toys 3 and 4 to put in boxes [2,5].
#       Toy 3 needs box>=3 -> only box 5 works.
#       Toy 4 needs box>=4 -> only box 5 works -> conflict.
#       So indeed, x=2 doesn't work.

#   So answer 3 is correct.

# Edge: if no k works, return -1.

# Implementation:

a_sorted = sorted(A)
b_sorted = sorted(B)

n = N
m = n - 1  # number of boxes

# If there's only one box, m=1

# Precompute prefix: P[k] = whether for all i in [0, k-1]: a_sorted[i] <= b_sorted[i]
P = [True] * (n+1)
# P[0] = True
for i in range(1, n):
    if i > m:
        # We don't have b_sorted[i-1] for i-1 >= m
        # But note: i runs from 1 to n-1, and m = n-1, so i-1 from 0 to n-2 -> valid indices for b_sorted
        pass
    if i <= m:
        P[i] = P[i-1] and (a_sorted[i-1] <= b_sorted[i-1])
    else:
        # i > m: then we are checking more than m prefix conditions, but we only have m boxes
        # Actually, for k > m, the prefix condition requires comparing a_sorted[0..k-1] with b_sorted[0..k-1] but k-1>=m -> out of bounds.
        # But note: our loop only goes to i=n-1, and m=n-1, so i<=m always holds.
        P[i] = P[i-1]  # but actually, we cannot have a condition for i>m, so we break logic.
        # However, since m = n-1, and i from 1 to n-1, then i<=m always. So safe.
        pass

# For k>=m+1, we don't have b_sorted[k-1], but k runs from 0 to n-1, and m=n-1, so k-1 <= n-2 = m-1? 
# Wait: k in [0, n-1], so k-1 in [-1, n-2]. But we only use i<=m, and m=n-1, and i<=n-1, and b_sorted index i-1 from 0 to n-2 -> valid.

# But note: when i = m+1 = n, we don't run because range(1,n) -> i from 1 to n-1.

# So P[i] for i in [0, n] is defined.

# Precompute suffix: S[k] = whether for all i in [k, m-1] (i.e., k to N-2) we have a_sorted[i+1] <= b_sorted[i]
S = [True] * (n+1)
# S[n] = True, but we only need up to n-1
# Compute from k = n-1 down to 0
# For k = n-1: no i in [n-1, m-1] = [n-1, n-2] -> empty -> True
# For k from n-2 down to 0:
S[n-1] = True
for k in range(n-2, -1, -1):
    # Check a_sorted[k+1] <= b_sorted[k] and S[k+1]
    if k < m:  # k from 0 to n-2, and m = n-1, so k < m always true
        S[k] = (a_sorted[k+1] <= b_sorted[k]) and S[k+1]
    else:
        S[k] = S[k+1]  # shouldn't happen

# Now, try each k from 0 to n-1:
ans = 10**18
found = False
for k in range(n):
    if P[k] and S[k]:
        found = True
        if a_sorted[k] < ans:
            ans = a_sorted[k]

if found:
    print(ans)
else:
    print(-1)
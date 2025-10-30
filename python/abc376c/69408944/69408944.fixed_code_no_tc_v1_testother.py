import bisect

N = int(input())
A = list(map(int, input().split()))
B = sorted(list(map(int, input().split())))

# We need to assign each toy to a box (either existing or the new one)
# Goal: minimize x (size of the new box), such that all toys can be placed.

# Strategy:
# - Try to put as many toys as possible into existing boxes.
# - The remaining toys must go into the new box -> so x must be at least max(remaining_toy_sizes).
# - But we can choose which toys go where. So we want to minimize the largest toy that cannot be placed in an existing box.

# Optimal approach:
# 1. Sort toys in ascending order and boxes in ascending order.
# 2. Use greedy matching: for smallest boxes, try to cover smallest possible toys that fit.
#    Actually, better: try to cover as many toys as possible using existing boxes.
#    We can use a greedy matching: assign smallest available box to the smallest toy it can contain.

A_sorted = sorted(A)
B_sorted = sorted(B)

# Greedily match toys to boxes: use smallest box that can hold a given toy
used = [False] * len(B_sorted)
assigned_count = 0

# For each toy in increasing order, try to assign the smallest box that can hold it
for a in A_sorted:
    # Find the smallest box >= a that hasn't been used
    idx = bisect.bisect_left(B_sorted, a)
    while idx < len(B_sorted) and used[idx]:
        idx += 1
    if idx < len(B_sorted):
        used[idx] = True
        assigned_count += 1

# If all toys are assigned, then we don't need a new box? But we have N-1 boxes and N toys -> always need one box.
# So exactly one toy will remain. We need x >= size of that toy.

# The unassigned toys are those not matched. Since we used greedy, the unmatched toys are the ones left.
# Actually, we didn't track which toys were matched — we just counted.

# Alternate method: simulate matching and collect unmatched toys.

# Let's do it properly: simulate with pointer for boxes
box_ptr = 0
matched = 0
for a in A_sorted:
    if box_ptr < len(B_sorted) and B_sorted[box_ptr] >= a:
        # Assign this box to this toy
        box_ptr += 1
        matched += 1

# Number of unmatched toys
unmatched_count = N - matched

if unmatched_count == 0:
    # This shouldn't happen since we have N-1 boxes and N toys
    # But logically, we still need one box
    # Actually, unmatched_count should be at least 1
    x = 0
else:
    # We need to find the minimum x such that the largest unmatched toy <= x
    # But which toys are unmatched?

    # Actually, our greedy matching above doesn't tell us which toys are unmatched.
    # Instead, we know that we matched 'matched' toys (the smallest 'matched' toys that could be matched).
    # Therefore, the unmatched toys include some of the larger ones.

    # But note: our greedy matches smallest toy to smallest possible box.
    # So the unmatched toys are not necessarily the largest ones.

    # However, we want to minimize x = size of new box.
    # We can choose which toy goes to the new box. So we want the new box to cover only one toy?
    # No: the new box can hold multiple toys? Wait: problem says "no box can contain two or more toys".
    # So each box holds at most one toy.

    # Therefore, the new box can only hold one toy.
    # So we need to assign one toy to the new box, and the rest to the existing N-1 boxes.

    # So the question becomes: is there a toy we can leave out such that the remaining N-1 toys can be packed into the N-1 boxes?
    # And we want to minimize x, which must be >= the size of the toy we leave out.
    # So we want to maximize the size of the toy we *can* pack, i.e., minimize the size of the toy we must leave out.

    # Therefore: try to leave out each toy and check if the rest can be packed into the boxes.
    # But N up to 200,000 — too slow.

    # Alternate efficient idea:
    # We want to know: what is the minimal x such that there exists a toy of size <= x that we can leave out, and the rest can be packed.

    # So we want to find the minimal value of max_{i in S} A_i over all subsets S of toys of size 1, such that the other N-1 toys can be packed into the N-1 boxes.

    # That is: we want to minimize the size of the toy we leave out, subject to the constraint that the remaining toys can be packed into the boxes.

    # So let’s define:
    #   candidate = minimum over all toys i such that (all toys except i can be packed into the boxes) of A[i]

    # How to check if N-1 toys can be packed into N-1 boxes? Sort both and greedily match.

    # But doing this for each i would be O(N^2 log N) — too slow.

    # Efficient approach:
    # Precompute:
    #   Sort toys: A_sorted
    #   Sort boxes: B_sorted

    # Idea: 
    #   Let’s try to compute for each position i in A_sorted, whether we can pack all toys except A_sorted[i].
    #   We can use two passes:
    #     - Forward pass: can we pack first k toys (in sorted order) using first k boxes?
    #     - Backward pass: can we pack last k toys using last k boxes?

    # Then, for excluding toy at index i, we need:
    #   - Pack toys [0, i-1] with first i boxes
    #   - Pack toys [i+1, N-1] with last (N-1-i) boxes

    # But the boxes are shared globally — we can assign any box to any toy.

    # Actually, since both toys and boxes are sorted, the optimal way to pack a set of toys is to sort them and match smallest box to smallest toy.

    # So: 
    #   Let’s define:
    #     prefix[i] = True if the first i toys (A_sorted[0..i-1]) can be packed into some i boxes from B_sorted
    #     But we want to use the smallest i boxes optimally.

    # Actually, standard greedy: to pack k toys with k boxes, sort both and check if for all j, A_sorted[j] <= B_sorted[j].

    # But here, when we remove one toy, we have N-1 toys and N-1 boxes.

    # So for a fixed excluded toy at index i (in sorted order), we form a new toy array: A_sorted without A_sorted[i].
    # Then sort it (already sorted), and check if for every j from 0 to N-2, new_toys[j] <= B_sorted[j].

    # But we can compute this fast.

    # Let’s define:
    #   Let C be the list A_sorted without element at i.
    #   Then we need C[j] <= B_sorted[j] for all j in [0, N-2].

    # But note: C is A_sorted with one element removed. So:
    #   For j < i: C[j] = A_sorted[j]
    #   For j >= i: C[j] = A_sorted[j+1]

    # So condition becomes:
    #   For j = 0 to i-1: A_sorted[j] <= B_sorted[j]
    #   For j = i to N-2: A_sorted[j+1] <= B_sorted[j]

    # We can precompute:
    #   prefix_ok[i]: whether for all j in [0, i-1], A_sorted[j] <= B_sorted[j]
    #   suffix_ok[i]: whether for all j in [i, N-2], A_sorted[j+1] <= B_sorted[j]

    # Then, removing toy i is feasible if prefix_ok[i] and suffix_ok[i].

    # Note: prefix_ok[0] = True (no elements to check)
    #       prefix_ok[i] = prefix_ok[i-1] and (A_sorted[i-1] <= B_sorted[i-1])

    # Similarly, suffix_ok[N-1] = True (no elements in the second part)
    #       suffix_ok[i] = (A_sorted[i+1] <= B_sorted[i]) and suffix_ok[i+1]? 
    # But note: suffix_ok[i] checks j from i to N-2: condition A_sorted[j+1] <= B_sorted[j]
    # So we can compute backward:

    #   suffix_ok[i] = True for i = N-1
    #   for i from N-2 down to 0: suffix_ok[i] = (A_sorted[i+1] <= B_sorted[i]) and suffix_ok[i+1]

    # But wait: when i = N-1, we are removing the last toy, then the toys are A_sorted[0..N-2], and we require for j=0..N-2: A_sorted[j] <= B_sorted[j]
    #   which is prefix_ok[N-1] (if we define prefix_ok[N-1] as checking j=0 to N-2)

    # Let me redefine:
    #   Let's make prefix_ok[i] = True if for all j in [0, i-1]: A_sorted[j] <= B_sorted[j]
    #   So prefix_ok[0] = True
    #   prefix_ok[1] = (A_sorted[0] <= B_sorted[0])
    #   ...
    #   prefix_ok[N] = (for j=0..N-1: A_sorted[j] <= B_sorted[j]) but B_sorted has only N-1 elements.

    # Actually, we only need prefix_ok for i from 0 to N.

    # Similarly, suffix_ok[i] = True if for all j in [i, N-2]: A_sorted[j+1] <= B_sorted[j]
    #   So j from i to N-2, inclusive.

    # Then, removing toy at index i is possible if:
    #   prefix_ok[i] is True AND suffix_ok[i] is True.

    # Then, the minimal x is min{ A_sorted[i] } over all i such that the above condition holds.

    # Steps:
    prefix_ok = [True] * (N + 1)
    for i in range(1, N):
        prefix_ok[i] = prefix_ok[i-1] and (A_sorted[i-1] <= B_sorted[i-1])
    # For i=N: we need j=0 to N-1 -> but B_sorted has no index N-1? B_sorted has indices 0 to N-2.
    # Correction: prefix_ok[i] should check j from 0 to i-1, but only if i-1 < N-1 (because B_sorted has length N-1)
    # Actually, when i > N-1, we cannot have prefix_ok[i] because we don't have enough boxes.
    # But in our case, i ranges from 0 to N.

    # Let's redefine prefix_ok[i] for i in [0, N]:
    #   It means: the first i toys (indices 0 to i-1) satisfy A_sorted[j] <= B_sorted[j] for j=0 to i-1.
    #   But if i > N-1, then we are trying to access B_sorted[i-1] for i-1 >= N-1 -> index out of bounds.

    # Actually, when i > N-1, we don't need to compute because we are only going to use i from 0 to N, but for i>N-1, the condition prefix_ok[i] would require comparing with non-existent boxes.

    # But note: if i > N-1, then we are trying to pack i toys with boxes, but we only have N-1 boxes, so impossible.
    # However, in our usage, when we remove toy i, we are packing N-1 toys. The split is:
    #   left part: i toys (if we remove at index i, then toys 0..i-1 are i toys) -> requires i <= N-1
    #   right part: N-1-i toys -> requires i>=0 and N-1-i <= N-1-i, obviously.

    # But i can be from 0 to N-1? Actually, index i in A_sorted is from 0 to N-1.

    # So i in [0, N-1].

    # For prefix_ok[i]: we need to check j=0 to i-1: A_sorted[j] <= B_sorted[j]
    #   This requires that i-1 < N-1, i.e., i <= N-1, which is true, but when i==N, we skip because i only to N-1.

    # But when i==N, we don't consider because indices are 0..N-1.

    # So we only need i from 0 to N-1.

    # Let's recompute prefix_ok for i from 0 to N (but only up to N-1 is needed for B_sorted indexing).

    prefix_ok = [True] * (N+1)
    # prefix_ok[0] = True
    for i in range(1, N):  # i from 1 to N-1
        if i == 1:
            prefix_ok[i] = (A_sorted[0] <= B_sorted[0])
        else:
            prefix_ok[i] = prefix_ok[i-1] and (A_sorted[i-1] <= B_sorted[i-1])
    # For i>=N: we don't use, but let's set prefix_ok[N] = False? Actually, we won't use i=N.

    # But note: when i = N, we are removing the last toy, then the left part has N toys? No: removing index i=N-1? 
    # Our A_sorted has indices 0 to N-1. So i in [0, N-1].

    # Now suffix_ok: for i in [0, N-1]
    #   suffix_ok[i] = for all j from i to N-2: A_sorted[j+1] <= B_sorted[j]
    suffix_ok = [True] * (N+1)
    # suffix_ok[N-1] = True (since the range j from N-1 to N-2 is empty)
    # suffix_ok[N] = True (not used)
    # Compute from i = N-2 down to 0:
    suffix_ok[N-1] = True
    # If N==2, then N-2=0, so we start from i=N-2=0.
    for i in range(N-2, -1, -1):
        suffix_ok[i] = (A_sorted[i+1] <= B_sorted[i]) and suffix_ok[i+1]

    # Now, try each i from 0 to N-1:
    candidates = []
    for i in range(N):
        # Check if we can remove toy A_sorted[i]
        # Condition: prefix_ok[i] and suffix_ok[i]
        if prefix_ok[i] and suffix_ok[i]:
            candidates.append(A_sorted[i])

    if not candidates:
        print(-1)
    else:
        print(min(candidates))
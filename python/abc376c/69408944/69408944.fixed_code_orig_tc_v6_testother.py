import heapq

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order to handle largest first
A.sort(reverse=True)
# Sort boxes in descending order
B.sort(reverse=True)

# Try to assign each toy to a box
box_index = 0
for toy_size in A:
    # If we still have existing boxes and the current largest box can fit this toy
    if box_index < len(B) and B[box_index] >= toy_size:
        box_index += 1
    # Otherwise, we need to purchase a new box of at least toy_size
    else:
        print(toy_size)
        exit()

# If all toys were placed without needing a new box, theoretically x could be 0
# But since x must be positive, and we don't need it, any positive value would work
# However, the problem implies we must purchase a box, so we need the minimum size
# Actually, if we used all N-1 boxes, we still need one more box for the last toy
# But our loop above should have caught that

# The above logic has a flaw: we might not need to buy a box if we can fit all toys
# But we have N toys and only N-1 existing boxes, so we always need to buy one box
# The question is: what's the minimum size of that box?

# Let's reconsider: we want to minimize the purchased box size
# We should try to use the existing boxes for the largest toys when possible

# Reset approach: greedy with max-heaps
# Use existing boxes for as many toys as possible, then the largest remaining toy size is the answer

# Sort both arrays
A_sorted = sorted(A)
B_sorted = sorted(B)

# Try to match toys to boxes using greedy from smallest to largest
# This is a better approach: we want to save large boxes for large toys
i = 0  # pointer for toys
j = 0  # pointer for boxes

# Match as many toys as possible to existing boxes
while i < N and j < N - 1:
    if A_sorted[i] <= B_sorted[j]:
        # This toy can go in this box
        i += 1
        j += 1
    else:
        # This toy is too big for the current box, will need new box
        i += 1

# If we matched N-1 or more toys, then the minimum purchased box size is the largest unmatched toy
# But we need to find which toys weren't matched

# Better approach: simulate optimally
# We want to minimize the maximum toy size that doesn't fit in existing boxes
# Strategy: try to fit the N-1 largest toys into the N-1 boxes optimally

A.sort(reverse=True)
B.sort(reverse=True)

# Try to fit the largest N-1 toys into the N-1 boxes
for i in range(N - 1):
    if A[i] > B[i]:
        # The i-th largest toy cannot fit in the i-th largest box
        # We'll need a box at least as big as A[i], but let's see if reordering helps
        # Actually, by pigeonhole principle, if the k largest toys cannot fit in the k largest boxes for any k,
        # then it's impossible? No, we just need to find the minimum x
        
        # We need to purchase a box. What's the minimum size needed?
        # We can try to fit N-1 toys in the existing boxes, and put the largest leftover in the new box
        break

# Greedy assignment: sort toys and boxes in ascending order and try to match
A_asc = sorted(A)
B_asc = sorted(B)

# Find maximum toy size that cannot be covered by optimal assignment
# Use greedy matching: for each box, assign the largest toy that fits
remaining_toys = A_asc[:]
for box_size in B_asc:
    # Find the largest toy that fits in this box
    candidate_toy_idx = -1
    for i in range(len(remaining_toys)):
        if remaining_toys[i] <= box_size:
            if candidate_toy_idx == -1 or remaining_toys[i] > remaining_toys[candidate_toy_idx]:
                candidate_toy_idx = i
    
    if candidate_toy_idx != -1:
        # Remove this toy
        remaining_toys.pop(candidate_toy_idx)

if not remaining_toys:
    # This shouldn't happen since we have N toys and N-1 boxes
    print(1)
else:
    # The largest remaining toy must go in the purchased box
    x = max(remaining_toys)
    print(x)
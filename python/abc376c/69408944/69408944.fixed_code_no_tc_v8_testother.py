import bisect

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order to handle largest toys first
A.sort(reverse=True)
B.sort()

# Try to assign the largest toys to existing boxes using greedy matching
# We want to find the minimum x such that all toys can be placed

# For each toy, we need a box >= its size
# We have N-1 existing boxes and one new box of size x

# Strategy:
# Try to assign the largest possible toys to existing boxes.
# The largest toy that cannot be assigned will require the new box.
# But we must ensure that after using the new box for one toy, 
# the remaining N-1 toys can fit into the N-1 boxes.

# We'll try to simulate: which toy should go to the new box?
# Idea: try to use the new box for the smallest possible x such that
#       the rest of the toys can be matched with existing boxes.

# We can binary search on x, but there's a more direct greedy approach.

# Alternate approach:
# 1. Try to match N-1 largest toys (excluding one) with boxes
# 2. For each candidate toy to be placed in the new box, check if the rest can be assigned
# 3. Then x must be at least the size of that toy

# However, optimal strategy:
# - Sort toys descending, boxes ascending
# - Try to assign the smallest possible set of toys to the new box (just one)
# - So we try to assign N-1 toys to N-1 boxes optimally

# Greedy matching: for the N-1 boxes, assign smallest box that fits each toy
# But since we want to save larger boxes for larger toys, we should process toys in descending order

def can_assign(toys, boxes):
    # Check if we can assign all toys in `toys` to boxes
    # Sort toys descending, boxes ascending
    toys_sorted = sorted(toys, reverse=True)
    boxes_sorted = sorted(boxes)
    
    # For each toy from largest to smallest, assign smallest available box that fits
    j = 0  # pointer in boxes
    for toy in toys_sorted:
        while j < len(boxes_sorted) and boxes_sorted[j] < toy:
            j += 1
        if j >= len(boxes_sorted):
            return False, None
        j += 1
    return True, None

# Try leaving out each toy to put in the new box
min_x = float('inf')

# Sort both
A.sort()
B.sort()

# We'll try each toy as candidate for the new box
for i in range(N):
    # Put toy A[i] in the new box -> x >= A[i]
    remaining_toys = A[:i] + A[i+1:]
    if can_assign(remaining_toys, B)[0]:
        min_x = min(min_x, A[i])

if min_x == float('inf'):
    print(-1)
else:
    print(min_x)
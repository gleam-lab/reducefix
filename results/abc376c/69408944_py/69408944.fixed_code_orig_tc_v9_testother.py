import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # おもちゃ降順
B = list(map(int, input().split()))
B.sort(reverse=True)

# We need to assign each toy to a box (either existing or new)
# Strategy: try to use the largest available boxes for the largest toys
# If we can't fit a toy in any existing box, we need a new box of at least that size

# Use greedy matching: match largest toys with largest boxes when possible
box_idx = 0
new_box_size = 0

for toy_size in A:
    # Try to place this toy in an existing box
    if box_idx < len(B) and B[box_idx] >= toy_size:
        # This toy fits in the current largest available box
        box_idx += 1
    else:
        # Need a new box for this toy
        new_box_size = max(new_box_size, toy_size)

# Check if we have enough boxes (we can only add one new box)
# We used 'box_idx' existing boxes, so we have (N-1 - box_idx) unused existing boxes
# The new box can hold one toy, so total capacity is (box_idx + 1) 
# But we've already accounted for which toys go where

# Actually, we need to verify if our assignment works
# We're using greedy: assign largest toys to largest boxes when possible
# When a toy doesn't fit in the next available largest box, we put it in the new box

# However, we must ensure that we don't need more than one new box
# In our loop above, we track the maximum size needed for the new box
# But we also need to make sure that at most one toy goes to the new box

# Let's reconsider: we want to minimize the new box size
# We should try to put as many toys as possible into existing boxes

# Alternative approach:
# We want to know if we can cover N-1 toys with the N-1 existing boxes
# The remaining toy will go to the new box

# So we need to check whether N-1 largest toys (or some combination) can be covered by the N-1 boxes
# This is a matching problem

# Better approach:
# Sort both toys and boxes in descending order
# Try to match the largest N-1 toys with boxes greedily
# If all N-1 can be matched, then the new box needs to be at least the size of the smallest toy
# Otherwise, we need to see what's the minimum x such that we can match

# Actually, we can use this strategy:
# For each possible candidate for the new box (each toy), try to fit all other toys into the existing boxes
# But that would be O(N^2)

# Efficient approach:
# Sort toys and boxes in descending order
# Try to match the first N-1 toys with the N-1 boxes using greedy
# If we can match all N-1, then answer is the last (smallest) toy size
# Otherwise, we need a larger box

# But wait - maybe it's better to leave a large toy for the new box and fit smaller ones in old boxes

# Correct greedy:
# We want to minimize the required new box size
# So ideally, we'd like to put the smallest toy in the new box
# Can we fit the N-1 largest toys into the N-1 boxes?

# Algorithm:
# Sort A in ascending order, B in ascending order
# Check if we can fit the N-1 largest toys into the N-1 boxes
# Using greedy from largest to smallest

A_sorted = sorted(A)
B_sorted = sorted(B)

# Check if we can fit N-1 largest toys into the boxes
# Try to fit largest toys first
j = N - 2  # pointer for boxes (0-indexed, N-1 boxes)
can_fit = True

# Go through toys from largest to smallest, but skip the smallest one (which would go to new box)
for i in range(N - 1, 0, -1):  # from largest to second smallest
    if j >= 0 and B_sorted[j] >= A_sorted[i]:
        j -= 1
    else:
        can_fit = False
        break

if can_fit:
    print(A_sorted[0])  # smallest toy goes to new box
else:
    # Maybe we need to put a larger toy in the new box
    # Try putting each toy in the new box and see if others can fit
    possible = []
    
    for skip_idx in range(N):
        # Try putting toy A_sorted[skip_idx] in new box
        j = N - 2  # pointer for boxes
        valid = True
        
        # Check all other toys
        for i in range(N - 1, -1, -1):
            if i == skip_idx:
                continue
            if j >= 0 and B_sorted[j] >= A_sorted[i]:
                j -= 1
            else:
                valid = False
                break
                
        if valid:
            possible.append(A_sorted[skip_idx])
    
    if possible:
        print(min(possible))
    else:
        print(-1)
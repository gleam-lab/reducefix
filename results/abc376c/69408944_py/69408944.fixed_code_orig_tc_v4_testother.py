import bisect

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order (largest first)
A.sort(reverse=True)
# Sort boxes in ascending order (smallest first)
B.sort()

# Try to assign the largest toys to existing boxes greedily
# We'll use binary search to find the smallest box that can fit each toy
available_boxes = B[:]  # Make a copy

# For each toy from largest to smallest
for toy_size in A:
    # Find the smallest box that can fit this toy
    pos = bisect.bisect_left(available_boxes, toy_size)
    if pos < len(available_boxes):
        # Found a box, remove it
        available_boxes.pop(pos)
    else:
        # No existing box can fit this toy, we need a new box of size at least toy_size
        print(toy_size)
        exit()

# If we've assigned all toys without needing a new box, 
# we still need to purchase a box (since we have N toys and N-1 existing boxes)
# The minimum size is 1 (smallest possible positive integer)
print(1)
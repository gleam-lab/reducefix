import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # Sort toys in descending order
B = sorted(map(int, input().split()), reverse=True)  # Sort boxes in descending order

# We need to assign each toy to a box (either existing or the new one)
# Strategy: try to match largest toys with largest available boxes
# If a toy doesn't fit in any remaining box, we'll need our purchased box to be at least that size

# Use two pointers for greedy matching
box_idx = 0
unfit_toys = []

for toy_size in A:
    if box_idx < len(B) and B[box_idx] >= toy_size:
        # This box can fit the toy
        box_idx += 1
    else:
        # This toy cannot be placed in any remaining existing box
        unfit_toys.append(toy_size)

# If more than one toy doesn't fit in existing boxes, we can't store all toys (only one new box allowed)
if len(unfit_toys) == 0:
    # All toys fit in existing boxes, so minimum x is just the smallest possible (but must be positive)
    print(1)
elif len(unfit_toys) == 1:
    # Only one toy doesn't fit, so our purchased box must fit that toy
    print(unfit_toys[0])
else:
    # More than one toy doesn't fit, but we can only buy one box -> impossible
    print(-1)
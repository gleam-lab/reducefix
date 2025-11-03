import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # おもちゃ降順
B = sorted(map(int, input().split()), reverse=True)  # 箱も降順

# Check if it's possible to assign toys to boxes without the new box
# We try to greedily assign largest toys to largest available boxes
boxes = B[:]
toy_idx = 0

# Try to assign as many toys as possible using existing boxes
for box_size in boxes:
    if toy_idx >= N:
        break
    if A[toy_idx] <= box_size:
        toy_idx += 1

# If all toys can be placed in existing boxes, we don't need a new box
# But we still need to find minimum x such that we can place all toys
if toy_idx == N:
    print(1)  # We can use smallest possible box (size 1) since all toys are already placed
else:
    # We need to place the remaining toys in the new box
    # The new box must be at least as large as the largest unassigned toy
    remaining_toys = A[toy_idx:]
    if remaining_toys:
        min_x = max(remaining_toys)
        
        # Verify that with this x, we can place all toys
        # Use greedy: assign largest toys to largest boxes, and the rest to new box
        box_ptr = 0
        toy_ptr = 0
        
        # Simulate assignment
        while toy_ptr < N and box_ptr < len(B):
            if A[toy_ptr] <= B[box_ptr]:
                toy_ptr += 1
                box_ptr += 1
            else:
                # This toy cannot go in current box, must go in new box
                # But we haven't assigned it yet - we'll check later
                break
        
        # All remaining toys must fit in the new box
        # Since we're using the maximum remaining toy size as x,
        # and we assign only remaining toys to the new box, it should work
        print(min_x)
    else:
        print(1)
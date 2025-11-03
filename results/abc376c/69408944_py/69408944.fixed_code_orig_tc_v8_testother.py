import sys

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort toys in descending order (largest first)
    A.sort(reverse=True)
    # Sort boxes in descending order (largest first)
    B.sort(reverse=True)
    
    # We need to assign each toy to a box.
    # Idea: Try to use existing boxes for the largest toys possible.
    # For the remaining toy (if any), we need to buy a box of size at least that toy's size.
    
    # Use two pointers: one for toys, one for boxes
    toy_idx = 0
    box_idx = 0
    
    # Try to assign toys to existing boxes
    while toy_idx < N and box_idx < N - 1:
        if A[toy_idx] <= B[box_idx]:
            # This toy can fit in this box
            toy_idx += 1
            box_idx += 1
        else:
            # This toy is too big for the current largest available box
            # So we'll need to buy a new box for this toy
            # But let's check if we can handle all remaining toys with the remaining boxes + one new box
            break
    
    # If we've assigned all toys using existing boxes, no need to buy a box
    if toy_idx == N:
        print(1)  # Minimum box size is 1 (or any positive integer)
        return
    
    # At this point, either:
    # 1. We have a toy that doesn't fit in the current box, or
    # 2. We've run out of boxes
    
    # We need to buy a box for at least one toy.
    # The question is: can we assign all toys using the N-1 existing boxes plus one new box?
    
    # Let's think differently:
    # We want to know the minimum x such that we can assign all toys.
    # We can try to simulate: use the new box for one toy, and see if the rest can be assigned.
    
    # Strategy: For each toy, try using the new box for that toy,
    # and check if the remaining N-1 toys can fit in the N-1 existing boxes.
    
    min_x = float('inf')
    
    # For each toy i, suppose we put toy i in the new box
    for i in range(N):
        # Size of new box must be at least A[i]
        required_size = A[i]
        
        # Now check if the remaining N-1 toys can fit in the N-1 existing boxes
        remaining_toys = A[:i] + A[i+1:]
        remaining_toys.sort(reverse=True)  # sort in descending order
        
        # Try to match remaining toys with boxes greedily
        box_ptr = 0
        valid = True
        
        for toy_size in remaining_toys:
            if box_ptr < len(B) and B[box_ptr] >= toy_size:
                box_ptr += 1
            else:
                valid = False
                break
        
        if valid:
            min_x = min(min_x, required_size)
    
    if min_x == float('inf'):
        print(-1)
    else:
        print(min_x)

solve()
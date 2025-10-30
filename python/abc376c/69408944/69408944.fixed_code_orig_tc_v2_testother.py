import sys

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort toys in descending order to handle largest first
    A.sort(reverse=True)
    B.sort(reverse=True)
    
    # We need to assign each toy to a box (either existing or the new one)
    # We want to minimize the size x of the new box
    
    # Try to use the largest available boxes for the largest toys
    # If we can't assign all toys without the new box, then we need it
    
    # Use two pointers: one for toys, one for existing boxes
    toy_idx = 0
    box_idx = 0
    
    # First, try to assign as many toys as possible to existing boxes
    while toy_idx < N and box_idx < N - 1:
        if B[box_idx] >= A[toy_idx]:
            # This box can hold this toy
            box_idx += 1
            toy_idx += 1
        else:
            # Current largest box cannot hold current largest toy
            # So we need a new box for this toy
            break
    
    # If we've assigned all toys, no new box is needed
    if toy_idx == N:
        print(1)  # Minimum box size is 1
        return
    
    # Otherwise, we need a new box. The new box must be able to hold
    # all remaining toys that couldn't be assigned.
    # Since we're processing in descending order, the largest unassigned
    # toy determines the minimum size of the new box.
    min_x = A[toy_idx]
    
    # But we need to check if it's actually possible to assign all remaining toys
    # with just one additional box.
    # We've already used box_idx boxes from the existing ones.
    # The remaining existing boxes are B[box_idx:] (sorted in descending order)
    # The remaining toys are A[toy_idx:] (sorted in descending order)
    
    # We need to check if we can assign the remaining toys using at most one new box
    # Let's simulate: we'll try to use the existing boxes optimally for the remaining toys
    
    remaining_toys = A[toy_idx:]
    remaining_boxes = B[box_idx:]
    
    # Use greedy matching: for each remaining toy (in descending order),
    # try to match with the largest available box that can fit it
    box_ptr = 0
    toy_ptr = 0
    
    while toy_ptr < len(remaining_toys) and box_ptr < len(remaining_boxes):
        if remaining_boxes[box_ptr] >= remaining_toys[toy_ptr]:
            box_ptr += 1
            toy_ptr += 1
        else:
            # This toy cannot be placed in any remaining existing box
            # It must go to the new box
            min_x = max(min_x, remaining_toys[toy_ptr])
            toy_ptr += 1
    
    # Any remaining toys must also go to the new box
    while toy_ptr < len(remaining_toys):
        min_x = max(min_x, remaining_toys[toy_ptr])
        toy_ptr += 1
    
    # However, we need to verify if our approach is correct
    # Alternative approach: binary search on the answer or proper greedy
    
    # Let's use a more robust approach:
    # For a given x, can we fit all toys?
    # We can sort both arrays and use greedy assignment
    
    def can_fit(x):
        # Can we fit all toys using existing boxes and one box of size x?
        toys = sorted(A, reverse=True)
        boxes = sorted(B + [x], reverse=True)
        
        # Try to assign largest toys to largest boxes
        t_idx = 0
        b_idx = 0
        
        while t_idx < len(toys) and b_idx < len(boxes):
            if boxes[b_idx] >= toys[t_idx]:
                b_idx += 1
                t_idx += 1
            else:
                # This box is too small for this toy
                # Skip this box
                b_idx += 1
                
        return t_idx == len(toys)
    
    # Binary search on x
    lo = 1
    hi = 10**9 + 1
    
    if not can_fit(hi):
        print(-1)
        return
    
    while lo < hi:
        mid = (lo + hi) // 2
        if can_fit(mid):
            hi = mid
        else:
            lo = mid + 1
    
    print(lo)

solve()
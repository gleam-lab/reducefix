import sys

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort toys in descending order to handle largest toys first
    A.sort(reverse=True)
    B.sort(reverse=True)
    
    # We need to assign each toy to a box
    # Idea: Try to assign the largest available box to the largest unassigned toy
    # If at any point we can't assign a toy, we need a new box of size >= that toy
    
    # Use two pointers for boxes and toys
    box_idx = 0
    required_size = -1
    
    for toy_size in A:
        # Try to assign current toy to an existing box
        if box_idx < len(B) and B[box_idx] >= toy_size:
            # This box can hold this toy
            box_idx += 1
        else:
            # We need a new box for this toy
            # The new box must be at least as large as this toy
            if required_size == -1:
                required_size = toy_size
            # Once we decide to use a new box, all remaining toys 
            # that can't fit in remaining boxes will go to either existing boxes or this new box
            # But since we're processing toys in descending order, if a toy is larger than 
            # the largest remaining box, it must go to our new box
            
            # However, we can only have one new box, so we just track the minimum size needed
    
    # Check if we actually need a new box
    if required_size == -1:
        # All toys were assigned to existing boxes
        # But we still need to purchase a box (we have N-1 boxes but N toys)
        # So we need a box of size 1 (minimum possible)
        return 1
    
    # Verify that with a box of size 'required_size', we can fit all toys
    # Count how many toys can be placed in existing boxes
    box_ptr = 0
    used_boxes = 0
    
    for toy_size in sorted(A, reverse=True):
        if box_ptr < len(B) and B[box_ptr] >= toy_size:
            box_ptr += 1
            used_boxes += 1
    
    # If we can place at most N-1 toys in existing boxes, then one toy needs the new box
    # Since we're using greedy assignment, this should work
    if used_boxes < N:
        return required_size
    else:
        # This shouldn't happen given our logic above
        return required_size

# Let's implement a cleaner solution
def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort both arrays in descending order
    A.sort(reverse=True)
    B.sort(reverse=True)
    
    # Try to match largest toys with largest boxes greedily
    box_idx = 0
    min_new_box_size = 0
    
    for toy_size in A:
        if box_idx < len(B) and B[box_idx] >= toy_size:
            box_idx += 1
        else:
            # This toy cannot fit in any remaining existing box
            # It must go to the new box we purchase
            min_new_box_size = max(min_new_box_size, toy_size)
    
    # If we didn't need any new box for any toy, we still need to buy one
    # (since we have N toys and only N-1 existing boxes)
    if min_new_box_size == 0:
        print(1)
    else:
        # Now verify that this solution works
        # Count how many toys can be accommodated in existing boxes
        # when we reserve boxes optimally for toys that don't need the new box
        
        # Actually, our greedy approach is correct:
        # - Sort toys and boxes in descending order
        # - For each toy, if the largest remaining box fits it, use that box
        # - Otherwise, the toy must go to the new box
        # - The answer is the maximum size among toys assigned to the new box
        
        # But we need to check if it's even possible
        # The only constraint is we can only have one new box
        
        # In our algorithm above, we're already determining which toys need the new box
        # and taking the maximum such toy size
        
        print(min_new_box_size)

# Corrected version with proper logic
def final_solve():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort in descending order
    A.sort(reverse=True)
    B.sort(reverse=True)
    
    # Greedy matching: try to fit largest toys into largest boxes
    box_idx = 0
    needed_for_new_box = []
    
    for toy_size in A:
        if box_idx < len(B) and B[box_idx] >= toy_size:
            box_idx += 1
        else:
            needed_for_new_box.append(toy_size)
    
    # If more than one toy needs the new box, it's impossible
    # because we can only have one new box
    if len(needed_for_new_box) > 1:
        print(-1)
        return
    
    # If exactly one toy needs the new box, that's our answer
    if len(needed_for_new_box) == 1:
        print(needed_for_new_box[0])
        return
    
    # If no toy needs the new box, it means we could theoretically
    # fit all toys in existing boxes, but we must purchase a box anyway
    # So we can purchase a box of size 1 (minimum)
    print(1)

final_solve()
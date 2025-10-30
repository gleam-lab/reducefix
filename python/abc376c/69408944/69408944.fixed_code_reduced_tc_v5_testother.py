import heapq

def solve():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    
    # Sort toys in descending order to assign largest toys first
    A.sort(reverse=True)
    # Sort boxes in descending order
    B.sort(reverse=True)
    
    # We need to check if it's possible to fit all toys using the existing N-1 boxes
    # and one additional box of size x. We want the minimal such x.
    
    # Try to assign the largest toys to the largest available boxes
    box_idx = 0
    remaining_toys = []
    
    for toy_size in A:
        if box_idx < len(B) and B[box_idx] >= toy_size:
            # This toy can go into an existing box
            box_idx += 1
        else:
            # This toy cannot go into any remaining existing box
            remaining_toys.append(toy_size)
    
    # After trying all existing boxes, if we have more than one toy left,
    # we cannot fit them because we only have one new box
    if len(remaining_toys) == 0:
        # All toys fit in existing boxes, so we don't need a large box
        # But we still need to buy one box, so minimal size is 1
        return 1
    elif len(remaining_toys) == 1:
        # Only one toy needs the new box
        return remaining_toys[0]
    else:
        # Two or more toys cannot fit in existing boxes, but we only have one new box
        # So impossible
        return -1

print(solve())
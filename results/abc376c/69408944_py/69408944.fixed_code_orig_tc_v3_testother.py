import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # おもちゃ降順
B = list(map(int, input().split()))
B.sort(reverse=True)

# Check if it's possible to assign toys to boxes without purchasing a new box
# We try to assign the largest toys to the largest available boxes first
boxes = B[:]
box_idx = 0
can_assign_without_new_box = True

for toy_size in A:
    if box_idx < len(boxes) and boxes[box_idx] >= toy_size:
        box_idx += 1
    else:
        can_assign_without_new_box = False
        break

if can_assign_without_new_box:
    print(0)
else:
    # We need a new box. Let's find the minimum size required.
    # Use greedy approach: assign largest toys to largest existing boxes,
    # then the remaining largest toy will determine the minimum new box size.
    
    # Create a max heap for boxes
    box_heap = [-b for b in B]
    heapq.heapify(box_heap)
    
    # Try to assign toys to existing boxes (largest first)
    remaining_toys = []
    for toy_size in A:
        if box_heap and -box_heap[0] >= toy_size:
            # Can place this toy in the largest available box
            heapq.heappop(box_heap)
        else:
            # Cannot place this toy in any remaining box
            remaining_toys.append(toy_size)
    
    if not remaining_toys:
        print(0)
    else:
        # The largest remaining toy determines the minimum box size needed
        min_x = max(remaining_toys)
        
        # Verify that with a box of size min_x, we can fit all toys
        # Count how many boxes we have total (N-1 existing + 1 new)
        total_boxes = N
        
        # Sort both toys and boxes (existing + one new of size min_x)
        all_boxes = B + [min_x]
        all_boxes.sort(reverse=True)
        toys_sorted = sorted(A, reverse=True)
        
        # Check if assignment is possible
        box_ptr = 0
        valid = True
        for toy_size in toys_sorted:
            if box_ptr < total_boxes and all_boxes[box_ptr] >= toy_size:
                box_ptr += 1
            else:
                valid = False
                break
                
        if valid:
            print(min_x)
        else:
            print(-1)
import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # Toys in descending order
B = list(map(int, input().split()))

# Use a max-heap for available boxes (using negative values for min-heap as max-heap)
box_heap = [-b for b in B]
heapq.heapify(box_heap)

# Try to assign toys using existing boxes greedily
unassigned_toys = []

for toy_size in A:
    assigned = False
    # We'll collect boxes that are too small temporarily
    temp_boxes = []
    
    while box_heap:
        max_box = -heapq.heappop(box_heap)
        if max_box >= toy_size:
            # Assign this toy to the largest possible box that fits
            assigned = True
            break
        else:
            # Box is too small, save for later
            temp_boxes.append(max_box)
    
    # Push back unused boxes
    for b in temp_boxes:
        heapq.heappush(box_heap, -b)
    
    if not assigned:
        unassigned_toys.append(toy_size)

# If more than one toy can't be placed, we need more than one new box -> impossible
if len(unassigned_toys) == 0:
    print(1)  # Minimum valid x is at least 1, but we can choose smallest possible
elif len(unassigned_toys) == 1:
    print(unassigned_toys[0])
else:
    print(-1)
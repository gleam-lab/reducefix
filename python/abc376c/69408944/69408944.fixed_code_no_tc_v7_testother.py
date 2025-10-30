import bisect

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Sort toys in descending order to try to place the largest ones first
A.sort(reverse=True)
B.sort()

# We'll simulate whether a given x (size of new box) works
def can_place(x):
    # Use a sorted list of available box sizes (original boxes + new box of size x)
    boxes = B[:]  # Copy of original boxes
    boxes.append(x)
    boxes.sort()
    
    # Try to assign each toy to a box using greedy matching: for each toy (from large to small),
    # find the smallest box that fits it (to save larger boxes for bigger toys later)
    for a in A:
        # Find the leftmost box >= a
        idx = bisect.bisect_left(boxes, a)
        if idx == len(boxes):
            return False  # No box can fit this toy
        # Remove the box we're using
        boxes.pop(idx)
    return True

# Binary search on x
lo, hi = 1, 10**9 + 1
ans = -1

while lo <= hi:
    mid = (lo + hi) // 2
    if can_place(mid):
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1

print(ans)
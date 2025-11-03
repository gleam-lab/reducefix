import math

N = int(input())
X = 0
Y = 0
total_cost = 0.0

# Store the first point to compute return to origin later, but we can just simulate the full path
prev_x, prev_y = 0, 0

for i in range(N):
    x, y = map(int, input().split())
    # Distance from current point (prev_x, prev_y) to next point (x, y)
    dx = x - prev_x
    dy = y - prev_y
    total_cost += math.sqrt(dx*dx + dy*dy)
    prev_x, prev_y = x, y

# Add distance to return to origin (0, 0)
dx = 0 - prev_x
dy = 0 - prev_y
total_cost += math.sqrt(dx*dx + dy*dy)

print(total_cost)
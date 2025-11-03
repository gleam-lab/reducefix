import math

N = int(input())
X = 0
Y = 0
total_cost = 0.0

# Store the points
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# Start at origin (0,0)
current_x, current_y = 0, 0

# Go from origin to each point in order
for i in range(N):
    next_x, next_y = points[i]
    dx = current_x - next_x
    dy = current_y - next_y
    total_cost += math.sqrt(dx*dx + dy*dy)
    current_x, current_y = next_x, next_y

# Return from last point to origin
dx = current_x - 0
dy = current_y - 0
total_cost += math.sqrt(dx*dx + dy*dy)

print(total_cost)
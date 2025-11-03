import math

N = int(input())
X = 0
Y = 0
result = 0.0

# Store the points to visit
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# Start at origin, go through each point in order
current_x, current_y = 0, 0
for i in range(N):
    next_x, next_y = points[i]
    # Distance from current point to next point
    dx = current_x - next_x
    dy = current_y - next_y
    result += math.sqrt(dx * dx + dy * dy)
    current_x, current_y = next_x, next_y

# Return to origin
dx = current_x - 0
dy = current_y - 0
result += math.sqrt(dx * dx + dy * dy)

print(result)
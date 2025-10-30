import math

N = int(input())
X = 0
Y = 0
total_cost = 0.0

# Store all points
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# Start from origin (0, 0)
current_x, current_y = 0, 0

# Visit each point in order
for i in range(N):
    next_x, next_y = points[i]
    # Distance from current point to next point
    distance = math.sqrt((next_x - current_x)**2 + (next_y - current_y)**2)
    total_cost += distance
    current_x, current_y = next_x, next_y

# Return to origin
distance_to_origin = math.sqrt((0 - current_x)**2 + (0 - current_y)**2)
total_cost += distance_to_origin

print(total_cost)
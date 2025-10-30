import math

N = int(input())

# Start at origin (0, 0)
x, y = 0, 0
total_cost = 0.0

# Read all points and calculate distances
for _ in range(N):
    x_next, y_next = map(int, input().split())
    # Distance from current point to next point
    distance = math.sqrt((x - x_next)**2 + (y - y_next)**2)
    total_cost += distance
    # Update current position
    x, y = x_next, y_next

# Add distance from last point back to origin
distance_to_origin = math.sqrt((x - 0)**2 + (y - 0)**2)
total_cost += distance_to_origin

print(total_cost)
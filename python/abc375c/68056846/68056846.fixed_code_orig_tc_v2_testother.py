import math

N = int(input())
X = 0
Y = 0
result = 0.0

# Store all points
points = []
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# Start from origin (0,0)
current_x, current_y = 0, 0

# Move to each point in order
for i in range(N):
    next_x, next_y = points[i]
    # Calculate distance
    distance = math.sqrt((current_x - next_x)**2 + (current_y - next_y)**2)
    result += distance
    # Update current position
    current_x, current_y = next_x, next_y

# Return to origin
distance_to_origin = math.sqrt((current_x - 0)**2 + (current_y - 0)**2)
result += distance_to_origin

print(result)
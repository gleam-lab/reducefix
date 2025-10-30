import math

N = int(input())
X, Y = 0, 0
total_cost = 0.0

# Read all points and calculate distance from current to next
for _ in range(N):
    x, y = map(int, input().split())
    # Distance from current point (X, Y) to next point (x, y)
    dx = X - x
    dy = Y - y
    total_cost += math.sqrt(dx * dx + dy * dy)
    # Update current position
    X, Y = x, y

# Distance from last point back to origin (0, 0)
dx = X - 0
dy = Y - 0
total_cost += math.sqrt(dx * dx + dy * dy)

print(total_cost)
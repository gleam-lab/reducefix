import math

N = int(input())
X, Y = 0, 0
total_cost = 0.0

# Read all points and calculate distances sequentially
for i in range(N):
    X_next, Y_next = map(int, input().split())
    # Distance from current point to next point
    dx = X_next - X
    dy = Y_next - Y
    total_cost += math.sqrt(dx*dx + dy*dy)
    # Update current position
    X, Y = X_next, Y_next

# Distance from last point back to origin (0, 0)
dx = 0 - X
dy = 0 - Y
total_cost += math.sqrt(dx*dx + dy*dy)

print(total_cost)
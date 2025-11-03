import math

N = int(input())
X = 0
Y = 0
total_cost = 0.0

# Start from origin, visit each point in order
for i in range(N):
    X_next, Y_next = map(int, input().split())
    # Distance from current point to next point
    dx = X - X_next
    dy = Y - Y_next
    total_cost += math.sqrt(dx*dx + dy*dy)
    # Update current position
    X, Y = X_next, Y_next

# Return to origin from last point
dx = X - 0
dy = Y - 0
total_cost += math.sqrt(dx*dx + dy*dy)

print(total_cost)
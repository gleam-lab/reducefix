import math

N = int(input())
X, Y = 0, 0
result = 0.0

# Read all points and calculate distance from current to next
for _ in range(N):
    X_next, Y_next = map(int, input().split())
    # Distance from current point (X, Y) to next point (X_next, Y_next)
    dx = X - X_next
    dy = Y - Y_next
    result += math.sqrt(dx * dx + dy * dy)
    # Update current position
    X, Y = X_next, Y_next

# Return to origin (0, 0)
dx = X - 0
dy = Y - 0
result += math.sqrt(dx * dx + dy * dy)

print(result)
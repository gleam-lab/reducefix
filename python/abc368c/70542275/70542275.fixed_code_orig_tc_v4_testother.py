n = int(input())
h = list(map(int, input().split()))

t = 0
i = 0

while i < n:
    # Skip enemies that are already defeated
    while i < n and h[i] <= 0:
        i += 1
    if i >= n:
        break
        
    # Attack the frontmost alive enemy
    t += 1
    if t % 3 == 0:
        h[i] -= 3
    else:
        h[i] -= 1

print(t)
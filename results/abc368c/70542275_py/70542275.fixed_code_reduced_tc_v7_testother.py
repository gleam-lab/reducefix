n = int(input())
h = list(map(int, input().split()))

t = 0
i = 0

while i < n:
    # Skip enemies that are already defeated
    if h[i] <= 0:
        i += 1
        continue
        
    t += 1
    # Attack the frontmost enemy with health > 0
    if t % 3 == 0:
        h[i] -= 3
    else:
        h[i] -= 1

print(t)
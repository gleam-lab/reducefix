n = int(input())
h = list(map(int, input().split()))

t = 0
pos = 0  # current enemy position

while pos < n:
    t += 1
    # Attack the frontmost enemy with health > 0
    if h[pos] > 0:
        if t % 3 == 0:
            h[pos] -= 3
        else:
            h[pos] -= 1
        
        # If current enemy's health drops to 0 or below, move to next enemy
        if h[pos] <= 0:
            pos += 1

print(t)
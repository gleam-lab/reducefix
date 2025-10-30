n = int(input())
h = list(map(int, input().split()))
t = 0

for i in range(n):
    # Process current enemy until its health drops to 0 or below
    while h[i] > 0:
        t += 1
        if t % 3 == 0:
            h[i] -= 3
        else:
            h[i] -= 1

print(t)
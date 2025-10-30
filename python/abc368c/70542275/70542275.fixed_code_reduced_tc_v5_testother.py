n = int(input())
h = list(map(int, input().split()))

t = 0
enemy_index = 0

while enemy_index < n:
    t += 1
    # Attack the frontmost enemy with health > 0
    if h[enemy_index] > 0:
        if t % 3 == 0:
            h[enemy_index] -= 3
        else:
            h[enemy_index] -= 1
        
        # If current enemy's health drops to 0 or below, move to next enemy
        if h[enemy_index] <= 0:
            enemy_index += 1

print(t)
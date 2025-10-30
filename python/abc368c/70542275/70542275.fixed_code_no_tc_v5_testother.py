n = int(input())
h = list(map(int, input().split()))

t = 0
enemy_index = 0

while enemy_index < n:
    t += 1
    
    # Attack the frontmost alive enemy
    if t % 3 == 0:
        h[enemy_index] -= 3
    else:
        h[enemy_index] -= 1
    
    # If current enemy is defeated, move to next enemy
    if h[enemy_index] <= 0:
        enemy_index += 1

print(t)
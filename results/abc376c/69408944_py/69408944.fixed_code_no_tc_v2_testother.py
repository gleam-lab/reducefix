import heapq

N = int(input())
A = sorted(map(int, input().split()))  # おもちゃ昇順
B = list(map(int, input().split()))

# 最小ヒープ
hp = []
heapq.heapify(hp)

x = -1
for a in A:
    while hp and hp[0] < a:
        heapq.heappop(hp)
    if hp:  # 箱が残っている
        Min = hp[0]  # 最小の箱
        if a <= Min:
            continue  # この箱でOK
        else:
            x = a  # 新しい箱が必要
            break
    else:
        x = a  # 箱がもう無いので新しい箱
        break

if x == -1:
    print(-1)
else:
    print(max(x, max(B) + 1))
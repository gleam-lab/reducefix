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
    if hp:
        continue
    else:
        x = a
        heapq.heappush(hp, a)

if x == -1:
    print(-1)
else:
    print(max(x, max(B)))
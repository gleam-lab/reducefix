import heapq

N = int(input())
A = sorted(map(int, input().split()), reverse=True)  # おもちゃ降順
B = list(map(int, input().split()))

# 最大ヒープ（負にして格納）
hp = [-b for b in B]
heapq.heapify(hp)

x = -1
for a in A:
    if hp:  # 箱が残っている
        Max = -heapq.heappop(hp)  # 最大の箱
        if a <= Max:
            continue  # この箱でOK
        else:
            x = a  # 新しい箱が必要
            break
    else:
        x = a  # 箱がもう無いので新しい箱
        break

print(x)

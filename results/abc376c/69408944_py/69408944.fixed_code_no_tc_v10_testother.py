import heapq

N = int(input())
A = sorted(map(int, input().split()))  # おもちゃ昇順
B = list(map(int, input().split()))

# 最小ヒープ
hp = [b for b in B]
heapq.heapify(hp)

x = -1
for a in A:
    if hp:  # 箱が残っている
        Min = heapq.heappop(hp)  # 最小の箱
        if a <= Min:
            continue  # この箱でOK
        else:
            x = a  # 新しい箱が必要
            break
    else:
        x = a  # 箱がもう無いので新しい箱
        break

print(x)
import math
N = int(input())

initial = '0 0'
X = 0
Y = 0
result = 0
for _ in range(N):
    if _ == N: ## 最後は初期位置に戻る
        initX, initY = map(int, initial.split())
        A = (X - initX) ** 2 + (Y - initY) ** 2
        result += math.sqrt(A)
    else:
        _X,_Y = map(int, input().split())
        A = (X - _X) ** 2 + (Y - _Y) ** 2
        result += math.sqrt(A)

print(result)
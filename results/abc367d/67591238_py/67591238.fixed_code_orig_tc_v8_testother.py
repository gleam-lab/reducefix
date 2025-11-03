from collections import defaultdict

N, M = map(int, input().split())
A = list(map(int, input().split()))

# 累積和
cum = [0] * (N + 1)
for i in range(N):
    cum[i + 1] = cum[i] + A[i]

# mod M の値の出現回数
count_mod = defaultdict(int)
answer = 0

# 各累積和に対して、同じmod Mの値を持つ過去の累積和とのペアをカウント
for val in cum:
    mod = val % M
    answer += count_mod[mod]
    count_mod[mod] += 1

print(answer)
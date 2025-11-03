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

# 全ての累積和に対して処理
for val in cum:
    mod = val % M
    answer += count_mod[mod]  # すでに同じmodのものとペアになれる
    count_mod[mod] += 1

# もう一度ループして、反時計回りの経路がMの倍数になるペアを追加
# 反時計回りの距離は total - clockwise_distance
total = cum[N]
for i in range(N + 1):
    for j in range(i + 1, N + 1):
        clockwise_dist = cum[j] - cum[i]
        counterclockwise_dist = total - clockwise_dist
        
        # 時計回りも反時計回りもMの倍数でない場合、スキップ
        if clockwise_dist % M != 0 and counterclockwise_dist % M != 0:
            continue
            
        # 既に時計回りでカウントしたペアかどうか確認
        # s = i+1, t = j+1 (ただしインデックスは1から始まる)
        s = i + 1 if i < N else 1
        t = j + 1 if j < N else 1
        if s == t:
            continue
            
        # このペアはまだカウントされていないか？
        # 上の累積和の方法では、clockwise_dist % M == 0 のみカウントしている
        if clockwise_dist % M == 0:
            # これは既にカウントされている
            continue
        elif counterclockwise_dist % M == 0:
            # これはまだカウントされていないので追加
            answer += 1

print(answer)
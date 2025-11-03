from collections import defaultdict

N, M = map(int, input().split())
A = list(map(int, input().split()))

# 累積和を計算（時計回りの距離）
cum = [0] * (N + 1)
for i in range(N):
    cum[i + 1] = cum[i] + A[i]

# 全体の周長
total = cum[N]

# mod M での出現頻度をカウント
count_mod = defaultdict(int)
answer = 0

for val in cum:
    mod = val % M
    # すでに同じmodの値があれば、それとのペアはMの倍数の距離
    answer += count_mod[mod]
    count_mod[mod] += 1

# 反時計回りの経路がより短い場合を除外する必要がある
# → s != t かつ、時計回り距離 d が total - d より大きくない（<=）なら良いが、
#    実際には問題文は「時計回りにs→tに行く最小ステップ数」と定義している。
# しかし実際には、時計回りと反時計回りのうち短い方を使うのが自然だが、
# 問題文をよく読むと、「時計回りにs→tへ行くのに必要な最小ステップ数」とある。
# つまり、強制的に時計回りに進まなければならない。

# ただし、時計回りに一周以上するような経路は意味がないので、
# 単純に累積和の差（mod Mで0）を見ていても、
# 距離が total を超えるような組み合わせを含んでしまう可能性がある。

# しかし、今回の累積和の取り方では、
# cum[j] - cum[i] は rest i から rest j への時計回り距離（i < j のとき）
# そして、これは常に total 未満である（なぜなら、i < j なら cum[j]-cum[i] < total）

# また、j < i の場合は、cum[j] - cum[i] は負になるが、
# mod M で一致しても、実際に時計回り距離は cum[j] + total - cum[i] となる。
# しかし、このコードでは cum 配列のすべての要素に対して mod を取っており、
# 例えば cum[i] ≡ cum[j] (mod M) なら、|cum[j] - cum[i]| が M の倍数。
# ただし、j > i のとき、時計回り距離は cum[j] - cum[i] であり、これが M の倍数。
# j < i のとき、時計回り距離は cum[j] + total - cum[i] だが、
# これは cum[j] - cum[i] + total であり、これが M の倍数かどうかは別途考えるべき？

# 問題文: 「時計回りに s から t へ行く」
# s=3, t=1 のとき、時計回りに 3→4→...→N→1 なので、距離は cum[1] + total - cum[3]

# つまり、一般に s ≠ t について、時計回り距離は：
# if s < t: dist = cum[t] - cum[s]
# if s > t: dist = cum[t] + total - cum[s] = (cum[t] - cum[s]) % total （ただし正の剰余）

# しかし、(cum[t] - cum[s]) % total が M の倍数かどうかではなく、
# 実際の距離が M の倍数かどうか。

# ここで重要な観察：
# 時計回り距離 d が M の倍数 ⇔ (cum[t] - cum[s]) ≡ 0 (mod M) とは限らない。
# なぜなら、s > t のとき、d = cum[t] - cum[s] + total なので、
# d ≡ 0 (mod M) ⇔ (cum[t] - cum[s] + total) ≡ 0 (mod M)

# つまり、単に cum[i] ≡ cum[j] (mod M) なペアを数えるだけでは不十分。

# 正しいアプローチ：
# 各 s, t (s ≠ t) に対して、時計回り距離が M の倍数であるものを数えたい。
# 時計回り距離 d(s,t) = (cum[t] - cum[s]) % total
# ただし、% total は正の剰余。実際には：
#   if s < t: d = cum[t] - cum[s]
#   if s > t: d = cum[t] - cum[s] + total

# d ≡ 0 (mod M) であればよい。

# つまり、
# case 1: s < t のとき： cum[t] - cum[s] ≡ 0 (mod M) → cum[t] ≡ cum[s] (mod M)
# case 2: s > t のとき： cum[t] - cum[s] + total ≡ 0 (mod M) → cum[t] ≡ cum[s] - total (mod M)

# したがって、累積和の mod M を見ながら、
# 各位置 i に対して、
# - 左側にある j (< i) で cum[j] ≡ cum[i] (mod M) なものを数える（s=j, t=i のケース）
# - 左側にある j (< i) で cum[j] ≡ (cum[i] - total) % M (mod M) なものを数える（s=i, t=j のケース、つまり i > j）

# 注意：s ≠ t なので、自分自身とのペアは除く。が、累積和配列には cum[0] があるので注意。

# 改良されたアルゴリズム：
# cum[0], cum[1], ..., cum[N] を順に処理。
# 各 i に対して：
#   - cum[i] % M と同じ値を持つ j < i の個数を加算（これは s=j, t=i で s < t）
#   - (cum[i] - total) % M と同じ値を持つ j < i の個数を加算（これは s=i, t=j で s > t）
# ただし、j は rest area の開始点に対応。cum[j] は rest area j までに要する距離。

# なぜなら：
#   s=j, t=i (j < i): 距離 = cum[i] - cum[j] → Mの倍数 ⇔ cum[i] ≡ cum[j] (mod M)
#   s=i, t=j (i > j): 距離 = cum[j] + total - cum[i] → Mの倍数 ⇔ (cum[j] - cum[i] + total) ≡ 0 ⇒ cum[j] ≡ cum[i] - total (mod M)

# したがって、以下のように修正：

count_mod = defaultdict(int)
answer = 0

for i in range(N + 1):
    mod_val = cum[i] % M
    target_mod = (cum[i] - total) % M  # s=i, t=j (i>j) の条件

    answer += count_mod[mod_val]      # s < t のケース
    answer += count_mod[target_mod]   # s > t のケース

    count_mod[mod_val] += 1

print(answer)
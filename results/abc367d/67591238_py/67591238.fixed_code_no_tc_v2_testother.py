from collections import defaultdict

N, M = map(int, input().split())
A = list(map(int, input().split()))

# 累積和を計算（時計回りの距離）
cum = [0] * (N + 1)
for i in range(N):
    cum[i + 1] = cum[i] + A[i]

# 全体の合計距離
total = cum[N]

# mod M の値の出現回数をカウント
count_mod = defaultdict(int)
answer = 0

# 累積和の各値について、同じ mod M の値とのペアを数える
for val in cum:
    mod = val % M
    answer += count_mod[mod]
    count_mod[mod] += 1

# 反時計回りの経路がより短い場合を除外する必要があるため、
# s → t の時計回り距離が total/2 より大きい場合は無効
# ただし、問題文では「時計回りにsからtへ行く最小ステップ数がMの倍数」とあるが、
# 実際には「最短経路」ではなく「時計回りに進んだ場合の距離」を指している可能性がある。
# 問題文の解釈：「時計回りにsからtへ行くのに必要なステップ数」がMの倍数であること。

# 上記のコードは「cum[j] - cum[i] ≡ 0 (mod M)」となる(i,j) (i < j)の数を数えている。
# これは「rest area i+1 から rest area j+1 まで時計回りに進む距離が M の倍数」という意味になる。
# つまり s = i+1, t = j+1 として、(s,t) ペアを数えている。

# しかし、このままでは累積和のインデックスと休憩所の対応がずれないように注意。
# cum[i] は rest area 1 から rest area i+1 までの距離。
# よって、cum[j] - cum[i] は rest area i+1 から j+1 への時計回り距離。

# したがって、(i+1, j+1) のようなペア (s,t) を数えている。s ≠ t。
# このロジック自体は正しい。

# ただし、時計回りの距離が全体の半分より大きい場合でも、
# 問題は「時計回りに進んだ場合の距離」がMの倍数かどうかを問うており、
# 「最短距離」ではないので、反時計回りのことは考慮しない。

# よって、上記のコードは論理的には正しい。

# しかし、total >= M の場合、modが一致しても差がMの倍数とは限らない？→いや、差がMの倍数 ⇔ modが等しい は常に成り立つ。

# 正しい。

print(answer)
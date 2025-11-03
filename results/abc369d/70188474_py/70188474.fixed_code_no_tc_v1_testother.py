n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: 最も最近の倒したモンスターが奇数番目（追加経験値なし）
# dp[i][1]: 最も最近の倒したモンスターが偶数番目（追加経験値あり）
# 状態0: 次に倒すと追加なし (全体で奇数個倒した状態)
# 状態1: 次に倒すと追加あり (全体で偶数個倒した状態)

dp = [[0, 0] for _ in range(n + 1)]

for i in range(1, n + 1):
    # モンスターiを倒さない場合
    # 前の状態をそのまま引き継ぐ
    no_fight = max(dp[i-1][0], dp[i-1][1])
    
    # モンスターiを倒す場合
    # 状態0 → 次は偶数番目なので追加経験値あり (2倍)
    fight_with_bonus = dp[i-1][0] + 2 * a[i-1]
    # 状態1 → 次は奇数番目なので通常 (1倍)
    fight_without_bonus = dp[i-1][1] + a[i-1]
    
    # 現在の状態更新
    # dp[i][0]: 今回倒して奇数番目 → 前回偶数番目だった状態から遷移
    dp[i][0] = max(no_fight, fight_without_bonus)
    # dp[i][1]: 今回倒して偶数番目 → 前回奇数番目だった状態から遷移
    dp[i][1] = fight_with_bonus

print(max(dp[n]))
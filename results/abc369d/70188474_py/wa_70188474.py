n = int(input())
s = list(map(int, input().split()))

dp = [[0, 0] for _ in range(n+1)]

for i in range(1, n+1):
    # i番目を通常通り取る
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + s[i-1]
    # i番目を2倍にして取る → その前は2倍していない必要あり
    dp[i][1] = dp[i-1][0] + 2 * s[i-1]

print(max(dp[n]))

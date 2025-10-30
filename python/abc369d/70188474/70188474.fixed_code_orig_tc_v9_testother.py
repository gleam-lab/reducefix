n = int(input())
a = list(map(int, input().split()))

# dp[i][j] = maximum experience after processing first i monsters, 
# where j=0 means the last defeated monster was odd-numbered in defeat order,
# and j=1 means the last defeated monster was even-numbered in defeat order.
dp = [[-10**18] * 2 for _ in range(n+1)]
dp[0][0] = 0

for i in range(1, n+1):
    # Option 1: Skip the current monster
    dp[i][0] = max(dp[i-1][0], dp[i-1][1])
    dp[i][1] = dp[i][0]  # If we skip, the state doesn't change from what it would be if we just took the best
    
    # Option 2: Defeat the current monster
    # If previous state ended with odd-numbered defeat (or no defeats), this will be even-numbered defeat
    if dp[i-1][0] != -10**18:
        # Current defeat becomes even-numbered (so double points)
        dp[i][1] = max(dp[i][1], dp[i-1][0] + 2 * a[i-1])
    
    # If previous state ended with even-numbered defeat, this will be odd-numbered defeat
    if dp[i-1][1] != -10**18:
        # Current defeat becomes odd-numbered (so single points)
        dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i-1])

print(max(dp[n][0], dp[n][1]))
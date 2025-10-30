n = int(input())
a = list(map(int, input().split()))

# dp[i][j] = maximum experience after processing first i monsters, 
# where j=0 means even-numbered defeat count is even, j=1 means odd
# j represents the parity of the number of defeated monsters so far
dp = [[-10**18] * 2 for _ in range(n+1)]
dp[0][0] = 0

for i in range(1, n+1):
    # Option 1: skip monster i-1
    dp[i][0] = max(dp[i][0], dp[i-1][0])
    dp[i][1] = max(dp[i][1], dp[i-1][1])
    
    # Option 2: defeat monster i-1
    # If current count of defeats is even (state 0), defeating makes it odd (state 1)
    # and we get only base points
    if dp[i-1][0] != -10**18:
        dp[i][1] = max(dp[i][1], dp[i-1][0] + a[i-1])
    
    # If current count of defeats is odd (state 1), defeating makes it even (state 0)
    # and we get base + bonus points (double)
    if dp[i-1][1] != -10**18:
        dp[i][0] = max(dp[i][0], dp[i-1][1] + 2 * a[i-1])

print(max(dp[n][0], dp[n][1]))
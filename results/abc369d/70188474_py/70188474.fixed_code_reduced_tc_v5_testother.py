n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum exp up to i-th monster, where the last defeated monster is at an odd position (1st, 3rd, ...)
# dp[i][1]: maximum exp up to i-th monster, where the last defeated monster is at an even position (2nd, 4th, ...)
dp = [[0, 0] for _ in range(n + 1)]

for i in range(1, n + 1):
    # Option 1: skip the i-th monster
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: take the i-th monster as an odd-numbered defeat (no bonus)
    take_as_odd = skip + a[i-1]
    
    # Option 3: take the i-th monster as an even-numbered defeat (bonus: double)
    # This requires that the previous sequence ended with an odd-numbered defeat
    take_as_even = dp[i-1][0] + 2 * a[i-1]
    
    dp[i][0] = max(dp[i][0], take_as_odd)
    dp[i][1] = max(dp[i][1], take_as_even)

print(max(dp[n]))
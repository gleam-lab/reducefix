n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum points up to i-th monster where the i-th monster is not doubled
# dp[i][1]: maximum points up to i-th monster where the i-th monster is doubled
dp = [[0, 0] for _ in range(n + 1)]

for i in range(1, n + 1):
    # Option 1: Take the current monster without doubling (can come from either state)
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + a[i-1]
    
    # Option 2: Take the current monster with doubling (only possible if previous was not doubled)
    # But we can also skip this option entirely
    dp[i][1] = dp[i-1][0] + 2 * a[i-1]
    
    # We might want to not use the double option at all
    # So we need to consider that we can have a state where we don't double even if we could
    # Actually, our formulation already handles this through dp[i][0]

print(max(dp[n][0], dp[n][1]))
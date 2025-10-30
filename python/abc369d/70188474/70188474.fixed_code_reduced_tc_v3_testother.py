n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: max exp up to i-th monster, where the i-th is not doubled (or skipped)
# dp[i][1]: max exp up to i-th monster, where the i-th is taken as a doubled kill
# However, note: only *even-numbered defeats* get doubled. So we need to track the count of defeats.

# Instead of tracking just last state, we need to know whether the next defeat will be odd or even in sequence.
# Let dp[i][0] = maximum exp after first i monsters with an *even* number of defeats so far (so next defeat is 1st, 3rd, ... -> no bonus)
# Let dp[i][1] = maximum exp after first i monsters with an *odd* number of defeats so far (so next defeat is 2nd, 4th, ... -> gets bonus)

dp = [[0, 0] for _ in range(n+1)]

for i in range(1, n+1):
    # Option 1: skip monster i
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: defeat monster i
    # If current number of defeats is even (state 0), then this will be an odd-numbered defeat -> no bonus
    defeat_no_bonus = dp[i-1][0] + a[i-1]
    # If current number of defeats is odd (state 1), then this will be even-numbered defeat -> bonus
    defeat_bonus = dp[i-1][1] + 2 * a[i-1]
    
    # After defeating, the parity flips
    dp[i][0] = max(dp[i][0], defeat_bonus)  # was odd, now becomes even
    dp[i][1] = max(dp[i][1], defeat_no_bonus)  # was even, now becomes odd
    
    # Also update states when skipping (parity doesn't change)
    dp[i][0] = max(dp[i][0], dp[i-1][0])  # skip, and were even -> remain even
    dp[i][1] = max(dp[i][1], dp[i-1][1])  # skip, and were odd -> remain odd

print(max(dp[n][0], dp[n][1]))
n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum experience up to i-th monster, where the i-th is defeated normally (or skipped)
# dp[i][1]: maximum experience up to i-th monster, where the i-th is defeated and counts as a doubled turn

# We need to track whether the current defeat would be an even-numbered defeat overall.
# Instead of tracking parity globally, we use state:
# dp[i][0] = max total exp after considering first i monsters, with an *even* number of defeats so far
# dp[i][1] = max total exp after considering first i monsters, with an *odd* number of defeats so far

# Then, when defeating the i-th monster:
# - If previous count was even (dp[i-1][0]), then this will be the (odd)th defeat -> no bonus
# - If previous count was odd (dp[i-1][1]), then this will be the (even)th defeat -> bonus (so gain 2*A[i])

# But note: skipping doesn't change the count.

dp = [[0, 0] for _ in range(n+1)]

for i in range(1, n+1):
    # Option 1: skip the i-th monster
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: defeat the i-th monster
    # If previous number of defeats was even (state 0), now becomes odd -> no bonus
    defeat_no_bonus = dp[i-1][0] + a[i-1]
    # If previous number of defeats was odd (state 1), now becomes even -> bonus
    defeat_with_bonus = dp[i-1][1] + 2 * a[i-1]
    
    # Now update states:
    # After defeating, if we came from even (0), now odd -> state 1
    # But we want dp[i][0] = best with even defeats after i monsters
    # So:
    #   To get even defeats at i: either skip and had even before, or defeat and had odd before (then becomes even)
    #   To get odd defeats at i: either skip and had odd before, or defeat and had even before (then becomes odd)
    
    dp[i][0] = max(
        dp[i-1][0],  # skip and keep even
        dp[i-1][1] + 2 * a[i-1]  # defeat with bonus, turning odd -> even
    )
    
    dp[i][1] = max(
        dp[i-1][1],  # skip and keep odd
        dp[i-1][0] + a[i-1]  # defeat without bonus, turning even -> odd
    )

print(max(dp[n]))
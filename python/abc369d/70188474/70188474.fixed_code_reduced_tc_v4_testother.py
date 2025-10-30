n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: max exp up to i-th monster, where the i-th is NOT taken as doubled
# dp[i][1]: max exp up to i-th monster, where the i-th IS taken as doubled (i.e., it's an even-numbered defeat)
# Note: We cannot force doubling arbitrarily — only every second defeated monster gets doubled.

# But note: the "even-numbered defeated" means the 2nd, 4th, 6th, ... defeat in order of defeats.
# So we need to track not just whether current is doubled, but how many defeats so far (mod 2).

# Let’s redefine:
# Instead, we use state:
# dp[i][0] = maximum experience after first i monsters, with even number of defeats (so next defeat would be odd, no bonus)
# dp[i][1] = maximum experience after first i monsters, with odd number of defeats (so next defeat would be even, bonus)

dp = [[0, 0] for _ in range(n+1)]

for i in range(1, n+1):
    # Option 1: skip monster i
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: defeat monster i
    # If current number of defeats is even (state 0), then this will be the (odd) 1st, 3rd, 5th... → no bonus
    take_no_bonus = dp[i-1][0] + a[i-1]
    # If current number of defeats is odd (state 1), then this will be even-numbered defeat → bonus
    take_with_bonus = dp[i-1][1] + 2 * a[i-1]
    
    # After taking, the parity flips
    dp[i][0] = max(dp[i][0], take_with_bonus)  # now even count (because was odd +1)
    dp[i][1] = max(dp[i][1], take_no_bonus)   # now odd count (because was even +1)
    
    # Also update both states from skipping
    dp[i][0] = max(dp[i][0], dp[i-1][0])  # skip: preserve even
    dp[i][1] = max(dp[i][1], dp[i-1][1])  # skip: preserve odd

print(max(dp[n]))
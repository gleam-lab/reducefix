n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum points up to i-th monster where the i-th is not doubled (or skipped)
# dp[i][1]: maximum points up to i-th monster where the i-th is doubled
# We need to track whether the last taken monster was doubled or not

# However, a simpler approach: we can choose which monsters to take and which ones to double.
# The doubling bonus applies only to even-numbered defeated monsters (2nd, 4th, 6th, ... in order of defeat)

# Alternate approach: use DP where state tracks the count of defeated monsters mod 2
# But note: we can skip monsters arbitrarily.

# Let dp[i][j] = maximum experience after processing first i monsters, 
# where j = number of defeated monsters so far mod 2 (0: even count, 1: odd count)
# When we defeat a monster at position i:
# - If current count is odd (j=1), then this will be even-numbered defeat -> get 2*A[i]
# - If current count is even (j=0), then this will be odd-numbered defeat -> get A[i]
# Then update the parity.

dp = [[-10**18] * 2 for _ in range(n+1)]
dp[0][0] = 0

for i in range(n):
    # Option 1: skip monster i
    for j in range(2):
        if dp[i][j] != -10**18:
            dp[i+1][j] = max(dp[i+1][j], dp[i][j])
    
    # Option 2: defeat monster i
    for j in range(2):
        if dp[i][j] != -10**18:
            if j == 0:  # currently even count, so next defeat is odd-numbered (1st, 3rd, ...)
                new_val = dp[i][j] + a[i]
            else:  # j == 1, currently odd count, so next defeat is even-numbered (2nd, 4th, ...)
                new_val = dp[i][j] + 2 * a[i]
            dp[i+1][1-j] = max(dp[i+1][1-j], new_val)

print(max(dp[n][0], dp[n][1]))
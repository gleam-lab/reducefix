n = int(input())
A = list(map(int, input().split()))

# dp[i][0]: max experience up to i-th monster, where the i-th is NOT taken as a doubled one
# dp[i][1]: max experience up to i-th monster, where the i-th IS taken as a doubled one
# Note: A doubled kill can only happen on an even-numbered defeat (2nd, 4th, ...), not based on index.
# But we don't know the global count of defeats — so we need state for whether current count is odd/even.

# Instead: let’s define:
# dp[i][0]: maximum total exp after considering first i monsters, with even number of defeats (so next defeat would be odd -> no bonus)
# dp[i][1]: maximum total exp after considering first i monsters, with odd number of defeats (so next defeat would be even -> bonus)

# Initially: 0 defeats -> even (0 is even), so dp[0][0] = 0, dp[0][1] = -inf (impossible)

dp0 = 0  # even number of defeats so far
dp1 = -10**18  # odd number of defeats so far (impossible at start)

for i in range(n):
    a = A[i]
    new_dp0 = dp0  # skip monster
    new_dp1 = dp1  # skip monster
    
    # Option 1: defeat monster — if currently even defeats (dp0), then this becomes odd-numbered defeat -> no bonus
    new_dp1 = max(new_dp1, dp0 + a)
    
    # Option 2: defeat monster — if currently odd defeats (dp1), then this becomes even-numbered defeat -> bonus
    new_dp0 = max(new_dp0, dp1 + a * 2)
    
    dp0, dp1 = new_dp0, new_dp1

print(max(dp0, dp1))
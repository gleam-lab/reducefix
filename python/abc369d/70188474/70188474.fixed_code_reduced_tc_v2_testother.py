n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: max exp up to i-th monster, where i-th is NOT taken as double
# dp[i][1]: max exp up to i-th monster, where i-th IS taken as double (so it's an even-numbered defeat)
# Note: a monster can only be doubled if it is the 2nd, 4th, etc. defeated monster overall.

# But note: we cannot double every other chosen monster arbitrarily — the doubling applies only when the count of defeats so far is even.
# Actually, the "even-numbered defeated monster" means: if this is the 2nd, 4th, 6th, ... defeat in order, then gain +X.

# Therefore, we need to track the parity of the number of defeats so far.

# Let:
# dp[i][0] = maximum experience after first i monsters with even number of defeats (including 0)
# dp[i][1] = maximum experience after first i monsters with odd number of defeats

# At step i, for monster i (0-indexed), strength = a[i]
# Option 1: skip monster i
#   Then state carries over: dp[i+1][parity] = max(dp[i+1][parity], dp[i][parity])

# Option 2: defeat monster i
#   If current number of defeats is even (state 0), then after defeating, it becomes odd (state 1), and we get a[i] points.
#   If current number of defeats is odd (state 1), then after defeating, it becomes even (state 0), and we get a[i] * 2 points (because this is an even-numbered defeat).

# So:
# From state dp[i][0]: defeat monster → dp[i+1][1] = max(dp[i+1][1], dp[i][0] + a[i])
# From state dp[i][1]: defeat monster → dp[i+1][0] = max(dp[i+1][0], dp[i][1] + 2 * a[i])

dp = [[-1] * 2 for _ in range(n+1)]
dp[0][0] = 0  # start with 0 defeats (even), 0 exp
dp[0][1] = -1  # impossible to have odd defeats at start

for i in range(n):
    for j in range(2):
        if dp[i][j] == -1:
            continue
        # Option 1: skip monster i
        if dp[i+1][j] < dp[i][j]:
            dp[i+1][j] = dp[i][j]
        # Option 2: defeat monster i
        if j == 0:  # currently even number of defeats -> after defeat: odd, gain a[i]
            next_val = dp[i][j] + a[i]
            if next_val > dp[i+1][1]:
                dp[i+1][1] = next_val
        else:  # j == 1: currently odd -> after defeat: even, gain 2*a[i]
            next_val = dp[i][j] + 2 * a[i]
            if next_val > dp[i+1][0]:
                dp[i+1][0] = next_val

print(max(dp[n][0], dp[n][1]))
n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum exp up to i-th monster, where the i-th is defeated normally (not as even count)
# dp[i][1]: maximum exp up to i-th monster, where the i-th is defeated and contributes double (i.e., it's an even-numbered defeat in sequence)
# However, note: "even-numbered defeated monster" means the 2nd, 4th, ... defeat overall, not by index.
# So we need to track whether the *number of defeats so far* is odd or even.

# Let’s redefine:
# We can’t just use two states per index because the doubling depends on the count of defeats, not the position.
# Instead, we can do:
# dp[i][j] where j = number of defeats % 2 after processing first i monsters.
# But we also need to know if current defeat would be even-numbered.

# Actually, we can use:
# dp[i][0] = max total exp after first i monsters with even number of defeats
# dp[i][1] = max total exp after first i monsters with odd number of defeats

# When we skip monster i: 
#   state doesn't change: dp[i][0] = max(dp[i][0], dp[i-1][0]), dp[i][1] = max(dp[i][1], dp[i-1][1])
# When we defeat monster i:
#   new_count_parity = (prev_parity + 1) % 2
#   if prev was even (0 defeats mod 2 → next will be 1st, 3rd, ... → odd count → no bonus)
#   if prev was odd (1 defeats mod 2 → next will be 2nd, 4th, ... → even-numbered defeat → bonus)
#
# So:
#   defeating after even count (0): gain a[i], go to state 1
#   defeating after odd count (1): gain 2*a[i], go to state 0

dp = [[-1 << 60] * 2 for _ in range(n+1)]
dp[0][0] = 0  # 0 monsters, 0 defeats (even)

for i in range(1, n+1):
    # Option 1: skip monster i-1 (0-indexed)
    for j in range(2):
        if dp[i-1][j] != -1 << 60:
            dp[i][j] = max(dp[i][j], dp[i-1][j])
    
    # Option 2: defeat monster i-1
    for j in range(2):
        if dp[i-1][j] != -1 << 60:
            if j == 0:  # previously even number of defeats → this will be odd-numbered defeat (1st, 3rd, ...)
                new_parity = 1
                exp_gain = a[i-1]
            else:  # j == 1, previously odd → this will be even-numbered defeat (2nd, 4th, ...) → bonus
                new_parity = 0
                exp_gain = 2 * a[i-1]
            dp[i][new_parity] = max(dp[i][new_parity], dp[i-1][j] + exp_gain)

print(max(dp[n]))
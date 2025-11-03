n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum points up to i-th monster where the i-th is not doubled (or skipped)
# dp[i][1]: maximum points up to i-th monster where the i-th is doubled
dp0 = 0  # previous state: not doubled
dp1 = float('-inf')  # previous state: doubled (initially impossible)

for i in range(n):
    # Current values
    new_dp0 = max(dp0, dp1)  # skip or take without doubling
    new_dp1 = dp0 + 2 * a[i]  # take with doubling (must follow non-doubled)
    
    # Update for next iteration
    dp0 = max(dp0 + a[i], new_dp0)  # either add current normally or skip
    dp1 = new_dp1

print(max(dp0, dp1))
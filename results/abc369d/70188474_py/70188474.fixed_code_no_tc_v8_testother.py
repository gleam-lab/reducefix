n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum exp up to i-th monster, where the last defeated monster was at an odd position (1st, 3rd, ...)
# dp[i][1]: maximum exp up to i-th monster, where the last defeated monster was at an even position (2nd, 4th, ...)
dp = [[0, 0] for _ in range(n + 1)]

for i in range(1, n + 1):
    # Option 1: Skip the i-th monster
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: Defeat the i-th monster
    # If we have an odd number of defeats so far (next will be even), or if no defeat yet (first defeat)
    # We consider both cases: current defeat could be odd or even in sequence
    
    # If previous count was even (so current becomes odd), we add A[i-1]
    # If previous count was odd (so current becomes even), we add 2*A[i-1]
    
    # We can always start a new sequence (odd position) from any state
    take_as_odd = max(dp[i-1][0], dp[i-1][1]) + a[i-1]
    
    # We can only take as even if the previous defeat was at an odd position
    take_as_even = dp[i-1][0] + 2 * a[i-1] if dp[i-1][0] != -10**18 else -10**18
    
    # But we need to handle states properly. Let's redefine:
    # dp[i][0]: last defeated monster is at an odd position in the defeat sequence
    # dp[i][1]: last defeated monster is at an even position in the defeat sequence
    
    # Initialize with skipping
    dp[i][0] = skip
    dp[i][1] = skip
    
    # Update by taking current monster
    # If we take it and it becomes an odd-numbered defeat (i.e., after even or start)
    dp[i][0] = max(dp[i][0], dp[i-1][1] + a[i-1], dp[i-1][0] + a[i-1])
    
    # If we take it and it becomes an even-numbered defeat (i.e., after an odd)
    dp[i][1] = max(dp[i][1], dp[i-1][0] + 2 * a[i-1])

print(max(dp[n]))
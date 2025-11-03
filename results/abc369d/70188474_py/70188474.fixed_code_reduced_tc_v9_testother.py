n = int(input())
a = list(map(int, input().split()))

# dp[i][0]: maximum exp up to i-th monster, where the last defeated monster was at an odd position (1st, 3rd, ...)
# dp[i][1]: maximum exp up to i-th monster, where the last defeated monster was at an even position (2nd, 4th, ...)
dp = [[0, 0] for _ in range(n + 1)]

for i in range(1, n + 1):
    # Option 1: skip the i-th monster
    skip = max(dp[i-1][0], dp[i-1][1])
    
    # Option 2: defeat the i-th monster
    # If we defeat it, the experience depends on whether this will be an odd or even defeat in sequence
    # To make this defeat the 1st, 3rd, 5th, ... (odd-numbered defeat), previous defeat must have been even-numbered or none
    # So we can come from either state, but this defeat gives base points only
    take_as_odd = skip + a[i-1]
    
    # To make this defeat the 2nd, 4th, ... (even-numbered defeat), previous defeat must have been odd-numbered
    # And we get double points: base + bonus
    take_as_even = dp[i-1][0] + 2 * a[i-1] if dp[i-1][0] != 0 or i == 1 else 0
    
    # But note: we can start with an even-numbered defeat? No — first defeat is always odd.
    # Actually, we need to handle the case when no monster was defeated before.
    # We can only take as even if there was an odd-numbered defeat before.
    
    # Correction: We should allow taking as even only if there was a previous defeat that ended at odd count.
    # However, if no monster has been defeated yet, we cannot have an even-numbered defeat.
    
    # Therefore:
    dp[i][0] = take_as_odd
    dp[i][1] = dp[i-1][0] + 2 * a[i-1]  # only if we had an odd-numbered last defeat

    # But wait: we might not want to force using dp[i-1][0]. What if skipping some monsters?
    # Actually, our state dp[i][0] means that among the first i monsters, the last defeated one was at an odd position.
    # Similarly, dp[i][1] means last defeated was at even position.

    # However, we can also skip monsters arbitrarily. The key is:
    # - To have an even-numbered defeat at position i, there must be exactly one more defeat before this (and total defeats so far is even)
    #   meaning the previous state must end with an odd number of defeats (i.e., dp[i-1][0] > -inf)

    # But what if we have gaps? Our state doesn't track count, just parity of defeat sequence.

    # Revised understanding:
    # dp[i][0]: best total exp from first i monsters, and total number of defeats is **odd**
    # dp[i][1]: best total exp from first i monsters, and total number of defeats is **even**

    # Then:
    # - From dp[i-1][0] (odd defeats), if we defeat monster i → becomes even → add 2*A[i-1]
    # - From dp[i-1][1] (even defeats), if we defeat monster i → becomes odd → add A[i-1]
    # - From either, if we skip → same state carries over

# Let's reset with correct state definition:

# Recompute with corrected logic
dp0 = 0  # max exp with even number of defeats so far (initially 0 defeats)
dp1 = 0  # max exp with odd number of defeats so far

for i in range(n):
    # Option: skip monster i
    # states remain
    new_dp0 = dp0
    new_dp1 = dp1
    
    # Option: defeat monster i
    # Case 1: coming from even count (dp0) → now odd count, gain A[i]
    candidate1 = dp0 + a[i]
    if candidate1 > new_dp1:
        new_dp1 = candidate1
    
    # Case 2: coming from odd count (dp1) → now even count, gain 2*A[i]
    candidate2 = dp1 + 2 * a[i]
    if candidate2 > new_dp0:
        new_dp0 = candidate2
    
    dp0, dp1 = new_dp0, new_dp1

print(max(dp0, dp1))
def min_cost_for_capacity(target):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines (from 0 up to what's needed)
        # We only need at most 'target' capacity from each machine type
        max_s_units = (target + a - 1) // a if a > 0 else 0
        max_t_units = (target + b - 1) // b if b > 0 else 0
        
        # We can cap the units to avoid overflow
        for s_units in range(max_s_units + 1):
            s_capacity = s_units * a
            if s_capacity >= target:
                min_cost = min(min_cost, s_units * p)
            else:
                remaining = target - s_capacity
                t_units = (remaining + b - 1) // b  # ceil division
                min_cost = min(min_cost, s_units * p + t_units * q)
        
        # Also try using only T machines
        t_units_only = (target + b - 1) // b
        min_cost = min(min_cost, t_units_only * q)
        
        total_cost += min_cost
        if total_cost > x:  # Early termination
            return float('inf')
    
    return total_cost

# Read input
n, x = map(int, input().split())
machines = []
for _ in range(n):
    a, p, b, q = map(int, input().split())
    machines.append((a, p, b, q))

# Binary search on the production capacity
lo = 0
hi = 2 * 10**7  # Maximum possible capacity: budget // 1 * max(A_i,B_i) <= 10^7 * 100, but we can be smarter

# But realistically, max capacity per process is limited by A_i, B_i <= 100 and X <= 10^7
# So maximum capacity is at most around 10^7 * 100 / 1 = 10^9, but we can use tighter bound
# Actually, since we need to satisfy all processes, and each machine gives at most 100 per day,
# and we can spend all money on one process: max capacity <= X * 100 // 1 = 10^9 -> too big

# Better: hi = X * max(max(A_i,B_i)) // min(P_i,Q_i) + 1 -> worst case min cost is 1
# But we can simply set hi = 2 * 10**9 which is safe

hi = 2 * 10**9

while lo < hi:
    mid = (lo + hi + 1) // 2
    if min_cost_for_capacity(mid) <= x:
        lo = mid
    else:
        hi = mid - 1

print(lo)
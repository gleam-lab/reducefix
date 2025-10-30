def min_cost_for_capacity(target):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines (from 0 up to what's needed)
        # We need at least `target` processing power from this machine combination
        max_s_units = (target + a - 1) // a if a > 0 else 0
        max_t_units = (target + b - 1) // b if b > 0 else 0
        
        # We only need to check reasonable bounds
        for s_units in range(max_s_units + 1):
            s_throughput = s_units * a
            remaining = max(0, target - s_throughput)
            t_units = (remaining + b - 1) // b if b > 0 else 0
            
            cost = s_units * p + t_units * q
            min_cost = min(min_cost, cost)
            
            # Early termination if already too expensive
            if min_cost > x:
                break
                
        total_cost += min_cost
        if total_cost > x:
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
hi = 2 * 10**7  # Maximum possible capacity: limited by budget and min machine speed

while lo < hi:
    mid = (lo + hi + 1) // 2
    if min_cost_for_capacity(mid) <= x:
        lo = mid
    else:
        hi = mid - 1

print(lo)
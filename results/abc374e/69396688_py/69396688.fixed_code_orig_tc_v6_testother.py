def min_cost_for_capacity(cap):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try different numbers of S_i machines
        max_s = cap // a if a > 0 else 0
        for s in range(max_s + 1):
            remaining = cap - s * a
            if remaining <= 0:
                min_cost = min(min_cost, s * p)
            else:
                # Need T_i machines for the rest
                t = (remaining + b - 1) // b  # Ceiling division
                min_cost = min(min_cost, s * p + t * q)
        
        # Also try using only T_i machines
        t_only = (cap + b - 1) // b
        min_cost = min(min_cost, t_only * q)
        
        total_cost += min_cost
        if total_cost > x:
            return float('inf')
    
    return total_cost

n, x = map(int, input().split())
machines = []
for _ in range(n):
    a, p, b, q = map(int, input().split())
    machines.append((a, p, b, q))

# Binary search on the production capacity
lo, hi = 0, 2 * 10**7  # Upper bound: even with cheapest machines

while lo < hi:
    mid = (lo + hi + 1) // 2
    if min_cost_for_capacity(mid) <= x:
        lo = mid
    else:
        hi = mid - 1

print(lo)
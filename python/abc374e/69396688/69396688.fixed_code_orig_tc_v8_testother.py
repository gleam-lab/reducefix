def min_cost_for_capacity(target):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try different numbers of S_i machines
        # We need at least ceil(target / a) units from S_i if using only S_i
        max_s_needed = (target + a - 1) // a if a > 0 else float('inf')
        for s_count in range(max_s_needed + 1):
            processed_by_s = s_count * a
            if processed_by_s >= target:
                min_cost = min(min_cost, s_count * p)
            else:
                # Need additional processing from T_i
                remaining = target - processed_by_s
                t_count = (remaining + b - 1) // b if b > 0 else float('inf')
                min_cost = min(min_cost, s_count * p + t_count * q)
        
        # Also try using only T_i machines
        t_only_count = (target + b - 1) // b
        min_cost = min(min_cost, t_only_count * q)
        
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
left, right = 0, 2 * 10**7  # Upper bound: even with minimal efficiency and max budget

while left < right:
    mid = (left + right + 1) // 2
    if min_cost_for_capacity(mid) <= x:
        left = mid
    else:
        right = mid - 1

print(left)
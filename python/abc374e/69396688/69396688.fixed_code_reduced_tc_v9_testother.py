def can_achieve(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Calculate how many units of processing we need at process i
        # We need at least 'capacity' throughput from this process
        
        # If using only S_i machines
        if a > 0:
            num_s = (capacity + a - 1) // a  # Ceiling division
            cost_s = num_s * p
            min_cost = min(min_cost, cost_s)
        
        # If using only T_i machines
        if b > 0:
            num_t = (capacity + b - 1) // b  # Ceiling division
            cost_t = num_t * q
            min_cost = min(min_cost, cost_t)
        
        # Try combinations of both machines
        # Use up to capacity//min(a,b) + 1 of one type and fill the rest with the other
        max_s_needed = (capacity + a - 1) // a
        for s_count in range(max_s_needed + 1):
            processed_by_s = s_count * a
            remaining = max(0, capacity - processed_by_s)
            if remaining == 0:
                min_cost = min(min_cost, s_count * p)
            else:
                t_count = (remaining + b - 1) // b
                min_cost = min(min_cost, s_count * p + t_count * q)
                
        total_cost += min_cost
        if total_cost > x:
            return False
            
    return total_cost <= x

n, x = map(int, input().split())
machines = []
for _ in range(n):
    a, p, b, q = map(int, input().split())
    machines.append((a, p, b, q))

# Binary search on the production capacity
left, right = 0, 2 * 10**7  # Upper bound: even with cheapest machine, X yen can buy at most ~X units

while left < right:
    mid = (left + right + 1) // 2
    if can_achieve(mid):
        left = mid
    else:
        right = mid - 1

print(left)
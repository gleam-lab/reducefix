def can_achieve(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Option 1: use only S_i machines
        if a > 0:
            num_s = (capacity + a - 1) // a  # ceil(capacity / a)
            cost_s = num_s * p
            min_cost = min(min_cost, cost_s)
        
        # Option 2: use only T_i machines
        if b > 0:
            num_t = (capacity + b - 1) // b  # ceil(capacity / b)
            cost_t = num_t * q
            min_cost = min(min_cost, cost_t)
        
        # Option 3: mix of both machines
        # We try different numbers of T_i machines and compute required S_i
        if b > 0:
            # Maximum T machines we might need
            max_t = (capacity + b - 1) // b
            for t_count in range(max_t + 1):
                processed_by_t = t_count * b
                remaining = max(0, capacity - processed_by_t)
                if a > 0:
                    s_count = (remaining + a - 1) // a if remaining > 0 else 0
                else:
                    if remaining > 0:
                        continue  # impossible
                    s_count = 0
                cost = t_count * q + s_count * p
                min_cost = min(min_cost, cost)
        
        # Also try mixing by fixing number of S machines
        if a > 0:
            max_s = (capacity + a - 1) // a
            for s_count in range(max_s + 1):
                processed_by_s = s_count * a
                remaining = max(0, capacity - processed_by_s)
                if b > 0:
                    t_count = (remaining + b - 1) // b if remaining > 0 else 0
                else:
                    if remaining > 0:
                        continue  # impossible
                    t_count = 0
                cost = s_count * p + t_count * q
                min_cost = min(min_cost, cost)
                
        if min_cost == float('inf'):
            return False
        
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
left, right = 0, 2 * 10**7  # upper bound: even with cheapest machine, X yen can buy at most ~X units

while left < right:
    mid = (left + right + 1) // 2
    if can_achieve(mid):
        left = mid
    else:
        right = mid - 1

print(left)
def can_achieve_capacity(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines
        # We need at least `num_s` such that num_s * a >= capacity => num_s >= ceil(capacity / a)
        max_s_needed = (capacity + a - 1) // a if a > 0 else float('inf')
        for num_s in range(max_s_needed + 1):
            products_from_s = num_s * a
            remaining = max(0, capacity - products_from_s)
            num_t = (remaining + b - 1) // b if b > 0 else 0 if remaining == 0 else float('inf')
            
            if num_t == float('inf'):
                continue
                
            cost = num_s * p + num_t * q
            min_cost = min(min_cost, cost)
        
        # Also try using only T machines
        num_t_only = (capacity + b - 1) // b
        min_cost = min(min_cost, num_t_only * q)
        
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
left, right = 0, 2 * 10**7  # Max capacity: max(A_i, B_i) * (X // min(P_i, Q_i)) but safe upper bound

while left < right:
    mid = (left + right + 1) // 2
    if can_achieve_capacity(mid):
        left = mid
    else:
        right = mid - 1

print(left)
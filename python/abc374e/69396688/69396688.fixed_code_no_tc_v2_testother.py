def can_achieve_capacity(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines
        # We need at least `num_s` such that num_s * a >= capacity
        # So num_s >= ceil(capacity / a) if a > 0
        max_s_needed = (capacity + a - 1) // a if a > 0 else 0
        if a == 0:
            max_s_needed = 0
        
        # Try using only T_i machines
        if b > 0:
            t_needed = (capacity + b - 1) // b
            min_cost = min(min_cost, t_needed * q)
        
        # Try combinations: use s units of S_i and rest with T_i
        # If we use s units of S_i, they handle s * a products
        # Remaining = max(0, capacity - s * a)
        # Need t = ceil(remaining / b) units of T_i if b > 0
        for s in range(max_s_needed + 1):
            processed_by_s = s * a
            remaining = max(0, capacity - processed_by_s)
            
            if remaining == 0:
                cost = s * p
                min_cost = min(min_cost, cost)
            elif b > 0:
                t = (remaining + b - 1) // b
                cost = s * p + t * q
                min_cost = min(min_cost, cost)
        
        # If capacity is 0, we don't need any machines
        if capacity == 0:
            min_cost = 0
            
        if min_cost == float('inf'):
            return False
            
        total_cost += min_cost
        if total_cost > x:
            return False
    
    return total_cost <= x

# Read input
n, x = map(int, input().split())
machines = []
for _ in range(n):
    a, p, b, q = map(int, input().split())
    machines.append((a, p, b, q))

# Binary search on the production capacity
left, right = 0, 10**9
answer = 0

while left <= right:
    mid = (left + right) // 2
    if can_achieve_capacity(mid):
        answer = mid
        left = mid + 1
    else:
        right = mid - 1

print(answer)
def can_achieve(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Maximum number of S_i machines we might need
        max_s = (capacity + a - 1) // a if a > 0 else 0
        # Try different numbers of S_i machines
        for num_s in range(max_s + 1):
            products_from_s = num_s * a
            remaining = max(0, capacity - products_from_s)
            num_t = (remaining + b - 1) // b if b > 0 else 0
            
            cost = num_s * p + num_t * q
            min_cost = min(min_cost, cost)
            
            # Optimization: if using more S machines becomes too expensive, break early
            if num_s * p >= min_cost:
                break
                
        total_cost += min_cost
        if total_cost > x:
            return False
    return total_cost <= x

n, x = map(int, input().split())
machines = []
for _ in range(n):
    machines.append(list(map(int, input().split())))

# Binary search on the production capacity
left, right = 0, 2 * 10**7  # Upper bound: even with cheapest machines, budget limits capacity

while left < right:
    mid = (left + right + 1) // 2
    if can_achieve(mid):
        left = mid
    else:
        right = mid - 1

print(left)
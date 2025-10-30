def min_cost_for_capacity(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines (from 0 up to what's needed)
        max_s_needed = (capacity + a - 1) // a if a > 0 else 0
        for num_s in range(max_s_needed + 1):
            processed_by_s = num_s * a
            remaining = max(0, capacity - processed_by_s)
            num_t = (remaining + b - 1) // b if b > 0 else 0
            
            cost = num_s * p + num_t * q
            min_cost = min(min_cost, cost)
            
            # Early break if adding more S machines won't help
            if processed_by_s >= capacity:
                break
                
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
left, right = 0, 2 * 10**7
result = 0

while left <= right:
    mid = (left + right) // 2
    if min_cost_for_capacity(mid) <= x:
        result = mid
        left = mid + 1
    else:
        right = mid - 1

print(result)
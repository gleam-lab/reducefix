def min_cost_for_capacity(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines
        max_s = capacity // a if a > 0 else 0
        if capacity == 0:
            min_cost = 0
        else:
            for s_count in range(max_s + 1):
                remaining = capacity - s_count * a
                t_count = (remaining + b - 1) // b if b > 0 and remaining > 0 else 0
                if remaining <= 0:
                    t_count = 0
                cost = s_count * p + t_count * q
                min_cost = min(min_cost, cost)
                
                # Early termination if cost already exceeds budget
                if cost >= min_cost:
                    break
                    
        total_cost += min_cost
        if total_cost > x:
            return total_cost
            
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
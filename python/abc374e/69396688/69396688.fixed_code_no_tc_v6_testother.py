def min_cost_for_throughput(target):
    total_cost = 0
    for i in range(n):
        a, p, b, q = v[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines (from 0 up to what's needed)
        # Maximum number of S_i machines needed: ceil(target / a)
        max_s = (target + a - 1) // a if a > 0 else 0
        for num_s in range(max_s + 1):
            processed_by_s = num_s * a
            remaining = max(0, target - processed_by_s)
            
            # Number of T_i machines needed
            num_t = (remaining + b - 1) // b if b > 0 else 0
            
            cost = num_s * p + num_t * q
            min_cost = min(min_cost, cost)
            
        total_cost += min_cost
        if total_cost > x:
            break
            
    return total_cost

n, x = map(int, input().split())
v = [list(map(int, input().split())) for _ in range(n)]

# Binary search on the production capacity (minimum throughput across all processes)
lo = 0
hi = 2 * 10**7  # Maximum possible capacity: budget X divided by minimum machine cost per unit work

while lo < hi:
    mid = (lo + hi + 1) // 2
    if min_cost_for_throughput(mid) <= x:
        lo = mid
    else:
        hi = mid - 1

print(lo)
def min_cost_for_capacity(cap):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of S_i machines (from 0 up to cap)
        # We only need to consider up to cap // a + 1
        max_s = (cap + a - 1) // a if a > 0 else 0
        for num_s in range(max_s + 1):
            processed_by_s = num_s * a
            if processed_by_s >= cap:
                min_cost = min(min_cost, num_s * p)
            else:
                remaining = cap - processed_by_s
                num_t = (remaining + b - 1) // b if b > 0 else 0
                min_cost = min(min_cost, num_s * p + num_t * q)
                
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
lo, hi = 0, 2 * 10**7  # upper bound: even with cheapest machine, we can't exceed this

while lo < hi:
    mid = (lo + hi + 1) // 2
    if min_cost_for_capacity(mid) <= x:
        lo = mid
    else:
        hi = mid - 1

print(lo)
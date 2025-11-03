def can_achieve(capacity):
    total_cost = 0
    for i in range(n):
        a, p, b, q = machines[i]
        min_cost = float('inf')
        
        # Try all possible numbers of machine S_i (from 0 up to what's needed)
        # We only need enough machines to achieve at least `capacity`
        max_s_needed = (capacity + a - 1) // a if a > 0 else float('inf')
        max_t_needed = (capacity + b - 1) // b if b > 0 else float('inf')
        
        # To avoid infinite loops, cap the number reasonably
        # Since capacity <= 10^7 and a,b >= 1, this is safe
        for s_count in range(max_s_needed + 1):
            s_output = s_count * a
            if s_output >= capacity:
                min_cost = min(min_cost, s_count * p)
            else:
                t_needed = (capacity - s_output + b - 1) // b
                if t_needed >= 0:
                    min_cost = min(min_cost, s_count * p + t_needed * q)
        
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

# Binary search on production capacity
lo, hi = 0, 10**9  # Hi: upper bound based on max budget and min cost per unit

while lo < hi:
    mid = (lo + hi + 1) // 2
    if can_achieve(mid):
        lo = mid
    else:
        hi = mid - 1

print(lo)
def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    x = int(data[1])
    machines = []
    index = 2
    for _ in range(n):
        a = int(data[index])
        p = int(data[index+1])
        b = int(data[index+2])
        q = int(data[index+3])
        index += 4
        machines.append((a, p, b, q))
    
    # Binary search on the production capacity
    left, right = 0, 10**9
    
    def can_achieve(capacity):
        total_cost = 0
        for a, p, b, q in machines:
            min_cost = float('inf')
            # Try different numbers of S_i machines
            # We need at least some combination such that daily output >= capacity
            # Let u be number of S_i machines, v be number of T_i machines
            # Then: u*a + v*b >= capacity
            # Cost: u*p + v*q
            # We can fix u and compute minimum v needed
            
            # If we use only T_i machines
            if b > 0:
                v_only = (capacity + b - 1) // b
                min_cost = min(min_cost, v_only * q)
            
            # If we use only S_i machines
            if a > 0:
                u_only = (capacity + a - 1) // a
                min_cost = min(min_cost, u_only * p)
            
            # Try combinations: iterate over possible counts of S_i machines
            # We only need to try up to capacity//a + 1
            if a > 0:
                max_u = (capacity + a - 1) // a
                for u in range(max_u + 1):
                    products_from_s = u * a
                    remaining = max(0, capacity - products_from_s)
                    if remaining == 0:
                        cost = u * p
                        min_cost = min(min_cost, cost)
                    else:
                        if b == 0:
                            continue
                        v = (remaining + b - 1) // b
                        cost = u * p + v * q
                        min_cost = min(min_cost, cost)
            
            if min_cost == float('inf'):
                return False
                
            total_cost += min_cost
            if total_cost > x:
                return False
        
        return total_cost <= x
    
    result = 0
    while left <= right:
        mid = (left + right) // 2
        if can_achieve(mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    
    print(result)

solve()
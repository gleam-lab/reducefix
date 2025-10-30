def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    x = int(data[1])
    
    processes = []
    index = 2
    for _ in range(n):
        a = int(data[index])
        p = int(data[index+1])
        b = int(data[index+2])
        q = int(data[index+3])
        index += 4
        processes.append((a, p, b, q))
    
    # Binary search on the production capacity
    left, right = 0, 10**7 + 1
    
    def can_achieve(capacity):
        total_cost = 0
        for a, p, b, q in processes:
            min_cost = float('inf')
            
            # Try different numbers of machine S_i
            # We need at least ceil(capacity / a) units of S_i if we use only S_i
            # But we can also mix with T_i
            # Let's try all possible counts of S_i from 0 to ceil(capacity / a)
            s_needed = (capacity + a - 1) // a if a > 0 else float('inf')
            
            for num_s in range(s_needed + 1):
                products_from_s = num_s * a
                remaining = max(0, capacity - products_from_s)
                
                # Number of T_i machines needed
                num_t = (remaining + b - 1) // b if b > 0 else (float('inf') if remaining > 0 else 0)
                
                cost = num_s * p + num_t * q
                min_cost = min(min_cost, cost)
                
                # Early termination if cost already exceeds budget
                if min_cost > x:
                    break
            
            total_cost += min_cost
            if total_cost > x:
                return False
        
        return total_cost <= x
    
    while left < right:
        mid = (left + right + 1) // 2
        if can_achieve(mid):
            left = mid
        else:
            right = mid - 1
    
    print(left)

solve()
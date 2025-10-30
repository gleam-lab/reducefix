q = int(input())
bag = {}
distinct_count = 0

for _ in range(q):
    query = list(map(int, input().split()))
    
    if query[0] == 1:
        x = query[1]
        if x not in bag:
            bag[x] = 0
            distinct_count += 1
        bag[x] += 1
        
    elif query[0] == 2:
        x = query[1]
        bag[x] -= 1
        if bag[x] == 0:
            del bag[x]
            distinct_count -= 1
            
    else:  # query[0] == 3
        print(distinct_count)
q = int(input())
freq = {}
distinct_count = 0

for _ in range(q):
    query = list(map(int, input().split()))
    
    if query[0] == 1:
        x = query[1]
        if x not in freq:
            freq[x] = 0
            distinct_count += 1
        freq[x] += 1
        
    elif query[0] == 2:
        x = query[1]
        freq[x] -= 1
        if freq[x] == 0:
            distinct_count -= 1
            del freq[x]  # Optional: clean up memory
            
    else:  # query[0] == 3
        print(distinct_count)
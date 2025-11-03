import sys

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    ptr = 0
    N = int(data[ptr]); ptr += 1
    Q = int(data[ptr]); ptr += 1
    
    # Each component will maintain a sorted list (descending) of up to 10 largest vertices
    comp_rep = list(range(N + 1))  # comp_rep[i] = representative of the component containing i
    comp_list = [[i] for i in range(N + 1)]  # List of vertices in each component (only maintained for representative)
    
    output = []
    
    for _ in range(Q):
        t = int(data[ptr]); ptr += 1
        if t == 1:
            u = int(data[ptr]); ptr += 1
            v = int(data[ptr]); ptr += 1
            
            # Find representatives
            ru = comp_rep[u]
            while comp_rep[ru] != ru:
                ru = comp_rep[ru]
            rv = comp_rep[v]
            while comp_rep[rv] != rv:
                rv = comp_rep[rv]
            
            if ru == rv:
                continue  # Already in same component
            
            # Union: merge smaller list into larger one for efficiency
            if len(comp_list[ru]) < len(comp_list[rv]):
                ru, rv = rv, ru
            
            # Merge rv into ru
            merged = comp_list[ru] + comp_list[rv]
            # Sort in descending order and keep top 10
            merged.sort(reverse=True)
            comp_list[ru] = merged[:10]
            
            # Update parent pointers: make all nodes in rv's component point to ru
            # We update only the representative of rv's component
            comp_list[rv] = []  # Clear to save space
            comp_rep[rv] = ru
            
            # Note: We don't update every node's comp_rep here — we use path compression via loop when needed
            # When querying, we will find the true root by traversing
            
        else:  # t == 2
            v = int(data[ptr]); ptr += 1
            k = int(data[ptr]); ptr += 1
            
            # Find the root representative of v
            r = v
            path = []
            while comp_rep[r] != r:
                path.append(r)
                r = comp_rep[r]
            # Path compression
            for node in path:
                comp_rep[node] = r
            
            lst = comp_list[r]
            if k <= len(lst):
                output.append(str(lst[k - 1]))
            else:
                output.append(str(-1))
    
    print('\n'.join(output))

if __name__ == '__main__':
    main()
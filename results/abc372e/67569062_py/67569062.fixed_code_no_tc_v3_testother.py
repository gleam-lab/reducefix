import sys

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    ptr = 0
    N = int(data[ptr])
    ptr += 1
    Q = int(data[ptr])
    ptr += 1
    
    # Store the graph as adjacency list
    adj = [[] for _ in range(N + 1)]
    
    # We'll process queries and maintain connected components using Union-Find
    # But instead of storing only top 10 by merging lists incorrectly,
    # we will store all nodes in a component via union-find with sets or sorted lists
    parent = list(range(N + 1))
    rank = [0] * (N + 1)
    comp = [set([i]) for i in range(N + 1)]  # comp[i] is the set of vertices in component of root i
    
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x, y):
        rx = find(x)
        ry = find(y)
        if rx == ry:
            return
        # Union by rank
        if rank[rx] < rank[ry]:
            rx, ry = ry, rx
        parent[ry] = rx
        # Merge the smaller component into the larger one
        if len(comp[rx]) < len(comp[ry]):
            rx, ry = ry, rx
        # Always merge ry into rx
        if rx != ry:
            comp[rx].update(comp[ry])
            comp[ry].clear()
        # Keep only up to 10 largest vertex numbers to avoid memory/time issues
        if len(comp[rx]) > 10:
            # Keep only the 10 largest
            largest = sorted(comp[rx], reverse=True)[:10]
            comp[rx] = set(largest)
    
    output = []
    for _ in range(Q):
        t = int(data[ptr])
        ptr += 1
        if t == 1:
            u = int(data[ptr])
            v = int(data[ptr + 1])
            ptr += 2
            union(u, v)
        else:  # t == 2
            v = int(data[ptr])
            k = int(data[ptr + 1])
            ptr += 2
            root = find(v)
            comp_list = sorted(comp[root], reverse=True)
            if k <= len(comp_list):
                output.append(str(comp_list[k - 1]))
            else:
                output.append(str(-1))
    
    print('\n'.join(output))

if __name__ == '__main__':
    main()
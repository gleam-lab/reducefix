class UnionFind:
    def __init__(self, n):
        self.par = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.par[y] = x
        self.size[x] += self.size[y]
        return True

    def same(self, x, y):
        return self.find(x) == self.find(y)

N, Q = map(int, input().split())

# For each component root, maintain a sorted list (descending) of vertex numbers
# We only need to keep at most 10 largest values since k <= 10
component_max_vertices = {}
for i in range(1, N + 1):
    component_max_vertices[i] = [i]

uf = UnionFind(N + 1)

results = []

for _ in range(Q):
    query = list(map(int, input().split()))
    
    if query[0] == 1:  # Add edge
        u, v = query[1], query[2]
        if not uf.same(u, v):
            root_u = uf.find(u)
            root_v = uf.find(v)
            
            # Always attach smaller tree to larger one (by size)
            if uf.size[root_u] < uf.size[root_v]:
                root_u, root_v = root_v, root_u
            
            # Merge the components: move all vertices from root_v to root_u
            # But we only care about top 10 largest vertex numbers
            combined = component_max_vertices[root_u] + component_max_vertices[root_v]
            combined.sort(reverse=True)
            # Keep only top 10
            component_max_vertices[root_u] = combined[:10]
            
            # Clean up old component
            del component_max_vertices[root_v]
            
            # Perform union
            uf.unite(u, v)
            
    else:  # Query type 2
        v, k = query[1], query[2]
        root = uf.find(v)
        
        vertices_list = component_max_vertices[root]
        if k <= len(vertices_list):
            results.append(vertices_list[k-1])  # k-th largest (1-indexed)
        else:
            results.append(-1)

# Output results
for res in results:
    print(res)
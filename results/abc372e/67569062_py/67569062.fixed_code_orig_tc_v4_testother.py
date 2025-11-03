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

# Store the vertices in each component, sorted in descending order
components = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    components[i] = [i]

uf = UnionFind(N + 1)
ans = []

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        u, v = query[1], query[2]
        if not uf.same(u, v):
            root_u = uf.find(u)
            root_v = uf.find(v)
            # Always merge smaller into larger (by root index, doesn't matter)
            if len(components[root_u]) < len(components[root_v]):
                u, v = v, u
                root_u, root_v = root_v, root_u
            
            # Merge components[root_v] into components[root_u]
            merged = []
            i = j = 0
            comp_u = components[root_u]
            comp_v = components[root_v]
            
            # Merge two sorted lists (descending order)
            while i < len(comp_u) and j < len(comp_v):
                if comp_u[i] > comp_v[j]:
                    merged.append(comp_u[i])
                    i += 1
                else:
                    merged.append(comp_v[j])
                    j += 1
            
            while i < len(comp_u):
                merged.append(comp_u[i])
                i += 1
            while j < len(comp_v):
                merged.append(comp_v[j])
                j += 1
            
            # Keep at most 10 largest elements
            if len(merged) > 10:
                merged = merged[:10]
            
            # Update the root and clear the old component
            uf.unite(u, v)
            new_root = uf.find(u)
            components[new_root] = merged
            # Clear the old component to avoid reuse
            components[root_v] = []
    else:
        v, k = query[1], query[2]
        root = uf.find(v)
        comp = components[root]
        if k <= len(comp):
            ans.append(comp[k-1])
        else:
            ans.append(-1)

for a in ans:
    print(a)
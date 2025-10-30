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

# Store the vertices in each connected component (sorted in descending order)
components = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    components[i] = [i]

ans = []
uf = UnionFind(N + 1)

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        u, v = query[1], query[2]
        if not uf.same(u, v):
            root_u = uf.find(u)
            root_v = uf.find(v)
            # Always merge smaller into larger (by root index or size doesn't matter as much)
            if root_u != root_v:
                # Ensure root_u becomes the new root
                if len(components[root_u]) < len(components[root_v]):
                    root_u, root_v = root_v, root_u
                # Merge components[root_v] into components[root_u]
                combined = components[root_u] + components[root_v]
                combined.sort(reverse=True)  # Sort in descending order
                if len(combined) > 10:
                    combined = combined[:10]  # Keep only top 10 largest
                uf.unite(u, v)
                new_root = uf.find(u)
                components[new_root] = combined
                # Clear the old component to avoid reuse
                components[root_v] = []
    else:  # query[0] == 2
        v, k = query[1], query[2]
        root = uf.find(v)
        comp = components[root]
        if k <= len(comp):
            ans.append(comp[k - 1])  # k-th largest (0-indexed)
        else:
            ans.append(-1)

for a in ans:
    print(a)
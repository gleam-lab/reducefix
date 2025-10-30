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

# mem[i] will store the top 10 largest vertex numbers in the component containing i (only valid for root)
mem = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
    mem[i] = [i]

uf = UnionFind(N + 1)

ans = []

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        u, v = query[1], query[2]
        if not uf.same(u, v):
            root_u = uf.find(u)
            root_v = uf.find(v)
            # Always attach smaller tree to larger one (union by size)
            if uf.size[root_u] < uf.size[root_v]:
                root_u, root_v = root_v, root_u
            # Merge the components: add all nodes from smaller component to larger
            merged = mem[root_u] + mem[root_v]
            # Sort in descending order and keep at most 10 largest
            merged.sort(reverse=True)
            mem[root_u] = merged[:10]
            # Update parent and size in union-find
            uf.unite(u, v)
            new_root = uf.find(u)
            # Ensure the root has the correct list
            if new_root != root_u:
                mem[new_root] = mem[root_u]
    else:
        v, k = query[1], query[2]
        root = uf.find(v)
        component_list = mem[root]
        if k <= len(component_list):
            ans.append(component_list[k - 1])
        else:
            ans.append(-1)

for a in ans:
    print(a)
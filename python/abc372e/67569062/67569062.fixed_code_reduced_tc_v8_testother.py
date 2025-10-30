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

# mem[i] will store the largest up to 10 vertex numbers in the component of root i
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
            # Always attach smaller tree to larger one (by size)
            if uf.size[root_u] < uf.size[root_v]:
                u, v = v, u
                root_u, root_v = root_v, root_u
            # Merge mem[root_v] into mem[root_u]
            merged = mem[root_u] + mem[root_v]
            # Sort in descending order and keep top 10
            merged.sort(reverse=True)
            mem[root_u] = merged[:10]
            uf.unite(u, v)
    else:  # query type 2
        v, k = query[1], query[2]
        root = uf.find(v)
        if k <= len(mem[root]):
            ans.append(mem[root][k - 1])
        else:
            ans.append(-1)

for a in ans:
    print(a)
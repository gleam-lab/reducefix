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

    def get_size(self, x):
        return self.size[self.find(x)]

N,Q=(int(x) for x in input().split())

mem=[]
for i in range(N+1):
    mem.append([i])

ans=[]
#nはノードの数
uf = UnionFind(N+1)
for i in range(Q):
    q=list(map(int, input().split()))
    if q[0] == 1:
        if not uf.same(q[1], q[2]):
            a = uf.find(q[1])
            b = uf.find(q[2])
            uf.unite(q[1], q[2])
            c = uf.find(q[1])
            aa = mem[a]
            bb = mem[b]
            res=[]
            for j in aa:
                res.append(j)
            for j in bb:
                res.append(j)
            if len(res) > 10:
                res = res[:10]
            mem[c] = res
    else:
        try:
            p = uf.find(q[1])
            ans.append(mem[p][-q[2]])
        except:
            ans.append(-1)

for i in ans:
    print(i)
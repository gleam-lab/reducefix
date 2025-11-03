import sys

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

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    N = int(data[idx])
    Q = int(data[idx + 1])
    idx += 2
    
    # For each component root, maintain a sorted list (in descending order) of up to 10 largest vertices
    comp_max = [[] for _ in range(N + 1)]
    for i in range(1, N + 1):
        comp_max[i] = [i]  # Each vertex starts as its own component with just itself
    
    uf = UnionFind(N + 1)
    output = []
    
    for _ in range(Q):
        t = int(data[idx])
        if t == 1:
            u = int(data[idx + 1])
            v = int(data[idx + 2])
            idx += 3
            
            if uf.same(u, v):
                continue
                
            root_u = uf.find(u)
            root_v = uf.find(v)
            
            # Always attach smaller tree to larger one (by size), so we merge into root_u if it's larger
            if uf.size[root_u] < uf.size[root_v]:
                u, v = v, u
                root_u, root_v = root_v, root_u
            
            # Merge comp_max[root_v] into comp_max[root_u]
            merged = comp_max[root_u] + comp_max[root_v]
            # Sort in descending order and keep top 10
            merged.sort(reverse=True)
            comp_max[root_u] = merged[:10]
            
            uf.unite(u, v)
            
        else:  # t == 2
            v = int(data[idx + 1])
            k = int(data[idx + 2])
            idx += 3
            
            root = uf.find(v)
            if k <= len(comp_max[root]):
                output.append(str(comp_max[root][k - 1]))
            else:
                output.append(str(-1))
    
    print('\n'.join(output))

if __name__ == "__main__":
    main()
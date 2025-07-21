struct UnionFind {
    vector<int> parent, rank, size;

    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findRoot(int x) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                parent[rx] = ry;
                size[ry] += size[rx];
            } else {
                parent[ry] = rx;
                size[rx] += size[ry];
                if (rank[rx] == rank[ry]) {
                    rank[rx]++;
                }
            }
            return true;
        }
        return false;
    }
};
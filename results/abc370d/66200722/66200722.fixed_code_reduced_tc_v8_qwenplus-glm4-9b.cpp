#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> p, rank;
    int n;

    UnionFind(int size) : n(size), p(size, -1) {}

    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) swap(rootX, rootY);
        if (rank[rootX] == rank[rootY]) rank[rootX]++;
        p[rootX] = rootY;
        return true;
    }
};

void solve() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // 1 wall initially
    UnionFind uf(h * w);

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to 0-based index
        if (grid[r][c]) {
            grid[r][c] = 0; // Bomb destroys the wall
            uf.unite(r, c); // Union the bomb's position with itself
        } else {
            int r2 = r, c2 = c;
            // Check all four directions
            if (r > 0) uf.unite(r2, r2 - 1);
            if (r < h - 1) uf.unite(r2, r2 + 1);
            if (c > 0) uf.unite(c2, c2 - 1);
            if (c < w - 1) uf.unite(c2, c2 + 1);
        }
    }

    // Count remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int root = uf.find(i * w + j);
            if (grid[i][j] && uf.rank[root] == 0) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
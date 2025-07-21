#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        rank[pu] += rank[pv];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true));

    UnionFind uf(h * w);

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!grid[r][c]) continue;

        grid[r][c] = false;

        int id = r * w + c;

        // Check up
        if (r > 0 && grid[r - 1][c]) {
            int up_id = (r - 1) * w + c;
            uf.unite(id, up_id);
        }

        // Check down
        if (r < h - 1 && grid[r + 1][c]) {
            int down_id = (r + 1) * w + c;
            uf.unite(id, down_id);
        }

        // Check left
        if (c > 0 && grid[r][c - 1]) {
            int left_id = r * w + (c - 1);
            uf.unite(id, left_id);
        }

        // Check right
        if (c < w - 1 && grid[r][c + 1]) {
            int right_id = r * w + (c + 1);
            uf.unite(id, right_id);
        }
    }

    int components = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] && uf.find(i * w + j) == i * w + j)
                ++components;
        }
    }

    cout << h * w - components << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) parent[pv] = pu;
        else if (rank[pu] < rank[pv]) parent[pu] = pv;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    DisjointSet ds(h * w + 1);
    vector<vector<int>> grid(h, vector<int>(w, 1));

    auto get_id = [&](int r, int c) { return r * w + c + 1; };

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!grid[r][c]) continue;

        grid[r][c] = 0;

        int id = get_id(r, c);

        if (r > 0 && grid[r - 1][c]) {
            ds.merge(id, get_id(r - 1, c));
        }
        if (r < h - 1 && grid[r + 1][c]) {
            ds.merge(id, get_id(r + 1, c));
        }
        if (c > 0 && grid[r][c - 1]) {
            ds.merge(id, get_id(r, c - 1));
        }
        if (c < w - 1 && grid[r][c + 1]) {
            ds.merge(id, get_id(r, c + 1));
        }
    }

    unordered_set<int> unique_roots;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j]) {
                unique_roots.insert(ds.find(get_id(i, j)));
            }
        }
    }

    cout << unique_roots.size() << '\n';

    return 0;
}
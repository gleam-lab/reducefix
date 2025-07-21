#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

void solve() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<unordered_map<int, int>> rows(h), cols(w);
    UnionFind uf(h * w);

    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!rows[r].count(c)) {
            rows[r][c] = qi;
            cols[c][r] = qi;
            
            if (r > 0 && rows[r - 1].count(c)) {
                uf.unite(rows[r - 1][c], qi);
            }
            if (r < h - 1 && rows[r + 1].count(c)) {
                uf.unite(rows[r + 1][c], qi);
            }
            if (c > 0 && cols[c - 1].count(r)) {
                uf.unite(cols[c - 1][r], qi);
            }
            if (c < w - 1 && cols[c + 1].count(r)) {
                uf.unite(cols[c + 1][r], qi);
            }
        } else {
            int root = uf.find(rows[r][c]);
            int minRow = rows[root].begin()->first;
            int maxRow = rows[root].rbegin()->first;
            int minCol = cols[root].begin()->first;
            int maxCol = cols[root].rbegin()->first;

            for (int i = minRow; i <= maxRow; ++i) {
                if (i != r && rows[i].count(c)) {
                    uf.unite(root, rows[i][c]);
                }
            }
            for (int j = minCol; j <= maxCol; ++j) {
                if (j != c && cols[j].count(r)) {
                    uf.unite(root, cols[j][r]);
                }
            }
        }
    }

    unordered_set<int> uniqueComponents;
    for (int i = 0; i < h; ++i) {
        for (const auto& [_, component] : rows[i]) {
            uniqueComponents.insert(uf.find(component));
        }
    }

    cout << h * w - uniqueComponents.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
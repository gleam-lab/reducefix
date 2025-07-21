#include <iostream>
#include <vector>
#include <map>
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
        
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) ++rank[pu];
    }
};

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<map<int, int>> rows(h), cols(w);
    UnionFind uf(h * w);
    
    for (int qi = 0; qi < q; ++qi) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if (!rows[r].contains(c)) {
            rows[r][c] = qi;
            cols[c][r] = qi;
            continue;
        }
        
        int qi_row = rows[r][c], qi_col = cols[c][r];
        int pi_row = uf.find(qi_row), pi_col = uf.find(qi_col);
        
        if (pi_row == pi_col) continue;
        
        // Merge components
        uf.unite(pi_row, pi_col);
        
        // Update boundary conditions
        int min_r = min(rows[r].begin()->second, cols[c].begin()->second);
        int max_r = max(prev(rows[r].end())->second, prev(cols[c].end())->second);
        
        for (auto it = rows[r].begin(); it != rows[r].end(); ) {
            if (uf.find(it->second) == pi_col) {
                it = rows[r].erase(it);
            } else {
                ++it;
            }
        }
        
        for (auto it = cols[c].begin(); it != cols[c].end(); ) {
            if (uf.find(it->second) == pi_col) {
                it = cols[c].erase(it);
            } else {
                ++it;
            }
        }
        
        rows[r][c] = min_r;
        cols[c][r] = min_r;
    }
    
    int remaining_walls = h * w;
    for (const auto& row : rows) {
        remaining_walls -= row.size();
    }
    
    cout << remaining_walls << endl;
    
    return 0;
}
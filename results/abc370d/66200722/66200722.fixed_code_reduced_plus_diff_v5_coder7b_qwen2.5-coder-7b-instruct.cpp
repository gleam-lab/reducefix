#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] = (parent[u] == u ? u : find(parent[u]));
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    UnionFind uf(h * w + 1);
    unordered_map<int, vector<int>> rows, cols;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        int id = r * w + c;

        if (!rows.count(id)) {
            rows[id].push_back(r);
            cols[id].push_back(c);
            continue;
        }

        int row_id = rows[id].back();
        int col_id = cols[id].back();

        if (row_id != r || col_id != c) {
            // Find the smallest index greater than row_id where there is no wall in the same column
            auto it_row = upper_bound(rows[col_id].begin(), rows[col_id].end(), row_id);
            if (it_row != rows[col_id].end()) {
                int new_id = (*it_row) * w + col_id;
                uf.unite(id, new_id);
            }

            // Find the largest index smaller than col_id where there is no wall in the same row
            auto it_col = lower_bound(cols[row_id].begin(), cols[row_id].end(), col_id);
            if (it_col != cols[row_id].begin()) {
                --it_col;
                int new_id = row_id * w + (*it_col);
                uf.unite(id, new_id);
            }
        }

        rows[id].push_back(r);
        cols[id].push_back(c);
    }

    set<int> unique_ids;
    for (const auto& entry : rows) {
        for (int id : entry.second) {
            unique_ids.insert(uf.find(id));
        }
    }

    cout << (h * w - unique_ids.size()) << endl;

    return 0;
}
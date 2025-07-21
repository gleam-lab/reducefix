#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row_walls(H), col_walls(W);
    int total_walls = H * W;
    
    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        
        if (!row_walls[R].count(C)) {
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            total_walls--;
        } else {
            // Check up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int up_row = *it_up;
                if (!row_walls[up_row].count(C)) {
                    row_walls[up_row].insert(C);
                    col_walls[C].insert(up_row);
                    total_walls--;
                }
            }
            // Check down
            auto it_down = col_walls[C].upper_bound(R);
            if (it_down != col_walls[C].end()) {
                int down_row = *it_down;
                if (!row_walls[down_row].count(C)) {
                    row_walls[down_row].insert(C);
                    col_walls[C].insert(down_row);
                    total_walls--;
                }
            }
            // Check left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int left_col = *it_left;
                if (!col_walls[left_col].count(R)) {
                    col_walls[left_col].insert(R);
                    row_walls[R].insert(left_col);
                    total_walls--;
                }
            }
            // Check right
            auto it_right = row_walls[R].upper_bound(C);
            if (it_right != row_walls[R].end()) {
                int right_col = *it_right;
                if (!col_walls[right_col].count(R)) {
                    col_walls[right_col].insert(R);
                    row_walls[R].insert(right_col);
                    total_walls--;
                }
            }
        }
    }
    cout << total_walls << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<map<int, int>> row_map(H), col_map(W);
    int max_id = 0;

    // For each cell, track whether it's been bombed
    vector<vector<bool>> bombed(H, vector<bool>(W, false));

    // Union-Find data structure for managing intervals
    vector<int> parent(max(H, W) * 32); // generous size estimate
    iota(parent.begin(), parent.end(), 0);

    function<int(int, vector<int>&)> find = [&](int x, vector<int> &par) {
        if (par[x] != x)
            par[x] = find(par[x], par);
        return par[x];
    };

    auto merge = [&](int x, int y, vector<int> &par, vector<int> &min_val, vector<int> &max_val) {
        int fx = find(x, par), fy = find(y, par);
        if (fx == fy) return;
        // Merge smaller set into larger one
        if (min_val[fx] > min_val[fy]) swap(fx, fy);
        par[fy] = fx;
        min_val[fx] = min(min_val[fx], min_val[fy]);
        max_val[fx] = max(max_val[fx], max_val[fy]);
    };

    vector<int> row_min(max_id), row_max(max_id), col_min(max_id), col_max(max_id);
    row_min.assign(row_min.size(), W);
    row_max.assign(row_max.size(), -1);
    col_min.assign(col_min.size(), H);
    col_max.assign(col_max.size(), -1);

    for (int query = 0; query < Q; ++query) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (!bombed[R][C]) {
            // First bomb at this cell

            // Add to row map
            auto it = row_map[R].insert({C, max_id++}).first;
            row_min.push_back(C);
            row_max.push_back(C);
            if (it != row_map[R].begin()) {
                auto prev = prev(it);
                merge(it->second, prev->second, parent, row_min, row_max);
            }
            if (next(it) != row_map[R].end()) {
                auto next_it = next(it);
                merge(it->second, next_it->second, parent, row_min, row_max);
            }

            // Add to column map
            auto it2 = col_map[C].insert({R, max_id++}).first;
            col_min.push_back(R);
            col_max.push_back(R);
            if (it2 != col_map[C].begin()) {
                auto prev = prev(it2);
                merge(it2->second, prev->second, parent, col_min, col_max);
            }
            if (next(it2) != col_map[C].end()) {
                auto next_it = next(it2);
                merge(it2->second, next_it->second, parent, col_min, col_max);
            }

            bombed[R][C] = true;
        } else {
            // Already bombed, destroy nearest walls in four directions

            // Check up
            auto it = col_map[C].lower_bound(R);
            if (it != col_map[C].begin()) {
                --it;
                int r = it->first;
                if (!bombed[r][C]) {
                    bombed[r][C] = true;
                }
            }

            // Check down
            it = col_map[C].upper_bound(R);
            if (it != col_map[C].end()) {
                int r = it->first;
                if (!bombed[r][C]) {
                    bombed[r][C] = true;
                }
            }

            // Check left
            auto it_row = row_map[R].lower_bound(C);
            if (it_row != row_map[R].begin()) {
                --it_row;
                int c = it_row->first;
                if (!bombed[R][c]) {
                    bombed[R][c] = true;
                }
            }

            // Check right
            it_row = row_map[R].upper_bound(C);
            if (it_row != row_map[R].end()) {
                int c = it_row->first;
                if (!bombed[R][c]) {
                    bombed[R][c] = true;
                }
            }
        }
    }

    // Count remaining walls
    long long remaining = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!bombed[i][j]) {
                remaining++;
            }
        }
    }

    cout << remaining << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
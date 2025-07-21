#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
using grid = vector<vector<T>>;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // For each row, keep track of remaining columns with walls
    vector<set<int>> row_walls(H + 1);
    // For each column, keep track of remaining rows with walls
    vector<set<int>> col_walls(W + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        // If there's a wall at the queried cell, remove it
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Look right in row
            auto rit = row_walls[r].lower_bound(c);
            if (rit != row_walls[r].end()) {
                int pos = *rit;
                row_walls[r].erase(pos);
                col_walls[pos].erase(r);
            }

            // Look left in row
            rit = row_walls[r].lower_bound(c);
            if (rit != row_walls[r].begin()) {
                --rit;
                int pos = *rit;
                row_walls[r].erase(pos);
                col_walls[pos].erase(r);
            }

            // Look down in column
            auto dit = col_walls[c].lower_bound(r);
            if (dit != col_walls[c].end()) {
                int pos = *dit;
                col_walls[c].erase(pos);
                row_walls[pos].erase(c);
            }

            // Look up in column
            dit = col_walls[c].lower_bound(r);
            if (dit != col_walls[c].begin()) {
                --dit;
                int pos = *dit;
                col_walls[c].erase(pos);
                row_walls[pos].erase(c);
            }
        }
    }

    ll remaining = 0;
    for (int i = 1; i <= H; ++i) {
        remaining += row_walls[i].size();
    }
    cout << remaining << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
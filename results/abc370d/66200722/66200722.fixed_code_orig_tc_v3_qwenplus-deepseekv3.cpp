#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<set<int>> row_walls(h + 1); // 1-based indexing
    vector<set<int>> col_walls(w + 1); // 1-based indexing
    for (int i = 1; i <= h; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(w + 1);
    }
    for (int j = 1; j <= w; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(h + 1);
    }

    long long remaining = h * 1LL * w;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall already destroyed, process the bomb
            auto it = row_walls[r].find(c);
            int left = *prev(it);
            int right = *next(it);
            if (left + 1 <= c - 1) {
                auto& col = col_walls[c];
                auto it_col = col.lower_bound(r);
                int up = *prev(it_col);
                int down = *it_col;
                if (up + 1 <= r - 1) {
                    int target = r - 1;
                    if (!row_walls[target].count(c)) {
                        row_walls[target].insert(c);
                        col_walls[c].insert(target);
                        remaining--;
                    }
                }
                if (r + 1 <= down - 1) {
                    int target = r + 1;
                    if (!row_walls[target].count(c)) {
                        row_walls[target].insert(c);
                        col_walls[c].insert(target);
                        remaining--;
                    }
                }
            }
            if (c + 1 <= right - 1) {
                auto& row = row_walls[r];
                auto it_row = row.upper_bound(c);
                int next_wall = *it_row;
                for (int j = c + 1; j < next_wall; ++j) {
                    if (!col_walls[j].count(r)) {
                        col_walls[j].insert(r);
                        row_walls[r].insert(j);
                        remaining--;
                    }
                }
            }
            if (left + 1 <= c - 1) {
                auto& row = row_walls[r];
                auto it_row = row.lower_bound(c);
                int prev_wall = *prev(it_row);
                for (int j = prev_wall + 1; j < c; ++j) {
                    if (!col_walls[j].count(r)) {
                        col_walls[j].insert(r);
                        row_walls[r].insert(j);
                        remaining--;
                    }
                }
            }
        } else {
            // Destroy the wall at (r, c)
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining--;
        }
    }

    cout << remaining << '\n';

    return 0;
}
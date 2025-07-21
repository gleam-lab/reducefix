#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Total number of cells
    long long total_walls = 1LL * H * W;

    // Grid to check if a wall exists at (i,j)
    vector<vector<bool>> has_wall(H + 2, vector<bool>(W + 2, true));

    // For each row, we maintain a set of columns that still have walls
    vector<set<int>> row(W + 2); // We index rows from 1 to H
    // For each column, we maintain a set of rows that still have walls
    vector<set<int>> col(H + 2); // We index columns from 1 to W

    // Initialize sets
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (has_wall[r][c]) {
            // If there is a wall at this position, just remove it
            has_wall[r][c] = false;
            row[r].erase(c);
            col[c].erase(r);
            total_walls--;
        } else {
            // Otherwise, look in four directions and destroy first wall in each

            // Left
            auto it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                if (!has_wall[r][j]) continue;
                has_wall[r][j] = false;
                row[r].erase(it);
                col[j].erase(r);
                total_walls--;
            }

            // Right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                if (!has_wall[r][j]) continue;
                has_wall[r][j] = false;
                row[r].erase(it);
                col[j].erase(r);
                total_walls--;
            }

            // Up
            auto it2 = col[c].lower_bound(r);
            if (it2 != col[c].begin()) {
                --it2;
                int i = *it2;
                if (!has_wall[i][c]) continue;
                has_wall[i][c] = false;
                col[c].erase(it2);
                row[i].erase(c);
                total_walls--;
            }

            // Down
            it2 = col[c].lower_bound(r);
            if (it2 != col[c].end()) {
                int i = *it2;
                if (!has_wall[i][c]) continue;
                has_wall[i][c] = false;
                col[c].erase(it2);
                row[i].erase(c);
                total_walls--;
            }
        }
    }

    cout << total_walls << endl;
    return 0;
}
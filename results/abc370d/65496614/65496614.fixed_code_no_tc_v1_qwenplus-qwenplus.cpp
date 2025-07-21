#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i < (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // We use 1-based indexing for rows and columns
    vector<set<int>> rows(h + 2);  // rows[i] stores the columns in row i that still have walls
    vector<set<int>> cols(w + 2);  // cols[j] stores the rows in column j that still have walls

    // Initialize sets with all columns/rows
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    vvb has_wall(h + 2, vb(w + 2, true));

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (has_wall[r][c]) {
            // Case: wall exists at (r,c), destroy it
            has_wall[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Case: no wall at (r,c), destroy first walls in each direction

            // Left
            auto it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                --it;
                int left_col = *it;
                has_wall[r][left_col] = false;
                rows[r].erase(it);
                cols[left_col].erase(r);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int right_col = *it;
                has_wall[r][right_col] = false;
                rows[r].erase(it);
                cols[right_col].erase(r);
            }

            // Up
            auto jt = cols[c].lower_bound(r);
            if (jt != cols[c].begin()) {
                --jt;
                int up_row = *jt;
                has_wall[up_row][c] = false;
                cols[c].erase(jt);
                rows[up_row].erase(c);
            }

            // Down
            jt = cols[c].lower_bound(r);
            if (jt != cols[c].end()) {
                int down_row = *jt;
                has_wall[down_row][c] = false;
                cols[c].erase(jt);
                rows[down_row].erase(c);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += has_wall[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
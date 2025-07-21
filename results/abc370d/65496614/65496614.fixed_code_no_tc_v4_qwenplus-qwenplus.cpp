#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i < (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize grid: true means wall exists
    vvb has_wall(H + 2, vb(W + 2, true));

    // For each row, keep a set of columns that still have walls
    vector<set<int>> row_left(W + 2), row_right(W + 2);
    vector<set<int>> col_up(H + 2), col_down(H + 2);

    // Also maintain sets for rows and columns to find nearest walls efficiently
    vector<set<int>> rows(H + 2);
    vector<set<int>> cols(W + 2);

    // Initialize the sets with all positions having walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (has_wall[r][c]) {
            // If there's a wall at this position, just remove it
            has_wall[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Otherwise, find nearest walls in each direction
            // Left
            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                int j = *left;
                has_wall[r][j] = false;
                rows[r].erase(j);
                cols[j].erase(r);
            }

            // Right
            auto right = rows[r].lower_bound(c);
            if (right != rows[r].end()) {
                int j = *right;
                has_wall[r][j] = false;
                rows[r].erase(j);
                cols[j].erase(r);
            }

            // Up
            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                int i = *up;
                has_wall[i][c] = false;
                cols[c].erase(i);
                rows[i].erase(c);
            }

            // Down
            auto down = cols[c].lower_bound(r);
            if (down != cols[c].end()) {
                int i = *down;
                has_wall[i][c] = false;
                cols[c].erase(i);
                rows[i].erase(c);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    rep1(i, H + 1) rep1(j, W + 1) ans += has_wall[i][j];

    cout << ans << endl;
    return 0;
}
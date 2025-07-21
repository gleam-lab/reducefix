#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

const int INF = 1 << 30;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Each row and column will have sets of available wall positions
    vector<set<int>> rows(H + 2), cols(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    // Grid to track if a wall exists at (i,j)
    vvi grid(H + 2, vi(W + 2, 1));  // 1 means wall exists

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            // Wall exists: destroy it and remove from sets
            grid[r][c] = 0;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Wall doesn't exist: destroy the first walls in each direction

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int ur = *it;
                grid[ur][c] = 0;
                rows[ur].erase(c);
                cols[c].erase(ur);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int dr = *it;
                grid[dr][c] = 0;
                rows[dr].erase(c);
                cols[c].erase(dr);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                int lc = *jt;
                grid[r][lc] = 0;
                cols[lc].erase(r);
                rows[r].erase(lc);
            }

            // Right
            jt = rows[r].lower_bound(c);
            if (jt != rows[r].end()) {
                int rc = *jt;
                grid[r][rc] = 0;
                cols[rc].erase(r);
                rows[r].erase(rc);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            ans += grid[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}
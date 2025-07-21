#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i <= (int)(n); ++i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // We represent the grid using a 2D boolean array
    vvb grid(H + 2, vb(W + 2, true)); // 1-based indexing

    // For each row and column, we maintain ordered sets of wall positions
    vector<set<int>> rows(H + 2), cols(W + 2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            // Case: Bomb placed on a wall -> destroy it
            grid[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Case: Bomb placed on empty cell -> destroy first walls in 4 directions

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                int x = *it;
                if (x >= 1 && x <= H && grid[x][c]) {
                    grid[x][c] = false;
                    rows[x].erase(c);
                    cols[c].erase(x);
                }
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int x = *it;
                if (x >= 1 && x <= H && grid[x][c]) {
                    grid[x][c] = false;
                    rows[x].erase(c);
                    cols[c].erase(x);
                }
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                int y = *jt;
                if (y >= 1 && y <= W && grid[r][y]) {
                    grid[r][y] = false;
                    rows[r].erase(y);
                    cols[y].erase(r);
                }
            }

            // Right
            jt = rows[r].lower_bound(c);
            if (jt != rows[r].end()) {
                int y = *jt;
                if (y >= 1 && y <= W && grid[r][y]) {
                    grid[r][y] = false;
                    rows[r].erase(y);
                    cols[y].erase(r);
                }
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    rep1(i, H) rep1(j, W) ans += grid[i][j];

    cout << ans << "\n";
    return 0;
}
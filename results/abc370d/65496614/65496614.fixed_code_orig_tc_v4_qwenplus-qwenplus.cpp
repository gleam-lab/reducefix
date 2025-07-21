#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)(n)-1; i >= 0; --i)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Each row and column's available positions in sets for quick access
    vector<set<int>> rows(H+2), cols(W+2);
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    // Grid to check if wall exists at position (i,j)
    vvi grid(H+2, vi(W+2, 1));  // 1 means wall exists

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            grid[r][c] = 0;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Check in all four directions
            for (int d = 0; d < 4; ++d) {
                int x = r + dx[d], y = c + dy[d];
                while (x >= 1 && x <= H && y >= 1 && y <= W) {
                    if (grid[x][y]) {
                        grid[x][y] = 0;
                        rows[x].erase(y);
                        cols[y].erase(x);
                        break;
                    }
                    x += dx[d];
                    y += dy[d];
                }
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
            ans += grid[i][j];

    cout << ans << endl;

    return 0;
}
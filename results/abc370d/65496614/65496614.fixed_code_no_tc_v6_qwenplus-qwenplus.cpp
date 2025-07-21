#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Grid to track presence of wall at each cell
    vector<vector<bool>> has_wall(h + 2, vector<bool>(w + 2, true));

    // For each row, we keep a sorted set of columns that have walls
    vector<set<int>> rows(h + 2);
    // For each column, we keep a sorted set of rows that have walls
    vector<set<int>> cols(w + 2);

    // Initialize each row and column with all wall positions
    rep1(i, h) {
        rep1(j, w) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (has_wall[r][c]) {
            // If there's a wall, remove it
            has_wall[r][c] = false;
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Otherwise, find and destroy the first walls in the four directions

            // Up and Down in column c
            auto& col = cols[c];
            if (!col.empty()) {
                auto it = col.lower_bound(r);
                if (it != col.end()) {
                    // Down direction
                    int y = *it;
                    has_wall[y][c] = false;
                    rows[y].erase(c);
                    col.erase(it);
                }
                if (it != col.begin()) {
                    // Up direction
                    --it;
                    int y = *it;
                    has_wall[y][c] = false;
                    rows[y].erase(c);
                    col.erase(it);
                }
            }

            // Left and Right in row r
            auto& row = rows[r];
            if (!row.empty()) {
                auto it = row.lower_bound(c);
                if (it != row.end()) {
                    // Right direction
                    int x = *it;
                    has_wall[r][x] = false;
                    cols[x].erase(r);
                    row.erase(it);
                }
                if (it != row.begin()) {
                    --it;
                    // Left direction
                    int x = *it;
                    has_wall[r][x] = false;
                    cols[x].erase(r);
                    row.erase(it);
                }
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    rep1(i, h) rep1(j, w) ans += has_wall[i][j];

    cout << ans << endl;
    return 0;
}
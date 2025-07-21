#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
const int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    vector<vector<set<int>>> row_walls(H), col_walls(W);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (has_wall[r][c]) {
            // Remove wall at (r,c)
            has_wall[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Find and remove first walls in each direction
            for (int dir = 0; dir < 4; ++dir) {
                int x = r, y = c;
                if (dx[dir] != 0) { // up or down - working with column c
                    if (dx[dir] == -1) { // up
                        auto it = col_walls[c].lower_bound(r);
                        if (it != col_walls[c].begin()) {
                            --it;
                            x = *it;
                            y = c;
                            has_wall[x][y] = false;
                            row_walls[x].erase(y);
                            col_walls[y].erase(x);
                        }
                    } else { // down
                        auto it = col_walls[c].lower_bound(r);
                        if (next(it) != col_walls[c].end()) {
                            ++it;
                            x = *it;
                            y = c;
                            has_wall[x][y] = false;
                            row_walls[x].erase(y);
                            col_walls[y].erase(x);
                        }
                    }
                } else { // left or right - working with row r
                    if (dy[dir] == -1) { // left
                        auto it = row_walls[r].lower_bound(c);
                        if (it != row_walls[r].begin()) {
                            --it;
                            x = r;
                            y = *it;
                            has_wall[x][y] = false;
                            row_walls[x].erase(y);
                            col_walls[y].erase(x);
                        }
                    } else { // right
                        auto it = row_walls[r].lower_bound(c);
                        if (next(it) != row_walls[r].end()) {
                            ++it;
                            x = r;
                            y = *it;
                            has_wall[x][y] = false;
                            row_walls[x].erase(y);
                            col_walls[y].erase(x);
                        }
                    }
                }
            }
        }
    }

    int remaining = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) remaining++;
        }
    }

    cout << remaining << "\n";
    return 0;
}
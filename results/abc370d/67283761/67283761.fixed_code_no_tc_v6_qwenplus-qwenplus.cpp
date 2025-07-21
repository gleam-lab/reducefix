#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Represent the presence of walls using a 2D grid
    vector<vector<bool>> has_wall(H + 2, vector<bool>(W + 2, true));

    // For each row and column, keep track of wall positions using ordered sets
    vector<set<int>> rows(H + 2), cols(W + 2);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (has_wall[r][c]) {
            // Bomb hits a wall: destroy it
            has_wall[r][c] = false;

            // Remove from row and column sets
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Bomb hits empty cell: destroy first visible walls in all directions
            // Left
            if (!rows[r].empty() && *rows[r].lower_bound(c) == c) {
                auto it = rows[r].lower_bound(c);
                if (it != rows[r].begin()) {
                    --it;
                    int y = *it;
                    if (has_wall[r][y]) {
                        has_wall[r][y] = false;
                        rows[r].erase(it);
                    }
                }
            }

            // Right
            if (!rows[r].empty()) {
                auto it = rows[r].upper_bound(c);
                if (it != rows[r].end()) {
                    int y = *it;
                    if (has_wall[r][y]) {
                        has_wall[r][y] = false;
                        rows[r].erase(it);
                    }
                }
            }

            // Up
            if (!cols[c].empty()) {
                auto it = cols[c].upper_bound(r);
                if (it != cols[c].end()) {
                    int x = *it;
                    if (has_wall[x][c]) {
                        has_wall[x][c] = false;
                        cols[c].erase(it);
                    }
                }
            }

            // Down
            if (!cols[c].empty() && *cols[c].lower_bound(r) == r) {
                auto it = cols[c].lower_bound(r);
                if (it != cols[c].begin()) {
                    --it;
                    int x = *it;
                    if (has_wall[x][c]) {
                        has_wall[x][c] = false;
                        cols[c].erase(it);
                    }
                }
            }
        }
    }

    // Count remaining walls
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j])
                count++;
        }
    }

    cout << count << endl;
    return 0;
}
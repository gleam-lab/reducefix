#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> grid(H + 1, vector<bool>(W + 1, true));
    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);

    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    int broken = 0;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            grid[r][c] = false;
            broken++;
            row_walls[r].insert(c);
            col_walls[c].insert(r);
        } else {
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            --it_left;
            int left = *it_left;
            if (left >= 1 && grid[r][left]) {
                grid[r][left] = false;
                broken++;
                row_walls[r].insert(left);
                col_walls[left].insert(r);
            }
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            int right = *it_right;
            if (right <= W && grid[r][right]) {
                grid[r][right] = false;
                broken++;
                row_walls[r].insert(right);
                col_walls[right].insert(r);
            }
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            --it_up;
            int up = *it_up;
            if (up >= 1 && grid[up][c]) {
                grid[up][c] = false;
                broken++;
                row_walls[up].insert(c);
                col_walls[c].insert(up);
            }
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            int down = *it_down;
            if (down <= H && grid[down][c]) {
                grid[down][c] = false;
                broken++;
                row_walls[down].insert(c);
                col_walls[c].insert(down);
            }
        }
    }

    cout << H * W - broken << '\n';

    return 0;
}
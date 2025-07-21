#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);

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

        if (row_walls[r].count(c)) {
            broken++;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            it_left--;
            int left_wall = *it_left;
            if (left_wall != 0) {
                broken++;
                row_walls[r].erase(left_wall);
                col_walls[left_wall].erase(r);
            }

            // Right
            auto it_right = row_walls[r].upper_bound(c);
            int right_wall = *it_right;
            if (right_wall != W + 1) {
                broken++;
                row_walls[r].erase(right_wall);
                col_walls[right_wall].erase(r);
            }

            // Up
            auto it_up = col_walls[c].lower_bound(r);
            it_up--;
            int up_wall = *it_up;
            if (up_wall != 0) {
                broken++;
                col_walls[c].erase(up_wall);
                row_walls[up_wall].erase(c);
            }

            // Down
            auto it_down = col_walls[c].upper_bound(r);
            int down_wall = *it_down;
            if (down_wall != H + 1) {
                broken++;
                col_walls[c].erase(down_wall);
                row_walls[down_wall].erase(c);
            }
        }
    }

    cout << H * W - broken << '\n';

    return 0;
}
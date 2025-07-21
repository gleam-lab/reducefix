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

    int remaining = H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists, so destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining++;
        } else {
            // No wall, find first walls in four directions
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            it_left--;
            int left_wall = *it_left;
            if (left_wall >= 1 && left_wall <= W) {
                row_walls[r].insert(left_wall);
                col_walls[left_wall].insert(r);
                remaining--;
            }

            // Right
            auto it_right = row_walls[r].lower_bound(c);
            int right_wall = *it_right;
            if (right_wall >= 1 && right_wall <= W) {
                row_walls[r].insert(right_wall);
                col_walls[right_wall].insert(r);
                remaining--;
            }

            // Up
            auto it_up = col_walls[c].lower_bound(r);
            it_up--;
            int up_wall = *it_up;
            if (up_wall >= 1 && up_wall <= H) {
                col_walls[c].insert(up_wall);
                row_walls[up_wall].insert(c);
                remaining--;
            }

            // Down
            auto it_down = col_walls[c].lower_bound(r);
            int down_wall = *it_down;
            if (down_wall >= 1 && down_wall <= H) {
                col_walls[c].insert(down_wall);
                row_walls[down_wall].insert(c);
                remaining--;
            }

            // Place the bomb (no wall here now)
            row_walls[r].insert(c);
            col_walls[c].insert(r);
            remaining--;
        }
    }

    cout << remaining << "\n";

    return 0;
}
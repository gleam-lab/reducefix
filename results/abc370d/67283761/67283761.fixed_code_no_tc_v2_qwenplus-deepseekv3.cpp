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

    vector<set<int>> row_walls(H + 2); // 1-based to H
    vector<set<int>> col_walls(W + 2); // 1-based to W

    // Initialize all walls as present
    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    int total_walls = H * W;
    int broken_walls = 0;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists, destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            broken_walls++;
        } else {
            // No wall, find first walls in each direction
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            --it_left;
            int left = *it_left;
            if (left >= 1 && row_walls[r].count(left)) {
                row_walls[r].erase(left);
                col_walls[left].erase(r);
                broken_walls++;
            }

            // Right
            auto it_right = row_walls[r].upper_bound(c);
            int right = *it_right;
            if (right <= W && row_walls[r].count(right)) {
                row_walls[r].erase(right);
                col_walls[right].erase(r);
                broken_walls++;
            }

            // Up
            auto it_up = col_walls[c].lower_bound(r);
            --it_up;
            int up = *it_up;
            if (up >= 1 && col_walls[c].count(up)) {
                col_walls[c].erase(up);
                row_walls[up].erase(c);
                broken_walls++;
            }

            // Down
            auto it_down = col_walls[c].upper_bound(r);
            int down = *it_down;
            if (down <= H && col_walls[c].count(down)) {
                col_walls[c].erase(down);
                row_walls[down].erase(c);
                broken_walls++;
            }
        }
    }

    cout << total_walls - broken_walls << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 2); // 1-based to H
    vector<set<int>> col_walls(W + 2); // 1-based to W

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining--;
        } else {
            // Check up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int wall_row = *it_up;
                row_walls[wall_row].erase(C);
                col_walls[C].erase(wall_row);
                remaining--;
            }

            // Check down
            auto it_down = col_walls[C].lower_bound(R);
            if (it_down != col_walls[C].end()) {
                int wall_row = *it_down;
                row_walls[wall_row].erase(C);
                col_walls[C].erase(wall_row);
                remaining--;
            }

            // Check left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int wall_col = *it_left;
                row_walls[R].erase(wall_col);
                col_walls[wall_col].erase(R);
                remaining--;
            }

            // Check right
            auto it_right = row_walls[R].lower_bound(C);
            if (it_right != row_walls[R].end()) {
                int wall_col = *it_right;
                row_walls[R].erase(wall_col);
                col_walls[wall_col].erase(R);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
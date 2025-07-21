#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H);
    vector<set<int>> col_walls(W);

    // Initialize all walls as present
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (row_walls[R].count(C)) {
            // Destroy the wall at (R, C)
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        } else {
            // Destroy the first walls in four directions
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int r = *it_up;
                row_walls[r].erase(C);
                col_walls[C].erase(r);
            }

            // Down
            auto it_down = col_walls[C].upper_bound(R);
            if (it_down != col_walls[C].end()) {
                int r = *it_down;
                row_walls[r].erase(C);
                col_walls[C].erase(r);
            }

            // Left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int c = *it_left;
                row_walls[R].erase(c);
                col_walls[c].erase(R);
            }

            // Right
            auto it_right = row_walls[R].upper_bound(C);
            if (it_right != row_walls[R].end()) {
                int c = *it_right;
                row_walls[R].erase(c);
                col_walls[c].erase(R);
            }
        }
    }

    int remaining = 0;
    for (int i = 0; i < H; ++i) {
        remaining += row_walls[i].size();
    }
    cout << remaining << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);

    long long remaining = (long long)H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (!row_walls[R].count(C)) {
            // Destroy the wall at (R, C)
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            remaining--;
        } else {
            // Find first walls in four directions
            // Up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                int r = *it_up;
                if (!row_walls[r].count(C)) {
                    row_walls[r].insert(C);
                    col_walls[C].insert(r);
                    remaining--;
                }
            }

            // Down
            auto it_down = col_walls[C].upper_bound(R);
            if (it_down != col_walls[C].end()) {
                int r = *it_down;
                if (!row_walls[r].count(C)) {
                    row_walls[r].insert(C);
                    col_walls[C].insert(r);
                    remaining--;
                }
            }

            // Left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                int c = *it_left;
                if (!col_walls[c].count(R)) {
                    col_walls[c].insert(R);
                    row_walls[R].insert(c);
                    remaining--;
                }
            }

            // Right
            auto it_right = row_walls[R].upper_bound(C);
            if (it_right != row_walls[R].end()) {
                int c = *it_right;
                if (!col_walls[c].count(R)) {
                    col_walls[c].insert(R);
                    row_walls[R].insert(c);
                    remaining--;
                }
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
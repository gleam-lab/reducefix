#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> wall(H + 2, vector<bool>(W + 2, true));
    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (wall[R][C]) {
            wall[R][C] = false;
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        } else {
            // Up
            auto it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].begin()) {
                --it;
                int r = *it;
                if (wall[r][C]) {
                    wall[r][C] = false;
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                }
            }

            // Down
            it = col_walls[C].lower_bound(R);
            if (it != col_walls[C].end()) {
                int r = *it;
                if (wall[r][C]) {
                    wall[r][C] = false;
                    row_walls[r].erase(C);
                    col_walls[C].erase(r);
                }
            }

            // Left
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].begin()) {
                --it;
                int c = *it;
                if (wall[R][c]) {
                    wall[R][c] = false;
                    row_walls[R].erase(c);
                    col_walls[c].erase(R);
                }
            }

            // Right
            it = row_walls[R].lower_bound(C);
            if (it != row_walls[R].end()) {
                int c = *it;
                if (wall[R][c]) {
                    wall[R][c] = false;
                    row_walls[R].erase(c);
                    col_walls[c].erase(R);
                }
            }
        }
    }

    int remaining = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (wall[i][j]) {
                ++remaining;
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
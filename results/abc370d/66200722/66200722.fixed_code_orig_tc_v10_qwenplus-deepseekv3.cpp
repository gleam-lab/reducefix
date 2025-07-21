#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);
    set<pair<int, int>> walls;

    for (int i = 1; i <= H; ++i) {
        row_walls[i].insert(0);
        row_walls[i].insert(W + 1);
    }
    for (int j = 1; j <= W; ++j) {
        col_walls[j].insert(0);
        col_walls[j].insert(H + 1);
    }

    long long remaining = (long long)H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (walls.count({R, C})) {
            walls.erase({R, C});
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining++;
        } else {
            walls.insert({R, C});
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            remaining--;
        }

        // Check up
        auto it = col_walls[C].lower_bound(R);
        if (*it != R) {
            int up = *prev(it);
            if (up >= 1 && !walls.count({up, C})) {
                walls.insert({up, C});
                row_walls[up].insert(C);
                col_walls[C].insert(up);
                remaining--;
            }
        }

        // Check down
        it = col_walls[C].upper_bound(R);
        if (*it != R) {
            int down = *it;
            if (down <= H && !walls.count({down, C})) {
                walls.insert({down, C});
                row_walls[down].insert(C);
                col_walls[C].insert(down);
                remaining--;
            }
        }

        // Check left
        it = row_walls[R].lower_bound(C);
        if (*it != C) {
            int left = *prev(it);
            if (left >= 1 && !walls.count({R, left})) {
                walls.insert({R, left});
                row_walls[R].insert(left);
                col_walls[left].insert(R);
                remaining--;
            }
        }

        // Check right
        it = row_walls[R].upper_bound(C);
        if (*it != C) {
            int right = *it;
            if (right <= W && !walls.count({R, right})) {
                walls.insert({R, right});
                row_walls[R].insert(right);
                col_walls[right].insert(R);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
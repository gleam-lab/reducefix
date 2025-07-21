#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H), col_walls(W);
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
        }
    }

    long long remaining = 1LL * H * W;

    auto destroy_wall = [&](int r, int c) {
        if (row_walls[r].find(c) == row_walls[r].end()) return false;
        row_walls[r].erase(c);
        col_walls[c].erase(r);
        --remaining;
        return true;
    };

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall at (R,C), destroy it
        if (destroy_wall(R, C)) continue;

        // Otherwise, destroy the first walls in each direction
        auto& cols_in_row = row_walls[R];
        if (!cols_in_row.empty()) {
            auto it = cols_in_row.lower_bound(C);
            if (it != cols_in_row.begin()) {
                --it;
                destroy_wall(R, *it);
            }
            it = cols_in_row.upper_bound(C);
            if (it != cols_in_row.end()) {
                destroy_wall(R, *it);
            }
        }

        auto& rows_in_col = col_walls[C];
        if (!rows_in_col.empty()) {
            auto it = rows_in_col.lower_bound(R);
            if (it != rows_in_col.begin()) {
                --it;
                destroy_wall(*it, C);
            }
            it = rows_in_col.upper_bound(R);
            if (it != rows_in_col.end()) {
                destroy_wall(*it, C);
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
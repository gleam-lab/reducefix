#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H), col_walls(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    long long total_remaining = (long long)H * W;

    auto destroy_wall = [&](int r, int c) {
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            total_remaining--;
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there's a wall here, destroy it directly
        if (row_walls[R].count(C)) {
            destroy_wall(R, C);
            continue;
        }

        // UP: look above for nearest wall in column C
        auto it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].begin()) {
            it--;
            destroy_wall(*it, C);
        }

        // DOWN: look below for nearest wall in column C
        it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].end()) {
            destroy_wall(*it, C);
        }

        // LEFT: look left in the same row
        it = row_walls[R].lower_bound(C);
        if (it != row_walls[R].begin()) {
            it--;
            destroy_wall(R, *it);
        }

        // RIGHT: look right in the same row
        it = row_walls[R].lower_bound(C);
        if (it != row_walls[R].end()) {
            destroy_wall(R, *it);
        }
    }

    cout << total_remaining << endl;
    return 0;
}
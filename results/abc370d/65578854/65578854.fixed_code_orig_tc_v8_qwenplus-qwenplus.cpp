#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_sets(H), col_sets(W);

    // Initialize all walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_sets[i].insert(j);
            col_sets[j].insert(i);
        }
    }

    long long total_walls = (long long)H * W;

    auto destroy_wall = [&](int r, int c) {
        row_sets[r].erase(c);
        col_sets[c].erase(r);
        total_walls--;
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // Check if there's a wall at current cell
        if (row_sets[R].count(C)) {
            destroy_wall(R, C);
            continue;
        }

        // Up
        auto it = col_sets[C].lower_bound(R);
        if (it != col_sets[C].begin()) {
            --it;
            if (*it < R) {
                destroy_wall(*it, C);
            }
        }

        // Down
        it = col_sets[C].lower_bound(R + 1);
        if (it != col_sets[C].end()) {
            if (*it > R) {
                destroy_wall(*it, C);
            }
        }

        // Left
        it = row_sets[R].lower_bound(C);
        if (it != row_sets[R].begin()) {
            --it;
            if (*it < C) {
                destroy_wall(R, *it);
            }
        }

        // Right
        it = row_sets[R].lower_bound(C + 1);
        if (it != row_sets[R].end()) {
            if (*it > C) {
                destroy_wall(R, *it);
            }
        }
    }

    cout << total_walls << '\n';
    return 0;
}
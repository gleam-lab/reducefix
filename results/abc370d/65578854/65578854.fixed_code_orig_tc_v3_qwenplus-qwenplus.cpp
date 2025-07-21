#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // Sets to track which columns have walls in each row
    vector<set<int>> row_walls(H);
    // Sets to track which rows have walls in each column
    vector<set<int>> col_walls(W);

    // Initialize all walls
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
        }
    }

    ll total_remaining = (ll)H * (ll)W;

    auto destroy_wall = [&](int r, int c) {
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            --total_remaining;
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        // If there is a wall here, destroy it
        if (row_walls[R].count(C)) {
            destroy_wall(R, C);
            continue;
        }

        // Otherwise, look in each direction and destroy first wall if exists

        // Up
        auto it = col_walls[C].lower_bound(R);
        if (it != col_walls[C].begin()) {
            --it;
            int r = *it;
            destroy_wall(r, C);
        }

        // Down
        it = col_walls[C].upper_bound(R);
        if (it != col_walls[C].end()) {
            int r = *it;
            destroy_wall(r, C);
        }

        // Left
        it = row_walls[R].lower_bound(C);
        if (it != row_walls[R].begin()) {
            --it;
            int c = *it;
            destroy_wall(R, c);
        }

        // Right
        it = row_walls[R].upper_bound(C);
        if (it != row_walls[R].end()) {
            int c = *it;
            destroy_wall(R, c);
        }
    }

    cout << total_remaining << '\n';

    return 0;
}
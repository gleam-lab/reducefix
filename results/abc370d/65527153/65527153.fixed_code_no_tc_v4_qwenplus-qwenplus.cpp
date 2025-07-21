#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    // row_walls[r]: ordered set of columns in row r that have walls
    vector<set<int>> row_walls(H + 1);
    // col_walls[c]: ordered set of rows in column c that have walls
    vector<set<int>> col_walls(W + 1);

    for (int r = 1; r <= H; ++r) {
        for (int c = 1; c <= W; ++c) {
            row_walls[r].insert(c);
            col_walls[c].insert(r);
        }
    }

    auto remove = [&](int r, int c) {
        row_walls[r].erase(c);
        col_walls[c].erase(r);
    };

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists at this cell, destroy it
            remove(r, c);
            continue;
        }

        // Otherwise, look in 4 directions and destroy the first wall in each direction

        // Left
        auto it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].begin()) {
            --it;
            remove(r, *it);
        }

        // Right
        it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].end()) {
            remove(r, *it);
        }

        // Up
        auto jt = col_walls[c].lower_bound(r);
        if (jt != col_walls[c].begin()) {
            --jt;
            remove(*jt, c);
        }

        // Down
        jt = col_walls[c].lower_bound(r);
        if (jt != col_walls[c].end()) {
            remove(*jt, c);
        }
    }

    // Count remaining walls
    ll ans = 0;
    for (int r = 1; r <= H; ++r) {
        ans += row_walls[r].size();
    }

    cout << ans << "\n";

    return 0;
}
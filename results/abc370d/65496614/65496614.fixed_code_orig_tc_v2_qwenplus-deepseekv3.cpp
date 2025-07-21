#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);

    // Initialize walls
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    int remaining = H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            // Wall exists at (r,c) - destroy it
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            remaining--;
            continue;
        }

        // Destroy first walls in all four directions
        // Left
        auto it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].begin()) {
            --it;
            int j = *it;
            row_walls[r].erase(j);
            col_walls[j].erase(r);
            remaining--;
        }

        // Right
        it = row_walls[r].lower_bound(c);
        if (it != row_walls[r].end()) {
            int j = *it;
            row_walls[r].erase(j);
            col_walls[j].erase(r);
            remaining--;
        }

        // Up
        it = col_walls[c].lower_bound(r);
        if (it != col_walls[c].begin()) {
            --it;
            int i = *it;
            col_walls[c].erase(i);
            row_walls[i].erase(c);
            remaining--;
        }

        // Down
        it = col_walls[c].lower_bound(r);
        if (it != col_walls[c].end()) {
            int i = *it;
            col_walls[c].erase(i);
            row_walls[i].erase(c);
            remaining--;
        }
    }

    cout << remaining << '\n';
    return 0;
}
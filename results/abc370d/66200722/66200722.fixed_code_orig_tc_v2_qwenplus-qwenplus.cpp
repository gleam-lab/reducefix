#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> grid(H, vector<int>(W, 1)); // All walls are initially present (1 means wall exists)

    // For each row, store the positions of existing walls in sorted order
    vector<set<int>> row(W), col(H);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    auto destroy = [&](int r, int c) {
        if (grid[r][c] == 0) {
            // Look up
            auto it = col[r].lower_bound(c);
            if (it != col[r].begin()) {
                --it;
                int x = *it;
                col[r].erase(it);
                row[x].erase(r);
                grid[r][x] = 0;
            }

            // Look down
            it = col[r].upper_bound(c);
            if (it != col[r].end()) {
                int x = *it;
                col[r].erase(it);
                row[x].erase(r);
                grid[r][x] = 0;
            }

            // Look left
            it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                --it;
                int y = *it;
                row[c].erase(it);
                col[y].erase(c);
                grid[y][c] = 0;
            }

            // Look right
            it = row[c].upper_bound(r);
            if (it != row[c].end()) {
                int y = *it;
                row[c].erase(it);
                col[y].erase(c);
                grid[y][c] = 0;
            }
        } else {
            // Destroy the bomb's wall
            grid[r][c] = 0;
            col[r].erase(c);
            row[c].erase(r);
        }
    };

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        destroy(R, C);
    }

    int remaining = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remaining += grid[i][j];
        }
    }

    cout << remaining << endl;

    return 0;
}
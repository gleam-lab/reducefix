#include <bits/stdc++.h>
using namespace std;

void solve() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> row_walls(H + 1); // 1-based indexing
    vector<set<int>> col_walls(W + 1); // 1-based indexing
    for (int r = 1; r <= H; ++r) {
        row_walls[r].insert(0); // Sentinel
        row_walls[r].insert(W + 1); // Sentinel
    }
    for (int c = 1; c <= W; ++c) {
        col_walls[c].insert(0); // Sentinel
        col_walls[c].insert(H + 1); // Sentinel
    }
    long long total_walls = (long long)H * W;
    while (Q--) {
        int R, C;
        cin >> R >> C;
        if (row_walls[R].count(C)) {
            // Wall already destroyed, find nearest walls in four directions
            // Up
            auto it_up = col_walls[C].upper_bound(R);
            int up = *it_up;
            if (up != H + 1) {
                if (!row_walls[up].count(C)) {
                    row_walls[up].insert(C);
                    col_walls[C].insert(up);
                    total_walls--;
                }
            }
            // Down
            it_up = col_walls[C].lower_bound(R);
            --it_up;
            int down = *it_up;
            if (down != 0) {
                if (!row_walls[down].count(C)) {
                    row_walls[down].insert(C);
                    col_walls[C].insert(down);
                    total_walls--;
                }
            }
            // Left
            auto it_left = row_walls[R].lower_bound(C);
            --it_left;
            int left = *it_left;
            if (left != 0) {
                if (!col_walls[left].count(R)) {
                    col_walls[left].insert(R);
                    row_walls[R].insert(left);
                    total_walls--;
                }
            }
            // Right
            it_left = row_walls[R].upper_bound(C);
            int right = *it_left;
            if (right != W + 1) {
                if (!col_walls[right].count(R)) {
                    col_walls[right].insert(R);
                    row_walls[R].insert(right);
                    total_walls--;
                }
            }
        } else {
            // Destroy the wall at (R, C)
            row_walls[R].insert(C);
            col_walls[C].insert(R);
            total_walls--;
        }
    }
    cout << total_walls << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
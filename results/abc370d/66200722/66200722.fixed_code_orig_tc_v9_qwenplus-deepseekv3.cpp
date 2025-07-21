#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);  // 1-based rows
    vector<set<int>> col_walls(W + 1);  // 1-based columns
    for (int r = 1; r <= H; ++r) {
        row_walls[r].insert(0);
        row_walls[r].insert(W + 1);
    }
    for (int c = 1; c <= W; ++c) {
        col_walls[c].insert(0);
        col_walls[c].insert(H + 1);
    }

    long long remaining = (long long)H * W;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
            remaining--;
        } else {
            // Up
            auto it = col_walls[C].lower_bound(R);
            --it;
            int up = *it;
            if (up >= 1 && !row_walls[up].count(C)) {
                row_walls[up].insert(C);
                col_walls[C].insert(up);
                remaining--;
            }

            // Down
            it = col_walls[C].upper_bound(R);
            int down = *it;
            if (down <= H && !row_walls[down].count(C)) {
                row_walls[down].insert(C);
                col_walls[C].insert(down);
                remaining--;
            }

            // Left
            it = row_walls[R].lower_bound(C);
            --it;
            int left = *it;
            if (left >= 1 && !col_walls[left].count(R)) {
                col_walls[left].insert(R);
                row_walls[R].insert(left);
                remaining--;
            }

            // Right
            it = row_walls[R].upper_bound(C);
            int right = *it;
            if (right <= W && !col_walls[right].count(R)) {
                col_walls[right].insert(R);
                row_walls[R].insert(right);
                remaining--;
            }
        }
    }

    cout << remaining << '\n';

    return 0;
}
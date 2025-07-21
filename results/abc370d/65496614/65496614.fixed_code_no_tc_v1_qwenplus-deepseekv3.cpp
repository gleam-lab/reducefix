#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H + 2);  // Rows 1..H, columns 1..W
    vector<set<int>> col(W + 2);  // Columns 1..W, rows 1..H

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    vector<vector<bool>> has_wall(H + 2, vector<bool>(W + 2, true));

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (has_wall[R][C]) {
            has_wall[R][C] = false;
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // Find the first wall in each direction
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                int i = *it_up;
                if (has_wall[i][C]) {
                    has_wall[i][C] = false;
                    row[i].erase(C);
                    col[C].erase(i);
                }
            }
            // Down
            auto it_down = col[C].upper_bound(R);
            if (it_down != col[C].end()) {
                int i = *it_down;
                if (has_wall[i][C]) {
                    has_wall[i][C] = false;
                    row[i].erase(C);
                    col[C].erase(i);
                }
            }
            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                int j = *it_left;
                if (has_wall[R][j]) {
                    has_wall[R][j] = false;
                    row[R].erase(j);
                    col[j].erase(R);
                }
            }
            // Right
            auto it_right = row[R].upper_bound(C);
            if (it_right != row[R].end()) {
                int j = *it_right;
                if (has_wall[R][j]) {
                    has_wall[R][j] = false;
                    row[R].erase(j);
                    col[j].erase(R);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (has_wall[i][j]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
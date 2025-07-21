#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> walls(H + 2, vector<bool>(W + 2, true));
    vector<set<int>> row_walls(H + 2);
    vector<set<int>> col_walls(W + 2);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (walls[r][c]) {
            walls[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int i = *it_up;
                if (walls[i][c]) {
                    walls[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                }
            }

            // Down
            auto it_down = col_walls[c].upper_bound(r);
            if (it_down != col_walls[c].end()) {
                int i = *it_down;
                if (walls[i][c]) {
                    walls[i][c] = false;
                    row_walls[i].erase(c);
                    col_walls[c].erase(i);
                }
            }

            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int j = *it_left;
                if (walls[r][j]) {
                    walls[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                }
            }

            // Right
            auto it_right = row_walls[r].upper_bound(c);
            if (it_right != row_walls[r].end()) {
                int j = *it_right;
                if (walls[r][j]) {
                    walls[r][j] = false;
                    row_walls[r].erase(j);
                    col_walls[j].erase(r);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            ans += walls[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
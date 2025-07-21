#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(H + 2);
    vector<set<int>> col(W + 2);
    vector<vector<bool>> wall(H + 2, vector<bool>(W + 2, true));

    // Initialize sets for rows and columns
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (wall[R][C]) {
            // Destroy the wall at (R, C)
            wall[R][C] = false;
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // Destroy the first walls in each direction
            // Left
            auto it_left = row[R].lower_bound(C);
            if (it_left != row[R].begin()) {
                --it_left;
                int j = *it_left;
                wall[R][j] = false;
                row[R].erase(j);
                col[j].erase(R);
            }
            // Right
            auto it_right = row[R].lower_bound(C);
            if (it_right != row[R].end()) {
                int j = *it_right;
                wall[R][j] = false;
                row[R].erase(j);
                col[j].erase(R);
            }
            // Up
            auto it_up = col[C].lower_bound(R);
            if (it_up != col[C].begin()) {
                --it_up;
                int i = *it_up;
                wall[i][C] = false;
                row[i].erase(C);
                col[C].erase(i);
            }
            // Down
            auto it_down = col[C].lower_bound(R);
            if (it_down != col[C].end()) {
                int i = *it_down;
                wall[i][C] = false;
                row[i].erase(C);
                col[C].erase(i);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            ans += wall[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}
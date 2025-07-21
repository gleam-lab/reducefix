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
        int R, C;
        cin >> R >> C;

        if (walls[R][C]) {
            walls[R][C] = false;
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        } else {
            // Find the first wall above
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                walls[*it_up][C] = false;
                row_walls[*it_up].erase(C);
                col_walls[C].erase(it_up);
            }

            // Find the first wall below
            it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].end()) {
                walls[*it_up][C] = false;
                row_walls[*it_up].erase(C);
                col_walls[C].erase(it_up);
            }

            // Find the first wall to the left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                walls[R][*it_left] = false;
                col_walls[*it_left].erase(R);
                row_walls[R].erase(it_left);
            }

            // Find the first wall to the right
            it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].end()) {
                walls[R][*it_left] = false;
                col_walls[*it_left].erase(R);
                row_walls[R].erase(it_left);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            ans += walls[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}
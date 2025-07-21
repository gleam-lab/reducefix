#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row_walls(H + 1);
    vector<set<int>> col_walls(W + 1);

    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (row_walls[R].count(C)) {
            row_walls[R].erase(C);
            col_walls[C].erase(R);
        } else {
            // Look up
            auto it_up = col_walls[C].lower_bound(R);
            if (it_up != col_walls[C].begin()) {
                --it_up;
                row_walls[*it_up].erase(C);
                col_walls[C].erase(it_up);
            }

            // Look down
            auto it_down = col_walls[C].lower_bound(R);
            if (it_down != col_walls[C].end()) {
                row_walls[*it_down].erase(C);
                col_walls[C].erase(it_down);
            }

            // Look left
            auto it_left = row_walls[R].lower_bound(C);
            if (it_left != row_walls[R].begin()) {
                --it_left;
                col_walls[*it_left].erase(R);
                row_walls[R].erase(it_left);
            }

            // Look right
            auto it_right = row_walls[R].lower_bound(C);
            if (it_right != row_walls[R].end()) {
                col_walls[*it_right].erase(R);
                row_walls[R].erase(it_right);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= H; ++i) {
        ans += row_walls[i].size();
    }
    cout << ans << "\n";

    return 0;
}
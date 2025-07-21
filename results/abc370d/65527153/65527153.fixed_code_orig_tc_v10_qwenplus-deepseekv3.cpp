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

    long long ans = (long long)H * W;
    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Check up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                int wall_r = *it;
                if (row_walls[wall_r].count(c)) {
                    row_walls[wall_r].erase(c);
                    col_walls[c].erase(wall_r);
                    ans--;
                }
            }

            // Check down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                int wall_r = *it;
                if (row_walls[wall_r].count(c)) {
                    row_walls[wall_r].erase(c);
                    col_walls[c].erase(wall_r);
                    ans--;
                }
            }

            // Check left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                int wall_c = *it;
                if (col_walls[wall_c].count(r)) {
                    col_walls[wall_c].erase(r);
                    row_walls[r].erase(wall_c);
                    ans--;
                }
            }

            // Check right
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) {
                int wall_c = *it;
                if (col_walls[wall_c].count(r)) {
                    col_walls[wall_c].erase(r);
                    row_walls[r].erase(wall_c);
                    ans--;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
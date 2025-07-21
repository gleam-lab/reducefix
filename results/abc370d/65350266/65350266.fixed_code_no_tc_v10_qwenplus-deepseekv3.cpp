#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);

    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }

    int ans = h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        bool has_wall = row_walls[r].count(c);
        if (has_wall) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                it_up--;
                int up_row = *it_up;
                row_walls[up_row].erase(c);
                col_walls[c].erase(up_row);
                ans--;
            }
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int down_row = *it_down;
                row_walls[down_row].erase(c);
                col_walls[c].erase(down_row);
                ans--;
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int left_col = *it_left;
                row_walls[r].erase(left_col);
                col_walls[left_col].erase(r);
                ans--;
            }
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int right_col = *it_right;
                row_walls[r].erase(right_col);
                col_walls[right_col].erase(r);
                ans--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
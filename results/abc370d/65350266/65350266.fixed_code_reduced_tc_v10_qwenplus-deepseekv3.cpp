#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Check up direction
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                --it_up;
                int row = *it_up;
                row_walls[row].erase(c);
                col_walls[c].erase(row);
            }

            // Check down direction
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int row = *it_down;
                row_walls[row].erase(c);
                col_walls[c].erase(row);
            }

            // Check left direction
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                --it_left;
                int col = *it_left;
                row_walls[r].erase(col);
                col_walls[col].erase(r);
            }

            // Check right direction
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int col = *it_right;
                row_walls[r].erase(col);
                col_walls[col].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, h) ans += row_walls[i].size();
    cout << ans << endl;
    return 0;
}
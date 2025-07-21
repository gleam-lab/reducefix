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
    ll total_walls = (ll)h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            total_walls--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                it_up--;
                int wall_r = *it_up;
                row_walls[wall_r].erase(c);
                col_walls[c].erase(wall_r);
                total_walls--;
            }
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int wall_r = *it_down;
                row_walls[wall_r].erase(c);
                col_walls[c].erase(wall_r);
                total_walls--;
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int wall_c = *it_left;
                row_walls[r].erase(wall_c);
                col_walls[wall_c].erase(r);
                total_walls--;
            }
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int wall_c = *it_right;
                row_walls[r].erase(wall_c);
                col_walls[wall_c].erase(r);
                total_walls--;
            }
        }
    }
    cout << total_walls << "\n";
    return 0;
}
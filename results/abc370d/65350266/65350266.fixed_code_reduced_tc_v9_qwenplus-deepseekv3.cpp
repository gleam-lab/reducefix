#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }
    int total_walls = h * w;
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
                int up_pos = *it_up;
                row_walls[up_pos].erase(c);
                col_walls[c].erase(up_pos);
                total_walls--;
            }
            // Down
            auto it_down = col_walls[c].lower_bound(r);
            if (it_down != col_walls[c].end()) {
                int down_pos = *it_down;
                row_walls[down_pos].erase(c);
                col_walls[c].erase(down_pos);
                total_walls--;
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                it_left--;
                int left_pos = *it_left;
                row_walls[r].erase(left_pos);
                col_walls[left_pos].erase(r);
                total_walls--;
            }
            // Right
            auto it_right = row_walls[r].lower_bound(c);
            if (it_right != row_walls[r].end()) {
                int right_pos = *it_right;
                row_walls[r].erase(right_pos);
                col_walls[right_pos].erase(r);
                total_walls--;
            }
        }
    }
    cout << total_walls << "\n";
    return 0;
}
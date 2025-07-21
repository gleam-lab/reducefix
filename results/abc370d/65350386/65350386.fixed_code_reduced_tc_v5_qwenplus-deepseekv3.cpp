#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_walls(h), col_walls(w);
    
    // Initialize all walls
    rep(i, h) rep(j, w) {
        row_walls[i].insert(j);
        col_walls[j].insert(i);
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].count(c)) {
            // Direct hit - remove this wall
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Find first wall in each direction
            
            // Up
            auto up_it = col_walls[c].lower_bound(r);
            if (up_it != col_walls[c].begin()) {
                up_it--;
                int target_r = *up_it;
                row_walls[target_r].erase(c);
                col_walls[c].erase(target_r);
            }

            // Down
            auto down_it = col_walls[c].lower_bound(r);
            if (down_it != col_walls[c].end()) {
                int target_r = *down_it;
                row_walls[target_r].erase(c);
                col_walls[c].erase(target_r);
            }

            // Left
            auto left_it = row_walls[r].lower_bound(c);
            if (left_it != row_walls[r].begin()) {
                left_it--;
                int target_c = *left_it;
                row_walls[r].erase(target_c);
                col_walls[target_c].erase(r);
            }

            // Right
            auto right_it = row_walls[r].lower_bound(c);
            if (right_it != row_walls[r].end()) {
                int target_c = *right_it;
                row_walls[r].erase(target_c);
                col_walls[target_c].erase(r);
            }
        }
    }

    int ans = 0;
    rep(i, h) ans += row_walls[i].size();
    cout << ans << "\n";
    return 0;
}
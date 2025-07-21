#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row and column, maintain the set of positions where walls exist
    vector<set<int>> tate(w), yoko(h);
    rep(i,h) rep(j,w) {
        tate[j].insert(i);
        yoko[i].insert(j);
    }

    rep(qi,q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Case: bomb at cell with a wall
        if (tate[c].count(r)) {
            tate[c].erase(r);
            yoko[r].erase(c);
        } 
        // Case: bomb at empty cell -> destroy first walls in 4 directions
        else {
            // Up
            auto it_up = tate[c].lower_bound(r);
            if (it_up != tate[c].begin()) {
                it_up--;
                int up_row = *it_up;
                tate[c].erase(up_row);
                yoko[up_row].erase(c);
            }

            // Down
            auto it_down = tate[c].lower_bound(r);
            if (it_down != tate[c].end()) {
                int down_row = *it_down;
                tate[c].erase(down_row);
                yoko[down_row].erase(c);
            }

            // Left
            auto it_left = yoko[r].lower_bound(c);
            if (it_left != yoko[r].begin()) {
                it_left--;
                int left_col = *it_left;
                yoko[r].erase(left_col);
                tate[left_col].erase(r);
            }

            // Right
            auto it_right = yoko[r].lower_bound(c);
            if (it_right != yoko[r].end()) {
                int right_col = *it_right;
                yoko[r].erase(right_col);
                tate[right_col].erase(r);
            }
        }
    }

    int ans = 0;
    for (auto &col : tate) {
        ans += col.size();
    }
    cout << ans << "\n";
    return 0;
}
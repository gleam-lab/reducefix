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
    int ans = h * w;
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Up direction
            auto up_it = col_walls[c].lower_bound(r);
            if (up_it != col_walls[c].begin()) {
                up_it--;
                int up_r = *up_it;
                if (row_walls[up_r].count(c)) {
                    row_walls[up_r].erase(c);
                    col_walls[c].erase(up_r);
                    ans--;
                }
            }
            // Down direction
            auto down_it = col_walls[c].lower_bound(r);
            if (down_it != col_walls[c].end()) {
                int down_r = *down_it;
                if (row_walls[down_r].count(c)) {
                    row_walls[down_r].erase(c);
                    col_walls[c].erase(down_r);
                    ans--;
                }
            }
            // Left direction
            auto left_it = row_walls[r].lower_bound(c);
            if (left_it != row_walls[r].begin()) {
                left_it--;
                int left_c = *left_it;
                if (col_walls[left_c].count(r)) {
                    col_walls[left_c].erase(r);
                    row_walls[r].erase(left_c);
                    ans--;
                }
            }
            // Right direction
            auto right_it = row_walls[r].lower_bound(c);
            if (right_it != row_walls[r].end()) {
                int right_c = *right_it;
                if (col_walls[right_c].count(r)) {
                    col_walls[right_c].erase(r);
                    row_walls[r].erase(right_c);
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
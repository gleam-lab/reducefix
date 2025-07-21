#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
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

    ll ans = (ll)h * w;

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row_walls[r].count(c)) {
            row_walls[r].erase(c);
            col_walls[c].erase(r);
            ans--;
        } else {
            // Up
            auto it_up = col_walls[c].lower_bound(r);
            if (it_up != col_walls[c].begin()) {
                int target = *prev(it_up);
                row_walls[target].erase(c);
                col_walls[c].erase(target);
                ans--;
            }
            // Down
            auto it_down = col_walls[c].upper_bound(r);
            if (it_down != col_walls[c].end()) {
                int target = *it_down;
                row_walls[target].erase(c);
                col_walls[c].erase(target);
                ans--;
            }
            // Left
            auto it_left = row_walls[r].lower_bound(c);
            if (it_left != row_walls[r].begin()) {
                int target = *prev(it_left);
                col_walls[target].erase(r);
                row_walls[r].erase(target);
                ans--;
            }
            // Right
            auto it_right = row_walls[r].upper_bound(c);
            if (it_right != row_walls[r].end()) {
                int target = *it_right;
                col_walls[target].erase(r);
                row_walls[r].erase(target);
                ans--;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
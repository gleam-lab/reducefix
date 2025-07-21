#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row_left(w), row_right(w), col_up(h), col_down(h);
    
    // Initialize each set with all column/row indices
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_left[i].insert(j);
            row_right[i].insert(j);
            col_up[j].insert(i);
            col_down[j].insert(i);
        }
    }

    auto remove_wall = [&](int r, int c) {
        if (row_left[r].count(c)) {
            row_left[r].erase(c);
            row_right[r].erase(c);
            col_up[c].erase(r);
            col_down[c].erase(r);
            return true;
        }
        return false;
    };

    auto destroy_first_wall = [&](int r, int c) {
        // Look left
        auto it = row_left[r].lower_bound(c);
        if (it != row_left[r].begin()) {
            --it;
            int l = *it;
            row_left[r].erase(l);
            row_right[r].erase(l);
            col_up[l].erase(r);
            col_down[l].erase(r);
        }

        // Look right
        it = row_right[r].upper_bound(c);
        if (it != row_right[r].end()) {
            int rgt = *it;
            row_left[r].erase(rgt);
            row_right[r].erase(rgt);
            col_up[rgt].erase(r);
            col_down[rgt].erase(r);
        }

        // Look up
        it = col_up[c].lower_bound(r);
        if (it != col_up[c].begin()) {
            --it;
            int u = *it;
            row_left[u].erase(c);
            row_right[u].erase(c);
            col_up[c].erase(u);
            col_down[c].erase(u);
        }

        // Look down
        it = col_down[c].upper_bound(r);
        if (it != col_down[c].end()) {
            int d = *it;
            row_left[d].erase(c);
            row_right[d].erase(c);
            col_up[c].erase(d);
            col_down[c].erase(d);
        }
    };

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (!remove_wall(r, c)) {
            destroy_first_wall(r, c);
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_left[i].size();
    }

    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> rows(h), cols(w);

    // Initialize all columns in each row and rows in each column
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if the cell has a wall
        if (rows[r].count(c)) {
            // Remove the wall at (r,c)
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                int ur = *prev(it);
                rows[ur].erase(c);
                cols[c].erase(ur);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int dr = *it;
                rows[dr].erase(c);
                cols[c].erase(dr);
            }

            // Left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                int lc = *prev(it);
                cols[lc].erase(r);
                rows[r].erase(lc);
            }

            // Right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int rc = *it;
                cols[rc].erase(r);
                rows[r].erase(rc);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}
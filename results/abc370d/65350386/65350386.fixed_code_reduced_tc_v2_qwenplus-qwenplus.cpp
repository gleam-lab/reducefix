#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Data structures to track walls in rows and columns
    vector<set<int>> row(h), col(w);
    
    // Initialize all positions as having walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            // Wall exists at the position: destroy it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Look up
            auto u = col[c].lower_bound(r);
            if (u != col[c].begin()) {
                u--;
                int ur = *u;
                col[c].erase(ur);
                row[ur].erase(c);
            }

            // Look down
            auto d = col[c].lower_bound(r);
            if (d != col[c].end()) {
                int dr = *d;
                col[c].erase(dr);
                row[dr].erase(c);
            }

            // Look left
            auto l = row[r].lower_bound(c);
            if (l != row[r].begin()) {
                l--;
                int lc = *l;
                row[r].erase(lc);
                col[lc].erase(r);
            }

            // Look right
            auto ri = row[r].lower_bound(c);
            if (ri != row[r].end()) {
                int rc = *ri;
                row[r].erase(rc);
                col[rc].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i)
        ans += row[i].size();
    cout << ans << endl;

    return 0;
}
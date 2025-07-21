#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row(w), col(h);

    // Initialize each cell having a wall
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row[j].insert(i);
            col[i].insert(j);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at (r,c)
        if (row[c].count(r)) {
            // Directly destroy the wall at (r,c)
            row[c].erase(r);
            col[r].erase(c);
        } else {
            // Destroy the first walls in up, down, left, right

            // Up direction
            auto it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                --it;
                int u = *it;
                row[c].erase(it);
                col[u].erase(c);
            }

            // Down direction
            it = row[c].lower_bound(r);
            if (it != row[c].end()) {
                int d = *it;
                row[c].erase(it);
                col[d].erase(c);
            }

            // Left direction
            auto jt = col[r].lower_bound(c);
            if (jt != col[r].begin()) {
                --jt;
                int l = *jt;
                col[r].erase(jt);
                row[l].erase(r);
            }

            // Right direction
            jt = col[r].lower_bound(c);
            if (jt != col[r].end()) {
                int ri = *jt;
                col[r].erase(jt);
                row[ri].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";

    return 0;
}
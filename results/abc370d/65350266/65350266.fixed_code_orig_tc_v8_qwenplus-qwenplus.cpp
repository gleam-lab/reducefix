#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> row(w), col(h);
    
    // Initialize each row and column with all positions having walls
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

        // Check if there is a wall at (r, c)
        if (row[c].count(r)) {
            // Destroy the wall at (r, c)
            row[c].erase(r);
            col[r].erase(c);
        } else {
            // Up
            auto it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                it--;
                int u = *it;
                row[c].erase(u);
                col[r].erase(u);
            }

            // Down
            it = row[c].upper_bound(r);
            if (it != row[c].end()) {
                int d = *it;
                row[c].erase(d);
                col[r].erase(d);
            }

            // Left
            it = col[r].lower_bound(c);
            if (it != col[r].begin()) {
                it--;
                int l = *it;
                col[r].erase(l);
                row[l].erase(r);
            }

            // Right
            it = col[r].upper_bound(c);
            if (it != col[r].end()) {
                int ri = *it;
                col[r].erase(ri);
                row[ri].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += row[i].size();
    }
    cout << ans << "\n";
    return 0;
}
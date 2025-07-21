#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Each row and column's wall positions are maintained in ordered sets
    vector<set<int>> rows(h), cols(w);

    // Initialize all walls
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

        // If there's a wall at (r,c)
        if (rows[r].count(c)) {
            // Destroy the wall
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Otherwise, destroy first walls in four directions

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int y = *it;
                rows[y].erase(c);
                cols[c].erase(y);
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                int y = *it;
                rows[y].erase(c);
                cols[c].erase(y);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                jt--;
                int x = *jt;
                cols[x].erase(r);
                rows[r].erase(x);
            }

            // Right
            jt = rows[r].upper_bound(c);
            if (jt != rows[r].end()) {
                int x = *jt;
                cols[x].erase(r);
                rows[r].erase(x);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < w; ++i) {
        ans += cols[i].size();
    }
    cout << ans << endl;

    return 0;
}
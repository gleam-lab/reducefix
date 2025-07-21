#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define pb push_back

int main() {
    ll h, w, q;
    cin >> h >> w >> q;

    // For each row and column, maintain the set of columns/rows that still have walls
    vector<set<int>> rows(h), cols(w);

    // Initialize all cells to have a wall
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        // Check if there's a wall at (r, c)
        if(rows[r].count(c)) {
            // Bomb hits directly: destroy this wall
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Bomb explodes: find first walls in four directions
            vector<pair<int, int>> to_destroy;

            // Right on the same row
            auto it = rows[r].upper_bound(c);
            if(it != rows[r].end()) {
                to_destroy.emplace_back(r, *it);
            }

            // Left on the same row
            it = rows[r].lower_bound(c);
            if(it != rows[r].begin()) {
                --it;
                to_destroy.emplace_back(r, *it);
            }

            // Down on the same column
            auto jt = cols[c].upper_bound(r);
            if(jt != cols[c].end()) {
                to_destroy.emplace_back(*jt, c);
            }

            // Up on the same column
            jt = cols[c].lower_bound(r);
            if(jt != cols[c].begin()) {
                --jt;
                to_destroy.emplace_back(*jt, c);
            }

            // Remove all found walls
            for(auto [x, y] : to_destroy) {
                rows[x].erase(y);
                cols[y].erase(x);
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    for(int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, q;
    cin >> h >> w >> q;

    // Each row and column stores the set of columns/rows with remaining walls
    vector<set<ll>> rows(h), cols(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at (r,c)
        if (rows[r].count(c)) {
            // Destroy the wall at (r,c)
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Find the nearest walls in all four directions
            vector<pair<ll, ll>> destroy;

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                destroy.push_back({*it, c});
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                destroy.push_back({*it, c});
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                destroy.push_back({r, *jt});
            }

            // Right
            jt = rows[r].upper_bound(c);
            if (jt != rows[r].end()) {
                destroy.push_back({r, *jt});
            }

            // Remove those walls
            for (auto [x, y] : destroy) {
                rows[x].erase(y);
                cols[y].erase(x);
            }
        }
    }

    // Count remaining walls
    ll total = 0;
    for (ll i = 0; i < h; ++i) {
        total += rows[i].size();
    }
    cout << total << '\n';

    return 0;
}
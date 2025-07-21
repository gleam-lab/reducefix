#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, h) for (ll i = 0; i < (ll)(h); i++)

int main() {
    ll h, w, q;
    cin >> h >> w >> q;

    vector<set<ll>> rows(h), cols(w);

    // Initialize each row and column with all wall positions
    rep(i, h) {
        rep(j, w) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    rep(queries, q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        // If there's a wall at (r, c)
        if (rows[r].find(c) != rows[r].end()) {
            rows[r].erase(c);
            cols[c].erase(r);
            continue;
        }

        // Otherwise, find the first walls in each direction
        vector<pair<ll, ll>> to_destroy;

        // Right
        if (rows[r].upper_bound(c) != rows[r].end()) {
            to_destroy.emplace_back(r, *rows[r].upper_bound(c));
        }

        // Left
        if (rows[r].lower_bound(c) != rows[r].begin()) {
            auto it = prev(rows[r].lower_bound(c));
            if (it != rows[r].end()) {
                to_destroy.emplace_back(r, *it);
            }
        }

        // Down
        if (cols[c].upper_bound(r) != cols[c].end()) {
            to_destroy.emplace_back(*cols[c].upper_bound(r), c);
        }

        // Up
        if (cols[c].lower_bound(r) != cols[c].begin()) {
            auto it = prev(cols[c].lower_bound(r));
            if (it != cols[c].end()) {
                to_destroy.emplace_back(*it, c);
            }
        }

        // Remove the found walls
        for (auto [x, y] : to_destroy) {
            rows[x].erase(y);
            cols[y].erase(x);
        }
    }

    // Count remaining walls
    ll ans = 0;
    rep(i, h) ans += rows[i].size();
    cout << ans << endl;

    return 0;
}
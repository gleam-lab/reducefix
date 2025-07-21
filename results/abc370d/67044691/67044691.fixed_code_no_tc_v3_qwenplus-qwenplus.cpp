#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, q;
    cin >> h >> w >> q;

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

        if (rows[r].count(c)) {
            // Wall exists at (r, c), destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in four directions for first existing walls
            vector<pair<ll, ll>> to_destroy;

            // Right (increasing column)
            auto right = rows[r].upper_bound(c);
            if (right != rows[r].end()) {
                to_destroy.emplace_back(r, *right);
            }

            // Left (decreasing column)
            if (right != rows[r].begin()) {
                if (right == rows[r].end()) right = rows[r].end();
                --right;
                if (*right < c) {
                    to_destroy.emplace_back(r, *right);
                }
            }

            // Down (increasing row)
            auto down = cols[c].upper_bound(r);
            if (down != cols[c].end()) {
                to_destroy.emplace_back(*down, c);
            }

            // Up (decreasing row)
            if (down != cols[c].begin()) {
                --down;
                if (*down < r && *down >= 0) {
                    to_destroy.emplace_back(*down, c);
                }
            }

            // Destroy found walls
            for (auto [x, y] : to_destroy) {
                rows[x].erase(y);
                cols[y].erase(x);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q;
    cin >> h >> w >> q;

    vector<set<ll>> rows(h), cols(w);

    // Initialize each cell to have a wall
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

        // Check if there's a wall at (r, c)
        if (rows[r].count(c)) {
            // Destroy the wall at (r, c)
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Up direction
            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                ll x = *up;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Down direction
            auto down = cols[c].upper_bound(r);
            if (down != cols[c].end()) {
                ll x = *down;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Left direction
            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                ll y = *left;
                rows[r].erase(y);
                cols[y].erase(r);
            }

            // Right direction
            auto right = rows[r].upper_bound(c);
            if (right != rows[r].end()) {
                ll y = *right;
                rows[r].erase(y);
                cols[y].erase(r);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += rows[i].size();
    }

    cout << ans << endl;
}
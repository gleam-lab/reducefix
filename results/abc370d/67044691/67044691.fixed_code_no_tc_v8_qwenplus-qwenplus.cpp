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

        if (rows[r].find(c) != rows[r].end()) {
            // Bomb placed on a wall: remove it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Bomb destroys one wall in each direction
            // Right
            auto right = rows[r].upper_bound(c);
            if (right != rows[r].end()) {
                ll j = *right;
                rows[r].erase(j);
                cols[j].erase(r);
            }

            // Left
            auto left = rows[r].lower_bound(c);
            if (left != rows[r].begin()) {
                --left;
                ll j = *left;
                rows[r].erase(j);
                cols[j].erase(r);
            }

            // Down
            auto down = cols[c].upper_bound(r);
            if (down != cols[c].end()) {
                ll i = *down;
                cols[c].erase(i);
                rows[i].erase(c);
            }

            // Up
            auto up = cols[c].lower_bound(r);
            if (up != cols[c].begin()) {
                --up;
                ll i = *up;
                cols[c].erase(i);
                rows[i].erase(c);
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
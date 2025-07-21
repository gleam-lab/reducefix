#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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
        --r; --c;

        if (rows[r].count(c)) {
            // Wall exists here, destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in four directions: Up, Down, Left, Right
            vector<pair<ll, ll>> to_destroy;

            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                --it_up;
                to_destroy.push_back({*it_up, c});
            }

            // Down
            auto it_down = cols[c].upper_bound(r);
            if (it_down != cols[c].end()) {
                to_destroy.push_back({*it_down, c});
            }

            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                --it_left;
                to_destroy.push_back({r, *it_left});
            }

            // Right
            auto it_right = rows[r].upper_bound(c);
            if (it_right != rows[r].end()) {
                to_destroy.push_back({r, *it_right});
            }

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
    cout << ans << "\n";
}
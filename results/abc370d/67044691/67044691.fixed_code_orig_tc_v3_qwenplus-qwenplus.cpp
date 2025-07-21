#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q;
    cin >> h >> w >> q;

    vector<set<ll>> rows(h), cols(w);

    // Initialize all cells with walls
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
            // Wall exists at this cell, destroy it
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Look in four directions and destroy first wall seen in each direction
            vector<pair<ll, ll>> to_destroy;

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                to_destroy.emplace_back(*it, c);
                cols[c].erase(it);
            }

            // Down
            it = cols[c].upper_bound(r);
            if (it != cols[c].end()) {
                to_destroy.emplace_back(*it, c);
                cols[c].erase(it);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                to_destroy.emplace_back(r, *jt);
                rows[r].erase(jt);
            }

            // Right
            jt = rows[r].upper_bound(c);
            if (jt != rows[r].end()) {
                to_destroy.emplace_back(r, *jt);
                rows[r].erase(jt);
            }

            // Remove destroyed walls from their respective column sets
            for (const auto& [x, y] : to_destroy) {
                if (x != r) cols[y].erase(x);
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
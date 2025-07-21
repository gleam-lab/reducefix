#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q;
    cin >> h >> w >> q;

    vector<set<ll>> row_walls(h), col_walls(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at (r, c)
        auto& row_set = row_walls[r];
        auto& col_set = col_walls[c];

        if (row_set.find(c) != row_set.end()) {
            // Destroy the wall at (r, c)
            row_set.erase(c);
            col_set.erase(r);
        } else {
            // Find and destroy one wall in each direction
            vector<pair<ll, ll>> to_destroy;

            // Up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                to_destroy.emplace_back(*it, c);
            }

            // Down
            it = col_walls[c].upper_bound(r);
            if (it != col_walls[c].end()) {
                to_destroy.emplace_back(*it, c);
            }

            // Left
            auto rit = row_walls[r].lower_bound(c);
            if (rit != row_walls[r].begin()) {
                --rit;
                to_destroy.emplace_back(r, *rit);
            }

            // Right
            rit = row_walls[r].upper_bound(c);
            if (rit != row_walls[r].end()) {
                to_destroy.emplace_back(r, *rit);
            }

            // Remove the found walls
            for (auto [x, y] : to_destroy) {
                row_walls[x].erase(y);
                col_walls[y].erase(x);
            }
        }
    }

    ll remaining = 0;
    for (ll i = 0; i < h; ++i) {
        remaining += row_walls[i].size();
    }

    cout << remaining << "\n";

    return 0;
}
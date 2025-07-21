#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    
    // Initialize all cells as walls
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            // Destroy the wall at (r, c)
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Destroy the nearest walls in four directions
            // Left
            auto left_it = row[r].lower_bound(c);
            if (left_it != row[r].begin()) {
                --left_it;
                ll left_j = *left_it;
                row[r].erase(left_j);
                col[left_j].erase(r);
            }
            // Right
            auto right_it = row[r].upper_bound(c);
            if (right_it != row[r].end()) {
                ll right_j = *right_it;
                row[r].erase(right_j);
                col[right_j].erase(r);
            }
            // Up
            auto up_it = col[c].lower_bound(r);
            if (up_it != col[c].begin()) {
                --up_it;
                ll up_i = *up_it;
                row[up_i].erase(c);
                col[c].erase(up_i);
            }
            // Down
            auto down_it = col[c].upper_bound(r);
            if (down_it != col[c].end()) {
                ll down_i = *down_it;
                row[down_i].erase(c);
                col[c].erase(down_i);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    return 0;
}
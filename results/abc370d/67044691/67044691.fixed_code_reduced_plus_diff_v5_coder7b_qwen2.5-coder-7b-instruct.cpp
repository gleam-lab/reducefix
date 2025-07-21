#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q; cin >> h >> w >> q;
    
    // Initialize sets to keep track of walls in each row and column
    vector<set<ll>> rows(h), cols(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    
    while (q--) {
        ll r, c; cin >> r >> c;
        --r; --c; // Convert 1-based index to 0-based
        
        // If there is a wall at (r, c), destroy it
        if (!rows[r].empty()) {
            rows[r].erase(rows[r].find(c));
            cols[c].erase(cols[c].find(r));
        } else {
            // Find the nearest walls to destroy
            auto ri = rows[r].lower_bound(c);
            auto ci = cols[c].lower_bound(r);
            
            if (ri != rows[r].begin()) {
                ri--;
                if (cols[c].count(*ri)) {
                    cols[c].erase(ri);
                    rows[*ri].erase(c);
                }
            }
            if (ri != rows[r].end()) {
                if (cols[c].count(*ri)) {
                    cols[c].erase(ri);
                    rows[*ri].erase(c);
                }
            }
            if (ci != cols[c].begin()) {
                ci--;
                if (rows[*ci].count(c)) {
                    rows[*ci].erase(c);
                    cols[c].erase(ci);
                }
            }
            if (ci != cols[c].end()) {
                if (rows[*ci].count(c)) {
                    rows[*ci].erase(c);
                    cols[c].erase(ci);
                }
            }
        }
    }
    
    // Calculate the number of remaining walls
    ll ans = 0;
    for (const auto& row : rows) {
        ans += row.size();
    }
    
    cout << ans << endl;
    return 0;
}
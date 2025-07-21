#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h + 1), col(w + 1);
    
    // Initialize all cells as having walls
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    while (q--) {
        ll r, c;
        cin >> r >> c;
        
        if (row[r].count(c)) {
            // Wall exists at (r, c), destroy it
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // No wall at (r, c), destroy the first walls in four directions
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
            // Down
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                ll i = *it_down;
                row[i].erase(c);
                col[c].erase(i);
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
            // Right
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                ll j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
            }
        }
    }
    
    ll ans = 0;
    for (ll i = 1; i <= h; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
    
    return 0;
}
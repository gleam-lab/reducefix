#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row[i].insert(j);
        }
    }
    for (ll j = 0; j < w; ++j) {
        for (ll i = 0; i < h; ++i) {
            col[j].insert(i);
        }
    }

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Find the nearest walls in four directions
            vector<pair<ll, ll>> to_remove;
            
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                to_remove.emplace_back(r, *it_left);
            }
            
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                to_remove.emplace_back(r, *it_right);
            }
            
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                to_remove.emplace_back(*it_up, c);
            }
            
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                to_remove.emplace_back(*it_down, c);
            }
            
            // Remove the walls found
            for (auto [i, j] : to_remove) {
                row[i].erase(j);
                col[j].erase(i);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << endl;
}
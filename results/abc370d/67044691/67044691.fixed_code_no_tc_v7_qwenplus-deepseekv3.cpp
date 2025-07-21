#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> rows(h), cols(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }
    ll ans = h * w;
    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
            ans--;
        } else {
            vector<pair<ll, ll>> to_remove;
            // Up
            auto it_up = cols[c].lower_bound(r);
            if (it_up != cols[c].begin()) {
                --it_up;
                to_remove.emplace_back(*it_up, c);
            }
            // Down
            auto it_down = cols[c].lower_bound(r);
            if (it_down != cols[c].end()) {
                to_remove.emplace_back(*it_down, c);
            }
            // Left
            auto it_left = rows[r].lower_bound(c);
            if (it_left != rows[r].begin()) {
                --it_left;
                to_remove.emplace_back(r, *it_left);
            }
            // Right
            auto it_right = rows[r].lower_bound(c);
            if (it_right != rows[r].end()) {
                to_remove.emplace_back(r, *it_right);
            }
            for (auto [i, j] : to_remove) {
                if (rows[i].count(j)) {
                    rows[i].erase(j);
                    cols[j].erase(i);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
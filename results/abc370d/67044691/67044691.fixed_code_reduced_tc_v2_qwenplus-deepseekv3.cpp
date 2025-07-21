#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    ll ans = h * w;
    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            ans--;
        } else {
            vector<pair<ll, ll>> to_erase;
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                to_erase.emplace_back(r, *it_right);
            }
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                to_erase.emplace_back(r, *it_left);
            }
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                to_erase.emplace_back(*it_down, c);
            }
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                to_erase.emplace_back(*it_up, c);
            }
            for (auto [i, j] : to_erase) {
                if (row[i].count(j)) {
                    row[i].erase(j);
                    col[j].erase(i);
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
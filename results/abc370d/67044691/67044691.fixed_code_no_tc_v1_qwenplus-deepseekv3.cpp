#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) {
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
            auto it = row[r].upper_bound(c);
            if (it != row[r].end()) {
                to_erase.emplace_back(r, *it);
            }
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                to_erase.emplace_back(r, *it);
            }
            it = col[c].upper_bound(r);
            if (it != col[c].end()) {
                to_erase.emplace_back(*it, c);
            }
            it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                to_erase.emplace_back(*it, c);
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
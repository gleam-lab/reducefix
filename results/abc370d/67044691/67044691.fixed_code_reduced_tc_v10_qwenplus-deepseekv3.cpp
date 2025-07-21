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

    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;

        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            if (!row[r].empty()) {
                auto it = row[r].upper_bound(c);
                if (it != row[r].end()) {
                    ll j = *it;
                    row[r].erase(j);
                    col[j].erase(r);
                }
                it = row[r].lower_bound(c);
                if (it != row[r].begin()) {
                    --it;
                    ll j = *it;
                    row[r].erase(j);
                    col[j].erase(r);
                }
            }
            if (!col[c].empty()) {
                auto it = col[c].upper_bound(r);
                if (it != col[c].end()) {
                    ll i = *it;
                    row[i].erase(c);
                    col[c].erase(i);
                }
                it = col[c].lower_bound(r);
                if (it != col[c].begin()) {
                    --it;
                    ll i = *it;
                    row[i].erase(c);
                    col[c].erase(i);
                }
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
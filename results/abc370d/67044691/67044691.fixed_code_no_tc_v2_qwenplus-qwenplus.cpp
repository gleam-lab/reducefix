#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, q;
    cin >> h >> w >> q;

    vector<set<ll>> rows(h), cols(w);

    // Initially, every cell has a wall: store all column indices in each row set and vice versa
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

        // If there's a wall at the current position
        if (rows[r].count(c)) {
            rows[r].erase(c);
            cols[c].erase(r);
        } else {
            // Otherwise, look in four directions and remove first walls found

            // Up
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                --it;
                ll x = *it;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Down
            it = cols[c].lower_bound(r);
            if (++it != cols[c].end()) {
                ll x = *it;
                rows[x].erase(c);
                cols[c].erase(x);
            }

            // Left
            auto jt = rows[r].lower_bound(c);
            if (jt != rows[r].begin()) {
                --jt;
                ll y = *jt;
                rows[r].erase(y);
                cols[y].erase(r);
            }

            // Right
            jt = rows[r].lower_bound(c);
            if (++jt != rows[r].end()) {
                ll y = *jt;
                rows[r].erase(y);
                cols[y].erase(r);
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
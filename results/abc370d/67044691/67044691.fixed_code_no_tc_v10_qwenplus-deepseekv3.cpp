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
            col[j].insert(i);
        }
    }
    while (q--) {
        ll r, c;
        cin >> r >> c;
        --r; --c;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Find up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
            // Find down
            it_up = col[c].upper_bound(r);
            if (it_up != col[c].end()) {
                ll i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
            // Find left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
            // Find right
            it_left = row[r].upper_bound(c);
            if (it_left != row[r].end()) {
                ll j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; ++i) {
        ans += row[i].size();
    }
    cout << ans << '\n';
    return 0;
}
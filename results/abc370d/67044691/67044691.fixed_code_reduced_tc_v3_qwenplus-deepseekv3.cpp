#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for (ll i = 0; i < (ll)r; i++)

int main() {
    ll h, w, q; cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    rep(iii, q) {
        ll r, c; cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                ll j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
            }
            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
            // Down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                ll i = *it_down;
                row[i].erase(c);
                col[c].erase(i);
            }
            // Up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
        }
    }
    ll ans = 0;
    rep(i, h) ans += row[i].size();
    cout << ans << endl;
}
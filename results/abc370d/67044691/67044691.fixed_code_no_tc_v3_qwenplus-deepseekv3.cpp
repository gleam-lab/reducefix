#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    for (ll i = 0; i < h; ++i)
        for (ll j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Find the first wall in each direction
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                row[i].erase(c);
                col[c].erase(i);
            }
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                ll i = *it_down;
                row[i].erase(c);
                col[c].erase(i);
            }
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                row[r].erase(j);
                col[j].erase(r);
            }
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                ll j = *it_right;
                row[r].erase(j);
                col[j].erase(r);
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < h; ++i)
        ans += row[i].size();
    cout << ans << endl;
    return 0;
}
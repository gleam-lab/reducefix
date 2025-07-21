#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for (ll i = 0; i < (ll)r; i++)

int main() {
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    rep(i, h) rep(j, w) {
        row[i].insert(j);
        col[j].insert(i);
    }
    rep(iii, q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Check up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                ll up_row = *(--it_up);
                row[up_row].erase(c);
                col[c].erase(up_row);
            }
            // Check down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                ll down_row = *it_down;
                row[down_row].erase(c);
                col[c].erase(down_row);
            }
            // Check left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                ll left_col = *(--it_left);
                row[r].erase(left_col);
                col[left_col].erase(r);
            }
            // Check right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                ll right_col = *it_right;
                row[r].erase(right_col);
                col[right_col].erase(r);
            }
        }
    }
    ll ans = 0;
    rep(i, h) ans += row[i].size();
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h, w, q;
    cin >> h >> w >> q;
    vector<set<ll>> row(h), col(w);
    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    ll total_walls = h * w;
    while (q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (row[r].count(c)) {
            row[r].erase(c);
            col[c].erase(r);
            total_walls--;
        } else {
            // Check up
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                ll i = *it_up;
                if (row[i].count(c)) {
                    row[i].erase(c);
                    col[c].erase(i);
                    total_walls--;
                }
            }
            // Check down
            auto it_down = col[c].upper_bound(r);
            if (it_down != col[c].end()) {
                ll i = *it_down;
                if (row[i].count(c)) {
                    row[i].erase(c);
                    col[c].erase(i);
                    total_walls--;
                }
            }
            // Check left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                ll j = *it_left;
                if (col[j].count(r)) {
                    col[j].erase(r);
                    row[r].erase(j);
                    total_walls--;
                }
            }
            // Check right
            auto it_right = row[r].upper_bound(c);
            if (it_right != row[r].end()) {
                ll j = *it_right;
                if (col[j].count(r)) {
                    col[j].erase(r);
                    row[r].erase(j);
                    total_walls--;
                }
            }
        }
    }
    cout << total_walls << endl;
    return 0;
}
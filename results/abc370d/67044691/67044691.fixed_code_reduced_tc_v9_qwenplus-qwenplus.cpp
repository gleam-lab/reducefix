#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, r) for (ll i = 0; i < (ll)r; i++)

int main() {
    ll h, w, q;
    cin >> h >> w >> q;

    // row[i]: set of columns in row i that still have walls
    vector<set<ll>> row(h);
    // col[j]: set of rows in column j that still have walls
    vector<set<ll>> col(w);

    // Initialize all walls present
    rep(i, h) {
        rep(j, w) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    rep(_, q) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;

        // Check if there's a wall at (r, c)
        if (row[r].find(c) != row[r].end()) {
            // Destroy wall at (r, c)
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // We need to destroy the first walls in each direction
            // up, down, left, right

            // For up (in column c, find first wall above r)
            auto up = col[c].lower_bound(r);
            if (up != col[c].begin()) {
                up--;
                ll ur = *up;
                row[ur].erase(c);
                col[c].erase(ur);
            }

            // For down (in column c, find first wall below r)
            auto down = col[c].upper_bound(r);
            if (down != col[c].end()) {
                ll dr = *down;
                row[dr].erase(c);
                col[c].erase(dr);
            }

            // For left (in row r, find first wall left of c)
            auto left = row[r].lower_bound(c);
            if (left != row[r].begin()) {
                left--;
                ll lc = *left;
                row[r].erase(lc);
                col[lc].erase(r);
            }

            // For right (in row r, find first wall right of c)
            auto right = row[r].upper_bound(c);
            if (right != row[r].end()) {
                ll rc = *right;
                row[r].erase(rc);
                col[rc].erase(r);
            }
        }
    }

    // Count remaining walls
    ll ans = 0;
    rep(i, h) {
        ans += row[i].size();
    }
    cout << ans << endl;

    return 0;
}
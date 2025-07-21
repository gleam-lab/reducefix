#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> row(W), col(H); // row[c] stores occupied columns in row c? No: it's actually col[c] for columns

    // Initialize all walls are present
    rep(i, H) {
        rep(j, W) {
            col[i].insert(j);
            row[j].insert(i);
        }
    }

    ll remaining = (ll)H * W;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (col[r].count(c)) {
            // Wall exists at (r,c), destroy it
            col[r].erase(c);
            row[c].erase(r);
            remaining--;
        } else {
            // Destroy first wall in each direction
            // Up
            auto it = row[c].lower_bound(r);
            if (it != row[c].begin()) {
                it--;
                int tr = *it;
                col[tr].erase(c);
                row[c].erase(tr);
                remaining--;
            }

            // Down
            it = row[c].lower_bound(r);
            if (it != row[c].end()) {
                int br = *it;
                col[br].erase(c);
                row[c].erase(br);
                remaining--;
            }

            // Left
            auto jt = col[r].lower_bound(c);
            if (jt != col[r].begin()) {
                jt--;
                int lc = *jt;
                row[lc].erase(r);
                col[r].erase(lc);
                remaining--;
            }

            // Right
            jt = col[r].lower_bound(c);
            if (jt != col[r].end()) {
                int rc = *jt;
                row[rc].erase(r);
                col[r].erase(rc);
                remaining--;
            }
        }
    }

    cout << remaining << endl;
}
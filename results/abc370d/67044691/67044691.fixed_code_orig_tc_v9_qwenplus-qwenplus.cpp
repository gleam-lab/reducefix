#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll H, W, Q;
    cin >> H >> W >> Q;

    vector<set<ll>> row(H), col(W);

    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (Q--) {
        ll R, C;
        cin >> R >> C;
        R--; C--;

        if (row[R].find(C) != row[R].end()) {
            // There's a wall here; destroy it
            row[R].erase(C);
            col[C].erase(R);
        } else {
            // Try to destroy the first wall in each direction
            // Left
            auto itL = row[R].lower_bound(C);
            if (itL != row[R].begin()) {
                --itL;
                ll c2 = *itL;
                row[R].erase(c2);
                col[c2].erase(R);
            }

            // Right
            auto itR = row[R].upper_bound(C);
            if (itR != row[R].end()) {
                ll c2 = *itR;
                row[R].erase(c2);
                col[c2].erase(R);
            }

            // Up
            auto itU = col[C].lower_bound(R);
            if (itU != col[C].begin()) {
                --itU;
                ll r2 = *itU;
                col[C].erase(r2);
                row[r2].erase(C);
            }

            // Down
            auto itD = col[C].upper_bound(R);
            if (itD != col[C].end()) {
                ll r2 = *itD;
                col[C].erase(r2);
                row[r2].erase(C);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < H; ++i) {
        ans += row[i].size();
    }
    cout << ans << '\n';

    return 0;
}
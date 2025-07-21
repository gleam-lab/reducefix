#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h, w, q; cin >> h >> w >> q;
    vector<vector<pair<ll, ll>>> grid(h, vector<pair<ll, ll>>(w));

    for (ll i = 0; i < h; ++i) {
        for (ll j = 0; j < w; ++j) {
            grid[i][j] = {i, j};
        }
    }

    while (q--) {
        ll r, c; cin >> r >> c;
        --r; --c;

        auto& [ri, ci] = grid[r][c];
        if (ri == -1 && ci == -1) continue;

        ri = ci = -1;
        
        for (ll i = r - 1; i >= 0; --i) {
            auto& [rii, cii] = grid[i][c];
            if (rii != -1) break;
            ri = rii, ci = cii;
        }

        for (ll i = r + 1; i < h; ++i) {
            auto& [rii, cii] = grid[i][c];
            if (rii != -1) break;
            ri = rii, ci = cii;
        }

        for (ll j = c - 1; j >= 0; --j) {
            auto& [rii, cii] = grid[r][j];
            if (rii != -1) break;
            ri = rii, ci = cii;
        }

        for (ll j = c + 1; j < w; ++j) {
            auto& [rii, cii] = grid[r][j];
            if (rii != -1) break;
            ri = rii, ci = cii;
        }
    }

    ll ans = 0;
    for (const auto& row : grid) {
        for (const auto& [ri, ci] : row) {
            if (ri != -1 && ci != -1) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}
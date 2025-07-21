#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        pieces[i] = {x, y};
    }

    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < m; i++) {
        ll x = pieces[i].first;
        ll y = pieces[i].second;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }

    ll ans = n * n; // Total number of squares
    // Subtract squares in rows, columns, and diagonals
    ans -= rows.size() * n;
    ans -= cols.size() * n;
    ans -= diag1.size() * n;
    ans -= diag2.size() * n;

    // Calculate overlaps
    set<pair<ll, ll>> diag1_to_diag2, diag2_to_diag1;
    for (ll x : diag1) {
        for (ll y : diag2) {
            if (x + y < n + 1) {
                diag1_to_diag2.insert({x + y, -y});
            }
        }
    }
    for (ll x : diag2) {
        for (ll y : diag1) {
            if (x - y < n + 1) {
                diag2_to_diag1.insert({x - y, y});
            }
        }
    }

    // Subtract overlaps
    for (auto [d1, d2] : diag1_to_diag2) {
        ans -= diag2.count(d2) - diag2_to_diag1.count({d1, d2});
    }
    for (auto [d1, d2] : diag2_to_diag1) {
        ans -= diag1.count(d1) - diag1_to_diag2.count({d1, d2});
    }

    cout << ans << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    ll NT = 1;
    cin >> NT;
    while (NT--) solve();
    return 0;
}
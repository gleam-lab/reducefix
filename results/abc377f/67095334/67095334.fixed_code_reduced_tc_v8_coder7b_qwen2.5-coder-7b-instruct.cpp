#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll n, vector<pair<ll, ll>>& pieces) {
    set<ll> rows, cols, diag1, diag2;

    for (const auto& p : pieces) {
        rows.insert(p.first);
        cols.insert(p.second);
        diag1.insert(p.first + p.second);
        diag2.insert(p.first - p.second);
    }

    ll total_empty = (n - rows.size()) * (n - cols.size());

    for (const auto& p : pieces) {
        ll x = p.first, y = p.second;

        // Check vertical line (column)
        if (cols.find(y) != cols.end()) {
            total_empty--;
        }

        // Check horizontal line (row)
        if (rows.find(x) != rows.end()) {
            total_empty--;
        }

        // Check diagonal line (i + j = constant)
        if (diag1.find(x + y) != diag1.end()) {
            total_empty--;
        }

        // Check anti-diagonal line (i - j = constant)
        if (diag2.find(x - y) != diag2.end()) {
            total_empty--;
        }
    }

    return total_empty;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> pieces(m);
    for (ll i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    cout << solve(n, pieces) << '\n';

    return 0;
}
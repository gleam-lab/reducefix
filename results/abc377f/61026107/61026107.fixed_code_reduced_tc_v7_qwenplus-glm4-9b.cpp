#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> rows, cols, diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        --x; --y; // Convert to 0-indexed
        rows.emplace_back(x, y);
        cols.emplace_back(y, x);
        diag1.emplace_back(x + y, i);
        diag2.emplace_back(abs(x - y), i);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());

    ll row = 0, col = 0, diag1_row = 0, diag2_row = 0;
    ll free_rows = 0, free_cols = 0, free_diag1 = 0, free_diag2 = 0;

    for (ll i = 0; i < n; ++i) {
        while (row < m && rows[row].first == i) {
            ++row;
        }
        free_rows += row;

        while (col < m && cols[col].first == i) {
            ++col;
        }
        free_cols += col;

        while (diag1_row < m && diag1[diag1_row].first == i) {
            ++diag1_row;
        }
        free_diag1 += diag1_row;

        while (diag2_row < m && diag2[diag2_row].first == i) {
            ++diag2_row;
        }
        free_diag2 += diag2_row;
    }

    free_rows = n - free_rows;
    free_cols = n - free_cols;
    free_diag1 = n - free_diag1;
    free_diag2 = n - free_diag2;

    cout << n * n - (free_rows + free_cols + free_diag1 + free_diag2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll NT;
    cin >> NT;
    while (NT--) solve();
    return 0;
}
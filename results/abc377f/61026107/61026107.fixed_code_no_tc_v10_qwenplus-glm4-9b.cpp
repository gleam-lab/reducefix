#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> rows(n + 1, 0), cols(n + 1, 0), diag1(n * 2 + 1, 0), diag2(n * 2 + 1, 0);
    
    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        rows[x]++;
        cols[y]++;
        diag1[x + y]++;
        diag2[x - y + n]++;
    }
    
    ll attacked_rows = 0, attacked_cols = 0, attacked_diag1 = 0, attacked_diag2 = 0;
    
    // Count the number of fully attacked rows, columns, and diagonals
    for (ll i = 1; i <= n; ++i) {
        if (rows[i] > 0) attacked_rows++;
        if (cols[i] > 0) attacked_cols++;
        if (diag1[i] > 0) attacked_diag1++;
        if (diag2[i] > 0) attacked_diag2++;
    }
    
    // Calculate the number of squares that cannot be captured
    ll total_squares = n * n;
    ll squares_captured = attacked_rows * n + attacked_cols * n + attacked_diag1 + attacked_diag2 - (attacked_rows + attacked_cols + attacked_diag1 + attacked_diag2) * (attacked_rows + attacked_cols + attacked_diag1 + attacked_diag2 - 1) / 2;
    
    cout << total_squares - squares_captured << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(m), b(m), c(m), d(m);
    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        a[i] = {x, i};
        b[i] = {y, i};
        c[i] = {x + y, i};
        d[i] = {x - y, i};
    }
    
    // Sort to process in order of coordinates
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    
    ll total_empty = n * n;
    ll captured = 0;
    
    // Mark rows, columns, diagonals, and anti-diagonals
    vector<bool> rows(n + 1, false), cols(n + 1, false);
    for (auto& p : a) rows[p.first] = true; // Rows
    for (auto& p : b) cols[p.first] = true; // Columns
    for (auto& p : c) rows[p.first - p.second] = true; // Diagonals
    for (auto& p : d) cols[p.first + p.second] = true; // Anti-diagonals
    
    // Count captured squares
    for (ll i = 1; i <= n; ++i) {
        if (rows[i]) captured++;
        if (cols[i]) captured++;
    }
    
    // Calculate the number of squares that can be safely placed
    ll answer = total_empty - captured;
    cout << answer << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin.exceptions(cin.failbit); // Handle unexpected input
    solve();
    return 0;
}
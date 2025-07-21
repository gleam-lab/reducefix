#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }
    
    ll total = n * n;
    ll threatened = 0;
    
    // Rows and columns
    threatened += rows.size() * n;
    threatened += cols.size() * n;
    
    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll x_minus_y = d;
        // The number of positions (x, y) such that x - y = d and 1 <= x, y <= n
        ll lower = max(1LL, 1 + x_minus_y);
        ll upper = min(n, n + x_minus_y);
        if (lower > upper) continue;
        threatened += (upper - lower + 1);
    }
    
    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll x_plus_y = d;
        // The number of positions (x, y) such that x + y = d and 1 <= x, y <= n
        ll lower = max(1LL, x_plus_y - n);
        ll upper = min(n, x_plus_y - 1);
        if (lower > upper) continue;
        threatened += (upper - lower + 1);
    }
    
    // Subtract intersections of rows and columns (counted twice)
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diag1.count(r - c) || diag2.count(r + c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections of rows and diagonals (counted twice)
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) || diag2.count(r + c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections of rows and anti-diagonals (counted twice)
    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) || diag1.count(r - c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections of columns and diagonals (counted twice)
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = d1 + c;
            if (r < 1 || r > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || diag2.count(r + c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections of columns and anti-diagonals (counted twice)
    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r < 1 || r > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || diag1.count(r - c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Subtract intersections of diagonals and anti-diagonals (counted twice)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > n || c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || cols.count(c)) {
                threatened -= 1;
            } else {
                threatened -= 1;
            }
        }
    }
    
    // Add back intersections of rows, columns, and diagonals/anti-diagonals (counted three times)
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            bool in_d1 = diag1.count(r - c);
            bool in_d2 = diag2.count(r + c);
            if (in_d1 && in_d2) {
                threatened += 2;
            } else if (in_d1 || in_d2) {
                threatened += 1;
            }
        }
    }
    
    // Subtract the occupied squares (they are included in the threatened count)
    ll safe = total - threatened - m;
    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
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
    
    ll total = n * n - m; // Total empty squares
    
    // Squares attacked by rows
    ll row_attacks = rows.size() * n;
    
    // Squares attacked by columns
    ll col_attacks = cols.size() * n;
    
    // Squares attacked by main diagonals (a - b = constant)
    ll diag1_attacks = 0;
    for (auto d : diag1) {
        ll x_plus_y_min = max(1LL, 1 + d);
        ll x_plus_y_max = min(n, n + d);
        if (x_plus_y_min > x_plus_y_max) continue;
        diag1_attacks += x_plus_y_max - x_plus_y_min + 1;
    }
    
    // Squares attacked by anti diagonals (a + b = constant)
    ll diag2_attacks = 0;
    for (auto d : diag2) {
        ll x_minus_y_min = max(1LL, d - n);
        ll x_minus_y_max = min(n, d - 1);
        if (x_minus_y_min > x_minus_y_max) continue;
        diag2_attacks += x_minus_y_max - x_minus_y_min + 1;
    }
    
    // Total squares attacked by at least one condition
    ll total_attacks = row_attacks + col_attacks + diag1_attacks + diag2_attacks;
    
    // Subtract overlaps between rows and columns
    ll row_col = rows.size() * cols.size();
    total_attacks -= row_col;
    
    // Subtract overlaps between rows and diag1
    ll row_diag1 = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                row_diag1++;
            }
        }
    }
    total_attacks -= row_diag1;
    
    // Subtract overlaps between rows and diag2
    ll row_diag2 = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                row_diag2++;
            }
        }
    }
    total_attacks -= row_diag2;
    
    // Subtract overlaps between columns and diag1
    ll col_diag1 = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                col_diag1++;
            }
        }
    }
    total_attacks -= col_diag1;
    
    // Subtract overlaps between columns and diag2
    ll col_diag2 = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                col_diag2++;
            }
        }
    }
    total_attacks -= col_diag2;
    
    // Subtract overlaps between diag1 and diag2
    ll diag1_diag2 = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                diag1_diag2++;
            }
        }
    }
    total_attacks -= diag1_diag2;
    
    // Add back overlaps between rows, columns, and diag1
    ll row_col_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c)) {
                row_col_diag1++;
            }
        }
    }
    total_attacks += row_col_diag1;
    
    // Add back overlaps between rows, columns, and diag2
    ll row_col_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r + c)) {
                row_col_diag2++;
            }
        }
    }
    total_attacks += row_col_diag2;
    
    // Add back overlaps between rows, diag1, and diag2
    ll row_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > n) continue;
            if (diag2.count(r + c)) {
                row_diag1_diag2++;
            }
        }
    }
    total_attacks += row_diag1_diag2;
    
    // Add back overlaps between columns, diag1, and diag2
    ll col_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > n) continue;
            if (diag2.count(r + c)) {
                col_diag1_diag2++;
            }
        }
    }
    total_attacks += col_diag1_diag2;
    
    // Subtract overlaps between rows, columns, diag1, and diag2
    ll row_col_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                row_col_diag1_diag2++;
            }
        }
    }
    total_attacks -= row_col_diag1_diag2;
    
    // The safe squares are total empty squares minus total_attacks plus pieces (since their squares are already excluded)
    ll safe = total - (total_attacks - m);
    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
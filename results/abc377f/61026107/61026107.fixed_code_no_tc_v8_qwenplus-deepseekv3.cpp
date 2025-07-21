#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    ll total_safe = n * n - m; // Total empty squares initially

    // Subtract squares threatened by rows
    total_safe -= rows.size() * n;
    // Subtract squares threatened by columns
    total_safe -= cols.size() * n;
    // Subtract squares threatened by first diagonals (a - b = constant)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        total_safe -= cnt;
    }
    // Subtract squares threatened by second diagonals (a + b = constant)
    for (auto d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        total_safe -= cnt;
    }

    // Add back squares that were subtracted multiple times
    // Intersection of row and column
    total_safe += rows.size() * cols.size();
    // Intersection of row and first diagonal
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                total_safe += 1;
            }
        }
    }
    // Intersection of row and second diagonal
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                total_safe += 1;
            }
        }
    }
    // Intersection of column and first diagonal
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                total_safe += 1;
            }
        }
    }
    // Intersection of column and second diagonal
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                total_safe += 1;
            }
        }
    }
    // Intersection of first and second diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                total_safe += 1;
            }
        }
    }

    // Subtract squares that were added back but are actually triple intersections
    // Intersection of row, column, and first diagonal
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c)) {
                total_safe -= 1;
            }
        }
    }
    // Intersection of row, column, and second diagonal
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r + c)) {
                total_safe -= 1;
            }
        }
    }
    // Intersection of row, first diagonal, and second diagonal
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c >= 1 && c <= n && diag2.count(r + c)) {
                total_safe -= 1;
            }
        }
    }
    // Intersection of column, first diagonal, and second diagonal
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r >= 1 && r <= n && diag2.count(r + c)) {
                total_safe -= 1;
            }
        }
    }

    // Add back squares that were subtracted too many times (quadruple intersections)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                total_safe += 1;
            }
        }
    }

    cout << total_safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> occupied;

    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll forbidden = 0;

    // Rows
    forbidden += rows.size() * n;
    // Columns
    forbidden += cols.size() * n;
    // Diagonals (a - b)
    for (auto d : diag1) {
        ll x_minus_y = d;
        // The diagonal i - j = x_minus_y
        // i ranges from max(1, 1 + x_minus_y) to min(n, n + x_minus_y)
        // j ranges accordingly.
        // The number of squares on this diagonal is:
        // min(n, n + x_minus_y) - max(1, 1 + x_minus_y) + 1
        // which is equal to n - abs(x_minus_y)
        ll cnt = n - abs(x_minus_y);
        forbidden += cnt;
    }
    // Anti-diagonals (a + b)
    for (auto d : diag2) {
        ll x_plus_y = d;
        // The diagonal i + j = x_plus_y
        // i ranges from max(1, x_plus_y - n) to min(n, x_plus_y - 1)
        // j ranges from x_plus_y - i
        // The number of squares is:
        // min(n, x_plus_y - 1) - max(1, x_plus_y - n) + 1
        // which is equal to n - abs(x_plus_y - (n + 1))
        ll cnt = n - abs(x_plus_y - (n + 1));
        forbidden += cnt;
    }

    // Now, subtract overlaps where squares are counted multiple times
    // Squares in row and column
    for (auto r : rows) {
        for (auto c : cols) {
            if (occupied.count({r, c})) continue;
            if (diag1.count(r - c) && diag2.count(r + c)) {
                forbidden -= 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                forbidden -= 2;
            } else {
                forbidden -= 1;
            }
        }
    }

    // Squares in row and diagonal (a - b)
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c < 1 || c > n) continue;
            if (occupied.count({r, c})) continue;
            if (cols.count(c) && diag2.count(r + c)) {
                forbidden -= 2;
            } else if (cols.count(c) || diag2.count(r + c)) {
                forbidden -= 1;
            }
        }
    }

    // Squares in row and anti-diagonal (a + b)
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c < 1 || c > n) continue;
            if (occupied.count({r, c})) continue;
            if (cols.count(c) && diag1.count(r - c)) {
                forbidden -= 2;
            } else if (cols.count(c) || diag1.count(r - c)) {
                forbidden -= 1;
            }
        }
    }

    // Squares in column and diagonal (a - b)
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (r < 1 || r > n) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) && diag2.count(r + c)) {
                forbidden -= 2;
            } else if (rows.count(r) || diag2.count(r + c)) {
                forbidden -= 1;
            }
        }
    }

    // Squares in column and anti-diagonal (a + b)
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r < 1 || r > n) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) && diag1.count(r - c)) {
                forbidden -= 2;
            } else if (rows.count(r) || diag1.count(r - c)) {
                forbidden -= 1;
            }
        }
    }

    // Squares in both diagonals
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > n || c < 1 || c > n) continue;
            if (occupied.count({r, c})) continue;
            if (rows.count(r) && cols.count(c)) {
                forbidden -= 2;
            } else if (rows.count(r) || cols.count(c)) {
                forbidden -= 1;
            }
        }
    }

    // Finally, subtract the occupied squares which were counted in forbidden but are not available
    forbidden -= occupied.size();

    ll total_squares = n * n;
    ll safe_squares = total_squares - forbidden;
    cout << safe_squares << "\n";

    return 0;
}
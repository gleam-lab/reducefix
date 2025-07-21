#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include<debug.h>
#else
#define debug(...)
#endif

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

    ll total_threatened = 0;

    // Rows
    total_threatened += rows.size() * n;

    // Columns
    total_threatened += cols.size() * n;

    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        total_threatened += cnt;
    }

    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        total_threatened += cnt;
    }

    // Overlaps between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diag1.count(r - c) || diag2.count(r + c)) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between rows and diagonals (a - b)
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) || diag2.count(r + c)) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between rows and anti-diagonals (a + b)
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (cols.count(c) || diag1.count(r - c)) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between columns and diagonals (a - b)
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r < 1 || r > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || diag2.count(r + c)) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between columns and anti-diagonals (a + b)
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r < 1 || r > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || diag1.count(r - c)) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between diagonals (a - b) and anti-diagonals (a + b)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > n || c < 1 || c > n) continue;
            if (pieces.count({r, c})) continue;
            if (rows.count(r) || cols.count(c)) {
                total_threatened -= 1;
            }
        }
    }

    ll safe_squares = n * n - total_threatened;
    cout << safe_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
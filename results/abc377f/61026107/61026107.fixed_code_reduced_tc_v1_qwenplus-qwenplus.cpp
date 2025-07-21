#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols;
    set<ll> diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    ll total = n * n;

    // Subtract squares threatened by existing pieces

    // Rows and columns
    total -= rows.size() * n;
    total -= cols.size() * n;

    // Diagonals of the form x - y = k
    for (auto d : diag1) {
        ll count = n - abs(d);
        if (count > 0) total -= count;
    }

    // Diagonals of the form x + y = k
    for (auto d : diag2) {
        ll count = n - abs(n - d);
        if (count > 0) total -= count;
    }

    // Add back overlaps (inclusion-exclusion principle)

    // Row and Column intersections
    for (auto r : rows) {
        for (auto c : cols) {
            total++;
        }
    }

    // Row and diag1 (x - y = d)
    for (auto r : rows) {
        for (auto d : diag1) {
            ll y = r - d;
            if (1 <= y && y <= n) total++;
        }
    }

    // Row and diag2 (x + y = d)
    for (auto r : rows) {
        for (auto d : diag2) {
            ll y = d - r;
            if (1 <= y && y <= n) total++;
        }
    }

    // Col and diag1 (x - y = d => x = y + d)
    for (auto c : cols) {
        for (auto d : diag1) {
            ll x = c + d;
            if (1 <= x && x <= n) total++;
        }
    }

    // Col and diag2 (x + y = d => x = d - y)
    for (auto c : cols) {
        for (auto d : diag2) {
            ll x = d - c;
            if (1 <= x && x <= n) total++;
        }
    }

    // diag1 and diag2 intersection: solve x - y = d1, x + y = d2 => x = (d1 + d2)/2, y = (d2 - d1)/2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (1 <= x && x <= n && 1 <= y && y <= n) total++;
        }
    }

    // Subtract triple overlaps (diag1 ∩ diag2 ∩ row/col overlaps)

    // diag1 ∩ diag2 ∩ row
    for (auto r : rows) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll y = r - d1;
                if (y < 1 || y > n) continue;
                if (r + y == d2) total--;
            }
        }
    }

    // diag1 ∩ diag2 ∩ col
    for (auto c : cols) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll x = c + d1;
                if (x < 1 || x > n) continue;
                if (x + c == d2) total--;
            }
        }
    }

    // Add back quadruple overlaps (row ∩ col ∩ diag1 ∩ diag2)
    for (auto r : rows) {
        for (auto c : cols) {
            bool in_diag1 = diag1.count(r - c);
            bool in_diag2 = diag2.count(r + c);
            if (in_diag1 && in_diag2) total++;
        }
    }

    // Finally, subtract those already occupied by other pieces
    total -= m;

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int NT = 1;
    // cin >> NT;
    while (NT--) solve();
}
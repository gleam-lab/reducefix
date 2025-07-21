#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

void solve() {
    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: x - y, diag2: x + y

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Total number of squares that are under attack
    ll attacked = 0;

    // Rows and columns
    attacked += rows.size() * n;
    attacked += cols.size() * n;

    // Diagonals of type x - y
    for (auto d : diag1) {
        ll count = 0;
        if (d >= 0) {
            count = n - d;
        } else {
            count = n + d;
        }
        attacked += count;
    }

    // Diagonals of type x + y
    for (auto d : diag2) {
        ll count = 0;
        if (d <= n + 1) {
            count = d - 1;
        } else {
            count = 2 * n + 1 - d;
        }
        attacked += count;
    }

    // Subtract overlaps: intersections of row-col, row-diag, col-diag, diag-diag

    // Row-Column intersections (already counted in rows or cols)
    for (auto r : rows) {
        for (auto c : cols) {
            attacked--; // Overlap point counted twice
        }
    }

    // Row-Diag1 intersections
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                attacked--;
            }
        }
    }

    // Row-Diag2 intersections
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                attacked--;
            }
        }
    }

    // Col-Diag1 intersections
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= n) {
                attacked--;
            }
        }
    }

    // Col-Diag2 intersections
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                attacked--;
            }
        }
    }

    // Diag1-Diag2 intersections
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = d2 - r;
            if ((d1 + d2) % 2 == 0 && 1 <= r && r <= n && 1 <= c && c <= n) {
                attacked--;
            }
        }
    }

    // Total empty safe squares
    ll totalSquares = n * n;
    ll occupied = m;
    ll safe = totalSquares - attacked - occupied;

    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    bool operator<(const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    set<ll> rows, cols;
    set<ll> diag1, diag2;  // diag1: x - y, diag2: x + y

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    ll total = n * n;

    // Subtract all squares attacked by existing pieces
    total -= rows.size() * n;
    total -= cols.size() * n;
    total -= diag1.size() * n;
    total -= diag2.size() * n;

    // Add back intersections of row & col
    for (auto r : rows) {
        for (auto c : cols) {
            ll x = r, y = c;
            ll d1 = x - y;
            ll d2 = x + y;
            if (diag1.count(d1) && diag2.count(d2)) {
                total += 2; // both diagonals will have subtracted this twice
            } else if (diag1.count(d1) || diag2.count(d2)) {
                total += 1;
            }
        }
    }

    // Add back intersections of row & diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll x = r;
            ll y = x - d;
            if (1 <= y && y <= n) {
                if (diag2.count(x + y)) {
                    total += 1;
                }
            }
        }
    }

    // Add back intersections of row & diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll x = r;
            ll y = d - x;
            if (1 <= y && y <= n) {
                if (diag1.count(x - y)) {
                    total += 1;
                }
            }
        }
    }

    // Add back intersections of col & diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll y = c;
            ll x = d + y;
            if (1 <= x && x <= n) {
                if (diag2.count(x + y)) {
                    total += 1;
                }
            }
        }
    }

    // Add back intersections of col & diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll y = c;
            ll x = d - y;
            if (1 <= x && x <= n) {
                if (diag1.count(x - y)) {
                    total += 1;
                }
            }
        }
    }

    // Add back intersections of diag1 & diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = d2 - x;
            if (1 <= x && x <= n && 1 <= y && y <= n) {
                if (rows.count(x) || cols.count(y)) {
                    total += 1;
                }
            }
        }
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
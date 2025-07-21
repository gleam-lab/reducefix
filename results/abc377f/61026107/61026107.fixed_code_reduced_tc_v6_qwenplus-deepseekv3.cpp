#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include<debug.h>
#else
#define dump(...)
#endif

struct Point {
    ll x, y;
    bool operator < (const Point& rhs) const {
        if (x == rhs.x) {
            return y < rhs.y;
        }
        return x < rhs.x;
    };
};

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    set<Point> points;

    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
        points.insert({x, y});
    }

    ll total = n * n;
    ll attacked = 0;

    // Squares attacked by rows or columns or diagonals
    attacked += rows.size() * n;
    attacked += cols.size() * n;

    for (auto d : diag1) {
        ll cnt = n - abs(d);
        if (d >= 0) {
            cnt = min(n - d, n);
        } else {
            cnt = min(n + d, n);
        }
        attacked += cnt;
    }

    for (auto d : diag2) {
        ll cnt = n - abs(d - (n + 1));
        if (d <= n + 1) {
            cnt = min(d - 1, n);
        } else {
            cnt = min(2 * n - d + 1, n);
        }
        attacked += cnt;
    }

    // Subtract squares counted twice (row and column)
    for (auto r : rows) {
        for (auto c : cols) {
            if (points.count({r, c})) continue;
            if (diag1.count(r - c) || diag2.count(r + c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract squares counted twice (row and diag1)
    for (auto r : rows) {
        for (auto d1 : diag1) {
            ll c = r - d1;
            if (c < 1 || c > n) continue;
            if (cols.count(c) || diag2.count(r + c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract squares counted twice (row and diag2)
    for (auto r : rows) {
        for (auto d2 : diag2) {
            ll c = d2 - r;
            if (c < 1 || c > n) continue;
            if (cols.count(c) || diag1.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract squares counted twice (column and diag1)
    for (auto c : cols) {
        for (auto d1 : diag1) {
            ll r = c + d1;
            if (r < 1 || r > n) continue;
            if (rows.count(r) || diag2.count(r + c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract squares counted twice (column and diag2)
    for (auto c : cols) {
        for (auto d2 : diag2) {
            ll r = d2 - c;
            if (r < 1 || r > n) continue;
            if (rows.count(r) || diag1.count(r - c)) {
                attacked -= 1;
            }
        }
    }

    // Subtract squares counted twice (diag1 and diag2)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r < 1 || r > n || c < 1 || c > n) continue;
            if (rows.count(r) || cols.count(c)) {
                attacked -= 1;
            }
        }
    }

    // Add squares counted three times (row, column, diag1)
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                attacked += 1;
            }
        }
    }

    // The final answer is total squares minus attacked squares plus occupied squares (since they were subtracted)
    ll result = total - attacked + m;
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
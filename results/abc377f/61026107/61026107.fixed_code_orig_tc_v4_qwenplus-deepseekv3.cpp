#include<bits/stdc++.h>

using namespace std;
using ll = long long;

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
    set<Point> occupied;

    for (int i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        occupied.insert({a, b});
    }

    ll threatened = 0;

    // Rows and columns
    threatened += rows.size() * n;
    threatened += cols.size() * n;
    threatened -= rows.size() * cols.size(); // Subtract intersections counted twice

    // Diagonals (a - b = constant)
    for (auto d : diag1) {
        ll x_min = max(1LL, 1 + d);
        ll x_max = min(n, n + d);
        ll y_min = max(1LL, 1 - d);
        ll y_max = min(n, n - d);
        if (x_min > x_max || y_min > y_max) continue;
        ll cnt = min(x_max - x_min, y_max - y_min) + 1;
        threatened += cnt;
    }

    // Anti-diagonals (a + b = constant)
    for (auto d : diag2) {
        ll x_min = max(1LL, d - n);
        ll x_max = min(n, d - 1);
        ll y_min = max(1LL, d - n);
        ll y_max = min(n, d - 1);
        if (x_min > x_max || y_min > y_max) continue;
        ll cnt = min(x_max - x_min, y_max - y_min) + 1;
        threatened += cnt;
    }

    // Subtract intersections between rows/cols and diag1/diag2
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                threatened -= 2;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                threatened -= 1;
            }
        }
    }

    // Subtract intersections between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                threatened -= 1;
            }
        }
    }

    // Add back the occupied squares as they were subtracted multiple times
    threatened -= occupied.size();

    ll total = n * n;
    ll safe = total - threatened;
    cout << safe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
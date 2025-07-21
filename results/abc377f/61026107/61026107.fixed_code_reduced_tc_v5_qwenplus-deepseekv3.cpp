#include <bits/stdc++.h>

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
    set<Point> pieces;

    for (int i = 0; i < m; i++) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }

    ll total_squares = n * n;

    // Subtract squares attacked by rows
    ll attacked_by_rows = rows.size() * n;
    // Subtract squares attacked by columns
    ll attacked_by_cols = cols.size() * n;
    // Subtract squares attacked by diagonals (i - j = constant)
    ll attacked_by_diag1 = 0;
    for (auto d : diag1) {
        if (d >= 0) {
            attacked_by_diag1 += n - d;
        } else {
            attacked_by_diag1 += n + d;
        }
    }
    // Subtract squares attacked by anti-diagonals (i + j = constant)
    ll attacked_by_diag2 = 0;
    for (auto d : diag2) {
        if (d <= n + 1) {
            attacked_by_diag2 += d - 1;
        } else {
            attacked_by_diag2 += 2 * n - d + 1;
        }
    }

    total_squares -= attacked_by_rows + attacked_by_cols + attacked_by_diag1 + attacked_by_diag2;

    // Add back intersections that were subtracted twice (inclusion-exclusion principle)
    // Intersections of rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            Point p = {r, c};
            if (pieces.count(p)) continue;
            if (diag1.count(r - c) && diag2.count(r + c)) {
                total_squares += 3;
            } else if (diag1.count(r - c) || diag2.count(r + c)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Intersections of rows and diagonals (i - j)
    for (auto r : rows) {
        for (auto d : diag1) {
            Point p = {r, r - d};
            if (p.y < 1 || p.y > n) continue;
            if (pieces.count(p)) continue;
            if (cols.count(p.y) && diag2.count(r + p.y)) {
                total_squares += 1;
            } else if (cols.count(p.y) || diag2.count(r + p.y)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Intersections of rows and anti-diagonals (i + j)
    for (auto r : rows) {
        for (auto d : diag2) {
            Point p = {r, d - r};
            if (p.y < 1 || p.y > n) continue;
            if (pieces.count(p)) continue;
            if (cols.count(p.y) && diag1.count(r - p.y)) {
                total_squares += 1;
            } else if (cols.count(p.y) || diag1.count(r - p.y)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Intersections of columns and diagonals (i - j)
    for (auto c : cols) {
        for (auto d : diag1) {
            Point p = {d + c, c};
            if (p.x < 1 || p.x > n) continue;
            if (pieces.count(p)) continue;
            if (rows.count(p.x) && diag2.count(p.x + c)) {
                total_squares += 1;
            } else if (rows.count(p.x) || diag2.count(p.x + c)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Intersections of columns and anti-diagonals (i + j)
    for (auto c : cols) {
        for (auto d : diag2) {
            Point p = {d - c, c};
            if (p.x < 1 || p.x > n) continue;
            if (pieces.count(p)) continue;
            if (rows.count(p.x) && diag1.count(p.x - c)) {
                total_squares += 1;
            } else if (rows.count(p.x) || diag1.count(p.x - c)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Intersections of diagonals (i - j) and anti-diagonals (i + j)
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            Point p = {(d1 + d2) / 2, (d2 - d1) / 2};
            if (p.x < 1 || p.x > n || p.y < 1 || p.y > n) continue;
            if (pieces.count(p)) continue;
            if (rows.count(p.x) && cols.count(p.y)) {
                total_squares += 1;
            } else if (rows.count(p.x) || cols.count(p.y)) {
                total_squares += 1;
            } else {
                total_squares += 1;
            }
        }
    }

    // Subtract the number of existing pieces (since they are not empty)
    total_squares -= m;

    cout << total_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
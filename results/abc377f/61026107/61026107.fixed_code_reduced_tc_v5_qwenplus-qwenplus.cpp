#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    vector<Point> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Total number of squares
    ll total = n * n;

    // Subtract all squares attacked by any piece
    total -= (ll)rows.size() * n; // Rows
    total -= (ll)cols.size() * n; // Columns

    // Diagonal 1: x - y = c
    for (auto c : diag1) {
        ll count = min(n - abs(c), n); // Number of points on this diagonal in the grid
        if (c >= -(n-1) && c <= n-1)
            total -= max(0LL, count);
    }

    // Diagonal 2: x + y = s
    for (auto s : diag2) {
        ll count;
        if (s < 2 || s > 2*n) continue;
        if (s <= n+1) {
            count = s - 1;
        } else {
            count = 2*n + 1 - s;
        }
        total -= count;
    }

    // Add back intersections of two lines (they were subtracted twice)
    for (auto r : rows) {
        for (auto c : cols) {
            // Row and column intersection
            total += 1;
        }
    }

    // Intersections of row and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                total += 1;
            }
        }
    }

    // Intersections of row and diag2
    for (auto r : rows) {
        for (auto s : diag2) {
            ll c = s - r;
            if (1 <= c && c <= n) {
                total += 1;
            }
        }
    }

    // Intersections of col and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= n) {
                total += 1;
            }
        }
    }

    // Intersections of col and diag2
    for (auto c : cols) {
        for (auto s : diag2) {
            ll r = s - c;
            if (1 <= r && r <= n) {
                total += 1;
            }
        }
    }

    // Intersections of diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                ll r = (d2 + d1) / 2;
                ll c = (d2 - d1) / 2;
                if (1 <= r && r <= n && 1 <= c && c <= n) {
                    total += 1;
                }
            }
        }
    }

    // Subtract intersections of three lines (added back three times)
    for (auto p : pieces) {
        // This square was:
        // - subtracted 4 times (once for each line it's on)
        // - added back 6 times (once for each pair of lines it's on)
        // - we need to end up with a net subtraction of 1
        // So total adjustment should be: -4 + 6 = +2, so we need to subtract 3 more
        total -= 3;
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
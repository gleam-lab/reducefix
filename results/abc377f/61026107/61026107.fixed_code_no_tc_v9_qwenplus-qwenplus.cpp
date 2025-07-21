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
    set<ll> diag1, diag2;  // diag1: x - y, diag2: x + y

    vector<Point> pieces(m);
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Total number of cells
    ll total = n * n;

    // Subtract all cells attacked by any piece
    total -= (ll)rows.size() * n; // Rows
    total -= (ll)cols.size() * n; // Columns

    // Diagonals (x - y = const)
    for (auto d : diag1) {
        ll count;
        if (d >= 0) {
            count = min(n, n - d);
        } else {
            count = min(n, n + d);
        }
        total -= count;
    }

    // Anti-diagonals (x + y = const)
    for (auto d : diag2) {
        ll count;
        if (d <= n) {
            count = d;
        } else {
            count = 2 * n - d;
        }
        total -= count;
    }

    // Add back over-subtracted intersections
    // We need to count how many unique squares are in the intersection of:
    // row & col, row & diag1, row & diag2, col & diag1, col & diag2, diag1 & diag2

    set<pair<ll, ll>> attacked_cells;

    // row & column
    for (ll r : rows) {
        for (ll c : cols) {
            attacked_cells.insert({r, c});
        }
    }

    // row & diagonal1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                attacked_cells.insert({r, c});
            }
        }
    }

    // row & diagonal2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                attacked_cells.insert({r, c});
            }
        }
    }

    // column & diagonal1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (r >= 1 && r <= n) {
                attacked_cells.insert({r, c});
            }
        }
    }

    // column & diagonal2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                attacked_cells.insert({r, c});
            }
        }
    }

    // diagonal1 & diagonal2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve:
            // r - c = d1
            // r + c = d2
            // => 2r = d1 + d2 => r = (d1 + d2)/2
            // => 2c = d2 - d1 => c = (d2 - d1)/2
            if ((d1 + d2) % 2 == 0) {
                ll r = (d1 + d2) / 2;
                ll c = d2 - r;
                if (r >= 1 && r <= n && c >= 1 && c <= n) {
                    attacked_cells.insert({r, c});
                }
            }
        }
    }

    // Subtract overlaps that were subtracted twice
    for (const auto& p : attacked_cells) {
        total += 1;
    }

    // Now subtract cells occupied by existing pieces
    total -= m;

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
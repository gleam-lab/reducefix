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
    ll n, m; cin >> n >> m;
    set<pair<ll, ll>> blocked_points;
    set<ll> row, col, diag1, diag2;

    for (ll i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        blocked_points.insert({a, b});
        row.insert(a);
        col.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of squares
    ll total = n * n;

    // Subtract all squares attacked by existing pieces
    for (auto r : row) {
        total -= n;
    }
    for (auto c : col) {
        total -= n;
    }
    for (auto d : diag1) {
        ll start = max(1LL, d + 1);
        ll end = min(n, n + d);
        if (start <= end) {
            total -= (end - start + 1);
        }
    }
    for (auto d : diag2) {
        ll start = max(1LL, d - n);
        ll end = min(n, d - 1);
        if (start <= end) {
            total -= (end - start + 1);
        }
    }

    // Add back over-subtracted intersections
    // Row & Column
    for (auto r : row) {
        for (auto c : col) {
            if (!blocked_points.count({r, c})) {
                total += 1;
            }
        }
    }

    // Row & Diag1
    for (auto r : row) {
        for (auto d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                if (!blocked_points.count({r, c})) {
                    total += 1;
                }
            }
        }
    }

    // Row & Diag2
    for (auto r : row) {
        for (auto d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                if (!blocked_points.count({r, c})) {
                    total += 1;
                }
            }
        }
    }

    // Col & Diag1
    for (auto c : col) {
        for (auto d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= n) {
                if (!blocked_points.count({r, c})) {
                    total += 1;
                }
            }
        }
    }

    // Col & Diag2
    for (auto c : col) {
        for (auto d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                if (!blocked_points.count({r, c})) {
                    total += 1;
                }
            }
        }
    }

    // Diag1 & Diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = d2 - x;
            if ((d1 + d2) % 2 == 0 && 1 <= x && x <= n && 1 <= y && y <= n) {
                if (!blocked_points.count({x, y})) {
                    total += 1;
                }
            }
        }
    }

    // Subtract the exact overlaps of three sets
    // Row & Col & Diag1
    for (auto r : row) {
        for (auto c : col) {
            for (auto d : diag1) {
                if (r - c == d) {
                    if (!blocked_points.count({r, c})) {
                        total -= 1;
                    }
                }
            }
        }
    }

    // Row & Col & Diag2
    for (auto r : row) {
        for (auto c : col) {
            for (auto d : diag2) {
                if (r + c == d) {
                    if (!blocked_points.count({r, c})) {
                        total -= 1;
                    }
                }
            }
        }
    }

    // Row & Diag1 & Diag2
    for (auto r : row) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll c1 = r - d1;
                ll c2 = d2 - r;
                if (c1 == c2 && 1 <= c1 && c1 <= n) {
                    if (!blocked_points.count({r, c1})) {
                        total -= 1;
                    }
                }
            }
        }
    }

    // Col & Diag1 & Diag2
    for (auto c : col) {
        for (auto d1 : diag1) {
            for (auto d2 : diag2) {
                ll r1 = d1 + c;
                ll r2 = d2 - c;
                if (r1 == r2 && 1 <= r1 && r1 <= n) {
                    if (!blocked_points.count({r1, c})) {
                        total -= 1;
                    }
                }
            }
        }
    }

    // Add back points that were subtracted four times (only on four-way intersection)
    // Only add if not already occupied
    for (auto r : row) {
        for (auto c : col) {
            if (!blocked_points.count({r, c})) {
                ll d1 = r - c;
                ll d2 = r + c;
                if (diag1.count(d1) && diag2.count(d2)) {
                    total += 1;
                }
            }
        }
    }

    // Finally subtract overlapping points (they are not valid placements)
    for (auto p : blocked_points) {
        total--;
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}
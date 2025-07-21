#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    bool operator<(const Point& o) const { return x != o.x ? x < o.x : y < o.y; }
};

void solve() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols;
    set<ll> diag1, diag2;  // diag1: x - y, diag2: x + y

    vector<Point> pieces(M);
    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x - y);
        diag2.insert(x + y);
    }

    // Total number of squares
    ll total = N * N;

    // Subtract all squares attacked by existing pieces
    // Rows
    total -= rows.size() * N;
    // Columns
    total -= cols.size() * N;

    // Diagonals (x - y = constant)
    for (auto d : diag1) {
        ll cnt = min(d + N - 1, N - max(1LL, 1 + d));
        total -= cnt;
    }

    // Anti-diagonals (x + y = constant)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = min(d - 1, N);
        } else {
            cnt = 2 * N - d + 1;
        }
        total -= cnt;
    }

    // Now add back the overlaps (squares that were double-counted in multiple attack sets)

    // Intersections: row & col
    for (ll r : rows) {
        for (ll c : cols) {
            total++;  // this square was subtracted twice, so add once
        }
    }

    // Intersections: row & diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                total++;
            }
        }
    }

    // Intersections: row & diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                total++;
            }
        }
    }

    // Intersections: col & diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d + c;
            if (1 <= r && r <= N) {
                total++;
            }
        }
    }

    // Intersections: col & diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                total++;
            }
        }
    }

    // Intersections: diag1 & diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            // Solve:
            // x - y = d1
            // x + y = d2
            // => x = (d1 + d2)/2, y = (d2 - d1)/2
            if ((d1 + d2) % 2 != 0) continue;
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                total++;
            }
        }
    }

    // Subtract the actual positions of the pieces as they are occupied
    total += M;

    // Now remove those which exactly match a piece's position (they are not empty!)
    for (const auto& [x, y] : pieces) {
        // Check if (x,y) was counted in the above process
        if (rows.count(x) && cols.count(y)) total--;
    }

    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
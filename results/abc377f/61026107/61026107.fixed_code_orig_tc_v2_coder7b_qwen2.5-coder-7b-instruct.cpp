#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef HOME
#include <debug.h>
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
    set<Point> pieces;
    set<Point> captures;

    // Read and store the positions of the pieces
    for (int i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        pieces.insert({x, y});
    }

    // Identify capture zones for each piece
    for (auto [x, y] : pieces) {
        // Row capture
        captures.insert({x, y});
        for (ll i = 1; i <= n; ++i) {
            captures.insert({i, y});
        }

        // Column capture
        captures.insert({x, y});
        for (ll j = 1; j <= n; ++j) {
            captures.insert({x, j});
        }

        // Diagonal capture (x + y = constant)
        captures.insert({x, y});
        for (ll k = 1; k <= n; ++k) {
            captures.insert({k, x + y - k});
        }

        // Anti-diagonal capture (x - y = constant)
        captures.insert({x, y});
        for (ll k = 1; k <= n; ++k) {
            captures.insert({k, x - y + k});
        }
    }

    // Remove duplicate capture points (if any)
    captures.erase(captures.begin()); // Remove the initial point {x, y}

    // Calculate the number of available squares
    ll total_squares = n * n;
    ll captured_squares = captures.size();
    ll available_squares = total_squares - captured_squares;

    cout << available_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while (NT--) solve();
    return 0;
}
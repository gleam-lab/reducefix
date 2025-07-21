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
    set<ll> a, b, c, d;
    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        a.insert(x);
        b.insert(y);
        c.insert(x - y);
        d.insert(x + y);
    }

    // Calculate the total number of empty squares initially
    ll ans = n * n;

    // Subtract the number of squares in each row, column, diagonal (sum) and anti-diagonal (difference)
    ans -= accumulate(a.begin(), a.end(), 0LL); // Rows
    ans -= accumulate(b.begin(), b.end(), 0LL); // Columns
    ans -= accumulate(c.begin(), c.end(), 0LL); // Diagonals (sum)
    ans -= accumulate(d.begin(), d.end(), 0LL); // Anti-Diagonals (difference)

    // Correct the over-subtraction for squares at intersections of rows/columns/diagonals
    for (auto v1 : a) {
        for (auto v2 : b) {
            int x = v1;
            int y = v2;
            if (c.count(x - y) && d.count(x + y)) {
                ans += 1;
            } else if (c.count(x - y) || d.count(x + y)) {
                ans += 1;
            }
        }
    }

    for (auto v1 : a) {
        for (auto v2 : c) {
            ll x = v1;
            ll y = v1 - v2;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (d.count(x + y)) {
                ans--;
            }
        }
    }

    for (auto v1 : a) {
        for (auto v2 : d) {
            ll x = v1;
            ll y = v2 - v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
        }
    }

    for (auto v1 : b) {
        for (auto v2 : c) {
            ll x = v1 + v2;
            ll y = v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (d.count(x + y)) {
                ans--;
            }
        }
    }

    for (auto v1 : b) {
        for (auto v2 : d) {
            ll x = v2 - v1;
            ll y = v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
        }
    }

    for (auto v1 : c) {
        for (auto v2 : d) {
            if ((v1 + v2) % 2 != 0) continue;
            ll x = (v1 + v2) / 2;
            ll y = v2 - x;
            if (x < 1 || x > n || y < 1 || y > n) continue;
        }
    }

    cout << ans + 1 << "\n"; // Adding 1 because we need to consider the initial count as well
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
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

    // Subtract the squares that are occupied directly by pieces
    ans -= a.size();
    ans -= b.size();

    // Subtract the squares that lie on the diagonals occupied by pieces
    for (auto v : c) {
        if (v >= 0 && v <= n - 1) ans -= 1;
    }
    for (auto v : d) {
        if (v >= 0 && v <= 2 * n - 1) ans -= 1;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
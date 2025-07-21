#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef DEBUG
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
    set<Point> horizontal, vertical, diag1, diag2;

    for (int i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        horizontal.insert({x, y});
        vertical.insert({y, x});
        diag1.insert({x - y, y});
        diag2.insert({x + y, y});
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (!horizontal.count({i, j}) && !vertical.count({j, i})
                && !diag1.count({i - j, j}) && !diag2.count({i + j, j})) {
                ans++;
            }
        }
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
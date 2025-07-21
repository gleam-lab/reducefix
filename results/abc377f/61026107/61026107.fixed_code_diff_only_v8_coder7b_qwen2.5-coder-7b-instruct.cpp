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
    ll ans = n * n;

    // Subtract the occupied positions along each axis and diagonal
    ans -= a.size() * n;
    ans -= b.size() * n;
    ans -= c.size() * (n - 1);
    ans -= d.size() * (n - 1);

    // Add back the positions that were subtracted twice
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

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
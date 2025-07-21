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

    // one
    for (auto v : a) ans -= n;
    for (auto v : b) ans -= n;
    for (auto v : c) ans -= n - abs(v);
    for (auto v : d) ans -= n - abs(n - v);

    // two three four
    for (auto v1 : a) {
        for (auto v2 : b) {
            int x = v1;
            int y = v2;
            if (x == y) continue;
            if (x + y == n + 1) continue;
            if (x - y == 0) continue;
            if (x - y == n - 1) continue;
            ans++;
        }
    }

    for (auto v1 : a) {
        for (auto v2 : c) {
            ll x = v1;
            ll y = v1 - v2;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (y == 0) continue;
            if (y == n) continue;
            ans++;
        }
    }

    for (auto v1 : a) {
        for (auto v2 : d) {
            ll x = v1;
            ll y = v2 - v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (y == 0) continue;
            if (y == n) continue;
            ans++;
        }
    }

    for (auto v1 : b) {
        for (auto v2 : c) {
            ll x = v1 + v2;
            ll y = v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (x == y) continue;
            if (x + y == n + 1) continue;
            ans++;
        }
    }

    for (auto v1 : b) {
        for (auto v2 : d) {
            ll x = v2 - v1;
            ll y = v1;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (x == y) continue;
            if (x + y == n + 1) continue;
            ans++;
        }
    }

    for (auto v1 : c) {
        for (auto v2 : d) {
            if ((v1 + v2) % 2 != 0) continue;
            ll x = (v1 + v2) / 2;
            ll y = v2 - x;
            if (x < 1 || x > n || y < 1 || y > n) continue;
            if (x == y) continue;
            if (x + y == n + 1) continue;
            ans++;
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
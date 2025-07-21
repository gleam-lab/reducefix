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
            if (!a.count(x) && !b.count(y) && !c.count(x - y) && !d.count(x + y)) {
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
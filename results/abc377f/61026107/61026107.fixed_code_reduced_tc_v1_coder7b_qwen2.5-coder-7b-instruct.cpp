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

    // Calculate the total number of squares that cannot be used
    ll cnt = a.size() + b.size() + c.size() + d.size();

    // Subtract the overcounted squares
    for (ll x : a) {
        for (ll y : b) {
            if (c.count(x - y) && d.count(x + y)) {
                cnt--;
            }
        }
    }

    for (ll x : a) {
        for (ll y : c) {
            if (d.count(x + y)) {
                cnt--;
            }
        }
    }

    for (ll x : a) {
        for (ll y : d) {
            cnt--;
        }
    }

    for (ll x : b) {
        for (ll y : c) {
            if (d.count(x + y)) {
                cnt--;
            }
        }
    }

    for (ll x : b) {
        for (ll y : d) {
            cnt--;
        }
    }

    for (ll x : c) {
        for (ll y : d) {
            if ((x + y) % 2 == 0) {
                cnt--;
            }
        }
    }

    cout << n * n - cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
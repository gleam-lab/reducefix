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
    set<ll> a, b, c, d;
    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        a.insert(x);
        b.insert(y);
        c.insert(x - y);
        d.insert(x + y);
    }

    // Calculate the number of captured squares
    ll captured_squares = 0;
    for (auto v : a) captured_squares += n;
    for (auto v : b) captured_squares += n;
    for (auto v : c) captured_squares += n - abs(v);
    for (auto v : d) captured_squares += n - abs(n - v);

    // Deduplicate captured squares
    captured_squares -= a.size() * n;
    captured_squares -= b.size() * n;
    captured_squares -= c.size() * (n - abs(*c.begin()));
    captured_squares -= d.size() * (n - abs(n - *d.rbegin()));

    cout << n * n - captured_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while (NT--) solve();
    return 0;
}
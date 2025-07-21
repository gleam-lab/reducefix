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
    set<ll> rows, cols, diags, antidiags;
    
    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diags.insert(x + y);
        antidiags.insert(x - y);
    }

    ll ans = n * n;
    
    // Subtract the number of squares in each line
    ans -= rows.size() * (n - rows.size());
    ans -= cols.size() * (n - cols.size());
    ans -= diags.size() * (n - diags.size());
    ans -= antidiags.size() * (n - antidiags.size());
    
    // Add back the intersections (since they were subtracted twice)
    for (ll r : rows) {
        ans += diags.count(r) + antidiags.count(r) - (diags.count(r) && antidiags.count(r));
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
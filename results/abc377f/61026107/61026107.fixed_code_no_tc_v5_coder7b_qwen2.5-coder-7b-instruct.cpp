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
    ll total_empty_squares = n * n;

    // Subtract the squares occupied by pieces in each row, column, diagonal
    total_empty_squares -= a.size() * n;
    total_empty_squares -= b.size() * n;
    total_empty_squares -= c.size() * n;
    total_empty_squares -= d.size() * n;

    // Add back the squares that were subtracted twice (diagonals)
    for (auto v : c) {
        total_empty_squares += n - abs(v);
    }
    for (auto v : d) {
        total_empty_squares += n - abs(n - v);
    }

    cout << total_empty_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
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
    set(pair<ll, ll>) covered;
    for (ll i = 0; i < m; ++i) {
        ll x, y; cin >> x >> y;
        covered.insert({x, y});
        covered.insert({y, x});
        covered.insert({x + y, 0});
        covered.insert({x - y, 0});

        if (x == 1 || y == 1 || x + y == n || x - y == n) {
            covered.insert({0, 0});  // These are critical lines that cover entire lines or intersections
        }
    }

    // Calculate the number of valid positions
    ll valid_positions = n * n;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (covered.count({i, j}) || covered.count({j, i}) || covered.count({i + j, 0}) || covered.count({i - j, 0})) {
                valid_positions--;
            }
        }
    }

    cout << valid_positions << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
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

    // Calculate the number of squares that cannot be placed on
    ll total_capturable_squares = 0;
    total_capturable_squares += a.size() * (n - 1); // Captured horizontally
    total_capturable_squares += b.size() * (n - 1); // Captured vertically
    total_capturable_squares += c.size() * (n - abs(*c.begin())); // Captured diagonally (top-left to bottom-right)
    total_capturable_squares += d.size() * (n - abs(*d.begin())); // Captured diagonally (bottom-left to top-right)

    // Remove duplicates and calculate the number of capturable squares
    total_capturable_squares = max(total_capturable_squares, 0LL);

    // The number of empty squares where you can place your piece
    ll empty_squares = n * n - total_capturable_squares;
    cout << empty_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
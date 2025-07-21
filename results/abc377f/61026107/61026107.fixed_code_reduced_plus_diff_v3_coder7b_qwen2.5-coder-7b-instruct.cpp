#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
    set<ll> rows, cols, diag1, diag2;
    
    for (int i = 1; i <= m; i++) {
        ll x, y; cin >> x >> y;
        rows.insert(x);
        cols.insert(y);
        diag1.insert(x + y);
        diag2.insert(x - y);
    }
    
    // Calculate total squares
    ll total_squares = n * n;
    
    // Subtract squares occupied by pieces
    total_squares -= rows.size();
    total_squares -= cols.size();
    total_squares -= diag1.size();
    total_squares -= diag2.size();
    
    // Add back squares counted multiple times
    for (ll r : rows) {
        for (ll c : cols) {
            if (r + c == r - c) {
                total_squares += 1;
            }
        }
    }
    
    for (ll r : rows) {
        for (ll c : diag1) {
            if (r + c == c - r) {
                total_squares += 1;
            }
        }
    }
    
    for (ll r : rows) {
        for (ll c : diag2) {
            if (r - c == c + r) {
                total_squares += 1;
            }
        }
    }
    
    for (ll c : cols) {
        for (ll d1 : diag1) {
            if (c + d1 == c - d1) {
                total_squares += 1;
            }
        }
    }
    
    for (ll c : cols) {
        for (ll d2 : diag2) {
            if (c + d2 == c - d2) {
                total_squares += 1;
            }
        }
    }
    
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if (d1 + d2 == d1 - d2) {
                total_squares += 1;
            }
        }
    }
    
    cout << total_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    // cin >> NT;
    while(NT--) solve();
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m; cin >> n >> m;
    set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll forbidden = 0;
    
    // Rows and columns
    forbidden += rows.size() * n;
    forbidden += cols.size() * n;
    
    // Diagonals (a - b)
    for (auto d : diag1) {
        ll count;
        if (d >= 0) {
            count = n - d;
        } else {
            count = n + d;
        }
        forbidden += count;
    }
    
    // Diagonals (a + b)
    for (auto d : diag2) {
        ll count;
        if (d <= n + 1) {
            count = d - 1;
        } else {
            count = 2 * n - d + 1;
        }
        forbidden += count;
    }
    
    // Overlaps between rows and columns
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r - c) || diag2.count(r + c)) {
                forbidden -= 2;
            } else {
                forbidden -= 1;
            }
        }
    }
    
    // Overlaps between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                if (cols.count(c) || diag2.count(r + c)) {
                    forbidden -= 1;
                } else {
                    forbidden -= 0;
                }
            }
        }
    }
    
    // Overlaps between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                if (cols.count(c) || diag1.count(r - c)) {
                    forbidden -= 1;
                } else {
                    forbidden -= 0;
                }
            }
        }
    }
    
    // Overlaps between columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                if (rows.count(r) || diag2.count(r + c)) {
                    forbidden -= 1;
                } else {
                    forbidden -= 0;
                }
            }
        }
    }
    
    // Overlaps between columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                if (rows.count(r) || diag1.count(r - c)) {
                    forbidden -= 1;
                } else {
                    forbidden -= 0;
                }
            }
        }
    }
    
    // Overlaps between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d2 - d1) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                if (rows.count(r) || cols.count(c)) {
                    forbidden -= 1;
                } else {
                    forbidden -= 0;
                }
            }
        }
    }
    
    ll total_squares = n * n;
    ll safe_squares = total_squares - forbidden;
    
    cout << safe_squares << "\n";
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cout.precision(12);
    int NT = 1;
    while(NT--) solve();
    return 0;
}
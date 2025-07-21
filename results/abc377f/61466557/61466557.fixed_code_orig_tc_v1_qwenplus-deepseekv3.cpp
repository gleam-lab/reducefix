#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> queens(m);
    for (auto &[a, b] : queens) {
        cin >> a >> b;
    }
    
    unordered_set<ll> rows, cols, diag1, diag2;
    for (auto [a, b] : queens) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size(); // Subtract overlaps
    
    // Diagonals (i - j = d)
    for (ll d : diag1) {
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(n, n + d);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        unsafe += cnt;
        
        // Subtract overlaps with rows and columns
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                unsafe--;
            }
        }
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                unsafe--;
            }
        }
        // Add back overlaps subtracted twice (rows and cols intersection)
        for (ll r : rows) {
            if (cols.count(r - d)) {
                unsafe++;
            }
        }
    }
    
    // Anti-diagonals (i + j = d)
    for (ll d : diag2) {
        ll i_min = max(1LL, d - n);
        ll i_max = min(n, d - 1);
        if (i_min > i_max) continue;
        ll cnt = i_max - i_min + 1;
        unsafe += cnt;
        
        // Subtract overlaps with rows and columns
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                unsafe--;
            }
        }
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                unsafe--;
            }
        }
        // Add back overlaps subtracted twice (rows and cols intersection)
        for (ll r : rows) {
            if (cols.count(d - r)) {
                unsafe++;
            }
        }
    }
    
    // Subtract overlaps between diagonals and anti-diagonals
    unordered_set<pll> intersections;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && 1 <= i && i <= n && 1 <= j && j <= n) {
                intersections.insert({i, j});
            }
        }
    }
    unsafe -= intersections.size();
    
    // Add back squares that are in queens' positions (they are already counted in rows/cols/diags)
    unsafe += m;
    
    ll total_safe = n * n - unsafe;
    cout << max(total_safe, 0LL) << endl;
    
    return 0;
}
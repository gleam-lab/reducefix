#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> queens(m);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        queens[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = n * n;
    
    // Subtract squares covered by rows and columns
    ll row_cnt = rows.size();
    ll col_cnt = cols.size();
    total -= row_cnt * n;
    total -= col_cnt * n;
    total += row_cnt * col_cnt;
    
    // Subtract squares covered by diagonals (i - j)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        total -= cnt;
        
        // Add back intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n) {
                intersections++;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (1 <= r && r <= n) {
                intersections++;
            }
        }
        // Subtract the overlaps counted twice
        for (auto r : rows) {
            ll c = r - d;
            if (1 <= c && c <= n && cols.count(c)) {
                intersections--;
            }
        }
        total += intersections;
    }
    
    // Subtract squares covered by anti-diagonals (i + j)
    for (auto d : diag2) {
        ll cnt;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - d + 1;
        }
        total -= cnt;
        
        // Add back intersections with rows and columns
        ll intersections = 0;
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n) {
                intersections++;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (1 <= r && r <= n) {
                intersections++;
            }
        }
        // Subtract the overlaps counted twice
        for (auto r : rows) {
            ll c = d - r;
            if (1 <= c && c <= n && cols.count(c)) {
                intersections--;
            }
        }
        total += intersections;
    }
    
    // Add back intersections between diagonals and anti-diagonals that were subtracted twice
    set<pair<ll, ll>> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && 1 <= i && i <= n && 1 <= j && j <= n) {
                intersections.insert({i, j});
            }
        }
    }
    total += intersections.size();
    
    // Subtract the squares occupied by existing queens
    total -= m;
    
    cout << max(total, 0LL) << endl;
    
    return 0;
}
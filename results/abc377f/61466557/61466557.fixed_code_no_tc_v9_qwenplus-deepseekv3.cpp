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
    for (int i = 0; i < m; ++i) {
        cin >> queens[i].first >> queens[i].second;
    }
    
    set<ll> rows, cols, diag1, diag2;
    for (auto [a, b] : queens) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll total = n * n;
    ll attacked = 0;
    
    // Attacked by rows and columns
    ll row_attacked = rows.size() * n;
    ll col_attacked = cols.size() * n;
    ll row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (rows.count(r) && cols.count(c)) {
                row_col_intersect++;
            }
        }
    }
    attacked += row_attacked + col_attacked - row_col_intersect;
    
    // Attacked by diagonals (i - j)
    for (auto d : diag1) {
        ll cnt = 0;
        if (d >= 0) {
            cnt = n - d;
        } else {
            cnt = n + d;
        }
        attacked += cnt;
        
        // Subtract intersections with rows and cols
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n && cols.count(c)) {
                attacked--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n && rows.count(r)) {
                attacked--;
            }
        }
    }
    
    // Attacked by diagonals (i + j)
    for (auto d : diag2) {
        ll cnt = 0;
        if (d <= n + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * n - (d - 1);
        }
        attacked += cnt;
        
        // Subtract intersections with rows and cols
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n && cols.count(c)) {
                attacked--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n && rows.count(r)) {
                attacked--;
            }
        }
    }
    
    // Subtract intersections between diag1 and diag2
    set<pll> diag_intersect;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll i = (d1 + d2) / 2;
            ll j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && i >= 1 && i <= n && j >= 1 && j <= n) {
                diag_intersect.insert({i, j});
            }
        }
    }
    attacked -= diag_intersect.size();
    
    // Add back squares that are under attack by both diag1 and diag2 and rows or cols
    for (auto [i, j] : diag_intersect) {
        if (rows.count(i) || cols.count(j)) {
            attacked++;
        }
    }
    
    ll safe = total - attacked + m; // Add back the queens' positions since they are not empty
    cout << safe << endl;
    
    return 0;
}
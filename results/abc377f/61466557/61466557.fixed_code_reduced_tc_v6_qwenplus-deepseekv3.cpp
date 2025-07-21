#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<pll> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }
    
    set<ll> rows, cols, diag1, diag2;
    for (auto &[a, b] : q) {
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i - j = d)
    for (auto &d : diag1) {
        ll i_min, j_min, i_max, j_max;
        if (d >= 0) {
            i_min = 1 + d;
            j_min = 1;
            i_max = n;
            j_max = n - d;
        } else {
            i_min = 1;
            j_min = 1 - d;
            i_max = n + d;
            j_max = n;
        }
        ll cnt = min(i_max - i_min + 1, j_max - j_min + 1);
        if (cnt <= 0) continue;
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        ll intersect_rows_cols = 0;
        for (auto &r : rows) {
            ll j = r - d;
            if (j >= 1 && j <= n) {
                intersect_rows_cols++;
            }
        }
        for (auto &c : cols) {
            ll i = c + d;
            if (i >= 1 && i <= n) {
                intersect_rows_cols++;
            }
        }
        
        // Subtract intersections with rows and columns, then add back those counted twice
        set<pll> intersections;
        for (auto &r : rows) {
            ll j = r - d;
            if (j >= 1 && j <= n) {
                intersections.insert({r, j});
            }
        }
        for (auto &c : cols) {
            ll i = c + d;
            if (i >= 1 && i <= n) {
                intersections.insert({i, c});
            }
        }
        unsafe -= intersections.size();
    }
    
    // Anti-diagonals (i + j = d)
    for (auto &d : diag2) {
        ll i_min, j_min, i_max, j_max;
        if (d <= n + 1) {
            i_min = 1;
            j_min = d - 1;
            i_max = d - 1;
            j_max = 1;
        } else {
            i_min = d - n;
            j_min = n;
            i_max = n;
            j_max = d - n;
        }
        ll cnt = min(i_max - i_min + 1, j_min - j_max + 1);
        if (cnt <= 0) cnt = 0;
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        set<pll> intersections;
        for (auto &r : rows) {
            ll j = d - r;
            if (j >= 1 && j <= n) {
                intersections.insert({r, j});
            }
        }
        for (auto &c : cols) {
            ll i = d - c;
            if (i >= 1 && i <= n) {
                intersections.insert({i, c});
            }
        }
        unsafe -= intersections.size();
        
        // Subtract intersections with diagonals (i - j = d1)
        for (auto &d1 : diag1) {
            ll i = (d + d1) / 2;
            ll j = (d - d1) / 2;
            if ((d + d1) % 2 == 0 && (d - d1) % 2 == 0 && i >= 1 && i <= n && j >= 1 && j <= n) {
                intersections.insert({i, j});
            }
        }
        unsafe += intersections.size();
    }
    
    // Total safe squares
    ll total = n * n;
    ll safe = total - unsafe + m; // Adding m because the existing pieces were subtracted but they are not empty
    cout << safe << endl;
    
    return 0;
}
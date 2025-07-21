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
    set<ll> rows, cols, d1, d2;
    for (int i = 0; i < m; ++i) {
        cin >> queens[i].first >> queens[i].second;
        rows.insert(queens[i].first);
        cols.insert(queens[i].second);
        d1.insert(queens[i].first - queens[i].second);
        d2.insert(queens[i].first + queens[i].second);
    }
    
    ll unsafe = 0;
    
    // Add rows and columns
    unsafe += rows.size() * n;
    unsafe += cols.size() * n;
    unsafe -= rows.size() * cols.size();
    
    // Add diagonals of type i - j = d (d1)
    for (auto d : d1) {
        ll length = n - abs(d);
        unsafe += length;
    }
    
    // Add diagonals of type i + j = d (d2)
    for (auto d : d2) {
        ll length;
        if (d <= n + 1) {
            length = d - 1;
        } else {
            length = 2 * n - d + 1;
        }
        unsafe += length;
    }
    
    // Subtract intersections between rows and d1 diagonals
    for (auto d : d1) {
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= n) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between columns and d1 diagonals
    for (auto d : d1) {
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= n) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between rows and d2 diagonals
    for (auto d : d2) {
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= n) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between columns and d2 diagonals
    for (auto d : d2) {
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= n) {
                unsafe--;
            }
        }
    }
    
    // Subtract intersections between d1 and d2 diagonals
    for (auto d1_val : d1) {
        for (auto d2_val : d2) {
            if ((d2_val + d1_val) % 2 != 0) continue;
            ll r = (d2_val + d1_val) / 2;
            ll c = (d2_val - d1_val) / 2;
            if (r >= 1 && r <= n && c >= 1 && c <= n) {
                unsafe--;
            }
        }
    }
    
    // Add triple intersections (rows, columns, and diagonals)
    // which were subtracted multiple times
    set<pll> queen_set(queens.begin(), queens.end());
    for (auto queen : queens) {
        ll r = queen.first;
        ll c = queen.second;
        if (rows.count(r) && cols.count(c) && d1.count(r - c) && d2.count(r + c)) {
            unsafe += 3;
        }
    }
    
    // Total safe squares
    ll total = n * n;
    ll safe = total - unsafe;
    
    // Subtract the squares already occupied by queens
    safe -= m;
    safe += queen_set.size();
    
    cout << safe << endl;
    
    return 0;
}
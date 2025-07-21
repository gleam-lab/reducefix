#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> queens(M);
    set<ll> rows, cols, diag1, diag2;
    for (ll i = 0; i < M; ++i) {
        cin >> queens[i].first >> queens[i].second;
        ll a = queens[i].first;
        ll b = queens[i].second;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    // Calculate total unsafe squares
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // squares counted twice
    
    // Diagonals (i - j = d)
    for (auto d : diag1) {
        ll cnt;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = c + d;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
        
        // Add back intersections between rows and columns (already subtracted twice)
        for (auto r : rows) {
            ll c = r - d;
            if (c >= 1 && c <= N && cols.count(c)) {
                unsafe++;
            }
        }
    }
    
    // Diagonals (i + j = d)
    for (auto d : diag2) {
        ll cnt;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
        
        // Subtract intersections with rows and columns
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                unsafe--;
            }
        }
        for (auto c : cols) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                unsafe--;
            }
        }
        
        // Add back intersections between rows and columns (already subtracted twice)
        for (auto r : rows) {
            ll c = d - r;
            if (c >= 1 && c <= N && cols.count(c)) {
                unsafe++;
            }
        }
    }
    
    // Subtract intersections between diag1 and diag2
    set<pair<ll, ll>> intersections;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            ll x = (d1 + d2) / 2;
            ll y = (d2 - d1) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                intersections.insert({x, y});
            }
        }
    }
    unsafe -= intersections.size();
    
    // Add back intersections that are already in rows or cols
    for (auto p : intersections) {
        if (rows.count(p.first) || cols.count(p.second)) {
            unsafe++;
        }
    }
    
    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe;
    
    // Subtract the squares already occupied by queens
    safe -= M;
    
    // Ensure safe is non-negative
    safe = max(safe, 0LL);
    
    cout << safe << endl;
    
    return 0;
}
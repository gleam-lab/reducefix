#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    set<pair<ll, ll>> pieces;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
        pieces.insert({a, b});
    }
    
    ll unsafe = 0;
    
    // Squares attacked by rows
    unsafe += rows.size() * N;
    
    // Squares attacked by cols
    unsafe += cols.size() * N;
    
    // Squares attacked by diag1 (i - j = constant c)
    for (ll c : diag1) {
        ll min_i = max(1LL, 1 + c);
        ll max_i = min(N, N + c);
        if (max_i < min_i) continue;
        unsafe += (max_i - min_i + 1);
    }
    
    // Squares attacked by diag2 (i + j = constant c)
    for (ll c : diag2) {
        ll min_i = max(1LL, c - N);
        ll max_i = min(N, c - 1);
        if (max_i < min_i) continue;
        unsafe += (max_i - min_i + 1);
    }
    
    // Subtract intersections between rows and cols (i.e., squares (r, c) where r is in rows and c is in cols)
    for (ll r : rows) {
        for (ll c : cols) {
            if (pieces.count({r, c})) continue;
            unsafe -= 1;
        }
    }
    
    // Subtract intersections between rows and diag1
    for (ll r : rows) {
        for (ll c_d1 : diag1) {
            ll j = r - c_d1;
            if (j < 1 || j > N) continue;
            if (pieces.count({r, j})) continue;
            unsafe -= 1;
        }
    }
    
    // Subtract intersections between rows and diag2
    for (ll r : rows) {
        for (ll c_d2 : diag2) {
            ll j = c_d2 - r;
            if (j < 1 || j > N) continue;
            if (pieces.count({r, j})) continue;
            unsafe -= 1;
        }
    }
    
    // Subtract intersections between cols and diag1
    for (ll c : cols) {
        for (ll c_d1 : diag1) {
            ll i = c + c_d1;
            if (i < 1 || i > N) continue;
            if (pieces.count({i, c})) continue;
            unsafe -= 1;
        }
    }
    
    // Subtract intersections between cols and diag2
    for (ll c : cols) {
        for (ll c_d2 : diag2) {
            ll i = c_d2 - c;
            if (i < 1 || i > N) continue;
            if (pieces.count({i, c})) continue;
            unsafe -= 1;
        }
    }
    
    // Subtract intersections between diag1 and diag2
    for (ll c_d1 : diag1) {
        for (ll c_d2 : diag2) {
            if ((c_d1 + c_d2) % 2 != 0) continue;
            ll i = (c_d1 + c_d2) / 2;
            ll j = (c_d2 - c_d1) / 2;
            if (i < 1 || i > N || j < 1 || j > N) continue;
            if (pieces.count({i, j})) continue;
            unsafe -= 1;
        }
    }
    
    // Add back the squares that are occupied by existing pieces (since they were subtracted multiple times)
    unsafe += M;
    
    ll total = N * N;
    ll ans = total - unsafe;
    
    cout << ans << "\n";
    
    return 0;
}
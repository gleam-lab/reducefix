#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    ll total_unsafe = 0;
    
    // Calculate unsafe squares due to rows and columns
    total_unsafe += unsafe_rows * N;
    total_unsafe += unsafe_cols * N;
    total_unsafe -= unsafe_rows * unsafe_cols; // subtract the intersections
    
    // Calculate unsafe squares due to diagonals (i-j)
    for (auto d : diag1) {
        ll r_start, c_start;
        if (d >= 0) {
            r_start = 1 + d;
            c_start = 1;
        } else {
            r_start = 1;
            c_start = 1 - d;
        }
        ll cnt = min(N - r_start + 1, N - c_start + 1);
        total_unsafe += cnt;
    }
    
    // Calculate unsafe squares due to diagonals (i+j)
    for (auto d : diag2) {
        ll r_start, c_start;
        if (d <= N + 1) {
            r_start = 1;
            c_start = d - 1;
        } else {
            r_start = d - N;
            c_start = N;
        }
        ll cnt = min(N - r_start + 1, c_start);
        total_unsafe += cnt;
    }
    
    // Subtract the squares counted multiple times (intersections of diagonals with rows/columns)
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.find(a - b) != diag1.end() || diag2.find(a + b) != diag2.end()) {
                total_unsafe--;
            }
        }
    }
    
    for (auto d : diag1) {
        for (auto a : rows) {
            ll b = a - d;
            if (b >= 1 && b <= N && cols.find(b) != cols.end()) {
                total_unsafe--;
            }
        }
        for (auto b : cols) {
            ll a = b + d;
            if (a >= 1 && a <= N && rows.find(a) != rows.end()) {
                total_unsafe--;
            }
        }
    }
    
    for (auto d : diag2) {
        for (auto a : rows) {
            ll b = d - a;
            if (b >= 1 && b <= N && cols.find(b) != cols.end()) {
                total_unsafe--;
            }
        }
        for (auto b : cols) {
            ll a = d - b;
            if (a >= 1 && a <= N && rows.find(a) != rows.end()) {
                total_unsafe--;
            }
        }
    }
    
    // The total safe squares
    ll total_safe = N * N - total_unsafe;
    
    cout << total_safe << endl;
    
    return 0;
}
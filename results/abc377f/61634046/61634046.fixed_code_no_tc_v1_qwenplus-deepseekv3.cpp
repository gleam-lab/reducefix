#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N, M;
    cin >> N >> M;
    
    unordered_set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i + j)
    for (ll d : diag1) {
        ll start = max(1LL, d - N);
        ll end = min(N, d - 1);
        if (start <= end) {
            unsafe += end - start + 1;
        }
    }
    
    // Diagonals (i - j)
    for (ll d : diag2) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (start_row <= end_row) {
            unsafe += end_row - start_row + 1;
        }
    }
    
    // Intersections between diagonals and rows/columns
    for (ll a : rows) {
        for (ll d : diag1) {
            ll b = d - a;
            if (b >= 1 && b <= N && cols.count(b)) {
                unsafe--;
            }
        }
        for (ll d : diag2) {
            ll b = a - d;
            if (b >= 1 && b <= N && cols.count(b)) {
                unsafe--;
            }
        }
    }
    
    // Intersections between diagonals themselves
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                ll a = (d1 + d2) / 2;
                ll b = (d1 - d2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N) {
                    if (rows.count(a) && cols.count(b)) {
                        unsafe++;
                    }
                }
            }
        }
    }
    
    ll total = N * N;
    ll safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}
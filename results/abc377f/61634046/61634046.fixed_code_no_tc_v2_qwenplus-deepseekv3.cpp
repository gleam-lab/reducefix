#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    int M;
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
    ll row_count = rows.size();
    ll col_count = cols.size();
    unsafe += N * row_count + N * col_count - row_count * col_count;
    
    // Diagonals (a + b)
    ll diag1_count = diag1.size();
    for (ll d : diag1) {
        ll start = max(1LL, d - N);
        ll end = min(N, d - 1);
        if (start > end) continue;
        unsafe += end - start + 1;
    }
    
    // Diagonals (a - b)
    ll diag2_count = diag2.size();
    for (ll d : diag2) {
        ll start_row = max(1LL, 1 + d);
        ll end_row = min(N, N + d);
        if (start_row > end_row) continue;
        unsafe += end_row - start_row + 1;
    }
    
    // Intersections: rows and diag1
    for (ll r : rows) {
        for (ll d : diag1) {
            ll c = d - r;
            if (c >= 1 && c <= N) {
                if (cols.find(c) == cols.end() && diag2.find(r - c) == diag2.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections: rows and diag2
    for (ll r : rows) {
        for (ll d : diag2) {
            ll c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.find(c) == cols.end() && diag1.find(r + c) == diag1.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections: cols and diag1
    for (ll c : cols) {
        for (ll d : diag1) {
            ll r = d - c;
            if (r >= 1 && r <= N) {
                if (rows.find(r) == rows.end() && diag2.find(r - c) == diag2.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections: cols and diag2
    for (ll c : cols) {
        for (ll d : diag2) {
            ll r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.find(r) == rows.end() && diag1.find(r + c) == diag1.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Intersections: diag1 and diag2
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N && (d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (rows.find(r) == rows.end() && cols.find(c) == cols.end()) {
                    unsafe--;
                }
            }
        }
    }
    
    // Total safe squares
    ll total = N * N;
    ll safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}
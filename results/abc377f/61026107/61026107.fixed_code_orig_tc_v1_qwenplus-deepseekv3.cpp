#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
    ll unsafe_diag1 = 0;
    for (auto d : diag1) {
        // The number of squares on the diagonal a - b = d
        ll start_row = max(1LL, 1LL + d);
        ll end_row = min(N, N + d);
        if (start_row > end_row) continue;
        unsafe_diag1 += (end_row - start_row + 1);
    }
    ll unsafe_diag2 = 0;
    for (auto d : diag2) {
        // The number of squares on the diagonal a + b = d
        ll start_row = max(1LL, d - N);
        ll end_row = min(N, d - 1);
        if (start_row > end_row) continue;
        unsafe_diag2 += (end_row - start_row + 1);
    }
    
    ll total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols;
    total_unsafe += unsafe_diag1 + unsafe_diag2;
    
    // Now subtract overlaps between rows/cols and diag1/diag2
    // Also subtract overlaps between diag1 and diag2
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b) || diag2.count(a + b)) {
                total_unsafe--;
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            ll a = (d1 + d2) / 2;
            ll b = (d2 - d1) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                total_unsafe--;
            }
        }
    }
    
    // Also subtract overlaps between rows and diag1/diag2, cols and diag1/diag2
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N && cols.count(b)) {
                total_unsafe--;
            }
        }
        for (auto d : diag2) {
            ll b = d - a;
            if (b >= 1 && b <= N && cols.count(b)) {
                total_unsafe--;
            }
        }
    }
    
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = b + d;
            if (a >= 1 && a <= N && rows.count(a)) {
                total_unsafe--;
            }
        }
        for (auto d : diag2) {
            ll a = d - b;
            if (a >= 1 && a <= N && rows.count(a)) {
                total_unsafe--;
            }
        }
    }
    
    ll total_safe = N * N - total_unsafe;
    
    cout << total_safe << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll N, M;
    cin >> N >> M;
    
    set<ll> rows, cols;
    set<ll> diag1, diag2; // diag1: i - j, diag2: i + j
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    ll unsafe = 0;
    
    // Add rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    // Add diagonals (i - j = d) and anti-diagonals (i + j = s)
    for (ll d : diag1) {
        // Number of (i, j) with i - j = d, 1 <= i, j <= N
        ll i_min = max(1LL, 1 + d);
        ll i_max = min(N, N + d);
        if (i_max >= i_min) {
            unsafe += (i_max - i_min + 1);
        }
    }
    
    for (ll s : diag2) {
        // Number of (i, j) with i + j = s, 1 <= i, j <= N
        ll i_min = max(1LL, s - N);
        ll i_max = min(N, s - 1);
        if (i_max >= i_min) {
            unsafe += (i_max - i_min + 1);
        }
    }
    
    // Subtract overlaps between rows and columns
    unsafe -= rows.size() * cols.size();
    
    // Subtract overlaps between rows and diagonals (i - j = d)
    for (ll d : diag1) {
        // For each row a in rows, if (a - j) = d => j = a - d
        // j must be in [1, N] and not in cols (if any)
        ll cnt = 0;
        for (ll a : rows) {
            ll j = a - d;
            if (1 <= j && j <= N) {
                cnt++;
            }
        }
        unsafe -= cnt;
    }
    
    // Subtract overlaps between rows and anti-diagonals (i + j = s)
    for (ll s : diag2) {
        // For each row a in rows, a + j = s => j = s - a
        ll cnt = 0;
        for (ll a : rows) {
            ll j = s - a;
            if (1 <= j && j <= N) {
                cnt++;
            }
        }
        unsafe -= cnt;
    }
    
    // Subtract overlaps between columns and diagonals (i - j = d)
    for (ll d : diag1) {
        // For each column b in cols, i - b = d => i = b + d
        ll cnt = 0;
        for (ll b : cols) {
            ll i = b + d;
            if (1 <= i && i <= N) {
                cnt++;
            }
        }
        unsafe -= cnt;
    }
    
    // Subtract overlaps between columns and anti-diagonals (i + j = s)
    for (ll s : diag2) {
        // For each column b in cols, i + b = s => i = s - b
        ll cnt = 0;
        for (ll b : cols) {
            ll i = s - b;
            if (1 <= i && i <= N) {
                cnt++;
            }
        }
        unsafe -= cnt;
    }
    
    // Add overlaps between rows, columns, and diagonals or anti-diagonals
    // Here, only need to add overlaps where all three or four conditions meet
    // For each existing piece (a, b), it's counted in all four conditions
    unsafe += M; // Overlap between row, column, diag1, diag2
    
    // The total safe squares
    ll total = N * N - unsafe;
    cout << total << endl;
    
    return 0;
}
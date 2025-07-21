#include <bits/stdc++.h>
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
    
    // Total squares: N^2
    // Safe squares = total - (rows + cols + diag1 + diag2) + intersections
    // Using inclusion-exclusion
    
    // Calculate rows and columns
    ll unsafe_rows = rows.size() * N;
    ll unsafe_cols = cols.size() * N;
    
    // Calculate diag1 (i - j = k)
    ll unsafe_diag1 = 0;
    for (ll k : diag1) {
        // i - j = k
        // i ranges from max(1, 1 + k) to min(N, N + k)
        ll i_low = max(1LL, 1 + k);
        ll i_high = min(N, N + k);
        if (i_low > i_high) continue;
        unsafe_diag1 += (i_high - i_low + 1);
    }
    
    // Calculate diag2 (i + j = k)
    ll unsafe_diag2 = 0;
    for (ll k : diag2) {
        // i + j = k
        // i ranges from max(1, k - N) to min(N, k - 1)
        ll i_low = max(1LL, k - N);
        ll i_high = min(N, k - 1);
        if (i_low > i_high) continue;
        unsafe_diag2 += (i_high - i_low + 1);
    }
    
    // Calculate intersections: rows ∩ cols, rows ∩ diag1, etc.
    // rows ∩ cols: squares (a, b) where a is in rows and b is in cols
    ll unsafe_rows_cols = rows.size() * cols.size();
    
    // rows ∩ diag1: squares (a, j) where a is in rows and j = a - k for some k in diag1
    ll unsafe_rows_diag1 = 0;
    for (ll a : rows) {
        for (ll k : diag1) {
            ll j = a - k;
            if (j >= 1 && j <= N) {
                unsafe_rows_diag1++;
            }
        }
    }
    
    // cols ∩ diag1: squares (i, b) where b is in cols and i = b + k for some k in diag1
    ll unsafe_cols_diag1 = 0;
    for (ll b : cols) {
        for (ll k : diag1) {
            ll i = b + k;
            if (i >= 1 && i <= N) {
                unsafe_cols_diag1++;
            }
        }
    }
    
    // rows ∩ diag2: squares (a, j) where a is in rows and j = k - a for some k in diag2
    ll unsafe_rows_diag2 = 0;
    for (ll a : rows) {
        for (ll k : diag2) {
            ll j = k - a;
            if (j >= 1 && j <= N) {
                unsafe_rows_diag2++;
            }
        }
    }
    
    // cols ∩ diag2: squares (i, b) where b is in cols and i = k - b for some k in diag2
    ll unsafe_cols_diag2 = 0;
    for (ll b : cols) {
        for (ll k : diag2) {
            ll i = k - b;
            if (i >= 1 && i <= N) {
                unsafe_cols_diag2++;
            }
        }
    }
    
    // diag1 ∩ diag2: squares (i, j) where i - j = k1 and i + j = k2
    // => i = (k1 + k2)/2, j = (k2 - k1)/2 must be integers
    ll unsafe_diag1_diag2 = 0;
    for (ll k1 : diag1) {
        for (ll k2 : diag2) {
            if ((k1 + k2) % 2 != 0) continue;
            if ((k2 - k1) % 2 != 0) continue;
            ll i = (k1 + k2) / 2;
            ll j = (k2 - k1) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe_diag1_diag2++;
            }
        }
    }
    
    // Apply inclusion-exclusion principle
    ll total_unsafe = unsafe_rows + unsafe_cols + unsafe_diag1 + unsafe_diag2
                    - (unsafe_rows_cols + unsafe_rows_diag1 + unsafe_rows_diag2 + unsafe_cols_diag1 + unsafe_cols_diag2 + unsafe_diag1_diag2)
                    + (unsafe_rows_cols); // Adjust for higher-order intersections
    
    // The safe squares: N^2 - total_unsafe
    // But we need to ensure that the existing pieces are not counted (they are already occupied)
    ll safe_squares = N * N - total_unsafe - M;
    cout << safe_squares << endl;
    
    return 0;
}
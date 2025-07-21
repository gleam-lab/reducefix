#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<ll> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    ll unsafe_rows = rows.size();
    ll unsafe_cols = cols.size();
    ll unsafe_diag1 = diag1.size();
    ll unsafe_diag2 = diag2.size();
    
    // Total unsafe squares: rows + columns + diagonals - overlaps
    // Overlaps between rows and columns (row,col intersections)
    ll row_col_intersect = unsafe_rows * unsafe_cols;
    
    // Overlaps between rows and diag1: for each row r, diag1 includes r + c = d => c = d - r
    // Need to count (r, c) where c is in cols or diag2 also
    ll row_diag1_intersect = 0;
    for (ll d : diag1) {
        for (ll r : rows) {
            ll c = d - r;
            if (1 <= c && c <= N) {
                row_diag1_intersect++;
            }
        }
    }
    
    // Overlaps between rows and diag2: for each row r, diag2 includes r - c = d => c = r - d
    ll row_diag2_intersect = 0;
    for (ll d : diag2) {
        for (ll r : rows) {
            ll c = r - d;
            if (1 <= c && c <= N) {
                row_diag2_intersect++;
            }
        }
    }
    
    // Overlaps between columns and diag1: for each column c, diag1 includes r + c = d => r = d - c
    ll col_diag1_intersect = 0;
    for (ll d : diag1) {
        for (ll c : cols) {
            ll r = d - c;
            if (1 <= r && r <= N) {
                col_diag1_intersect++;
            }
        }
    }
    
    // Overlaps between columns and diag2: for each column c, diag2 includes r - c = d => r = c + d
    ll col_diag2_intersect = 0;
    for (ll d : diag2) {
        for (ll c : cols) {
            ll r = c + d;
            if (1 <= r && r <= N) {
                col_diag2_intersect++;
            }
        }
    }
    
    // Overlaps between diag1 and diag2: solve r + c = d1 and r - c = d2 => r = (d1 + d2)/2, c = (d1 - d2)/2
    ll diag1_diag2_intersect = 0;
    for (ll d1 : diag1) {
        for (ll d2 : diag2) {
            if ((d1 + d2) % 2 != 0 || (d1 - d2) % 2 != 0) continue;
            ll r = (d1 + d2) / 2;
            ll c = (d1 - d2) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                diag1_diag2_intersect++;
            }
        }
    }
    
    // Total unsafe squares: inclusion-exclusion principle
    ll total_unsafe = unsafe_rows * N + unsafe_cols * N - unsafe_rows * unsafe_cols
                    + unsafe_diag1 * N - row_diag1_intersect - col_diag1_intersect
                    + unsafe_diag2 * N - row_diag2_intersect - col_diag2_intersect
                    + diag1_diag2_intersect;
    
    // Total safe squares
    ll total_safe = N * N - total_unsafe;
    cout << total_safe << endl;
    
    return 0;
}
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
    
    ll unsafe = 0;
    
    // Rows and columns
    unsafe += N * rows.size() + N * cols.size();
    
    // Diagonals: a - b = constant and a + b = constant
    for (auto d : diag1) {
        // Calculate the number of squares in the diagonal a - b = d
        if (d >= 0) {
            unsafe += N - d;
        } else {
            unsafe += N + d;
        }
    }
    
    for (auto s : diag2) {
        // Calculate the number of squares in the diagonal a + b = s
        if (s <= N + 1) {
            unsafe += s - 1;
        } else {
            unsafe += 2 * N - s + 1;
        }
    }
    
    // Overlaps: squares counted multiple times
    // Rows and columns
    ll overlap_rows_cols = rows.size() * cols.size();
    unsafe -= overlap_rows_cols;
    
    // Rows and diagonals (a - b)
    ll overlap_rows_diag1 = 0;
    for (auto a : rows) {
        for (auto d : diag1) {
            ll b = a - d;
            if (b >= 1 && b <= N) {
                overlap_rows_diag1++;
            }
        }
    }
    unsafe -= overlap_rows_diag1;
    
    // Rows and diagonals (a + b)
    ll overlap_rows_diag2 = 0;
    for (auto a : rows) {
        for (auto s : diag2) {
            ll b = s - a;
            if (b >= 1 && b <= N) {
                overlap_rows_diag2++;
            }
        }
    }
    unsafe -= overlap_rows_diag2;
    
    // Columns and diagonals (a - b)
    ll overlap_cols_diag1 = 0;
    for (auto b : cols) {
        for (auto d : diag1) {
            ll a = d + b;
            if (a >= 1 && a <= N) {
                overlap_cols_diag1++;
            }
        }
    }
    unsafe -= overlap_cols_diag1;
    
    // Columns and diagonals (a + b)
    ll overlap_cols_diag2 = 0;
    for (auto b : cols) {
        for (auto s : diag2) {
            ll a = s - b;
            if (a >= 1 && a <= N) {
                overlap_cols_diag2++;
            }
        }
    }
    unsafe -= overlap_cols_diag2;
    
    // Diagonals (a - b) and (a + b)
    ll overlap_diag1_diag2 = 0;
    for (auto d : diag1) {
        for (auto s : diag2) {
            if ((s + d) % 2 != 0) continue;
            ll a = (s + d) / 2;
            ll b = (s - d) / 2;
            if (a >= 1 && a <= N && b >= 1 && b <= N) {
                overlap_diag1_diag2++;
            }
        }
    }
    unsafe -= overlap_diag1_diag2;
    
    // Triple overlaps: row, column, and either diagonal
    ll triple_overlap = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b) || diag2.count(a + b)) {
                triple_overlap++;
            }
        }
    }
    unsafe += triple_overlap;
    
    // Quadruple overlap: row, column, and both diagonals
    ll quadruple_overlap = 0;
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.count(a - b) && diag2.count(a + b)) {
                quadruple_overlap++;
            }
        }
    }
    unsafe -= quadruple_overlap;
    
    // Total safe squares
    ll total_squares = N * N;
    ll safe_squares = total_squares - unsafe;
    
    cout << safe_squares << endl;
    
    return 0;
}
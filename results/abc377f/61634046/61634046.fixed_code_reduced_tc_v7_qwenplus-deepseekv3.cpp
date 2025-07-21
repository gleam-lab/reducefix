#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diags, anti_diags;
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags.insert(a - b);
        anti_diags.insert(a + b);
    }
    
    long long unsafe = 0;
    
    // Rows
    unsafe += N * rows.size();
    
    // Columns
    unsafe += N * cols.size();
    
    // Diagonals (a - b = constant)
    for (const auto &d : diags) {
        long long min_a = max(1LL, 1 + d);
        long long max_a = min(N, N + d);
        if (max_a >= min_a) {
            unsafe += max_a - min_a + 1;
        }
    }
    
    // Anti-diagonals (a + b = constant)
    for (const auto &s : anti_diags) {
        long long min_a = max(1LL, s - N);
        long long max_a = min(N, s - 1);
        if (max_a >= min_a) {
            unsafe += max_a - min_a + 1;
        }
    }
    
    // Overlaps: row and column
    long long row_col = rows.size() * cols.size();
    unsafe -= row_col;
    
    // Overlaps: row and diagonal
    long long row_diag = 0;
    for (const auto &r : rows) {
        for (const auto &d : diags) {
            long long col = r - d;
            if (col >= 1 && col <= N) {
                row_diag++;
            }
        }
    }
    unsafe -= row_diag;
    
    // Overlaps: row and anti-diagonal
    long long row_anti_diag = 0;
    for (const auto &r : rows) {
        for (const auto &s : anti_diags) {
            long long col = s - r;
            if (col >= 1 && col <= N) {
                row_anti_diag++;
            }
        }
    }
    unsafe -= row_anti_diag;
    
    // Overlaps: column and diagonal
    long long col_diag = 0;
    for (const auto &c : cols) {
        for (const auto &d : diags) {
            long long row = c + d;
            if (row >= 1 && row <= N) {
                col_diag++;
            }
        }
    }
    unsafe -= col_diag;
    
    // Overlaps: column and anti-diagonal
    long long col_anti_diag = 0;
    for (const auto &c : cols) {
        for (const auto &s : anti_diags) {
            long long row = s - c;
            if (row >= 1 && row <= N) {
                col_anti_diag++;
            }
        }
    }
    unsafe -= col_anti_diag;
    
    // Overlaps: diagonal and anti-diagonal
    long long diag_anti_diag = 0;
    for (const auto &d : diags) {
        for (const auto &s : anti_diags) {
            long long row = (s + d) / 2;
            long long col = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && row >= 1 && row <= N && col >= 1 && col <= N) {
                diag_anti_diag++;
            }
        }
    }
    unsafe -= diag_anti_diag;
    
    // Overlaps: row, column, diagonal
    long long row_col_diag = 0;
    for (const auto &r : rows) {
        for (const auto &c : cols) {
            if (diags.find(r - c) != diags.end()) {
                row_col_diag++;
            }
        }
    }
    unsafe += row_col_diag;
    
    // Overlaps: row, column, anti-diagonal
    long long row_col_anti_diag = 0;
    for (const auto &r : rows) {
        for (const auto &c : cols) {
            if (anti_diags.find(r + c) != anti_diags.end()) {
                row_col_anti_diag++;
            }
        }
    }
    unsafe += row_col_anti_diag;
    
    // Overlaps: row, diagonal, anti-diagonal
    long long row_diag_anti_diag = 0;
    for (const auto &r : rows) {
        for (const auto &d : diags) {
            long long c = r - d;
            if (c >= 1 && c <= N && anti_diags.find(r + c) != anti_diags.end()) {
                row_diag_anti_diag++;
            }
        }
    }
    unsafe += row_diag_anti_diag;
    
    // Overlaps: column, diagonal, anti-diagonal
    long long col_diag_anti_diag = 0;
    for (const auto &c : cols) {
        for (const auto &d : diags) {
            long long r = c + d;
            if (r >= 1 && r <= N && anti_diags.find(r + c) != anti_diags.end()) {
                col_diag_anti_diag++;
            }
        }
    }
    unsafe += col_diag_anti_diag;
    
    // Overlaps: row, column, diagonal, anti-diagonal
    long long all_four = 0;
    for (const auto &r : rows) {
        for (const auto &c : cols) {
            if (diags.find(r - c) != diags.end() && anti_diags.find(r + c) != anti_diags.end()) {
                all_four++;
            }
        }
    }
    unsafe -= all_four;
    
    long long total_squares = N * N;
    long long safe_squares = total_squares - unsafe;
    
    cout << safe_squares << endl;
    
    return 0;
}
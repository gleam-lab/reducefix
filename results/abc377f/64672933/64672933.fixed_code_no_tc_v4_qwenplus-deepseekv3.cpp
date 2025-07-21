#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    set<i64> rows, cols, diag_sum, diag_diff;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag_sum.insert(a[i] + b[i]);
        diag_diff.insert(a[i] - b[i]);
    }

    i64 total_attacked = 0;
    
    // Rows
    total_attacked += rows.size() * N;
    
    // Columns
    total_attacked += cols.size() * N;
    
    // Diagonals (sum)
    for (auto s : diag_sum) {
        i64 x_min = max(1LL, s - N);
        i64 x_max = min(N, s - 1);
        if (x_max >= x_min) {
            total_attacked += (x_max - x_min + 1);
        }
    }
    
    // Diagonals (difference)
    for (auto d : diag_diff) {
        i64 x_min = max(1LL, 1 + d);
        i64 x_max = min(N, N + d);
        if (x_max >= x_min) {
            total_attacked += (x_max - x_min + 1);
        }
    }
    
    // Intersections: row and column
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag_sum.count(r + c) || diag_diff.count(r - c)) {
                continue; // counted in diagonals
            }
            row_col_intersect++;
        }
    }
    total_attacked -= row_col_intersect;
    
    // Intersections: row and diagonal sum
    i64 row_diag_sum_intersect = 0;
    for (auto r : rows) {
        for (auto s : diag_sum) {
            i64 c = s - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c)) {
                    continue; // counted in row_col_intersect
                }
                row_diag_sum_intersect++;
            }
        }
    }
    total_attacked -= row_diag_sum_intersect;
    
    // Intersections: row and diagonal diff
    i64 row_diag_diff_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag_diff) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.count(c)) {
                    continue; // counted in row_col_intersect
                }
                row_diag_diff_intersect++;
            }
        }
    }
    total_attacked -= row_diag_diff_intersect;
    
    // Intersections: column and diagonal sum
    i64 col_diag_sum_intersect = 0;
    for (auto c : cols) {
        for (auto s : diag_sum) {
            i64 r = s - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r)) {
                    continue; // counted in row_col_intersect
                }
                col_diag_sum_intersect++;
            }
        }
    }
    total_attacked -= col_diag_sum_intersect;
    
    // Intersections: column and diagonal diff
    i64 col_diag_diff_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag_diff) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r)) {
                    continue; // counted in row_col_intersect
                }
                col_diag_diff_intersect++;
            }
        }
    }
    total_attacked -= col_diag_diff_intersect;
    
    // Intersections: all three (row, column, diagonal sum or diff)
    i64 all_three_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag_sum.count(r + c) && diag_diff.count(r - c)) {
                all_three_intersect++;
            }
        }
    }
    total_attacked += all_three_intersect;
    
    // The total safe squares is N*N - total_attacked + M (since existing pieces are already placed and not counted as safe)
    i64 safe_squares = N * N - total_attacked;
    cout << safe_squares << "\n";
    
    return 0;
}
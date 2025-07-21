#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, sum_diags, diff_diags;
    
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        sum_diags.insert(a + b);
        diff_diags.insert(a - b);
    }
    
    i64 total_attacked = 0;
    
    // Rows and columns
    total_attacked += rows.size() * N;
    total_attacked += cols.size() * N;
    
    // Sum diagonals (i + j = k)
    for (i64 k : sum_diags) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max >= x_min) {
            total_attacked += (x_max - x_min + 1);
        }
    }
    
    // Difference diagonals (i - j = k)
    for (i64 k : diff_diags) {
        i64 x_min, x_max;
        if (k >= 0) {
            x_min = 1 + k;
            x_max = N;
        } else {
            x_min = 1;
            x_max = N + k;
        }
        if (x_max >= x_min) {
            total_attacked += (x_max - x_min + 1);
        }
    }
    
    // Overlaps between rows and columns (i.e., squares (a, b) where both a and b are in rows and cols)
    i64 row_col_overlap = 0;
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b)) {
            row_col_overlap++;
        }
    }
    
    // Overlaps between rows and sum diagonals
    i64 row_sum_overlap = 0;
    for (i64 a : rows) {
        for (i64 k : sum_diags) {
            i64 b = k - a;
            if (b >= 1 && b <= N && cols.count(b)) {
                row_sum_overlap++;
            }
        }
    }
    
    // Overlaps between rows and difference diagonals
    i64 row_diff_overlap = 0;
    for (i64 a : rows) {
        for (i64 k : diff_diags) {
            i64 b = a - k;
            if (b >= 1 && b <= N && cols.count(b)) {
                row_diff_overlap++;
            }
        }
    }
    
    // Overlaps between columns and sum diagonals
    i64 col_sum_overlap = 0;
    for (i64 b : cols) {
        for (i64 k : sum_diags) {
            i64 a = k - b;
            if (a >= 1 && a <= N && rows.count(a)) {
                col_sum_overlap++;
            }
        }
    }
    
    // Overlaps between columns and difference diagonals
    i64 col_diff_overlap = 0;
    for (i64 b : cols) {
        for (i64 k : diff_diags) {
            i64 a = k + b;
            if (a >= 1 && a <= N && rows.count(a)) {
                col_diff_overlap++;
            }
        }
    }
    
    // Overlaps between sum and difference diagonals
    i64 sum_diff_overlap = 0;
    for (i64 k1 : sum_diags) {
        for (i64 k2 : diff_diags) {
            if ((k1 + k2) % 2 == 0) {
                i64 a = (k1 + k2) / 2;
                i64 b = (k1 - k2) / 2;
                if (a >= 1 && a <= N && b >= 1 && b <= N && rows.count(a) && cols.count(b)) {
                    sum_diff_overlap++;
                }
            }
        }
    }
    
    // Apply inclusion-exclusion principle
    i64 safe_squares = N * N - total_attacked + row_col_overlap + row_sum_overlap + row_diff_overlap + col_sum_overlap + col_diff_overlap - sum_diff_overlap;
    
    cout << safe_squares << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    unordered_set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 total_threatened = 0;

    // Add all unique rows, columns, diag1, diag2
    total_threatened += rows.size() * N;
    total_threatened += cols.size() * N;

    // For diag1 (i + j = d): number of (i,j) with i + j = d, 1 <= i,j <= N
    for (i64 d : diag1) {
        i64 min_i = max(1LL, d - N);
        i64 max_i = min(N, d - 1);
        if (max_i >= min_i) {
            total_threatened += max_i - min_i + 1;
        }
    }

    // For diag2 (i - j = d): number of (i,j) with i - j = d, 1 <= i,j <= N
    for (i64 d : diag2) {
        i64 min_i = max(1LL, 1 + d);
        i64 max_i = min(N, N + d);
        if (max_i >= min_i) {
            total_threatened += max_i - min_i + 1;
        }
    }

    // Subtract overlaps: squares counted in both rows and cols
    i64 rows_cols_intersect = 0;
    for (i64 r : rows) {
        for (i64 c : cols) {
            rows_cols_intersect++;
        }
    }
    total_threatened -= rows_cols_intersect;

    // Subtract overlaps: squares counted in rows and diag1
    i64 rows_diag1_intersect = 0;
    for (i64 r : rows) {
        for (i64 d : diag1) {
            i64 j = d - r;
            if (j >= 1 && j <= N) {
                rows_diag1_intersect++;
            }
        }
    }
    total_threatened -= rows_diag1_intersect;

    // Subtract overlaps: squares counted in rows and diag2
    i64 rows_diag2_intersect = 0;
    for (i64 r : rows) {
        for (i64 d : diag2) {
            i64 j = r - d;
            if (j >= 1 && j <= N) {
                rows_diag2_intersect++;
            }
        }
    }
    total_threatened -= rows_diag2_intersect;

    // Subtract overlaps: squares counted in cols and diag1
    i64 cols_diag1_intersect = 0;
    for (i64 c : cols) {
        for (i64 d : diag1) {
            i64 i = d - c;
            if (i >= 1 && i <= N) {
                cols_diag1_intersect++;
            }
        }
    }
    total_threatened -= cols_diag1_intersect;

    // Subtract overlaps: squares counted in cols and diag2
    i64 cols_diag2_intersect = 0;
    for (i64 c : cols) {
        for (i64 d : diag2) {
            i64 i = c + d;
            if (i >= 1 && i <= N) {
                cols_diag2_intersect++;
            }
        }
    }
    total_threatened -= cols_diag2_intersect;

    // Add back overlaps counted in rows, cols, and diag1 or diag2
    i64 rows_cols_diag1_intersect = 0;
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (diag1.find(r + c) != diag1.end()) {
                rows_cols_diag1_intersect++;
            }
        }
    }
    total_threatened += rows_cols_diag1_intersect;

    i64 rows_cols_diag2_intersect = 0;
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (diag2.find(r - c) != diag2.end()) {
                rows_cols_diag2_intersect++;
            }
        }
    }
    total_threatened += rows_cols_diag2_intersect;

    // Subtract the M pieces themselves since they are occupied
    total_threatened -= M;

    // The answer is total squares (N*N) minus threatened squares minus occupied squares (M)
    // But since occupied squares are already included in threatened squares, we subtract M once more
    i64 safe_squares = N * N - total_threatened - M;
    cout << safe_squares << "\n";

    return 0;
}
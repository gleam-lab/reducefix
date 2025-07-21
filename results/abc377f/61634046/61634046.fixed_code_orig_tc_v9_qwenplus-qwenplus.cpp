#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_M = 2010;

int N, M;

set<int> rows, cols;
set<int> diag1, diag2; // diag1: i - j, diag2: i + j

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    // Total number of squares not attacked by any piece
    // Total squares = N * N
    // Subtract:
    // - Number of squares in attacked rows: rows.size() * N
    // - Number of squares in attacked columns: cols.size() * N
    // - Number of squares in attacked diagonals diag1: diag1.size() * N
    // - Number of squares in attacked diagonals diag2: diag2.size() * N
    // But we have overlaps, so we use inclusion-exclusion principle

    int total = N * N;
    int attack_by_rows = rows.size() * N;
    int attack_by_cols = cols.size() * N;
    int attack_by_diag1 = diag1.size() * N;
    int attack_by_diag2 = diag2.size() * N;

    // Overlap between rows and columns
    int overlap_row_col = rows.size() * cols.size();

    // Overlap between rows and diag1: for each row r, diag d = r - b => b = r - d
    // So for each row r and diag d in diag1, square (r, r-d) must be valid (1 <= r <= N, 1 <= r-d <= N)
    // => max(r - N, -(N-1)) <= d <= min(r - 1, N - 1)
    // But this is hard to compute directly. Instead, for each row r, the number of diag1 intersections is at most 2N.
    // So instead, for each row r, count how many diag1 values intersect that row.

    // Similarly for other overlaps

    // To avoid O(M^2), precompute all intersections using sets and math.

    // Helper function to count diag1 values that pass through row r
    auto count_diag1_in_row = [&](int r) {
        int cnt = 0;
        for (int d : diag1) {
            int c = r - d;
            if (1 <= c && c <= N)
                ++cnt;
        }
        return cnt;
    };

    // Helper function to count diag2 values that pass through row r
    auto count_diag2_in_row = [&](int r) {
        int cnt = 0;
        for (int s : diag2) {
            int c = s - r;
            if (1 <= c && c <= N)
                ++cnt;
        }
        return cnt;
    };

    // Helper function to count diag1 values that pass through column c
    auto count_diag1_in_col = [&](int c) {
        int cnt = 0;
        for (int d : diag1) {
            int r = d + c;
            if (1 <= r && r <= N)
                ++cnt;
        }
        return cnt;
    };

    // Helper function to count diag2 values that pass through column c
    auto count_diag2_in_col = [&](int c) {
        int cnt = 0;
        for (int s : diag2) {
            int r = s - c;
            if (1 <= r && r <= N)
                ++cnt;
        }
        return cnt;
    };

    // Count overlaps between row and diag1
    int overlap_row_diag1 = 0;
    for (int r : rows)
        overlap_row_diag1 += count_diag1_in_row(r);

    // Count overlaps between row and diag2
    int overlap_row_diag2 = 0;
    for (int r : rows)
        overlap_row_diag2 += count_diag2_in_row(r);

    // Count overlaps between col and diag1
    int overlap_col_diag1 = 0;
    for (int c : cols)
        overlap_col_diag1 += count_diag1_in_col(c);

    // Count overlaps between col and diag2
    int overlap_col_diag2 = 0;
    for (int c : cols)
        overlap_col_diag2 += count_diag2_in_col(c);

    // Count overlaps between diag1 and diag2
    int overlap_diag1_diag2 = 0;
    for (int d1 : diag1) {
        for (int s : diag2) {
            int r = (s + d1) / 2;
            int c = (s - d1) / 2;
            if ((s + d1) % 2 == 0 && 1 <= r && r <= N && 1 <= c && c <= N)
                ++overlap_diag1_diag2;
        }
    }

    // Three-way overlaps
    int overlap_row_col_diag1 = 0;
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(r - c))
                ++overlap_row_col_diag1;
        }
    }

    int overlap_row_col_diag2 = 0;
    for (int r : rows) {
        for (int c : cols) {
            if (diag2.count(r + c))
                ++overlap_row_col_diag2;
        }
    }

    int overlap_row_diag1_diag2 = 0;
    for (int r : rows) {
        for (int d1 : diag1) {
            int c = r - d1;
            if (1 <= c && c <= N && diag2.count(r + c))
                ++overlap_row_diag1_diag2;
        }
    }

    int overlap_col_diag1_diag2 = 0;
    for (int c : cols) {
        for (int d1 : diag1) {
            int r = d1 + c;
            if (1 <= r && r <= N && diag2.count(r + c))
                ++overlap_col_diag1_diag2;
        }
    }

    // Four-way overlap
    int overlap_all = 0;
    for (int r : rows) {
        for (int c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c))
                ++overlap_all;
        }
    }

    // Inclusion-Exclusion
    int attacked = attack_by_rows + attack_by_cols + attack_by_diag1 + attack_by_diag2
                 - overlap_row_col - overlap_row_diag1 - overlap_row_diag2
                 - overlap_col_diag1 - overlap_col_diag2 - overlap_diag1_diag2
                 + overlap_row_col_diag1 + overlap_row_col_diag2 + overlap_row_diag1_diag2 + overlap_col_diag1_diag2
                 - overlap_all;

    // Subtract attacked squares from total
    int answer = total - attacked;

    cout << answer << endl;

    return 0;
}
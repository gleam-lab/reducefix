#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diags1, diags2;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a + b);
        diags2.insert(a - b);
    }

    i64 total_threatened = 0;

    // Rows and columns
    i64 unique_rows = rows.size();
    i64 unique_cols = cols.size();
    total_threatened += unique_rows * N + unique_cols * N - unique_rows * unique_cols;

    // Diagonals (i+j = constant)
    i64 unique_diags1 = diags1.size();
    for (i64 d : diags1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        i64 count = max_x - min_x + 1;
        total_threatened += count;
    }

    // Anti-diagonals (i-j = constant)
    i64 unique_diags2 = diags2.size();
    for (i64 d : diags2) {
        i64 min_x = max(1LL, 1 - d);
        i64 max_x = min(N, N - d);
        i64 count = max_x - min_x + 1;
        total_threatened += count;
    }

    // Overlaps between diagonals and anti-diagonals
    for (i64 d1 : diags1) {
        for (i64 d2 : diags2) {
            i64 x = (d1 + d2) / 2;
            i64 y = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0) {
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    total_threatened -= 1;
                }
            }
        }
    }

    // Overlaps between rows and diagonals/anti-diagonals
    for (i64 r : rows) {
        for (i64 d1 : diags1) {
            i64 y = d1 - r;
            if (y >= 1 && y <= N) {
                total_threatened -= 1;
            }
        }
        for (i64 d2 : diags2) {
            i64 y = r - d2;
            if (y >= 1 && y <= N) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between columns and diagonals/anti-diagonals
    for (i64 c : cols) {
        for (i64 d1 : diags1) {
            i64 x = d1 - c;
            if (x >= 1 && x <= N) {
                total_threatened -= 1;
            }
        }
        for (i64 d2 : diags2) {
            i64 x = c + d2;
            if (x >= 1 && x <= N) {
                total_threatened -= 1;
            }
        }
    }

    // Overlaps between rows and columns
    i64 row_col_intersect = 0;
    for (i64 r : rows) {
        for (i64 c : cols) {
            if (rows.count(r) && cols.count(c)) {
                row_col_intersect += 1;
            }
        }
    }
    total_threatened += row_col_intersect;

    // Overlaps between all four: row, column, diagonal, anti-diagonal
    for (auto [a, b] : pieces) {
        total_threatened += 1;
    }

    i64 safe_squares = N * N - total_threatened;
    cout << safe_squares << "\n";

    return 0;
}
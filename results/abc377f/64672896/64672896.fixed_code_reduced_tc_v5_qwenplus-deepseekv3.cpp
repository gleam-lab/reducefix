#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diags1, diags2;
    set<pair<i64, i64>> occupied;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a + b);
        diags2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 total = N * N;
    i64 attacked = 0;

    // Rows
    attacked += N * rows.size();
    // Columns
    attacked += N * cols.size();
    // Diagonals (i + j = c)
    for (auto d : diags1) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (max_x < min_x) continue;
        attacked += (max_x - min_x + 1);
    }
    // Anti-diagonals (i - j = c)
    for (auto d : diags2) {
        i64 min_x = max(1LL, 1 + d);
        i64 max_x = min(N, N + d);
        if (max_x < min_x) continue;
        attacked += (max_x - min_x + 1);
    }

    // Inclusion-exclusion for overlaps between rows and columns
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diags1.count(r + c) || diags2.count(r - c)) {
                continue; // handled in diagonal intersections
            }
            row_col_intersect++;
        }
    }
    attacked -= row_col_intersect;

    // Inclusion-exclusion for overlaps between rows and diagonals
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d : diags1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diags2.count(r - c)) {
                    continue;
                }
                row_diag1_intersect++;
            }
        }
    }
    attacked -= row_diag1_intersect;

    i64 row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto d : diags2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diags1.count(r + c)) {
                    continue;
                }
                row_diag2_intersect++;
            }
        }
    }
    attacked -= row_diag2_intersect;

    // Inclusion-exclusion for overlaps between columns and diagonals
    i64 col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto d : diags1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diags2.count(r - c)) {
                    continue;
                }
                col_diag1_intersect++;
            }
        }
    }
    attacked -= col_diag1_intersect;

    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d : diags2) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diags1.count(r + c)) {
                    continue;
                }
                col_diag2_intersect++;
            }
        }
    }
    attacked -= col_diag2_intersect;

    // Inclusion-exclusion for overlaps between diagonals and anti-diagonals
    i64 diag1_diag2_intersect = 0;
    for (auto d1 : diags1) {
        for (auto d2 : diags2) {
            if ((d1 + d2) % 2 != 0) continue;
            i64 r = (d1 + d2) / 2;
            i64 c = (d1 - d2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.count(r) || cols.count(c)) {
                    continue;
                }
                diag1_diag2_intersect++;
            }
        }
    }
    attacked -= diag1_diag2_intersect;

    // Add back the squares that are occupied (since they were subtracted but are not available)
    i64 safe = total - attacked + occupied.size();
    cout << safe << "\n";

    return 0;
}
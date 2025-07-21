#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diags, anti_diags;
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }
    
    i64 unsafe = 0;
    
    // Rows
    unsafe += rows.size() * N;
    
    // Columns
    unsafe += cols.size() * N;
    
    // Diagonals (i + j = constant)
    for (auto d : diags) {
        i64 min_x = max(1LL, d - N);
        i64 max_x = min(N, d - 1);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    
    // Anti-diagonals (i - j = constant)
    for (auto ad : anti_diags) {
        i64 min_x = max(1LL, 1 + ad);
        i64 max_x = min(N, N + ad);
        if (max_x >= min_x) {
            unsafe += (max_x - min_x + 1);
        }
    }
    
    // Overlaps: squares counted in both rows and columns
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) {
                continue; // already counted as a piece
            }
            row_col_intersect++;
        }
    }
    unsafe -= row_col_intersect;
    
    // Overlaps: squares counted in rows and diagonals
    i64 row_diag_intersect = 0;
    for (auto r : rows) {
        for (auto d : diags) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                if (pieces.count({r, c})) {
                    continue;
                }
                row_diag_intersect++;
            }
        }
    }
    unsafe -= row_diag_intersect;
    
    // Overlaps: squares counted in rows and anti-diagonals
    i64 row_anti_diag_intersect = 0;
    for (auto r : rows) {
        for (auto ad : anti_diags) {
            i64 c = r - ad;
            if (c >= 1 && c <= N) {
                if (pieces.count({r, c})) {
                    continue;
                }
                row_anti_diag_intersect++;
            }
        }
    }
    unsafe -= row_anti_diag_intersect;
    
    // Overlaps: squares counted in columns and diagonals
    i64 col_diag_intersect = 0;
    for (auto c : cols) {
        for (auto d : diags) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                if (pieces.count({r, c})) {
                    continue;
                }
                col_diag_intersect++;
            }
        }
    }
    unsafe -= col_diag_intersect;
    
    // Overlaps: squares counted in columns and anti-diagonals
    i64 col_anti_diag_intersect = 0;
    for (auto c : cols) {
        for (auto ad : anti_diags) {
            i64 r = c + ad;
            if (r >= 1 && r <= N) {
                if (pieces.count({r, c})) {
                    continue;
                }
                col_anti_diag_intersect++;
            }
        }
    }
    unsafe -= col_anti_diag_intersect;
    
    // Overlaps: squares counted in diagonals and anti-diagonals
    i64 diag_anti_diag_intersect = 0;
    for (auto d : diags) {
        for (auto ad : anti_diags) {
            if ((d + ad) % 2 != 0) continue;
            i64 r = (d + ad) / 2;
            i64 c = (d - ad) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (pieces.count({r, c})) {
                    continue;
                }
                diag_anti_diag_intersect++;
            }
        }
    }
    unsafe -= diag_anti_diag_intersect;
    
    // Overlaps: squares counted in rows, columns, and diagonals
    i64 row_col_diag_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diags.count(r + c)) {
                row_col_diag_intersect++;
            }
        }
    }
    unsafe += row_col_diag_intersect;
    
    // Overlaps: squares counted in rows, columns, and anti-diagonals
    i64 row_col_anti_diag_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (anti_diags.count(r - c)) {
                row_col_anti_diag_intersect++;
            }
        }
    }
    unsafe += row_col_anti_diag_intersect;
    
    // Overlaps: squares counted in rows, diagonals, and anti-diagonals
    i64 row_diag_anti_diag_intersect = 0;
    for (auto r : rows) {
        for (auto d : diags) {
            i64 c = d - r;
            if (c < 1 || c > N) continue;
            if (pieces.count({r, c})) continue;
            if (anti_diags.count(r - c)) {
                row_diag_anti_diag_intersect++;
            }
        }
    }
    unsafe += row_diag_anti_diag_intersect;
    
    // Overlaps: squares counted in columns, diagonals, and anti-diagonals
    i64 col_diag_anti_diag_intersect = 0;
    for (auto c : cols) {
        for (auto d : diags) {
            i64 r = d - c;
            if (r < 1 || r > N) continue;
            if (pieces.count({r, c})) continue;
            if (anti_diags.count(r - c)) {
                col_diag_anti_diag_intersect++;
            }
        }
    }
    unsafe += col_diag_anti_diag_intersect;
    
    // Overlaps: squares counted in all four
    i64 all_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (pieces.count({r, c})) continue;
            if (diags.count(r + c) && anti_diags.count(r - c)) {
                all_intersect++;
            }
        }
    }
    unsafe -= all_intersect;
    
    // Total safe squares
    i64 total_squares = N * N;
    i64 safe_squares = total_squares - unsafe - M; // subtract existing pieces
    
    cout << max(0LL, safe_squares) << "\n";
    
    return 0;
}
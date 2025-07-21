#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total_attacked = 0;
    
    // Rows and columns
    total_attacked += rows.size() * N;
    total_attacked += cols.size() * N;
    
    // Diagonals (a + b)
    for (auto d : diag1) {
        i64 min_sum = 1 + 1;
        i64 max_sum = N + N;
        if (d < min_sum || d > max_sum) continue;
        i64 cnt = min(d - 1, N) - max(d - N, 1LL) + 1;
        total_attacked += cnt;
    }
    
    // Anti-diagonals (a - b)
    for (auto d : diag2) {
        i64 min_diff = 1 - N;
        i64 max_diff = N - 1;
        if (d < min_diff || d > max_diff) continue;
        i64 cnt = min(N - d, N) - max(1 - d, 1LL) + 1;
        total_attacked += cnt;
    }
    
    // Intersections: row and column
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                row_col_intersect++;
            }
        }
    }
    total_attacked -= row_col_intersect;
    
    // Intersections: row and diagonal (a + b)
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag2.count(r - c)) {
                    row_diag1_intersect++;
                }
            }
        }
    }
    total_attacked -= row_diag1_intersect;
    
    // Intersections: row and anti-diagonal (a - b)
    i64 row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag1.count(r + c)) {
                    row_diag2_intersect++;
                }
            }
        }
    }
    total_attacked -= row_diag2_intersect;
    
    // Intersections: column and diagonal (a + b)
    i64 col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag2.count(r - c)) {
                    col_diag1_intersect++;
                }
            }
        }
    }
    total_attacked -= col_diag1_intersect;
    
    // Intersections: column and anti-diagonal (a - b)
    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag1.count(r + c)) {
                    col_diag2_intersect++;
                }
            }
        }
    }
    total_attacked -= col_diag2_intersect;
    
    // Intersections: diagonal (a + b) and anti-diagonal (a - b)
    i64 diag1_diag2_intersect = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    if (rows.count(r) || cols.count(c)) {
                        diag1_diag2_intersect++;
                    }
                }
            }
        }
    }
    total_attacked -= diag1_diag2_intersect;
    
    // Triple intersections: row, column, and diagonal or anti-diagonal
    i64 triple_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                triple_intersect++;
            }
        }
    }
    total_attacked += triple_intersect;
    
    // Total safe squares = N² - total_attacked + M (since M squares are already occupied)
    i64 safe_squares = N * N - total_attacked + M;
    cout << safe_squares << "\n";
    
    return 0;
}
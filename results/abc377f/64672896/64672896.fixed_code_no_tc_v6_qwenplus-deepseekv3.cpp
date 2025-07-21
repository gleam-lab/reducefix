#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, i64>> pieces(M);
    unordered_set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 threatened = 0;
    
    // Rows
    threatened += rows.size() * N;
    
    // Columns
    threatened += cols.size() * N;
    
    // Diagonals (i + j)
    for (auto d : diag1) {
        i64 min_x_plus_y = max(1LL, d - N);
        i64 max_x_plus_y = min(N, d - 1);
        i64 count = max_x_plus_y - min_x_plus_y + 1;
        threatened += count;
    }
    
    // Anti-diagonals (i - j)
    for (auto d : diag2) {
        i64 min_x_minus_y = max(1LL - N, d);
        i64 max_x_minus_y = min(N - 1LL, d);
        i64 count = N - abs(d);
        threatened += count;
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
    threatened -= row_col_intersect;
    
    // Intersections: row and diagonal1
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                row_diag1_intersect++;
            }
        }
    }
    threatened -= row_diag1_intersect;
    
    // Intersections: row and diagonal2
    i64 row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                row_diag2_intersect++;
            }
        }
    }
    threatened -= row_diag2_intersect;
    
    // Intersections: column and diagonal1
    i64 col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                col_diag1_intersect++;
            }
        }
    }
    threatened -= col_diag1_intersect;
    
    // Intersections: column and diagonal2
    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                col_diag2_intersect++;
            }
        }
    }
    threatened -= col_diag2_intersect;
    
    // Intersections: diagonal1 and diagonal2
    i64 diag1_diag2_intersect = 0;
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    diag1_diag2_intersect++;
                }
            }
        }
    }
    threatened -= diag1_diag2_intersect;
    
    // Triple intersections: row, column, diagonal1
    i64 row_col_diag1 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                row_col_diag1++;
            }
        }
    }
    threatened += row_col_diag1;
    
    // Triple intersections: row, column, diagonal2
    i64 row_col_diag2 = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r - c)) {
                row_col_diag2++;
            }
        }
    }
    threatened += row_col_diag2;
    
    // Triple intersections: row, diagonal1, diagonal2
    i64 row_diag1_diag2 = 0;
    for (auto r : rows) {
        for (auto d1 : diag1) {
            i64 c = d1 - r;
            if (c >= 1 && c <= N && diag2.count(r - c)) {
                row_diag1_diag2++;
            }
        }
    }
    threatened += row_diag1_diag2;
    
    // Triple intersections: column, diagonal1, diagonal2
    i64 col_diag1_diag2 = 0;
    for (auto c : cols) {
        for (auto d1 : diag1) {
            i64 r = d1 - c;
            if (r >= 1 && r <= N && diag2.count(r - c)) {
                col_diag1_diag2++;
            }
        }
    }
    threatened += col_diag1_diag2;
    
    // Quadruple intersections: row, column, diagonal1, diagonal2
    i64 all_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                all_intersect++;
            }
        }
    }
    threatened -= all_intersect;
    
    // Subtract the existing pieces themselves since they are already occupied
    threatened -= M;
    
    i64 total_squares = N * N;
    i64 safe_squares = total_squares - threatened;
    
    cout << safe_squares << "\n";
    
    return 0;
}
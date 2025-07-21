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
    
    i64 row_cnt = rows.size();
    i64 col_cnt = cols.size();
    i64 diag_cnt = diags.size();
    i64 anti_diag_cnt = anti_diags.size();
    
    i64 attacked = 0;
    
    // Rows and columns: row_cnt * N + col_cnt * N - row_cnt * col_cnt
    attacked += row_cnt * N;
    attacked += col_cnt * N;
    attacked -= row_cnt * col_cnt;
    
    // Diagonals and anti-diagonals: count squares in these lines, adjusting for overlaps
    i64 diag_contribution = 0;
    for (i64 d : diags) {
        i64 min_val = max(1LL, d - N);
        i64 max_val = min(N, d - 1);
        if (max_val >= min_val) {
            diag_contribution += (max_val - min_val + 1);
        }
    }
    
    i64 anti_diag_contribution = 0;
    for (i64 d : anti_diags) {
        i64 min_val = max(1LL, 1 - d);
        i64 max_val = min(N, N - d);
        if (max_val >= min_val) {
            anti_diag_contribution += (max_val - min_val + 1);
        }
    }
    
    attacked += diag_contribution + anti_diag_contribution;
    
    // Subtract overlaps between diagonals and anti-diagonals
    set<pair<i64, i64>> intersections;
    for (i64 d : diags) {
        for (i64 ad : anti_diags) {
            i64 x = (d + ad) / 2;
            i64 y = (d - ad) / 2;
            if ((d + ad) % 2 == 0 && (d - ad) % 2 == 0) {
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    intersections.insert({x, y});
                }
            }
        }
    }
    
    i64 overlap_diag_anti = intersections.size();
    attacked -= overlap_diag_anti;
    
    // Subtract overlaps between rows and diagonals
    i64 row_diag_overlap = 0;
    for (i64 r : rows) {
        for (i64 d : diags) {
            i64 y = d - r;
            if (y >= 1 && y <= N) {
                row_diag_overlap++;
            }
        }
    }
    attacked -= row_diag_overlap;
    
    // Subtract overlaps between rows and anti-diagonals
    i64 row_anti_diag_overlap = 0;
    for (i64 r : rows) {
        for (i64 ad : anti_diags) {
            i64 y = r - ad;
            if (y >= 1 && y <= N) {
                row_anti_diag_overlap++;
            }
        }
    }
    attacked -= row_anti_diag_overlap;
    
    // Subtract overlaps between columns and diagonals
    i64 col_diag_overlap = 0;
    for (i64 c : cols) {
        for (i64 d : diags) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                col_diag_overlap++;
            }
        }
    }
    attacked -= col_diag_overlap;
    
    // Subtract overlaps between columns and anti-diagonals
    i64 col_anti_diag_overlap = 0;
    for (i64 c : cols) {
        for (i64 ad : anti_diags) {
            i64 x = ad + c;
            if (x >= 1 && x <= N) {
                col_anti_diag_overlap++;
            }
        }
    }
    attacked -= col_anti_diag_overlap;
    
    // Add back overlaps that were subtracted multiple times
    // Squares at the intersection of row, column, diagonal, and anti-diagonal
    i64 multi_overlap = 0;
    for (auto [a, b] : pieces) {
        if (rows.count(a) && cols.count(b) && diags.count(a + b) && anti_diags.count(a - b)) {
            multi_overlap++;
        }
    }
    attacked += multi_overlap;
    
    // The total safe squares is N*N - attacked + M (since the existing pieces are already placed)
    i64 safe = N * N - attacked + M;
    
    cout << safe << "\n";
    
    return 0;
}
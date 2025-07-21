#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    
    i64 attacked = 0;
    
    // Rows and columns
    i64 row_attacks = rows.size() * N;
    i64 col_attacks = cols.size() * N;
    i64 row_col_intersection = rows.size() * cols.size();
    
    // Diagonals (i + j = c)
    i64 diag1_attacks = 0;
    for (i64 c : diag1) {
        i64 min_x_plus_y = 1 + 1;
        i64 max_x_plus_y = N + N;
        i64 lower = max(c - N, 1LL);
        i64 upper = min(c - 1, N);
        if (lower > upper) continue;
        diag1_attacks += upper - lower + 1;
    }
    
    // Diagonals (i - j = c)
    i64 diag2_attacks = 0;
    for (i64 c : diag2) {
        i64 min_x_minus_y = 1 - N;
        i64 max_x_minus_y = N - 1;
        i64 lower = max(1LL, 1 + c);
        i64 upper = min(N, N + c);
        if (lower > upper) continue;
        diag2_attacks += upper - lower + 1;
    }
    
    // Intersections between rows and diag1
    i64 row_diag1_intersection = 0;
    for (i64 r : rows) {
        for (i64 c : diag1) {
            i64 y = c - r;
            if (y >= 1 && y <= N) {
                if (cols.count(y)) continue; // Avoid double-counting
                row_diag1_intersection++;
            }
        }
    }
    
    // Intersections between rows and diag2
    i64 row_diag2_intersection = 0;
    for (i64 r : rows) {
        for (i64 c : diag2) {
            i64 y = r - c;
            if (y >= 1 && y <= N) {
                if (cols.count(y)) continue; // Avoid double-counting
                row_diag2_intersection++;
            }
        }
    }
    
    // Intersections between cols and diag1
    i64 col_diag1_intersection = 0;
    for (i64 c : cols) {
        for (i64 d : diag1) {
            i64 x = d - c;
            if (x >= 1 && x <= N) {
                if (rows.count(x)) continue; // Avoid double-counting
                col_diag1_intersection++;
            }
        }
    }
    
    // Intersections between cols and diag2
    i64 col_diag2_intersection = 0;
    for (i64 c : cols) {
        for (i64 d : diag2) {
            i64 x = c + d;
            if (x >= 1 && x <= N) {
                if (rows.count(x)) continue; // Avoid double-counting
                col_diag2_intersection++;
            }
        }
    }
    
    // Intersections between diag1 and diag2
    i64 diag1_diag2_intersection = 0;
    for (i64 c1 : diag1) {
        for (i64 c2 : diag2) {
            if ((c1 + c2) % 2 != 0) continue;
            i64 x = (c1 + c2) / 2;
            i64 y = (c1 - c2) / 2;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                if (rows.count(x) || cols.count(y)) continue;
                diag1_diag2_intersection++;
            }
        }
    }
    
    // Total attacked squares
    attacked = row_attacks + col_attacks + diag1_attacks + diag2_attacks
               - row_col_intersection
               - row_diag1_intersection - row_diag2_intersection
               - col_diag1_intersection - col_diag2_intersection
               - diag1_diag2_intersection;
    
    // Subtract the original M pieces since they were counted multiple times
    attacked -= M;
    
    i64 safe = N * N - attacked;
    cout << safe << "\n";
    return 0;
}
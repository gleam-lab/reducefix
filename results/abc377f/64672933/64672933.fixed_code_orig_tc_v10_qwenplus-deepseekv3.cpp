#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }

    i64 attacked = 0;
    
    // Rows and columns: each row or column not already counted contributes N squares
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    
    // Diagonals: for each unique a+b or a-b, the number of squares is min(N, ...)
    for (auto d : diag1) {
        i64 x_min = max(1LL, d - N);
        i64 x_max = min(N, d - 1);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }
    for (auto d : diag2) {
        i64 x_min = max(1LL, 1 - d);
        i64 x_max = min(N, N - d);
        if (x_max >= x_min) {
            attacked += x_max - x_min + 1;
        }
    }
    
    // Now, subtract intersections between rows and columns, rows and diag1, etc.
    // We need to count squares that are in (rows AND cols), (rows AND diag1), etc.
    
    // Rows and columns: each (row, col) intersection is one square
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                // This square is counted in both rows and columns, and possibly diagonals
                row_col_intersect++;
            }
        }
    }
    attacked -= row_col_intersect;
    
    // Rows and diag1: for each row 'r' and diag1 'd', if there exists 'c' such that r + c = d
    for (auto r : rows) {
        for (auto d : diag1) {
            i64 c = d - r;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }
    
    // Rows and diag2: for each row 'r' and diag2 'd', if there exists 'c' such that r - c = d
    for (auto r : rows) {
        for (auto d : diag2) {
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                attacked--;
            }
        }
    }
    
    // Columns and diag1: for each column 'c' and diag1 'd', if there exists 'r' such that r + c = d
    for (auto c : cols) {
        for (auto d : diag1) {
            i64 r = d - c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Columns and diag2: for each column 'c' and diag2 'd', if there exists 'r' such that r - c = d
    for (auto c : cols) {
        for (auto d : diag2) {
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                attacked--;
            }
        }
    }
    
    // Diag1 and diag2: for each diag1 'd1' and diag2 'd2', if there exists (r, c) such that r + c = d1 and r - c = d2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                i64 r = (d1 + d2) / 2;
                i64 c = (d1 - d2) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    attacked++;
                }
            }
        }
    }
    
    // Finally, add the squares that are in rows, cols, diag1, and diag2 simultaneously (i.e., the piece positions)
    // Each piece position is subtracted multiple times, so we add back (M) to correct for that.
    attacked += M;
    
    i64 total_squares = N * N;
    i64 safe_squares = total_squares - attacked;
    
    cout << safe_squares << "\n";
    return 0;
}
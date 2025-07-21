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
    set<pair<i64, i64>> occupied;

    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert({a, b});
    }

    i64 total = N * N;
    i64 attacked = 0;

    // Rows
    attacked += rows.size() * N;
    // Columns
    attacked += cols.size() * N;
    // Diagonals (i+j = k)
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max < x_min) continue;
        attacked += (x_max - x_min + 1);
    }
    // Anti-diagonals (i-j = k)
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max < x_min) continue;
        attacked += (x_max - x_min + 1);
    }

    // Subtract intersections counted twice
    // Row and Column
    i64 row_col_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) || diag2.count(r - c)) {
                continue;
            }
            row_col_intersect++;
        }
    }
    attacked -= row_col_intersect;

    // Row and Diag1
    i64 row_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto k : diag1) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag2.count(r - c)) {
                    continue;
                }
                row_diag1_intersect++;
            }
        }
    }
    attacked -= row_diag1_intersect;

    // Row and Diag2
    i64 row_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto k : diag2) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || diag1.count(r + c)) {
                    continue;
                }
                row_diag2_intersect++;
            }
        }
    }
    attacked -= row_diag2_intersect;

    // Column and Diag1
    i64 col_diag1_intersect = 0;
    for (auto c : cols) {
        for (auto k : diag1) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag2.count(r - c)) {
                    continue;
                }
                col_diag1_intersect++;
            }
        }
    }
    attacked -= col_diag1_intersect;

    // Column and Diag2
    i64 col_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto k : diag2) {
            i64 r = k + c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || diag1.count(r + c)) {
                    continue;
                }
                col_diag2_intersect++;
            }
        }
    }
    attacked -= col_diag2_intersect;

    // Diag1 and Diag2
    i64 diag1_diag2_intersect = 0;
    for (auto k1 : diag1) {
        for (auto k2 : diag2) {
            if ((k1 + k2) % 2 != 0) continue;
            i64 r = (k1 + k2) / 2;
            i64 c = (k1 - k2) / 2;
            if (r >= 1 && r <= N && c >= 1 && c <= N) {
                if (rows.count(r) || cols.count(c)) {
                    continue;
                }
                diag1_diag2_intersect++;
            }
        }
    }
    attacked -= diag1_diag2_intersect;

    // Add back triple intersections subtracted too many times
    // Row, Column, and Diag1
    i64 row_col_diag1_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c)) {
                if (diag2.count(r - c)) {
                    continue;
                }
                row_col_diag1_intersect++;
            }
        }
    }
    attacked += row_col_diag1_intersect;

    // Row, Column, and Diag2
    i64 row_col_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag2.count(r - c)) {
                if (diag1.count(r + c)) {
                    continue;
                }
                row_col_diag2_intersect++;
            }
        }
    }
    attacked += row_col_diag2_intersect;

    // Row, Diag1, and Diag2
    i64 row_diag1_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto k1 : diag1) {
            i64 c = k1 - r;
            if (c >= 1 && c <= N) {
                if (cols.count(c) || !diag2.count(r - c)) {
                    continue;
                }
                row_diag1_diag2_intersect++;
            }
        }
    }
    attacked += row_diag1_diag2_intersect;

    // Column, Diag1, and Diag2
    i64 col_diag1_diag2_intersect = 0;
    for (auto c : cols) {
        for (auto k1 : diag1) {
            i64 r = k1 - c;
            if (r >= 1 && r <= N) {
                if (rows.count(r) || !diag2.count(r - c)) {
                    continue;
                }
                col_diag1_diag2_intersect++;
            }
        }
    }
    attacked += col_diag1_diag2_intersect;

    // Subtract quadruple intersections added too many times
    i64 row_col_diag1_diag2_intersect = 0;
    for (auto r : rows) {
        for (auto c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                row_col_diag1_diag2_intersect++;
            }
        }
    }
    attacked -= row_col_diag1_diag2_intersect;

    // The safe squares are total squares minus attacked squares plus occupied squares (since they were subtracted but are already occupied)
    i64 safe = total - attacked + occupied.size();
    cout << safe << "\n";

    return 0;
}
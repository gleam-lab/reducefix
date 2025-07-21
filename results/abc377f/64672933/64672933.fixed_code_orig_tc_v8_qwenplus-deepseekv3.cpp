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
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }

    i64 unsafe = 0;

    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    // Diagonals type 1: a + b = k
    for (auto k : diag1) {
        i64 x_min = max(1LL, k - N);
        i64 x_max = min(N, k - 1);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }

    // Diagonals type 2: a - b = k
    for (auto k : diag2) {
        i64 x_min = max(1LL, 1 + k);
        i64 x_max = min(N, N + k);
        if (x_max >= x_min) {
            unsafe += x_max - x_min + 1;
        }
    }

    // Subtract intersections counted twice
    // Intersection of row and column
    i64 row_col_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && cols.count(p.second)) {
            row_col_intersect++;
        }
    }
    unsafe -= row_col_intersect;

    // Intersection of row and diag1
    i64 row_diag1_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && diag1.count(p.first + p.second)) {
            row_diag1_intersect++;
        }
    }
    unsafe -= row_diag1_intersect;

    // Intersection of row and diag2
    i64 row_diag2_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && diag2.count(p.first - p.second)) {
            row_diag2_intersect++;
        }
    }
    unsafe -= row_diag2_intersect;

    // Intersection of column and diag1
    i64 col_diag1_intersect = 0;
    for (auto p : pieces) {
        if (cols.count(p.second) && diag1.count(p.first + p.second)) {
            col_diag1_intersect++;
        }
    }
    unsafe -= col_diag1_intersect;

    // Intersection of column and diag2
    i64 col_diag2_intersect = 0;
    for (auto p : pieces) {
        if (cols.count(p.second) && diag2.count(p.first - p.second)) {
            col_diag2_intersect++;
        }
    }
    unsafe -= col_diag2_intersect;

    // Intersection of diag1 and diag2
    i64 diag1_diag2_intersect = 0;
    for (auto p : pieces) {
        if (diag1.count(p.first + p.second) && diag2.count(p.first - p.second)) {
            diag1_diag2_intersect++;
        }
    }
    unsafe -= diag1_diag2_intersect;

    // Add back intersections subtracted thrice
    // Intersection of row, column, and diag1
    i64 row_col_diag1_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && cols.count(p.second) && diag1.count(p.first + p.second)) {
            row_col_diag1_intersect++;
        }
    }
    unsafe += row_col_diag1_intersect;

    // Intersection of row, column, and diag2
    i64 row_col_diag2_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && cols.count(p.second) && diag2.count(p.first - p.second)) {
            row_col_diag2_intersect++;
        }
    }
    unsafe += row_col_diag2_intersect;

    // Intersection of row, diag1, and diag2
    i64 row_diag1_diag2_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && diag1.count(p.first + p.second) && diag2.count(p.first - p.second)) {
            row_diag1_diag2_intersect++;
        }
    }
    unsafe += row_diag1_diag2_intersect;

    // Intersection of column, diag1, and diag2
    i64 col_diag1_diag2_intersect = 0;
    for (auto p : pieces) {
        if (cols.count(p.second) && diag1.count(p.first + p.second) && diag2.count(p.first - p.second)) {
            col_diag1_diag2_intersect++;
        }
    }
    unsafe += col_diag1_diag2_intersect;

    // Subtract intersection of all four (row, column, diag1, diag2)
    i64 all_intersect = 0;
    for (auto p : pieces) {
        if (rows.count(p.first) && cols.count(p.second) && diag1.count(p.first + p.second) && diag2.count(p.first - p.second)) {
            all_intersect++;
        }
    }
    unsafe -= all_intersect;

    // Total safe squares
    i64 total = N * N;
    i64 safe = total - unsafe;

    cout << safe << "\n";

    return 0;
}
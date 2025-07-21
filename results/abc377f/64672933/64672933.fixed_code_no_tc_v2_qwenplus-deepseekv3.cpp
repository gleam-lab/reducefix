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

    i64 row_count = rows.size();
    i64 col_count = cols.size();
    i64 diag1_count = diag1.size();
    i64 diag2_count = diag2.size();

    i64 unsafe = 0;
    unsafe += row_count * N;
    unsafe += col_count * N;
    unsafe += diag1_count * N;
    unsafe += diag2_count * N;

    // Subtract overlaps between rows and columns (squares counted twice: once in row, once in column)
    unsafe -= row_count * col_count;
    // Subtract overlaps between rows and diag1
    unsafe -= row_count * diag1_count;
    // Subtract overlaps between rows and diag2
    unsafe -= row_count * diag2_count;
    // Subtract overlaps between columns and diag1
    unsafe -= col_count * diag1_count;
    // Subtract overlaps between columns and diag2
    unsafe -= col_count * diag2_count;
    // Subtract overlaps between diag1 and diag2
    unsafe -= diag1_count * diag2_count;

    // Add back the squares subtracted multiple times in the above subtractions
    // For rows, columns, and diag1: intersection is the squares at (a, b) where a in rows, b in cols, and a + b in diag1
    for (i64 a_val : rows) {
        for (i64 b_val : cols) {
            if (diag1.find(a_val + b_val) != diag1.end()) {
                unsafe += 1;
            }
        }
    }
    // For rows, columns, and diag2: intersection is the squares at (a, b) where a in rows, b in cols, and a - b in diag2
    for (i64 a_val : rows) {
        for (i64 b_val : cols) {
            if (diag2.find(a_val - b_val) != diag2.end()) {
                unsafe += 1;
            }
        }
    }
    // For rows, diag1, and diag2: intersection is the squares at (a, b) where a in rows, a + b in diag1, and a - b in diag2
    for (i64 a_val : rows) {
        for (i64 sum : diag1) {
            i64 b_val = sum - a_val;
            if (b_val >= 1 && b_val <= N && diag2.find(a_val - b_val) != diag2.end()) {
                unsafe += 1;
            }
        }
    }
    // For columns, diag1, and diag2: intersection is the squares at (a, b) where b in cols, a + b in diag1, and a - b in diag2
    for (i64 b_val : cols) {
        for (i64 sum : diag1) {
            i64 a_val = sum - b_val;
            if (a_val >= 1 && a_val <= N && diag2.find(a_val - b_val) != diag2.end()) {
                unsafe += 1;
            }
        }
    }
    // Finally, subtract the squares counted in all four sets (rows, columns, diag1, diag2)
    // These are the positions of the existing pieces
    unsafe -= M;

    i64 total_squares = N * N;
    i64 safe_squares = total_squares - unsafe;
    cout << safe_squares << "\n";

    return 0;
}
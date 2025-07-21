#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols;
    unordered_set<long long> diag1, diag2; // diag1: i-j, diag2: i+j
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    long long total = N * N - M;
    long long unsafe = 0;
    
    unsafe += N * rows.size(); // squares in attacked rows
    unsafe += N * cols.size(); // squares in attacked columns
    
    for (long long d : diag1) {
        long long count = 0;
        if (d >= 0) {
            count = min(N - d, N);
        } else {
            count = min(N, N + d);
        }
        unsafe += count;
    }
    
    for (long long d : diag2) {
        long long count = 0;
        if (d <= N + 1) {
            count = d - 1;
        } else {
            count = 2 * N - d + 1;
        }
        unsafe += count;
    }
    
    // Subtract overlaps between rows and columns
    long long row_col_overlap = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                row_col_overlap++;
            }
        }
    }
    unsafe -= rows.size() * cols.size();
    
    // Subtract overlaps between rows and diagonals
    long long row_diag1_overlap = 0;
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = r - d;
            if (c >= 1 && c <= N) {
                row_diag1_overlap++;
            }
        }
    }
    unsafe -= row_diag1_overlap;
    
    long long row_diag2_overlap = 0;
    for (long long r : rows) {
        for (long long d : diag2) {
            long long c = d - r;
            if (c >= 1 && c <= N) {
                row_diag2_overlap++;
            }
        }
    }
    unsafe -= row_diag2_overlap;
    
    // Subtract overlaps between columns and diagonals
    long long col_diag1_overlap = 0;
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = c + d;
            if (r >= 1 && r <= N) {
                col_diag1_overlap++;
            }
        }
    }
    unsafe -= col_diag1_overlap;
    
    long long col_diag2_overlap = 0;
    for (long long c : cols) {
        for (long long d : diag2) {
            long long r = d - c;
            if (r >= 1 && r <= N) {
                col_diag2_overlap++;
            }
        }
    }
    unsafe -= col_diag2_overlap;
    
    // Add back overlaps between rows, columns, and diagonals (three-way)
    long long triple_overlap = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                triple_overlap++;
            }
        }
    }
    unsafe += triple_overlap;
    
    long long safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}
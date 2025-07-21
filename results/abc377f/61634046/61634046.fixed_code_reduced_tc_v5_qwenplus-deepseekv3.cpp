#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    long long total = N * N;
    long long forbidden = 0;
    
    // Forbidden due to rows
    forbidden += rows.size() * N;
    
    // Forbidden due to columns
    forbidden += cols.size() * N;
    
    // Forbidden due to diagonals (i + j = k)
    for (long long d : diag1) {
        long long min_val = max(1LL, d - N);
        long long max_val = min(N, d - 1);
        if (max_val >= min_val) {
            forbidden += max_val - min_val + 1;
        }
    }
    
    // Forbidden due to anti-diagonals (i - j = k)
    for (long long d : diag2) {
        long long min_i = max(1LL, 1 + d);
        long long max_i = min(N, N + d);
        if (max_i >= min_i) {
            forbidden += max_i - min_i + 1;
        }
    }
    
    // Count intersections: rows and columns
    long long row_col_intersect = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (rows.count(r) && cols.count(c)) {
                row_col_intersect++;
            }
        }
    }
    forbidden -= row_col_intersect;
    
    // Count intersections: rows and diag1
    long long row_diag1_intersect = 0;
    for (long long r : rows) {
        for (long long d : diag1) {
            long long j = d - r;
            if (1 <= j && j <= N && cols.count(j)) {
                row_diag1_intersect++;
            }
        }
    }
    forbidden -= row_diag1_intersect;
    
    // Count intersections: rows and diag2
    long long row_diag2_intersect = 0;
    for (long long r : rows) {
        for (long long d : diag2) {
            long long j = r - d;
            if (1 <= j && j <= N && cols.count(j)) {
                row_diag2_intersect++;
            }
        }
    }
    forbidden -= row_diag2_intersect;
    
    // Count intersections: columns and diag1
    long long col_diag1_intersect = 0;
    for (long long c : cols) {
        for (long long d : diag1) {
            long long i = d - c;
            if (1 <= i && i <= N && rows.count(i)) {
                col_diag1_intersect++;
            }
        }
    }
    forbidden -= col_diag1_intersect;
    
    // Count intersections: columns and diag2
    long long col_diag2_intersect = 0;
    for (long long c : cols) {
        for (long long d : diag2) {
            long long i = c + d;
            if (1 <= i && i <= N && rows.count(i)) {
                col_diag2_intersect++;
            }
        }
    }
    forbidden -= col_diag2_intersect;
    
    // Count intersections: diag1 and diag2
    long long diag1_diag2_intersect = 0;
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long i = (d1 + d2) / 2;
            long long j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && 1 <= i && i <= N && 1 <= j && j <= N && rows.count(i) && cols.count(j)) {
                diag1_diag2_intersect++;
            }
        }
    }
    forbidden += diag1_diag2_intersect;
    
    // Count intersections: rows, columns, and diag1
    long long row_col_diag1_intersect = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            long long d = r + c;
            if (diag1.count(d)) {
                row_col_diag1_intersect++;
            }
        }
    }
    forbidden += row_col_diag1_intersect;
    
    // Count intersections: rows, columns, and diag2
    long long row_col_diag2_intersect = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            long long d = r - c;
            if (diag2.count(d)) {
                row_col_diag2_intersect++;
            }
        }
    }
    forbidden += row_col_diag2_intersect;
    
    // Count intersections: rows, diag1, and diag2
    long long row_diag1_diag2_intersect = 0;
    for (long long r : rows) {
        for (long long d1 : diag1) {
            for (long long d2 : diag2) {
                long long j = (d1 - d2) / 2;
                if ((d1 - d2) % 2 == 0 && 1 <= j && j <= N && cols.count(j) && (r + j == d1) && (r - j == d2)) {
                    row_diag1_diag2_intersect++;
                }
            }
        }
    }
    forbidden += row_diag1_diag2_intersect;
    
    // Count intersections: columns, diag1, and diag2
    long long col_diag1_diag2_intersect = 0;
    for (long long c : cols) {
        for (long long d1 : diag1) {
            for (long long d2 : diag2) {
                long long i = (d1 + d2) / 2;
                if ((d1 + d2) % 2 == 0 && 1 <= i && i <= N && rows.count(i) && (i + c == d1) && (i - c == d2)) {
                    col_diag1_diag2_intersect++;
                }
            }
        }
    }
    forbidden += col_diag1_diag2_intersect;
    
    // Count intersections: rows, columns, diag1, and diag2
    long long all_intersect = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            long long d1 = r + c;
            long long d2 = r - c;
            if (diag1.count(d1) && diag2.count(d2)) {
                all_intersect++;
            }
        }
    }
    forbidden -= all_intersect;
    
    long long safe = total - forbidden;
    cout << safe << endl;
    
    return 0;
}
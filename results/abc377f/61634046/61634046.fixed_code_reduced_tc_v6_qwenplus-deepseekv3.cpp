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
    long long invalid_rows = rows.size() * N;
    long long invalid_cols = cols.size() * N;
    long long invalid_diag1 = 0;
    long long invalid_diag2 = 0;
    
    for (long long d : diag1) {
        if (d <= N + 1) {
            invalid_diag1 += d - 1;
        } else {
            invalid_diag1 += 2 * N - d + 1;
        }
    }
    
    for (long long d : diag2) {
        if (d >= 0) {
            invalid_diag2 += N - d;
        } else {
            invalid_diag2 += N + d;
        }
    }
    
    long double invalid_all = invalid_rows + invalid_cols + invalid_diag1 + invalid_diag2;
    
    long double invalid_row_col = rows.size() * cols.size();
    
    long double invalid_row_diag1 = 0;
    for (long long a : rows) {
        for (long long d : diag1) {
            long long b = d - a;
            if (b >= 1 && b <= N) {
                invalid_row_diag1++;
            }
        }
    }
    
    long double invalid_row_diag2 = 0;
    for (long long a : rows) {
        for (long long d : diag2) {
            long long b = a - d;
            if (b >= 1 && b <= N) {
                invalid_row_diag2++;
            }
        }
    }
    
    long double invalid_col_diag1 = 0;
    for (long long b : cols) {
        for (long long d : diag1) {
            long long a = d - b;
            if (a >= 1 && a <= N) {
                invalid_col_diag1++;
            }
        }
    }
    
    long double invalid_col_diag2 = 0;
    for (long long b : cols) {
        for (long long d : diag2) {
            long long a = d + b;
            if (a >= 1 && a <= N) {
                invalid_col_diag2++;
            }
        }
    }
    
    long double invalid_diag1_diag2 = 0;
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long a = (d1 + d2) / 2;
            long long b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                invalid_diag1_diag2++;
            }
        }
    }
    
    long double invalid_row_col_diag1 = 0;
    for (long long a : rows) {
        for (long long b : cols) {
            if (diag1.find(a + b) != diag1.end()) {
                invalid_row_col_diag1++;
            }
        }
    }
    
    long double invalid_row_col_diag2 = 0;
    for (long long a : rows) {
        for (long long b : cols) {
            if (diag2.find(a - b) != diag2.end()) {
                invalid_row_col_diag2++;
            }
        }
    }
    
    long double invalid_row_diag1_diag2 = 0;
    for (long long a : rows) {
        for (long long d1 : diag1) {
            long long b = d1 - a;
            if (b >= 1 && b <= N && diag2.find(a - b) != diag2.end()) {
                invalid_row_diag1_diag2++;
            }
        }
    }
    
    long double invalid_col_diag1_diag2 = 0;
    for (long long b : cols) {
        for (long long d1 : diag1) {
            long long a = d1 - b;
            if (a >= 1 && a <= N && diag2.find(a - b) != diag2.end()) {
                invalid_col_diag1_diag2++;
            }
        }
    }
    
    long double invalid_row_col_diag1_diag2 = 0;
    for (long long a : rows) {
        for (long long b : cols) {
            if (diag1.find(a + b) != diag1.end() && diag2.find(a - b) != diag2.end()) {
                invalid_row_col_diag1_diag2++;
            }
        }
    }
    
    long double invalid = invalid_all - invalid_row_col - invalid_row_diag1 - invalid_row_diag2 - invalid_col_diag1 - invalid_col_diag2 - invalid_diag1_diag2
                        + invalid_row_col_diag1 + invalid_row_col_diag2 + invalid_row_diag1_diag2 + invalid_col_diag1_diag2
                        - invalid_row_col_diag1_diag2;
    
    long double answer = total - invalid;
    cout << (long long)(answer + 1e-9) << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<long long> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    long long attacked = 0;
    attacked += rows.size() * N;
    attacked += cols.size() * N;
    
    for (long long d : diag1) {
        long long i_min = max(1LL, d - N);
        long long i_max = min(N, d - 1);
        attacked += i_max - i_min + 1;
    }
    
    for (long long d : diag2) {
        long long i_min = max(1LL, 1 - d);
        long long i_max = min(N, N - d);
        attacked += i_max - i_min + 1;
    }
    
    // Subtract overlaps: rows and cols
    long long row_col = rows.size() * cols.size();
    
    // Subtract overlaps: rows and diag1
    long long row_diag1 = 0;
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = d - r;
            if (1 <= c && c <= N) {
                row_diag1++;
            }
        }
    }
    
    // Subtract overlaps: rows and diag2
    long long row_diag2 = 0;
    for (long long r : rows) {
        for (long long d : diag2) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                row_diag2++;
            }
        }
    }
    
    // Subtract overlaps: cols and diag1
    long long col_diag1 = 0;
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = d - c;
            if (1 <= r && r <= N) {
                col_diag1++;
            }
        }
    }
    
    // Subtract overlaps: cols and diag2
    long long col_diag2 = 0;
    for (long long c : cols) {
        for (long long d : diag2) {
            long long r = d + c;
            if (1 <= r && r <= N) {
                col_diag2++;
            }
        }
    }
    
    // Subtract overlaps: diag1 and diag2
    long long diag1_diag2 = 0;
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            if ((d1 - d2) % 2 == 0) {
                long long r = (d1 + d2) / 2;
                long long c = (d1 - d2) / 2;
                if (1 <= r && r <= N && 1 <= c && c <= N) {
                    diag1_diag2++;
                }
            }
        }
    }
    
    // Add back triple overlaps
    long long triple = 0;
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                triple++;
            }
        }
    }
    
    long long overlaps = row_col + row_diag1 + row_diag2 + col_diag1 + col_diag2 + diag1_diag2 - triple;
    
    long long safe = N * N - attacked + overlaps;
    cout << safe << endl;
    
    return 0;
}
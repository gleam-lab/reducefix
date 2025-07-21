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
    
    long long row_cnt = rows.size();
    long long col_cnt = cols.size();
    long long diag1_cnt = diag1.size();
    long long diag2_cnt = diag2.size();
    
    // Total unsafe positions: rows + cols + diag1 + diag2 intersections
    long long unsafe = row_cnt * N + col_cnt * N - row_cnt * col_cnt;
    
    // Additional for diagonals
    for (auto d : diag1) {
        long long max_a = min(d - 1, N);
        long long min_a = max(1LL, d - N);
        unsafe += (max_a - min_a + 1);
    }
    for (auto d : diag2) {
        long long max_a = min(d + N, N);
        long long min_a = max(1LL, d + 1);
        unsafe += (max_a - min_a + 1);
    }
    
    // Subtract intersections
    for (auto a : rows) {
        for (auto b : cols) {
            if (diag1.find(a + b) != diag1.end() && diag2.find(a - b) != diag2.end()) {
                unsafe -= 1;
            }
        }
    }
    
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            long long a = (d1 + d2) / 2;
            long long b = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                if (rows.find(a) != rows.end() && cols.find(b) != cols.end()) {
                    unsafe -= 1;
                }
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}
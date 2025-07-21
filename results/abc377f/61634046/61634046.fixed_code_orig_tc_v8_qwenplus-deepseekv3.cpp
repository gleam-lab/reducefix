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
    
    long long row_count = rows.size();
    long long col_count = cols.size();
    long long diag1_count = diag1.size();
    long long diag2_count = diag2.size();
    
    total -= row_count * N;
    total -= col_count * N;
    
    for (long long d : diag1) {
        long long min_val = max(1LL, d - N);
        long long max_val = min(N, d - 1);
        if (min_val <= max_val) {
            total -= (max_val - min_val + 1);
        }
    }
    
    for (long long d : diag2) {
        long long min_val = max(1LL, 1 - d);
        long long max_val = min(N, N - d);
        if (min_val <= max_val) {
            total -= (max_val - min_val + 1);
        }
    }
    
    total += row_count * col_count;
    
    for (long long a : rows) {
        for (long long d : diag1) {
            long long b = d - a;
            if (cols.count(b)) {
                total++;
            }
        }
        for (long long d : diag2) {
            long long b = a - d;
            if (cols.count(b)) {
                total++;
            }
        }
    }
    
    for (long long b : cols) {
        for (long long d : diag1) {
            long long a = d - b;
            if (rows.count(a)) {
                total++;
            }
        }
        for (long long d : diag2) {
            long long a = b + d;
            if (rows.count(a)) {
                total++;
            }
        }
    }
    
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                long long a = (d1 + d2) / 2;
                long long b = (d1 - d2) / 2;
                if (rows.count(a) && cols.count(b)) {
                    total--;
                }
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}
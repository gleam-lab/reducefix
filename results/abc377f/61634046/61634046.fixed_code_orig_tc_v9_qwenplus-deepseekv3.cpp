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
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    long long attacked = 0;
    
    // Rows
    attacked += N * rows.size();
    // Columns
    attacked += N * cols.size();
    // Diagonals (a - b)
    for (long long d : diag1) {
        long long min_val = max(1 - d, 1 + d);
        long long max_val = min(N - d, N + d);
        if (min_val > max_val) continue;
        attacked += (max_val - min_val + 1);
    }
    // Diagonals (a + b)
    for (long long s : diag2) {
        long long min_val = max(s - N, 1LL);
        long long max_val = min(s - 1, N);
        if (min_val > max_val) continue;
        attacked += (max_val - min_val + 1);
    }
    
    // Subtract intersections: row & col
    attacked -= rows.size() * cols.size();
    // Subtract intersections: row & diag1
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = r - d;
            if (cols.count(c)) attacked--;
        }
    }
    // Subtract intersections: row & diag2
    for (long long r : rows) {
        for (long long s : diag2) {
            long long c = s - r;
            if (cols.count(c)) attacked--;
        }
    }
    // Subtract intersections: col & diag1
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = c + d;
            if (rows.count(r)) attacked--;
        }
    }
    // Subtract intersections: col & diag2
    for (long long c : cols) {
        for (long long s : diag2) {
            long long r = s - c;
            if (rows.count(r)) attacked--;
        }
    }
    // Subtract intersections: diag1 & diag2
    for (long long d : diag1) {
        for (long long s : diag2) {
            if ((s - d) % 2 != 0) continue;
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if (rows.count(r) && cols.count(c)) attacked--;
        }
    }
    
    // Add back three-way intersections
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) attacked++;
        }
    }
    
    long long total_squares = N * N;
    long long safe_squares = total_squares - attacked;
    
    cout << safe_squares << endl;
    
    return 0;
}
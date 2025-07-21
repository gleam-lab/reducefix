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
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    long long unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Overlap between rows and columns
    
    // Diagonals
    for (auto d : diag1) {
        long long min_a = max(1LL, 1 + d);
        long long max_a = min(N, N + d);
        if (max_a >= min_a) {
            unsafe += max_a - min_a + 1;
        }
    }
    
    for (auto d : diag2) {
        long long min_a = max(1LL, d - N);
        long long max_a = min(N, d - 1);
        if (max_a >= min_a) {
            unsafe += max_a - min_a + 1;
        }
    }
    
    // Overlap between rows and diag1
    for (auto r : rows) {
        for (auto d : diag1) {
            long long b = r - d;
            if (1 <= b && b <= N) {
                unsafe -= 1;
            }
        }
    }
    
    // Overlap between rows and diag2
    for (auto r : rows) {
        for (auto d : diag2) {
            long long b = d - r;
            if (1 <= b && b <= N) {
                unsafe -= 1;
            }
        }
    }
    
    // Overlap between columns and diag1
    for (auto c : cols) {
        for (auto d : diag1) {
            long long a = d + c;
            if (1 <= a && a <= N) {
                unsafe -= 1;
            }
        }
    }
    
    // Overlap between columns and diag2
    for (auto c : cols) {
        for (auto d : diag2) {
            long long a = d - c;
            if (1 <= a && a <= N) {
                unsafe -= 1;
            }
        }
    }
    
    // Overlap between diag1 and diag2
    for (auto d1 : diag1) {
        for (auto d2 : diag2) {
            long long a = (d1 + d2) / 2;
            long long b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && 1 <= a && a <= N && 1 <= b && b <= N) {
                unsafe += 1;
            }
        }
    }
    
    // Overlap between all four: row, column, diag1, diag2
    for (auto r : rows) {
        for (auto c : cols) {
            long long d1 = r - c;
            long long d2 = r + c;
            if (diag1.count(d1) && diag2.count(d2)) {
                unsafe -= 1;
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}
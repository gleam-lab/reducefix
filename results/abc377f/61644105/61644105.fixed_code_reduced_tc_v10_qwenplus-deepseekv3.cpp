#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows;
    unordered_set<long long> cols;
    unordered_set<long long> diag1; // i - j
    unordered_set<long long> diag2; // i + j
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }
    
    long long unsafe = 0;
    
    // Count squares attacked by rows or columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size(); // Overlap between rows and columns
    
    // Count squares attacked by diagonals
    for (long long d : diag1) {
        long long i_min = max(1LL, 1 + d);
        long long i_max = min(N, N + d);
        if (i_min > i_max) continue;
        unsafe += (i_max - i_min + 1);
    }
    
    for (long long d : diag2) {
        long long i_min = max(1LL, d - N);
        long long i_max = min(N, d - 1);
        if (i_min > i_max) continue;
        unsafe += (i_max - i_min + 1);
    }
    
    // Subtract overlaps between diagonals and rows/columns
    for (long long a : rows) {
        for (long long d : diag1) {
            long long b = a - d;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
        for (long long d : diag2) {
            long long b = d - a;
            if (b >= 1 && b <= N) {
                unsafe--;
            }
        }
    }
    
    for (long long b : cols) {
        for (long long d : diag1) {
            long long a = d + b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
        for (long long d : diag2) {
            long long a = d - b;
            if (a >= 1 && a <= N) {
                unsafe--;
            }
        }
    }
    
    // Add overlaps between both diagonals
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            long long a = (d1 + d2) / 2;
            long long b = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                unsafe++;
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}
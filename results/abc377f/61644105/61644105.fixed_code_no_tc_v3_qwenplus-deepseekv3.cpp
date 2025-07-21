#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diagonals, antiDiagonals;
    vector<long long> a(M), b(M);
    
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diagonals.insert(a[i] + b[i]);
        antiDiagonals.insert(a[i] - b[i]);
    }
    
    long long unsafe = 0;
    
    // Rows
    unsafe += rows.size() * N;
    
    // Columns
    unsafe += cols.size() * N;
    
    // Diagonals (i + j = d)
    for (long long d : diagonals) {
        long long start = max(1LL, d - N);
        long long end = min(N, d - 1);
        if (start <= end) {
            unsafe += (end - start + 1);
        }
    }
    
    // Anti-diagonals (i - j = d)
    for (long long d : antiDiagonals) {
        long long start = max(1LL, 1 - d);
        long long end = min(N, N - d);
        if (start <= end) {
            unsafe += (end - start + 1);
        }
    }
    
    // Intersections: Row and Column
    for (long long r : rows) {
        for (long long c : cols) {
            if (rows.count(r) && cols.count(c)) {
                unsafe--;
            }
        }
    }
    
    // Intersections: Row and Diagonal
    for (long long r : rows) {
        for (long long d : diagonals) {
            if (d - r >= 1 && d - r <= N) {
                unsafe--;
            }
        }
    }
    
    // Intersections: Row and Anti-diagonal
    for (long long r : rows) {
        for (long long d : antiDiagonals) {
            if (r - d >= 1 && r - d <= N) {
                unsafe--;
            }
        }
    }
    
    // Intersections: Column and Diagonal
    for (long long c : cols) {
        for (long long d : diagonals) {
            if (d - c >= 1 && d - c <= N) {
                unsafe--;
            }
        }
    }
    
    // Intersections: Column and Anti-diagonal
    for (long long c : cols) {
        for (long long d : antiDiagonals) {
            if (c + d >= 1 && c + d <= N) {
                unsafe--;
            }
        }
    }
    
    // Intersections: Diagonal and Anti-diagonal
    for (long long d1 : diagonals) {
        for (long long d2 : antiDiagonals) {
            long long i = (d1 + d2) / 2;
            long long j = (d1 - d2) / 2;
            if ((d1 + d2) % 2 == 0 && (d1 - d2) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                unsafe--;
            }
        }
    }
    
    // Triple intersections: Row, Column, Diagonal
    for (long long r : rows) {
        for (long long c : cols) {
            if (rows.count(r) && cols.count(c)) {
                long long d1 = r + c;
                long long d2 = r - c;
                if (diagonals.count(d1)) {
                    unsafe++;
                }
                if (antiDiagonals.count(d2)) {
                    unsafe++;
                }
            }
        }
    }
    
    // Triple intersections: Row, Column, Anti-diagonal
    // Quadruple intersections: Row, Column, Diagonal, Anti-diagonal
    for (long long r : rows) {
        for (long long c : cols) {
            if (rows.count(r) && cols.count(c)) {
                long long d1 = r + c;
                long long d2 = r - c;
                if (diagonals.count(d1) && antiDiagonals.count(d2)) {
                    unsafe--;
                }
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - unsafe;
    cout << safe << endl;
    
    return 0;
}
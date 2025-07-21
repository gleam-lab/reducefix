#include <bits/stdc++.h>
using namespace std;

#define MAX_M 1000

int main() {
    long long N, M;
    cin >> N >> M;

    unordered_set<long long> rows, cols;
    unordered_set<long long> diag1, diag2; // i-j and i+j

    for (int k = 0; k < M; ++k) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a - b);
        diag2.insert(a + b);
    }

    long long unsafe = 0;

    // Count squares attacked by rows
    unsafe += rows.size() * N;
    
    // Count squares attacked by columns
    unsafe += cols.size() * N;
    
    // Count squares attacked by diagonals (i-j)
    for (long long d : diag1) {
        long long i_min = max(1LL, 1 + d);
        long long i_max = min(N, N + d);
        if (i_min > i_max) continue;
        unsafe += i_max - i_min + 1;
    }
    
    // Count squares attacked by diagonals (i+j)
    for (long long s : diag2) {
        long long i_min = max(1LL, s - N);
        long long i_max = min(N, s - 1);
        if (i_min > i_max) continue;
        unsafe += i_max - i_min + 1;
    }

    // Subtract overlaps between rows and columns
    unsafe -= rows.size() * cols.size();
    
    // Subtract overlaps between rows and diag1 (i-j)
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps between rows and diag2 (i+j)
    for (long long r : rows) {
        for (long long s : diag2) {
            long long c = s - r;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Subtract overlaps between columns and diag1 (i-j)
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = c + d;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Subtract overlaps between columns and diag2 (i+j)
    for (long long c : cols) {
        for (long long s : diag2) {
            long long r = s - c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }

    // Subtract overlaps between diag1 and diag2
    for (long long d : diag1) {
        for (long long s : diag2) {
            if ((s - d) % 2 != 0) continue;
            long long r = (s + d) / 2;
            long long c = (s - d) / 2;
            if (1 <= r && r <= N && 1 <= c && c <= N) {
                unsafe--;
            }
        }
    }

    // Add back triple overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c)) unsafe++;
            if (diag2.count(r + c)) unsafe++;
        }
    }

    // Add back overlaps between row, diag1 and diag2
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = r - d;
            if (1 <= c && c <= N && diag2.count(r + c)) {
                unsafe++;
            }
        }
    }

    // Add back overlaps between column, diag1 and diag2
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = c + d;
            if (1 <= r && r <= N && diag2.count(r + c)) {
                unsafe++;
            }
        }
    }

    // Subtract quadruple overlaps
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r - c) && diag2.count(r + c)) {
                unsafe--;
            }
        }
    }

    long long total = N * N;
    long long safe = total - unsafe;
    cout << safe << endl;

    return 0;
}
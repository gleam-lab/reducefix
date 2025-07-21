#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows;
    unordered_set<long long> cols;
    unordered_set<long long> diags1; // i - j
    unordered_set<long long> diags2; // i + j
    
    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags1.insert(a - b);
        diags2.insert(a + b);
    }
    
    long long unsafe = 0;
    
    // Rows and columns
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    unsafe -= rows.size() * cols.size();
    
    // Diagonals (i - j)
    for (long long d : diags1) {
        long long i_min, i_max;
        if (d >= 0) {
            i_min = 1 + d;
            i_max = N;
        } else {
            i_min = 1;
            i_max = N + d;
        }
        if (i_max >= i_min) {
            unsafe += (i_max - i_min + 1);
        }
    }
    
    // Diagonals (i + j)
    for (long long d : diags2) {
        long long i_min, i_max;
        if (d <= N + 1) {
            i_min = 1;
            i_max = d - 1;
        } else {
            i_min = d - N;
            i_max = N;
        }
        if (i_max >= i_min) {
            unsafe += (i_max - i_min + 1);
        }
    }
    
    // Intersections between rows/columns and diagonals
    for (long long r : rows) {
        for (long long d : diags1) {
            long long c = r - d;
            if (c >= 1 && c <= N && cols.count(c)) {
                unsafe--;
            }
        }
        for (long long d : diags2) {
            long long c = d - r;
            if (c >= 1 && c <= N && cols.count(c)) {
                unsafe--;
            }
        }
    }
    
    // Intersections between diagonals
    for (long long d1 : diags1) {
        for (long long d2 : diags2) {
            long long i = (d1 + d2) / 2;
            long long j = (d2 - d1) / 2;
            if ((d1 + d2) % 2 == 0 && (d2 - d1) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.count(i) && cols.count(j)) {
                    unsafe++;
                }
            }
        }
    }
    
    long long total = N * N;
    long long safe = total - unsafe;
    
    cout << safe << endl;
    
    return 0;
}
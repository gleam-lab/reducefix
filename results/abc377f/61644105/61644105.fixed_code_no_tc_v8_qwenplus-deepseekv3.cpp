#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    unordered_set<long long> rows, cols, diag1, diag2;
    unordered_set<long long> occupied;
    
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
        occupied.insert((a - 1) * N + b);
    }
    
    long long total = N * N;
    long long unsafe = 0;
    
    unsafe += rows.size() * N;
    unsafe += cols.size() * N;
    
    for (long long d : diag1) {
        long long cnt = 0;
        if (d <= N + 1) {
            cnt = d - 1;
        } else {
            cnt = 2 * N - d + 1;
        }
        unsafe += cnt;
    }
    
    for (long long d : diag2) {
        long long cnt = 0;
        if (d >= 0) {
            cnt = N - d;
        } else {
            cnt = N + d;
        }
        unsafe += cnt;
    }
    
    // Overlaps between rows and columns
    unsafe -= rows.size() * cols.size();
    
    // Overlaps between rows and diag1
    for (long long r : rows) {
        for (long long d : diag1) {
            long long c = d - r;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }
    
    // Overlaps between rows and diag2
    for (long long r : rows) {
        for (long long d : diag2) {
            long long c = r - d;
            if (1 <= c && c <= N) {
                unsafe--;
            }
        }
    }
    
    // Overlaps between columns and diag1
    for (long long c : cols) {
        for (long long d : diag1) {
            long long r = d - c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Overlaps between columns and diag2
    for (long long c : cols) {
        for (long long d : diag2) {
            long long r = d + c;
            if (1 <= r && r <= N) {
                unsafe--;
            }
        }
    }
    
    // Overlaps between diag1 and diag2
    for (long long d1 : diag1) {
        for (long long d2 : diag2) {
            if ((d1 + d2) % 2 == 0) {
                long long r = (d1 + d2) / 2;
                long long c = (d1 - d2) / 2;
                if (1 <= r && r <= N && 1 <= c && c <= N) {
                    unsafe++;
                }
            }
        }
    }
    
    // Overlaps between rows, columns, and diag1
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r + c)) {
                unsafe++;
            }
        }
    }
    
    // Overlaps between rows, columns, and diag2
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag2.count(r - c)) {
                unsafe++;
            }
        }
    }
    
    // Overlaps between rows, diag1, and diag2
    for (long long r : rows) {
        for (long long d1 : diag1) {
            long long c = d1 - r;
            if (1 <= c && c <= N && diag2.count(r - c)) {
                unsafe--;
            }
        }
    }
    
    // Overlaps between columns, diag1, and diag2
    for (long long c : cols) {
        for (long long d1 : diag1) {
            long long r = d1 - c;
            if (1 <= r && r <= N && diag2.count(r - c)) {
                unsafe--;
            }
        }
    }
    
    // All four overlaps (rows, columns, diag1, diag2)
    for (long long r : rows) {
        for (long long c : cols) {
            if (diag1.count(r + c) && diag2.count(r - c)) {
                unsafe++;
            }
        }
    }
    
    long long safe = total - unsafe;
    safe += occupied.size(); // since occupied squares were subtracted multiple times
    safe -= M; // because occupied squares were initially counted in total
    
    cout << safe << endl;
    
    return 0;
}
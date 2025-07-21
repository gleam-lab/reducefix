#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<i64,2>> g(M);
    set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    i64 total_attacked = 0;
    
    // Rows and columns
    i64 unique_rows = rows.size();
    i64 unique_cols = cols.size();
    total_attacked += unique_rows * N + unique_cols * N - unique_rows * unique_cols;
    
    // Diagonals (sum and difference)
    i64 unique_diag1 = diag1.size();
    i64 unique_diag2 = diag2.size();
    
    // Calculate the number of squares in each diagonal (sum)
    for (i64 s : diag1) {
        i64 min_s = max(1LL, s - N);
        i64 max_s = min(N, s - 1);
        if (max_s >= min_s) {
            total_attacked += (max_s - min_s + 1);
        }
    }
    
    // Calculate the number of squares in each diagonal (difference)
    for (i64 d : diag2) {
        i64 min_d = max(1LL, 1 - d);
        i64 max_d = min(N, N - d);
        if (max_d >= min_d) {
            total_attacked += (max_d - min_d + 1);
        }
    }
    
    // Overlaps between rows/columns and diagonals
    for (i64 r : rows) {
        for (i64 s : diag1) {
            // r + c = s => c = s - r
            i64 c = s - r;
            if (c >= 1 && c <= N) {
                total_attacked--;
            }
        }
        for (i64 d : diag2) {
            // r - c = d => c = r - d
            i64 c = r - d;
            if (c >= 1 && c <= N) {
                total_attacked--;
            }
        }
    }
    
    for (i64 c : cols) {
        for (i64 s : diag1) {
            // r + c = s => r = s - c
            i64 r = s - c;
            if (r >= 1 && r <= N) {
                total_attacked--;
            }
        }
        for (i64 d : diag2) {
            // r - c = d => r = d + c
            i64 r = d + c;
            if (r >= 1 && r <= N) {
                total_attacked--;
            }
        }
    }
    
    // Overlaps between diagonals (sum and difference)
    for (i64 s : diag1) {
        for (i64 d : diag2) {
            // r + c = s, r - c = d
            // => 2r = s + d => r = (s + d)/2
            // => 2c = s - d => c = (s - d)/2
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0) {
                i64 r = (s + d) / 2;
                i64 c = (s - d) / 2;
                if (r >= 1 && r <= N && c >= 1 && c <= N) {
                    total_attacked++;
                }
            }
        }
    }
    
    i64 safe_squares = N * N - total_attacked;
    cout << safe_squares << "\n";
    
    return 0;
}
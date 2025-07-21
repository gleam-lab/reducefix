#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> a(M), b(M);
    unordered_set<i64> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        rows.insert(a[i]);
        cols.insert(b[i]);
        diag1.insert(a[i] + b[i]);
        diag2.insert(a[i] - b[i]);
    }
    
    i64 total_attacked = 0;
    
    // Rows and columns
    i64 row_count = rows.size();
    i64 col_count = cols.size();
    total_attacked += row_count * N + col_count * N - row_count * col_count;
    
    // Diagonals (i + j = k)
    i64 diag1_count = diag1.size();
    for (i64 k : diag1) {
        i64 min_ij = max(1LL, k - N);
        i64 max_ij = min(N, k - 1);
        if (min_ij > max_ij) continue;
        total_attacked += (max_ij - min_ij + 1);
    }
    
    // Diagonals (i - j = k)
    i64 diag2_count = diag2.size();
    for (i64 k : diag2) {
        i64 min_i = max(1LL, 1 + k);
        i64 max_i = min(N, N + k);
        if (min_i > max_i) continue;
        total_attacked += (max_i - min_i + 1);
    }
    
    // Intersections between rows/columns and diagonals
    for (i64 k : diag1) {
        for (i64 r : rows) {
            i64 c = k - r;
            if (c >= 1 && c <= N) {
                total_attacked--;
            }
        }
        for (i64 c : cols) {
            i64 r = k - c;
            if (r >= 1 && r <= N) {
                total_attacked--;
            }
        }
    }
    
    for (i64 k : diag2) {
        for (i64 r : rows) {
            i64 c = r - k;
            if (c >= 1 && c <= N) {
                total_attacked--;
            }
        }
        for (i64 c : cols) {
            i64 r = c + k;
            if (r >= 1 && r <= N) {
                total_attacked--;
            }
        }
    }
    
    // Intersections between the two diagonals
    for (i64 k1 : diag1) {
        for (i64 k2 : diag2) {
            i64 x = (k1 + k2) / 2;
            i64 y = (k1 - k2) / 2;
            if ((k1 + k2) % 2 == 0 && (k1 - k2) % 2 == 0 && x >= 1 && x <= N && y >= 1 && y <= N) {
                total_attacked++;
            }
        }
    }
    
    // Subtract the squares that are already occupied
    total_attacked -= M;
    
    i64 safe_squares = N * N - total_attacked;
    cout << safe_squares << "\n";
    
    return 0;
}
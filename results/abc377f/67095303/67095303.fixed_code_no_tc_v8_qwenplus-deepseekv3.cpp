#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    unordered_set<int> rows, cols, diag1, diag2;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int safe_rows = N - rows.size();
    int safe_cols = N - cols.size();
    int initial_safe = safe_rows * safe_cols;
    
    // Calculate safe squares not attacked by any diagonal
    int total_diag1 = 0;
    for (int d : diag1) {
        if (d <= N + 1) {
            total_diag1 += d - 1;
        } else {
            total_diag1 += 2 * N - d + 1;
        }
    }
    
    int total_diag2 = 0;
    for (int d : diag2) {
        if (d >= 0) {
            total_diag2 += N - d;
        } else {
            total_diag2 += N + d;
        }
    }
    
    // Subtract the squares already counted in initial_safe
    // For each (i,j) in safe_rows x safe_cols, check if it lies on any diagonal
    // To avoid double counting, we need to subtract the safe squares that are on diagonals
    // But calculating this directly is expensive, so we use inclusion-exclusion
    // Instead, we can compute the total diagonals and subtract overlaps with safe_rows and safe_cols
    
    // Total squares attacked by diagonals excluding rows and columns already counted
    // We need to find the number of squares (i,j) not in any row or column from existing pieces
    // but lying on any of the diagonals
    int diag1_safe = 0;
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int count = max_i - min_i + 1;
        for (int i = min_i; i <= max_i; ++i) {
            int j = d - i;
            if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                count--;
            }
        }
        diag1_safe += count;
    }
    
    int diag2_safe = 0;
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int count = max_i - min_i + 1;
        for (int i = min_i; i <= max_i; ++i) {
            int j = i - d;
            if (rows.find(i) != rows.end() || cols.find(j) != cols.end()) {
                count--;
            }
        }
        diag2_safe += count;
    }
    
    // Now, subtract these from initial_safe
    initial_safe -= diag1_safe + diag2_safe;
    
    // But we also need to add back squares that are on both types of diagonals
    // i.e., squares (i,j) where i + j = d1 and i - j = d2 for some d1 in diag1 and d2 in diag2
    int overlap = 0;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                if (rows.find(i) == rows.end() && cols.find(j) == cols.end()) {
                    overlap++;
                }
            }
        }
    }
    
    initial_safe += overlap;
    
    cout << initial_safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}
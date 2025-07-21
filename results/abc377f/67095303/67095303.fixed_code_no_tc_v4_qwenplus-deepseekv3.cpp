#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2; // diag1: i+j, diag2: i-j
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int total_rows = rows.size();
    int total_cols = cols.size();
    int total_diag1 = diag1.size();
    int total_diag2 = diag2.size();
    
    // Calculate total attacked squares without overlaps
    int attacked = 0;
    
    // Rows and columns
    attacked += N * total_rows + N * total_cols - total_rows * total_cols;
    
    // Diagonals (i+j)
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        int len = max_i - min_i + 1;
        attacked += len;
    }
    
    // Diagonals (i-j)
    for (int d : diag2) {
        int min_i = max(1LL, 1 + d);
        int max_i = min(N, N + d);
        int len = max_i - min_i + 1;
        attacked += len;
    }
    
    // Subtract overlaps between rows/columns and diagonals
    // For each existing piece, it's already counted in rows/columns and diagonals
    attacked -= M;
    
    // Now, subtract overlaps between diagonals (i+j) and (i-j)
    // For each intersection point (i,j) where i+j = d1 and i-j = d2
    // We have i = (d1 + d2)/2, j = (d1 - d2)/2
    // They must be integers and within [1, N]
    set<pair<int, int>> diagonal_intersections;
    for (int d1 : diag1) {
        for (int d2 : diag2) {
            if ((d1 + d2) % 2 != 0 || (d1 - d2) % 2 != 0) continue;
            int i = (d1 + d2) / 2;
            int j = (d1 - d2) / 2;
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                diagonal_intersections.insert({i, j});
            }
        }
    }
    attacked -= diagonal_intersections.size();
    
    // Total safe squares: N^2 - M (existing pieces) - attacked squares
    // But attacked squares already include the existing pieces, so adjust
    int safe = N * N - M - attacked;
    cout << safe << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    
    return 0;
}
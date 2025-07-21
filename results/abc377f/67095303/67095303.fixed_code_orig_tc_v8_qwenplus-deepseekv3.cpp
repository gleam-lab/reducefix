#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    set<int> rows, cols, diag1, diag2;
    
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    int total_covered = 0;
    
    // Rows and columns
    total_covered += rows.size() * N;
    total_covered += cols.size() * N;
    total_covered -= rows.size() * cols.size();
    
    // Diagonals (i + j = d)
    for (int d : diag1) {
        int min_i = max(1LL, d - N);
        int max_i = min(N, d - 1);
        if (min_i > max_i) continue;
        int cnt = max_i - min_i + 1;
        total_covered += cnt;
        
        // Subtract overlaps with rows
        for (int r : rows) {
            if (d - r >= 1 && d - r <= N) {
                total_covered--;
            }
        }
        
        // Subtract overlaps with columns
        for (int c : cols) {
            if (d - c >= 1 && d - c <= N) {
                total_covered--;
            }
        }
        
        // Subtract overlaps with other diagonals (i - j = e)
        for (int e : diag2) {
            int i = (d + e) / 2;
            int j = (d - e) / 2;
            if ((d + e) % 2 == 0 && (d - e) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                total_covered--;
            }
        }
    }
    
    // Diagonals (i - j = e)
    for (int e : diag2) {
        int min_j = max(1LL, 1 - e);
        int max_j = min(N, N - e);
        if (min_j > max_j) continue;
        int cnt = max_j - min_j + 1;
        total_covered += cnt;
        
        // Subtract overlaps with rows
        for (int r : rows) {
            if (r - e >= 1 && r - e <= N) {
                total_covered--;
            }
        }
        
        // Subtract overlaps with columns
        for (int c : cols) {
            if (e + c >= 1 && e + c <= N) {
                total_covered--;
            }
        }
        
        // Subtract overlaps with other diagonals (i + j = d)
        for (int d : diag1) {
            int i = (d + e) / 2;
            int j = (d - e) / 2;
            if ((d + e) % 2 == 0 && (d - e) % 2 == 0 && i >= 1 && i <= N && j >= 1 && j <= N) {
                total_covered--;
            }
        }
    }
    
    // Total safe squares
    int total_squares = N * N;
    int safe_squares = total_squares - total_covered + M; // Adding M because existing pieces are already counted in rows/cols/diags
    cout << safe_squares << endl;
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
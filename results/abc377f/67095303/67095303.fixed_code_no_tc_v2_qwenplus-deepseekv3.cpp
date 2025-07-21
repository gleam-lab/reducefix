#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    
    set<int> rows, cols, diag1, diag2;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diag1.insert(a + b);
        diag2.insert(a - b);
    }
    
    // Total safe squares = N*N - M - attacked squares
    // Attacked squares = (rows + cols + diags) - intersections
    
    // Calculate rows and columns
    int row_cnt = rows.size();
    int col_cnt = cols.size();
    int row_col_intersection = 0;
    for(int r : rows) {
        if(cols.count(r)) row_col_intersection++;
    }
    int row_col_attack = row_cnt * N + col_cnt * N - row_cnt * col_cnt;
    
    // Calculate diagonals
    int diag1_cnt = diag1.size();
    int diag2_cnt = diag2.size();
    
    // For each diagonal type, calculate how many squares it covers
    // For diag1 (i+j=d): length depends on d
    // min( (d-1), (2N - (d-1)) )
    int diag1_total = 0;
    for(int d : diag1) {
        if(d <= N+1) diag1_total += d - 1;
        else diag1_total += 2*N - d + 1;
    }
    
    // For diag2 (i-j=d): length is N - abs(d)
    int diag2_total = 0;
    for(int d : diag2) {
        diag2_total += N - abs(d);
    }
    
    // Calculate intersections between diagonals
    int diag_diag_intersection = 0;
    for(int d1 : diag1) {
        for(int d2 : diag2) {
            // Solve i+j = d1 and i-j = d2
            if((d1 + d2) % 2 == 0) {
                int i = (d1 + d2) / 2;
                int j = (d1 - d2) / 2;
                if(i >= 1 && i <= N && j >= 1 && j <= N) {
                    diag_diag_intersection++;
                }
            }
        }
    }
    
    // Calculate intersections between rows/cols and diagonals
    int row_diag1_intersection = 0;
    for(int r : rows) {
        for(int d : diag1) {
            int j = d - r;
            if(j >= 1 && j <= N) row_diag1_intersection++;
        }
    }
    
    int row_diag2_intersection = 0;
    for(int r : rows) {
        for(int d : diag2) {
            int j = r - d;
            if(j >= 1 && j <= N) row_diag2_intersection++;
        }
    }
    
    int col_diag1_intersection = 0;
    for(int c : cols) {
        for(int d : diag1) {
            int i = d - c;
            if(i >= 1 && i <= N) col_diag1_intersection++;
        }
    }
    
    int col_diag2_intersection = 0;
    for(int c : cols) {
        for(int d : diag2) {
            int i = c + d;
            if(i >= 1 && i <= N) col_diag2_intersection++;
        }
    }
    
    // Total attacked squares
    int total_attacked = row_col_attack 
                       + diag1_total + diag2_total - diag_diag_intersection
                       - row_diag1_intersection - row_diag2_intersection 
                       - col_diag1_intersection - col_diag2_intersection;
    
    // Add back triple intersections (already subtracted twice)
    // These are points where row/col/diag1/diag2 all meet (which are the original pieces)
    total_attacked += M;
    
    // Safe squares = total empty squares - attacked empty squares
    int total_empty = N*N - M;
    int safe_squares = total_empty - (total_attacked - M);
    
    cout << safe_squares << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
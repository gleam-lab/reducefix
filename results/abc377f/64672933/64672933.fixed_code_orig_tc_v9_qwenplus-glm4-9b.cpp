#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<i64> seen_rows(N+1), seen_cols(N+1), seen_diags1(N*2+1), seen_diags2(N*2+1);
    
    for (i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        seen_rows[a] = 1;
        seen_cols[b] = 1;
        seen_diags1[a+b] = 1;
        seen_diags2[a-b+N] = 1;
    }
    
    // Count the number of unique rows, columns, and diagonals that are occupied
    i64 occupied_rows = 0, occupied_cols = 0, occupied_diags1 = 0, occupied_diags2 = 0;
    for (i64 i = 1; i <= N; ++i) {
        if (seen_rows[i]) ++occupied_rows;
        if (seen_cols[i]) ++occupied_cols;
    }
    for (i64 i = 1; i <= 2*N; ++i) {
        if (seen_diags1[i]) ++occupied_diags1;
        if (seen_diags2[i]) ++occupied_diags2;
    }
    
    // Calculate the number of empty squares
    i64 total_squares = N * N;
    i64 occupied_squares = occupied_rows * N + occupied_cols + occupied_diags1 + occupied_diags2;
    i64 ans = total_squares - occupied_squares;
    
    cout << ans << "\n";
    return 0;
}
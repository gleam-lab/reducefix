#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    set<pair<i64, i64>> occupied;
    for(i64 i = 0; i < M; ++i){
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }
    
    i64 total_squares = N*N;
    i64 occupied_squares = M;
    
    // Count squares in each row, column, diagonal, and anti-diagonal
    vector<i64> rows(N+1, 0), cols(N+1, 0), diag(N+1, 0), antidiag(N+1, 0);
    for(auto [a, b]: pieces){
        rows[a]++;
        cols[b]++;
        diag[a+b]++;
        antidiag[a-b+N-1]++;
    }
    
    // Calculate non-attacked squares
    for(i64 i = 1; i <= N; ++i){
        total_squares -= max(0ll, min(rows[i], N) - 1);
        total_squares -= max(0ll, min(cols[i], N) - 1);
        total_squares -= max(0ll, min(diag[i], N) - 1);
        total_squares -= max(0ll, min(antidiag[i], N) - 1);
    }
    
    // Add back overcounted squares (where multiple diagonals overlap)
    for(i64 i = 1; i <= N; ++i){
        for(i64 j = 1; j <= N; ++j){
            if(rows[i] > 1 && cols[j] > 1 && diag[i+j] > 1 && antidiag[i-j+N-1] > 1){
                total_squares++;
            }
        }
    }
    
    cout << total_squares << '\n';
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    vector<array<int, 2>> pieces(M);
    vector<i64> sum_rows(N+1, 0), sum_cols(N+1, 0), sum_diag1(N+N+1, 0), sum_diag2(N+N+1, 0);
    
    for(int i = 0; i < M; ++i){
        i64 r, c; cin >> r >> c;
        pieces[i] = {r, c};
        sum_rows[r]++;
        sum_cols[c]++;
        sum_diag1[r+c]++;
        sum_diag2[r-c+N]++;
    }

    i64 valid_squares = 0;
    for(i64 r = 1; r <= N; ++r){
        for(i64 c = 1; c <= N; ++c){
            if(sum_rows[r] > 0 || sum_cols[c] > 0 || sum_diag1[r+c] > 0 || sum_diag2[r-c+N] > 0) continue;
            valid_squares++;
        }
    }

    cout << valid_squares << '\n';
    return 0;
}
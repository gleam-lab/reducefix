#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> positions(M);
    set<pair<i64, i64>> pieces;
    
    for(i64 i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        positions[i] = {a, b};
        pieces.insert({a, b});
        pieces.insert({a, N+1-b});
        pieces.insert({N+1-a, b});
        pieces.insert({N+1-a, N+1-b});
    }
    
    i64 total_squares = N*N;
    i64 occupied_squares = pieces.size();
    
    cout << total_squares - occupied_squares << '\n';
    
    return 0;
}
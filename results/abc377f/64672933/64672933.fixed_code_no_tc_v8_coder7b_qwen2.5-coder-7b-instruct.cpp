#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    i64 N, M;
    cin >> N >> M;
    
    vector<array<i64,2>> g(M);
    set<pair<i64, i64>> positions;
    for(int i=0; i<M; ++i){
        i64 a, b;
        cin >> a >> b;
        --a; --b; // Adjusting to 0-based index
        g[i] = {a, b};
        positions.insert({a, b});
        
        // Mark all squares in the same row, column, diagonal, and anti-diagonal as occupied
        for(i64 j=0; j<N; ++j){
            positions.insert({a, j}); // Same row
            positions.insert({j, b}); // Same column
            
            if(a + j < N && b + j < N) positions.insert({a + j, b + j}); // Same diagonal
            if(a + j < N && b - j >= 0) positions.insert({a + j, b - j}); // Same anti-diagonal
        }
    }
    
    // The total number of empty squares is N*N minus the number of occupied squares
    cout << N*N - positions.size() << '\n';
    
    return 0;
}
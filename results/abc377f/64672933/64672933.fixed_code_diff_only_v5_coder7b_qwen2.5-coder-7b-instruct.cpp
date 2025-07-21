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
    
    for (int i = 0; i < M; ++i) {
        i64 a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        occupied.insert({a, b});
        
        // Add all squares in the same row, column, and diagonals to the occupied set
        for (i64 j = 1; j <= N; ++j) {
            if (j != a && j != b) {
                occupied.insert({j, b}); // Same column
                occupied.insert({a, j}); // Same row
                occupied.insert({j, j - (a - b)}); // Diagonal 1
                occupied.insert({j, (a - b) + j}); // Diagonal 2
            }
        }
    }
    
    // Calculate the number of empty squares
    i64 empty_squares = N * N - occupied.size();
    
    cout << empty_squares << "\n";
    
    return 0;
}
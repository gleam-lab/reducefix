#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    set<pair<i64, i64>> pieceSet;
    for (i64 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        pieceSet.insert(pieces[i]);
    }
    
    unordered_set<i64> sums, differences;
    for (const auto& [x, y] : pieces) {
        sums.insert(x + y);
        differences.insert(x - y);
    }

    i64 totalValidPositions = N * N;
    
    for (const auto& [x, y] : pieces) {
        // Check row captures
        for (i64 j = 1; j <= N; ++j) {
            if (j != y && pieceSet.find({x, j}) != pieceSet.end()) {
                totalValidPositions--;
                break;
            }
        }
        
        // Check column captures
        for (i64 i = 1; i <= N; ++i) {
            if (i != x && pieceSet.find({i, y}) != pieceSet.end()) {
                totalValidPositions--;
                break;
            }
        }
        
        // Check diagonal captures (x + y = constant)
        for (i64 j = 1; j <= N; ++j) {
            if (j != y && sums.count(x + j) && pieceSet.find({x + j, j}) != pieceSet.end()) {
                totalValidPositions--;
                break;
            }
        }
        
        // Check anti-diagonal captures (x - y = constant)
        for (i64 j = 1; j <= N; ++j) {
            if (j != y && differences.count(x - j) && pieceSet.find({x - j, j}) != pieceSet.end()) {
                totalValidPositions--;
                break;
            }
        }
    }
    
    cout << totalValidPositions << endl;
    return 0;
}
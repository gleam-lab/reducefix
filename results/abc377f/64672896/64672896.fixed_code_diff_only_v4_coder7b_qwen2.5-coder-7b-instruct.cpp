#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 N, M;
    cin >> N >> M;
    
    vector<pair<i64, i64>> pieces(M);
    for(i64 i = 0; i < M; ++i){
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    set<pair<i64, i64>> board;
    for(i64 i = 1; i <= N; ++i){
        for(i64 j = 1; j <= N; ++j){
            board.insert({i, j});
        }
    }

    for(auto &piece : pieces){
        auto [r, c] = piece;
        board.erase(board.find({r, c}));
        
        for(i64 k = 1; k <= N; ++k){
            board.erase(board.find({r, k}));
            board.erase(board.find({k, c}));
            board.erase(board.find({r + k, c + k}));
            board.erase(board.find({r - k, c - k}));
        }
    }
    
    cout << board.size() << '\n';
    return 0;
}
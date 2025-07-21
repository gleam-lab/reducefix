#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e9 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> rows(M), cols(M);
    for(int i = 0; i < M; ++i) {
        cin >> rows[i] >> cols[i];
    }

    bool board[MAXN][MAXN] = {};
    for(int i = 0; i < M; ++i) {
        int r = rows[i], c = cols[i];
        board[r][c] = true;
        
        // Check all possible knight moves
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for(auto [dr, dc] : moves) {
            int nr = r + dr, nc = c + dc;
            if(nr >= 1 && nr <= N && nc >= 1 && nc <= N) {
                board[nr][nc] = true;
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(!board[i][j]) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    
    vector<vector<bool>> board(N + 1, vector<bool>(N + 1, true));
    for (auto &p : pieces) {
        for (int i = max(p.first - 2, 1); i <= min(p.first + 2, N); ++i) {
            for (int j = max(p.second - 1, 1); j <= min(p.second + 2, N); ++j) {
                board[i][j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (board[i][j]) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
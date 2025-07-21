#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) cin >> A[i][j];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);

    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q[A[i][j]].emplace(i, j);
                visited[i][j] = true;
            }
        }
    }

    for(int y = 1; y <= Y; ++y) {
        while(!q[y].empty()) {
            auto [i, j] = q[y].front(); q[y].pop();
            for(int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= y) {
                    visited[ni][nj] = true;
                    q[y].emplace(ni, nj);
                }
            }
        }
    }

    vector<int> result(Y + 1, H * W);
    for(int y = 1; y <= Y; ++y) {
        for(int i = 0; i < H; ++i) for(int j = 0; j < W; ++j) if(!visited[i][j]) --result[y];
    }

    for(int y = 1; y <= Y; ++y) cout << result[y] << '\n';

    return 0;
}
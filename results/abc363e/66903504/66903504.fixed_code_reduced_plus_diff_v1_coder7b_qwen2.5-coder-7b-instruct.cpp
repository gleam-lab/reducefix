#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
queue<pair<int, int>> q;

void bfs(int H, int W, int sea_level) {
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        visited[i][j] = true;
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= sea_level) {
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            if (A[i][j] > 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        bfs(H, W, y);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > y && visited[i][j]) {
                    --ans;
                }
            }
        }
        fill(visited.begin(), visited.end(), false);
        queue<pair<int, int>>().swap(q);
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > y && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
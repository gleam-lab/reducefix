#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<vector<int>> A(MAXN, vector<int>(MAXN));

void solve() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);
    
    // Initialize the queue and visited array
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q[A[i][j]].push({i, j});
            }
        }
    }
    
    int ans = H * W;
    for (int y = 1; y <= Y; ++y) {
        while (!q[y].empty()) {
            auto [i, j] = q[y].front();
            q[y].pop();
            ans--;
            
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj] && A[ni][nj] <= y) {
                    visited[ni][nj] = true;
                    q[y].push({ni, nj});
                }
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
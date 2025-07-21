#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<queue<pair<int, int>>> q(Y + 1);
    
    // Initialize boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q[A[i][j]].push({i, j});
            }
        }
    }
    
    int remaining_area = H * W;
    
    for (int y = 1; y <= Y; ++y) {
        while (!q[y].empty()) {
            auto [i, j] = q[y].front();
            q[y].pop();
            --remaining_area;
            
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q[max(A[ni][nj], y)].push({ni, nj});
                }
            }
        }
        
        cout << remaining_area << endl;
    }
    
    return 0;
}
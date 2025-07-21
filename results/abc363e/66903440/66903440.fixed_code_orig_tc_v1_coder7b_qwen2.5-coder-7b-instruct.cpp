#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs(vector<vector<int>>& A, vector<vector<bool>>& F, int targetLevel) {
    int H = A.size();
    int W = A[0].size();
    queue<pair<int, int>> q;
    
    // Enqueue all cells that will sink immediately
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] <= targetLevel && F[i][j]) {
                F[i][j] = false;
                q.push({i, j});
            }
        }
    }
    
    // Perform BFS to sink connected components
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if (ni >= 0 && ni < H && nj >= 0 && nj < W && A[ni][nj] <= targetLevel && F[ni][nj]) {
                F[ni][nj] = false;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<bool>> F(H, vector<bool>(W, true));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    set<int> levels;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            levels.insert(A[i][j]);
        }
    }
    
    for (auto it = levels.rbegin(); it != levels.rend(); ++it) {
        bfs(A, F, *it);
    }
    
    for (int i = 0; i < Y; ++i) {
        int targetLevel = *levels.lower_bound(i + 1);
        int remainingArea = 0;
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                if (F[j][k] && A[j][k] > targetLevel) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }
    
    return 0;
}
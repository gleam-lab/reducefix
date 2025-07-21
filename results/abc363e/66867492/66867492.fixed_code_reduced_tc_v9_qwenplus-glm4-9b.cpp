#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }
    
    // Initialize the queue with the edges of the island
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> used(H, vector<bool>(W, false));
    
    for (int i = 0; i < H; ++i) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][W - 1], i, W - 1});
        used[i][0] = true;
        used[i][W - 1] = true;
    }
    
    for (int j = 0; j < W; ++j) {
        pq.push({A[0][j], 0, j});
        pq.push({A[H - 1][j], H - 1, j});
        used[0][j] = true;
        used[H - 1][j] = true;
    }
    
    int ans = H * W;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    while (!pq.empty()) {
        auto cell = pq.top();
        pq.pop();
        int r = cell[1];
        int c = cell[2];
        
        // Mark the cell as sunk and decrease the remaining area
        used[r][c] = true;
        ans--;
        
        // Check adjacent cells
        for (int d = 0; d < 4; ++d) {
            int nr = r + dy[d];
            int nc = c + dx[d];
            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !used[nr][nc] && A[nr][nc] <= cell[0] + 1) {
                pq.push({A[nr][nc], nr, nc});
            }
        }
    }
    
    // Output the remaining area after each year
    for (int i = 0; i < Y; ++i) {
        cout << ans << endl;
    }
    
    return 0;
}
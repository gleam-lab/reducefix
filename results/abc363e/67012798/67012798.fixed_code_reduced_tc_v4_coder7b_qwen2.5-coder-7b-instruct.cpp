#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // Initialize the island matrix where true means the section is above water
    vector<vector<bool>> island(H, vector<bool>(W, true));

    // Priority queue to handle sea level rises
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    // Add boundary cells to the queue
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                pq.push({A[i][j], {i, j}});
                island[i][j] = false;
            }
        }
    }

    // Function to perform BFS to mark all connected cells as submerged
    function<void(int)> bfs = [&](int sea_level) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        
        while (!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();
            
            if (height > sea_level) break;
            
            int x = pos.first, y = pos.second;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            
            q.push({x, y});
            
            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];
                    
                    if (nx < 0 || ny < 0 || nx >= H || ny >= W || visited[nx][ny] || A[nx][ny] > sea_level) continue;
                    
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    island[nx][ny] = false;
                }
            }
        }
    };

    // Process each sea level rise
    for (int i = 1; i <= Y; i++) {
        bfs(i);
        
        // Count the remaining land areas
        int ans = 0;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (island[j][k]) {
                    ans++;
                }
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val; // Min-heap by elevation
    }
};

signed main() {
    close;
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Priority queue to process cells in order of increasing elevation
    priority_queue<Node> pq;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    // Initialize with all border cells since they are adjacent to the sea
    for (int i = 0; i < H; i++) {
        pq.push({i, 0, grid[i][0]});
        visited[i][0] = true;
        
        if (W > 1) {
            pq.push({i, W-1, grid[i][W-1]});
            visited[i][W-1] = true;
        }
    }
    
    for (int j = 1; j < W-1; j++) {
        pq.push({0, j, grid[0][j]});
        visited[0][j] = true;
        
        if (H > 1) {
            pq.push({H-1, j, grid[H-1][j]});
            visited[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1); // Store results for each year
    
    // Process sinking over time
    for (int year = 1; year <= Y; year++) {
        // Remove all cells that sink at this sea level (elevation <= year)
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top();
            pq.pop();
            remaining--;
            
            // Check neighbors
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        result[year] = remaining;
    }
    
    // Output results for each year
    for (int i = 1; i <= Y; i++) {
        cout << result[i] << '\n';
    }
    
    return 0;
}
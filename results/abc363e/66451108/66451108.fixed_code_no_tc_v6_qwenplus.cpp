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
    
    // Visited array to track which cells have been processed
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    priority_queue<Node> pq;
    
    // Initialize with all border cells since they are adjacent to the sea
    for (int i = 0; i < H; i++) {
        pq.push({i, 0, grid[i][0]});
        vis[i][0] = true;
        
        if (W > 1) {
            pq.push({i, W-1, grid[i][W-1]});
            vis[i][W-1] = true;
        }
    }
    
    for (int j = 1; j < W-1; j++) {
        pq.push({0, j, grid[0][j]});
        vis[0][j] = true;
        
        if (H > 1) {
            pq.push({H-1, j, grid[H-1][j]});
            vis[H-1][j] = true;
        }
    }
    
    int remaining = H * W;
    vector<int> result(Y + 1); // Store result for each year
    
    // Process cells in increasing order of elevation
    for (int year = 1; year <= Y; year++) {
        // Remove all cells that get submerged at this sea level
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top();
            pq.pop();
            remaining--;
            
            // Check neighbors
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
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
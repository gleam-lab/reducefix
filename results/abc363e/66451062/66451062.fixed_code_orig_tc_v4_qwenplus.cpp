#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;
    
    // Add all border cells to the priority queue
    for (int i = 0; i < h; i++) {
        q.push({i, 0, grid[i][0]});
        q.push({i, w-1, grid[i][w-1]});
        vis[i][0] = true;
        if (w > 1) vis[i][w-1] = true;
    }
    
    for (int j = 1; j < w-1; j++) {
        q.push({0, j, grid[0][j]});
        q.push({h-1, j, grid[h-1][j]});
        vis[0][j] = true;
        vis[h-1][j] = true;
    }
    
    int res = h * w;
    
    // Process each year
    for (int level = 1; level <= y; level++) {
        // Process all cells with elevation <= current sea level
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top();
            q.pop();
            
            // This cell sinks, decrease remaining area
            res--;
            
            // Check neighbors
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        
        cout << res << endl;
    }
    
    return 0;
}
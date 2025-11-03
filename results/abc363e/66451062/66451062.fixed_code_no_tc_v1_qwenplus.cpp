#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int inf = 0x3f3f3f3f3f3f;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
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
    int res = h * w;

    // Add all border cells to the priority queue
    for (int i = 0; i < h; i++) {
        if (!vis[i][0]) {
            vis[i][0] = true;
            q.push({i, 0, grid[i][0]});
        }
        if (w > 1 && !vis[i][w-1]) {
            vis[i][w-1] = true;
            q.push({i, w-1, grid[i][w-1]});
        }
    }
    for (int j = 1; j < w-1; j++) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            q.push({0, j, grid[0][j]});
        }
        if (h > 1 && !vis[h-1][j]) {
            vis[h-1][j] = true;
            q.push({h-1, j, grid[h-1][j]});
        }
    }

    // Process each year from 1 to Y
    for (int level = 1; level <= y; level++) {
        // Remove all cells with elevation <= current sea level
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top();
            q.pop();
            res--;

            // Check neighbors
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    // Only add to queue if it might be submerged in future
                    if (grid[nx][ny] <= level) {
                        // This cell will be submerged now, so we process it in this while loop
                        q.push({nx, ny, grid[nx][ny]});
                    } else {
                        // This cell won't be submerged yet, but might be in future
                        q.push({nx, ny, grid[nx][ny]});
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
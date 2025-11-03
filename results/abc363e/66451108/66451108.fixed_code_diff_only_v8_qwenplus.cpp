#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAXN = 1005;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val; // Min-heap by elevation
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
    priority_queue<Node> pq;
    int remaining = h * w;

    // Initialize the priority queue with all border cells
    for (int i = 0; i < h; i++) {
        if (!vis[i][0]) {
            vis[i][0] = true;
            pq.push({i, 0, grid[i][0]});
        }
        if (w > 1 && !vis[i][w-1]) {
            vis[i][w-1] = true;
            pq.push({i, w-1, grid[i][w-1]});
        }
    }
    for (int j = 1; j < w-1; j++) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            pq.push({0, j, grid[0][j]});
        }
        if (h > 1 && !vis[h-1][j]) {
            vis[h-1][j] = true;
            pq.push({h-1, j, grid[h-1][j]});
        }
    }

    // Process each year from 1 to Y
    for (int year = 1; year <= y; year++) {
        // Sink all cells with elevation <= current sea level (year)
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top();
            pq.pop();
            remaining--;

            // Check neighbors to add them to the priority queue
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << remaining << '\n';
    }

    return 0;
}
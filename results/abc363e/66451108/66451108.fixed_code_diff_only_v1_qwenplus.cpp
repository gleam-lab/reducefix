#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

    // Initialize the border cells as starting points for flooding
    for (int i = 0; i < h; i++) {
        pq.push({i, 0, grid[i][0]});
        pq.push({i, w-1, grid[i][w-1]});
        if (!vis[i][0]) {
            vis[i][0] = true;
            remaining--;
        }
        if (!vis[i][w-1]) {
            vis[i][w-1] = true;
            remaining--;
        }
    }
    for (int j = 1; j < w-1; j++) {
        pq.push({0, j, grid[0][j]});
        pq.push({h-1, j, grid[h-1][j]});
        if (!vis[0][j]) {
            vis[0][j] = true;
            remaining--;
        }
        if (!vis[h-1][j]) {
            vis[h-1][j] = true;
            remaining--;
        }
    }

    // We need to output the area for each year from 1 to Y
    // But note: multiple cells may sink at the same sea level.
    // So we process all cells with elevation <= current sea level.

    // However, the above initialization incorrectly subtracts border cells immediately.
    // Instead, we should simulate year-by-year and only sink when sea level >= elevation.

    // Let's rework: use Dijkstra-like approach where we process cells in order of elevation.
    // But we must output result *each year*, so simulate year 1 to Y.

    // Reset:
    vis.assign(h, vector<bool>(w, false));
    while (!pq.empty()) pq.pop();
    remaining = h * w;

    // Add all border cells to the priority queue
    auto addCell = [&](int x, int y) {
        if (x >= 0 && x < h && y >= 0 && y < w && !vis[x][y]) {
            vis[x][y] = true;
            pq.push({x, y, grid[x][y]});
        }
    };

    for (int i = 0; i < h; i++) {
        addCell(i, 0);
        addCell(i, w-1);
    }
    for (int j = 1; j < w-1; j++) {
        addCell(0, j);
        addCell(h-1, j);
    }

    // Process each year
    for (int year = 1; year <= y; year++) {
        // Remove all cells that are now submerged (elevation <= year)
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top();
            pq.pop();
            // This cell is now underwater, but we already count it as removed?
            // Actually, we remove it now
            remaining--;

            // Propagate to neighbors
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                addCell(nx, ny);
            }
        }
        cout << remaining << '\n';
    }

    return 0;
}
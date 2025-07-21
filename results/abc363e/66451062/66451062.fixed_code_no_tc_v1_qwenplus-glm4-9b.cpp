#include <bits/stdc++.h>
using namespace std;
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;

struct Node {
    int x, y, val;
    bool operator <(const Node &a) const {
        return val < a.val; // Use less to pop the smallest value
    }
};

void bfs(int level, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
    queue<pair<int, int>> q;
    // Start BFS from all edges of the grid that are at the current sea level
    for (int i = 0; i < grid.size(); ++i) {
        if (grid[i][0] == level) q.push({i, 0});
        if (grid[i][grid[i].size() - 1] == level) q.push({i, grid[i].size() - 1});
        if (grid[0][i] == level) q.push({0, i});
        if (grid[grid.size() - 1][i] == level) q.push({grid.size() - 1, i});
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (vis[x][y]) continue;
        vis[x][y] = true;

        // Explore neighbors
        if (x > 0 && !vis[x - 1][y] && grid[x - 1][y] <= level) q.push({x - 1, y});
        if (x < grid.size() - 1 && !vis[x + 1][y] && grid[x + 1][y] <= level) q.push({x + 1, y});
        if (y > 0 && !vis[x][y - 1] && grid[x][y - 1] <= level) q.push({x, y - 1});
        if (y < grid[x].size() - 1 && !vis[x][y + 1] && grid[x][y + 1] <= level) q.push({x, y + 1});
    }
}

int main() {
    close;
    int h, w, y; cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    int res = h * w;

    for (int year = 1; year <= y; ++year) {
        bool newVis = false;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!vis[i][j] && grid[i][j] <= year) {
                    bfs(year, grid, vis);
                    newVis = true;
                }
            }
        }
        if (!newVis) break; // No new cells have sunk, the sea level is above all elevations
        cout << res - count(vis, true) << endl; // Count the number of visited cells (above the sea)
    }
    
    return 0;
}
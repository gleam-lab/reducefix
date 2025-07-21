#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;

    // Initialize the priority queue with border cells
    for (int i = 0; i < h; ++i) {
        if (!vis[i][0]) {
            vis[i][0] = true;
            q.push({i, 0, grid[i][0]});
        }
        if (!vis[i][w - 1]) {
            vis[i][w - 1] = true;
            q.push({i, w - 1, grid[i][w - 1]});
        }
    }
    for (int j = 1; j < w - 1; ++j) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            q.push({0, j, grid[0][j]});
        }
        if (!vis[h - 1][j]) {
            vis[h - 1][j] = true;
            q.push({h - 1, j, grid[h - 1][j]});
        }
    }

    int res = h * w;
    for (int level = 1; level <= y; ++level) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top();
            q.pop();
            res--;
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
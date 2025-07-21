#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int H = 1100, W = 1100;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator < (const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    int grid[H][W];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    bool vis[H][W];
    memset(vis, false, sizeof(vis));
    priority_queue<Node> pq;

    // Initialize the queue with all boundary cells
    for (int i = 0; i < h; ++i) {
        if (!vis[i][0]) {
            vis[i][0] = true;
            pq.push({i, 0, grid[i][0]});
        }
        if (!vis[i][w-1]) {
            vis[i][w-1] = true;
            pq.push({i, w-1, grid[i][w-1]});
        }
    }

    for (int j = 1; j < w-1; ++j) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            pq.push({0, j, grid[0][j]});
        }
        if (!vis[h-1][j]) {
            vis[h-1][j] = true;
            pq.push({h-1, j, grid[h-1][j]});
        }
    }

    int total = h * w;
    vector<int> ans(y + 2, 0);

    // We'll simulate up to year Y
    for (int year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            auto cur = pq.top(); pq.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = total - pq.size();
    }

    for (int i = 1; i <= y; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
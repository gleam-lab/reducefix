#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int H = 1005, W = 1005;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int Y; cin >> Y;
    int grid[H][W];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    bool vis[H][W];
    memset(vis, false, sizeof(vis));
    priority_queue<Node> q;

    // Push all boundary cells into the priority queue
    for (int i = 0; i < h; i++) {
        q.push({i, 0, grid[i][0]});
        q.push({i, w-1, grid[i][w-1]});
        vis[i][0] = vis[i][w-1] = true;
    }
    for (int j = 1; j < w-1; j++) {
        q.push({0, j, grid[0][j]});
        q.push({h-1, j, grid[h-1][j]});
        vis[0][j] = vis[h-1][j] = true;
    }

    int remaining = h * w;
    vector<int> ans(Y + 2, remaining);

    for (int year = 1; year <= Y; ++year) {
        while (!q.empty() && q.top().val <= year) {
            auto [x, y, val] = q.top(); q.pop();
            if (!vis[x][y]) continue;
            remaining--;
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = remaining;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << ans[year] << '\n';
    }

    return 0;
}
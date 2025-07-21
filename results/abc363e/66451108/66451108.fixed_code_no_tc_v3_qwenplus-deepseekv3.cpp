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

    int h, w, Y;
    cin >> h >> w >> Y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;

    // Push all border cells into the priority queue
    for (int i = 0; i < h; ++i) {
        if (!vis[i][0]) {
            q.push({i, 0, grid[i][0]});
            vis[i][0] = true;
        }
        if (!vis[i][w-1]) {
            q.push({i, w-1, grid[i][w-1]});
            vis[i][w-1] = true;
        }
    }
    for (int j = 1; j < w-1; ++j) {
        if (!vis[0][j]) {
            q.push({0, j, grid[0][j});
            vis[0][j] = true;
        }
        if (!vis[h-1][j]) {
            q.push({h-1, j, grid[h-1][j]});
            vis[h-1][j] = true;
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, res); // ans[0] is initial state
    int current_level = 1;
    int processed = 0;

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        while (!q.empty() && q.top().val <= year) {
            Node cur = q.top();
            q.pop();
            processed++;
            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + (k == 2) - (k == 3);
                int ny = cur.y + (k == 0) - (k == 1);
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = res - processed;
    }

    for (int year = 1; year <= Y; ++year) {
        cout << ans[year] << endl;
    }

    return 0;
}
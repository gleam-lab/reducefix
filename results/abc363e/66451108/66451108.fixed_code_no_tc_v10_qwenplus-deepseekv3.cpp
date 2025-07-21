#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int inf = 0x3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    bool operator < (const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int Y; cin >> Y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;
    
    // Add boundary cells to the priority queue
    for (int i = 0; i < h; i++) {
        if (!vis[i][0]) {
            q.push({i, 0, grid[i][0]});
            vis[i][0] = true;
        }
        if (w > 1 && !vis[i][w-1]) {
            q.push({i, w-1, grid[i][w-1]});
            vis[i][w-1] = true;
        }
    }
    for (int j = 1; j < w-1; j++) {
        if (!vis[0][j]) {
            q.push({0, j, grid[0][j]});
            vis[0][j] = true;
        }
        if (h > 1 && !vis[h-1][j]) {
            q.push({h-1, j, grid[h-1][j]});
            vis[h-1][j] = true;
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, res); // ans[0] is initial state, ans[1] is after 1 year, etc.
    int current_level = 1;
    int sunk = 0;

    while (current_level <= Y && !q.empty()) {
        while (!q.empty() && q.top().val <= current_level) {
            Node cur = q.top(); q.pop();
            sunk++;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + (i == 2) - (i == 3);
                int ny = cur.y + (i == 0) - (i == 1);
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[current_level] = res - sunk;
        current_level++;
    }

    // Fill remaining years if Y is larger than levels processed
    for (int i = current_level; i <= Y; i++) {
        ans[i] = ans[current_level - 1];
    }

    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
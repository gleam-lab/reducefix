#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val; // Min-heap based on elevation
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

    priority_queue<Node> q;
    vector<vector<bool>> vis(h, vector<bool>(w, false));

    // Push all border cells into the priority queue
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                q.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, res); // ans[0] is initial state (sea level 0)

    for (int level = 1; level <= Y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
            ans[level]--; // Decrement the remaining area
            for (int k = 0; k < 4; k++) {
                int nx = cur.x + (k == 2) - (k == 3);
                int ny = cur.y + (k == 0) - (k == 1);
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        if (level < Y) {
            ans[level + 1] = ans[level]; // Carry forward if no more cells to process
        }
    }

    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
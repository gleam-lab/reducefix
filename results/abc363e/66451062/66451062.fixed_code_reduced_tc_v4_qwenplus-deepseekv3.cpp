#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 110
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

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
    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    // Edge case: 1x1 grid
    if (h == 1 && w == 1) {
        for (int i = 1; i <= Y; i++) {
            cout << (grid[0][0] > i ? 1 : 0) << endl;
        }
        return 0;
    }

    // Push all border cells into the priority queue
    for (int i = 0; i < h; i++) {
        q.push({i, 0, grid[i][0]});
        vis[i][0] = true;
        if (w > 1) {
            q.push({i, w-1, grid[i][w-1]});
            vis[i][w-1] = true;
        }
    }
    for (int j = 1; j < w-1; j++) {
        q.push({0, j, grid[0][j]});
        vis[0][j] = true;
        if (h > 1) {
            q.push({h-1, j, grid[h-1][j]});
            vis[h-1][j] = true;
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, res);
    int current_level = 1;

    while (current_level <= Y && !q.empty()) {
        while (!q.empty() && q.top().val <= current_level) {
            Node cur = q.top();
            q.pop();
            res--;
            for (int k = 0; k < 4; k++) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[current_level] = res;
        current_level++;
    }

    // Fill remaining levels if any
    for (int i = current_level; i <= Y; i++) {
        ans[i] = res;
    }

    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
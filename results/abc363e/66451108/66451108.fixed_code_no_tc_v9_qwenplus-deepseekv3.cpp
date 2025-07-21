#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val; // Min-heap based on val
    }
};

signed main() {
    close;
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
    
    // Push border cells into the priority queue
    for (int i = 0; i < h; ++i) {
        q.push({i, 0, grid[i][0]});
        q.push({i, w - 1, grid[i][w - 1]});
        vis[i][0] = true;
        vis[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; ++j) {
        q.push({0, j, grid[0][j]});
        q.push({h - 1, j, grid[h - 1][j]});
        vis[0][j] = true;
        vis[h - 1][j] = true;
    }

    int res = h * w;
    int current_level = 1;
    int sunk = 0;

    while (current_level <= y) {
        while (!q.empty() && q.top().val <= current_level) {
            Node cur = q.top();
            q.pop();
            sunk++;
            for (int i = 0; i < 4; ++i) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << res - sunk << endl;
        current_level++;
    }
    
    return 0;
}
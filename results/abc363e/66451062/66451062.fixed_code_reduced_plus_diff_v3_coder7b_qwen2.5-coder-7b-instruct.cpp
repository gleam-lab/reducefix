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
    bool operator<(const Node& a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(h, vector<bool>(w, false));
    priority_queue<Node> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            q.push({i, j, grid[i][j]});
            vis[i][j] = true;
        }
    }

    int res = h * w;
    for (int level = 1; level <= y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
            res--;

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d], ny = cur.y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && grid[nx][ny] <= level) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
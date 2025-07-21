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
        return val > a.val || (val == a.val && (x > a.x || (x == a.x && y > a.y)));
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
    priority_queue<Node> q;
    memset(grid[0].data(), 0, sizeof(grid[0]));
    memset(grid[h - 1].data(), 0, sizeof(grid[h - 1]));
    memset(grid[0][0], 0, sizeof(grid[0][0]));
    memset(grid[h - 1][w - 1], 0, sizeof(grid[h - 1][w - 1]));
    for (int i = 1; i < w - 1; i++) {
        memset(grid[0].data() + i * sizeof(int), 0, sizeof(int));
        memset(grid[h - 1].data() + i * sizeof(int), 0, sizeof(int));
    }
    q.push({0, 0, grid[0][0]});
    q.push({0, w - 1, grid[0][w - 1]});
    q.push({h - 1, 0, grid[h - 1][0]});
    q.push({h - 1, w - 1, grid[h - 1][w - 1]});
    int res = h * w;
    for (int level = 1; level <= y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
            res -= 1;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] > level && grid[nx][ny] != 0) {
                    grid[nx][ny] = 0;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
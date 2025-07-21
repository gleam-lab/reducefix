#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1010
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
        return val > a.val; // Min-heap based on elevation
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    bool vis[MAXN][MAXN] = {false};
    priority_queue<Node> q;
    
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
    vector<int> ans(y + 1, 0); // ans[0] is unused, ans[1] is year 1
    
    for (int level = 1; level <= y; level++) {
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
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
        ans[level] = res;
    }
    
    for (int i = 1; i <= y; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}
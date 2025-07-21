#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
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
    int h, w, Y;
    cin >> h >> w >> Y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    
    bool vis[MAXN][MAXN] = {false};
    priority_queue<Node> q;
    
    for (int i = 0; i < h; i++) {
        if (!vis[i][0]) {
            q.push({i, 0, grid[i][0]});
            vis[i][0] = true;
        }
        if (!vis[i][w - 1]) {
            q.push({i, w - 1, grid[i][w - 1]});
            vis[i][w - 1] = true;
        }
    }
    for (int j = 1; j < w - 1; j++) {
        if (!vis[0][j]) {
            q.push({0, j, grid[0][j]});
            vis[0][j] = true;
        }
        if (!vis[h - 1][j]) {
            q.push({h - 1, j, grid[h - 1][j]});
            vis[h - 1][j] = true;
        }
    }
    
    int res = h * w;
    vector<int> ans(Y + 1, 0);
    int current_level = 1;
    int current_res = res;
    
    while (current_level <= Y && !q.empty()) {
        while (!q.empty() && q.top().val <= current_level) {
            Node cur = q.top();
            q.pop();
            current_res--;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[current_level] = current_res;
        current_level++;
    }
    
    for (int i = 1; i <= Y; i++) {
        if (i < current_level) {
            cout << ans[i] << endl;
        } else {
            cout << ans[current_level - 1] << endl;
        }
    }
    
    return 0;
}
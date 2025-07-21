#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1010
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] =  {0,0,1,-1};
int dy[] = {1,-1,0,0};
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
        if (!vis[i][0]) {
            vis[i][0] = true;
            q.push({i, 0, grid[i][0]});
        }
        if (!vis[i][w-1]) {
            vis[i][w-1] = true;
            q.push({i, w-1, grid[i][w-1]});
        }
    }
    for (int j = 1; j < w - 1; j++) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            q.push({0, j, grid[0][j]});
        }
        if (!vis[h-1][j]) {
            vis[h-1][j] = true;
            q.push({h-1, j, grid[h-1][j]});
        }
    }

    int res = h * w;
    vector<int> ans(Y + 1, 0);
    int current_level = 1;

    for (int year = 1; year <= Y; year++) {
        while (!q.empty() && q.top().val <= year) {
            Node cur = q.top(); q.pop();
            res--;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = res;
    }

    for (int i = 1; i <= Y; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
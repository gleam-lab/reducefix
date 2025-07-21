#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1005;
int H, W, Y;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    priority_queue<Node> pq;

    // Push all boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y + 2, remaining);  // ans[year] = area
    int level = 0;

    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top(); pq.pop();
            if (!vis[cur.x][cur.y]) continue;
            ans[year]++;
            for (int d = 0; d < 4; ++d) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << ans[year] << "\n";
    }

    return 0;
}
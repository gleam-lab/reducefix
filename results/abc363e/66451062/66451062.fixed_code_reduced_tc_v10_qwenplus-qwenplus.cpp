#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
const int MAXN = 1005;
const int MOD = 1e9 + 7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int H, W, Y;
    cin >> H >> W >> Y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    bool vis[MAXN][MAXN] = {};
    priority_queue<Node> pq;

    // Push all the boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                pq.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y + 2);

    // Process levels using Dijkstra-like BFS with sea level rising
    for (int year = 1; !pq.empty() && year <= Y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top(); pq.pop();
            if (!vis[cur.x][cur.y]) continue;
            remaining--;

            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = remaining;
    }

    // For years beyond what we processed, output the last computed value
    for (int i = 1; i <= Y; ++i) {
        if (ans[i] == 0) ans[i] = ans[i - 1];
        cout << ans[i] << endl;
    }

    return 0;
}
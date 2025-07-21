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

    priority_queue<Node> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int total = H * W;
    vector<int> ans(Y + 2); // Store answers for all years

    int level = 1;
    while (!pq.empty()) {
        while (!pq.empty() && pq.top().val <= level) {
            auto cur = pq.top(); pq.pop();
            total--;
            for (int d = 0; d < 4; ++d) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[level] = total;
        level++;
    }

    // For levels beyond the max height in the queue, island size remains same
    while (level <= Y) {
        ans[level] = total;
        level++;
    }

    for (int i = 1; i <= Y; ++i)
        cout << ans[i] << '\n';

    return 0;
}
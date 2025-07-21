#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MAXN = 1005;
const int inf = 0x3f3f3f3f3f3f;

struct Cell {
    int h, x, y;
    bool operator<(const Cell& o) const { return h < o.h; }
};

int H, W, Y;
bool vis[MAXN][MAXN];
int grid[MAXN][MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    close;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    vector<Cell> cells;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || j == 0 || i == H - 1 || j == W - 1) {
                cells.push_back({grid[i][j], i, j});
                vis[i][j] = true;
            }
        }
    }

    // Sort all boundary cells by height
    sort(cells.begin(), cells.end());

    int area = H * W;
    int idx = 0;
    int res[Y + 2];  // Store results for each year

    // Precompute when each cell is submerged
    for (int i = 0; i <= Y; ++i) res[i] = area;

    // Process using BFS with priority to height
    queue<pair<int, int>> q;
    for (auto c : cells) {
        if (c.h <= Y) res[c.h]--;
        q.push({c.x, c.y});
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                int h = grid[nx][ny];
                if (h <= Y) res[h]--;
                q.push({nx, ny});
            }
        }
    }

    // Accumulate results
    for (int i = 1; i <= Y; ++i) {
        res[i] = min(res[i], res[i - 1]);
        cout << res[i] << '\n';
    }

    return 0;
}
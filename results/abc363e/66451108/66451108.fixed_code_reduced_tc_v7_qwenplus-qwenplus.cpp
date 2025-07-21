#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1005;
int H, W, Y;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Cell {
    int r, c, val;
    bool operator<(const Cell& other) const {
        return val > other.val;
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

    // Priority queue to process cells in increasing order of elevation
    priority_queue<Cell> pq;
    memset(vis, false, sizeof(vis));

    // Mark and add boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int remaining = H * W;
    int res[Y + 1];  // res[level] stores area after level years

    int year = 1;
    while (!pq.empty()) {
        Cell cur = pq.top();
        pq.pop();

        // Process all cells up to current sea level
        while (year <= cur.val) {
            res[year] = remaining;
            ++year;
        }

        // Flood fill
        for (int k = 0; k < 4; ++k) {
            int nx = cur.r + dx[k];
            int ny = cur.c + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    // Fill remaining years with final result
    while (year <= Y) {
        res[year++] = remaining;
    }

    // Output results
    for (int i = 1; i <= Y; ++i)
        cout << res[i] << "\n";

    return 0;
}
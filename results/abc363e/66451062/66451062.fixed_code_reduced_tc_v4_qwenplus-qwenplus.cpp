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

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    // Initialize a min-heap priority queue with all boundary cells
    priority_queue<Cell> pq;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int total = H * W;
    vector<int> ans(Y + 2); // To store answer for each year

    int level = 1;
    for (int year = 1; year <= Y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Cell cur = pq.top(); pq.pop();
            if (!vis[cur.r][cur.c]) continue;
            total--;

            for (int d = 0; d < 4; ++d) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({nr, nc, grid[nr][nc]});
                }
            }
        }
        ans[year] = total;
    }

    for (int i = 1; i <= Y; ++i)
        cout << ans[i] << '\n';

    return 0;
}
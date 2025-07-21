#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1005;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int H, W, Y;

struct Cell {
    int r, c, val;
    bool operator<(const Cell& other) const {
        return val > other.val;
    }
};

bool inBounds(int r, int c) {
    return r >= 0 && r < H && c >= 0 && c < W;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Cell> pq;
    bool vis[MAXN][MAXN] = {};
    int total = H * W;

    // Initialize the queue with border cells
    for (int i = 0; i < H; ++i) {
        if (!vis[i][0]) {
            vis[i][0] = true;
            pq.push({i, 0, grid[i][0]});
        }
        if (!vis[i][W-1]) {
            vis[i][W-1] = true;
            pq.push({i, W-1, grid[i][W-1]});
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        if (!vis[0][j]) {
            vis[0][j] = true;
            pq.push({0, j, grid[0][j]});
        }
        if (!vis[H-1][j]) {
            vis[H-1][j] = true;
            pq.push({H-1, j, grid[H-1][j]});
        }
    }

    int year = 1;
    vector<int> ans(Y + 2, 0);
    int idx = 0;

    while (!pq.empty()) {
        Cell cur = pq.top(); pq.pop();
        while (year <= cur.val) {
            ans[year] = total;
            year++;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = cur.r + dx[d];
            int nc = cur.c + dy[d];
            if (inBounds(nr, nc) && !vis[nr][nc]) {
                vis[nr][nc] = true;
                pq.push({nr, nc, grid[nr][nc]});
                total--;
            }
        }
    }

    while (year <= Y) {
        ans[year++] = total;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
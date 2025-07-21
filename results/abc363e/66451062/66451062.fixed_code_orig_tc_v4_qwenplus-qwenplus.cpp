#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MAXN = 1005;

int H, W, Y;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Cell {
    int x, y, h;
    bool operator<(const Cell& other) const {
        return h > other.h;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    close;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    priority_queue<Cell> pq;
    // Initialize the queue with all border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int total = H * W;
    vector<int> ans(Y + 2, 0);

    int current_level = 1;
    while (!pq.empty()) {
        auto [x, y, h] = pq.top();
        pq.pop();

        while (current_level <= h) {
            ans[current_level++] = total;
        }

        total--;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    while (current_level <= Y) {
        ans[current_level++] = total;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}
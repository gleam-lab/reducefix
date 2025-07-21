#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXH = 1005;
const int MAXW = 1005;

int H, W, Y;
int grid[MAXH][MAXW];
bool vis[MAXH][MAXW];

struct Cell {
    int r, c, val;
    bool operator<(const Cell& other) const {
        return val > other.val; // Min-heap
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Cell> pq;
    // Mark and push all boundary cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int total = H * W;
    vector<int> ans(Y + 2); // ans[level] = remaining area
    int current_year = 0;
    int res = total;

    while (!pq.empty()) {
        Cell cur = pq.top();
        pq.pop();

        // If the current cell's value is <= current year, it would have already been flooded
        while (current_year < cur.val) {
            current_year++;
            ans[current_year] = res;
        }

        if (!vis[cur.r][cur.c]) {
            vis[cur.r][cur.c] = true;
            res--;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = cur.r + dx[k];
            int ny = cur.c + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    // Fill in any remaining years
    while (current_year < Y) {
        current_year++;
        ans[current_year] = res;
    }

    // Output
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
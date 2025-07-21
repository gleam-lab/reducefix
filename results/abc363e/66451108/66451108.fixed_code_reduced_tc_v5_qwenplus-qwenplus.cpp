#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXH = 1005;
const int MAXW = 1005;

int H, W, Y;
int grid[MAXH][MAXW];
bool vis[MAXH][MAXW];

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
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
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

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

    int total = H * W;
    vector<int> ans(Y + 2); // To store answer for each year
    int level = 0;
    int year = 1;

    // Process in order of increasing elevation
    while (!pq.empty() && year <= Y) {
        while (!pq.empty() && pq.top().val <= year) {
            auto cur = pq.top(); pq.pop();
            if (cur.val > level) {
                // Fill everything up to this elevation
                for (int l = level + 1; l <= cur.val && l <= Y; ++l) {
                    ans[l] = total;
                }
                level = cur.val;
                year = min(Y + 1LL, level + 1);
            }
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
        if (year <= Y) {
            ans[year] = total;
            year++;
        }
    }

    // Fill remaining years with final value
    for (int l = level + 1; l <= Y; ++l) {
        ans[l] = total;
    }

    // Output results
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
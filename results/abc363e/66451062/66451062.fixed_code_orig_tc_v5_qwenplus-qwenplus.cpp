#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int H = 1100, W = 1100;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Node {
    int x, y, val;
    bool operator < (const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w, y;
    cin >> h >> w >> y;
    int grid[H][W];
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> grid[i][j];

    bool vis[H][W];
    memset(vis, false, sizeof(vis));

    priority_queue<Node> pq;
    // Push all boundary cells into the priority queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int total = h * w;
    int seaLevel = 1;
    vector<int> ans(y + 2);

    // We process up to Y years
    for (int year = 1; year <= y; ++year) {
        while (!pq.empty() && pq.top().val <= year) {
            Node cur = pq.top(); pq.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[year] = total - pq.size();
    }

    for (int year = 1; year <= y; ++year)
        cout << ans[year] << endl;

    return 0;
}
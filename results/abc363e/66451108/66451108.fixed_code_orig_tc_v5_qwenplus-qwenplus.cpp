#include <bits/stdc++.h>
using namespace std;

#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

    int grid[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    bool vis[h][w];
    memset(vis, false, sizeof(vis));

    priority_queue<Node> pq;
    // Push all boundary cells into the priority queue
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int total_area = h * w;
    int res[100005] = {0};  // To store results for each year

    // We'll simulate until the queue is empty
    for (int year = 1; year <= y; ++year) {
        // Process all nodes with value <= current sea level (year)
        while (!pq.empty() && pq.top().val <= year) {
            auto cur = pq.top(); pq.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
            total_area--;
        }
        res[year] = total_area;
    }

    // Output the results
    for (int i = 1; i <= y; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}
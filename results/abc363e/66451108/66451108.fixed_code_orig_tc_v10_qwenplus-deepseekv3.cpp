#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f
#define endl '\n'
const double eps = 1e-7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int MOD = 1e9 + 7;

struct Node {
    int x, y, val;
    bool operator<(const Node &a) const {
        return val > a.val;
    }
};

signed main() {
    close;
    int h, w; cin >> h >> w;
    int y; cin >> y;
    int grid[MAXN][MAXN];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    bool vis[MAXN][MAXN] = {false};
    priority_queue<Node> q;
    
    // Push all border cells into the priority queue
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                q.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int res = h * w;
    for (int level = 1; level <= y; level++) {
        queue<pair<int, int>> to_process;
        
        // Process all cells that will sink at this level
        while (!q.empty() && q.top().val <= level) {
            Node cur = q.top(); q.pop();
            to_process.push({cur.x, cur.y});
            res--;
        }
        
        // Process all adjacent cells that will sink due to the current sinking
        while (!to_process.empty()) {
            auto [x, y] = to_process.front(); to_process.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    if (grid[nx][ny] <= level) {
                        res--;
                        to_process.push({nx, ny});
                    } else {
                        q.push({nx, ny, grid[nx][ny]});
                    }
                }
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
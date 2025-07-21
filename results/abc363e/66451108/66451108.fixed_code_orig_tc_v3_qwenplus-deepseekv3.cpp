#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
#define LIMIT 22
#define inf 0x3f3f3f3f3f3f3f3f
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
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    priority_queue<Node> pq;
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    int res = h * w;

    // Initialize the priority queue with boundary cells
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push({i, j, grid[i][j]});
                vis[i][j] = true;
            }
        }
    }

    int current_level = 1;
    vector<int> ans(y + 1, res);
    ans[0] = res;

    while (!pq.empty() && current_level <= y) {
        while (!pq.empty() && pq.top().val <= current_level) {
            Node cur = pq.top();
            pq.pop();
            res--;
            for (int k = 0; k < 4; k++) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        ans[current_level] = res;
        current_level++;
    }

    for (int i = 1; i <= y; i++) {
        if (i < current_level) {
            cout << ans[i] << endl;
        } else {
            cout << ans[current_level - 1] << endl;
        }
    }

    return 0;
}
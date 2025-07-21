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
    int Y; cin >> Y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> sunk(h, vector<bool>(w, false));
    priority_queue<Node> pq;
    for (int i = 0; i < h; i++) {
        pq.push({i, 0, grid[i][0]});
        pq.push({i, w - 1, grid[i][w - 1]});
        sunk[i][0] = sunk[i][w - 1] = true;
    }
    for (int j = 1; j < w - 1; j++) {
        pq.push({0, j, grid[0][j]});
        pq.push({h - 1, j, grid[h - 1][j]});
        sunk[0][j] = sunk[h - 1][j] = true;
    }

    int res = h * w;
    for (int level = 1; level <= Y; level++) {
        while (!pq.empty() && pq.top().val <= level) {
            Node cur = pq.top(); pq.pop();
            res--;
            for (int k = 0; k < 4; k++) {
                int nx = cur.x + dx[k];
                int ny = cur.y + dy[k];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !sunk[nx][ny]) {
                    sunk[nx][ny] = true;
                    pq.push({nx, ny, grid[nx][ny]});
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
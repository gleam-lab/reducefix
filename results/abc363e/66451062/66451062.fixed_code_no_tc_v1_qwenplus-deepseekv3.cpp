#include <bits/stdc++.h>
using namespace std;
#define int long long
#define close ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1005
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
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> earliest(h, vector<int>(w, inf));
    priority_queue<Node> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                earliest[i][j] = grid[i][j];
                q.push({i, j, earliest[i][j]});
            }
        }
    }

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                int new_earliest = max(earliest[cur.x][cur.y], grid[nx][ny]);
                if (new_earliest < earliest[nx][ny]) {
                    earliest[nx][ny] = new_earliest;
                    q.push({nx, ny, earliest[nx][ny]});
                }
            }
        }
    }

    vector<int> cnt(1e5 + 2, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cnt[earliest[i][j]]++;
        }
    }

    int total = h * w;
    vector<int> res(y + 1);
    for (int i = 1; i <= y; i++) {
        if (i <= 1e5) {
            total -= cnt[i];
        }
        res[i] = total;
    }

    for (int i = 1; i <= y; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
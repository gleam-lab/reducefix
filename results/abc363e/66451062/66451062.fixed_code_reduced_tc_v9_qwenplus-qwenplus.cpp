#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1010;

int H, W, Y;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node {
    int x, y, val;
    bool operator<(const Node& a) const {
        return val > a.val;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    priority_queue<Node> pq;
    memset(vis, false, sizeof(vis));

    // Initialize the border cells
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H-1 || j == 0 || j == W-1) {
                vis[i][j] = true;
                pq.push({i, j, grid[i][j]});
            }
        }
    }

    int remaining = H * W;
    vector<int> ans(Y+2, 0);
    int current_year = 1;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        
        // If elevation <= sea level, it's submerged
        while (current_year <= Y && cur.val > current_year) {
            ans[current_year] = remaining;
            current_year++;
        }
        ans[current_year-1] = remaining;

        remaining--;
        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                vis[nx][ny] = true;
                pq.push({nx, ny, grid[nx][ny]});
            }
        }
    }

    // Fill in any remaining years with the last known value
    while (current_year <= Y) {
        ans[current_year++] = remaining;
    }

    for (int i = 1; i <= Y; ++i)
        cout << ans[i] << '\n';

    return 0;
}
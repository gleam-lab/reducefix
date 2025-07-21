#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define endl '\n'
#define dx4 {0, 1, 0, -1}
#define dy4 {1, 0, -1, 0}

const int MOD = 1e9 + 7;
const int INF = 1e18;

int H, W, Y;

bool inside(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> grid[i][j];

    // Create a map of elevation -> list of coordinates
    vector<vector<pii>> elevMap(Y + 2); // up to Y+1
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            int e = grid[i][j];
            if (e <= Y)
                elevMap[e].emplace_back(i, j);
        }

    // Visited matrix
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // BFS queue
    queue<pii> q;

    // Mark border cells as visited and add to queue
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                vis[i][j] = true;
                q.emplace(i, j);
            }

    int remaining = H * W;
    vector<int> ans(Y + 1);

    // Prepare an array to store the current year's result
    function<void()> bfs = [&]() {
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx4[d];
                int ny = y + dy4[d];
                if (inside(nx, ny) && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                    remaining--;
                }
            }
        }
    };

    // Run through each year
    for (int year = 1; year <= Y; ++year) {
        remaining -= elevMap[year].size();
        for (auto [x, y] : elevMap[year]) {
            if (vis[x][y]) continue; // already submerged
            vis[x][y] = true;
            q.emplace(x, y);
        }
        bfs(); // perform BFS to flood connected regions
        ans[year] = remaining;
    }

    for (int i = 1; i <= Y; ++i)
        cout << ans[i] << endl;

    return 0;
}
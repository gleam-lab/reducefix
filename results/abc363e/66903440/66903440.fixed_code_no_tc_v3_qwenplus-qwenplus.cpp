#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) a.begin(), a.end()
#define pb push_back

using ll = long long;
const int INF = 1 << 30;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // visited array to mark if cell is already submerged
    vector<vector<bool>> vis(H, vector<bool>(W, false));

    // Queue for BFS grouped by elevation
    vector<queue<pair<int, int>>> q(Y + 2);  // up to Y+1 inclusive

    // Initialize the boundary cells into appropriate queues
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            if (A[i][j] <= Y) {
                q[A[i][j]].push({i, j});
            }
            vis[i][j] = true;
        }
    }

    int remaining = H * W;
    vector<int> ans(Y + 1);  // ans[year] stores area above water at that year

    // Process each sea level from 1 to Y
    for (int y = 1; y <= Y; ++y) {
        // Process all cells in current queue
        while (!q[y].empty()) {
            auto [x, y_coord] = q[y].front();
            q[y].pop();
            --remaining;

            // Check neighbors and add to queue if not yet submerged
            rep(dir, 4) {
                int nx = x + dx[dir];
                int ny = y_coord + dy[dir];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    if (A[nx][ny] <= Y) {
                        q[min(y, A[nx][ny])].push({nx, ny});
                    }
                }
            }
        }
        ans[y] = remaining;
    }

    // Output results for years 1 through Y
    for (int y = 1; y <= Y; ++y) {
        cout << ans[y] << "\n";
    }

    return 0;
}
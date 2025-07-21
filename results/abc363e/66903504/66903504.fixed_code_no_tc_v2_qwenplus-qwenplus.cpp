#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const int INF = 1000000001;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define all(x) x.begin(), x.end()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Remaining land cells
    int ans = H * W;
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // Queue for each height level
    vector<queue<pair<int, int>>> Q(Y + 2);

    // Mark border cells as sinking and add to respective queues
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            alive[i][j] = false;
            if (A[i][j] <= Y) {
                Q[A[i][j]].push({i, j});
            }
        }
    }

    // Direction vectors for BFS (only 4-directional)
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};

    // Process year by year
    for (int y = 1; y <= Y; ++y) {
        // Process all cells that sink this year
        while (!Q[y].empty()) {
            auto [x, y_coord] = Q[y].front();
            Q[y].pop();
            ans--;

            // Check neighbors
            rep(d, 4) {
                int nx = x + dx[d];
                int ny = y_coord + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && alive[nx][ny]) {
                    alive[nx][ny] = false;
                    int h = A[nx][ny];
                    if (h <= Y) {
                        Q[h].push({nx, ny});
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
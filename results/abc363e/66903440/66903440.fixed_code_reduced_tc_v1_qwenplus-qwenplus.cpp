#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

int H, W, Y;
const int MAX = 1e5 + 5;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Create a list of positions for each height
    vector<vector<pair<int, int>>> height_map(MAX);
    rep(i, H) rep(j, W) height_map[A[i][j]].push_back({i, j});

    // Initialize visited matrix
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Queue for BFS
    queue<pair<int, int>> q;

    // Process borders first
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H-1 || j == 0 || j == W-1) {
            visited[i][j] = true;
            q.push({i, j});
        }
    }

    // Array to store the remaining area for each year
    vector<int> ans(Y+2, H * W);

    // We'll keep track of how many cells are removed at each level
    vector<int> removed(MAX);

    // Use a pointer to process heights in increasing order
    for (int h = 1; h <= Y; ++h) {
        // Process all cells with height equal to current year
        for (auto &p : height_map[h]) {
            if (!visited[p.first][p.second]) {
                visited[p.first][p.second] = true;
                q.push(p);
            }
        }

        // BFS flood fill from the current border
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            --ans[h];
        }

        // For next year, we carry forward the previous count
        if (h < Y) ans[h+1] = ans[h];
    }

    // Print results
    for (int i = 1; i <= Y; ++i) cout << ans[i] << "\n";
}
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    // Initialize: true means the cell is still part of the island
    vector<vector<bool>> alive(H, vector<bool>(W, true));

    // For each elevation level, store list of cells with that elevation
    vector<vector<pair<int, int>>> level_cells(Y + 2);
    rep(i, H) rep(j, W) {
        if (A[i][j] <= Y) {
            level_cells[A[i][j]].push_back({i, j});
        }
    }

    // BFS queue
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initially mark border cells as visited (they will never sink completely by year Y)
    rep(i, H) rep(j, W) {
        if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
            visited[i][j] = true;
            q.push({i, j});
        }
    }

    // Process from sea level = 1 to Y
    int remaining = H * W;
    vector<int> result(Y + 1);

    for (int sea_level = 1; sea_level <= Y; ++sea_level) {
        // Add all cells with this elevation that are not yet visited to the queue
        for (auto [i, j] : level_cells[sea_level]) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }

        // BFS flood fill
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // If this cell was originally above water and now sinks
            if (alive[x][y]) {
                alive[x][y] = false;
                remaining--;
            }

            // Propagate to neighbors if they can also sink
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && A[nx][ny] <= sea_level) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        result[sea_level] = remaining;
    }

    for (int i = 1; i <= Y; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
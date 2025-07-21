#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize remaining area
    ll remaining = 1LL * H * W;
    vector<vector<bool>> is_submerged(H, vector<bool>(W, false));

    // Map from elevation to list of cells at that elevation
    map<int, vector<pair<int, int>>> elevations;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            elevations[A[i][j]].push_back({i, j});
        }
    }

    // Union-Find with BFS flood simulation
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> q;

    // Initially mark border cells as submerged
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }

    // Process all BFS levels corresponding to rising sea level
    vector<int> ans(Y + 2, 0);
    int current_year = 0;
    auto it = elevations.begin();

    while (current_year <= Y) {
        // Submerge all cells at or below current year
        while (it != elevations.end() && it->first <= current_year) {
            for (auto [x, y] : it->second) {
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
            ++it;
        }

        // Perform BFS to spread submersion
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};

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
        }

        // Count remaining land
        if (current_year >= 1)
            ans[current_year] = remaining;
        ++current_year;
    }

    // Output results
    for (int i = 1; i <= Y; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
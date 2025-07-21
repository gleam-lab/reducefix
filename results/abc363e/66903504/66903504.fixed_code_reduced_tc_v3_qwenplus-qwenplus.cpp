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

    // Total area of the island
    int ans = H * W;

    // Visited matrix to mark if a cell has sunk
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Queue for BFS processing
    queue<pair<int, int>> q;

    // Direction vectors for 4-directional movement
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    // Initialize: all edge cells sink first
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                visited[i][j] = true;
                q.emplace(i, j);
            }
        }
    }

    // Store heights with their coordinates
    vector<vector<int>> height(Y + 2);  // up to Y+1

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int h = A[i][j];
            if (h <= Y) {
                height[h].push_back(i * W + j);
            }
        }
    }

    // Process each year
    for (int y = 1; y <= Y; ++y) {
        // Add current year's sinking cells
        for (int val : height[y]) {
            int i = val / W;
            int j = val % W;
            if (!visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }

        // BFS from newly added cells
        while (!q.empty()) {
            auto [ci, cj] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ni = ci + dx[d];
                int nj = cj + dy[d];
                if (ni >= 0 && ni < H && nj >= 0 && nj < W && !visited[ni][nj]) {
                    if (A[ni][nj] <= y) {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                        ans--;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int H, W, Y;
const int MAX_A = 100005;
vector<vector<int>> A;
vector<vector<bool>> visited;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS queue for each elevation level
vector<queue<pair<int, int>>> levelQueues(MAX_A);

void processYear(int y) {
    while (!levelQueues[y].empty()) {
        auto [r, c] = levelQueues[y].front();
        levelQueues[y].pop();

        // This cell is now submerged
        visited[r][c] = true;

        // Check neighbors and flood if possible
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && !visited[nr][nc]) {
                int h = A[nr][nc];
                if (h <= Y) {
                    // This will be processed in the appropriate year
                    levelQueues[max(y, h)].push({nr, nc});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    visited.resize(H, vector<bool>(W, false));

    // Read input
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Initialize borders
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                levelQueues[A[i][j]].push({i, j});
                visited[i][j] = true;
            }
        }
    }

    // Total land cells
    ll total = 1LL * H * W;

    // We'll track area changes
    vector<ll> result(Y + 1, 0);
    ll submerged = 0;

    // Process from year 1 to Y
    for (int y = 1; y <= Y; ++y) {
        processYear(y);
        submerged += levelQueues[y].size();  // Count how many were submerged this year
        result[y] = total - submerged;
    }

    // Output results from year 1 to Y
    for (int y = 1; y <= Y; ++y) {
        cout << result[y] << "\n";
    }

    return 0;
}
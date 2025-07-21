#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    // Precompute the maximum elevation that can be submerged by Y years
    vector<vector<int>> dp(H, vector<int>(W, -1));
    queue<pair<int, int>> q;

    // Initialize the queue for the BFS
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] > 0) {
                dp[i][j] = grid[i][j];
                q.push({i, j});
            }
        }
    }

    // Perform BFS to propagate the submerged elevations
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if (dp[nx][ny] == -1 || dp[nx][ny] < dp[x][y] + 1) {
                        dp[nx][ny] = dp[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }

    // Calculate the remaining area after Y years
    long long remaining_area = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] > dp[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output the remaining area for each year
    for (int y = 0; y < Y; y++) {
        cout << remaining_area << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Directions for moving to adjacent cells (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // Queue to manage cells that will sink each year
    queue<pair<int, int>> q;

    // Mark cells adjacent to the edges (sea level) as initially sinking
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
                q.push({i, j});
            }
        }
    }

    // Water level starts at 0
    int waterLevel = 0;
    // Area of the island that remains above water
    int remainingArea = H * W;

    while (!q.empty()) {
        int currentYear = waterLevel + 1;
        int queueSize = q.size();
        for (int i = 0; i < queueSize; ++i) {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check boundaries
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

                // Check if the adjacent cell sinks
                if (A[nx][ny] <= currentYear) {
                    // Add to queue for the next year
                    q.push({nx, ny});
                }

                // Decrease the remaining area
                remainingArea--;
            }
        }

        // Output the remaining area after this year's sinking
        cout << remainingArea << '\n';
        // Increase water level for the next year
        waterLevel++;
    }

    return 0;
}
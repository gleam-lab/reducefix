#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // BFS to calculate areas at each sea level
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the BFS with the corners and edges of the island
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i == 0 || i == H - 1 || j == 0 || j == W - 1) && !visited[i][j]) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int currentSeaLevel = 0;
    int remainingArea = H * W;

    while (!q.empty() && currentSeaLevel < Y) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            auto [x, y] = q.front();
            q.pop();

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny]) {
                        if (grid[nx][ny] > currentSeaLevel) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        // After processing all sections at the current sea level, reduce the remaining area
        remainingArea -= levelSize;
        currentSeaLevel++;
    }

    // Output the remaining area for each year
    for (int i = 0; i < min(Y, currentSeaLevel); ++i) {
        cout << remainingArea << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    cin >> grid[0][0];

    for (int i = 1; i < H; ++i) {
        for (int j = 1; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    int totalArea = H * W;
    int remainingArea = totalArea;

    // Process each year
    for (int year = 1; year <= Y; ++year) {
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        stack<pair<int, int>> stack;
        int floodedArea = 0;

        // Perform a DFS to find areas that will flood this year
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] <= year && !visited[i][j]) {
                    stack.push({i, j});
                    visited[i][j] = true;
                    floodedArea++;
                    while (!stack.empty()) {
                        auto [x, y] = stack.top();
                        stack.pop();

                        // Check all 4 neighbors
                        for (int dx = -1; dx <= 1; ++dx) {
                            for (int dy = -1; dy <= 1; ++dy) {
                                int nx = x + dx, ny = y + dy;
                                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                                    if (grid[nx][ny] <= year && !visited[nx][ny]) {
                                        stack.push({nx, ny});
                                        visited[nx][ny] = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        remainingArea -= floodedArea;
        cout << remainingArea << endl;
    }

    return 0;
}
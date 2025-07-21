#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    set<pair<int, int>> sinking;
    queue<pair<int, int>> to_check;

    // Initialize the sinking sections at the edges
    for (int i = 0; i < H; ++i) {
        to_check.push({i, 0});
        to_check.push({i, W - 1});
        visited[i][0] = true;
        visited[i][W - 1] = true;
    }
    for (int j = 0; j < W; ++j) {
        to_check.push({0, j});
        to_check.push({H - 1, j});
        visited[0][j] = true;
        visited[H - 1][j] = true;
    }

    // Perform the simulation
    while (!to_check.empty()) {
        auto [x, y] = to_check.front();
        to_check.pop();
        sinking.insert({x, y});

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int nx = x + i, ny = y + j;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (!visited[nx][ny] && grid[nx][ny] < Y + 1) {
                    to_check.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    // Calculate the remaining area
    int remaining_area = H * W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (sinking.count({i, j})) {
                remaining_area--;
            }
        }
    }

    cout << remaining_area << endl;
    return 0;
}
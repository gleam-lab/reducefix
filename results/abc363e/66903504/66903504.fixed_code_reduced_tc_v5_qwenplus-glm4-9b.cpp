#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_H = 1000;
const int MAX_W = 1000;

int H, W, Y;
vector<vector<int>> grid(MAX_H, vector<int>(MAX_W));
vector<vector<bool>> visited(MAX_H, vector<bool>(MAX_W, false));
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

void simulateSinking(int year) {
    queue<pair<int, int>> q;
    // Initialize queue with edge cells
    for (int i = 0; i < H; ++i) {
        q.push({i, 0});
        q.push({i, W - 1});
    }
    for (int j = 1; j < W - 1; ++j) {
        q.push({0, j});
        q.push({H - 1, j});
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto& dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (!visited[nx][ny] && grid[nx][ny] <= year) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int y = 1; y <= Y; ++y) {
        simulateSinking(y);
        int remainingArea = H * W;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!visited[i][j]) {
                    remainingArea--;
                }
            }
        }
        cout << remainingArea << endl;
        // Reset visited grid for next year
        fill(visited[0].begin(), visited[0].end(), false);
    }

    return 0;
}
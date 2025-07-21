#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool withinBounds(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

int floodFill(vector<vector<int>>& grid, int H, int W, int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    q.push({x, y});
    vis[x][y] = true;
    int area = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (auto [dx, dy] : d) {
            int nx = cx + dx, ny = cy + dy;
            if (withinBounds(nx, ny, H, W) && !vis[nx][ny] && grid[nx][ny] <= grid[cx][cy]) {
                vis[nx][ny] = true;
                q.push({nx, ny});
                area++;
            }
        }
    }

    return area;
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    int remainingArea = H * W;

    for (int year = 1; year <= Y; ++year) {
        int newRemainingArea = remainingArea;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(H, vector<bool>(W, false));

        // Use a BFS to find all cells that are at or below sea level
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] <= year && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : d) {
                int nx = x + dx, ny = y + dy;
                if (withinBounds(nx, ny, H, W) && !vis[nx][ny] && grid[nx][ny] <= grid[x][y]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // Calculate the new remaining area
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!vis[i][j]) {
                    newRemainingArea -= floodFill(grid, H, W, i, j);
                }
            }
        }

        remainingArea = newRemainingArea;
        cout << remainingArea << "\n";
    }

    return 0;
}
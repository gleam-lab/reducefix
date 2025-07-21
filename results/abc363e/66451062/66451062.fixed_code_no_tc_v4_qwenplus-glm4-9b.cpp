#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 1005

int h, w, y;
vector<vector<int>> grid;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int main() {
    cin >> h >> w >> y;
    grid.resize(h, vector<int>(w));
    visited.resize(h, vector<bool>(w, false));

    // Input the grid and initialize the queue with edges
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    // Directions for neighbors (right, left, down, up)
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // Initialize queue with edge elements
    for (int i = 0; i < h; ++i) {
        q.push({i, 0});
        visited[i][0] = true;
    }
    for (int i = 0; i < w; ++i) {
        q.push({0, i});
        visited[0][i] = true;
    }
    for (int i = 0; i < h; ++i) {
        q.push({i, w - 1});
        visited[i][w - 1] = true;
    }
    for (int i = 0; i < w - 1; ++i) {
        q.push({h - 1, i});
        visited[h - 1][i] = true;
    }

    int currentLevel = 1;
    int remainingArea = h * w;

    while (!q.empty()) {
        vector<pair<int, int>> next LevelNeighbors;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (grid[x][y] <= currentLevel) {
                remainingArea--;
            }
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= currentLevel) {
                    visited[nx][ny] = true;
                    next LevelNeighbors.emplace_back(nx, ny);
                }
            }
        }
        if (!next LevelNeighbors.empty()) {
            q = next LevelNeighbors;
        }
        if (currentLevel == y) {
            cout << remainingArea << '\n';
            return 0;
        }
        currentLevel++;
    }

    return 0;
}
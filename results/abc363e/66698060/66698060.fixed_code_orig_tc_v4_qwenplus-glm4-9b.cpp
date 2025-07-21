#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sinkIsland(vector<vector<int>>& grid, int h, int w) {
    queue<pair<int, int>> q;
    // Mark the sections adjacent to sea or with the lowest elevation as sunk
    for (int i = 0; i < h; ++i) {
        if (grid[i][0] <= 0) q.push({i, 0});
        if (grid[i][w-1] <= 0) q.push({i, w-1});
    }
    for (int j = 1; j < w-1; ++j) {
        if (grid[0][j] <= 0) q.push({0, j});
        if (grid[h-1][j] <= 0) q.push({h-1, j});
    }

    // Simulate sinking
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (visited[i][j]) continue;
        visited[i][j] = true;
        // Check adjacent sections
        if (i > 0 && !visited[i-1][j] && grid[i-1][j] <= 0) q.push({i-1, j});
        if (i < h-1 && !visited[i+1][j] && grid[i+1][j] <= 0) q.push({i+1, j});
        if (j > 0 && !visited[i][j-1] && grid[i][j-1] <= 0) q.push({i, j-1});
        if (j < w-1 && !visited[i][j+1] && grid[i][j+1] <= 0) q.push({i, j+1});
    }
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int year = 0; year < y; ++year) {
        sinkIsland(grid, h, w);
        int remainingArea = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > 0) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }

    return 0;
}
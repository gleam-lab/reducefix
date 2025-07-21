#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void simulateSinking(int H, int W, vector<vector<int>>& grid, int Y) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    // Initialize the queue and the visited array with the border sections of the grid
    // (sections adjacent to the sea or the grid's edge)
    for (int i = 0; i < H; ++i) {
        visited[i][0] = visited[i][W - 1] = true;
        q.push({i, 0});
        q.push({i, W - 1});
    }
    for (int i = 1; i < W - 1; ++i) {
        visited[0][i] = visited[H - 1][i] = true;
        q.push({0, i});
        q.push({H - 1, i});
    }

    int remainingArea = H * W; // Initial area of the island

    for (int year = 1; year <= Y; ++year) {
        int newSunkArea = 0;
        int currentYearLevel = year;
        queue<pair<int, int>> nextQueue;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Check all adjacent sections
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= currentYearLevel) {
                        visited[nx][ny] = true;
                        nextQueue.push({nx, ny});
                        newSunkArea++;
                    }
                }
            }
        }

        remainingArea -= newSunkArea;
        q = nextQueue;

        cout << remainingArea << endl;
    }
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

    simulateSinking(H, W, grid, Y);

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1005;
vector<vector<int>> grid(MAXN);
vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
int h, w, y;

void floodFill(int r, int c, int level) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i, ny = y + j;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || grid[nx][ny] <= level) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    for (int level = 1; level <= y; level++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                visited[i][j] = false;
            }
        }

        // Find the highest point on the grid
        int maxPoint = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] > maxPoint) {
                    maxPoint = grid[i][j];
                }
            }
        }

        // Perform flood fill from the highest point down to the sea level
        for (int r = maxPoint; r >= level; r--) {
            for (int j = 0; j < w; j++) {
                if (!visited[r][j] && grid[r][j] > level) {
                    floodFill(r, j, level);
                }
            }
        }

        // Calculate the remaining area
        int remainingArea = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j]) {
                    remainingArea++;
                }
            }
        }

        cout << remainingArea << endl;
    }

    return 0;
}
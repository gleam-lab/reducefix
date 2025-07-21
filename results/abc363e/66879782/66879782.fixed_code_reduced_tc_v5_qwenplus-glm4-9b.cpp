#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    // Initialize the grid with elevations and identify the seaè¾¹ç
    queue<pair<int, int>> q; // queue of pairs (row, col)
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            // If the cell is on the boundary or adjacent to an already sunk cell
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1 || (i > 0 && grid[i - 1][j] == -1) || (i < h - 1 && grid[i + 1][j] == -1) ||
                (j > 0 && grid[i][j - 1] == -1) || (j < w - 1 && grid[i][j + 1] == -1)) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // BFS to simulate the sinking
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc]) continue;
                if (grid[nr][nc] <= grid[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    // Calculate the area of the island remaining above sea level
    int area = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j]) {
                area++;
            }
        }
    }

    // Output the result for each year
    for (int i = 0; i < y; i++) {
        cout << area << '\n';
    }

    return 0;
}
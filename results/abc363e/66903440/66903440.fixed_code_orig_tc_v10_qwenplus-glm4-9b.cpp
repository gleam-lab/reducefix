#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    queue<pair<int, int>> q;
    int total_area = 0;
    int count = 0;

    // Read grid and identify the sections that are not at the sea level
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] > 0) {
                q.push({i, j});
                visited[i][j] = true;
                total_area++;
            }
        }
    }

    // Perform BFS to simulate the sinking
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + 1, ny = y + k;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if (grid[nx][ny] > grid[x][y]) {
                    count++;
                }
            }

            nx = x - 1, ny = y + k;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if (grid[nx][ny] > grid[x][y]) {
                    count++;
                }
            }

            nx = x + k, ny = y + 1;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if (grid[nx][ny] > grid[x][y]) {
                    count++;
                }
            }

            nx = x + k, ny = y - 1;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if (grid[nx][ny] > grid[x][y]) {
                    count++;
                }
            }
        }
    }

    // Output the remaining area after the specified number of years
    for (int y = 0; y < Y; ++y) {
        cout << (total_area - count) << endl;
    }

    return 0;
}
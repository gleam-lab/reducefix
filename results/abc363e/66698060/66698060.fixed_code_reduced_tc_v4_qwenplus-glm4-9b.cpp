#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Directions for BFS (right, down, left, up)
    vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    
    // Start BFS from the boundary cells that are above the sea level
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            // Check if the cell is on the boundary and above the sea level
            if ((i == 0 || j == 0 || j == w - 1 || i == h - 1) && grid[i][j] > 0) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    // Array to store the area of the island above sea level for each year
    vector<long long> remaining_areas(y);
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        for (auto& dir : directions) {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    // Calculate the remaining area for each year
    long long current_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                current_area++;
                grid[i][j] -= 1; // Simulate the sinking
            }
        }
    }
    
    remaining_areas[0] = current_area;
    for (int year = 1; year < y; ++year) {
        current_area = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    current_area++;
                    grid[i][j] -= 1; // Simulate the sinking
                }
            }
        }
        remaining_areas[year] = current_area;
    }
    
    // Output the results
    for (int year = 0; year < y; ++year) {
        cout << remaining_areas[year] << endl;
    }
    
    return 0;
}
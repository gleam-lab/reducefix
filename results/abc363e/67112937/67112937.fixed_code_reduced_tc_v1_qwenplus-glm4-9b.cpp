#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    for (int year = 0; year < Y; ++year) {
        queue<pair<int, int>> q;
        int sunk_area = 0;
        
        // Enqueue all cells that are at or below the current sea level (year)
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (grid[i][j] <= year) {
                    q.push({i, j});
                    visited[i][j] = true;
                    ++sunk_area;
                }
            }
        }
        
        // Perform BFS to sink all connected cells below the current sea level
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= year) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                        ++sunk_area;
                    }
                }
            }
        }
        
        // Output the remaining area
        cout << (H * W - sunk_area) << endl;
    }
    
    return 0;
}
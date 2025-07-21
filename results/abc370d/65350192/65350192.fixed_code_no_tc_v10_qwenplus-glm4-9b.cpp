#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<int>> grid(h, vector<int>(w));
    for (auto &row : grid) {
        for (int &cell : row) {
            cell = -1; // -1 indicates a wall
        }
    }
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = -1; // Initialize all cells with walls
        }
    }
    
    int remainingWalls = h * w; // Initially, all cells have walls
    
    for (int q_num = 0; q_num < q; ++q_num) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to zero-based index
        
        if (grid[r][c] == -1) { // If there's a wall at (r, c)
            grid[r][c] = 0; // Remove the wall
            remainingWalls--;
        } else { // No wall at (r, c)
            // Find the nearest wall in all four directions
            // Check down
            int down = r + 1;
            while (down < h && grid[down][c] != -1) {
                grid[down][c] = 0; // Remove the wall
                remainingWalls--;
                down++;
            }
            
            // Check up
            int up = r - 1;
            while (up >= 0 && grid[up][c] != -1) {
                grid[up][c] = 0; // Remove the wall
                remainingWalls--;
                up--;
            }
            
            // Check right
            int right = c + 1;
            while (right < w && grid[r][right] != -1) {
                grid[r][right] = 0; // Remove the wall
                remainingWalls--;
                right++;
            }
            
            // Check left
            int left = c - 1;
            while (left >= 0 && grid[r][left] != -1) {
                grid[r][left] = 0; // Remove the wall
                remainingWalls--;
                left--;
            }
        }
    }
    
    cout << remainingWalls << endl;
    return 0;
}
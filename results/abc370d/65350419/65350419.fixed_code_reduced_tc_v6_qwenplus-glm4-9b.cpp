#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Initialize the walls grid
    vector<vector<bool>> grid(h + 1, vector<bool>(w + 1, true));
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            grid[i][j] = true; // All cells have walls initially
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        
        // Find and remove the wall at (r, c)
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            // Remove the first wall in each direction
            // Up
            for (int i = r - 1; i > 0 && grid[i][c]; --i) {
                grid[i][c] = false;
            }
            // Down
            for (int i = r + 1; i <= h && grid[i][c]; ++i) {
                grid[i][c] = false;
            }
            // Left
            for (int j = c - 1; j > 0 && grid[r][j]; --j) {
                grid[r][j] = false;
            }
            // Right
            for (int j = c + 1; j <= w && grid[r][j]; ++j) {
                grid[r][j] = false;
            }
        }
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }
    
    // Output the result
    cout << remainingWalls << endl;
    
    return 0;
}
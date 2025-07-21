#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Grid to represent walls
    int totalWalls = h * w; // Total number of walls
    
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to zero-based index
        
        if (grid[r][c]) {
            grid[r][c] = false; // Destroy the wall at (r, c)
            totalWalls--; // Decrement the wall count
        } else {
            // Destroy walls in all four directions
            for (int i = 0; i < h; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    totalWalls--;
                }
            }
            for (int j = 0; j < w; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    totalWalls--;
                }
            }
        }
    }
    
    cout << totalWalls << endl; // Output the number of remaining walls
    return 0;
}
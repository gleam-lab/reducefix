#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // Initialize the grid with all cells having a wall
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    
    while(Q--) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Adjusting indices to zero-based
        
        if(grid[R][C]) {
            // If there's a wall at (R, C), just remove it
            grid[R][C] = false;
        } else {
            // If there's no wall, remove the closest wall in all directions
            for(int d = 0; d < 4; ++d) { // Directions: Left, Right, Up, Down
                int x = R, y = C;
                bool found = false;
                
                // Move in the current direction until we find a wall or go out of bounds
                while(true) {
                    x += (d == 0 ? -1 : d == 1 ? 1 : 0); // Adjust x based on direction
                    y += (d == 2 ? -1 : d == 3 ? 1 : 0); // Adjust y based on direction
                    
                    if(x < 0 || x >= H || y < 0 || y >= W) break; // Out of bounds
                    if(grid[x][y]) {
                        grid[x][y] = false; // Remove the found wall
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    // Count the remaining walls
    int remaining_walls = 0;
    for(auto& row : grid) {
        for(bool cell : row) {
            if(cell) ++remaining_walls;
        }
    }
    
    cout << remaining_walls << endl;
    return 0;
}
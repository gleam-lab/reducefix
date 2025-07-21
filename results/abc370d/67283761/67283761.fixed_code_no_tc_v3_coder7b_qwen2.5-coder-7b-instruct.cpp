#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    // Initialize the grid with walls
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    
    while(Q--) {
        int r, c;
        cin >> r >> c;
        
        // Adjusting index to zero-based
        --r;
        --c;
        
        if(grid[r][c]) {
            // If there's a wall, remove it
            grid[r][c] = false;
        } else {
            // If there's no wall, destroy adjacent walls
            grid[r][c] = false;
            
            // Directions for checking adjacent cells
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            for(auto& d : directions) {
                int x = r + d.first;
                int y = c + d.second;
                
                // Check boundaries
                if(x >= 0 && x < H && y >= 0 && y < W) {
                    // Continue moving until we hit a wall or reach the boundary
                    while(grid[x][y] == false) {
                        x += d.first;
                        y += d.second;
                        
                        // Check boundaries again before accessing grid
                        if(x >= 0 && x < H && y >= 0 && y < W) {
                            grid[x][y] = false;
                        }
                    }
                }
            }
        }
    }
    
    // Count the remaining walls
    int remaining_walls = count_if(grid.begin(), grid.end(), [](const auto& row){
        return count(row.begin(), row.end(), true);
    });
    
    cout << remaining_walls << endl;
    
    return 0;
}
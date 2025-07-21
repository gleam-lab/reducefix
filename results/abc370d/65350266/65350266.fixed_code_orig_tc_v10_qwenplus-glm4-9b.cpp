#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<int>> grid(H, vector<int>(W, 1)); // grid stores the number of walls in each cell
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to zero-based index
        
        if (grid[R][C] > 0) {
            grid[R][C]--; // Destroy the wall at (R, C)
        } else {
            // Find the next wall to the left of (R, C)
            int left = C;
            while (left >= 0 && grid[R][left] == 0) {
                left--;
            }
            if (left >= 0) {
                grid[R][left]--;
            }
            
            // Find the next wall to the right of (R, C)
            int right = C;
            while (right < W && grid[R][right] == 0) {
                right++;
            }
            if (right < W) {
                grid[R][right]--;
            }
            
            // Find the next wall above (R, C)
            int up = R;
            while (up >= 0 && grid[up][C] == 0) {
                up--;
            }
            if (up >= 0) {
                grid[up][C]--;
            }
            
            // Find the next wall below (R, C)
            int down = R;
            while (down < H && grid[down][C] == 0) {
                down++;
            }
            if (down < H) {
                grid[down][C]--;
            }
        }
    }
    
    // Compute the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j];
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}
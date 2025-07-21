#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W));
    
    // Initialize the grid with walls (1)
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 1;
        }
    }
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to zero-indexed
        
        if (grid[R][C] == 1) {
            grid[R][C] = 0; // Bomb explodes and destroys the wall
        } else {
            // Destroy walls above, below, to the left, and to the right
            // Check and remove walls on each side until no wall is found or edge of the grid is reached
            for (int i = R - 1; i >= 0 && grid[i][C] == 1; --i) {
                grid[i][C] = 0;
            }
            for (int i = R + 1; i < H && grid[i][C] == 1; ++i) {
                grid[i][C] = 0;
            }
            for (int j = C - 1; j >= 0 && grid[R][j] == 1; --j) {
                grid[R][j] = 0;
            }
            for (int j = C + 1; j < W && grid[R][j] == 1; ++j) {
                grid[R][j] = 0;
            }
        }
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += grid[i][j];
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}
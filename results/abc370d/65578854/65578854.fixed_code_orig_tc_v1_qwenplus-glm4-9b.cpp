#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2 * 100005;

int H, W, Q;
int grid[MAX][MAX];

void destroyWalls(int r, int c) {
    // Destroyed walls will be marked as -1
    grid[r][c] = -1;
    
    // Check upwards
    for (int i = r - 1; i >= 0 && grid[i][c] != -1; --i) {
        grid[i][c] = -1;
    }
    
    // Check downwards
    for (int i = r + 1; i < H && grid[i][c] != -1; ++i) {
        grid[i][c] = -1;
    }
    
    // Check left
    for (int j = c - 1; j >= 0 && grid[r][j] != -1; --j) {
        grid[r][j] = -1;
    }
    
    // Check right
    for (int j = c + 1; j < W && grid[r][j] != -1; ++j) {
        grid[r][j] = -1;
    }
}

int main() {
    cin >> H >> W >> Q;
    
    // Initialize the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 1;  // Start with 1 wall
        }
    }
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (grid[r][c] == 0) {
            continue;  // No wall at this location to destroy
        }
        
        destroyWalls(r, c);
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] > 0) {
                remainingWalls += grid[i][j];
            }
        }
    }
    
    cout << remainingWalls << endl;
    return 0;
}
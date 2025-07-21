#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<int>> grid(H, vector<int>(W, H * W)); // Each cell initially has H * W walls
    
    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        // Check if the bomb destroys a wall
        if (--grid[r][c] == 0) {
            for (int i = 0; i <= H; ++i) {
                if (i != r && grid[i][c] > 0) grid[i][c] -= 1;
            }
            for (int j = 0; j <= W; ++j) {
                if (j != c && grid[r][j] > 0) grid[r][j] -= 1;
            }
        }
    }
    
    // Calculate the remaining number of walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            remainingWalls += max(grid[i][j] - 1, 0);
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    set<pair<int, int>> freeCells;
    
    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (grid[r][c]) {
            grid[r][c] = false;
            freeCells.insert({r, c});
        } else {
            // Check the four directions
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            
            for (int d = 0; d < 4; ++d) {
                int i = r, j = c;
                // Move in the direction until a wall is found or boundary is reached
                while (i >= 0 && i < H && j >= 0 && j < W && grid[i][j]) {
                    i += dr[d];
                    j += dc[d];
                    if (i >= 0 && i < H && j >= 0 && j < W) {
                        grid[i][j] = false;
                        freeCells.insert({i, j});
                    }
                }
            }
        }
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }
    
    cout << remainingWalls << endl;
    
    return 0;
}
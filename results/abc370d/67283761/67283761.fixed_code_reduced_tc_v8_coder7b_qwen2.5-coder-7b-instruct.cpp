#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));

    for(int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        
        if(grid[r][c]) {
            // If there is a wall, just remove it
            grid[r][c] = false;
        } else {
            // Otherwise, remove the nearest wall(s) in all directions
            grid[r][c] = false;
            
            // Up direction
            for(int k = r-1; k >= 0; --k) {
                if(grid[k][c]) {
                    grid[k][c] = false;
                    break;
                }
            }

            // Down direction
            for(int k = r+1; k < H; ++k) {
                if(grid[k][c]) {
                    grid[k][c] = false;
                    break;
                }
            }

            // Left direction
            for(int k = c-1; k >= 0; --k) {
                if(grid[r][k]) {
                    grid[r][k] = false;
                    break;
                }
            }

            // Right direction
            for(int k = c+1; k < W; ++k) {
                if(grid[r][k]) {
                    grid[r][k] = false;
                    break;
                }
            }
        }
    }

    // Count the remaining walls
    int count = 0;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(grid[i][j]) {
                ++count;
            }
        }
    }

    cout << count << endl;
    return 0;
}
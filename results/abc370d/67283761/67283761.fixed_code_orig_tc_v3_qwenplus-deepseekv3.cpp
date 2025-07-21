#include <vector>
#include <iostream>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int remaining = H * W;
    
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        
        if (grid[R][C]) {
            grid[R][C] = false;
            remaining--;
        } else {
            // Check up
            for (int i = R - 1; i >= 0; --i) {
                if (grid[i][C]) {
                    grid[i][C] = false;
                    remaining--;
                    break;
                }
            }
            // Check down
            for (int i = R + 1; i < H; ++i) {
                if (grid[i][C]) {
                    grid[i][C] = false;
                    remaining--;
                    break;
                }
            }
            // Check left
            for (int j = C - 1; j >= 0; --j) {
                if (grid[R][j]) {
                    grid[R][j] = false;
                    remaining--;
                    break;
                }
            }
            // Check right
            for (int j = C + 1; j < W; ++j) {
                if (grid[R][j]) {
                    grid[R][j] = false;
                    remaining--;
                    break;
                }
            }
        }
    }
    
    cout << remaining << endl;
    
    return 0;
}
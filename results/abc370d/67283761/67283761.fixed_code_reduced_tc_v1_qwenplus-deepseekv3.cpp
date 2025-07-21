#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int broken = 0;
    
    while (Q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        
        if (grid[r][c]) {
            grid[r][c] = false;
            ++broken;
        } else {
            // Check up
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    ++broken;
                    break;
                }
            }
            // Check down
            for (int i = r + 1; i < H; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    ++broken;
                    break;
                }
            }
            // Check left
            for (int j = c - 1; j >= 0; --j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    ++broken;
                    break;
                }
            }
            // Check right
            for (int j = c + 1; j < W; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    ++broken;
                    break;
                }
            }
        }
    }
    
    cout << (H * W - broken) << endl;
    
    return 0;
}
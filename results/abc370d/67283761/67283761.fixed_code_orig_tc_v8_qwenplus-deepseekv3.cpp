#include <vector>
#include <iostream>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    int broken = 0;

    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            broken++;
            grid[r][c] = false;
        } else {
            // Check up
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c]) {
                    broken++;
                    grid[i][c] = false;
                    break;
                }
            }
            // Check down
            for (int i = r + 1; i < H; ++i) {
                if (grid[i][c]) {
                    broken++;
                    grid[i][c] = false;
                    break;
                }
            }
            // Check left
            for (int j = c - 1; j >= 0; --j) {
                if (grid[r][j]) {
                    broken++;
                    grid[r][j] = false;
                    break;
                }
            }
            // Check right
            for (int j = c + 1; j < W; ++j) {
                if (grid[r][j]) {
                    broken++;
                    grid[r][j] = false;
                    break;
                }
            }
        }
    }
    cout << H * W - broken << endl;
    return 0;
}
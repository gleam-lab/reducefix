#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1)); // 1 represents a wall
    vector<vector<int>> wallsCount(h, vector<int>(w, 1));
    vector<vector<int>> firstWallIndex(h, vector<int>(w, 0));
    int totalWalls = h * w;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to zero-based index
        
        if (grid[r][c] == 1) {
            // If there's a wall at (r, c), destroy it
            grid[r][c] = 0;
            --totalWalls;
        } else {
            // If there's no wall at (r, c), find and destroy the first wall in the row and column
            int rowFirstWall = firstWallIndex[r][c];
            int colFirstWall = firstWallIndex[c][r];

            for (int x = rowFirstWall; x < w; ++x) {
                if (grid[r][x] == 1) {
                    grid[r][x] = 0;
                    grid[c][x] = 0;
                    --totalWalls;
                    break;
                }
            }

            for (int y = colFirstWall; y < h; ++y) {
                if (grid[y][c] == 1) {
                    grid[y][c] = 0;
                    grid[c][y] = 0;
                    --totalWalls;
                    break;
                }
            }

            // Update first wall indices
            for (int y = 0; y < h; ++y) {
                firstWallIndex[y][c] = x;
            }
            for (int x = 0; x < w; ++x) {
                firstWallIndex[c][x] = y;
            }
        }
    }

    cout << totalWalls << endl;
    return 0;
}
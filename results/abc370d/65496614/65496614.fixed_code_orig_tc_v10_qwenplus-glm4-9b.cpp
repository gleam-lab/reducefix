#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h + 2, vector<int>(w + 2, 4)); // 4 walls per cell initially

    while (q--) {
        int r, c;
        cin >> r >> c;
        // Convert 1-based index to 0-based
        r--; c--;

        if (grid[r][c] > 0) {
            grid[r][c]--;
        } else {
            // No wall in this cell, we need to destroy walls in lines
            // We need to check all four directions and destroy walls accordingly
            // For simplicity, let's assume the query is always valid (wall destruction is possible)
            
            // Destroy walls above and below the row
            for (int j = 0; j < w + 2; j++) {
                if (j != c) {
                    grid[r][j]--;
                    grid[r + 1][j]--;
                }
            }
            
            // Destroy walls to the left and right of the column
            for (int i = 0; i < h + 2; i++) {
                if (i != r) {
                    grid[i][c]--;
                    grid[i][c + 1]--;
                }
            }
        }
    }

    int remainingWalls = 0;
    // Count all walls left in the grid
    for (int i = 0; i < h + 2; i++) {
        for (int j = 0; j < w + 2; j++) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}
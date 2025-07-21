#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    // Initialize the grid with walls
    vector<vector<bool>> grid(h + 2, vector<bool>(w + 2, true));

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            grid[i][j] = true; // Set all cells to have walls initially
        }
    }

    // To keep track of the next available wall to remove in each row and column
    vector<vector<int>> nextWallInRow(h + 2, vector<int>(w + 2, 0));
    vector<vector<int>> nextWallInCol(h + 2, vector<int>(w + 2, 0));

    int totalWalls = h * w; // Total number of walls initially

    for (int q_i = 0; q_i < q; ++q_i) {
        int r, c;
        cin >> r >> c;
        int originalWallCount = totalWalls;

        // Remove the wall at (r, c)
        if (grid[r][c]) {
            grid[r][c] = false;
            nextWallInRow[r][c] = 0; // New walls to remove in this cell
            nextWallInCol[r][c] = 0; // New walls to remove in this cell
        } else {
            // Remove walls around (r, c)
            for (int i = 1; i <= h; ++i) {
                if (grid[i][c] && i != r) {
                    grid[i][c] = false;
                    nextWallInRow[i][c] = 0;
                }
            }
            for (int j = 1; j <= w; ++j) {
                if (grid[r][j] && j != c) {
                    grid[r][j] = false;
                    nextWallInCol[r][j] = 0;
                }
            }
        }

        // Update the total number of walls remaining
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                if (grid[i][j]) {
                    totalWalls--;
                }
            }
        }

        // Output the total number of walls remaining after this query
        cout << totalWalls << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_H = 400001;
const int MAX_W = 400001;

int h, w, q;
int grid[MAX_H][MAX_W]; // grid[i][j] = 1 if there is a wall, 0 otherwise

int main() {
    cin >> h >> w >> q;

    // Reading the queries and marking the grid cells accordingly
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        queries.emplace_back(r, c);
    }

    // Sort the queries by row and column
    sort(queries.begin(), queries.end());

    int remainingWalls = 0;

    // Process the queries
    int currentRow = 0; // current row being processed
    for (const auto& p : queries) {
        int r = p.first - 1; // convert to zero-based index
        int c = p.second - 1; // convert to zero-based index

        if (r < currentRow) {
            // Process the previous row before moving to the next row
            for (int j = 0; j < w; ++j) {
                remainingWalls -= grid[currentRow][j]; // walls in this row are removed
            }
        }

        for (int j = 0; j < w; ++j) {
            if (j < c) {
                // Remove walls to the left of the current column
                remainingWalls -= grid[r][j];
            }
            if (j > c) {
                // Remove walls to the right of the current column
                remainingWalls -= grid[r][j];
            }
        }

        // Place a bomb and destroy the wall
        grid[r][c] = 0;
        remainingWalls--;

        currentRow = r + 1; // Move to the next row
    }

    // Process any remaining rows
    for (int i = currentRow; i < h; ++i) {
        for (int j : grid[i]) {
            remainingWalls -= j;
        }
    }

    cout << remainingWalls << endl;

    return 0;
}
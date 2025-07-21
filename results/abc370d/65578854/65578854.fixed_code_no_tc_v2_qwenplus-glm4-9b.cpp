#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Assuming 1-based index, adjust to 0-based for easier array manipulation
    H--;
    W--;

    vector<vector<bool>> grid(H + 1, vector<bool>(W + 1, true));

    // Process each query
    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        // Convert to 0-based index
        R--;
        C--;

        // Check if there is a wall at the given position
        if (grid[R][C]) {
            // Destroy the wall
            grid[R][C] = false;
        } else {
            // No wall, so destroy walls around the position
            // Top to bottom
            for (int i = R - 1; i >= 0 && !grid[i][C]; i--) {
                grid[i][C] = false;
            }
            // Bottom to top
            for (int i = R + 1; i <= H && !grid[i][C]; i++) {
                grid[i][C] = false;
            }
            // Left to right
            for (int j = C - 1; j >= 0 && !grid[R][j]; j--) {
                grid[R][j] = false;
            }
            // Right to left
            for (int j = C + 1; j <= W && !grid[R][j]; j++) {
                grid[R][j] = false;
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    // Output the result
    cout << remainingWalls << endl;

    return 0;
}
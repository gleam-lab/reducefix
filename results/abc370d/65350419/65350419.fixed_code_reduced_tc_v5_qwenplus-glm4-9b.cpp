#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with walls
    vector<vector<int>> grid(W, vector<int>(H, 1)); // Using 1 to represent walls

    // To maintain the count of remaining walls
    int remainingWalls = H * W;

    // Process each query
    while (Q--) {
        int R, C;
        cin >> R >> C;

        // Convert 1-based index to 0-based
        R--; C--;

        if (grid[C][R] > 0) {
            // If there is a wall at the given cell
            grid[C][R]--;
            if (grid[C][R] == 0) {
                remainingWalls--;
            }
        } else {
            // No wall at (R, C), look for the first wall to the left
            int i = C - 1;
            while (i >= 0 && grid[i][R] == 0) i--;
            if (i >= 0) {
                // Found a wall to the left, destroy it
                grid[i][R]--;
                remainingWalls--;
            }

            // Look for the first wall to the right
            i = C + 1;
            while (i < W && grid[i][R] == 0) i++;
            if (i < W) {
                // Found a wall to the right, destroy it
                grid[i][R]--;
                remainingWalls--;
            }

            // Look for the first wall above
            i = R - 1;
            while (i >= 0 && grid[C][i] == 0) i--;
            if (i >= 0) {
                // Found a wall above, destroy it
                grid[C][i]--;
                remainingWalls--;
            }

            // Look for the first wall below
            i = R + 1;
            while (i < H && grid[C][i] == 0) i++;
            if (i < H) {
                // Found a wall below, destroy it
                grid[C][i]--;
                remainingWalls--;
            }
        }
    }

    // Output the remaining number of walls
    cout << remainingWalls << endl;

    return 0;
}
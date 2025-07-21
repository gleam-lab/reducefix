#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> grid(H, vector<int>(W, 1));  // Using 1 to represent walls and 0 for empty spaces

    int remainingWalls = H * W;  // Initialize count of walls

    while (Q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r - 1][c - 1] == 1) {  // If a wall exists at the destination
            grid[r - 1][c - 1] = 0;  // Destroy the wall
            remainingWalls--;
        } else {  // If there is no wall at the destination
            // Destroy walls in all four directions
            for (int i = 1; i < H && grid[r - 1][c - 1] == 1; i++) {
                grid[r - 1 - i][c - 1] = 0;
            }

            for (int i = 1; i < W && grid[r - 1][c - 1] == 1; i++) {
                grid[r - 1][c - 1 - i] = 0;
            }

            for (int i = 1; i < H && grid[r - 1][c - 1] == 1; i++) {
                grid[r - 1 + i][c - 1] = 0;
            }

            for (int i = 1; i < W && grid[r - 1][c - 1] == 1; i++) {
                grid[r - 1][c - 1 + i] = 0;
            }

            remainingWalls -= 4;  // Decrease count by 4 as we destroyed 4 walls
        }
    }

    cout << remainingWalls << endl;

    return 0;
}
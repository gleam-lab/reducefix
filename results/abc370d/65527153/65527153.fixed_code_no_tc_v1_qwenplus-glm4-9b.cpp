#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 402020; // Slightly larger than max H * W to handle edge cases
vector<bool> grid(MAX_N, true); // Wall presence, true means wall is present

void process_bomb(int r, int c) {
    // Remove the wall at the given cell if it exists
    if (grid[r * MAX_N + c]) {
        grid[r * MAX_N + c] = false;
    } else {
        // If no wall at (r, c), remove walls in the vertical and horizontal lines
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i * MAX_N + c] && grid[i * MAX_N + c] != grid[r * MAX_N + c]) {
                grid[i * MAX_N + c] = false;
            } else {
                break;
            }
        }
        for (int i = r + 1; i < MAX_N; ++i) {
            if (grid[i * MAX_N + c] && grid[i * MAX_N + c] != grid[r * MAX_N + c]) {
                grid[i * MAX_N + c] = false;
            } else {
                break;
            }
        }
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r * MAX_N + j] && grid[r * MAX_N + j] != grid[r * MAX_N + c]) {
                grid[r * MAX_N + j] = false;
            } else {
                break;
            }
        }
        for (int j = c + 1; j < MAX_N; ++j) {
            if (grid[r * MAX_N + j] && grid[r * MAX_N + j] != grid[r * MAX_N + c]) {
                grid[r * MAX_N + j] = false;
            } else {
                break;
            }
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i * W + j] = true;
        }
    }

    // Process each query
    while (Q--) {
        int r, c;
        cin >> r >> c;
        process_bomb(r - 1, c - 1); // Adjust for 0-indexed grid
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < MAX_N; ++i) {
        remaining_walls += grid[i];
    }

    cout << remaining_walls << endl;

    return 0;
}
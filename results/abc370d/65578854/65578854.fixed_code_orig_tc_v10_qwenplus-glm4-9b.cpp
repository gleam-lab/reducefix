#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Define the grid size and the maximum number of queries
const int maxH = 400005;
const int maxW = 400005;

int H, W, Q;
vector<set<int>> X(maxH), Y(maxW);
vector<int> grid[maxH][maxW];

// Function to destroy walls in the given range
void destroyWalls(int r1, int r2, int c1, int c2) {
    for (int r = r1; r <= r2; ++r) {
        for (int c = c1; c <= c2; ++c) {
            grid[r][c] = 0; // Destroy the wall by setting it to 0
        }
    }
}

// Main function to process the queries and count remaining walls
int main() {
    cin >> H >> W >> Q;
    
    // Initialize the grid with walls
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 1; // Each cell initially has a wall
        }
    }
    
    int R, C;
    while (Q--) {
        cin >> R >> C;
        R--; C--; // Convert to 0-based index
        
        // Check if there is a wall at the given position
        if (grid[R][C] == 1) {
            grid[R][C] = 0; // Destroy it
        } else {
            // Find the nearest walls in all four directions
            int up = -1, down = -1, left = -1, right = -1;
            for (int i = R - 1; i >= 0; --i) {
                if (grid[i][C] == 1) {
                    up = i;
                    break;
                }
            }
            for (int i = R + 1; i < H; ++i) {
                if (grid[i][C] == 1) {
                    down = i;
                    break;
                }
            }
            for (int j = C - 1; j >= 0; --j) {
                if (grid[R][j] == 1) {
                    left = j;
                    break;
                }
            }
            for (int j = C + 1; j < W; ++j) {
                if (grid[R][j] == 1) {
                    right = j;
                    break;
                }
            }
            
            // Destroy walls within the affected region
            destroyWalls(max(up, 0), min(down, H - 1), max(left, 0), min(right, W - 1));
        }
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 1) {
                remainingWalls++;
            }
        }
    }
    
    // Output the result
    cout << remainingWalls << endl;
    
    return 0;
}
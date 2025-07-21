#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Create a 2D vector to keep track of the number of walls left in each cell
    vector<vector<int>> walls(h + 1, vector<int>(w + 1, 4)); // Start with 4 walls, will decrement accordingly

    // Process each query
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        
        // Check if the wall at (r, c) exists
        if (walls[r][c] > 0) {
            walls[r][c]--; // Destroy the wall at (r, c)
        } else {
            // If no wall at (r, c), destroy the first wall in each direction
            for (int i = r - 1; i > 0 && walls[i][c] > 0; i--) {
                walls[i][c]--;
            }
            for (int i = r + 1; i <= h && walls[i][c] > 0; i++) {
                walls[i][c]--;
            }
            for (int j = c - 1; j > 0 && walls[r][j] > 0; j--) {
                walls[r][j]--;
            }
            for (int j = c + 1; j <= w && walls[r][j] > 0; j++) {
                walls[r][j]--;
            }
        }
    }

    // Calculate the total number of remaining walls
    long long remaining_walls = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            remaining_walls += walls[i][j];
        }
    }

    // Output the result
    cout << remaining_walls << endl;

    return 0;
}
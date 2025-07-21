#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<int>> grid(h, vector<int>(w, 1)); // Grid initialized with walls (1)
    
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        queries[i] = {r - 1, c - 1}; // Convert to 0-indexed
    }
    
    // Process each query
    for (auto &query : queries) {
        int r = query.first, c = query.second;
        if (grid[r][c] == 1) {
            // If there is a wall at (r, c), destroy it
            grid[r][c] = 0;
        } else {
            // No wall at (r, c), destroy walls in the four directions
            // Up
            for (int i = r - 1; i >= 0 && grid[i][c] == 1; i--) {
                grid[i][c] = 0;
            }
            // Down
            for (int i = r + 1; i < h && grid[i][c] == 1; i++) {
                grid[i][c] = 0;
            }
            // Left
            for (int j = c - 1; j >= 0 && grid[r][j] == 1; j--) {
                grid[r][j] = 0;
            }
            // Right
            for (int j = c + 1; j < w && grid[r][j] == 1; j++) {
                grid[r][j] = 0;
            }
        }
    }
    
    // Count the remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remainingWalls += grid[i][j];
        }
    }
    
    cout << remainingWalls << endl;
    return 0;
}
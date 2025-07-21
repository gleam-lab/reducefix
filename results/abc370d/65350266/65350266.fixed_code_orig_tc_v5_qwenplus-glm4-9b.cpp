#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // All cells start with a wall
    
    for (int q_num = 0; q_num < q; q_num++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index
        
        if (!grid[r][c]) continue; // If there is no wall, skip
        
        // Destroy walls in all four directions
        for (int i = max(0, r - 1); i <= min(h - 1, r + 1); i++) {
            if (i != r) grid[i][c] = false;
        }
        for (int j = max(0, c - 1); j <= min(w - 1, c + 1); j++) {
            if (j != c) grid[r][j] = false;
        }
    }
    
    // Count the remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) remaining_walls++;
        }
    }
    
    cout << remaining_walls << endl;
    
    return 0;
}
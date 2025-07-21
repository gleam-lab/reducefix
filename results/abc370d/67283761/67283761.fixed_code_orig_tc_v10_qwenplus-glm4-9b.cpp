#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<int>> grid(h, vector<int>(w, 1)); // 1 initially means a wall is present.
    
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c; // adjust for 1-based indexing
        
        if (grid[r][c] == 1) {
            // If there's a wall at (r, c), destroy it.
            grid[r][c] = 0;
            cout << h * w - i - 1 << endl; // Output the number of remaining walls.
            continue;
        }
        
        // Count the number of walls in the column and row to determine if they can be destroyed.
        int colWalls = 0, rowWalls = 0;
        for (int j = 0; j < w; ++j) {
            if (grid[r][j] == 1) colWalls++;
        }
        for (int i = 0; i < h; ++i) {
            if (grid[i][c] == 1) rowWalls++;
        }
        
        // If there's only one wall in the row or column, it can be destroyed.
        if (colWalls == 1 || rowWalls == 1) {
            grid[r][c] = 0;
            cout << h * w - i - 1 << endl;
            continue;
        }
        
        // If neither the row nor the column has only one wall, no walls can be destroyed.
        cout << h * w - i - 1 << endl;
    }
    
    return 0;
}
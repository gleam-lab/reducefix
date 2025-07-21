#include <bits/stdc++.h>
using namespace std;

int H, W, Y;
vector<vector<int>> grid;

void fill(int x, int y, const vector<vector<bool>>& visited) {
    // Your flood fill logic here
    // This function should flood fill the area and mark it as visited
    // Make sure to only visit cells with an elevation above or equal to the current sea level
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> H >> W >> Y;
    grid.resize(H, vector<int>(W));
    
    // Read the input
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    
    // Your flood fill algorithm to find initial submerged cells
    // ...

    // Simulate the sea level rise and compute the remaining area
    while (Y--) {
        // Update the grid according to the current sea level and compute the remaining area
        // ...
        
        // Output the remaining area
        cout << /* remaining area */ << endl;
    }
    
    return 0;
}
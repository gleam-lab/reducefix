#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAX_H = 1000;
const int MAX_W = 1000;

vector<vector<int>> grid(MAX_H, vector<int>(MAX_W));

void flood_fill(int i, int j) {
    // Base condition: out of bounds or out of water
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] <= 0) {
        return;
    }

    // Mark the cell as visited by setting its value to negative
    grid[i][j] = -1;

    // Recursively flood fill all adjacent cells that are not yet visited
    flood_fill(i + 1, j);
    flood_fill(i - 1, j);
    flood_fill(i, j + 1);
    flood_fill(i, j - 1);
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    // Read the grid
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }

    // Start flood fill from the top-left corner if it's at sea level or higher
    if (grid[0][0] >= 0) {
        flood_fill(0, 0);
    }

    // Calculate the remaining area
    ll remaining_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] > 0) { // This cell hasn't sunk
                remaining_area++;
            }
        }
    }

    cout << remaining_area << endl;

    return 0;
}
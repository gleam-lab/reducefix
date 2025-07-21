#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define rrep(i,n) for(int i = (int)n-1; i >= 0; --i)

using ll = long long;

using vi = vector<int>;
using vb = vector<bool>;

// Function to erase walls from the specified row and column
void erase_wall(int row, int col, vb &grid, vector<vi> &rowWalls, vector<vi> &colWalls) {
    // Ensure the row and column indices are within bounds
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;

    // Remove wall from the grid and update the row and column wall counts
    if (grid[row][col]) {
        grid[row][col] = false;
        rowWalls[row]--;
        colWalls[col]--;
    }
}

// Function to process the bomb placement and destroy walls
void process_bomb(int row, int col, vb &grid, vector<vi> &rowWalls, vector<vi> &colWalls) {
    // Check if there is a wall at the given position
    if (!grid[row][col]) return;

    // If there is no wall, destroy the first walls that appear when looking up, down, left, and right
    int r = max(0, row - 1);
    while (r < row && !grid[r][col]) r++;
    erase_wall(r, col, grid, rowWalls, colWalls); // Destroy the wall from the row

    r = min(grid.size() - 1, row + 1);
    while (r > row && !grid[r][col]) r--;
    erase_wall(r, col, grid, rowWalls, colWalls); // Destroy the wall from the row

    int c = max(0, col - 1);
    while (c < col && !grid[row][c]) c++;
    erase_wall(row, c, grid, rowWalls, colWalls); // Destroy the wall from the column

    c = min(grid[0].size() - 1, col + 1);
    while (c > col && !grid[row][c]) c--;
    erase_wall(row, c, grid, rowWalls, colWalls); // Destroy the wall from the column
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vb grid(h, vb(w, true)); // Initialize the grid with walls
    vector<vi> rowWalls(h, vi(w, 1)); // Keep track of the number of walls in each row
    vector<vi> colWalls(h, vi(w, 1)); // Keep track of the number of walls in each column

    rep(i, q) {
        int r, c;
        cin >> r >> c;
        process_bomb(r - 1, c - 1, grid, rowWalls, colWalls); // Process the bomb placement
    }

    // Calculate the number of remaining walls
    int remainingWalls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remainingWalls += grid[i][j] && rowWalls[i][j] && colWalls[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}
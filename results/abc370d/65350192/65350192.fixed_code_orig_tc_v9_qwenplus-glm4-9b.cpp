#include <iostream>
#include <vector>
using namespace std;

const int dx[] = {-1, 1, 0, 0}; // Directions: up, down, left, right
const int dy[] = {0, 0, -1, 1};

void destroyWalls(vector<vector<int>>& grid, int x, int y) {
    if (grid[x][y] == 0) return; // No wall to destroy
    grid[x][y] = 0; // Destroy the wall at (x, y)
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
            destroyWalls(grid, nx, ny); // Recursively destroy walls in the direction
        }
    }
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // Initialize all cells with walls

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to zero-based index
        if (grid[r][c] == 1) {
            destroyWalls(grid, r, c); // Destroy walls starting from (r, c)
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;
    return 0;
}
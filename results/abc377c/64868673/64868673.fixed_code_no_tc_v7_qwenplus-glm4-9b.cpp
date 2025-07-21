#include <iostream>
using namespace std;

const int MAXN = 1001; // Sufficiently large to handle edge cases

int main() {
    int n, m;
    cin >> n >> m;
    int grid[MAXN][MAXN] = {0};

    // Read the pieces' positions and mark the cells they can capture
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        // Convert to 0-based index and mark the cells in the grid
        for (int k = 0; k < 8; ++k) {
            int a = x + (k < 4 ? 1 : (k < 8 ? -1 : 0));
            int b = y + (k < 2 ? 2 : (k < 4 ? 1 : k < 6 ? -1 : -2));
            if (a >= 0 && a < n && b >= 0 && b < n) {
                grid[a][b] = 1; // Mark this cell
            }
        }
    }

    // Use a prefix sum to compute the number of pieces that can capture each cell
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) grid[i][j] += grid[i-1][j];
            if (j > 0) grid[i][j] += grid[i][j-1];
            if (i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
        }
    }

    // Count the number of free cells
    long long free_cells = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // A cell is free if it is not captured by any piece
            if (grid[i][j] == 0) {
                free_cells++;
            }
        }
    }

    cout << free_cells << endl;
    return 0;
}
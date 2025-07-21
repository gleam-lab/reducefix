#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // Initialize grid with walls (1)
    set<pair<int, int>> bomb_positions;

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; // Convert to 0-based index
        c--;

        // Place the bomb and remove the wall if it exists
        bomb_positions.insert({r, c});
        grid[r][c] = 0;

        // Check if the current position has a bomb, if not, remove walls in all directions
        if (grid[r][c] == 0) {
            // Remove walls upwards
            for (int col = c - 1; col >= 0 && grid[r][col] == 1; col--) {
                grid[r][col] = 0;
                bomb_positions.insert({r, col});
            }
            // Remove walls downwards
            for (int col = c + 1; col < w && grid[r][col] == 1; col++) {
                grid[r][col] = 0;
                bomb_positions.insert({r, col});
            }
            // Remove walls left
            for (int row = r - 1; row >= 0 && grid[row][c] == 1; row--) {
                grid[row][c] = 0;
                bomb_positions.insert({row, c});
            }
            // Remove walls right
            for (int row = r + 1; row < h && grid[row][c] == 1; row++) {
                grid[row][c] = 0;
                bomb_positions.insert({row, c});
            }
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 1) {
                remaining_walls++;
            }
        }
    }
    cout << remaining_walls << endl;

    return 0;
}
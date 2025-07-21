#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with walls
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    vector<list<pair<int, int>>> column_walls(W); // list of (row, wall_status)
    vector<list<pair<int, int>>> row_walls(H);    // list of (col, wall_status)

    // Read the queries and process each one
    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        --R, --C; // Convert to zero-based index

        // Place bomb and destroy walls
        if (grid[R][C]) {
            grid[R][C] = false;
            column_walls[C].remove({R, true});
            row_walls[R].remove({C, true});
        } else {
            // Check for walls in the four directions
            // ...
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int r = 0; r < H; ++r) {
        for (auto& col : row_walls[r]) {
            if (col.second) {
                remaining_walls++;
            }
        }
    }

    for (int c = 0; c < W; ++c) {
        for (auto& row : column_walls[c]) {
            if (row.second) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}
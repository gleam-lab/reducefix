#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Create two vectors of size H and W initialized with 2 * H * W (total walls)
    vector<int> row_walls(H, 2 * H * W), col_walls(W, 2 * H * W);

    ll total_walls = H * W;
    ll remaining_walls = total_walls;

    for (int i = 0; i < Q; ++i) {
        int R, C;
        cin >> R >> C;
        --R; --C; // Convert to 0-based indexing

        // Check if there's a wall at the given position
        if (row_walls[R] > C || col_walls[C] > R) {
            // Place bomb, destroy the wall at (R, C)
            row_walls[R] = col_walls[C] = max(0, row_walls[R] - 1);
            col_walls[C] = row_walls[R] = max(0, col_walls[C] - 1);
        } else {
            // No wall at (R, C), so it's a new bomb placement

            // Find the first wall to the left and right
            int left = C - 1;
            while (left >= 0 && row_walls[R] <= left) {
                row_walls[R] = max(0, row_walls[R] - 1);
                left--;
            }

            left = C + 1;
            while (left < W && row_walls[R] <= left) {
                row_walls[R] = max(0, row_walls[R] - 1);
                left++;
            }

            // Find the first wall above and below
            int top = R - 1;
            while (top >= 0 && col_walls[C] <= top) {
                col_walls[C] = max(0, col_walls[C] - 1);
                top--;
            }

            top = R + 1;
            while (top < H && col_walls[C] <= top) {
                col_walls[C] = max(0, col_walls[C] - 1);
                top++;
            }
        }

        // Calculate the number of remaining walls
        remaining_walls = 0;
        for (int k = 0; k < H; ++k) {
            remaining_walls += max(0, row_walls[k]);
        }
        for (int k = 0; k < W; ++k) {
            remaining_walls += max(0, col_walls[k]);
        }

        cout << remaining_walls << endl;
    }

    return 0;
}
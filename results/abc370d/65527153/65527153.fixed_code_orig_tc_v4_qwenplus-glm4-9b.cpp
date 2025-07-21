#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Maps to keep track of wall counts in rows and columns
    map<int, int> row_walls, col_walls;
    vector<int> total_walls(H + 1, W + 1); // total_walls[i] gives the number of walls in row i

    // Simulate the process of placing bombs and destroying walls
    for (int i = 0; i < Q; ++i) {
        int R, C;
        cin >> R >> C;

        // Update the wall count for the row and column
        row_walls[R]--;
        total_walls[R]--;

        col_walls[C]--;
        total_walls[C]--;

        // Handle the destruction based on the bomb placement
        // (This part requires careful logic based on the problem description)

        // Example update: destroy a wall at the exact position
        if (row_walls[R] > 0) row_walls[R]--;
        if (col_walls[C] > 0) col_walls[C]--;
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 1; i <= H; ++i) {
        remaining_walls += total_walls[i] - row_walls[i];
    }

    cout << remaining_walls << endl;

    return 0;
}
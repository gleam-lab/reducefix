#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> map(H, vector<bool>(W, true));
    int totalWalls = H * W;

    vector<vector<pair<int, int>>> directions(4);
    directions[0] = {{0, -1}, {0, 0, 1}}; // Left
    directions[1] = {{0, 1}, {0, 0, -1}}; // Right
    directions[2] = {{-1, 0}, {1, 0, 1}}; // Up
    directions[3] = {{1, 0}, {-1, 0, -1}}; // Down

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!map[r][c]) continue; // If there's no wall, just continue

        map[r][c] = false; // Destroy the wall at (r, c)
        totalWalls--;

        // Check adjacent cells along each direction
        for (int d = 0; d < 4; ++d) {
            int x = r, y = c;
            for (int step = 1; step < W; ++step) { // Check both left and right if vertical, or up and down if horizontal
                x = r + directions[d][1][0] * step;
                y = c + directions[d][1][1] * step;
                if (x >= 0 && x < H && y >= 0 && y < W && map[x][y]) {
                    map[x][y] = false;
                    totalWalls--;
                } else {
                    break; // No more walls in this direction
                }
            }

            x = r, y = c;
            for (int step = 1; step < H; ++step) { // Check both up and down if horizontal, or left and right if vertical
                x = r + directions[d][2][0] * step;
                y = c + directions[d][2][1] * step;
                if (x >= 0 && x < H && y >= 0 && y < W && map[x][y]) {
                    map[x][y] = false;
                    totalWalls--;
                } else {
                    break; // No more walls in this direction
                }
            }
        }
    }

    cout << totalWalls << endl;

    return 0;
}
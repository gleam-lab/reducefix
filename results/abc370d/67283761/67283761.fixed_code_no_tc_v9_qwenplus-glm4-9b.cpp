#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int H, W, Q;
    std::cin >> H >> W >> Q;
    std::vector<std::vector<bool>> map(H, std::vector<bool>(W, true));

    for (int i = 0; i < Q; ++i) {
        int r, c;
        std::cin >> r >> c;
        --r; --c; // Convert to 0-indexed

        // Check if the cell is empty and needs walls to be destroyed
        if (!map[r][c]) {
            // Find the next wall in the four directions
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue; // Skip the current cell

                    int nr = r + dr;
                    int nc = c + dc;

                    // Check if the next wall in the direction exists
                    while (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc]) {
                        nr += dr;
                        nc += dc;
                    }

                    // If we go out of bounds, take the last valid cell
                    if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                        nr -= dr;
                        nc -= dc;
                    }

                    // Destroy the walls in the direction
                    nr = std::max(0, std::min(nr, static_cast<int>(H) - 1));
                    nc = std::max(0, std::min(nc, static_cast<int>(W) - 1));
                    for (int i = std::max(0, r + dr); i < std::min(H, nr + dr); ++i) {
                        map[i][c + dc] = false;
                    }
                }
            }
        }
    }

    // Count the remaining walls
    int remainingWalls = std::count(std::begin(map), std::end(map), true);
    for (int i = 0; i < H; ++i) {
        remainingWalls += std::count(map[i].begin(), map[i].end(), true);
    }

    std::cout << remainingWalls << std::endl;

    return 0;
}
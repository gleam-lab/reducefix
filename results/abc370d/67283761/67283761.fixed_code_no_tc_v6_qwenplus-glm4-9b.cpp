#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> map(H, vector<bool>(W, true));
    vector<vector<int>> remaining_walls(H, vector<int>(W, 4)); // initial walls count: top, bottom, left, right

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c; // convert to 0-based index

        // Check if there's a wall at (r, c)
        if (map[r][c]) {
            // Bomb destroys a wall, decrease the count and mark it as destroyed
            map[r][c] = false;
            remaining_walls[r][c] = 0;
        } else {
            // Bomb destroys all walls around (r, c)
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue; // Skip the center cell

                    int count = 0;
                    int r_current = r;
                    int c_current = c;

                    // Search in the direction of dr and dc
                    while (true) {
                        r_current += dr;
                        c_current += dc;
                        if (r_current >= 0 && r_current < H && c_current >= 0 && c_current < W && map[r_current][c_current]) {
                            map[r_current][c_current] = false;
                            remaining_walls[r_current][c_current] = 0;
                            count++;
                        } else {
                            break;
                        }
                    }

                    // If there are walls in both directions, remove the count from opposite directions
                    if (count > 1) {
                        int r_opposite = r - dr;
                        int c_opposite = c - dc;
                        if (r_opposite >= 0 && r_opposite < H && c_opposite >= 0 && c_opposite < W) {
                            remaining_walls[r_opposite][c_opposite] -= count;
                            if (remaining_walls[r_opposite][c_opposite] < 0) {
                                remaining_walls[r_opposite][c_opposite] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    // Count the remaining walls
    int total_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (map[i][j]) {
                total_walls++;
            }
        }
    }

    cout << total_walls << endl;

    return 0;
}
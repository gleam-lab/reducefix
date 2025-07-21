#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> map(H + 1, vector<bool>(W + 1, true)); // +1 to avoid bounds checking
    int remaining_walls = H * W; // Start with all walls

    for (int q = 0; q < Q; ++q) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to 0-based index
        
        if (!map[r][c]) {
            // If there's no wall, we need to simulate the explosion
            bool wall_destroyed = false;
            // Check all four directions
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) continue; // Skip the current position
                    int nr, nc;
                    for (nr = r + dr, nc = c + dc; nr >= 1 && nr <= H && nc >= 1 && nc <= W; nr += dr, nc += dc) {
                        if (map[nr][nc]) {
                            map[nr][nc] = false; // Destroy wall
                            remaining_walls--;
                            wall_destroyed = true;
                            break;
                        }
                    }
                    if (wall_destroyed) break;
                }
                if (wall_destroyed) break;
            }
        } else {
            // If there's a wall, just destroy it
            map[r][c] = false;
            remaining_walls--;
        }
    }
    
    cout << remaining_walls << endl;
    return 0;
}
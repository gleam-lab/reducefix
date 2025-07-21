#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<int>> grid(H, vector<int>(W));
    int totalWalls = H * W;
    int remainingWalls = totalWalls;

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (grid[R][C] > 0) {
            // Wall exists, destroy it
            remainingWalls--;
            grid[R][C]--;
        } else {
            // No wall exists, destroy surrounding walls
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : directions) {
                int r = R + dir.first;
                int c = C + dir.second;

                while (r >= 0 && r < H && c >= 0 && c < W) {
                    if (grid[r][c] > 0) {
                        remainingWalls--;
                        grid[r][c]--;
                        break;
                    }
                    r += dir.first;
                    c += dir.second;
                }
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}
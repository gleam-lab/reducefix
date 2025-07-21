#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    // Initialize the grid with all walls
    vector<vector<set<int>>> G(H, vector<set<int>>(W, set<int>(1, W)));

    for (int q = 0; q < Q; q++) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to zero-indexed

        // Check if the wall exists at (R, C)
        if (G[R][C].size() == 1) {
            // The wall at (R, C) exists, remove it
            G[R][C].clear();
        } else {
            // The wall at (R, C) does not exist, simulate the destruction
            set<int> cells_to_destroy;
            for (int i = max(0, R - 1); i <= min(H - 1, R + 1); i++) {
                for (int j = max(0, C - 1); j <= min(W - 1, C + 1); j++) {
                    if (i == R && j == C) continue;
                    if (G[i][j].size() == 1) {
                        // There's only one wall, so destroy it
                        cells_to_destroy.insert(i * W + j);
                    }
                }
            }

            // Remove the walls marked for destruction
            for (int cell : cells_to_destroy) {
                int r = cell / W;
                int c = cell % W;
                G[r][c].clear();
            }
        }
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            remaining_walls += G[i][j].size();
        }
    }

    cout << remaining_walls << endl;
}
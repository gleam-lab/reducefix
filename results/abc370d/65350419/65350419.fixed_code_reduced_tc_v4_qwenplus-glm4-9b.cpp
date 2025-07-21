#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<int>> grid(H, vector<int>(W));
    vector<vector<set<int>>> tate(W, vector<set<int>>(H));
    vector<vector<set<int>>> yoko(H, vector<set<int>>(W));

    // Initialize the grid and the sets
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            grid[i][j] = 1; // 1 wall
            tate[j][i] = {i};
            yoko[i][j] = {j};
        }
    }

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--; // Convert to 0-based indexing

        // Check if there's a wall at (R, C)
        if (!tate[C][R].empty()) {
            tate[C][R].erase(R);
            yoko[R][C].erase(C);
            grid[R][C] = 0; // No wall
        } else {
            // Remove walls in all four directions
            // Up direction
            for (auto it = tate[C].lower_bound(R); it != tate[C].end(); ++it) {
                if (grid[*it][C] == 1) {
                    tate[C].erase(it);
                    yoko[*it][C].erase(C);
                    grid[*it][C] = 0;
                    break;
                }
            }
            // Down direction
            for (auto it = tate[C].lower_bound(R); it != tate[C].begin(); --it) {
                if (grid[*it][C] == 1) {
                    tate[C].erase(it);
                    yoko[*it][C].erase(C);
                    grid[*it][C] = 0;
                    break;
                }
            }
            // Left direction
            for (auto it = yoko[R].lower_bound(C); it != yoko[R].end(); ++it) {
                if (grid[R][*it] == 1) {
                    yoko[R][C].erase(it);
                    tate[*it][R].erase(R);
                    grid[R][*it] = 0;
                    break;
                }
            }
            // Right direction
            for (auto it = yoko[R].lower_bound(C); it != yoko[R].begin(); --it) {
                if (grid[R][*it] == 1) {
                    yoko[R][C].erase(it);
                    tate[*it][R].erase(R);
                    grid[R][*it] = 0;
                    break;
                }
            }
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 1) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1)); // grid[i][j] = 1 represents a wall

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert to 0-based index
        if (grid[r][c] == 1) {
            grid[r][c] = 0; // Destroy the wall
        } else {
            // Destroy the first wall in each row and column
            for (int j = 0; j < w && grid[r][j] == 1; j++) {
                grid[r][j] = 0;
            }
            for (int i = 0; i < h && grid[i][c] == 1; i++) {
                grid[i][c] = 0;
            }
        }
    }
    
    // Count the remaining walls
    ll remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += grid[i][j];
        }
    }
    
    cout << remaining_walls << "\n";
    return 0;
}
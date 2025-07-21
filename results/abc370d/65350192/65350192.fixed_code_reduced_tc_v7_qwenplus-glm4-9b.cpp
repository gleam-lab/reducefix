#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> up(h + 1, set<int>(w + 1));
    vector<set<int>> down(h + 1, set<int>(w + 1));
    vector<set<int>> left(w + 1, set<int>(h + 1));
    vector<set<int>> right(w + 1, set<int>(h + 1));
    vector<vector<int>> grid(h + 1, vector<int>(w + 1, -1)); // grid[h][w] = number of walls at (h, w)
    
    // Initialize the walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            grid[i][j] = 2; // 2 walls at (h, w): one for vertical and one for horizontal walls
            up[i][j] = 1; // There's a wall above (i, j)
            down[i - 1][j] = 1; // There's a wall below (i - 1, j)
            left[i][j] = 1; // There's a wall to the left of (i, j)
            right[i][j] = 1; // There's a wall to the right of (i, j)
        }
    }
    
    int r, c;
    while (q--) {
        cin >> r >> c;
        if (grid[r][c] == 2) {
            // Bomb explodes at a cell with walls
            grid[r][c]--;
            up[r][c]--;
            if (up[r][c] == 0) up[r - 1][c]--; // Remove wall above
            down[r][c]--;
            if (down[r][c] == 0) down[r + 1][c]--; // Remove wall below
            left[r][c]--;
            if (left[r][c] == 0) left[r][c - 1]--; // Remove wall to the left
            right[r][c]--;
            if (right[r][c] == 0) right[r][c + 1]--; // Remove wall to the right
        } else {
            // Bomb destroys walls around the cell
            grid[r][c]--;
            up[r][c]--;
            down[r - 1][c]--;
            left[r][c]--;
            right[r][c]--;
        }
    }
    
    int remaining_walls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            remaining_walls += grid[i][j];
        }
    }
    
    cout << remaining_walls << endl;
    return 0;
}
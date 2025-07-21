#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> walls(h + 1, vector<int>(w + 1, 0));
    vector<int> top_wall(w + 1, 0);
    vector<int> left_wall(h + 1, 0);
    
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            // Initially, all cells have a wall
            walls[i][j] = 1;
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (walls[r][c]) {
            // If there's a wall at (r, c), destroy it
            walls[r][c] = 0;
            if (r > 1) --top_wall[c];
            if (c > 1) --left_wall[r];
        } else {
            // Find the first and last wall in the row and column
            int first_row = r, last_row = r;
            while (first_row > 0 && !walls[first_row - 1][c]) --first_row;
            while (last_row < h && !walls[last_row + 1][c]) ++last_row;
            
            int first_col = c, last_col = c;
            while (first_col > 0 && !walls[r][first_col - 1]) --first_col;
            while (last_col < w && !walls[r][last_col + 1]) ++last_col;
            
            // Destroy walls in the row and column
            for (int j = first_row; j <= last_row; ++j) {
                if (j > 1) --top_wall[c];
                if (j < h) ++left_wall[j];
            }
            for (int i = first_col; i <= last_col; ++i) {
                if (i > 1) --left_wall[i];
                if (i < w) ++top_wall[c];
            }
        }
    }
    
    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 1; i < h + 1; ++i) {
        for (int j = 1; j < w + 1; ++j) {
            remaining_walls += walls[i][j];
        }
    }
    
    cout << remaining_walls << endl;
    return 0;
}
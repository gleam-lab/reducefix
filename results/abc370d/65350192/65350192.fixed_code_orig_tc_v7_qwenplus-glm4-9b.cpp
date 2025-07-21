#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<set<int>> tate(h), yoko(w);
    vector<vector<int>> grid(h, vector<int>(w, 0)); // To mark deleted walls
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            tate[j].insert(i);
            yoko[i].insert(j);
            grid[i][j] = 1; // Initially, each cell has a wall
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index
        
        // Check if there is a wall at (r, c)
        if (grid[r][c] == 1) {
            // Destroy the wall at (r, c)
            grid[r][c] = 0;
            tate[c].erase(r);
            yoko[r].erase(c);
        } else {
            // Find the nearest walls in the row and column
            int r_up = *lower_bound(tate[c].begin(), tate[c].end(), r);
            int r_down = *upper_bound(tate[c].begin(), tate[c].end(), r);
            int c_left = *lower_bound(yoko[r].begin(), yoko[r].end(), c);
            int c_right = *upper_bound(yoko[r].begin(), yoko[r].end(), c);
            
            // Remove walls from r_up to r and from c_left to c
            for (int i = r_up; i < r_down; ++i) {
                grid[i][c] = 0;
                tate[c].erase(i);
            }
            for (int j = c_left; j < c_right; ++j) {
                grid[r][j] = 0;
                yoko[r].erase(j);
            }
        }
    }

    // Calculate the number of remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 1) {
                remaining_walls++;
            }
        }
    }

    cout << remaining_walls << endl;
    return 0;
}
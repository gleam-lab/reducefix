#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define MAX_H 400010
#define MAX_W 400010

vector<vector<set<int>>> grid(MAX_H, vector<set<int>>(MAX_W));

void clear_walls(int x, int y) {
    grid[x][y].clear();
    if (x > 0) grid[x - 1][y].erase(y);
    if (x < MAX_H - 1) grid[x + 1][y].erase(y);
    if (y > 0) grid[x][y - 1].erase(y);
    if (y < MAX_W - 1) grid[x][y + 1].erase(y);
}

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // Initialize the grid with walls
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            grid[i][j].insert(j);
            grid[i][j].insert(j + 1);
        }
    }
    
    // Process queries
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if (grid[r][c].size() == 2) { // There's a wall at the cell
            clear_walls(r, c);
        } else {
            // Remove walls in the four directions
            int i = r - 1, j = c - 1;
            while (i >= 0 && grid[i][j].size() == 2) {
                clear_walls(i, j);
                i--;
            }
            
            i = r + 1;
            while (i < h && grid[i][j].size() == 2) {
                clear_walls(i, j);
                i++;
            }
            
            i = r;
            while (j >= 0 && grid[i][j].size() == 2) {
                clear_walls(i, j);
                j--;
            }
            
            j = c + 1;
            while (j < w && grid[i][j].size() == 2) {
                clear_walls(i, j);
                j++;
            }
        }
    }
    
    // Count remaining walls
    int remaining_walls = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            remaining_walls += grid[i][j].size();
        }
    }
    
    cout << remaining_walls << endl;
    return 0;
}
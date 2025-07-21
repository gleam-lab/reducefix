#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    int total_walls = h * w;
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c]) {
            grid[r][c] = false;
            total_walls--;
        } else {
            bool found = false;
            
            // Check upwards
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    total_walls--;
                    found = true;
                    break;
                }
            }
            
            // Check downwards
            if (!found) {
                for (int i = r + 1; i < h; ++i) {
                    if (grid[i][c]) {
                        grid[i][c] = false;
                        total_walls--;
                        found = true;
                        break;
                    }
                }
            }
            
            // Check leftwards
            if (!found) {
                for (int j = c - 1; j >= 0; --j) {
                    if (grid[r][j]) {
                        grid[r][j] = false;
                        total_walls--;
                        found = true;
                        break;
                    }
                }
            }
            
            // Check rightwards
            if (!found) {
                for (int j = c + 1; j < w; ++j) {
                    if (grid[r][j]) {
                        grid[r][j] = false;
                        total_walls--;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    
    cout << total_walls << "\n";
    return 0;
}
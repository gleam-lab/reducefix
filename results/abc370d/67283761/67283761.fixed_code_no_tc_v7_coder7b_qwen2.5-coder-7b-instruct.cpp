#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    
    while(Q--) {
        int r, c;
        cin >> r >> c;
        
        if(grid[--r][--c]) {
            // Place bomb at (r, c)
            grid[r][c] = false;
        } else {
            // Destroy walls around (r, c)
            for(int i = max(0, r-1); i <= min(H-1, r+1); ++i) {
                if(i == r) continue;
                if(grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            
            for(int j = max(0, c-1); j <= min(W-1, c+1); ++j) {
                if(j == c) continue;
                if(grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
        }
    }

    // Count remaining walls
    int remaining_walls = 0;
    for(const auto& row : grid) {
        remaining_walls += count(row.begin(), row.end(), true);
    }

    cout << remaining_walls << '\n';

    return 0;
}
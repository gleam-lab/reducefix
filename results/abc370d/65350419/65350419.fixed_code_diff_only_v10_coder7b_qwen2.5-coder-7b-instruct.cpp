#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    while(q--) {
        int r, c;
        cin >> r >> c;
        --r; --c; // Convert to 0-based index
        if(grid[r][c]) { // If there's a wall at this position
            grid[r][c] = false; // Destroy it
        } else { // If there's no wall
            // Find the nearest wall above
            for(int i=r-1; i>=0; --i)
                if(grid[i][c]) {
                    grid[i][c] = false; // Destroy it
                    break;
                }
            
            // Find the nearest wall below
            for(int i=r+1; i<h; ++i)
                if(grid[i][c]) {
                    grid[i][c] = false; // Destroy it
                    break;
                }
            
            // Find the nearest wall left
            for(int j=c-1; j>=0; --j)
                if(grid[r][j]) {
                    grid[r][j] = false; // Destroy it
                    break;
                }
            
            // Find the nearest wall right
            for(int j=c+1; j<w; ++j)
                if(grid[r][j]) {
                    grid[r][j] = false; // Destroy it
                    break;
                }
        }
    }
    int ans = 0;
    for(auto &row:grid)
        ans += count(row.begin(), row.end(), true);
    cout << ans << '\n';
    return 0;
}
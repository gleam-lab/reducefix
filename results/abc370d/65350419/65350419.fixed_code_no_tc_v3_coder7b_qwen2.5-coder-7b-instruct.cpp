#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true)); // Initialize grid with walls
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c; // Convert to zero-indexed
        
        if (!grid[r][c]) continue; // Skip if already destroyed
        
        grid[r][c] = false; // Destroy current cell
        
        // Check and destroy upward
        for (int i = r - 1; i >= 0 && grid[i][c]; --i)
            grid[i][c] = false;
        
        // Check and destroy downward
        for (int i = r + 1; i < h && grid[i][c]; ++i)
            grid[i][c] = false;
        
        // Check and destroy leftward
        for (int j = c - 1; j >= 0 && grid[r][j]; --j)
            grid[r][j] = false;
        
        // Check and destroy rightward
        for (int j = c + 1; j < w && grid[r][j]; ++j)
            grid[r][j] = false;
    }
    
    int ans = 0;
    rep(i, h) rep(j, w) 
        if (grid[i][j]) ++ans; // Count remaining walls
    
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int h, w, q;
    cin >> h >> w >> q;
    
    vector<vector<char>> grid(h + 2, vector<char>(w + 2, '#'));
    vector<vector<bool>> vis(h + 2, vector<bool>(w + 2, false));
    
    while(q--) {
        int r, c;
        cin >> r >> c;
        
        if(grid[r][c] == '.') continue;
        
        grid[r][c] = '.';
        vis[r][c] = true;
        
        // Up
        for(int i = r - 1; i >= 1 && grid[i][c] == '#' && !vis[i][c]; --i) {
            grid[i][c] = '.';
            vis[i][c] = true;
        }
        
        // Down
        for(int i = r + 1; i <= h && grid[i][c] == '#' && !vis[i][c]; ++i) {
            grid[i][c] = '.';
            vis[i][c] = true;
        }
        
        // Left
        for(int j = c - 1; j >= 1 && grid[r][j] == '#' && !vis[r][j]; --j) {
            grid[r][j] = '.';
            vis[r][j] = true;
        }
        
        // Right
        for(int j = c + 1; j <= w && grid[r][j] == '#' && !vis[r][j]; ++j) {
            grid[r][j] = '.';
            vis[r][j] = true;
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(grid[i][j] == '#') ++cnt;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
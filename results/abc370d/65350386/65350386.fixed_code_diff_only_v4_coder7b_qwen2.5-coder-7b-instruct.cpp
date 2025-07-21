#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    int count = h * w;
    
    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        
        if(grid[r][c]) {
            grid[r][c] = false;
            count--;
        } else {
            // Destroy walls upwards
            for(int i = r - 1; i >= 0 && !grid[i][c]; --i) {
                grid[i][c] = false;
                count--;
            }
            
            // Destroy walls downwards
            for(int i = r + 1; i < h && !grid[i][c]; ++i) {
                grid[i][c] = false;
                count--;
            }
            
            // Destroy walls to the left
            for(int j = c - 1; j >= 0 && !grid[r][j]; --j) {
                grid[r][j] = false;
                count--;
            }
            
            // Destroy walls to the right
            for(int j = c + 1; j < w && !grid[r][j]; ++j) {
                grid[r][j] = false;
                count--;
            }
        }
    }
    
    cout << count << "\n";
    return 0;
}
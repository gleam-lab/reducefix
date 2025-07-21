#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    ll ans = H * W;
    
    for (int i = 0; i < Q; i++) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        if (!grid[R][C]) {
            continue; // If there's no wall, just skip the query
        }
        grid[R][C] = false; // Destroy the wall at (R, C)
        ans--; // Decrease the count of walls by 1
        
        // Check and destroy walls to the left
        for (int j = C - 1; j >= 0 && grid[R][j]; j--) {
            grid[R][j] = false;
            ans--;
        }
        
        // Check and destroy walls to the right
        for (int j = C + 1; j < W && grid[R][j]; j++) {
            grid[R][j] = false;
            ans--;
        }
        
        // Check and destroy walls above
        for (int i = R - 1; i >= 0 && grid[i][C]; i--) {
            grid[i][C] = false;
            ans--;
        }
        
        // Check and destroy walls below
        for (int i = R + 1; i < H && grid[i][C]; i++) {
            grid[i][C] = false;
            ans--;
        }
    }
    
    cout << ans << endl;
    return 0;
}
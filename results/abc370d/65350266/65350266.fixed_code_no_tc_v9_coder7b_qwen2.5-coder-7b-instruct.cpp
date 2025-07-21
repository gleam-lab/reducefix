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
        r--; c--;
        if(grid[r][c]) {
            grid[r][c] = false;
            // Check up
            for(int i = r - 1; i >= 0; --i) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                } else break;
            }
            // Check down
            for(int i = r + 1; i < h; ++i) {
                if(grid[i][c]) {
                    grid[i][c] = false;
                } else break;
            }
            // Check left
            for(int j = c - 1; j >= 0; --j) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                } else break;
            }
            // Check right
            for(int j = c + 1; j < w; ++j) {
                if(grid[r][j]) {
                    grid[r][j] = false;
                } else break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
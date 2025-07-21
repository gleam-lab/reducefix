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
        --r; --c;
        if(grid[r][c]) {
            grid[r][c] = false;
            continue;
        }
        int i = r, j = c;
        // Check upwards
        while(i > 0 && !grid[--i][j]);
        if(i > 0) {
            grid[i][j] = false;
        }
        i = r, j = c;
        // Check downwards
        while(i < h - 1 && !grid[++i][j]);
        if(i < h - 1) {
            grid[i][j] = false;
        }
        i = r, j = c;
        // Check leftwards
        while(j > 0 && !grid[i][--j]);
        if(j > 0) {
            grid[i][j] = false;
        }
        i = r, j = c;
        // Check rightwards
        while(j < w - 1 && !grid[i][++j]);
        if(j < w - 1) {
            grid[i][j] = false;
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) if(grid[i][j]) ++ans;
    cout << ans << "\n";
    return 0;
}
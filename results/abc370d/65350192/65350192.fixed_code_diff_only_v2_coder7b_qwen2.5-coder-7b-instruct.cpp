#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    while(q--) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            bool found = false;
            // Check upwards
            for(int i = r - 1; i >= 0 && !found; --i)
                if(grid[i][c]) {
                    grid[i][c] = false;
                    found = true;
                }
            // Check downwards
            for(int i = r + 1; i < h && !found; ++i)
                if(grid[i][c]) {
                    grid[i][c] = false;
                    found = true;
                }
            // Check leftwards
            for(int j = c - 1; j >= 0 && !found; --j)
                if(grid[r][j]) {
                    grid[r][j] = false;
                    found = true;
                }
            // Check rightwards
            for(int j = c + 1; j < w && !found; ++j)
                if(grid[r][j]) {
                    grid[r][j] = false;
                    found = true;
                }
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) ans += grid[i][j];
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    while(q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if(grid[r][c]) {
            grid[r][c] = 0;
        } else {
            for(int i = r-1; i >= 0; --i) {
                if(!grid[i][c]) break;
                grid[i][c] = 0;
            }
            for(int i = r+1; i < h; ++i) {
                if(!grid[i][c]) break;
                grid[i][c] = 0;
            }
            for(int j = c-1; j >= 0; --j) {
                if(!grid[r][j]) break;
                grid[r][j] = 0;
            }
            for(int j = c+1; j < w; ++j) {
                if(!grid[r][j]) break;
                grid[r][j] = 0;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            ans += grid[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}
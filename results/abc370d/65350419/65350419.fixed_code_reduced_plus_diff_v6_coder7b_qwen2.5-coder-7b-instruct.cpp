#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            for(int i = r; i >= 0 && !grid[i][c]; --i);
            if(i >= 0) grid[i][c] = false;

            for(int i = r; i < h && !grid[i][c]; ++i);
            if(i < h) grid[i][c] = false;

            for(int j = c; j >= 0 && !grid[r][j]; --j);
            if(j >= 0) grid[r][j] = false;

            for(int j = c; j < w && !grid[r][j]; ++j);
            if(j < w) grid[r][j] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j]) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
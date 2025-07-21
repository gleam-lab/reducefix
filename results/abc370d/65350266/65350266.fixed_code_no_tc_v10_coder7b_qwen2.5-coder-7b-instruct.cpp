#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (grid[r][c]) {
            grid[r][c] = false;
            int i = r - 1;
            while (i >= 0 && !grid[i][c]) --i;
            if (i >= 0) grid[i][c] = false;
            
            i = r + 1;
            while (i < h && !grid[i][c]) ++i;
            if (i < h) grid[i][c] = false;
            
            i = c - 1;
            while (i >= 0 && !grid[r][i]) --i;
            if (i >= 0) grid[r][i] = false;
            
            i = c + 1;
            while (i < w && !grid[r][i]) ++i;
            if (i < w) grid[r][i] = false;
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) if (grid[i][j]) ++ans;
    cout << ans << "\n";
    return 0;
}
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

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!grid[r][c]) continue;

        grid[r][c] = false;
        
        // Destroying walls above (r, c)
        for (int i = r-1; i >= 0; --i) {
            if (grid[i][c]) break;
            grid[i][c] = false;
        }
        
        // Destroying walls below (r, c)
        for (int i = r+1; i < h; ++i) {
            if (grid[i][c]) break;
            grid[i][c] = false;
        }
        
        // Destroying walls to the left of (r, c)
        for (int j = c-1; j >= 0; --j) {
            if (grid[r][j]) break;
            grid[r][j] = false;
        }
        
        // Destroying walls to the right of (r, c)
        for (int j = c+1; j < w; ++j) {
            if (grid[r][j]) break;
            grid[r][j] = false;
        }
    }

    int count = 0;
    for (const auto &row : grid) {
        for (bool cell : row) {
            if (cell) ++count;
        }
    }

    cout << count << endl;

    return 0;
}
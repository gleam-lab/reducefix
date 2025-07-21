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
        --r, --c; // Convert to zero-based index
        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            // Destroy walls in the same column as (r, c)
            for (int i = 0; i < h; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            // Destroy walls in the same row as (r, c)
            for (int j = 0; j < w; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (const auto& row : grid) {
        for (bool cell : row) {
            if (cell) ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
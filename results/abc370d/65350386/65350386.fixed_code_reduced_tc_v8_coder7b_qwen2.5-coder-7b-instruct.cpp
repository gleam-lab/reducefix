#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (grid[r][c]) {
            grid[r][c] = false;
        } else {
            for (int i = 0; i < h; i++) {
                if (i == r) continue;
                if (grid[i][c] && !grid[i-1][c]) break;
                if (!grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            for (int i = h-1; i >= 0; i--) {
                if (i == r) continue;
                if (grid[i][c] && !grid[i+1][c]) break;
                if (!grid[i][c]) {
                    grid[i][c] = false;
                    break;
                }
            }
            for (int j = 0; j < w; j++) {
                if (j == c) continue;
                if (grid[r][j] && !grid[r][j-1]) break;
                if (!grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
            for (int j = w-1; j >= 0; j--) {
                if (j == c) continue;
                if (grid[r][j] && !grid[r][j+1]) break;
                if (!grid[r][j]) {
                    grid[r][j] = false;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (const auto& row : grid) {
        for (bool cell : row) {
            if (cell) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
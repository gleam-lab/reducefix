#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    while(q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(grid[r][c] == 0) continue;

        grid[r][c] = 0;

        for(int i = r-1; i >= 0 && grid[i][c]; --i) {
            grid[i][c] = 0;
        }

        for(int i = r+1; i < h && grid[i][c]; ++i) {
            grid[i][c] = 0;
        }

        for(int j = c-1; j >= 0 && grid[r][j]; --j) {
            grid[r][j] = 0;
        }

        for(int j = c+1; j < w && grid[r][j]; ++j) {
            grid[r][j] = 0;
        }
    }

    int ans = 0;
    for(const auto& row : grid) {
        ans += count(row.begin(), row.end(), 1);
    }

    cout << ans << '\n';

    return 0;
}
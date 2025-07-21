#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    vector<pair<int, int>> queries(q);
    rep(i, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        queries[i] = {r, c};
    }

    for(auto& [r, c]: queries) {
        if(grid[r][c]) {
            grid[r][c] = false;
        } else {
            int up = r, down = r, left = c, right = c;
            while(up > 0 && grid[up-1][c]) --up;
            while(down+1 < h && grid[down+1][c]) ++down;
            while(left > 0 && grid[r][left-1]) --left;
            while(right+1 < w && grid[r][right+1]) ++right;
            for(int i = up; i <= down; ++i) {
                if(i != r) grid[i][c] = false;
            }
            for(int j = left; j <= right; ++j) {
                if(j != c) grid[r][j] = false;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(grid[i][j]) ++ans;
        }
    }
    cout << ans << "\n";

    return 0;
}
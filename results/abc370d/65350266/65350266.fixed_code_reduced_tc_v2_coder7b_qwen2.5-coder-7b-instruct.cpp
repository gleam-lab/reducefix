#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    int cnt = h * w;

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        if (grid[r][c]) {
            grid[r][c] = false;
            --cnt;
            continue;
        }

        for (int i = r - 1; i >= 0; --i) {
            if (!grid[i][c]) break;
            grid[i][c] = false;
            --cnt;
        }

        for (int i = r + 1; i < h; ++i) {
            if (!grid[i][c]) break;
            grid[i][c] = false;
            --cnt;
        }

        for (int j = c - 1; j >= 0; --j) {
            if (!grid[r][j]) break;
            grid[r][j] = false;
            --cnt;
        }

        for (int j = c + 1; j < w; ++j) {
            if (!grid[r][j]) break;
            grid[r][j] = false;
            --cnt;
        }
    }

    cout << cnt << '\n';
    return 0;
}
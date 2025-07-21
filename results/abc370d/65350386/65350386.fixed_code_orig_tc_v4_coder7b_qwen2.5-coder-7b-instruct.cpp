#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> grid(h, vector<bool>(w, true));
    set<pair<int, int>> bombs;

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--, c--;

        if (!grid[r][c]) {
            continue;
        }

        bombs.insert({r, c});
        grid[r][c] = false;

        // Check above
        for (int i = r - 1; i >= 0; i--) {
            if (bombs.count({i, c})) break;
            bombs.erase({i, c});
            grid[i][c] = false;
        }

        // Check below
        for (int i = r + 1; i < h; i++) {
            if (bombs.count({i, c})) break;
            bombs.erase({i, c});
            grid[i][c] = false;
        }

        // Check left
        for (int j = c - 1; j >= 0; j--) {
            if (bombs.count({r, j})) break;
            bombs.erase({r, j});
            grid[r][j] = false;
        }

        // Check right
        for (int j = c + 1; j < w; j++) {
            if (bombs.count({r, j})) break;
            bombs.erase({r, j});
            grid[r][j] = false;
        }
    }

    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j]) count++;
        }
    }

    cout << count << endl;

    return 0;
}
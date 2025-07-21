#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<int>> grid(h, vector<int>(w, 1));
    vector<pair<int, int>> bombs;

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;
        bombs.push_back({r, c});
    }

    for (auto &bomb : bombs) {
        int x = bomb.first, y = bomb.second;

        if (grid[x][y] == 0) continue;

        grid[x][y] = 0;

        for (int i = 0; i < x; ++i) {
            if (grid[i][y] == 0) break;
            grid[i][y] = 0;
        }

        for (int i = x + 1; i < h; ++i) {
            if (grid[i][y] == 0) break;
            grid[i][y] = 0;
        }

        for (int j = 0; j < y; ++j) {
            if (grid[x][j] == 0) break;
            grid[x][j] = 0;
        }

        for (int j = y + 1; j < w; ++j) {
            if (grid[x][j] == 0) break;
            grid[x][j] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            count += grid[i][j];
        }
    }

    cout << count << '\n';

    return 0;
}
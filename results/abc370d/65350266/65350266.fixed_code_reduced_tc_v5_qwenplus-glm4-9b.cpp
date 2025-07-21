#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h + 1, vector<int>(w + 1, h * w)); // grid[i][j] will hold the number of walls between (i, j) and (i-1, j) or (i, j-1)
    vector<vector<bool>> removed_wall(h + 1, vector<bool>(w + 1, false));

    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (r > 0 && !removed_wall[r][c]) {
            // Check the wall above
            if (grid[r - 1][c] && grid[r][c]) {
                removed_wall[r][c] = true;
                removed_wall[r - 1][c] = true;
                grid[r][c] = 0;
            }
        }
        if (c > 0 && !removed_wall[r][c]) {
            // Check the wall to the left
            if (grid[r][c - 1] && grid[r][c]) {
                removed_wall[r][c] = true;
                removed_wall[r][c - 1] = true;
                grid[r][c] = 0;
            }
        }
    }

    ll remaining_walls = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> grid(h + 2, vector<bool>(w + 2, true)); // grid[h+1][w+1] is unused

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            set<int> &row = grid[i][j];
            row.insert(i);
            row.insert(j);
        }
    }

    function<void(int, bool)> removeWall = [&](int r, bool vertical) {
        if (vertical) {
            for (int i = 1; i <= h; ++i) {
                set<int> &row = grid[i][r];
                auto it = row.lower_bound(r + 1);
                if (it != row.end()) row.erase(*it);
                it = row.lower_bound(r - 1);
                if (it != row.end()) row.erase(*it);
            }
        } else {
            for (int j = 1; j <= w; ++j) {
                set<int> &col = grid[r][j];
                auto it = col.lower_bound(r + 1);
                if (it != col.end()) col.erase(*it);
                it = col.lower_bound(r - 1);
                if (it != col.end()) col.erase(*it);
            }
        }
    };

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (!grid[r][c]) {
            removeWall(r, true); // Remove walls in the row
            removeWall(c, false); // Remove walls in the column
        } else {
            grid[r][c] = false; // Bomb explodes at this cell
        }
    }

    int remainingWalls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j]) {
                remainingWalls++;
            }
        }
    }

    cout << remainingWalls << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<set<pair<int, int>>>> grid(h, vector<set<pair<int, int>>>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j].insert({i, j});
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c].size() == 0) {
            // No wall at (r, c), need to destroy walls in all directions
            for (int i = 0; i < h; ++i) {
                if (i == r) continue;
                if (grid[i][c].size() > 0) {
                    grid[i][c].erase({i, c});
                }
            }
            for (int j = 0; j < w; ++j) {
                if (j == c) continue;
                if (grid[r][j].size() > 0) {
                    grid[r][j].erase({r, j});
                }
            }
        } else {
            // There is a wall at (r, c), destroy it
            grid[r][c].erase({r, c});
        }
    }

    long long remaining_walls = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            remaining_walls += grid[i][j].size();
        }
    }

    cout << remaining_walls << endl;

    return 0;
}
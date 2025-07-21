#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 4e5 + 10;

vector<vector<bool>> grid(MAXN, vector<bool>(MAXN, true));

void destroyWalls(int r, int c) {
    for (int i = 1; i <= grid.size() - 1; ++i) {
        if (grid[i][c]) {
            grid[i][c] = false;
            break;
        }
    }
    for (int i = 1; i <= grid[r].size() - 1; ++i) {
        if (grid[r][i]) {
            grid[r][i] = false;
            break;
        }
    }
    // Destroy walls to the right
    for (int j = c + 1; j <= grid[r].size(); ++j) {
        if (grid[r][j]) {
            grid[r][j] = false;
            break;
        }
    }
    // Destroy walls to the left
    for (int j = c - 1; j > 0; --j) {
        if (grid[r][j]) {
            grid[r][j] = false;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, q;
    cin >> h >> w >> q;

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (grid[r][c]) {
            destroyWalls(r, c);
        }
    }

    int remaining_walls = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j]) {
                ++remaining_walls;
            }
        }
    }

    cout << remaining_walls << endl;

    return 0;
}
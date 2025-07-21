#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 4e5 + 10;
bool grid[MAXN][MAXN];
int cache[MAXN][MAXN][4];
int remainingWalls;

void destroyWalls(int r, int c) {
    // Directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int x = r, y = c;
        while (true) {
            x += dirs[i][0];
            y += dirs[i][1];
            if (x < 1 || x > MAXN || y < 1 || y > MAXN || grid[x][y] == false) break;
            if (grid[x][y] == true) {
                grid[x][y] = false;
                remainingWalls--;
                break;
            }
        }
    }
}

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    memset(grid, true, sizeof(grid));
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            cache[i][j][0] = cache[i][j][1] = cache[i][j][2] = cache[i][j][3] = 0;
        }
    }

    for (int i = 0; i < Q; ++i) {
        int r, c;
        cin >> r >> c;
        if (grid[r][c]) {
            grid[r][c] = false;
            remainingWalls--;
        }
    }
    cout << (H * W - remainingWalls) << endl;

    return 0;
}
#include <iostream>
using namespace std;

const int MAXN = 400005;
int grid[MAXN][MAXN];
int rows, cols, queries;

void removeWalls(int r, int c) {
    if (grid[r][c] == 0) return;
    grid[r][c] = 0;

    if (r > 0) removeWalls(r - 1, c);
    if (r < rows - 1) removeWalls(r + 1, c);
    if (c > 0) removeWalls(r, c - 1);
    if (c < cols - 1) removeWalls(r, c + 1);
}

int main() {
    cin >> rows >> cols >> queries;

    for (int i = 0; i < queries; i++) {
        int r, c;
        cin >> r >> c;
        if (grid[r - 1][c - 1] > 0) {
            removeWalls(r - 1, c - 1);
        }
    }

    int remainingWalls = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            remainingWalls += grid[i][j];
        }
    }

    cout << remainingWalls << endl;

    return 0;
}
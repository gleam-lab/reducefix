#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flood_fill(vector<vector<int>>& grid, int r, int c, int h, int w) {
    if (r < 0 || r >= h || c < 0 || c >= w) return;
    if (grid[r][c] == 0) return; // already visited
    grid[r][c] = 0; // mark as sunk
    flood_fill(grid, r - 1, c, h, w);
    flood_fill(grid, r + 1, c, h, w);
    flood_fill(grid, r, c - 1, h, w);
    flood_fill(grid, r, c + 1, h, w);
}

int main() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> A(h, vector<int>(w));
    vector<vector<int>> S(h, vector<int>(w, -2)); // sea or border
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1 || A[i][j] == 0)
                S[i][j] = 0; // sea
        }
    }

    vector<int> years(y + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (S[i][j] == 0) continue; // sea
            if (A[i][j] > 0) {
                if (A[i][j] <= y) {
                    flood_fill(S, i, j, h, w);
                    years[A[i][j]]++;
                }
            }
        }
    }

    for (int i = 1; i <= y; ++i) {
        years[i] += years[i - 1];
        cout << h * w - years[i] << endl;
    }

    return 0;
}
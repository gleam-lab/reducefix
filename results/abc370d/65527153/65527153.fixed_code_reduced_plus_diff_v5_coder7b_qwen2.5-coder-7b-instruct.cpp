#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

vector<vector<bool>> grid;

void destroyWall(int r, int c) {
    if (grid[r][c]) {
        grid[r][c] = false;
    } else {
        // Find the closest wall above
        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }
        // Find the closest wall below
        for (int i = r + 1; i < grid.size(); ++i) {
            if (grid[i][c]) {
                grid[i][c] = false;
                break;
            }
        }
        // Find the closest wall left
        for (int j = c - 1; j >= 0; --j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }
        // Find the closest wall right
        for (int j = c + 1; j < grid[0].size(); ++j) {
            if (grid[r][j]) {
                grid[r][j] = false;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    grid.resize(h, vector<bool>(w, true));

    while (q--) {
        int r, c;
        cin >> r >> c;
        destroyWall(r-1, c-1); // Adjusting indices as input is 1-based
    }

    int count = 0;
    for (auto &row : grid) {
        for (bool cell : row) {
            if (cell) count++;
        }
    }

    cout << count << endl;

    return 0;
}
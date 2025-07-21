#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

// Function to erase the wall in direction dir (0: up, 1: down, 2: left, 3: right)
void eraseWall(vector<vector<int>>& grid, int x, int y, int dir) {
    while (true) {
        switch (dir) {
            case 0: if (--x >= 0 && grid[x][y] == 1) { grid[x][y] = 0; } else { return; } break;
            case 1: if (++x < grid.size() && grid[x][y] == 1) { grid[x][y] = 0; } else { return; } break;
            case 2: if (--y >= 0 && grid[x][y] == 1) { grid[x][y] = 0; } else { return; } break;
            case 3: if (++y < grid[0].size() && grid[x][y] == 1) { grid[x][y] = 0; } else { return; } break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> grid(h, vector<int>(w, 1));

    while (q--) {
        int r, c;
        cin >> r >> c;
        --r, --c;  // Convert to zero-indexed

        if (grid[r][c] == 1) {
            grid[r][c] = 0;
        } else {
            eraseWall(grid, r, c, 0);
            eraseWall(grid, r, c, 1);
            eraseWall(grid, r, c, 2);
            eraseWall(grid, r, c, 3);
        }
    }

    int count = 0;
    for (auto& row : grid) {
        for (auto& val : row) {
            if (val == 1) count++;
        }
    }

    cout << count << endl;
    return 0;
}
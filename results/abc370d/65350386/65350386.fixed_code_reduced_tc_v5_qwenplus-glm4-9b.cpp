#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN (4 * 100000 + 10)
#define MOD (1000000007)

int grid[MAXN][MAXN];
int n, m, q;

void destroy_walls(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = 0; // Wall is destroyed

    // Vertical walls
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Check left
        if (y > 0 && grid[x][y - 1]) {
            grid[x][y - 1] = 0;
            q.push({x, y - 1});
        }

        // Check right
        if (y < m - 1 && grid[x][y + 1]) {
            grid[x][y + 1] = 0;
            q.push({x, y + 1});
        }
    }
}

int main() {
    cin >> n >> m >> q;
    int r, c;
    while (q--) {
        cin >> r >> c;
        if (grid[r - 1][c - 1]) {
            destroy_walls(r - 1, c - 1);
        }
    }

    int remaining_walls = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            remaining_walls += grid[i][j];
        }
    }

    cout << remaining_walls << endl;
    return 0;
}
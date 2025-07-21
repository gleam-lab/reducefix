#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Dir {
    int x, y;
};

const Dir directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y, int H, int W) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

void floodFill(vector<vector<int>>& grid, int x, int y, int seaLevel) {
    queue<tuple<int, int, int>> q; // queue of (x, y, seaLevel)
    q.push(make_tuple(x, y, seaLevel));

    while (!q.empty()) {
        auto [currX, currY, currSeaLevel] = q.front();
        q.pop();

        if (grid[currX][currY] <= currSeaLevel) continue;

        grid[currX][currY] = currSeaLevel;

        for (const auto& dir : directions) {
            int newX = currX + dir.x, newY = currY + dir.y;
            if (isValid(newX, newY, grid.size(), grid[0].size()) && grid[newX][newY] > currSeaLevel) {
                q.push(make_tuple(newX, newY, currSeaLevel + 1));
            }
        }
    }
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    // Start with the initial sea level being 0
    for (int year = 0; year < Y; ++year) {
        vector<vector<int>> grid(H, vector<int>(W, 1)); // Grid initialized to above sea level

        // Apply flood-fill algorithm from all edges
        for (int i = 0; i < H; ++i) {
            floodFill(grid, i, 0, year + 1); // Top edge
            floodFill(grid, i, W - 1, year + 1); // Bottom edge
        }

        for (int j = 0; j < W; ++j) {
            floodFill(grid, 0, j, year + 1); // Left edge
            floodFill(grid, H - 1, j, year + 1); // Right edge
        }

        // Calculate the area of the island that remains above sea level
        int remainingArea = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                remainingArea += grid[i][j];
            }
        }

        cout << remainingArea << endl;
    }

    return 0;
}
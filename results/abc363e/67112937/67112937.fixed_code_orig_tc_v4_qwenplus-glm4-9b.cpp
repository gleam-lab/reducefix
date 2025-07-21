#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000;

vector<vector<int>> elevation;
vector<vector<bool>> visited;
vector<vector<int>> sea_level;

void dfs(int x, int y, int currentSeaLevel) {
    if (visited[x][y] || elevation[x][y] > currentSeaLevel) {
        return;
    }
    visited[x][y] = true;
    // Perform DFS for all adjacent cells (up, down, left, right)
    // ...
}

int main() {
    int H, W, Y;
    cin >> H >> W >> Y;
    
    elevation.resize(H, vector<int>(W));
    visited.resize(H, vector<bool>(W, false));
    sea_level.resize(Y + 1, vector<int>(H * W, 0));

    // Read the elevation matrix
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> elevation[i][j];
        }
    }

    // Calculate the initial sea level for each year
    for (int year = 1; year <= Y; ++year) {
        sea_level[year][0] = 1;
        for (int i = 1; i < H * W; ++i) {
            sea_level[year][i] = max(sea_level[year][i - 1], sea_level[year - 1][i - 1] + 1);
        }
    }

    // Initialize the area of the island that remains above sea level
    long long aboveSeaLevelArea = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            aboveSeaLevelArea += elevation[i][j];
        }
    }

    // Simulate the sinking of the island for each year
    for (int year = 1; year <= Y; ++year) {
        // Start DFS from all edges
        // ...

        // Calculate the new area above sea level
        // ...
        
        // Output the area for this year
        cout << aboveSeaLevelArea << endl;
    }

    return 0;
}
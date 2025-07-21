#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
int grid[MAXN][MAXN];
int n, m, y;
bool visited[MAXN][MAXN];

struct Cell {
    int x, y, height;
};

// Directions for moving up, down, left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int start_x, int start_y, int sea_level) {
    queue<Cell> q;
    q.push({start_x, start_y, grid[start_x][start_y]});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        auto [x, y, height] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && grid[nx][ny] <= sea_level) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, grid[nx][ny]});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> y;

    // Read the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // Result array to store the area above sea level for each year
    vector<int> result(y + 1, 0);

    // Iterate over each sea level
    for (int sea_level = 1; sea_level <= y; ++sea_level) {
        memset(visited, false, sizeof(visited));

        // Perform BFS starting from each cell to mark all reachable cells below or equal to the sea level
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] <= sea_level) {
                    bfs(i, j, sea_level);
                }
            }
        }

        // Count the number of cells above the sea level
        int count_above_water = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]) {
                    ++count_above_water;
                }
            }
        }

        result[sea_level] = count_above_water;
    }

    // Print the results for each sea level
    for (int i = 1; i <= y; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
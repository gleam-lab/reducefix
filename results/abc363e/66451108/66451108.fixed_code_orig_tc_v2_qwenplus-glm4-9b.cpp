#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    set<pair<int, int>> sinking_cells; // To store cells that will sink
    queue<pair<int, int>> q; // BFS queue

    // Initialize BFS with coastlines (cells next to edge of grid)
    for (int i = 0; i < h; ++i) {
        q.push({i, 0});
        q.push({i, w-1});
        sinking_cells.insert({i, 0});
        sinking_cells.insert({i, w-1});
    }

    for (int i = 0; i < w; ++i) {
        q.push({0, i});
        q.push({h-1, i});
        sinking_cells.insert({0, i});
        sinking_cells.insert({h-1, i});
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= grid[x][y] + y) {
                visited[nx][ny] = true;
                sinking_cells.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }

    // Calculate initial remaining area
    int remaining_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j]) {
                remaining_area++;
            }
        }
    }

    // Output remaining area for each year
    for (int year = 0; year < y; ++year) {
        for (auto [x, y] : sinking_cells) {
            visited[x][y] = true;
            remaining_area--;
        }
        cout << remaining_area << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

struct Cell {
    int x, y, level;
    Cell(int _x, int _y, int _level) : x(_x), y(_y), level(_level) {}
};

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int seaLevel, int& remainingArea) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<Cell> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && grid[i][j] > seaLevel) {
                q.push(Cell(i, j, seaLevel));
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        remainingArea--;

        for (auto& dir : directions) {
            int nx = curr.x + dir.first;
            int ny = curr.y + dir.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > seaLevel) {
                q.push(Cell(nx, ny, seaLevel));
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));

    int totalArea = h * w;
    vector<int> result(y + 1, totalArea);

    for (int seaLevel = 1; seaLevel <= y; ++seaLevel) {
        bfs(grid, visited, seaLevel, result[seaLevel]);
    }

    for (int i = 1; i <= y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}
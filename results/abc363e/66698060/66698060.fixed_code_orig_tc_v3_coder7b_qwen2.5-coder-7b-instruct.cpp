#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
int h, w, y;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));

struct Cell {
    int x, y, height;
    bool operator<(const Cell& other) const {
        return height > other.height;
    }
};

void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int sea_level) {
    static int dx[] = {0, 0, 1, -1};
    static int dy[] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] <= sea_level) {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= sea_level) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<Cell> cells;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cells.emplace_back(i, j, grid[i][j]);
        }
    }
    sort(cells.begin(), cells.end());
    for (int i = 0; i < y; ++i) {
        int sea_level = cells[i].height;
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        bfs(grid, visited, sea_level);
        int remaining_area = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    remaining_area++;
                }
            }
        }
        cout << remaining_area << '\n';
    }
    return 0;
}
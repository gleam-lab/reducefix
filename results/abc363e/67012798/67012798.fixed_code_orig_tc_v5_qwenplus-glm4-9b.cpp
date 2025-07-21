#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

void flood_fill(vector<vector<int>>& grid, int start_row, int start_col, int sea_level) {
    int h = grid.size();
    int w = grid[0].size();
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, int>> q;

    q.push({start_row, start_col});
    visited[start_row][start_col] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] || grid[nx][ny] <= sea_level) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    int remaining_island_area = h * w;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < h; ++k) {
                if (!a[k][j] && (k == 0 || k == h - 1 || j == 0 || j == w - 1 || a[k - 1][j] <= a[k][j] || a[k + 1][j] <= a[k][j] || a[k][j - 1] <= a[k][j] || a[k][j + 1] <= a[k][j])) {
                    flood_fill(a, k, j, a[k][j] - 1);
                }
            }
        }
        for (int row = 0; row < h; ++row) {
            for (int col = 0; col < w; ++col) {
                if (a[row][col] > remaining_island_area) {
                    remaining_island_area = a[row][col];
                }
            }
        }
        cout << remaining_island_area << '\n';
    }

    return 0;
}
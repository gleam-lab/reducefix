#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int x, y, height;
    Cell(int x, int y, int height) : x(x), y(y), height(height) {}
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int targetHeight) {
    queue<Cell> q;
    q.emplace(x, y, heights[x][y]);
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy, ch] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size() || visited[nx][ny]) continue;
            if (heights[nx][ny] > targetHeight) {
                visited[nx][ny] = true;
                q.emplace(nx, ny, heights[nx][ny]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> heights(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> heights[i][j];
        }
    }

    vector<int> result(y + 1);
    for (int k = 1; k <= y; ++k) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && heights[i][j] > k) {
                    bfs(heights, visited, i, j, k);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    count++;
                }
            }
        }
        result[k] = count * count;
    }

    for (int i = 1; i <= y; ++i) {
        cout << result[i] << '\n';
    }

    return 0;
}
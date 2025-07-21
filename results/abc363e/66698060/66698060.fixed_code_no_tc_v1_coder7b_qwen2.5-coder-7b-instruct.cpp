#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct Cell {
    int x, y, height;
    Cell(int x, int y, int height) : x(x), y(y), height(height) {}
    bool operator>(const Cell& other) const {
        return height > other.height;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, y;
    cin >> h >> w >> y;

    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
                pq.push(Cell(i, j, grid[i][j]));
                visited[i][j] = true;
            }
        }
    }

    while (!pq.empty()) {
        auto [x, y, height] = pq.top();
        pq.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= height) {
                pq.push(Cell(nx, ny, grid[nx][ny]));
                visited[nx][ny] = true;
            }
        }
    }

    int total_area = h * w;

    for (int i = 0; i < y; ++i) {
        total_area -= pq.size();
        while (!pq.empty() && pq.top().height <= i + 1) {
            pq.pop();
        }
        cout << total_area << endl;
    }

    return 0;
}
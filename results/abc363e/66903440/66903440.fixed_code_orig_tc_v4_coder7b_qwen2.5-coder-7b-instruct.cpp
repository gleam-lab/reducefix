#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int h, w, y;

void bfs(int start_level) {
    queue<pair<int, int>> q;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!visited[i][j] && grid[i][j] <= start_level) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !visited[nx][ny] && grid[nx][ny] <= start_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;
    grid.resize(h, vector<int>(w));
    visited.resize(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    int total_area = h * w;
    for (int i = 0; i <= y; ++i) {
        bfs(i);
        int remaining_area = total_area - count_if(begin(visited), end(visited), [](const auto &row) {
            return accumulate(row.begin(), row.end(), 0, [](int acc, bool val) {
                return acc + static_cast<int>(val);
            });
        });
        cout << remaining_area << endl;
    }

    return 0;
}
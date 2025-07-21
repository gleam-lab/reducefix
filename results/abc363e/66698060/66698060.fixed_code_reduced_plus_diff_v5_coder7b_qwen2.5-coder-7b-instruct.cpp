#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 1000 + 5;
int h, w, y;
vector<vector<int>> grid(MAXN, vector<int>(MAXN));

bool inside(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

void bfs(vector<vector<bool>>& visited, int start_x, int start_y, int sea_level) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (inside(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= sea_level) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int sea_level = 1; sea_level <= y; ++sea_level) {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int remaining_area = 0;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && grid[i][j] > sea_level) {
                    bfs(visited, i, j, sea_level);
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] > sea_level) {
                    remaining_area++;
                }
            }
        }

        cout << remaining_area << '\n';
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;

int h, w, y;
vector<vector<int>> island, sink;

void bfs(int r, int c, int level) {
    queue<pair<int, int>> q;
    q.push({r, c});
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    visited[r][c] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + (i & 1 ? -1 : 1);
            int ny = y + (i & 2 ? -1 : 1);

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny] || island[nx][ny] <= level)
                continue;

            visited[nx][ny] = true;
            sink[nx][ny] = level;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> h >> w >> y;
    island = vector<vector<int>>(h, vector<int>(w));
    sink = vector<vector<int>>(h, vector<int>(w, INF));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> island[i][j];
            if (i == 0 || j == 0 || i == h - 1 || j == w - 1) {
                sink[i][j] = island[i][j];
            }
        }
    }

    for (int level = 0; level < y; ++level) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (sink[i][j] > level) {
                    bfs(i, j, level);
                    break;
                }
            }
        }
    }

    long long remaining_area = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (sink[i][j] > y) {
                remaining_area++;
            }
        }
    }

    cout << remaining_area << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int h, w, y;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int result;

void floodFill(int r, int c, int prev_level) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int current_level = grid[r][c];

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            int next_level = grid[nx][ny];

            if (next_level <= prev_level) {
                q.push({nx, ny});
            } else {
                result -= q.size();
                q.pop();
                q.push({nx, ny});
                current_level = next_level;
            }
        }
    }
}

int main() {
    cin >> h >> w >> y;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }

    int current_level = 0;

    while (current_level < y) {
        fill(visited[0], visited[h], false);
        result = 0;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j] && grid[i][j] < current_level) {
                    floodFill(i, j, current_level);
                }
            }
        }

        current_level++;
        cout << result << endl;
    }

    return 0;
}
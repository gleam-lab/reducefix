#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int h, w, y;

bool isValid(int x, int y) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

void floodFill(int x, int y, int level) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (isValid(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= level) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    cin >> h >> w >> y;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    memset(visited, false, sizeof(visited));

    // Initialize the flood fill for the edges
    for (int i = 0; i < h; ++i) visited[i][0] = visited[i][w - 1] = true;
    for (int j = 0; j < w; ++j) visited[0][j] = visited[h - 1][j] = true;

    for (int level = 1; level <= y; ++level) {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] <= level) {
                    floodFill(i, j, level);
                }
            }
        }
        int remainingArea = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (!visited[i][j]) {
                    remainingArea++;
                }
            }
        }
        cout << remainingArea << endl;
    }
    return 0;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
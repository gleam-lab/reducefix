#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MAXN = 1001;

int H, W, Y;
int heights[MAXN][MAXN];
bool visited[MAXN][MAXN];

int bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    int area = 1;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W || visited[nx][ny] || heights[nx][ny] <= Y) continue;

            visited[nx][ny] = true;
            area++;
            q.push({nx, ny});
        }
    }

    return area;
}

int main() {
    cin >> H >> W >> Y;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> heights[i][j];
        }
    }

    int initial_area = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!visited[i][j] && (i == 0 || j == 0 || i == H - 1 || j == W - 1 || heights[i][j] > Y)) {
                initial_area += bfs(i, j);
            }
        }
    }

    for (int i = 0; i < Y; ++i) {
        cout << initial_area << endl;
    }

    return 0;
}
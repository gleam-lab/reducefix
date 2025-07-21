#include <bits/stdc++.h>
using namespace std;

#define CLOSE ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAXN 1010

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void sink(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] <= currentSeaLevel) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void simulate(int years) {
    queue<pair<int, int>> q;
    for (int i = 0; i < H; ++i) {
        q.push({i, 0}); // Left edge
        q.push({i, W - 1}); // Right edge
        visited[i][0] = visited[i][W - 1] = true;
    }
    for (int i = 1; i < W - 1; ++i) {
        q.push({0, i}); // Top edge
        q.push({H - 1, i}); // Bottom edge
        visited[0][i] = visited[H - 1][i] = true;
    }
    int remainingArea = H * W;
    for (int year = 1; year <= years; ++year) {
        currentSeaLevel = year;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (grid[r][c] <= currentSeaLevel) {
                sink(r, c);
            } else {
                remainingArea--;
            }
        }
        cout << remainingArea << endl;
    }
}

int main() {
    CLOSE;
    int H, W, Y;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> grid[i][j];
        }
    }
    simulate(Y);
    return 0;
}